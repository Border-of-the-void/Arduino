#include <SoftwareSerial.h>
//                    имя                пароль             скорость           CMODE          получить адрес        записать адрес            роль
//запрос            AT+NAME?            AT+PSWD?            AT+UART?          AT+CMODE?          AT+ADDR?               AT+BIND?            AT+ROLE?
//вариант ответа  +NAME:SLAVE         +PIN:"1234"        +UART:9600,0,0        +CMODE:1                          AT+BIND=18,E4,400006       +ROLE:0                                         
//--------------------------------------------------------------------------------------------------------------------------------------------------
//какие установить (более подробно смотрите видео которое внизу статьи)
//для слейва    | AT+NAME=SLAVE     AT+PSWD="1234"       AT+UART=9600,0,0     AT+CMODE=1    +ADDR:98d3:11:fc1faa                            AT+ROLE=0   
//для мастера   | AT+NAME=MASTER    AT+PSWD="1234"       AT+UART=9600,0,0     AT+CMODE=0                          AT+BIND=98d3,11,fc1faa     AT+ROLE=1

//сброс настроек  AT+ORGL это для крайнего случая, если что то напутали с настройками, и не можете найти как исправить


const int rx = 5;
const int tx = 6;
SoftwareSerial BT (rx, tx);
 
void setup()  {
  pinMode(rx,INPUT); pinMode(tx,OUTPUT);
  Serial.begin(9600);       //в мониторе порта выбрать NL&CR, скорость Arduino с компьютером 9600
  BT.begin(38400);    //по умолчанию скорость BT модуля с Arduino в режиме AT команд 38400 иногда 9600
  Serial.println( "<<< Start! >>>");
  BT.println("AT");
}

void loop() {
  if (BT.available()) {
    char c = BT.read();      // читаем из программного Serial-порта
    Serial.print(c);   }           // пишем в штатный Serial-порт
  if (Serial.available()) {
    char c = Serial.read();        // читаем из штатного Serial-порта
    BT.write(c); }           // пишем в программный Serial-порт
}
