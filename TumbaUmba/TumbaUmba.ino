volatile bool Flag = 1;
int pt = 0;
int pin[3] = {5, 6, 9};
void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(1, but, FALLING);
}


void but() {Flag = !Flag;}


void work() {
  pt = analogRead(A0);
  if (pt < 341) {analogWrite(5, 255);}
  else {analogWrite(5, 0);}
  if (pt > 341 and pt < 682) {analogWrite(6, 255);}
  else {analogWrite(6, 0);};
  if (pt > 682) {analogWrite(9, 255);}
  else {analogWrite(9, 0);};
  Serial.println(pt);
}

void crush() {
  for (int t = 0; t < 3; t++) {
    for (int i = 0; i < 255; i++) {
      analogWrite(5, 0);
      analogWrite(6, 0);
      analogWrite(9, 0);
      analogWrite(pin[t], i);
      delay(2);
      if (Flag){break;}
    }
    if (Flag){break;}
  }
}
void loop() {
  if (Flag) {work();}
  else {crush();}
}
