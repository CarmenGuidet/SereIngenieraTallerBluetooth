#include <SoftwareSerial.h>
SoftwareSerial bluetoothSerial(12, 13);  
const int trigPin = 9;
const int echoPin = 8;

void setup() {
  bluetoothSerial.begin(9600);     
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);   
}

void loop() {
  long duration; 
  int distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lee la duración del pulso en el pin echo
  duration = pulseIn(echoPin, HIGH);

  // Calcula la distancia en centímetros
  distance = duration / 59;

  // Envia la distancia por el Bluetooth
  bluetoothSerial.print("Distancia: ");
  bluetoothSerial.print(distance);
  bluetoothSerial.println(" cm");
  
  delay(1000);
}
