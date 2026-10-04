#include <Arduino.h>

#include "config.h"

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    Serial.println("ESP32 iniciado");
}

void loop() {
    digitalWrite(LED_PIN, HIGH);
    delay(BLINK_INTERVAL_MS);
    digitalWrite(LED_PIN, LOW);
    delay(BLINK_INTERVAL_MS);
}
