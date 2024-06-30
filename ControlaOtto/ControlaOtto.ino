// Controlando a Otto por Bluetooth
#include <SoftwareSerial.h>
#include <Otto.h>
Otto Otto;
SoftwareSerial bluetoothSerial(13, 12);  
#define LeftLeg 2 
#define RightLeg 3
#define LeftFoot 4 
#define RightFoot 5 
#define Buzzer  10
const int trigPin = 9;
const int echoPin = 8;
const int speakerPin = 10;
void setup() {
 Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer); //Set the servo pins and Buzzer pin
 bluetoothSerial.begin(9600);     
 pinMode(trigPin, OUTPUT);  
 pinMode(echoPin, INPUT); 
 pinMode(speakerPin, OUTPUT);
}

void loop() {
  if (bluetoothSerial.available()){
    char data_received;
    data_received =  bluetoothSerial.read();
    if (data_received == '1'){
      Otto.walk(2,2000,1);
      noTone(speakerPin);
    }
    else if (data_received == '2'){
        tone(speakerPin, 440);
        delay(1000);
        tone(speakerPin, 524);
        delay(500);
        tone(speakerPin, 494);
        delay(500);
     }
    else if (data_received == '3'){
      noTone(speakerPin);
      }
    else {
        bluetoothSerial.print("Seleciona Camina(1), Canta(2) o Para(3)");
      } 
    }
   
}
