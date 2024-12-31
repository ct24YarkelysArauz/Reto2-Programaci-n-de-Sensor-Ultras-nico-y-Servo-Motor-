#include <ESP32Servo.h>  // Librería para controlar el servo

// Definir pines
const int trigPin = 12;  // Pin para el Trigger
const int echoPin = 14;   // Pin para el Echo
const int servoPin = 7; // Pin para el Servo

// Crear objeto Servo
Servo miServo;

void setup() {
  // Iniciar comunicación serial para mostrar los datos de distancia
  Serial.begin(115200);
  
  // Configurar pines de sensor ultrasónico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Iniciar o configurar el servo en el pin correspondiente
  miServo.attach(servoPin);
  
  // Mover el servo a la posición inicial
  miServo.write(0);  // Posición central (0 grados)
  
  Serial.println("Iniciando");
}

void loop() {
 // Enviar un pulso de 10 microsegundos al pin Trigger para iniciar la medición
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Leer la duración del pulso desde el pin Echo y calcular la distancia en centímetros
  long duracion = pulseIn (echoPin, HIGH);
  float distance = duracion * 0.034 / 2;
  
  // Imprimir la distancia en el monitor serial
  Serial.print("Distance: ");
  Serial.print(distance);
   Serial.println(" cm");
  
  // Control del servo 
  if (distance <=10 && distance> 0) { 
    miServo.write (180);
    Serial.print("Objeto detectado");
  } else{
    miServo.write(0);
  }
  delay(1000);
}
