// ===== EXIBE A HORA A CADA SEGUNDO NO MONITOR SERIAL =====

#include <ThreeWire.h>  
#include <RtcDS1302.h>

ThreeWire myWire(6,7,8); // 6 -> DAT (SDA) | 7 -> CLK (SCL) | 8 -> RST (RESET)
RtcDS1302<ThreeWire> Rtc(myWire);

// ===== Configurações =====
void setup () {
    Serial.begin(57600);
    Serial.print("compiled: ");
    Serial.print(__DATE__);
    Serial.println(__TIME__);

    Rtc.Begin();
    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
    printDateTime(compiled);
    Serial.println();

    if (!Rtc.IsDateTimeValid()) {
        // Causas comuns: 1) primeira vez que você executou e o dispositivo ainda não estava funcionando 2) a bateria do dispositivo está fraca ou até faltando
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
}

// ===== Loop =====
void loop () {
    RtcDateTime now = Rtc.GetDateTime();
    printDateTime(now);
    if (!now.IsValid()) {
        // Causas comuns: 1) a bateria do dispositivo está fraca ou até mesmo ausente e a linha de alimentação foi desconectada
        Serial.println("RTC perdeu a confiança no DateTime!.");
    }
    delay(1000);
}

#define countof(a) (sizeof(a) / sizeof(a[0]))

void printDateTime(const RtcDateTime& dt) {
    char datestring[20];
    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            dt.Month(), dt.Day(), dt.Year(),
            dt.Hour(), dt.Minute(), dt.Second() );
            Serial.println(); // Pular linha
    Serial.print(datestring);
}
