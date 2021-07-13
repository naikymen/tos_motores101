/* DEFINIR VARIABLES */

int potPin = A0;
int motorPin = 9;

int sensorValue = 0;
int outputValue = 0;



/* CONFIGURAR ARDUINO */

void setup()
{
  pinMode(potPin, INPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}



/* PROGRAMAR EL CONTROL */

void loop()
{
  // read the value from the sensor
  sensorValue = analogRead(potPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(motorPin, outputValue);
  Serial.print("Señal de entrada (potenciometro) = ");
  Serial.print(sensorValue);
  Serial.print("     Señal de salida (PWM) = ");
  Serial.println(outputValue);
  delay(100); // Wait for 100 millisecond(s)
}