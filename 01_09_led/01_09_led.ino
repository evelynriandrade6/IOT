#include <math.h>
#include "AdafruitIO_WiFi.h"

#define WIFI_SSID "..."
#define WIFI_PASS "..."


#define IO_USERNAME "..."
#define IO_KEY "..."

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);


AdafruitIO_Feed *botaoled = io.feed("botaoled");

// --- Configuração 
#define pinNTC 34 
#define pinLed 14 

void setup() {
  Serial.begin(115200);
  pinMode(pinNTC, INPUT);
  pinMode(pinLed, OUTPUT);

  while(!Serial);

  Serial.print("Conectando ao Adafruit IO");
  io.connect();

  while(io.status() < AIO_CONNECTED){
  Serial.print(".");
  delay(500);
  }

  Serial.println();
  Serial.println(io.statusText());


  botaoled -> onMessage(handleLed);
 
  delay(1000);

}

void loop() {

  io.run();

  delay(1000);

}
