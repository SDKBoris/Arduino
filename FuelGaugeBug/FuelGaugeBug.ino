int addr = 0;
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
int lowval = 320;             //Set analog low value for conversion (fuel high)
int highval = 600;            //Set analog high value for conversion (fuel low)
int TankValueUnsmoothed;

int b10 = 2; //Indicator Bar 10%
int b20 = 3; //Indicator Bar 20%
int b30 = 4; //Indicator Bar 30%
int b40 = 5; //Indicator Bar 40%
int b50 = 6; //Indicator Bar 50%
int b60 = 7; //Indicator Bar 60%
int b70 = 8; //Indicator Bar 70%
int b80 = 9; //Indicator Bar 80%
int b90 = 10; //Indicator Bar 90%
int b100 = 11; //Indicator Bar 100%

void setup() {
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
//Serial.begin(9600);
//Set Readings to 0
for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
}
    digitalWrite(b10, HIGH);
    delay(50);
    digitalWrite(b20, HIGH);
    delay(50);
    digitalWrite(b30, HIGH);
    delay(50);
    digitalWrite(b40, HIGH);
    delay(50);
    digitalWrite(b50, HIGH);
    delay(50);
    digitalWrite(b60, HIGH);
    delay(50);
    digitalWrite(b70, HIGH);
    delay(50);
    digitalWrite(b80, HIGH);
    delay(50);
    digitalWrite(b90, HIGH);
    delay(50);
    digitalWrite(b100, HIGH);
    delay(750);
    digitalWrite(b100, LOW);
    delay(50);
    digitalWrite(b90, LOW);
    delay(50);
    digitalWrite(b80, LOW);
    delay(50);
    digitalWrite(b70, LOW);
    delay(50);
    digitalWrite(b60, LOW);
    delay(50);
    digitalWrite(b50, LOW);
    delay(50);
    digitalWrite(b40, LOW);
    delay(50);
    digitalWrite(b30, LOW);
    delay(50);
    digitalWrite(b20, LOW);
    delay(50);
    digitalWrite(b10, LOW);
    delay(50);
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
    digitalWrite(b100, HIGH);
    digitalWrite(b90, HIGH);
    digitalWrite(b80, HIGH);
    digitalWrite(b60, HIGH);
    digitalWrite(b50, HIGH);
    digitalWrite(b50, HIGH);
    digitalWrite(b40, HIGH);
    digitalWrite(b30, HIGH);
    digitalWrite(b20, HIGH);
    digitalWrite(b10, HIGH);
   }
  else if (TankValue0 < 100 && TankValue0 >= 90)
   {
    digitalWrite(b100, LOW);
    digitalWrite(b90, HIGH);
    digitalWrite(b80, HIGH);
    digitalWrite(b70, HIGH);
    digitalWrite(b60, HIGH);
    digitalWrite(b50, HIGH);
    digitalWrite(b40, HIGH);
    digitalWrite(b30, HIGH);
    digitalWrite(b20, HIGH);
    digitalWrite(b10, HIGH);
  }
  else if (TankValue0 < 90 && TankValue0 >= 80)
  {
    digitalWrite(b100, LOW);
    digitalWrite(b90, LOW);
    digitalWrite(b80, HIGH);
    digitalWrite(b70, HIGH);
    digitalWrite(b60, HIGH);
    digitalWrite(b50, HIGH);
    digitalWrite(b40, HIGH);
    digitalWrite(b30, HIGH);
    digitalWrite(b20, HIGH);
    digitalWrite(b10, HIGH);
  }
  else if (TankValue0 < 80 && TankValue0 >= 70)
  {
    digitalWrite(b100, LOW);
    digitalWrite(b90, LOW);
    digitalWrite(b80, LOW);
    digitalWrite(b70, HIGH);
    digitalWrite(b60, HIGH);
    digitalWrite(b50, HIGH);
    digitalWrite(b40, HIGH);
    digitalWrite(b30, HIGH);
    digitalWrite(b20, HIGH);
    digitalWrite(b10, HIGH);
  }
  else if (TankValue0 < 70 && TankValue0 >= 60)
  {
    digitalWrite(b100, LOW);
    digitalWrite(b90, LOW);
    digitalWrite(b80, LOW);
    digitalWrite(b70, LOW);
    digitalWrite(b60, HIGH);
    digitalWrite(b50, HIGH);
    digitalWrite(b40, HIGH);
    digitalWrite(b30, HIGH);
    digitalWrite(b20, HIGH);
    digitalWrite(b10, HIGH);
  }
  else if (TankValue0 < 60 && TankValue0 >= 50)
  {
    digitalWrite(b100, LOW);
    digitalWrite(b90, LOW);
    digitalWrite(b80, LOW);
    digitalWrite(b70, LOW);
    digitalWrite(b60, LOW);
    digitalWrite(b50, HIGH);
    digitalWrite(b40, HIGH);
    digitalWrite(b30, HIGH);
    digitalWrite(b20, HIGH);
    digitalWrite(b10, HIGH);
  }
  else if (TankValue0 < 50 && TankValue0 >= 40)
  {
    digitalWrite(b100, LOW);
    digitalWrite(b90, LOW);
    digitalWrite(b80, LOW);
    digitalWrite(b70, LOW);
    digitalWrite(b60, LOW);
    digitalWrite(b50, LOW);
    digitalWrite(b40, HIGH);
    digitalWrite(b30, HIGH);
    digitalWrite(b20, HIGH);
    digitalWrite(b10, HIGH);
  }
  else if (TankValue0 < 40 && TankValue0 >= 30)
  {
    digitalWrite(b100, LOW);
    digitalWrite(b90, LOW);
    digitalWrite(b80, LOW);
    digitalWrite(b70, LOW);
    digitalWrite(b60, LOW);
    digitalWrite(b50, LOW);
    digitalWrite(b40, LOW);
    digitalWrite(b30, HIGH);
    digitalWrite(b20, HIGH);
    digitalWrite(b10, HIGH);
  }
  else if (TankValue0 < 30 && TankValue0 >= 20)
  {
    digitalWrite(b100, LOW);
    digitalWrite(b90, LOW);
    digitalWrite(b80, LOW);
    digitalWrite(b70, LOW);
    digitalWrite(b60, LOW);
    digitalWrite(b50, LOW);
    digitalWrite(b40, LOW);
    digitalWrite(b30, LOW);
    digitalWrite(b20, HIGH);
    digitalWrite(b10, HIGH);
  }
  else if (TankValue0 < 20 && TankValue0 >= 10)
  {
    digitalWrite(b100, LOW);
    digitalWrite(b90, LOW);
    digitalWrite(b80, LOW);
    digitalWrite(b70, LOW);
    digitalWrite(b60, LOW);
    digitalWrite(b50, LOW);
    digitalWrite(b40, LOW);
    digitalWrite(b30, LOW);
    digitalWrite(b20, LOW);
    digitalWrite(b10, HIGH);
  }
  else if (TankValue0 < 10)
  {
    digitalWrite(b100, LOW);
    digitalWrite(b90, LOW);
    digitalWrite(b80, LOW);
    digitalWrite(b70, LOW);
    digitalWrite(b60, LOW);
    digitalWrite(b50, LOW);
    digitalWrite(b40, LOW);
    digitalWrite(b30, LOW);
    digitalWrite(b20, LOW);
    digitalWrite(b10, ledState);
  }  
//Serial.print(sensorTankValue0);
//Serial.print('\n');
}
}

