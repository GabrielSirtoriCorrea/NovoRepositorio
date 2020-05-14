#include <SoftwareSerial.h>

#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4
#define VelA 3
#define VelB 9
#define rx 10
#define tx 11

SoftwareSerial bluetooth(rx, tx);

int ValorBluetooth;
int vel;

void frente();
void tras();
void direita();
void esquerda();
void parado();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600);
  
  delay(100);
    
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(VelA, OUTPUT);
  pinMode(VelB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:  
  if (bluetooth.available()){
    ValorBluetooth = bluetooth.read();
    Serial.println(ValorBluetooth);
    switch(ValorBluetooth){
      case 70:
        frente();
        analogWrite(VelA, vel);
        analogWrite(VelB, vel);
        break;
      case 66:
        tras();
        analogWrite(VelA, vel);
        analogWrite(VelB, vel);
        break;
      case 82:
        direita();
        analogWrite(VelA, vel);
        analogWrite(VelB, vel);
        break;
      case 76:
        esquerda();
        analogWrite(VelA, vel);
        analogWrite(VelB, vel);
        break;
      case 71:
        esquerda();
        analogWrite(VelA, vel);
        analogWrite(VelB, vel);
        break;
      case 73:
        direita();
        analogWrite(VelA, vel);
        analogWrite(VelB, vel);
        break;
      case 50:
        vel = 0;
        break;

      case 51:
        vel = 50;
        break;

      case 52:
        vel = 70;
        break;

      case 53:
        vel = 90;
        break;

      case 54:
        vel = 110;
        break;

      case 55:
        vel = 150;
        break;

      case 56:
        vel = 180;
        break;

      case 57:
        vel = 210;
        break;

      case 58:
        vel = 240;
        break;

      case 59:
        vel = 255;
        break;
        
      default:
        parado();
        break;
    }
    
    /*if(ValorBluetooth == 70){
      frente();
    }else{
      tras();
    }*/
  }
}

void frente(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void parado(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}

void tras(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void direita(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void esquerda(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);  
}
