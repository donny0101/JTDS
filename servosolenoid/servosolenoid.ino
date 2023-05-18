int D3 = 3; //pin 3
int D4 = 4; //pin 4
int d3temp=0;


void setup() {
  // put your setup code here, to run once:
  pinMode(D3, INPUT);
  pinMode(D4, OUTPUT);
  //if (d3temp < 127)
   // digitalWrite(D4, HIGH);
  //digtalWrite(D4,0)
  //delay(1000);
  //input is high, turn off solenoid
  //digitalWrite(D3,245);
  //d3temp = digitalRead(D3);
  //if (d3temp > 127)
   // digitalWrite(D4, LOW); 
  //delay(2000);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //input is low, drives solenoid
  //digitalWrite(D3,0);
  delay(10);
  d3temp = digitalRead(D3);
  Serial.println(d3temp);
  if (d3temp == LOW){
    digitalWrite(D4, 151);
  }

  else{
    digitalWrite(D4, LOW);
  }
  
  
}
