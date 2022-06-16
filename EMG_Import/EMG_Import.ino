#include <Servo.h>
int Signs[4][5] = {{180, 3, 0, 172, 168},{180, 3, 120, 109, 86},{0, 3, 2, 63, 72},{0, 180, 180, 80, 0}};
String t;
Servo s[5];
int pins[5] = {3, 5, 6, 9, 10};
void setup() {
  for (int i = 0; i < 5; i++){s[i].attach(pins[i]);}
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    t = Serial.readStringUntil('\n');
      for(int i = 0; i < 5; i++){
        s[i].write(Signs[t.toInt()][i]);
    }
    
  }
}
