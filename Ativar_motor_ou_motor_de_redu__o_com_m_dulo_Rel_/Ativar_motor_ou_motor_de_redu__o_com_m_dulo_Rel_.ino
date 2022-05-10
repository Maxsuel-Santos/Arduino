// Ativar motor/motor de redução com módulo Relé

void setup()
{
  pinMode(12, OUTPUT);
}

void loop()
{
  // liga o relé
  digitalWrite(12, LOW);
  delay(1000); // espera 1 segundo
  // desliga o relé
  digitalWrite(12, HIGH);
  delay(1000); // espera 1 segundo
}
