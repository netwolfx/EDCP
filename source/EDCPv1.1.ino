/*
 * Elite Dangerous Control Panel
 * Adapted from code Example 4-5 from the book "Getting Started with Arduino: 3rd edition, by Massimo Banzi and Michael Shiloh (Maker Media). Copyright 2015 Massimo Banzi and Michael Shiloh, 978-1-4493-6333-8."
 * code (c) netwolfx 2016
*/

#include <Keyboard.h>

const int LED = 2;  //the pin for the LED
const int BUTTON = 10;  //the input pin where the pushbutton is connected

int val = 0;  //val will be used to store the state of the input pin
int old_val = 0;  // this variable stores the previous value of "val"
int state = 0;  // 0 = LED off while 1 = LED on


void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);   //tell Arduino LED is an output
  pinMode(BUTTON, INPUT); //and BUTTON is an input
  Keyboard.begin(); //initialize control of the keyboard
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(BUTTON);  //read input value and store it, yum, fresh!

  //check whether the input is HIGH (button pressed) and change the state
  if ((val == HIGH) && (old_val == LOW)) {
    state = 1 - state;
    Keyboard.write('l');
    delay(200);
  }

  old_val = val ; //val is now old, let's store it
  
  if (state == 1) {
    digitalWrite(LED, HIGH);  //turn LED on
    
  } else {
    digitalWrite(LED, LOW);
  }
  if ((val == LOW) && (old_val == HIGH)){
    delay(10);
  }
}
