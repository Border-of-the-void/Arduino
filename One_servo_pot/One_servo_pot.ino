#include <Servo.h>
Servo servo;
void setup() {
  servo.attach(10);
}

void loop() {
  servo.write(map(analogRead(A3), 0, 1023, 0, 180));
}
