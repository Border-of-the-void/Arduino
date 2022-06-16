#define button 4
int led [3] = {8, 7, 6};              // Пины светодиодов: Красный, Жёлтый, Зелёный
long int Time [2] = {0, 0};           // Время: входа в цикл, нажатия кнопки
bool but [2] = {0, 0};                // Состояние кнопки: ново, старое
bool work = true;
bool ryb [3] = {0, 0, 0};

void checkButon() {
  but[1] = but[0];
  but[0] = !digitalRead(button);
  if (but[0] and but[0] != but[1]) {
    Time[1] = millis() + 3000;
    ryb[0] = 1;
  }
  if (not(but[0]) and but[0] != but[1]) {
    ryb[0] = 0;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  pinMode(led[0], OUTPUT);
  pinMode(led[1], OUTPUT);
  pinMode(led[2], OUTPUT);
}

void loop() {
  Time[0] = millis();
  checkButon();
  if (but[0] and Time[0] > Time[1] and work) {
    work = not(work);
    ryb[1] = not(ryb[1]);
    ryb[0] = 0;
    digitalWrite(led[0], ryb[0]);
  }
  if (digitalRead(button)) {
    work = true;
  }
  if (not(ryb[1])) {
    digitalWrite(led[0], ryb[0]);
  }
  digitalWrite(led[1], ryb[1]);
}
