# Arduino Multi-Sensor & Actuator Project (Tinkercad)

## Overview
This project demonstrates how to interface multiple **sensors** and **actuators** with an Arduino Uno using a breadboard, simulated in Tinkercad Circuits. It is a general-purpose template that can be adapted for any combination of inputs (sensors) and outputs (actuators) — from simple LED blinking to automated systems like smart lighting, security alarms, or environment monitors.

---

## Components Required

### Core
- Arduino Uno
- Breadboard
- Jumper Wires
- USB Cable (for a physical Arduino)

### Sensors (Inputs) — pick as needed
| Sensor | Purpose | Typical Pin Type |
|--------|---------|-------------------|
| PIR Motion Sensor | Detect motion | Digital |
| LDR (Light Sensor) | Detect light/darkness | Analog |
| Ultrasonic Sensor (HC-SR04) | Measure distance | Digital (Trig/Echo) |
| DHT11/DHT22 | Temperature & Humidity | Digital |
| IR Sensor | Obstacle/line detection | Digital |
| Potentiometer | Variable analog input | Analog |
| Push Button | Manual digital input | Digital |
| Soil Moisture Sensor | Detect moisture level | Analog |
| Gas/Smoke Sensor (MQ series) | Detect gas presence | Analog |

### Actuators (Outputs) — pick as needed
| Actuator | Purpose | Typical Pin Type |
|----------|---------|-------------------|
| LED | Visual indicator | Digital / PWM |
| Buzzer | Sound alert | Digital / PWM |
| Servo Motor | Precise angular movement | PWM |
| DC Motor (with driver) | Continuous rotation | PWM/Digital |
| Relay Module | Switch high-power devices | Digital |
| RGB LED | Multi-color indication | PWM (3 pins) |
| LCD Display (16x2) | Show text/data | Digital (or I2C) |

### Passive Components
- Resistors (220Ω for LEDs, 10kΩ for pull-downs, etc.)
- Capacitors (if needed for sensor stability)

**Simulation Platform**
- [Tinkercad Circuits](https://www.tinkercad.com/)

---

## Circuit Connections (Template)

Fill this table in per project — one row per component.

| Arduino Pin | Component | Pin Type | Notes |
|-------------|-----------|----------|-------|
| Digital Pin 13 | LED (+) via 220Ω Resistor | Digital Out | Standard LED wiring |
| Digital Pin 7 | PIR Sensor OUT | Digital In | Detects motion |
| Analog Pin A0 | LDR (voltage divider) | Analog In | Light level |
| Digital Pin 9 | Servo Motor Signal | PWM Out | Angle control |
| Digital Pin 8 | Buzzer (+) | Digital Out | Sound alert |
| 5V | Sensor VCC pins | Power | Shared power rail |
| GND | Sensor/Actuator GND pins | Ground | Shared ground rail |

**General Wiring Rules**
- All components share a common **GND** rail on the breadboard.
- Sensors needing 5V/3.3V connect to the Arduino's power pins (via breadboard power rails).
- Use a resistor with LEDs to prevent burnout (220Ω is standard).
- PWM-capable pins on Uno: **3, 5, 6, 9, 10, 11** — use these for servos, dimmable LEDs, motor speed control.
- Ultrasonic sensors need two digital pins (Trig and Echo).

---

## Arduino Code (Template Structure)

```cpp
// ---- Pin Definitions ----
int ledPin = 13;
int pirPin = 7;
int ldrPin = A0;
int servoPin = 9;
int buzzerPin = 8;

// ---- Include libraries as needed ----
#include <Servo.h>
Servo myServo;

void setup() {
  Serial.begin(9600);

  // Actuators
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  myServo.attach(servoPin);

  // Sensors
  pinMode(pirPin, INPUT);
  pinMode(ldrPin, INPUT); // analog pins don't strictly need this
}

void loop() {
  // ---- Read Sensors ----
  int motionDetected = digitalRead(pirPin);
  int lightLevel = analogRead(ldrPin);

  // ---- Decision Logic ----
  if (motionDetected == HIGH) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000, 200); // short beep
    myServo.write(90);
  } else {
    digitalWrite(ledPin, LOW);
    myServo.write(0);
  }

  // ---- Debugging ----
  Serial.print("Light Level: ");
  Serial.println(lightLevel);

  delay(500);
}
```

Adjust pins, sensor logic, and included libraries based on which components you actually use.

---

## How to Run (Tinkercad)

1. Open [Tinkercad Circuits](https://www.tinkercad.com/).
2. Create a new Circuit.
3. Add Arduino Uno, Breadboard, and the sensors/actuators your project needs.
4. Wire components per your filled-in Circuit Connections table.
5. Open the **Code** editor → select **Text** mode.
6. Paste and adjust your Arduino code.
7. Click **Start Simulation**.
8. Use the **Serial Monitor** to debug sensor readings in real time.

---

## Project Structure

```
Arduino-MultiSensor-Project/
│
├── README.md
├── MainSketch.ino
└── docs/
    └── circuit-diagram.png   (optional screenshot from Tinkercad)
```

---

## Concepts Learned
- Digital vs Analog I/O
- Reading sensor data (`digitalRead`, `analogRead`)
- Controlling actuators (`digitalWrite`, `analogWrite`, `Servo.write`, `tone`)
- Using external libraries (e.g., `Servo.h`, `DHT.h`)
- Conditional logic based on sensor input
- Power and ground rail management on a breadboard
- Debugging with the Serial Monitor

---

## Expected Output
Depends on configuration, e.g.:
- LED turns ON when motion is detected.
- Buzzer beeps briefly on trigger.
- Servo moves to a set angle in response to sensor input.
- Serial Monitor logs live sensor readings.

---

## Future Improvements
- Combine multiple sensors for smarter automation (e.g., PIR + LDR for smart lighting).
- Add an LCD to display live sensor readings.
- Integrate a mobile app or Bluetooth module for remote control.
- Expand into IoT by adding an ESP8266/ESP32 for WiFi connectivity.
- Build complete mini-projects: smart doorbell, automatic plant watering, weather station, security alarm.

---

## Author
**Theresrose Vilsan**
B.Tech Computer Science Engineering
Learning Arduino and Embedded Systems through hands-on projects.
