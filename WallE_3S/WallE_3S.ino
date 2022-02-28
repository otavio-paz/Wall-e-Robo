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

int Sensor01 = A1;
int Sensor02 = A2; //central
int Sensor03 = A3;


int LFSensor[3] = {0, 0, 0};

//caso deixe como analogico, digital precisa declarar no void setup

//Valores dos sensores
int Valor01;
int Valor02;
int Valor03;


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

  pinMode(Sensor01, INPUT);
  pinMode(Sensor02, INPUT);
  pinMode(Sensor03, INPUT);

}

void loop() {

  if (Serial.available() > 0)
  {
    letra = Serial.read();
    Serial.println(letra);

    switch (letra) {
      //Bluetooth
      case 'x':
        ModoBlue = HIGH;
        break;

      case 'X':
        ModoBlue = LOW;
        break;
    }
  }

  //Condição de seguir linha ou bluetooth
  if (ModoBlue == HIGH) {
    BlueOn();
  } else {
    SeguirLinha();
  }


}
