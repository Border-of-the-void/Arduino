   // переменная времени
boolean ledState = 0;                 // переменная состояния светодиода

void setup() {
    pinMode(3, OUTPUT);      // объявляем пин 10, как выход
}

void loop() {
    if (millis() - currentTime > 500)   // проверяем сколько прошло миллисекунд
    {
       currentTime = millis();
       ledState=!ledState;                   // меняем состояние светодиода на противоположное
       digitalWrite(3, ledState);
    }
}
