unsigned long Time;
int EMG0, EMG1;
char sym;
boolean first, second;
void setup() {
  Serial.begin(115200);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}
void loop() {
  EMG0 = map(analogRead(A0), 0, 1023, 0, 255);
  EMG1 = map(analogRead(A1), 0, 1023, 0, 255);
  Serial.write("A0");
  Serial.write(EMG0);
  Serial.write("A1");
  Serial.write(EMG1);
  if (Serial.available()) {
    sym = Serial.read();
    if (sym == 'A') {
      first = 1;
    }
    if (sym == 'B') {
      first = 0;
      digitalWrite(3, 0);
    }
    if (sym == 'C') {
      second = 1;
    }
    if (sym == 'D') {
      second = 0;
      digitalWrite(5, 0);
    }
  }
  if (first and not(second)) {
    Time = millis() % 1000;
    if (Time < 200) {
      digitalWrite(3, 1);
    }
    else {
      digitalWrite(3, 0);
    }
  }
  if (second and not(first)) {
    Time = millis() % 500;
    if (Time < 250) {
      digitalWrite(5, 1);
    }
    else {
      digitalWrite(5, 0);
    }
  }
  if (first and second) {
    Time = millis() % 1000;
    if (Time < 500) {
      digitalWrite(3, 1);
      digitalWrite(5, 0);
    }
    else {
      digitalWrite(3, 0);
      digitalWrite(5, 1);
    }
  }
}
