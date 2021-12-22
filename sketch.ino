#include <Keypad.h>
#define makeKeymap(x) ((char*)x)

const byte ROWS = 4;
const byte COLS = 4;

byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
  };
  
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// This is our password
const String password = "1234";
//This is whatever the user is typing on the keypad
String userInput;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  userInput.reserve(32);
  // Set output pin for LED  
  pinMode(13, OUTPUT);
}

void loop() {
 
  char keyInput = keypad.getKey(); 
  if(keyInput){
    Serial.println(keyInput);
    if(keyInput == '*'){
      // Clear input
      userInput = "";
    }
    if(keyInput == '#'){
      if(password == userInput){
            Serial.println("You shall pass!");
             userInput = "";
      }
      else{
            Serial.println("You shall NOT pass!!");
             // Turn LED on when program starts 
            digitalWrite(13, HIGH);
            // Kep the light on for 4 seconds
            delay(4000);
            digitalWrite(13, LOW);
      }
    }
    else{     
      userInput += keyInput;
    }
  }
}
