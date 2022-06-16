char L;
int emg[2][64], Max[2], Min[2], amp[2];
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  for (int i = 0; i < 64; i++) {
    for (int t = 0; t < 2; t++) {
      emg[t][i] = analogRead(t);
    }
  }
}

void loop() {
  for (int i = 0; i < 63; i++) {
    for (int t = 0; t < 2; t++) {
      emg[t][i] = emg[t][i + 1];
    }
  }
  emg[0][63] = analogRead(0);
  emg[1][63] = analogRead(1);
  Max[0] = Max[1] = 0;                                                    
  Min[0] = Min[1] = 1023;   
  for (int i = 0; i < 63; i++) {
    for (int t = 0; t < 2; t++) {
      if (Max[t] < emg[t][i]) {
        Max[t] = emg[t][i];
      }
      if (Min[t] > emg[t][i]) {
        Min[t] = emg[t][i];
      }
    }
  }
  amp[0] = 0.7 * amp[0] + 0.3 * (Max[0] - Min[0]);
  amp[1] = 0.7 * amp[1] + 0.3 * (Max[1] - Min[1]);
  if (amp[0] > 650 and amp[1] < 650){L = 'V';}
  if (amp[0] < 650 and amp[1] > 650){L = 'O';}
  if (amp[0] < 650 and amp[1] < 650){L = 'L';}
  if (amp[0] > 650 and amp[1] > 650){L = 'K';}
  Serial.println(L);
}
