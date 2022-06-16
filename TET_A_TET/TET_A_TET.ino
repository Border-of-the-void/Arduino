#include <Servo.h>
Servo s[5];
char Alp[4] = {'V', 'O', 'L', 'K'};
int Pins[5] = {3, 5, 6, 9, 10};
char L;
int S[4][5] = {{0, 3, 0, 172, 168}, {180, 3, 120, 109, 86}, {180, 3, 0, 172, 168},{0, 180, 180, 80, 0}};
void setup() {
  for (int i = 0; i < 5; i++){s[i].attach(Pins[i]);}
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()){
    L = char(Serial.read());
    for (int i = 0; i < 4; i++){if (L == Alp[i]){for (int t = 0; t < 5; t++){s[t].write(S[i][t]);}}}
  }
}
