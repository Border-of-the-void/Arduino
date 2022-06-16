int I = 0;
byte B [11] = {0b00000000, 0b00000000, 0b00000000, 0b10000000, 0b11000000, 0b11100000, 0b11110000, 0b11111000, 0b11111100, 0b11111110, 0b11111111};
void setup() {
  Serial.begin(9600);
  for (int i = 8; i < 13; i ++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  if (Serial.available()) {
    I = Serial.readString().toInt();
    digitalWrite(10, 0);
    shiftOut(12, 11, LSBFIRST, B[I]);
    digitalWrite(10, 1);
    digitalWrite(9, I >= 1);
    digitalWrite(8, I >= 2);
    Serial.println(I);
  }
}
