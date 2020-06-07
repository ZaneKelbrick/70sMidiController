/**
   ENEL599 Physical Computing 2018 Final

   Final Submission - Start Code

   !!!!!!! PLEASE NOTE - This is not the Final Version!!!!!!!!

  This Project was inspired by the work of Sam Battle (LOOK MUM NO COMPUTER),
  I drew from his https://www.lookmumnocomputer.com/projects/#/sequencer-keyboard/,
  fully reformating and refining the code, yet I may have gotten in a bit to deep
  with the use of arrays. All the code does at the moment is scan the buttons and
  print thier values over serial - I struggled to get the leds to turn on too
  along with other parts. However this is also my studio project, and it will be more
  than finished for the showing on wednesday. - I have sent you an email regarding my predicament.
  (thought it was better to submit something rather than just leave it)

   @author Zane Kelbrick, Student ID# 17988257
   @version 3.0 - 19.10.2018
*/
#include <MozziGuts.h>
#include <Sample.h> // Sample template
#include <samples/burroughs1_18649_int8.h> // a converted audio sample included in the Mozzi download

const int PIN_STEPBUTTON[8] = {14, 15, 16, 17, 18, 19, 11, 12}; // the number of button pins
const int NUM_STEPBUTTONS = sizeof(PIN_STEPBUTTON) / sizeof(PIN_STEPBUTTON[0]); // number of Buttons 

const int KNOB_PIN = A6;  // set the analog input pin for the knob

const int PIN_LED[8] = {2, 3, 5, 4, 6, 7, 8, 10};
const int NUM_LEDS = sizeof(PIN_LED) / sizeof(PIN_LED[0]); // number of LEDs

int padVal[8];
int old_padVal[8];

// use: Sample <table_size, update_rate> SampleName (wavetable)
Sample <BURROUGHS1_18649_NUM_CELLS, AUDIO_RATE> aSample(BURROUGHS1_18649_DATA);
float recorded_pitch = (float) BURROUGHS1_18649_SAMPLERATE / (float) BURROUGHS1_18649_NUM_CELLS;

boolean triggered = false;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < NUM_STEPBUTTONS; i++) {
    pinMode(PIN_STEPBUTTON[i], INPUT_PULLUP);
  }
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(PIN_LED[i], OUTPUT);
  }
    startMozzi(); // :))
}
void updateControl(){
  // read the knob
   int knob_value = mozziAnalogRead(KNOB_PIN); // value is 0-1023

  // map it to values between 0.1 and about double the recorded pitch
  float pitch = (recorded_pitch * (float) knob_value / 512.f) + 0.1f; 

  // set the sample playback frequency
  aSample.setFreq(pitch);
    
  for ( int i = 0; i < NUM_STEPBUTTONS; i++) {
    padVal[i] = digitalRead(PIN_STEPBUTTON[i]);  
  if (padVal[i] == 1) {
    digitalWrite(PIN_LED[i], HIGH);

  }
  else
    digitalWrite(PIN_LED[i], LOW);

  }
}
int updateAudio(){
  return aSample.next();
}

void loop() {
audioHook();
}
