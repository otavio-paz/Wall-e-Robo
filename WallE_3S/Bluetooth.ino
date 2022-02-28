void BlueOn() {

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
      //-------------------------------------------
      //Movimento dos servos
      case 'w':
        PosInicial();
        break;

      case 'W':
        PosLevantada();
        break;
      //-------------------------------------------
      //Movimentos
      case 'F':// Frente
        Frente(Vel);
        break;

      case 'B':// Tras
        Tras(Vel);
        break;

      case 'R':// Direita
        Direita(Vel);
        break;

      case 'L'://Esquerda
        Esquerda(Vel);
        break;

      case 'S':// Parado
        analogWrite(enA, 0);
        analogWrite(enB, 0);
        break;

      case 'G': //Frente Esquerda
        FrenteEsquerda(Vel, VelCurva);
        break;

      case 'I'://Frente Direita
        FrenteDireita(Vel, VelCurva);
        break;

      //-------------------------------------------
      //Limitador de velocidade
      case '0'://Limitador O
        Vel = 23;
        VelCurva = 13;
        break;

      case '1'://Limitador 1
        Vel = 46;
        VelCurva = 30;
        break;

      case '2'://Limitador 2
        Vel = 69;
        VelCurva = 30;
        break;

      case '3'://Limitador 3
        Vel = 92;
        VelCurva = 40;
        break;

      case '4'://Limitador 4
        Vel = 115;
        VelCurva = 50;
        break;

      case '5'://Limitador 5
        Vel = 138;
        VelCurva = 70;
        break;

      case '6'://Limitador 6
        Vel = 161;
        VelCurva = 80;
        break;

      case '7'://Limitador 7
        Vel = 184;
        VelCurva = 100;
        break;

      case '8'://Limitador 8
        Vel = 207;
        VelCurva = 120;
        break;

      case '9'://Limitador 9
        Vel = 230;
        VelCurva = 130;
        break;

      case 'q'://Limitador q
        Vel = 245;
        VelCurva = 150;
        break;


    }
  }
}
