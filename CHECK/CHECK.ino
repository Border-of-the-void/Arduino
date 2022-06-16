void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

}

void loop() {
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  delay(10);
  digitalWrite(10, 0);
  digitalWrite(11, 1);
  delay(10);

}
