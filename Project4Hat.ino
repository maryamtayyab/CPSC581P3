int fsrAnalogPin = A0;    // FSR is connected to Analog 6
int scentPin = 4;
int flower1Pin = 5;       // LED is connected to Digital 5
int flower2Pin = 6;       // LED is connected to Digital 6
int flower3Pin = 7;      // LED is connected to Analog 8
int fsrReading;           // the analog reading from the FSR resistor divider
int count = 0;


void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(flower1Pin, OUTPUT);
  pinMode(flower2Pin, OUTPUT);
  pinMode(flower3Pin, OUTPUT);
  pinMode(scentPin, OUTPUT);

}

int lightList[10];
int lightIndex = 0;

void loop(void) {
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print("Analog reading = ");

  lightList[((lightIndex++)%10)] = fsrReading;
  int lightLevel = 0;

  for ( int i = 0 ; i < 10 ; i++){
    lightLevel += lightList[i];
  }

  lightLevel = lightLevel/10;
  
  Serial.println(lightLevel);

  
  //Flower 1
  if(lightLevel <= 100)
    digitalWrite(flower1Pin, HIGH);
  else
    digitalWrite(flower1Pin, LOW);

  //Flower 2
  if(100 < lightLevel && lightLevel < 740)
    digitalWrite(flower2Pin, HIGH);
  else
    digitalWrite(flower2Pin, LOW);

  //Flower 3
  if(740 <= lightLevel)
  {
    digitalWrite(flower3Pin, HIGH);


    
  }
  else
    digitalWrite(flower3Pin, LOW);


  if((count == 0 || count == 1) && 740 <= lightLevel )
    digitalWrite(scentPin, HIGH);

  else
      digitalWrite(scentPin, LOW);
    
    count ++;
    count = count % 5;

 
  delay(1000);
}
