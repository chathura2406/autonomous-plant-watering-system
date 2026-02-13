#include <DHT.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

/* ---------------- PIN CONFIG ---------------- */
#define SOIL_PIN A3
#define DHT_PIN 7
#define RELAY_PIN 5

/* ---------------- THRESHOLDS ---------------- */
#define TEMP_LIMIT 35.0
#define DRY_SOIL 900
#define WET_SOIL 350

/* ---------------- OBJECTS ---------------- */
DHT dht(DHT_PIN, DHT11);
LiquidCrystal_I2C lcd(0x3F, 16, 2);
SoftwareSerial sim800l(3, 2);

/* ---------------- SYSTEM STATE ---------------- */
float temperature = 0;
int moistureRaw = 0;
int moisturePercent = 0;
bool pumpState = false;
bool smsSent = false;

/* ---------------- TIMING ---------------- */
unsigned long lastRead = 0;
const long interval = 2000;

/* ------------------------------------------------ */

void setup() {
  Serial.begin(9600);
  sim800l.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);

  dht.begin();
  lcd.init();
  lcd.backlight();

  displayStartup();
}

/* ------------------------------------------------ */

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - lastRead >= interval) {
    lastRead = currentMillis;

    readSensors();
    controlPump();
    updateDisplay();
    notifyUser();
  }
}

/* ---------------- SENSOR FUNCTIONS ---------------- */

void readSensors() {
  temperature = dht.readTemperature();
  if (isnan(temperature)) temperature = 0;

  moistureRaw = analogRead(SOIL_PIN);

  moisturePercent = map(moistureRaw, DRY_SOIL, WET_SOIL, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);

  Serial.print("Temp: "); Serial.println(temperature);
  Serial.print("Moisture: "); Serial.println(moisturePercent);
}

/* ---------------- CONTROL LOGIC ---------------- */

void controlPump() {
  bool soilDry = moisturePercent < 30;
  bool safeTemp = temperature < TEMP_LIMIT;

  if (soilDry && safeTemp) {
    digitalWrite(RELAY_PIN, LOW);
    pumpState = true;
  } else {
    digitalWrite(RELAY_PIN, HIGH);
    pumpState = false;
  }
}

/* ---------------- DISPLAY ---------------- */

void updateDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Moist:");
  lcd.print(moisturePercent);
  lcd.print("% ");

  if (pumpState)
    lcd.print("ON");
  else
    lcd.print("OFF");
}

/* ---------------- SMS ---------------- */

void notifyUser() {
  if (pumpState && !smsSent) {
    sendSMS("Plants watered successfully");
    smsSent = true;
  }

  if (!pumpState) {
    smsSent = false;
  }
}

void sendSMS(String message) {
  sim800l.println("AT+CMGF=1");
  delay(500);
  sim800l.print("AT+CMGS=\"+947XXXXXXXX\"");
  delay(500);
  sim800l.print(message);
  delay(500);
  sim800l.write(26);
}

/* ---------------- UI ---------------- */

void displayStartup() {
  lcd.setCursor(0, 0);
  lcd.print("Smart Irrigation");
  lcd.setCursor(0, 1);
  lcd.print("System Starting");
  delay(2000);
  lcd.clear();
}
