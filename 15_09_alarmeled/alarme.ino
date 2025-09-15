void handleAlarme(AdafruitIO_Data *data) {
  String valor = data->toString();

  Serial.print(F("Valor Recebido do Feed: "));
  Serial.println(valor);

  if (valor == "true") {
    alarmeAtivo = true;
    Serial.println("Alarme ARMADO pelo dash / app!");
  } else {
    alarmeAtivo = false;
    Serial.println("Alarme DESARMADO pelo dash / app!");
  }
}

void ativarAlerta() {
  digitalWrite(Buzzer_Pin, HIGH);
  digitalWrite(Led_Alarme, HIGH);
}

void DesligarAlerta() {
  digitalWrite(Buzzer_Pin, LOW);
  digitalWrite(Led_Alarme, LOW);
}