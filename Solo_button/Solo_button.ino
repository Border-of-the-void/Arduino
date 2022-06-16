void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT);

}

void loop() {
  boolean b = digitalRead(7);
  if (b){
    Serial.println("Вкл");
  }
  else{
    Serial.println("Выкл");
  }
  
  delay(10);

}
