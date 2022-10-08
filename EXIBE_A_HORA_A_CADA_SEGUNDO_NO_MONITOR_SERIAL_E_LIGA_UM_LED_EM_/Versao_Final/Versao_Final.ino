// ===== EXIBE A HORA A CADA SEGUNDO NO MONITOR SERIAL E EXIBE EM UM LCD 16X2. LIGA UM LED EM 2 HORÁRIOS DIFERENTES DURANTE O DIA =====

#include <ThreeWire.h>
#include <RtcDS1302.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2); // Portas do LCD no Arduino

ThreeWire myWire(9, 10, 11); // 6 -> DAT (SDA) | 7 -> CLK (SCL) | 8 -> RST (RESET) => Portas do RTC no Arduino
RtcDS1302<ThreeWire> Rtc(myWire);

// ===== Configurações =====
void setup () {
  // SETUP LED DIFUSO
  pinMode(8, OUTPUT); // LED

  // SETUP RTC DS1302
  Serial.begin(57600);
  Serial.print("compiled: ");
  Serial.print(__DATE__); // Monitor Serial => Data
  Serial.println(__TIME__); // Monitor Serial => Hora

  Rtc.Begin();
  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  printDateTime(compiled);
  Serial.println();

  // Verifica se a data e a hora são válidos 
  if (!Rtc.IsDateTimeValid()) {
    Serial.println("RTC perdeu a confiança no DateTime!");
    Rtc.SetDateTime(compiled);
  }

  // Desabilita a proteção contra escrita para gravar a hora e data
  if (Rtc.GetIsWriteProtected()) {
    Serial.println("O RTC foi protegido contra gravação, permitindo a gravação agora.");
    Rtc.SetIsWriteProtected(false);
  }

  // Se não estava rodando, começa a funcionar
  if (!Rtc.GetIsRunning()) {
    Serial.println("O RTC não estava funcionando ativamente, começando agora.");
    Rtc.SetIsRunning(true);
  }

  RtcDateTime now = Rtc.GetDateTime();
  if (now < compiled) {
    Serial.println("O RTC é mais antigo que o tempo de compilação! (Atualizando DateTime).");
    Rtc.SetDateTime(compiled);
  }
  else if (now > compiled)
    Serial.println("O RTC é mais recente que o tempo de compilação. (isso é esperado).");
  else
    Serial.println("RTC é o mesmo que tempo de compilação! (não esperado, mas está tudo bem).");

  // SETUP LCD
  lcd.begin(16,2);
  lcd.clear();
}

// ===== Loop =====
void loop () {
  RtcDateTime now = Rtc.GetDateTime();
  printDateTime(now);
  
  if (!now.IsValid()) {
    Serial.println("RTC perdeu a confiança no DateTime!.");
  }
  delay(1000);
  
}

// FUNÇÃO
#define countof(a) (sizeof(a) / sizeof(a[0]))

void printDateTime(const RtcDateTime& dt) {
  char lcdDate[20];
  char lcdHour[20];
  
  char datestring[20];
  
  snprintf_P(datestring,
             countof(datestring),
             PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
             dt.Month(), dt.Day(), dt.Year(),
             dt.Hour(), dt.Minute(), dt.Second() );
  Serial.println(); // Pular linha
  Serial.print(datestring);

  // LIGAR PELA 1ª VEZ => 6:00 ÀS 7:00
  if (dt.Hour() == 6 && dt.Hour() < 7) {
    Serial.println(); // Pular linha
    Serial.println("LED LIGADO!"); // Imprime no Monitor Serial p/ Ligar o Led
    digitalWrite(8, HIGH); // Liga o Led
  } 
  // LIGAR PELA 2ª VEZ => 16:00 ÀS 18:00
  else if (dt.Hour() == 16 && dt.Hour() < 18) {
    Serial.println(); // Pular linha
    Serial.println("LED LIGADO!"); // Imprime no Monitor Serial p/ Ligar o Led
    digitalWrite(8, HIGH); // Liga o Led
  }
  else {
    digitalWrite(8, LOW); // Led desligado
  }

  // EXIBE A HORA NO LCD
  // Data
  snprintf_P(lcdDate,
             countof(lcdDate),
             PSTR("Data: %02u/%02u/%04u"),
             dt.Day(), dt.Month(), dt.Year());
  lcd.setCursor(0,0);
  lcd.print(lcdDate);
  
  // Hora
  snprintf_P(lcdHour,
             countof(lcdHour),
             PSTR("Hora: %02u:%02u:%02u"),
             dt.Hour(), dt.Minute(), dt.Second());
  lcd.setCursor(1,4);
  lcd.print(lcdHour);

}
