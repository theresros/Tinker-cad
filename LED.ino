// Blink LED using Arduino Uno

int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH); // LED ON
  delay(1000);                // Wait 1 second

  digitalWrite(ledPin, LOW);  // LED OFF
  delay(1000);                // Wait 1 second
}
