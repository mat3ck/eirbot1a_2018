//Programme de test afficheur 7-segments
#include <SoftwareSerial.h>
SoftwareSerial mySerial(PA7,PA6); //RX TX

int valeur0 = 1;
int valeur1 = 2;
int valeur2 = 7;
int str[] = {0,0,0};

int freq = 100;
int clk = 0b0;
int compteur_aff = 0;

void setup() {
  mySerial.begin(9600);
  pinMode(PA6, OUTPUT); // TX
  pinMode(PA7, INPUT);  // RX
  pinMode(PA0, OUTPUT); // bit0
  pinMode(PA1, OUTPUT); // bit1
  pinMode(PA2, OUTPUT); // bit2
  pinMode(PA3, OUTPUT); // bit3
  pinMode(PA4, OUTPUT); // clk
  pinMode(PA5, INPUT);  // position
}

void loop() {
  if(clk == 0){
    if(digitalRead(PA5))
      compteur_aff == 3;
    if(compteur_aff == 1){
      affichage(valeur0);
    }
    else if(compteur_aff == 2){
      affichage(valeur1);
    }
    else if(compteur_aff == 3){
      affichage(valeur2);
      compteur_aff = 0;
    }
    compteur_aff++;  
  
  }
  clk = ~clk;
  digitalWrite(PA4, clk);
  Event();
  delayMicroseconds(1000000/(7*freq));
}

void affichage(int valeur){
  digitalWrite(PA0, valeur & 0b0001);
  digitalWrite(PA1, valeur & 0b0010); 
  digitalWrite(PA2, valeur & 0b0100);
  digitalWrite(PA3, valeur & 0b1000);
}

void Event(){
  if(mySerial.available() >= 3){ // Envoyer le score dans un char* sous le format "000"
    for(int i=0; i < 3; i++){
      str[i] = mySerial.read() - 48;
    }
    valeur0 = str[0];
    valeur1 = str[1];
    valeur2 = str[2];
    while(mySerial.available() > 0){
      mySerial.read();
    }
  }
}

