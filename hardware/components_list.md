\# 🔧 Hardware Components (Bill of Materials)



This document lists all physical components required to build the Smart Irrigation System.



---



\### Core Controller 



| Component   | Quantity | Description                                                               |

| ----------- | -------- | ------------------------------------------------------------------------- |

| Arduino Uno | 1        | Main microcontroller responsible for sensor processing and decision logic |



---



\### Sensors



| Component                     | Quantity | Description                                                   |

| ----------------------------- | -------- | ------------------------------------------------------------- |

| Soil Moisture Sensor (Analog) | 1        | Detects soil water content level                              |

| DHT11 Temperature Sensor      | 1        | Measures ambient temperature for evaporation-aware irrigation |



---



\### Actuators



| Component         | Quantity | Description                                   |

| ----------------- | -------- | --------------------------------------------- |

| Relay Module (5V) | 1        | Electrically isolates and controls water pump |

| DC Water Pump     | 1        | Provides irrigation water to plants           |



---



\### Communication \& Interface



| Component            | Quantity | Description                                      |

| -------------------- | -------- | ------------------------------------------------ |

| SIM800L GSM Module   | 1        | Sends SMS notification when watering occurs      |

| 16x2 I2C LCD Display | 1        | Displays real-time temperature and moisture data |



---



\### Power \& Supporting Parts



| Component                            | Quantity | Description                              |

| ------------------------------------ | -------- | ---------------------------------------- |

| External 4V Battery / Buck Converter | 1        | Required stable power for SIM800L module |

| 10kΩ Resistor                        | 1        | Pull-up resistor for DHT11 data pin      |

| Jumper Wires                         | Several  | Circuit connections                      |

| Breadboard                           | 1        | Prototyping connections                  |

| Water Tubing                         | 1        | Directs water from pump to plant         |



---



\### Important Note



All modules must share a \*\*common ground connection\*\* for proper operation.



