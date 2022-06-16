int L;
int notes[8] = {0, 261.63, 293.66, 329.63, 349.23, 392.00, 440.00, 493.881};

void setup() {
  for (int i = 2; i < 9; i ++){pinMode(i, INPUT);}
}

void loop() {
 L = 0;
 if (not(digitalRead(2))){L = 1;}
 if (not(digitalRead(3))){L = 2;}
 if (not(digitalRead(4))){L = 3;}
 if (not(digitalRead(5))){L = 4;}
 if (not(digitalRead(6))){L = 5;}
 if (not(digitalRead(7))){L = 6;}
 if (not(digitalRead(8))){L = 7;}
tone(11, notes[L]);
}
  
