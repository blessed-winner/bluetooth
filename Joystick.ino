#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // RX, TX
int buttonPin = 7;
bool lastState = HIGH; // because INPUT_PULLUP

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(38400);
  BT.begin(38400);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  // Detect button press (state change from HIGH → LOW)
  if (lastState == HIGH && buttonState == LOW) {
    BT.println("1"); // send '1' to slave to turn LED ON
    Serial.println("Sent: 1");
    delay(200); // debounce
  }
  // Optional: detect button release to send OFF
  else if (lastState == LOW && buttonState == HIGH) {
    BT.println("0"); // send '0' to slave to turn LED OFF
    Serial.println("Sent: 0");
    delay(200); // debounce
  }

  lastState = buttonState;
}
