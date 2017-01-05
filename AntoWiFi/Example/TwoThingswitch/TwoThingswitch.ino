#include <Wire.h>
#include <Ciao.h>
#include "AntoWiFi.h"

#define key "You key"
#define thing1 "thing1"
#define thing2 "thing2"
#define ch1 "ch1" //thing1
#define ch2 "ch2" //thing1
#define ch3 "ch3" //thing2
#define ch4 "ch4" //thing2

#define pin1 3
#define pin2 4
#define pin3 5
#define pin4 6

AntoWiFi Anto(key);
void setup() {
  Ciao.begin();
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,HIGH);
}

void loop() {
  Anto.AntodigitalGet(pin1,thing1,ch1);
  //delay(200);
  Anto.AntodigitalGet(pin2,thing1,ch2);
  //delay(200);
  Anto.AntodigitalGet(pin3,thing2,ch3);
  //delay(200);
  Anto.AntodigitalGet(pin4,thing2,ch4);
  delay(2000);
}
