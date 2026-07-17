# Arduino LED Blink using Breadboard

## Overview

This project demonstrates the basics of Arduino programming by blinking an LED connected to an Arduino Uno through a breadboard. It is one of the simplest projects for beginners to understand digital output, circuit connections, and Arduino programming.

---

## Components Required

- Arduino Uno
- Breadboard
- LED
- 220Ω Resistor
- Jumper Wires
- USB Cable (for a physical Arduino)

**Simulation Platform**
- Tinkercad Circuits

---

## Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| Digital Pin 13 | 220Ω Resistor |
| Resistor | LED Anode (Long Leg) |
| LED Cathode (Short Leg) | GND |

Connection Flow:

```
Pin 13 → 220Ω Resistor → LED (+)
LED (-) → GND
```

---

## Arduino Code

```cpp
int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000);

  digitalWrite(ledPin, LOW);
  delay(1000);
}
```

---

## How to Run

### Using Tinkercad

1. Open Tinkercad.
2. Create a new Circuit.
3. Add:
   - Arduino Uno
   - Breadboard
   - LED
   - 220Ω Resistor
4. Connect the components as shown in the circuit diagram.
5. Open the **Code** editor.
6. Select **Text** mode.
7. Paste the Arduino code.
8. Click **Start Simulation**.

The LED should blink every second.

---

## Project Structure

```
Arduino-LED-Blink/
│
├── README.md
└── Blink.ino
```

---

## Concepts Learned

- Arduino IDE programming
- Digital Output Pins
- `setup()` and `loop()` functions
- `pinMode()`
- `digitalWrite()`
- `delay()`
- Breadboard wiring
- LED polarity (Anode and Cathode)

---

## Expected Output

- LED turns **ON** for 1 second.
- LED turns **OFF** for 1 second.
- The process repeats continuously.

---

## Future Improvements

- Control LED brightness using PWM.
- Blink multiple LEDs in sequence.
- Add a push button to control the LED.
- Use sensors such as LDR or PIR to automate blinking.
- Create traffic light and pattern-based LED projects.

---

## Author

**Theresrose Vilsan**

B.Tech Computer Science Engineering

Learning Arduino and Embedded Systems through hands-on projects.
