//declare constants
const int floatSensor1Pin = 13;
const int floatSensor2Pin = 12;
const int floatSensor3Pin = 11;
const int solenoidPin = 10;

//declare variables
int timeCounter = 0;
int floatCounter = 0;

void setup() {
    // put your setup code here, to run once:
    pinMode(floatSensor1Pin, INPUT);
    pinMode(floatSensor2Pin, INPUT);
    pinMode(floatSensor3Pin, INPUT);
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
  if(digitalRead(floatSensor1Pin) == HIGH) floatCounter++;
  if(digitalRead(floatSensor2Pin) == HIGH) floatCounter++;
  if(digitalRead(floatSensor3Pin) == HIGH) floatCounter++;

  if(floatCounter >= 2) {
    floatCounter = 0;
    return true;
  }

  floatCounter = 0;
  return false;
}

