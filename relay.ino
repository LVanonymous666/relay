#include <NanitLib.h>

#define RELAY P3_2
#define BUTTON P3_4

bool relayState;

void setup() {
  Nanit_Base_Start();
  pinMode(RELAY, OUTPUT);
  relayState = 1;
  digitalWrite(RELAY, relayState);
  pinMode(BUTTON, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  bool buttonValue = digitalRead(BUTTON);
  Serial.println(buttonValue);
  if (buttonValue == 0) {
    changeRelay();
  } else {
    delay(50);
  }
}

void changeRelay() {
  relayState = !relayState;
  bool buttonValue = 0;
    digitalWrite(RELAY, relayState);
    while(buttonValue == 0) {
      Serial.println(buttonValue);
      buttonValue = digitalRead(BUTTON);
      delay(50);
    }
}
