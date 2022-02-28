void Frente(int Vel) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, Vel);
  analogWrite(enB, Vel);

}

void Tras(int Vel) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, Vel);
  analogWrite(enB, Vel);

}


void Direita(int Vel) {
  digitalWrite(in1, HIGH); //DIREITA
  digitalWrite(in2, LOW); //DIREITA
  digitalWrite(in3, LOW);//ESQUERDA
  digitalWrite(in4, HIGH);//ESQUERDA
  analogWrite(enA, Vel);
  analogWrite(enB, Vel);
}

void Esquerda(int Vel) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, Vel);
  analogWrite(enB, Vel);
}

void FrenteEsquerda(int Vel, int VelCurva) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, Vel);
  analogWrite(enB, VelCurva);
}

void FrenteDireita(int Vel, int VelCurva) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, VelCurva);
  analogWrite(enB, Vel);
}

void Parado() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}
