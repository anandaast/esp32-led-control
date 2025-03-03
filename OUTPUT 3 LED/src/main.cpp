#include <Arduino.h>

int BTN1 = 34; // 🔴 Tombol 1
int BTN2 = 35; // 🟢 Tombol 2
int BTN3 = 32; // 🟡 Tombol 3

int LED_RED = 23;    // 🔴 LED Merah
int LED_YELLOW = 22; // 🟡 LED Kuning
int LED_GREEN = 21;  // 🟢 LED Hijau

void setup() {
    Serial.begin(115200);
    pinMode(BTN1, INPUT_PULLUP);
    pinMode(BTN2, INPUT_PULLUP);
    pinMode(BTN3, INPUT_PULLUP);
    
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_GREEN, LOW);
}

void blinkLED(int led, int times) {
    for (int i = 0; i < times; i++) {
        digitalWrite(led, HIGH);
        delay(300);
        digitalWrite(led, LOW);
        delay(300);
    }
}

bool isButtonPressed(int button) {
    if (digitalRead(button) == LOW) {
        delay(50); // Debounce
        if (digitalRead(button) == LOW) {
            Serial.println("Tombol ditekan!");
            while (digitalRead(button) == LOW);
            return true;
        }
    }
    return false;
}

void loop() {
    if (isButtonPressed(BTN1)) {
        Serial.println("🔴 Tombol 1 ditekan - LED Merah kedip 5x");
        blinkLED(LED_RED, 5);
    }
    
    if (isButtonPressed(BTN2)) {
        Serial.println("🔴🟢 Tombol 2 ditekan - LED Merah & Hijau bergantian");
        for (int i = 0; i < 5; i++) {
            digitalWrite(LED_RED, HIGH);
            digitalWrite(LED_GREEN, LOW);
            delay(300);
            digitalWrite(LED_RED, LOW);
            digitalWrite(LED_GREEN, HIGH);
            delay(300);
        }
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_GREEN, LOW);
    }
    
    if (isButtonPressed(BTN3)) {
        Serial.println("🔴🟡🟢 Tombol 3 ditekan - LED Merah, Kuning, Hijau bergantian");
        for (int i = 0; i < 5; i++) {
            digitalWrite(LED_RED, HIGH);
            delay(300);
            digitalWrite(LED_RED, LOW);
            
            digitalWrite(LED_YELLOW, HIGH);
            delay(300);
            digitalWrite(LED_YELLOW, LOW);
            
            digitalWrite(LED_GREEN, HIGH);
            delay(300);
            digitalWrite(LED_GREEN, LOW);
        }
    }
}
