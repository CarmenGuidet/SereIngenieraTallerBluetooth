#include <SoftwareSerial.h> 
SoftwareSerial bluetoothserial(10, 11); 

void setup(){ 
  Serial.begin(115200); 
  bluetoothserial.begin(9600) ; 
} 

void loop(){  
  if (bluetoothserial.available()){
    char dataBluetooth = bluetoothserial.read(); 
    Serial.print(dataBluetooth);
  }
  if (Serial.available()){
    char dataPC = Serial.read(); 
    bluetoothserial.print(dataPC);
  }
}
