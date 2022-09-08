#include <Servo.h>
#include <AccelStepper.h>
#define S0 6
#define S1 7
#define S2 8
#define S3 9
#define SO 10
#define imaNesto 12
int dP = 4;
int sP = 5;

#define traka 13

int CF = 0;
int ZF = 0;
int BF = 0;
int crvena = 0;
int zelena = 0;
int plava = 0;
int boja;
Servo motoric;

int pozicija=0;
AccelStepper motor2 = AccelStepper(1, sP, dP);

void setup() {
 
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(traka, OUTPUT);
  pinMode(dP, OUTPUT);
  pinMode(sP, OUTPUT);

  pinMode(SO, INPUT);
  pinMode(imaNesto, INPUT);
  motoric.attach(11);
  motor2.setMaxSpeed(1000);
   motor2.setAcceleration(200);

  

  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
   
  Serial.begin(9600);
 motoric.write(0);
}




void kretanje(int  korak){
motor2.setSpeed(250);
   motor2.move(korak);
   motor2.runToPosition();
   Serial.println(korak);
}

void loop() { 
  digitalWrite(traka, HIGH);
  
  if(digitalRead(imaNesto)==LOW)
{ digitalWrite(traka, LOW);
  Serial.println("IMA NESTO");
  digitalWrite(traka, LOW);
  motoric.write(100);
  delay(600);
  kretanje(266);
  delay(1000);

  
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  
  CF = pulseIn(SO, LOW);
  
  
 
  Serial.print("R = ");
  Serial.print(CF);
  delay(100);
  
 
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  
  ZF = pulseIn(SO, LOW);
 
  
  Serial.print(" G = ");
  Serial.print(ZF);
  delay(100);
 
  
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  
  BF = pulseIn(SO, LOW);
 
  Serial.print(" B = ");
  Serial.println(BF);
  delay(100);
  if (50<CF && CF<100 && 165<BF && BF<360 && 235<ZF && ZF<350){
  boja=1; //crvena
  }
  else{
  if (190<CF && CF<300 && 150<BF && BF<210 && 255<ZF && ZF<320){
  boja=2; //plave
  }
  else{
    if (320<CF && CF<400 && 250<BF && BF<380 && 260<ZF && ZF<350){
  boja=3; //zelena
  }
  else{
    boja = 4;
  }
  }
  }
 switch(boja){
  case 1: 
  Serial.println("crvena");
  kretanje(266);
  motoric.write(0);
  delay(1000);
  kretanje(-532);
  break;
  case 2:
  Serial.println("plava");
  kretanje(532);
  motoric.write(0);
  delay(1000);
  kretanje(-798);
  break;
  case 3:
  Serial.println("zelena");
  kretanje(798);
  motoric.write(0);
  delay(1000);
  kretanje(-1064);
  break;
  case 4:
  Serial.println("greška");
  kretanje(1064);
  delay(600);
  motoric.write(0);  
  kretanje(-1330);
  break;
 }
 }}
    
   
  
