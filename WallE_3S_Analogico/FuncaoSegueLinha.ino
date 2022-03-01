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

  valsensorE = analogRead (sensorE);
  valsensorC = analogRead (sensorC);
  valsensorD = analogRead (sensorD);

  valcorte = 300;
  Vel = 60;

  /*
    Serial.println("Sensor Esquerda");
    Serial.println(valsensorE);
    delay(2000);
    Serial.println("Sensor Central");
    Serial.println(valsensorC);
    delay(2000);
    Serial.println("Sensor Direita");
    Serial.println(valsensorD);
    delay(2000);
  */



  if ((valsensorE < valcorte) && (valsensorC > valcorte) && (valsensorD < valcorte)) { // Seguir em Frente
    Frente(Vel - 10);
    Serial.println("Frente");
  }

  if ((valsensorE < valcorte) && (valsensorC < valcorte) && (valsensorD > valcorte)) { // Virar para Direita
    Direita(Vel);
    Serial.println("Direita");
  }

  if ((valsensorE > valcorte) && (valsensorC < valcorte) && (valsensorD < valcorte)) { // Virar para Esquerda
    Esquerda(Vel);
    Serial.println("Esquerda");
  }

  if ((valsensorE < valcorte) && (valsensorC > valcorte) && (valsensorD > valcorte)) { // Virar 90° para Direita
    Direita(Vel+66);

    Serial.println("90 graus direita");
  }


  if ((valsensorE > valcorte) && (valsensorC > valcorte) && (valsensorD < valcorte)) { // Virar 90° para Esquerda
    Esquerda(Vel+66);
    Serial.println("90 graus esquerda");
  }

  if ((valsensorE < valcorte) && (valsensorC < valcorte) && (valsensorD < valcorte)) { // No Branco ==> GAP
    Frente(Vel - 10);
    Serial.println("Gap ou sem linha");
  }


}
