
//
const int ledRedPin=13;
const int ledYellowPin=12;
const int ledGreenPin=7;
const int pinGreen=11;
const int buttonPin=2;

int buttonCurrentState=0;
int buttonLastState = 0;
int buttonPressCount=0;
// for case 2 
bool ledWord = true;

void setup()
{
  pinMode(ledRedPin, OUTPUT);
  pinMode(ledYellowPin, OUTPUT);
  pinMode(ledGreenPin, OUTPUT);
  
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin),handleButtonInterrupt, FALLING);
  
}
void handleButtonInterrupt(){
buttonPressCount++;
  if(buttonPressCount == 4 ){
	buttonPressCount = 0;
}
  // only for case 2
  ledWord = false;

}

void caseOne(){
  // change color by press button
	if(buttonPressCount == 1){
    	digitalWrite(ledRedPin, HIGH);
        digitalWrite(ledYellowPin, LOW);
        digitalWrite(ledGreenPin, LOW);
    }
    else if(buttonPressCount == 2){
    	digitalWrite(ledRedPin, LOW);
        digitalWrite(ledYellowPin, HIGH);
        digitalWrite(ledGreenPin, LOW);
    }
    else if(buttonPressCount == 3){
    	digitalWrite(ledRedPin, LOW);
        digitalWrite(ledYellowPin, LOW);
        digitalWrite(ledGreenPin, HIGH);
  	}else if(buttonPressCount == 0){
  		// 4 press all low
    	digitalWrite(ledRedPin, LOW);
        digitalWrite(ledYellowPin, LOW);
        digitalWrite(ledGreenPin, LOW);
  	}
}

void caseTwo(){
// he program will turn LEDs on and off one by one in a loop until the button is pressed.
  while(ledWord){
  	digitalWrite(ledRedPin, HIGH);
    digitalWrite(ledYellowPin, LOW);
    digitalWrite(ledGreenPin, LOW);
    delay(2000);
    
    digitalWrite(ledRedPin, LOW);
    digitalWrite(ledYellowPin, HIGH);
    digitalWrite(ledGreenPin, LOW);
    delay(2000);
    
    digitalWrite(ledRedPin, LOW);
    digitalWrite(ledYellowPin, LOW);
    digitalWrite(ledGreenPin, HIGH);
    delay(2000);
  }
  
  digitalWrite(ledRedPin, LOW);
  digitalWrite(ledYellowPin, LOW);
  digitalWrite(ledGreenPin, LOW);
  
}

void loop()
{
// please uncomment one method and comment another
//test commit new branch
  caseOne();
  caseTwo();
}