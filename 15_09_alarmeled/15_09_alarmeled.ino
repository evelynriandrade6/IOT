#include "AdafruitIO_WiFi.h"
#include "NewPing.h"

// --- Configuração
#define Buzzer_Pin 27
#define Led_Alarme 13
#define Botao_Fisico 26
#define TRIG_PIN 12
#define ECHO_PIN 14

// --- Configuração do ultrassônico
#define MAX_DISTANCE 100
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

#define IO_USERNAME "..."
#define IO_KEY "..."

#define WIFI_SSID "..."
#define WIFI_PASS "..."

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

// Definição dos Feeds
AdafruitIO_Feed *botaoalarme = io.feed("botaoalarme");

// Variáveis de controle
bool alarmeAtivo = false;
unsigned int distancia = 0;
const int LIMITE_DISTANCIA = 15;

void setup() {

  pinMode(Buzzer_Pin, OUTPUT);
  pinMode(Led_Alarme, OUTPUT);
  pinMode(Botao_Fisico, INPUT);
  Serial.begin(115200);

  while (!Serial)
    ;

  io.connect();

  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println(io.statusText());

  // Vincula a função callback ao feed
  botaoalarme->onMessage(handleAlarme);

  Serial.println("Solicitando o estado inicial do alarme: ");
  botaoalarme->get();

  delay(1000);
}

void loop() {
  io.run();

  // Leitura do botão físico
  if (digitalRead(Botao_Fisico) == 1) {
    delay(200);  // Debounce simples
    alarmeAtivo = !alarmeAtivo;

    botaoalarme->save(alarmeAtivo ? "true" : "false");
    Serial.println(alarmeAtivo ? F("Alarme ARMADO pelo botao fisico.") : F("Alarme DESARMADO pelo botao fisico."));
  }


  distancia = sonar.ping_cm();
  Serial.print("Distancia lida: ");
  Serial.println(distancia);
  Serial.println(" cm");

  // Ativação ou desativação do alarme
  if(alarmeAtivo && distancia > 0 && distancia > LIMITE_DISTANCIA){
    ativarAlerta();
  }
  else{
    desligarAlerta();
  }
  // delay(1000);

  // testeBuzzer();

  //  testeLed();

  // testeBotao(Botao_Fisico);

  // Serial.print(F("Distancia Lida: "));
  // Serial.println(sonar.ping_cm());
  // delay(500);
}
