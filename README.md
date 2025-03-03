# 📌 Tugas Praktik IoT
```cpp
Name : Ananda Setiawati Abidin
NIM : 233140707111122
Information Technology 
University of Brawijaya 
```
# 💡 Project Description

This project aims to control an LED using the ESP32 microcontroller. 
By programming the ESP32 with the Arduino IDE, we can turn the LED on and off programmatically.

# 🔧 Features

1. Uses ESP32 as the main microcontroller.
2. LED control via code in the Arduino IDE.
3. Supports multiple LED control modes (e.g., blinking or manual control).
4. Simulation can be run using Wokwi Simulator.

# 🖥️ Circuit Diagram

Below is the circuit diagram in JSON format, ready to use in Wokwi Simulator. 

# 📜 ESP32 Code 
```cpp
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
```

# 🚀 How to Run in Wokwi

1. Open Wokwi ESP32 Simulator.
2. Create a new project and select ESP32.
3. Copy and paste the JSON diagram into diagram.json.
4. Copy and paste the C++ code into main.cpp.
5. Click the RUN ▶️ button to start the simulation.

# 📌 Conclusion

This project demonstrates how ESP32 can be used to control an LED efficiently. 
With simulators like Wokwi, we can develop and test the project without requiring physical hardware. 🚀 
