int dataPin=3; //ser to pin3
int latchPin=2; //rclk to pin2
int clockPin=4; //srclk to pin4

int sensorPin=0; //a0 for raw sensor reading
int IRLED =9; //digital pin send signal to amp->IRLED
int sensorVal=0; //phototransistor reading

int health[2] = {3,5}; //initialize titan with 69 health 
int leftDigit = 0;
int rightDigit=0;
int shifter=99;
int yeah=0;

int str1 = MSBFIRST;
int str2 = LSBFIRST;
const int digitPins[2]={5,6};

void IRRead(){
  sensorVal = analogRead(sensorPin); //read phototransistor
  delay(5);
  Serial.println("raw sensor val");
  Serial.println(sensorVal);
  digitalWrite(IRLED,HIGH);
  delay(50);
}

void updateHealth(){
  health[1]=health[1]-1;
  if(health[1]==-1){
    health[1]=9;
    health[0]=health[0]-1;
  }
  
}

void changeHealth(){
  sensorVal = analogRead(sensorPin); //read phototransistor
  delay(5);
  Serial.println("raw sensor val");
  Serial.println(sensorVal);
  if(sensorVal <20){
    updateHealth();
  }

  if((health[0]==0 ) && (health[1]==0)){
    yeah=1;
    gameOver();
  }
  
}



void intToDispL(){
  if(health[0]==6){
    shifter=str2;
    leftDigit=5;
  }

  if(health[0]==4){
    shifter=str2;
    leftDigit=50;
  }

  if(health[0]==3){
    shifter=str1;
    leftDigit=6;
  }

  if(health[0]==2){
    shifter=str1;
    leftDigit=18;
  }

  if(health[0]==1){
    shifter=str1;
    leftDigit= 79;//B01001111;
  }

  if(health[0]==0){
    shifter=str1;
    leftDigit=1;
  }
  
}

void intToDispR(){
  if(health[1]==9){
    shifter=str1;
    rightDigit=4;
  }

  if(health[1]==8){
    shifter=str1;
    rightDigit=0;
  }
  if(health[1]==7){
    shifter=str1;
    rightDigit=15;
  }

  if(health[1]==6){
    shifter=str2;
    rightDigit=5;
  }

  if(health[1]==5){
    shifter=str2;
    rightDigit=36;
  }

  if(health[1]==4){
    shifter=str2;
    rightDigit=50;
  }

  if(health[1]==3){
    shifter=str1;
    rightDigit=6;
  }

  if(health[1]==2){
    shifter=str1;
    rightDigit=18;
  }

  if(health[1]==1){
    shifter=str1;
    rightDigit=B01001111;
  }
  if(health[1]==0){
    shifter=str1;
    rightDigit=1;
  }
  
}

void gameOver(){
  leftDigit=127;
  rightDigit=127;
  shifter=str1;

  digitalWrite(digitPins[0],HIGH);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,shifter,leftDigit);//6
  digitalWrite(latchPin,HIGH);
  delay(45);
  digitalWrite(digitPins[0],LOW);
  delay(5);

  digitalWrite(digitPins[1],HIGH);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, shifter, rightDigit); //9
  digitalWrite(latchPin,HIGH);
  delay(45);
  digitalWrite(digitPins[1],LOW);
  delay(5);


  
  Serial.println("called");
}



void trackHealth(){
  while(yeah==1){
    gameOver();
  }
  //changeHealth();
  //initially titan has 69 health
  //leftDigit=health[0];
  //if((health[0]==0 ) && (health[1]==0)){
  //  gameOver();
  //}
  intToDispL();//update shift and value for display
  //Serial.println("leftDigit");
  //Serial.println(leftDigit);
  //Serial.println("shifter");
  //Serial.println(shifter);
  digitalWrite(digitPins[0],HIGH);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,shifter,leftDigit);//6
  digitalWrite(latchPin,HIGH);
  delay(45);
  digitalWrite(digitPins[0],LOW);
  delay(5);

  //rightDigit=health[1];
  intToDispR();
  digitalWrite(digitPins[1],HIGH);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, shifter, rightDigit); //9
  digitalWrite(latchPin,HIGH);
  delay(45);
  digitalWrite(digitPins[1],LOW);
  delay(5);
  //Serial.println("rightDigit");
  //Serial.println(rightDigit);
  //Serial.println("shifter");
  //Serial.println(shifter);

}

void setup() {
  // put your setup code here, to run once:
  pinMode(dataPin,OUTPUT);
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  for(int i=0;i<2;i++){
    pinMode(digitPins[i],OUTPUT);
  }

  pinMode(sensorPin,INPUT);
  pinMode(IRLED,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  trackHealth();
  digitalWrite(IRLED,HIGH);
  changeHealth();
  //while(yeah==1){
    //IRRead();
  //  trackHealth();
  //}

}
