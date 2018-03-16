//Start Smoothing
const int numReadings = 20;
int readings[numReadings];
int readIndex = 0;
int total = 0;
int TankValue0 = 0;
//End Smoothing

//Start LED Blink
int ledState = LOW;
unsigned long previousMillis = 0;
const long interval = 250;    //Low fuel LED blink interval
//END LED Blink

int analogPin = A0;           //Pin set int
int lowval = 370;             //Set analog low value for conversion
int highval = 750;            //Set analog high value for conversion
int TankValueUnsmoothed;
void setup() {
Serial.begin(9600);
pinMode(A0, INPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);

//Set Readings to 0
for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
}
}

void loop() {
  unsigned long currentMillis = millis();

if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

  
  int sensorTankValue0 = analogRead(analogPin);
  TankValueUnsmoothed = map(sensorTankValue0, lowval, highval, 100, 0);
  
total = total - readings[readIndex];
readings[readIndex] = TankValueUnsmoothed;
total = total + readings[readIndex];
readIndex = readIndex + 1;

if (readIndex >= numReadings)
{
  readIndex = 0;
}
TankValue0 = total / numReadings;


  
  
    //Control LEDs
  if (TankValue0 >= 100)
  {
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
   }
  else if (TankValue0 < 100 && TankValue0 >= 90)
  {
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
  }
  else if (TankValue0 < 90 && TankValue0 >= 80)
  {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
  }
  else if (TankValue0 < 80 && TankValue0 >= 70)
  {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
  }
  else if (TankValue0 < 70 && TankValue0 >= 60)
  {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
  }
  else if (TankValue0 < 60 && TankValue0 >= 50)
  {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
  }
  else if (TankValue0 < 50 && TankValue0 >= 40)
  {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
  }
  else if (TankValue0 < 40 && TankValue0 >= 30)
  {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
  }
  else if (TankValue0 < 30 && TankValue0 >= 20)
  {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
  }
  else if (TankValue0 < 20 && TankValue0 >= 10)
  {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
  }
  else if (TankValue0 < 10)
  {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, ledState);
  }  
  Serial.println(currentMillis);

}
}
