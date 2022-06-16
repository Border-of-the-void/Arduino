long int Time[2] = {0, 0};
int A = 0;
byte B[9] = {0b00000001, 0b00000011,0b00000111,0b00001111,0b00011111,0b00111111,0b01111111,0b11111111,0b00000000};
int C = 0;
boolean L = 0;
void setup() {
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  A = analogRead(A0);
  if (A > 650 and millis() > Time[0] + 500){
    L = 1;
    Time[1] = Time[0];
    Time[0] = millis();
  }
  if (L == 1){
    C = millis()%500/62.5;
      digitalWrite(13, 0);
      shiftOut(12, 11, LSBFIRST, B[C]);
      digitalWrite(13, 1);
     if (C == 7){
      digitalWrite(13, 0);
      shiftOut(12, 11, LSBFIRST, B[8]);
      digitalWrite(13, 1);   
      C = 0;
      L = 0;
     }
  }
  Serial.print(A);
  Serial.print(',');
  Serial.print(650);
  Serial.print(',');
  Serial.println(60000/(Time[0]-Time[1]));
}
