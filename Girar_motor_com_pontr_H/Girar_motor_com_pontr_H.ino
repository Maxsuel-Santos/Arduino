/* ******* Controle de um Motor com Ponte-H *******
   Criado por: Anderson Harayashiki Moreira
   Rev.: 01
   Data: 30.04.2019

   Guia de conexão:
   Potenciômetro: Pino A0
   Botão de sentido de rotação: Pino 2
   Controle de sentido de rotação 1: Pino 3
   Controle de sentido de rotação 2: Pino 4
   Controle de velocidade do motor: Pino 6

 *************************** */

// Girar motor com pontr H

const int potenciometro = A0; // Liga no terminal do meio do potenciômetro
const int botao = 2;          // Liga no botão
const int pinoDir1 = 3;       // Liga no pino IN1 do driver de controle do motor
const int pinoDir2 = 4;       // Liga no pino IN2 do driver de controle do motor
const int pinoVel = 6;        // Liga no pino EN1 do driver de controle do motor. Precisa ser um pino com PWM

// Definição das variáveis do programa
int estadoBotao = 0;      // Estado do botão, HIGH = apertado e LOW = solto
int velocidade = 0;       // Velocidade do motor varia de 0 a 255
int sentidoRotacao = LOW; // LOW = Anti-horário e HIGH = horário

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(pinoDir1, OUTPUT);
  pinMode(pinoDir2, OUTPUT);
  // Configura o motor para girar no sentido anti-horário
  digitalWrite(pinoDir1, HIGH);
  digitalWrite(pinoDir2, LOW);
}

void loop() {
  estadoBotao = digitalRead(botao);               // Lê a entrada  do botão
  if (estadoBotao == LOW) {                      // Se o botão for apertado
    delay(50);                                    // Espera 50 ms (necessário para o debouncing)
    estadoBotao = digitalRead(botao);             // Lê a entrada  do botão novamente
    while (!digitalRead(botao))                    // Só libera o programa após soltar o botão
    {
      delay(1);
    }
    if (estadoBotao == LOW) {                    // Se o botão realmente for apertado faz a sequência normal
      if (sentidoRotacao == HIGH) {               // O sentido de rotação é horário?
        sentidoRotacao = LOW;                     // Muda para anti-horário
      }
      else {                                      // O sentido de rotação é anti-horário?
        sentidoRotacao = HIGH;                    // Muda para horário
      }
    }
  }
  if (sentidoRotacao == HIGH)  {
    // Configura o sentido de rotação como horário
    digitalWrite(pinoDir1, LOW);
    digitalWrite(pinoDir2, HIGH);
  }
  else  {
    // Configura o sentido de rotação como anti-horário
    digitalWrite(pinoDir1, HIGH);
    digitalWrite(pinoDir2, LOW);
  }
  velocidade = analogRead(potenciometro);         // Lê a entrada do potenciômetro
  velocidade = map(velocidade, 0, 1023, 0, 255);  // Converte a escala da entrada analógica para a escala da saída analógica
  analogWrite(pinoVel, velocidade);   // Liga o motor com a velocidade definida pelo potenciômetro
}
