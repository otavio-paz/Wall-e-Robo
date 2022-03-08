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
int servoesq = 9; //braço esquerdo
int servodir = 10; //braço direito

Servo Servo1;
Servo Servo2;

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
bool ModoBlue = HIGH;
//----------------------------------------------------

void setup() {
  Serial.begin (9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT); //esquerda
  pinMode(enB, OUTPUT); //direita

  Servo1.attach(servoesq);
  Servo2.attach(servodir);

}

void loop() {

  if (Serial.available() > 0)
  {
    letra = Serial.read();
    Serial.println(letra);

    switch (letra) {
      //Bluetooth
      case 'x':
        ModoBlue = HIGH; //modo manual
        break;

      case 'X':
        ModoBlue = LOW; //seguir linha
        break;

      case 'W':
        MovimentoServo();
        break;
    }
  }

  //Condição de seguir linha ou bluetooth
  if (ModoBlue) {
    BlueOn();
  } else {
    SeguirLinha();
  }


}
