/*
  Sensor array
  0 0 0 0 0 - sem linha ou gap
  0 0 0 0 1 - direita + 20
  0 0 0 1 0 - direita + 50
  0 0 0 1 1 - direita + 70 (DIREITA 90 GRAUS)
  0 0 1 0 0 - em frente
  0 0 1 0 1 - nada - em frente
  0 0 1 1 0 - direita - 10
  0 0 1 1 1 - direita + 70 (DIREITA 90 GRAUS)
  0 1 0 0 0 - esquerda
  0 1 0 0 1 - nada - em frente
  0 1 0 1 0 - nada - em frente
  0 1 0 1 1 - nada - em frente
  0 1 1 0 0 - esquerda - 10
  0 1 1 0 1 - nada - em frente
  0 1 1 1 0 - nada - em frente
  0 1 1 1 1 - nada - em frente
  1 0 0 0 0 - esquerda + 20
  1 0 0 0 1 - nada - em frente
  1 0 0 1 0 - nada - em frente
  1 0 0 1 1 - nada - em frente
  1 0 1 0 0 - nada - em frente
  1 0 1 0 1 - nada - em frente
  1 0 1 1 0 - nada - em frente
  1 0 1 1 1 - nada - em frente
  1 1 0 0 0 - esquerda + 70(ESQUERDA 90 GRAUS)
  1 1 0 0 1 - nada - em frente
  1 1 0 1 0 - nada - em frente
  1 1 0 1 1 - nada - em frente
  1 1 1 0 0 - esquerda + 70 (ESQUERDA 90 GRAUS)
  1 1 1 0 1 - nada - em frente
  1 1 1 1 0 - nada - em frente
  1 1 1 1 1 - nada - em frente

*/
void SeguirLinha() {
  ModoBlue = LOW;

  
 if (Serial.available() > 0)
  {
    letra = Serial.read();
    Serial.println(letra);

    switch (letra) {
      //Bluetooth
      case 'X':
        SeguirLinha(); //Seguidor ligado
        break;

      case 'x':
        BlueOn(); //bluetooth manual ligado
        break;

    }
   



    //Sensores
    //Valores dos sensores
    valsensorE = analogRead(sensorE); //esquerda
    valsensorEC = analogRead(sensorEC);
    valsensorC = analogRead(sensorC); //central
    valsensorDC = analogRead(sensorDC);
    valsensorD = analogRead(sensorD); //direita

    valcorte = 375;
    Vel = 53;

    /*
      //--------Calibração dos sensores-------------
      Serial.println("Sensor Esquerda");
      Serial.println(valsensorE);
      delay(2000);
      Serial.println("Sensor Central Esquerda");
      Serial.println(valsensorEC);
      delay(2000);
      Serial.println("Sensor Central");
      Serial.println(valsensorC);
      delay(2000);
      Serial.println("Sensor Central Direita");
      Serial.println(valsensorDC);
      delay(2000);
      Serial.println("Sensor Direita");
      Serial.println(valsensorD);
      delay(2000);
  */


    //logica: sensor < valor de corte = BRANCO
    // sensor > valor de corte = PRETO

    if ((valsensorE < valcorte) && (valsensorEC < valcorte) && (valsensorC < valcorte) && (valsensorDC < valcorte) && (valsensorD < valcorte)) {
      // 0 0 0 0 0
      Frente(Vel);
      Serial.println("Gap ou sem linha - frente");
    }

    if ((valsensorE < valcorte) && (valsensorEC < valcorte) && (valsensorC < valcorte) && (valsensorDC < valcorte) && (valsensorD > valcorte)) {
      // 0 0 0 0 1
      Direita(Vel + 20);
      Serial.println("Direita");
    }

    if ((valsensorE < valcorte) && (valsensorEC < valcorte) && (valsensorC < valcorte) && (valsensorDC > valcorte) && (valsensorD < valcorte)) {
      // 0 0 0 1 0
      Direita(Vel + 20);
      Serial.println("Direita");
    }

    if ((valsensorE < valcorte) && (valsensorEC < valcorte) && (valsensorC < valcorte) && (valsensorDC > valcorte) && (valsensorD > valcorte)) {
      // 0 0 0 1 1
      Parado();
      delay(250);
      Direita(Vel);
      delay(400);
      Serial.println("Direita 90 graus");

    }

    if ((valsensorE < valcorte) && (valsensorEC < valcorte) && (valsensorC > valcorte) && (valsensorDC < valcorte) && (valsensorD < valcorte)) {
      // 0 0 1 0 0
      Frente(Vel);
      Serial.println("Frente");

    }

    if ((valsensorE < valcorte) && (valsensorEC < valcorte) && (valsensorC > valcorte) && (valsensorDC < valcorte) && (valsensorD > valcorte)) {
      // 0 0 1 0 1
      Frente(Vel);
      Serial.println("Nada - Frente");

    }

    if ((valsensorE < valcorte) && (valsensorEC < valcorte) && (valsensorC > valcorte) && (valsensorDC > valcorte) && (valsensorD < valcorte)) {
      // 0 0 1 1 0
      Direita(Vel);
      delay(100);
      Serial.println("Direita");

    }

    if ((valsensorE < valcorte) && (valsensorEC < valcorte) && (valsensorC > valcorte) && (valsensorDC > valcorte) && (valsensorD > valcorte)) {
      // 0 0 1 1 1
      Parado();
      delay(250);
      Direita(Vel + 20);
      delay(400);
      Serial.println("Direita 90 graus");

    }

    if ((valsensorE < valcorte) && (valsensorEC > valcorte) && (valsensorC < valcorte) && (valsensorDC < valcorte) && (valsensorD < valcorte)) {
      // 0 1 0 0 0
      Esquerda(Vel);
      Serial.println("Esquerda");

    }

    if ((valsensorE < valcorte) && (valsensorEC > valcorte) && (valsensorC < valcorte) && (valsensorDC < valcorte) && (valsensorD > valcorte)) {
      // 0 1 0 0 1
      Frente(Vel);
      Serial.println("Nada - Frente");

    }

    if ((valsensorE < valcorte) && (valsensorEC > valcorte) && (valsensorC < valcorte) && (valsensorDC > valcorte) && (valsensorD < valcorte)) {
      // 0 1 0 1 0
      Frente(Vel);
      Serial.println("Nada - Frente");

    }

    if ((valsensorE < valcorte) && (valsensorEC > valcorte) && (valsensorC < valcorte) && (valsensorDC > valcorte) && (valsensorD > valcorte)) {
      // 0 1 0 1 1
      Frente(Vel);
      Serial.println("Nada - Frente");

    }

    if ((valsensorE < valcorte) && (valsensorEC > valcorte) && (valsensorC > valcorte) && (valsensorDC < valcorte) && (valsensorD < valcorte)) {
      // 0 1 1 0 0
      Esquerda(Vel);
      delay(100);
      Serial.println("Esquerda");

    }

    if ((valsensorE < valcorte) && (valsensorEC > valcorte) && (valsensorC > valcorte) && (valsensorDC < valcorte) && (valsensorD > valcorte)) {
      // 0 1 1 0 1
      Frente(Vel);
      Serial.println("Nada - Frente");

    }

    if ((valsensorE < valcorte) && (valsensorEC > valcorte) && (valsensorC > valcorte) && (valsensorDC > valcorte) && (valsensorD < valcorte)) {
      // 0 1 1 1 0
      Frente(Vel);
      Serial.println("Nada - Frente");

    }

    if ((valsensorE < valcorte) && (valsensorEC > valcorte) && (valsensorC > valcorte) && (valsensorDC > valcorte) && (valsensorD > valcorte)) {
      // 0 1 1 1 1
      Parado();
      delay(250);
      Direita(Vel + 20);
      delay(400);
      Serial.println("Direita 90 graus");

    }

    if ((valsensorE > valcorte) && (valsensorEC < valcorte) && (valsensorC < valcorte) && (valsensorDC < valcorte) && (valsensorD < valcorte)) {
      // 1 0 0 0 0
      Esquerda(Vel);
      Serial.println("Esquerda");

    }

    if ((valsensorE > valcorte) && (valsensorEC < valcorte) && (valsensorC < valcorte) && (valsensorDC < valcorte) && (valsensorD > valcorte)) {
      // 1 0 0 0 1
      Frente(Vel);
      Serial.println("Nada - Frente");

    }

    if ((valsensorE > valcorte) && (valsensorEC < valcorte) && (valsensorC < valcorte) && (valsensorDC > valcorte) && (valsensorD < valcorte)) {
      // 1 0 0 1 0
      Frente(Vel);
      Serial.println("Nada - Frente");

    }

    if ((valsensorE > valcorte) && (valsensorEC < valcorte) && (valsensorC < valcorte) && (valsensorDC > valcorte) && (valsensorD > valcorte)) {
      // 1 0 0 1 1
      Frente(Vel - 5);
      Serial.println("Nada - Frente");

    }

    if ((valsensorE > valcorte) && (valsensorEC < valcorte) && (valsensorC > valcorte) && (valsensorDC < valcorte) && (valsensorD < valcorte)) {
      // 1 0 1 0 0
      Esquerda(Vel);
      Serial.println("Nada - Frente - ou esquerda");

    }

    if ((valsensorE > valcorte) && (valsensorEC < valcorte) && (valsensorC > valcorte) && (valsensorDC < valcorte) && (valsensorD > valcorte)) {
      // 1 0 1 0 1
      Frente(Vel);
      Serial.println("Nada - Frente");

    }

    if ((valsensorE > valcorte) && (valsensorEC < valcorte) && (valsensorC > valcorte) && (valsensorDC > valcorte) && (valsensorD < valcorte)) {
      // 1 0 1 1 0
      Frente(Vel);
      Serial.println("Nada - Frente");

    }

    if ((valsensorE > valcorte) && (valsensorEC < valcorte) && (valsensorC > valcorte) && (valsensorDC > valcorte) && (valsensorD > valcorte)) {
      // 1 0 1 1 1
      Frente(Vel - 5);
      Serial.println("Nada - Frente");

    }

    if ((valsensorE > valcorte) && (valsensorEC > valcorte) && (valsensorC < valcorte) && (valsensorDC < valcorte) && (valsensorD < valcorte)) {
      // 1 1 0 0 0
      Parado();
      delay(250);
      Esquerda(Vel);
      delay(400);
      Serial.println("Esquerda 90 graus");

    }

    if ((valsensorE > valcorte) && (valsensorEC > valcorte) && (valsensorC < valcorte) && (valsensorDC < valcorte) && (valsensorD > valcorte)) {
      // 1 1 0 0 1
      Frente(Vel - 5);
      Serial.println("Nada - Frente");

    }

    if ((valsensorE > valcorte) && (valsensorEC > valcorte) && (valsensorC < valcorte) && (valsensorDC > valcorte) && (valsensorD < valcorte)) {
      // 1 1 0 1 0
      Frente(Vel);
      Serial.println("Nada - Frente");

    }

    if ((valsensorE > valcorte) && (valsensorEC > valcorte) && (valsensorC < valcorte) && (valsensorDC > valcorte) && (valsensorD > valcorte)) {
      // 1 1 0 1 1
      Frente(Vel);
      Serial.println("Nada - Frente");

    }

    if ((valsensorE > valcorte) && (valsensorEC > valcorte) && (valsensorC > valcorte) && (valsensorDC < valcorte) && (valsensorD < valcorte)) {
      // 1 1 1 0 0
      Parado();
      delay(250);
      Esquerda(Vel + 40);
      delay(400);
      Serial.println("Esquerda 90 graus");

    }

    if ((valsensorE > valcorte) && (valsensorEC > valcorte) && (valsensorC > valcorte) && (valsensorDC < valcorte) && (valsensorD > valcorte)) {
      // 1 1 1 0 1
      Frente(Vel);
      Serial.println("Nada - Frente");

    }

    if ((valsensorE > valcorte) && (valsensorEC > valcorte) && (valsensorC > valcorte) && (valsensorDC > valcorte) && (valsensorD < valcorte)) {
      // 1 1 1 1 0
      Parado();
      delay(250);
      Esquerda(Vel + 40);
      delay(400);
      Serial.println("Esquerda 90 graus");

    }

    if ((valsensorE > valcorte) && (valsensorEC > valcorte) && (valsensorC > valcorte) && (valsensorDC > valcorte) && (valsensorD > valcorte)) {
      // 1 1 1 1 1
      Frente(Vel);
      Serial.println("Nada - Frente");

    }

  }
  
}
