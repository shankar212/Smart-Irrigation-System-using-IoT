#define BLYNK_TEMPLATE_ID "TMPL3so5au32P"
#define BLYNK_TEMPLATE_NAME "smart irrigation"
#define BLYNK_AUTH_TOKEN "J_tbH59v8HJm64wuAUwD4QYyaO4FnYXY"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"
#include "ThingSpeak.h"

// 🌐 WiFi credentials
const char* ssid = "Sentry";
const char* password = "12345678";

// 🔹 ThingSpeak credentials
unsigned long channelID = 3136106;
const char* writeAPIKey = "60FH37N78IGFYZF0";
WiFiClient client;

// 🔹 Sensor pins
#define DHTPIN 0
#define DHTTYPE DHT11
#define SOIL_PIN 34
#define RELAY_PIN 15

DHT dht(DHTPIN, DHTTYPE);

// 🔹 Moisture threshold
const int MOISTURE_THRESHOLD = 40;  // below this = dry

// 🔹 Blynk Virtual Pins
#define VPIN_TEMP V0
#define VPIN_HUM V1
#define VPIN_SOIL V2
#define VPIN_PUMP V3

// 🔹 Variables
float temperature = 0;
float humidity = 0;
int soilMoisturePercent = 0;
bool pumpStatus = false;

BlynkTimer timer; // ⏱ Timer object

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(SOIL_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Pump OFF initially

  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\n✅ WiFi Connected!");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
  ThingSpeak.begin(client);

  // Run sendData() every 20 seconds without blocking
  timer.setInterval(20000L, sendData);

  Serial.println("🌱 Smart Irrigation System Started");
  Serial.println("-----------------------------------");
}

void loop() {
  Blynk.run();   // Keeps Blynk connection alive
  timer.run();   // Runs scheduled tasks
}

// 🔹 Periodic task
void sendData() {
  readSensors();
  controlPump();
  sendToThingSpeak();
  sendToBlynk();
}

// 🔹 Read sensors
void readSensors() {
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  int soilValue = analogRead(SOIL_PIN);
  soilMoisturePercent = map(soilValue, 4095, 0, 0, 100);

  Serial.println("📊 Sensor Readings:");
  Serial.print("Temperature: "); Serial.println(temperature);
  Serial.print("Humidity: "); Serial.println(humidity);
  Serial.print("Soil Moisture: "); Serial.print(soilMoisturePercent); Serial.println("%");
}

// 🔹 Pump control
void controlPump() {
  if (soilMoisturePercent < MOISTURE_THRESHOLD) {
    digitalWrite(RELAY_PIN, HIGH);
    pumpStatus = true;
    Serial.println("💧 Soil is dry → Pump ON ✅");
  } else {
    digitalWrite(RELAY_PIN, LOW);
    pumpStatus = false;
    Serial.println("🌿 Soil is wet → Pump OFF ❌");
  }
}

// 🔹 Send to ThingSpeak
void sendToThingSpeak() {
  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.setField(3, soilMoisturePercent);
  ThingSpeak.setField(4, pumpStatus);

  int status = ThingSpeak.writeFields(channelID, writeAPIKey);
  if (status == 200)
    Serial.println("📤 Data sent to ThingSpeak successfully!");
  else
    Serial.println("⚠️ ThingSpeak upload failed: " + String(status));
}

// 🔹 Send to Blynk
void sendToBlynk() {
  Blynk.virtualWrite(VPIN_TEMP, temperature);
  Blynk.virtualWrite(VPIN_HUM, humidity);
  Blynk.virtualWrite(VPIN_SOIL, soilMoisturePercent);
  Blynk.virtualWrite(VPIN_PUMP, pumpStatus ? 1 : 0);
}
