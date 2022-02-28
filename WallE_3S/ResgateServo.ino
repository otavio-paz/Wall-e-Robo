void PosInicial() {
  Servo1.write(120); //braço esquerdo reto
  Servo2.write(50); //braço direito reto
  delay(2000);

}

void PosLevantada() {
  Servo1.write(60); //braço esquerdo para cima
  Servo2.write(105); //braço direito para cima
  delay(1000);

}
