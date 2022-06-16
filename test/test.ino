#define DATA 13
#define LATCH 12
#define CLOCK 11
int sec = 0;
void setup() {
  pinMode(DATA, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
}

void loop() {
  digitalWrite(LATCH, 0);
  shiftOut(DATA, CLOCK, LSBFIRST, 0b00011001);
  digitalWrite(LATCH, 1);
  delay(1000);
  sec = (sec + 1) % 10;
}
