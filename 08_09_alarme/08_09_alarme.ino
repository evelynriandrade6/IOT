#include "AdafruitIO_WiFi.h"
#include "NewPing.h"

#define WIFI_SSID "..."
#define WIFI_PASS "..."


#define IO_USERNAME "..."
#define IO_KEY "..."

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);


AdafruitIO_Feed *botaoled = io.feed("botaoled");

// --- Configuração 
#define Buzzer_Pin 27
#define Led_Alarme 13
#define Botao_Fisico 26
#define TRIG_PIN 12
#define ECHO_PIN 14

// --- Configuração do ultrassônico
#define MAX_DISTANCE 100
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {

  pinMode(Buzzer_Pin, OUTPUT);
  pinMode(Led_Alarme, OUTPUT);
  pinMode(Botao_Fisico, INPUT);
  Serial.begin(115200);

  while(!Serial);

  // Serial.print("Conectando ao Adafruit IO");
  // io.connect();

  // while(io.status() < AIO_CONNECTED){
  // Serial.print(".");
  // delay(500);
  // }

  // Serial.println();
  // Serial.println(io.statusText());


  // botaoled -> onMessage(handleLed);
 
  delay(1000);

}

void loop() {

  // io.run();

  // delay(1000);

   // testeBuzzer();

  //  testeLed();

  // testeBotao(Botao_Fisico);

  // Serial.print(F("Distancia Lida: "));
  // Serial.println(sonar.ping_cm());
  // delay(500);

}
