# 🌱 Smart Irrigation System using IoT

### 📘 Overview  
The **Smart Irrigation System using IoT** is an automated, cloud-connected irrigation solution designed to optimize water usage and monitor environmental conditions in agriculture.  
Developed using **Arduino IDE** and **ESP32**, the system automatically controls water flow based on **real-time soil moisture**, **temperature**, and **humidity** readings — ensuring smart and sustainable irrigation.

---

### 🚀 Features  
- 💧 **Automated Water Control** – Activates or deactivates the pump based on soil moisture readings.  
- 🌡️ **Real-Time Monitoring** – Tracks soil moisture, temperature, and humidity continuously.  
- ☁️ **Cloud Connectivity (ThingSpeak)** – Sends data to a live IoT dashboard for analysis.  
- ⚙️ **ThingHTTP + React Integration** – Automates triggers for controlling pump activity.  
- 🤖 **Telegram Bot Integration** – Sends alerts and allows remote control via chat commands.  
- 🌍 **IoT Automation** – Reduces manual intervention and enhances water efficiency.  

---

### 🧩 Tech Stack  
| Component | Description |
|------------|-------------|
| **Microcontroller** | ESP32 |
| **Sensors** | DHT11 (Temperature & Humidity), Soil Moisture Sensor |
| **Actuator** | Relay Module (Water Pump Control) |
| **Cloud Platform** | ThingSpeak (with ThingHTTP & React) |
| **Bot Service** | Telegram Bot (via BotFather) |
| **Software Used** | Arduino IDE |

---

### 🔌 Working Principle  
1. The **Soil Moisture Sensor** measures soil wetness.  
2. The **DHT11 Sensor** monitors temperature and humidity.  
3. **ESP32** collects and uploads sensor data to **ThingSpeak Cloud**.  
4. **ThingHTTP** and **React** automatically trigger the water pump based on preset thresholds.  
5. A **Telegram Bot** notifies users and allows remote manual control.  
6. Once the moisture reaches the optimal level, the pump stops automatically.  

---

### 🖥️ Cloud & Bot Integration  
- **ThingSpeak Dashboard** – Displays live graphs for moisture, temperature, and humidity.  
- **ThingHTTP + React** – Handles automatic responses for pump control.  
- **Telegram Bot Commands:**  
  - `/status` – Check current soil and weather data  
  - `/pump_on` – Turn ON the water pump remotely  
  - `/pump_off` – Turn OFF the water pump remotely  
  - `/data` – Get latest readings instantly  

---

### ⚙️ Setup Instructions  
1. **Clone the Repository:**  
   ```bash
   git clone https://github.com/<your-username>/Smart-Irrigation-System-using-IoT.git
   ```  
2. **Open the project in Arduino IDE.**  
3. **Install required libraries:**  
   - `WiFi.h`  
   - `HTTPClient.h`  
   - `DHT.h`  
4. **Update Configuration:**  
   - Add your Wi-Fi credentials.  
   - Add ThingSpeak API key, ThingHTTP URL, and Telegram Bot Token.  
5. **Connect Components:**  
   - ESP32 ↔ DHT11 ↔ Soil Moisture Sensor ↔ Relay ↔ Pump.  
6. **Upload the code** and monitor real-time readings on **ThingSpeak** or via the **Telegram Bot**.  

---

### 📸 Project Preview  
*(Add images to your `/assets` folder)*  
```
/assets/circuit-diagram.png
/assets/dashboard.png
/assets/telegram-bot.png
```

---

### 📊 Performance Highlights  
- ⏱️ Real-time updates every 15 seconds  
- 💧 Up to 40% water savings  
- 🔔 Instant Telegram alerts for low soil moisture  
- 🧠 Fully automated IoT-based decision-making  

---

### 🔮 Future Enhancements  
- Weather API integration for predictive irrigation  
- Solar-powered version for energy efficiency  
- Mobile app for better control and analytics  
- AI-based soil health prediction  

---

### 👨‍💻 Developer  
**Shanker Rathod**  
*Developed using Arduino IDE, ESP32, and ThingSpeak Cloud with Telegram IoT automation.*  

📧 Email: shankerr7780@gmail.com 
🌐 GitHub: [https://github.com/shankar212](https://github.com/shankar212)  



---

### 🏷️ Project Summary  
> **Smart Irrigation System using IoT (2025)**  
> Automated IoT-based system for efficient water management and weather condition monitoring in agriculture.  
> - Developed an automated irrigation system controlling water flow based on real-time soil moisture and environment.  
> - Integrated ESP32 with ThingSpeak for continuous monitoring and auto-triggering via ThingHTTP and React.  
> - Created a Telegram Bot using BotFather to send alerts and enable remote pump control through chat commands.  
> - Improved water efficiency and reduced manual intervention through intelligent IoT automation.  
> - **Tech Stack:** ESP32, DHT11, Soil Moisture Sensor, Relay Module, ThingSpeak, ThingHTTP, Telegram Bot, Arduino IDE.  
