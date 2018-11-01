float tempC; // Variable para almacenar el valor obtenido del sensor (0 a 1023)

int pinLM35 = 0; // Variable del pin analogo de entrada del sensor 

void setup() {
  //Iniciamos la comunicación con el puerto serie
  Serial.begin(9600);
}

void loop() {

  // Con analogRead leemos el sensor, recuerda que es un valor de 0 a 1023
  tempC = analogRead(pinLM35); 

 // Calculamos la temperatura con la fórmula
  tempC = (5.0 * tempC * 100.0)/1024.0; 

  // Envia el dato al puerto serial
  Serial.println(tempC);
  delay(1000); //Retraso de 1 segundo
}
