int emg [64];
int amp = 0;
int Max = 0;
int Min = 1000;
int led [10] = {0, 50, 100, 150, 200, 250, 300, 350, 400, 450};
int pins [10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
void setup() {
  Serial.begin(9600);
  for (int i = 2; i < 12; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A0, INPUT);
  for (int i = 0; i < 64; i++) {
    emg[i] = map(analogRead(A0), 0, 1023, 0, 1000);
  }
}

void loop() {
  for (int i = 0; i < 63; i++) {
    emg[i] = emg [i + 1];
  }
  emg[63] = map(analogRead(A0), 0, 1023, 0, 1000);
  Max = 0;
  Min = 1000;
  for (int i = 0; i < 64; i++) {
    if (emg[i] < Min) {
      Min = emg[i];
    }
    if (emg[0] > Max) {
      Max = emg[i];
    }
  }
  amp = 0.7 * amp + 0.3 * (Max - Min);
  Serial.println(amp);
  for (int i = 0; i < 10; i++) {
    if (amp > led[i]) {
      digitalWrite(pins[i], 1);
    }
    else {
      digitalWrite(pins[i], 0);
    }
  }
  
}
