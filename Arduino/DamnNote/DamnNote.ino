/* 
  This sketch turns the Bean into a bluetooth Midi controller. 
  The sketch requires a button to be used with the Bean. 
  
  When the button is pushed, the note C4 is held.
  When the button is released, the note C4 is released. 
  
  This example code is in the public domain.
*/

//static const char message[] = "L";

const int buttonPin = 0;
int previousButtonReading = 0;

void setup() {
  BeanMidi.enable();
//  BeanHid.enable();
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Read the button's state
  int buttonReading = digitalRead(buttonPin);

  // If the button has just been pressed 
  if(buttonReading == HIGH && previousButtonReading == LOW) {
    
    BeanMidi.noteOn(CHANNEL0, NOTE_C4, 127); // hold note
  
//  // send media control play command
//  BeanHid.sendMediaControl(PLAY);

  // send keyboard key
//  BeanHid.sendKey(message[0]);
  }
  // If the button has just been released 
  else if(buttonReading == LOW && previousButtonReading == HIGH) {
    BeanMidi.noteOff(CHANNEL0, NOTE_C4, 127); // release note
  }

  previousButtonReading = buttonReading;
}
