/* CARGAR UNA LIBRERIA "Servo.h" PARA USAR EL SERVO */

#include <Servo.h>

/* DEFINIR VARIABLES DEL PROGRAMA */

int potPin = 0;    // Equivalente a "A0"
int servoPin = 9;  // Pin (tipo PWM) donde conectamos el servo.
int sensorValue;   // Para guardar la señal del potenciómetro.
int valorAngulo;   // Para guardar el ángulo.

// La librería servo provee una forma abstracta (simple) de controlar
// el servo. La siguiente línea "define" una variable que
// representa al microservo dentro del programa, y nos
// permite controlarlo más fácilmente.
Servo mi_servo;



/* CONFIGURAR EL ARDUINO */

void setup (){
  pinMode(potPin, INPUT);
  mi_servo.attach(servoPin); //conecta o objeto servo1 ao pino 9

  // Configurar mensajes que el arduino nos enviará
  // a traves del "serial monitor":
  Serial.begin(9600);
  // Enviar un mensaje de prueba:
  Serial.println("Señal de entrada (potenciometro), Señal de salida (angulo)");
}



/* PROGRAMAR EL CONTROL */

void loop(){

  // Leer la señal del potenciómetro.
  // Este valor es un número entero entre 0 y 1023.
  sensorValue = analogRead(potPin);

  // Convertir la señal del potenciometro (de 0 a 1023)
  // al rango de ángulos que puede girar el servo (0 1 180).
  valorAngulo = map(sensorValue, 0, 1023, 0, 179);

  // Enviar señal para posicionar al servo
  // en el ángulo deseado, usando mi_servo.write()
  mi_servo.write(valorAngulo);

  // Esperemos a que el servo se mueva un poco
  // antes de enviarle otra instrucción.
  delay(50);

  // Imprimir señal del potenciómetro
  // y el valor de ángulo correspondiente
  // en el serial monitor (es solo para saber).
  Serial.print(sensorValue);
  Serial.print(", ");
  Serial.println(valorAngulo);
}
