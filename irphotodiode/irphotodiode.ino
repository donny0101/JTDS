//int photodiode_value;
//int LED_bright;
int sensorPin = 0; //a0
int IRLED = 9;
int sensorVal = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(IRLED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //photodiode_value = analogRead(0); //A0 pin
  sensorVal = analogRead(sensorPin); //read ir led value from phototransistor
  delay(5);
  Serial.println("raw sensor val");
  Serial.println(sensorVal);
  //sensorVal = sensorVal/4;
  //Serial.println("mapped sensor val");
  //Serial.println(sensorVal);
  //delay(250);
  //analogWrite(IRLED, 200); //write led brightness
  digitalWrite(IRLED,HIGH);
  //delay(1000);
  //Serial.println(photodiode_value);
  //LED_bright = map(photodiode_value, 0, 1023, 0 , 255);
  //analogWrite(5, 255);
  delay(100); //give led time to change

}
