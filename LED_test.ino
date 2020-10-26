// This program helps identify the correct RGB LED pins to ensure 
// the correct colors are being controlled by the correct signals
//
// This program will print a message on the Serial connection for
// which LED and color is being tested, and then fade the LED color on
// If the color being faded does not match the message in the Serial
// connection, then the signal is controlling the wrong LED pin.

//Pin Assignment
const int LEDAred = 3;
const int LEDAgreen = 5;
const int LEDAblue = 6;

const int LEDBred = 9;
const int LEDBgreen = 10;
const int LEDBblue = 11;

//Set fade speed
const int FADE_SPEED = 20;

void setup() {
  //Code that runs only once at startup
  
  //Initialize Serial communication
  Serial.begin(9600);

  //Set digital pin direction (input vs output)
  pinMode(LEDAred, OUTPUT);
  pinMode(LEDAgreen, OUTPUT);
  pinMode(LEDAblue, OUTPUT);

  pinMode(LEDBred, OUTPUT);
  pinMode(LEDBgreen, OUTPUT);
  pinMode(LEDBblue, OUTPUT);
}

void loop() {
  //Code that runs continuously after startup

  //Loop between 0 and 255
  for(int i = 0; i<=255; i++){
    //Print message via Serial connection back to PC
    Serial.print("LED A - Red: ");
    Serial.println(i);

    //Write PWM value between 0 and 255 out to LED A red pin to set current brightness
    analogWrite(LEDAred, i);

    //Wait a short amount of time before going to next iteration to setup how quickly the fade occurs
    delay(FADE_SPEED);
  }
  //Reset brightness on red pin to 0 before moving to next color pin
  analogWrite(LEDAred, 0);

  //Repeat above for all indivudual color pins on both LEDs to confirm each color works as expected
  for(int i = 0; i<=255; i++){
    Serial.print("LED A - Green: ");
    Serial.println(i);
    analogWrite(LEDAgreen, i);
    delay(FADE_SPEED);
  }
  analogWrite(LEDAgreen, 0);

  for(int i = 0; i<=255; i++){
    Serial.print("LED A - Blue: ");
    Serial.println(i);
    analogWrite(LEDAblue, i);
    delay(FADE_SPEED);
  }
  analogWrite(LEDAblue, 0);

  for(int i = 0; i<=255; i++){
    Serial.print("LED B - Red: ");
    Serial.println(i);
    analogWrite(LEDBred, i);
    delay(FADE_SPEED);
  }
  analogWrite(LEDBred, 0);

  for(int i = 0; i<=255; i++){
    Serial.print("LED B - Green: ");
    Serial.println(i);
    analogWrite(LEDBgreen, i);
    delay(FADE_SPEED);
  }
  analogWrite(LEDBgreen, 0);

  for(int i = 0; i<=255; i++){
    Serial.print("LED B - Blue: ");
    Serial.println(i);
    analogWrite(LEDBblue, i);
    delay(FADE_SPEED);
  }
  analogWrite(LEDBblue, 0);
}
