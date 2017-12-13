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
    pinMode(floatSensor1Pin, input);
    pinMode(floatSensor2Pin, input);
    pinMode(floatSensor3Pin, input);
    pinMode(solenoidPin, output);
}

void loop() {
    // put your main code here, to run repeatedly:
    if(timeCounter >= 10000) {
        if(digitalRead(floatSensor1Pin) == HIGH) floatCounter++;
        if(digitalRead(floatSensor2Pin) == HIGH) floatCounter++;
        if(digitalRead(floatSensor3Pin) == HIGH) floatCounter++;

        if(floatCounter >= 2) {
          actuateSolenoid();
          floatCounter = 0;
        }

        timeCounter = 0;
    }
}

void actuateSolenoid() {
  //implement method
}

