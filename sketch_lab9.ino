int LED1pin = 43;
int LED2pin = 44;
int LED3pin = 45;
int LED4pin = 46;
int button1pin = 38;
int button2pin = 39;

int lastButton1State = LOW;  
int lastButton2State = LOW;  


int led1State = LOW;    
int led2State = LOW;  
int led3State = LOW;  
int led4State = LOW;  


bool systemOn = false; 
int currentMode = 1;  


unsigned long previousMillis = 0;
const long interval = 1000; 
int sequenceStep = 0;       

void setup() {
  pinMode(LED1pin, OUTPUT);
  pinMode(LED2pin, OUTPUT);
  pinMode(LED3pin, OUTPUT);
  pinMode(LED4pin, OUTPUT);
  pinMode(button1pin, INPUT);
  pinMode(button2pin, INPUT);
}

void loop() {

  int currentButton1State = digitalRead(button1pin);
  int currentButton2State = digitalRead(button2pin);


  if (currentButton1State == HIGH && lastButton1State == LOW) {
    systemOn = !systemOn; 
    
 
    if (!systemOn) {
      turnAllLEDsOff();
      sequenceStep = 0;
    }
    delay(50);
  }
  lastButton1State = currentButton1State;

  if (systemOn) {
    if (currentButton2State == HIGH && lastButton2State == LOW) {
      currentMode++;
      if (currentMode > 3) {
        currentMode = 1;
      }
      
    
      turnAllLEDsOff();
      sequenceStep = 0;
      previousMillis = millis();
      delay(50);
    }
  }
  lastButton2State = currentButton2State;

  if (systemOn) {
    unsigned long currentMillis = millis();


    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      
      if (currentMode == 1) {
        led1State = !led1State;
        led2State = led1State;
        led3State = led1State;
        led4State = led1State;
        
        applyLEDStates();
      } 
     
      else if (currentMode == 2) {
        turnAllLEDsOff(); 
        
        if (sequenceStep == 0) led1State = HIGH;
        else if (sequenceStep == 1) led2State = HIGH;
        else if (sequenceStep == 2) led3State = HIGH;
        else if (sequenceStep == 3) led4State = HIGH;
        
        applyLEDStates();
        sequenceStep = (sequenceStep + 1) % 4; 
      } 
     
      else if (currentMode == 3) {
        turnAllLEDsOff(); 
        
        if (sequenceStep == 0) led4State = HIGH;
        else if (sequenceStep == 1) led3State = HIGH;
        else if (sequenceStep == 2) led2State = HIGH;
        else if (sequenceStep == 3) led1State = HIGH;
        
        applyLEDStates();
        sequenceStep = (sequenceStep + 1) % 4; 
      }
    }
  }
}


void turnAllLEDsOff() {
  led1State = LOW;
  led2State = LOW;
  led3State = LOW;
  led4State = LOW;
  applyLEDStates();
}


void applyLEDStates() {
  digitalWrite(LED1pin, led1State);
  digitalWrite(LED2pin, led2State);
  digitalWrite(LED3pin, led3State);
  digitalWrite(LED4pin, led4State);
}