//https://programarfacil.com/blog/el-potenciometro-y-arduino/

/*const int analogPin = A0;
int value; //variable que almacena la lectura analogica Raw
int position; //posicion del potenciometro en tanto por ciento*/

//Variable donde almacenaremos el valor del potenciometro
long valor;
 
//Declaramos los pins de los LEDs
int LED_1 = 2;
int LED_2 = 3;
int LED_3 = 4;
int LED_4 = 5;
int LED_5 = 6;
int LED_6 = 7;
int LED_7 = 8;

void setup() {
  // put your setup code here, to run once:
  //Inicializamos la comunicación serial
  Serial.begin(9600);
  
  //Escribimos por el monitor serie mensaje de inicio
  Serial.println("Valores del potenciometro");
}

void loop() {
  /*value = analogRead(analogPin);//realiza la lectura analogica raw 
  position = map (value,0,1023,0,100);//convertir a porcentaje
  //... hacer lo que se quiera con el valor de la posicion medido
  delay(1000);*/

  // leemos del pin A0 valor
  valor = analogRead(A0);

  //Imprimimos por el monitor serie
  Serial.print("El valor es = ");
  Serial.println(valor);
  
  if(valor >= 0)
  {
      digitalWrite(LED_1, LOW);
      digitalWrite(LED_2, LOW);
      digitalWrite(LED_3, LOW);
      digitalWrite(LED_4, LOW);
      digitalWrite(LED_5, LOW);
      digitalWrite(LED_6, LOW);
      digitalWrite(LED_7, LOW);
  }
  if(valor >= 1 && valor <=146)
  {
      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, LOW);
      digitalWrite(LED_3, LOW);
      digitalWrite(LED_4, LOW);
      digitalWrite(LED_5, LOW);
      digitalWrite(LED_6, LOW);
      digitalWrite(LED_7, LOW);
  } 
  if(valor >= 147 && valor <=293)
  {
      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, HIGH);
      digitalWrite(LED_3, LOW);
      digitalWrite(LED_4, LOW);
      digitalWrite(LED_5, LOW);
      digitalWrite(LED_6, LOW);
      digitalWrite(LED_7, LOW);
  }
  if(valor >= 294 && valor <=440)
  {
      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, HIGH);
      digitalWrite(LED_3, HIGH);
      digitalWrite(LED_4, LOW);
      digitalWrite(LED_5, LOW);
      digitalWrite(LED_6, LOW);
      digitalWrite(LED_7, LOW);
  } 
  if(valor >= 441 && valor <=587)
  {
      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, HIGH);
      digitalWrite(LED_3, HIGH);
      digitalWrite(LED_4, HIGH);
      digitalWrite(LED_5, LOW);
      digitalWrite(LED_6, LOW);
      digitalWrite(LED_7, LOW);
  }
  if(valor >= 588 && valor <=734)
  {
      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, HIGH);
      digitalWrite(LED_3, HIGH);
      digitalWrite(LED_4, HIGH);
      digitalWrite(LED_5, HIGH);
      digitalWrite(LED_6, LOW);
      digitalWrite(LED_7, LOW);
  }
  if(valor >= 735 && valor <=881)
  {
      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, HIGH);
      digitalWrite(LED_3, HIGH);
      digitalWrite(LED_4, HIGH);
      digitalWrite(LED_5, HIGH);
      digitalWrite(LED_6, HIGH);
      digitalWrite(LED_7, LOW);
  } 
  if(valor >= 882 && valor <=1023)
  {
      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, HIGH);
      digitalWrite(LED_3, HIGH);
      digitalWrite(LED_4, HIGH);
      digitalWrite(LED_5, HIGH);
      digitalWrite(LED_6, HIGH);
      digitalWrite(LED_7, HIGH);
  } 
}

