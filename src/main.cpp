#include <Arduino.h>

int const inButton = 7;
int inState = 0;
int inLastState = 1;
int const inLED = 8;

int const outButton = 11;
int outState = 0;
int outLastState = 1;
int const outLED = 12;

int books = 0;
unsigned long previousMillis = 0;        
const long interval = 100; 


void setup() {
  pinMode(inButton, INPUT_PULLUP);
  pinMode(outButton, INPUT_PULLUP);
  pinMode(inLED, OUTPUT);
  pinMode(outLED, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  inState = digitalRead(inButton);
  outState = digitalRead(outButton);

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    Serial.println(books); 

    if (inState == LOW) {
      digitalWrite(inLED, HIGH);
      if (inState != inLastState) books++;
    } else {
      digitalWrite(inLED, LOW);
    };
    
    if (outState == LOW) {
      digitalWrite(outLED, HIGH);
      if (outState != outLastState) books--;
    } else {
      digitalWrite(outLED, LOW);
    };

    inLastState = inState;
    outLastState = outState; 

  }; 

  
}





/* Testing Code

int const inButton = 4;
int inState = 0;

void setup() {
  pinMode(inButton, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  inState = digitalRead(inButton);
  Serial.println(inState);

}

*/