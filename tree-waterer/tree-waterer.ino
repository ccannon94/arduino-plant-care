//declare constants
const int floatSensor1Pin = 2;
const int floatSensor2Pin = 3;
const int timeoutLedPin = 5;
const int solenoidPin = 7;

//declare variables
int timeCounter = 0;
int floatCounter = 0;
int timeoutCounter = 0

int fillTimeLog[50];
int currentLogLocaton = 0;

void setup() {
    pinMode(floatSensor1Pin, INPUT_PULLUP);
    pinMode(floatSensor2Pin, INPUT_PULLUP);
    pinMode(timeoutLedPin, OUTPUT);
    pinMode(solenoidPin, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    if(timeCounter >= 10000) {
        
        if(waterIsLow) {
          actuateSolenoid();
        }

        timeCounter = 0;
    }
    timeCounter++;
    Serial.println(fillTimeLog);
}

void actuateSolenoid() {
  bool lowWater = true;

  digitalWrite(solenoidPin, HIGH);
  
  while(lowWater) {
    delay(200);
    if(!waterIsLow) lowWater = false;
    timeoutCounter++;

    if(timeoutCounter >= 600) {
      timeout();
    }
  }

  fillTimeLog[currentLogLocation] = timeoutCounter;
  currentLogLocation ++;
  
  digitalWrite(solenoidPin, LOW);
  timeoutCounter = 0;
}

bool waterIsLow() {
  if(digitalRead(floatSensor1Pin) == LOW) floatCounter++;
  if(digitalRead(floatSensor2Pin) == LOW) floatCounter++;

  if(floatCounter > 0) {
    floatCounter = 0;
    return true;
  }

  floatCounter = 0;
  return false;
}

void timeout() {
  while(true) {
    digitalWrite(solenoidPin, LOW);
    digitalWrite(timeoutLedPin, HIGH);
  }
}

