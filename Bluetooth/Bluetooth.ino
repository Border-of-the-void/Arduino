int emg[64];
bool L = 0;
int Max;
int Min;
int amp;
long int Time[6];
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 64; i ++){
    emg[i] = analogRead(A0);
  }
  pinMode(13, OUTPUT);
}

void loop() {
  Time[0] = millis();
  for (int i = 0; i < 63; i ++){
    emg[i] = emg[i+1];
  }
  emg[63] = analogRead(A0);
  Max = 0;
  Min = 1023;
  for (int i = 0; i < 64; i ++){
    if (emg[i] > Max){
      Max = emg[i];
    }
    if (emg[i] < Min){
      Min = emg[i];
    }
  }
  amp = 0.7*amp + 0.3*(Max-Min);
  Serial.print("160");
  Serial.print(",");
  Serial.print("320");
  Serial.print(",");
  Serial.print("480");
  Serial.print(",");
  Serial.print("640");
  Serial.print(",");
  Serial.print("800");
  Serial.print(",");
  Serial.println(amp);
  
  if (amp > 800){
    if (Time[0] > Time[1]){
      L = !L;
      Time[1] = Time[0] + 100;
    }
  }
  else if (amp > 640){
    if (Time[0] > Time[2]){
      L = !L;
      Time[2] = Time[0] + 125;
    }
  }
  else if (amp > 480){
    if (Time[0] > Time[3]){
      L = !L;
      Time[3] = Time[0] + 167;
    }
  }
  else if (amp > 320){
    if (Time[0] > Time[4]){
      L = !L;
      Time[4] = Time[0] + 250;
    }
  }
  else if (amp > 160){
    if (Time[0] > Time[5]){
      L = !L;
      Time[5] = Time[0] + 500;
    }
  }
  else {
    L = 0;
  }
  digitalWrite(13, L);
}
