/* Sensor de umidade de solo
 
Escrito por Gedeane Kenshima
 
Data: 07/08/2017
 
*/
 
 
 
int buzzer = 11; //buzzer no pino 11
 
 
 
void setup() {
 
// inicio da comunicação serial
  
Serial.begin(9600);
}
 
 
void loop() {
 
// Leitura do sensor no pino A0 e armazenamento em SensorValue
 
int sensorValue = analogRead(A0);
 
// verifica se valor de leitura está abaixo de 400
 
    if (sensorValue > 600){
 
    // modulando apito sonoro conforme leitura do sensor
 
    int thisPitch = map(sensorValue, 200, 1023, 1500, 120);
 
    // fazendo o apito
    
    // porta, frequência, duração
 
    tone(buzzer, thisPitch, 50);
 
    Serial.print("Valor lido por sensor: "); // mostra mensagem
    
    Serial.println(sensorValue);// mostra valores no Monitor Serial
    
    Serial.println("Solo está seco: necessário regar!");// mostra mensagem
    
    delay(100);
 
}
 
else{
 
  Serial.print("Valor lido por sensor: "); // mostra mensagem
 
  Serial.println(sensorValue);// mostra valores no Monitor Serial
  delay(100);// aguarda 100ms por leitura
  }
  
}
