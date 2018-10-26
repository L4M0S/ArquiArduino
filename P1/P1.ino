void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); // Pin 13 como Salida.
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH); // Pone la salida 13 a ON
  delay(500);            // Espera un segundo
  digitalWrite(13, LOW);  // Pone la salida 13 a OFF
  delay(500);            // Espera un segundo
}
