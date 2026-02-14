# 🔧 Hardware Components (Bill of Materials)

This document lists all physical components required to build the Smart Irrigation System.

---

### 🧠 Controller

| Component   | Qty | Purpose                                                           |
| ----------- | --- | ----------------------------------------------------------------- |
| Arduino Uno | 1   | Main microcontroller handling sensing, decision logic and control |

---

### 🌱 Sensors

| Component                     | Qty | Purpose                                                    |
| ----------------------------- | --- | ---------------------------------------------------------- |
| Soil Moisture Sensor (Analog) | 1   | Detects soil water level                                   |
| DHT11 Temperature Sensor      | 1   | Measures ambient temperature to avoid evaporation watering |

---

### 💧 Actuators

| Component       | Qty | Purpose                         |
| --------------- | --- | ------------------------------- |
| 5V Relay Module | 1   | Controls high-power pump safely |
| DC Water Pump   | 1   | Performs irrigation             |

---

### 📡 Communication & Display

| Component          | Qty | Purpose                        |
| ------------------ | --- | ------------------------------ |
| SIM800L GSM Module | 1   | Sends SMS alerts to user       |
| 16x2 I2C LCD       | 1   | Displays real-time system data |

---

### 🔌 Power & Supporting Parts

| Component                   | Qty     | Purpose                     |
| --------------------------- | ------- | --------------------------- |
| 4V Battery / Buck Converter | 1       | Stable power for GSM module |
| 10kΩ Resistor               | 1       | Pull-up resistor for DHT11  |
| Jumper Wires                | Several | Electrical connections      |
| Breadboard                  | 1       | Prototype assembly          |
| Water Tubing                | 1       | Direct water to plant       |

---

### ⚠️ Important

All modules must share a **common ground connection** for stable operation.
