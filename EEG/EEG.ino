//long int Time;
void setup() {
  Serial.begin(115200);
}
void loop() {
  //Time = millis() % 6;
  //if (Time < 3) {
    delay(3);
    Serial.write("A0");
    Serial.write(map(analogRead(0), 0, 1023, 0, 255));
  //}
}
