int EMG0;
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  EMG0 = map(analogRead(A0), 0, 1023, 0, 255);
  Serial.write("A0");
  Serial.write(EMG0);
}
