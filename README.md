# \# 🌱 Smart Irrigation System (Embedded + GSM)

# 

# A low-cost autonomous irrigation controller that monitors soil moisture and temperature to optimize watering and prevent water wastage.

# The system notifies the user via SMS whenever irrigation occurs, enabling remote monitoring without internet connectivity.

# 

# ---

# 

# \## 📌 Problem

# 

# Traditional irrigation requires manual inspection and often leads to:

# 

# \* Overwatering

# \* Water wastage

# \* Plant damage due to heat evaporation

# \* Continuous human monitoring

# 

# ---

# 

# \## 💡 Solution

# 

# This system automatically decides when to water plants based on environmental conditions and alerts the farmer using GSM communication.

# 

# ---

# 

# \## 🧠 Features

# 

# \* Soil moisture sensing

# \* Temperature-aware watering logic

# \* Automatic pump control

# \* LCD real-time monitoring

# \* SMS notification using SIM800L

# \* Calibrated sensor readings

# \* Non-blocking embedded design

# 

# ---

# 

# \## 🛠 Hardware Used

# 

# \* Arduino Uno

# \* Soil Moisture Sensor

# \* DHT11 Temperature Sensor

# \* Relay Module + Water Pump

# \* SIM800L GSM Module

# \* 16x2 I2C LCD

# 

# ---

# 

# \## ⚙️ Working Logic

# 

# Watering occurs only if:

# 

# Dry Soil AND Safe Temperature (<35°C)

# 

# Prevents watering during hot periods to reduce evaporation loss.

# 

# ---

# 

# \## 📷 System Architecture

# 

# Sensors → Microcontroller → Decision Engine → Pump + GSM + Display

# 

# ---

# 

# \## 🚀 Future Improvements

# 

# \* IoT Cloud Dashboard (ESP8266)

# \* Mobile App Monitoring

# \* Data logging \& analytics

# \* Weather prediction integration

# 

# ---

# 

# \## 👨‍💻 Author

# 

# Developed as an embedded systems project demonstrating real-world automation and resource optimization.



