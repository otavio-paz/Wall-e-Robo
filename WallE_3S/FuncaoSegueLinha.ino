/*
  Sensor Array
   0 0 0 - sem linha (reto lento)
   0 0 1 - direita
   0 1 0 - reto
   0 1 1 - direita 90º
   1 0 0 - esquerda
   1 0 1 - nada (reto lento)
   1 1 0 - esquerda 90º
   1 1 1 - nada (reto lento)

*/

void SeguirLinha() {
  //Serial.println("Seguidor de linha ativado");

  LFSensor[0] = digitalRead(Sensor01); //direita
  LFSensor[1] = digitalRead(Sensor02); //central
  LFSensor[2] = digitalRead(Sensor03); //esquerda


  if ((     LFSensor[0] == 0 ) && (LFSensor[1] == 0 ) && (LFSensor[2] == 0 ))  {
    Serial.println("Sem linha");
    Frente(Vel - 20);

  }

  if ((     LFSensor[0] == 0 ) && (LFSensor[1] == 0 ) && (LFSensor[2] == 1 ))  {
    Serial.println("Direita");
    Direita(Vel);

  }

  if ((     LFSensor[0] == 0 ) && (LFSensor[1] == 1 ) && (LFSensor[2] == 0 ))  {
    Serial.println("Reto");
    Frente(Vel - 10);

  }

  if ((     LFSensor[0] == 0 ) && (LFSensor[1] == 1 ) && (LFSensor[2] == 1 ))  {
    Serial.println("Direita - 90 graus");
    Direita(Vel + 30);

  }

  if ((     LFSensor[0] == 1 ) && (LFSensor[1] == 0 ) && (LFSensor[2] == 0 ))  {
    Serial.println("Esquerda");
    Esquerda(Vel);

  }
  if ((     LFSensor[0] == 1 ) && (LFSensor[1] == 0 ) && (LFSensor[2] == 1 ))  {
    Serial.println("Nada");
    Frente(Vel - 30);

  }

  if ((     LFSensor[0] == 1 ) && (LFSensor[1] == 1 ) && (LFSensor[2] == 0 ))  {
    Serial.println("Esquerda 90 graus");
    Esquerda(Vel + 30);

  }

  if ((     LFSensor[0] == 1 ) && (LFSensor[1] == 1 ) && (LFSensor[2] == 1 ))  {
    Serial.println("Nada - frente");
    Frente(Vel - 30);

  }

}
