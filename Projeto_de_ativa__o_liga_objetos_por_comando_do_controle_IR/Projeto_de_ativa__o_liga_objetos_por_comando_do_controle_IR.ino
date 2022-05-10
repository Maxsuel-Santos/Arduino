
//Ativa objetos por controle IR(infravermelho)

#include <IRremote.h>

int voltage[12];
unsigned int i = 0;

IRrecv irrecv(12);
decode_results results;
unsigned long key_value = 0;

//--------------------setup

void setup(){
  Serial.begin(9600);
  SetUpPins();
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

//--------------------loop

void loop(){ 
  TranslateIR();
}

//--------------------functions


//-----ToggleLED-----
void ToggleLED(int pin) {
  if (voltage[pin]) {
    Serial.print("LED ");
    Serial.print(pin - 2);
    Serial.println(" was turned off");
    digitalWrite(pin, LOW);
    voltage[pin] = 0;
  } else {
    Serial.print("LED ");
    Serial.print(pin - 2);
    Serial.println(" was turned on");
    digitalWrite(pin, HIGH);
    voltage[pin] = 1;
  }
}
//-----SetUpPins-----
void SetUpPins() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}
//-----TranslateIR-----
void TranslateIR() {
  if (irrecv.decode(&results)){
 
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;

        switch(results.value){
          case 0xFD00FF://power
          break;
          case 0xFFA857://vol+
          break;
          case 0xFD40BF://func/stop
          break;
          case 0xFF22DD://|<<
          break;
          case 0xFFC23D://>||
          break ;  
          case 0xFF02FD://>>|
          break ;               
          case 0xFD10EF://down arrow
          break ;  
          case 0xFFE01F://vol-
          break ;  
          case 0xFD50AF://up arrow
          break ;  
          case 0xFF6897://0
          ToggleLED(2);
          break ;  
          case 0xFF906F://eq
          break ;
          case 0xFD708F://st/rept
          break ;
          case 0xFF30CF://1
          ToggleLED(3);
          break ;
          case 0xFF18E7://2
          ToggleLED(4);
          break ;
          case 0xFF7A85://3
          ToggleLED(5);
          break ;
          case 0xFF10EF://4
          ToggleLED(6);
          break ;
          case 0xFF38C7://5
          ToggleLED(7);
          break ;
          case 0xFF5AA5://6
          ToggleLED(8);
          break ;
          case 0xFF42BD://7
          ToggleLED(9);
          break ;
          case 0xFF4AB5://8
          ToggleLED(10);
          break ;
          case 0xFF52AD://9
          ToggleLED(11);
          break ;      
        }
        key_value = results.value;
        irrecv.resume(); 
  }
}
