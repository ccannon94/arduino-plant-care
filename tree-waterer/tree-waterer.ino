//declare constants
const int floatSensor1Pin = 2;
const int floatSensor2Pin = 3;
const int floatSensor3Pin = 4;
const int solenoidPin = 7;

//declare variables
int timeCounter = 0;
int floatCounter = 0;

void setup() {
    // put your setup code here, to run once:
    pinMode(floatSensor1Pin, INPUT_PULLUP);
    pinMode(floatSensor2Pin, INPUT_PULLUP);
    pinMode(floatSensor3Pin, INPUT_PULLUP);
    pinMode(solenoidPin, OUTPUT);
}

void loop() {
    // put your main code here, to run repeatedly:
    if(timeCounter >= 10000) {
        
        if(waterIsLow) {
          actuateSolenoid();
        }

        timeCounter = 0;
    }
    timeCounter++;
}

void actuateSolenoid() {
  bool lowWater = true;

  digitalWrite(solenoidPin, HIGH);
  
  while(lowWater) {
    delay(500);
    if(!waterIsLow) lowWater = false;
  }
  digitalWrite(solenoidPin, LOW);
}

bool waterIsLow() {
  if(digitalRead(floatSensor1Pin) == LOW) floatCounter++;
  if(digitalRead(floatSensor2Pin) == LOW) floatCounter++;
  if(digitalRead(floatSensor3Pin) == LOW) floatCounter++;

  if(floatCounter >= 2) {
    floatCounter = 0;
    return true;
  }

  floatCounter = 0;
  return false;
}

