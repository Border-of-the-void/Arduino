void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == '1') {
      digitalWrite(13, 1);
    }
    if (c == '0') {
      digitalWrite(13, 0);
    }
  }
}
