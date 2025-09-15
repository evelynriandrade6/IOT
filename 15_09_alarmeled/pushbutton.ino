void testeBotao(int pinoBotao) {
  Serial.print(F("Estado do Botao:"));
  Serial.println(digitalRead(pinoBotao));
  delay(500);
}