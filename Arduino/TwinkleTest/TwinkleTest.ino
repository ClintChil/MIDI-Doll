/* 
  This sketch turns the Bean into a bluetooth Midi controller. 
  The sketch requires a button to be used with the Bean. 
  
  When the button is pushed, the note C4 is held.
  When the button is released, the note C4 is released. 
  
  This example code is in the public domain.
*/
// Twinkle Little Star
midiNotes notes[] = {NOTE_C2, NOTE_C2, NOTE_G2, NOTE_G2, NOTE_A2, NOTE_A2, NOTE_G2, NOTE_F2, NOTE_F2, NOTE_E2, NOTE_E2, NOTE_D2, NOTE_D2, NOTE_C2};
// Row Your Boat
midiNotes notes1[] = {NOTE_C2, NOTE_C2, NOTE_C2, NOTE_D2, NOTE_E2, NOTE_E2, NOTE_D2, NOTE_E2, NOTE_F2, NOTE_G2, NOTE_C3, NOTE_C3, NOTE_C3, NOTE_G2, NOTE_G2, NOTE_G2, NOTE_E2, NOTE_E2, NOTE_E2, NOTE_C2, NOTE_C2, NOTE_C2, NOTE_G2, NOTE_F2, NOTE_E2, NOTE_D2, NOTE_C2};

const int buttonPin = 0;
int previousButtonReading = 0;
int index = 0;


void setup() {
  BeanMidi.enable();
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Read the button's state
  int buttonReading = digitalRead(buttonPin);

  // If the button has just been pressed 
  if(buttonReading == HIGH && previousButtonReading == LOW) { 
    BeanMidi.noteOn(CHANNEL1, notes[index], 90); // hold note
  }
  // If the button has just been released 
  else if(buttonReading == LOW && previousButtonReading == HIGH) {
    BeanMidi.noteOff(CHANNEL1, notes[index], 90); // release note

    //FIXME make 13 a dynamic variable, last item in array
    if (index >= 13) {
      index = 0;
    } else {
      index++;
    }
  }

  previousButtonReading = buttonReading;
}
