int val; //valeur numerique donnée le CAN
int pnum, j;//pnum pas numerique, j derniere led à allumer
void setup() {
  for (int i = 0; i < 8; i++)
    pinMode(i, OUTPUT); // de 0 à 7 comme sorties
  pnum = 128; //div entiere
}
void loop() {
  val = analogRead(A1); //lire la valeur numérique correspondante à la tension au niveau de A1
  j = val / pnum; //j represente la derniere led à allumer
  for (int i = 0; i <= j; i++)
    digitalWrite(i, HIGH); //allumer D0 --> Dj
  for (int i = j+1; i <= 7; i++)
    digitalWrite(i, LOW); //eteindre Dj+1 --> D7
  delay(1000); //attendre 1s et recommencer
}
