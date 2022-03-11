#include<Servo.h>

//Ponte H (motores)
const int in1 = 4;
const int in2 = 5;
const int in3 = 6;
const int in4 = 7;
const int enA = 3; //PWM~   9 e 10, com servo motor, dão problema
const int enB = 11; //PWM~

int Vel = 0;
int VelCurva = 0;

//---------------------------------------------------
//Servo motores
int servodir = 10; //braço direito

Servo Servo2; //braço direito

int graus = 0;

//---------------------------------------------------
//Sensores
int sensorE = A4; //esquerda
int sensorEC = A3; //esquerda central
int sensorC = A2; //centro
int sensorDC = A1; //direita central
int sensorD = A0; //direita

int valcorte = 300;

//caso deixe como analogico, digital precisa declarar no void setup

//Valores dos sensores
int valsensorE = 0;
int valsensorEC = 0;
int valsensorC = 0;
int valsensorDC = 0;
int valsensorD = 0;


//----------------------------------------------------
//Bluetooth
char letra;
bool ModoBlue = LOW;
//----------------------------------------------------

void setup() {
  Serial.begin (9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT); //esquerda
  pinMode(enB, OUTPUT); //direita

  Servo2.attach(servodir);
  Servo2.write(80);

}

void loop() {

  SinalBluetooth();
  Modo();

  if (ModoBlue == LOW) {
    BlueOn();
  }

  if (ModoBlue == HIGH) {
    SeguirLinha();
  }


}
void SinalBluetooth() {


  if (Serial.available() > 0)
  {
    letra = Serial.read();
    Serial.println(letra);

  }
}

void Modo() {

  switch (letra) {
    //Bluetooth
    case 'x':
      ModoBlue = LOW; //modo manual
      break;

    case 'X':
      ModoBlue = HIGH; //seguir linha
      break;
  }
}

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
  digitalWrite(in3, LOW); //ESQUERDA
  digitalWrite(in4, HIGH); //ESQUERDA
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

void BlueOn() {
  SinalBluetooth();

  switch (letra) {
    //-------------------------------------------
    //Movimento dos servos
    case 'w':
      MovimentoServo2();
      break;

    case 'W':
      MovimentoServo1();
      break;

    case 'U':
      MovimentoServo3();
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
      Vel = 60;
      VelCurva = 40;
      break;

    case '2'://Limitador 2
      Vel = 70;
      VelCurva = 50;
      break;

    case '3'://Limitador 3
      Vel = 90;
      VelCurva = 60;
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

  //Sensores
  //Valores dos sensores
  valsensorE = analogRead(sensorE); //esquerda
  valsensorEC = analogRead(sensorEC);
  valsensorC = analogRead(sensorC); //central
  valsensorDC = analogRead(sensorDC);
  valsensorD = analogRead(sensorD); //direita

  valcorte = 325;
  Vel = 59;

  /*
     //--------Calibração dos sensores-------------
     Serial.println("--------------------------");
     Serial.println("Sensor Esquerda");
     Serial.println(valsensorE);
     delay(2000);
     Serial.println("Sensor Central Esquerda");
     Serial.println(valsensorEC);
     delay(250);
     Serial.println("Sensor Central");
     Serial.println(valsensorC);
     delay(250);
     Serial.println("Sensor Central Direita");
     Serial.println(valsensorDC);
     delay(250);
     Serial.println("Sensor Direita");
     Serial.println(valsensorD);
     delay(250);
  */


  //logica: sensor < valor de corte = BRANCO
  // sensor > valor de corte = PRETO

  if ((valsensorE < valcorte) && (valsensorEC < valcorte) && (valsensorC < valcorte) && (valsensorDC < valcorte) && (valsensorD < valcorte)) {
    // 0 0 0 0 0
    Frente(Vel);
    //Serial.println("Gap ou sem linha - frente");
  }

  if ((valsensorE < valcorte) && (valsensorEC < valcorte) && (valsensorC < valcorte) && (valsensorDC < valcorte) && (valsensorD > valcorte)) {
    // 0 0 0 0 1
    Direita(Vel + 20);
    delay(150);
    //Serial.println("Direita");
  }

  if ((valsensorE < valcorte) && (valsensorEC < valcorte) && (valsensorC < valcorte) && (valsensorDC > valcorte) && (valsensorD < valcorte)) {
    // 0 0 0 1 0
    Direita(Vel + 10);
    delay(100);
    //Serial.println("Direita");
  }

  if ((valsensorE < valcorte) && (valsensorEC < valcorte) && (valsensorC < valcorte) && (valsensorDC > valcorte) && (valsensorD > valcorte)) {
    // 0 0 0 1 1
    Direita(Vel + 30);
    delay(250);
    //Serial.println("Direita 90 graus");

  }

  if ((valsensorE < valcorte) && (valsensorEC < valcorte) && (valsensorC > valcorte) && (valsensorDC < valcorte) && (valsensorD < valcorte)) {
    // 0 0 1 0 0
    Frente(Vel);
    //Serial.println("Frente");

  }

  if ((valsensorE < valcorte) && (valsensorEC < valcorte) && (valsensorC > valcorte) && (valsensorDC > valcorte) && (valsensorD < valcorte)) {
    // 0 0 1 1 0
    Direita(Vel + 10);
    delay(150);
    //Serial.println("Direita");

  }

  if ((valsensorE < valcorte) && (valsensorEC < valcorte) && (valsensorC > valcorte) && (valsensorDC > valcorte) && (valsensorD > valcorte)) {
    // 0 0 1 1 1
    Parado();
    delay(250);
    Direita(Vel + 30);
    delay(100);
    //Serial.println("Direita 90 graus");

  }

  if ((valsensorE < valcorte) && (valsensorEC > valcorte) && (valsensorC < valcorte) && (valsensorDC < valcorte) && (valsensorD < valcorte)) {
    // 0 1 0 0 0
    Esquerda(Vel + 20);
    delay(100);
    //Serial.println("Esquerda");

  }

  if ((valsensorE < valcorte) && (valsensorEC > valcorte) && (valsensorC > valcorte) && (valsensorDC < valcorte) && (valsensorD < valcorte)) {
    // 0 1 1 0 0
    Esquerda(Vel + 20);
    delay(100);
    //Serial.println("Esquerda");

  }

  if ((valsensorE < valcorte) && (valsensorEC > valcorte) && (valsensorC > valcorte) && (valsensorDC > valcorte) && (valsensorD > valcorte)) {
    // 0 1 1 1 1
    Parado();
    delay(250);
    Direita(Vel + 30);
    delay(250);
    //Serial.println("Direita 90 graus");

  }

  if ((valsensorE > valcorte) && (valsensorEC < valcorte) && (valsensorC < valcorte) && (valsensorDC < valcorte) && (valsensorD < valcorte)) {
    // 1 0 0 0 0
    Esquerda(Vel + 20);
    delay(150);
    //Serial.println("Esquerda");

  }

  if ((valsensorE > valcorte) && (valsensorEC > valcorte) && (valsensorC < valcorte) && (valsensorDC < valcorte) && (valsensorD < valcorte)) {
    // 1 1 0 0 0
    Esquerda(Vel + 30);
    delay(250);

    // Serial.println("Esquerda 90 graus");

  }


  if ((valsensorE > valcorte) && (valsensorEC > valcorte) && (valsensorC > valcorte) && (valsensorDC < valcorte) && (valsensorD < valcorte)) {
    // 1 1 1 0 0
    Parado();
    delay(250);
    Esquerda(Vel + 30);
    delay(250);
    //Serial.println("Esquerda 90 graus");

  }


  if ((valsensorE > valcorte) && (valsensorEC > valcorte) && (valsensorC > valcorte) && (valsensorDC > valcorte) && (valsensorD < valcorte)) {
    // 1 1 1 1 0
    Parado();
    delay(250);
    Esquerda(Vel + 30);
    delay(250);
    //Serial.println("Esquerda 90 graus");

  }


  else {
    Frente(Vel - 2);
  }

}


void MovimentoServo1() { //descer

  for (graus = 115; graus >= 30; graus--) {
    Servo2.write(graus);
    delay(50);
  }

  /*

    Servo2.write(95);
    delay(500);
    Servo2.write(85);
    delay(500);
    Servo2.write(75);
    delay(500);
    Servo2.write(65);
    delay(500);
    Servo2.write(55);
    delay(500);
    Servo2.write(45);
    delay(500);
    Servo2.write(30);
    delay(500);

  */

}

void MovimentoServo2() {//subir

  for (graus = 30; graus <= 115 ; graus++) {
    Servo2.write(graus);
    delay(50);
  }
  /*
    Servo2.write(30);
    delay(500);
    Servo2.write(45);
    delay(500);
    Servo2.write(55);
    delay(500);
    Servo2.write(65);
    delay(500);
    Servo2.write(75);
    delay(500);
    Servo2.write(85);
    delay(500);
    Servo2.write(95);
    delay(500);

  */
}

void MovimentoServo3() {
  Servo2.write(80);
}
