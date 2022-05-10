//Programa : Motor de passo 5v 28BYJ-48 com Arduino Motor Shield L293D
//Autor : GBA Tec

// SEGUNDO PROGRAMA PARA GIRAR MOTOR A PASSO


#include <AFMotor.h>
double passos_total = 2048; //Numero de passos para 1 rotacao total
 
int porta_motor = 2; //1 para motor em M1/M2 e 2 para motor em M3/M4
int angulo = 30; //Angulo de rotacao do eixo
 
double numero_de_passos = 0; //Armazena o numero de passos que o motor vai girar
 
AF_Stepper arduino(passos_total, porta_motor); //Define os parametros do motor
 
void setup()
{
arduino.setSpeed(10); //Define a velocidade de rotacao
Serial.begin(9600);
}
 
void loop()
{
//Calcula a quantidade de passos, baseado no angulo determinado
numero_de_passos = angulo / (360 / passos_total);
 
//Mostra no serial monitor o numero de passos calculados
Serial.println(numero_de_passos);
 
//Move o motor. Use FORWARD para sentido horario,
//BACKWARD para anti-horario
arduino.step(numero_de_passos, FORWARD, SINGLE);
arduino.release();
 
delay(2000);
}
