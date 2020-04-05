#include <Arduino.h>
#include "LowPower.h"

int const inButtonPin = 3;
int inButtonState = 0;
int inLastButtonState = 1;
int const inLEDPin = 4;

int const outButtonPin = 0;
int outButtonState = 0;
int outLastButtonState = 1;
int const outLEDPin = 1;

int books = 0;
unsigned long previousCountMillis = 0; 
const long countInterval = 100; 


void setup() {
  pinMode(inButtonPin, INPUT_PULLUP);
  pinMode(outButtonPin, INPUT_PULLUP);
  pinMode(inLEDPin, OUTPUT);
  pinMode(outLEDPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  //If in button is has been pushed, activate the LED and increase number of books.
  //If out button has been pushed, activate the LED and decrease number of books.
  outButtonState = digitalRead(outButtonPin);
  inButtonState = digitalRead(inButtonPin);
  
  //Print amount of books out if proper interval of time has passed.
  unsigned long currentCountMillis = millis();
  if (currentCountMillis - previousCountMillis >= countInterval) {
    previousCountMillis = currentCountMillis;
    Serial.println(books);
    if (outButtonState == LOW) {
      if (outButtonState != outLastButtonState) books--;
      digitalWrite(outLEDPin, HIGH);
    } else {
      digitalWrite(outLEDPin, LOW);
    }
    outLastButtonState = outButtonState;
    if (inButtonState == LOW) {
      if (inButtonState != inLastButtonState) books++;
      digitalWrite(inLEDPin, HIGH);
    } else {
      digitalWrite(inLEDPin, LOW);
    }
    inLastButtonState = inButtonState;
  }



}