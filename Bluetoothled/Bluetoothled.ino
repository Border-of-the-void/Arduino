bool C = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write("A0");
  Serial.write(analogRead(A0));
}
