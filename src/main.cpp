#include <Arduino.h>

#define BAUD_RATE 9600
#define PIR_SENSOR_PIN 10

unsigned long calculateHighTimeMS() {

    while (digitalRead(PIR_SENSOR_PIN) == LOW);

    unsigned long highTimeStartMS = millis();

    while (digitalRead(PIR_SENSOR_PIN) == HIGH);

    unsigned long highTimeEndMS = millis();

    return highTimeEndMS - highTimeStartMS;
}

void setup() {
    Serial.begin(BAUD_RATE);
    pinMode(PIR_SENSOR_PIN, INPUT);
}

void loop() {
/*    short value = digitalRead(PIR_SENSOR_PIN);

    Serial.println(value);*/

   unsigned long highTime = calculateHighTimeMS();

   if(highTime > 0) {
       Serial.println(highTime);
   }
}