int EMG[2][64];
int amp[2];
int Max[2] = {0, 0};
int Min[2] = {1023, 1023};
int th[2] = {200, 200};
  

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  for (int t = 0; t < 2; t++){for (int i = 0; i < 64; i++){EMG[t][i] = analogRead(t);}}
}


void loop() {  
  for (int t = 0; t < 2; t++){
    for (int i = 0; i < 63; i++){EMG[t][i] = EMG[t][i+1];}
    EMG[t][63] = analogRead(t);
  }

  for (int t = 0; t < 2; t++){
    for (int i = 0; i < 64; i++){
      if (EMG[t][i] < Min[t]){Min[t] = EMG[t][i];}
      if (EMG[t][i] > Max[t]){Max[t] = EMG[t][i];}
    }
  }
  for (int t = 0; t < 2; t ++){
    amp[t] = 0.7*amp[t] + 0.3*(Max[t]-Min[t]);
    Max[t] = 0;
    Min[t] = 1023;
    th[t] = analogRead(t+2);
  }
 Serial.println((amp[0] > th[0])  + (amp[1] > th[1] )*2);
}
