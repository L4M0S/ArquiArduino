/*
  https://programarfacil.com/tutoriales/fragmentos/servomotor-con-arduino/
  https://programarfacil.com/tutoriales/fragmentos/sensor-de-ultrasonidos-con-arduino/
  
*/
// Incluímos la librería para poder controlar el servo
#include <Servo.h>

// Declaramos la variable para controlar el servo
Servo servoMotor;

// Configuramos los pines del sensor Trigger y Echo
const int PinTrig = 2;
const int PinEcho = 3;

// Constante velocidad sonido en cm/s
const float VelSon = 34000.0;

float distancia;

// Método que inicia la secuencia del Trigger para comenzar a medir
void iniciarTrigger()
{
  // Ponemos el Triiger en estado bajo y esperamos 2 ms
  digitalWrite(PinTrig, LOW);
  delayMicroseconds(2);
  
  // Ponemos el pin Trigger a estado alto y esperamos 10 ms
  digitalWrite(PinTrig, HIGH);
  delayMicroseconds(10);
  
  // Comenzamos poniendo el pin Trigger en estado bajo
  digitalWrite(PinTrig, LOW);
}

void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);

  // Ponemos el pin Trig en modo salida
  pinMode(PinTrig, OUTPUT);
  // Ponemos el pin Echo en modo entrada
  pinMode(PinEcho, INPUT);

  // Iniciamos el servo para que empiece a trabajar con el pin 9
  servoMotor.attach(9);
  // Desplazamos a la posición 90º
  servoMotor.write(90);
}

void loop() {
  iniciarTrigger();

  // La función pulseIn obtiene el tiempo que tarda en cambiar entre estados, en este caso a HIGH
  unsigned long tiempo = pulseIn(PinEcho, HIGH);
  
  // Obtenemos la distancia en cm, hay que convertir el tiempo en segudos ya que está en microsegundos
  // por eso se multiplica por 0.000001
  distancia = tiempo * 0.000001 * VelSon / 2.0;
  Serial.print(distancia);
  Serial.print("cm");
  Serial.println();

  if(distancia<=10)
  {
    servoMotor.write(180);
    delay(5000);
  }
  else servoMotor.write(90);
}
