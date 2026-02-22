#include <Arduino.h>
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SDA_PIN 21
#define SCL_PIN 22
#define LED 2

Adafruit_BME280 bme;

// put function declarations here:

void setup() {
  // put your setup code here, to run once:

  pinMode(LED, OUTPUT);

  Serial.begin(115200);
  delay(1000);

  Wire.begin(SDA_PIN, SCL_PIN);

  if (!bme.begin(0x76)) {
      Serial.println("Could not find BME280 sensor!");
      while (1);
  }

  Serial.println("BME280 detected.");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);

  Serial.print("Temp: ");
  Serial.print(bme.readTemperature());
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.print("Pressure: ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.println("--------------------");
  delay(500);
}
