#include <Servo.h>
long int Time = 0;
int pins[5] = {3, 5, 6 , 9, 10};
int led[2] = {2, 4};
bool data0[2] = {0, 0};
int emg0[64];
int amp0 = 0;
int min0 = 1023;
int max0 = 0;
int Switch = 0;
int* G[5][5] = {{0, 180, 0, 93, 37}, {0, 0, 175, 93, 37}, {0, 0, 0, 93, 37}, {180, 0, 0, 93, 37}, {180, 0, 0, 110, 180}};
int L[5] = {180, 0, 0, 110, 180};
int th = 0;
Servo s[5];


void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 5; i++) {
    s[i].attach(pins[i]);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(led[i], OUTPUT);
  }
  for (int i = 0; i < 64; i++) {
    emg0[i] = analogRead(A0);
  }
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}
void loop() {
  th = analogRead(A2);
  for (int i = 0; i < 63; i++) {
    emg0[i] = emg0[i + 1];
  }
  emg0[63] = analogRead(A0);
  min0 = 1023;
  max0 = 0;
  for (int i = 0; i < 64; i++) { //   поиск минимума и максимума
    if (emg0[i] < min0) {
      min0 = emg0[i];
    }
    else if (emg0[i] > max0) {
      max0 = emg0[i];
    }
  }
  amp0 = 0.3 * (max0 - min0) + 0.7 * amp0;
  data0[1] = data0[0];
  data0[0] = amp0 > th;
  if (data0[0] and data0[0] != data0[1]) {
    Switch = (Switch + 1) % 5;
    digitalWrite(led[0], Switch % 2);
    digitalWrite(led[1], (Switch + 1) % 2);
    for (int i = 0; i < 5; i++) {
      s[i].write(L[i]);
    }
    Time = millis() + 500;
  }
  if (millis() > Time) {
    for (int i = 0; i < 5; i++) {
      s[i].write(G[Switch][i]);
    }
  }
  Serial.print(th);
  Serial.print(",");
  Serial.println(amp0);
}
