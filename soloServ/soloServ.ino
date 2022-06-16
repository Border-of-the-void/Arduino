#include <Servo.h>
Servo s;
void setup() {
  Serial.begin(9600);
  s.attach(6);

}

void loop() {
  s.write(map(analogRead(A0), 0, 1023, 0, 180));
  Serial.println(map(analogRead(A0), 0, 1023, 0, 180));
}
