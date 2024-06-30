#include <SoftwareSerial.h> 
SoftwareSerial bluetoothSerial(10, 11);
int LED = 13; 
void setup() { 
  pinMode(LED, OUTPUT); 
  Serial.begin(115200); 
  bluetoothSerial.begin(9600); 
}

void loop() { 
  if (bluetoothSerial.available()) { 
    char data_received; 
    data_received = bluetoothSerial.read(); 
    if (data_received == '1'){ 
      digitalWrite(LED, HIGH); 
      bluetoothSerial.write("LED turned ON\n");
    }
    else if (data_received == '2'){
      digitalWrite(LED, LOW); 
      bluetoothSerial.write("LED turned OFF\n"); 
    }
    else{
      bluetoothSerial.write("Select either 1 or 2"); 
    }
  }
}
