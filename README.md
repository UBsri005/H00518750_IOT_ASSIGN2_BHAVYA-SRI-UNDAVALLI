int ledPin = 2;   // try GPIO 2 first

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  Serial.println("LED ON");
  digitalWrite(ledPin, HIGH);   // turn LED ON
  delay(1000);                  // wait 1 second

  Serial.println("LED OFF");
  digitalWrite(ledPin, LOW);    // turn LED OFF
  delay(1000);                  // wait 1 second
}
