/* 
  This sketch turns the Bean into a bluetooth Midi controller. 
  The sketch requires a button to be used with the Bean. 
  
  When the button is pushed, the note C4 is held.
  When the button is released, the note C4 is released. 
  
  This example code is in the public domain.
*/

const int buttonPin = 0;
int previousButtonReading = 0;

void setup() {
  BeanHid.enable();
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Read the button's state
  int buttonReading = digitalRead(buttonPin);

  if(buttonReading == HIGH && previousButtonReading == LOW) {
    BeanHid.sendMediaControl(VOLUME_UP);
//    BeanHid.sendKeys("TEST");
  }

  previousButtonReading = buttonReading;
}
