/*
  Zane Kelbrick - zane.kelbrick@gmail.com
  This is a project that I created for a paper called creative audio, using the MIDI_controller library.
  I connected an analog multiplexer to analog pin A0 with the address lines on pins 10, 16, 14 and 15.
  The Joysticks for the controller were then connected to inputs of the multiplexer and remapped so they worked with Ableton effectively.
  I then connected another 9 potentiometers that were also mapped to midi cc channels. Finally some additonal switches and a rotary 
  encoder and it was done - my blog can be found here : https://www.tumblr.com/blog/zkelbrick-bct
  I should have a website soon. 

  Map accordingly in your DAW or DJ software.

  This would not have been possible without the work of Pieter P, 20-05-2019
  https://github.com/tttapa/MIDI_controller
*/
#define USE_ROTARY_ENCODER
#include <MIDI_Controller.h> // Include the library

const uint8_t Channel = 1;       // MIDI channel 1
const uint8_t Controller = 0x14; // MIDI Control Change controller number
const int speedMultiply = 20;     // No change in speed of the encoder (number of steps is multiplied by 1)

const uint8_t velocity = 0b1111111; // Maximum velocity (0b1111111 = 0x7F = 127)
const unsigned long latchTime = 100; // The duration of the MIDI note (in milliseconds)

// Create a new instance of the class 'RotaryEncoder', called 'enc', on pin 2 and 3, controller number 0x14, on channel1,
// no change in speed (speed is multiplied by 1), it's used as a jog wheel, and the sign mode is set to two's complement.
RotaryEncoder encoder(6, 8, Controller, Channel, speedMultiply, JOG, TWOS_COMPLEMENT);

DigitalLatch switches[] = {
  {3, 0x10, 1, velocity, latchTime}, // Create a new instance of class 'DigitalLatch' on pin 0, note number 16 (mute) on MIDI channel 1, with a predefined latch time
  {4, 0x11, 1, velocity, latchTime},
  {5, 0x12, 1, velocity, latchTime},
};

const uint8_t C4 = 60;              // Note number 60 is defined as middle C in the MIDI specification
const uint8_t D4 = 62;              // Note number 60 is defined as middle C in the MIDI specification

// Digital button(2, C4, 1, velocity);
Digital buttonRotary(7, D4, 1, velocity);


// Create an instance of 'AnalogMultiplex' with the output pin of the multiplexer connected to
// analog input pin A0 and the address pins connected to pins 2, 3 and 4.
AnalogMultiplex multiplexer(A0, { 10, 16, 14, 15 } ); // forgot to change these earlier

// Create 8 new instances of the class 'Analog', on the 8 pins of the multiplexer,
// that send MIDI messages with controller 7 (channel volume) on channels 1 - 8
Analog potentiometer_1(multiplexer.pin(0), MIDI_CC::Breath_Controller, 1);
Analog potentiometer_2(multiplexer.pin(1), MIDI_CC::Modulation_Wheel, 1);
Analog potentiometer_3(multiplexer.pin(2), MIDI_CC::Pan, 1);
Analog potentiometer_4(multiplexer.pin(3), MIDI_CC::Channel_Volume, 1);

Analog potentiometers[] = {
  {multiplexer.pin(4), MIDI_CC::Channel_Volume, 5},
  {multiplexer.pin(5), MIDI_CC::Channel_Volume, 6},
  {multiplexer.pin(6), MIDI_CC::Channel_Volume, 7},
  {multiplexer.pin(7), MIDI_CC::Channel_Volume, 8},
  {multiplexer.pin(8), MIDI_CC::Channel_Volume, 9},
  {multiplexer.pin(9), MIDI_CC::Channel_Volume, 10},
  {multiplexer.pin(10), MIDI_CC::Channel_Volume, 11},
};

Analog knobsSide[] = {
  {multiplexer.pin(11), MIDI_CC::Pan, 2},
  {multiplexer.pin(12), MIDI_CC::Pan, 3},

};

Bank bank(3); // A bank with three channels

BankSelector bankselector(bank, {2}, {A3, A2, A1}); // A bank selector with a single toggle switch on pin 11
/*_______________________________________________________________________________________________________________________________________*/

// remapping all the old joystick potentiometers to the correct values (extremes found via the use of the trimmers)
int mapCalibrated_1(int value) {
  value = constrain(value, 140, 422); // make sure that the analog value is between the minimum and maximum value
  return map(value, 140, 422, 0, 1023); // map the value from [minimumValue, maximumValue] to [0, 1023]
}
int mapCalibrated_2(int value) {
  value = constrain(value, 150, 432); // make sure that the analog value is between the minimum and maximum value
  return map(value, 150, 432, 0, 1023); // map the value from [minimumValue, maximumValue] to [0, 1023]
}
int mapCalibrated_3(int value) {
  value = constrain(value, 140, 401); // make sure that the analog value is between the minimum and maximum value
  return map(value, 140, 401, 0, 1023); // map the value from [minimumValue, maximumValue] to [0, 1023]
}
int mapCalibrated_4(int value) {
  value = constrain(value, 144, 460); // make sure that the analog value is between the minimum and maximum value
  return map(value, 144, 460, 0, 1023); // map the value from [minimumValue, maximumValue] to [0, 1023]
}

/*_______________________________________________________________________________________________________________________________________*/

void setup() {
  potentiometer_1.map(mapCalibrated_1);
  potentiometer_2.map(mapCalibrated_2);
  potentiometer_3.map(mapCalibrated_3);
  potentiometer_4.map(mapCalibrated_4);
  
  bank.add(knobsSide, Bank::CHANGE_CHANNEL);
}
void loop() {

  // Refresh the MIDI controller (check whether the potentiometer's input has changed since last time, if so, send the new value over MIDI)
  MIDI_Controller.refresh();
}
