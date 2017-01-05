#include <Wire.h>
#include <Ciao.h>
#include <AntoWiFi.h>

#define key "you key"
#define thing1 "you thing1"
#define thing2 "you thing2"
#define String_ch1 "ch1" //thing1
#define String_ch2 "ch2" //thing2

AntoWiFi Anto(key);
void setup() {
  Ciao.begin();
}

void loop() {
  Anto.AntogetString(thing1,String_ch1);
  Ciao.println(Anto.readString);
  Anto.AntogetString(thing2,String_ch2);
  Ciao.println(Anto.readString);
  delay(3000);
}
