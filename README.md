
---

## ⚙️ System Architecture

The proposed system consists of **three primary layers**:

1. **Perception Layer** – Hardware components (ESP32, DHT11, NeoPixel LED).  
2. **Network Layer** – Communication via Wi-Fi using MQTT protocol.  
3. **Application Layer** – Data visualization and control via Node-RED dashboard and Jupyter analytics.

![Architecture Diagram](https://user-images.githubusercontent.com/example/architecture-diagram.png)

---

## 🔧 Hardware Components

| Component | Description | Function |
|------------|--------------|-----------|
| **ESP32** | Wi-Fi enabled microcontroller | Core control and communication unit |
| **DHT11 Sensor** | Temperature & Humidity | Environment data sensing |
| **NeoPixel LED** | RGB Indicator | Visual feedback for temperature range |
| **USB Cable + Breadboard + Jumper Wires** | - | Connections and prototyping |

---

## 🧠 Software Stack

| Layer | Technology | Description |
|--------|-------------|-------------|
| **Programming** | Arduino IDE | ESP32 firmware and MQTT publish/subscribe |
| **Communication** | MQTT (test.mosquitto.org) | Lightweight IoT message protocol |
| **Visualization** | Node-RED Dashboard | Real-time monitoring and LED control |
| **Data Storage** | MongoDB Atlas / InfluxDB | Cloud time-series database |
| **Analytics** | Jupyter Notebook | Trend analysis, graphs, and performance metrics |

---

## 🚀 Setup Instructions

### 1. ESP32 Setup
1. Install **Arduino IDE** and ESP32 board package.  
2. Add required libraries: `WiFi.h`, `PubSubClient.h`, `DHT.h`, and `Adafruit_NeoPixel.h`.  
3. Configure Wi-Fi credentials and MQTT broker in the `.ino` sketch.  
4. Upload the code to ESP32 and open **Serial Monitor** at 115200 baud to verify connection.

### 2. MQTT Broker Configuration
- Broker: `test.mosquitto.org`  
- Port: `1883`  
- Publish topic: `iot/bhavya/esp32/sensors`  
- Subscribe topic: `iot/bhavya/esp32/led`

### 3. Node-RED Setup
1. Import `node_red_flow_temperature_humidity.json`.  
2. Deploy the flow and open the dashboard.  
3. Monitor live temperature and humidity readings.  
4. Control the LED via MQTT messages.

### 4. Jupyter Data Analytics
- Use the notebook in `/Jupyter_Analytics/data_analysis.ipynb`.  
- Load CSV data exported from Node-RED or MQTT subscriber.  
- Analyze daily averages, trends, and correlations.

---

## 📊 Functional Testing

| Test Case | Description | Result |
|------------|--------------|---------|
| Sensor Data Transmission | Temperature & humidity published every 5 sec | ✅ Stable |
| MQTT Connectivity | Tested with broker test.mosquitto.org | ✅ Connected |
| Node-RED Dashboard | Displays live readings with control switches | ✅ Functional |
| LED Control via MQTT | Remote ON/OFF via dashboard | ✅ Working |
| Jupyter Data Analysis | Data plotted and interpreted | ✅ Accurate |

---

## 💬 Discussion and Future Work

### Discussion
The implementation validates ESP32 and MQTT as a **robust IoT foundation** for real-time monitoring. Node-RED provides a **low-code** platform for rapid development and visualization. MongoDB/InfluxDB ensures **scalable** data storage for time-series analytics.

### Future Work
- Integrate **BME280 sensor** for improved precision.  
- Add **TLS encryption** for secure MQTT transmission.  
- Extend dashboard with **mobile app view**.  
- Automate cloud alerts using **email/SMS notifications**.  
- Deploy using **Edge AI** for anomaly detection.

---

## 🧾 References

Selected references (IEEE style):

[2] OASIS, *MQTT v3.1.1 Specification*, 2019.  
[3] I.-V. Nițulescu and A. Korodi, “Supervisory Control and Data Acquisition Approach in Node-RED,” *IoT*, vol. 1, no. 1, 2020.  
[4] T. Prantl *et al.*, “Performance Impact Analysis of Securing MQTT Using TLS,” *Proc. IoT ’21*, 2021.  
[5] Aosong Electronics, *DHT11 Sensor Datasheet*, 2018.  
[6] Espressif Systems, *ESP32 Technical Reference Manual*, 2020.  
[7] G. Premsankar *et al.*, “Edge Computing for IoT,” *IEEE IoT J.*, 2018.  
... (Full list in `/Documentation/References.txt`)

---

## 📜 License

This project is released under the **MIT License**.  
See the [LICENSE](./LICENSE) file for more details.

---

## 👩‍💻 Author

**Undavalli Bhavya Sri**  
MSc Robotics (Industrial Applications)  
Heriot-Watt University, Edinburgh  
Student ID: H00518750  

📧 [bhavya.undavalli@hw.ac.uk](mailto:bhavya.undavalli@hw.ac.uk)  
🌐 [GitHub Profile](https://github.com/bhavyasri-undavalli)

---

⭐ *If you found this project useful, please consider starring the repo!*
