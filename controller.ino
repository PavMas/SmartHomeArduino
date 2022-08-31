const int SWITCH_LED1 = 0x4;
const int SWITCH_LED2 = 0x5;
const int CONNECTED = 0x6;
const int DISCONNECTED = 0x7;

const int lightsPin1 = 6;
const int lightsPin2 = 7;

const initController() {
  pinMode(lightsPin1, OUTPUT);
  pinMode(lightsPin2, OUTPUT);

}

void executeCommand(int cmd[]) {
  switch(cmd[1]) {
    case SWITCH_LED1: switchLight(cmd[3], lightsPin1); break;
    case SWITCH_LED2: switchLight(cmd[3], lightsPin2); break;
    case CONNECTED:  
      lcd.clear(); 
      lcd.print("BT Le status:");
      lcd.setCursor(0, 1);
      lcd.print("Connected"); break;
    case DISCONNECTED:  
      lcd.clear(); 
      lcd.print("BT Le status:");
      lcd.setCursor(0, 1);
      lcd.print("Disonnected"); break;
      
  }
}

void switchLight(int v, int pin) {
  if(v == 0) {
    Serial.println("Switch the linght off");
  }else {
    Serial.println("Switch the linght on");
  }
  
  switchLED(pin, v);
}

void switchLED(int pin, int value) {
    analogWrite(pin, value);
}
