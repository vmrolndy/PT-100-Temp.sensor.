#include <LiquidCrystal.h> 
int Contrast=75;
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
   analogWrite(6,Contrast);
     lcd.begin(16, 2);
}
void loop() {
  int sensorValue = analogRead(A0);
//****************************************************************************************//
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1024.0);
//****************************************************************************************//
//************ I = voltage / Known Resistor *******************//
  float I = voltage / 1000;
  float VRx = 5 - voltage; 
  float Rx = VRx / I;
  Rx = (5 - voltage) / I;
  int Tx;
  int Out ;
  Tx = map(Rx, 1000, 2740, 0, 480);
  Out = Tx ;
//********Print***************//
  ("Temperature:");
  Serial.print(Out);
  (" °C");
  lcd.setCursor(0, 0);
    lcd.print("Temp. is: ");
    lcd.print(Tx);
  delay(1000);
}
