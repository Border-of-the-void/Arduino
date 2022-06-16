long int Time, Time0, Time1;
int  dt = 0;
int emg;
void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(A0, INPUT);
  Time0 = 0;
  Time1 = 0;
}

void loop() {
  Time = millis();
  emg = analogRead(A0);
  if ((emg >= 750) and (Time > (Time0 + 250))) {
    Time1 = Time0;
    Time0 = Time;
    dt = Time0 - Time1;
    digitalWrite(2, 1);
  }
  Serial.print(emg);
  Serial.print(',');
  Serial.print(100);
  Serial.print(',');
  Serial.println(60000 / dt);
  digitalWrite(2, 0);
}
