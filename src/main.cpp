#include <Arduino.h>

#define BAUD_RATE 9600
#define PIR_SENSOR_PIN 10

unsigned long calculateHighTimeMS() {

    while (digitalRead(PIR_SENSOR_PIN) == LOW);
    Serial.println("Sensing now...");
    unsigned long highTimeStartMS = millis();

    while (digitalRead(PIR_SENSOR_PIN) == HIGH);

    unsigned long highTimeEndMS = millis();
    Serial.println("End sensing!");

    return highTimeEndMS - highTimeStartMS;
}

/**
 * Will block until a high signal is detected, which length is equal or above the given one
 */
void detectBySignalLength(const unsigned long& signalLength) {
    while (calculateHighTimeMS() < signalLength);
}

void setup() {
    Serial.begin(BAUD_RATE);
    pinMode(PIR_SENSOR_PIN, INPUT);
}

void loop() {
    /*short value = digitalRead(PIR_SENSOR_PIN);

    Serial.println(value);*/

    unsigned long highTime = calculateHighTimeMS();

    if (highTime > 0) {
        Serial.println(highTime);
    }
}