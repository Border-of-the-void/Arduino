#define DATA 13
#define LATCH 12
#define CLOCK 11
byte nums[10] = {0b01111101, 0b00100100, 0b01111010, 0b01110110, 0b00100111, 0b01010111, 0b01011111, 0b01100100, 0b01111111, 0b01110111};
int sec = 0;
void setup() {
  pinMode(DATA, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
}

void loop() {
  digitalWrite(LATCH, 0);
  shiftOut(DATA, CLOCK, LSBFIRST, nums[sec]);
  digitalWrite(LATCH, 1);
  delay(50);
  sec = (sec + 1) % 10;
}
