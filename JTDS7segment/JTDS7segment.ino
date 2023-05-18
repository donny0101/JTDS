int dataPin=3; //ser to pin3
int latchPin=2; //rclk to pin2
int clockPin=4; //srclk to pin4
int health = 69;
int counter=0;

byte one[7]={1,0,0,1,1,1,1};

const int digitPins[2]={5,6};

void lab3checkoff(){

  while(counter < 150){
  //left digit
  digitalWrite(digitPins[0],HIGH); //left on 
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 18); //0
  digitalWrite(latchPin,HIGH);
  delay(30);
  digitalWrite(digitPins[0],LOW);
  delay(5);

  digitalWrite(digitPins[1],HIGH); //right on
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 6); //3
  digitalWrite(latchPin,HIGH);
  delay(30);
  digitalWrite(digitPins[1],LOW);
  delay(5);
  counter = counter+1;
  Serial.println(counter);
  }
  
  
  while(counter<300){
  //left digit
  digitalWrite(digitPins[0],HIGH); //left on 
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 50); //4
  digitalWrite(latchPin,HIGH);
  delay(30);
  digitalWrite(digitPins[0],LOW);
  delay(5);

  digitalWrite(digitPins[1],HIGH); //right on
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0); //8
  digitalWrite(latchPin,HIGH);
  delay(30);
  digitalWrite(digitPins[1],LOW);
  delay(5);
  counter=counter+1;
  Serial.println(counter);
  }
  counter=0;
  delay(50);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(dataPin,OUTPUT);
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  for(int i=0;i<2;i++){
    pinMode(digitPins[i],OUTPUT);
  }
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  while(health==69){
    lab3checkoff();
  }
  //0
  digitalWrite(digitPins[0],HIGH);
  digitalWrite(digitPins[1],HIGH);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 1);
  digitalWrite(latchPin,HIGH);
  delay(1000);
  digitalWrite(digitPins[0],LOW);
  digitalWrite(digitPins[1],LOW);
  //digitalWrite(latchPin,LOW);
  delay(100);

  //1
  digitalWrite(digitPins[0],HIGH);
  digitalWrite(digitPins[1],HIGH);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, B01001111);
  digitalWrite(latchPin,HIGH);
  delay(1000);
  digitalWrite(digitPins[0],LOW);
  digitalWrite(digitPins[1],LOW);
  //digitalWrite(latchPin,LOW);
  delay(100);

  //2
  digitalWrite(digitPins[0],HIGH);
  digitalWrite(digitPins[1],HIGH);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 18);
  digitalWrite(latchPin,HIGH);
  delay(1000);
  digitalWrite(digitPins[0],LOW);
  digitalWrite(digitPins[1],LOW);
  //digitalWrite(latchPin,LOW);
  delay(100);

  //3
  digitalWrite(digitPins[0],HIGH);
  digitalWrite(digitPins[1],HIGH);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 6);
  digitalWrite(latchPin,HIGH);
  delay(1000);
  digitalWrite(digitPins[0],LOW);
  digitalWrite(digitPins[1],LOW);
  //digitalWrite(latchPin,LOW);
  delay(100);

  //4
  digitalWrite(digitPins[0],HIGH);
  digitalWrite(digitPins[1],HIGH);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 50);
  digitalWrite(latchPin,HIGH);
  delay(1000);
  digitalWrite(digitPins[0],LOW);
  digitalWrite(digitPins[1],LOW);
  //digitalWrite(latchPin,LOW);
  delay(100);

  //5
  digitalWrite(digitPins[0],HIGH);
  digitalWrite(digitPins[1],HIGH);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 36);
  digitalWrite(latchPin,HIGH);
  delay(1000);
  digitalWrite(digitPins[0],LOW);
  digitalWrite(digitPins[1],LOW);
  //digitalWrite(latchPin,LOW);
  delay(100);

  //6
  digitalWrite(digitPins[0],HIGH);
  digitalWrite(digitPins[1],HIGH);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 5);
  digitalWrite(latchPin,HIGH);
  delay(1000);
  digitalWrite(digitPins[0],LOW);
  digitalWrite(digitPins[1],LOW);
  //digitalWrite(latchPin,LOW);
  delay(100);



  //7
  digitalWrite(digitPins[0],HIGH);
  digitalWrite(digitPins[1],HIGH);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 15);
  digitalWrite(latchPin,HIGH);
  delay(1000);
  digitalWrite(digitPins[0],LOW);
  digitalWrite(digitPins[1],LOW);
  //digitalWrite(latchPin,LOW);
  delay(100);

  //8
  digitalWrite(digitPins[0],HIGH);
  digitalWrite(digitPins[1],HIGH);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0);
  digitalWrite(latchPin,HIGH);
  delay(1000);
  digitalWrite(digitPins[0],LOW);
  digitalWrite(digitPins[1],LOW);
  //digitalWrite(latchPin,LOW);
  delay(200);

  //9
  digitalWrite(digitPins[0],HIGH);
  digitalWrite(digitPins[1],HIGH);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 4);
  digitalWrite(latchPin,HIGH);
  delay(1000);
  digitalWrite(digitPins[0],LOW);
  digitalWrite(digitPins[1],LOW);
  //digitalWrite(latchPin,LOW);
  delay(100);

  //blank
  digitalWrite(digitPins[0],HIGH);
  digitalWrite(digitPins[1],HIGH);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 127);
  digitalWrite(latchPin,HIGH);
  delay(1000);
  digitalWrite(digitPins[0],LOW);
  digitalWrite(digitPins[1],LOW);
  //digitalWrite(latchPin,LOW);
  delay(100);


}
