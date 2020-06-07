#include <CapacitiveSensor.h>
#include "MIDIUSB.h"
/*
   Capactive Midi controller for Etextiles
   Zane Kelbrick 2019 - for Marea 
   This code 
*/

#define Distance 2000 // this will affect how sensitive each of the sensors are (bigger = closer you will need to be)
#define Time 10 //Change this to the length of each track 

CapacitiveSensor   cs_6_A2 = CapacitiveSensor(6, A2);       // pin A2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_6_A3 = CapacitiveSensor(6, A3);       // pin A3 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_6_A4 = CapacitiveSensor(6, A4);       // pin A4 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_6_A5 = CapacitiveSensor(6, A5);       // pin A5 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_6_A7 = CapacitiveSensor(6, A7);       // pin A7 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_6_A8 = CapacitiveSensor(6, A8);       // pin A8 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_6_A9 = CapacitiveSensor(6, A9);       // pin A9 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_6_10 = CapacitiveSensor(6, 10);       // pin 10 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_6_11 = CapacitiveSensor(6, 11);       // pin 11 is sensor pin, add a wire and or foil

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void setup()
{
  cs_6_A2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate 
  cs_6_A3.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate 
  cs_6_A4.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate 
  cs_6_A5.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate 
  cs_6_A7.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate 
  cs_6_A8.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate 
  cs_6_A9.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate 
  cs_6_10.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate 
  cs_6_11.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate 
  Serial.begin(115200);                           // Start Communication
}

void loop()
{
  long start = millis(); // Time between each reading 
  long total1 =  cs_6_A2.capacitiveSensor(30); // getting the vaule from the sensor
  long total2 =  cs_6_A3.capacitiveSensor(30); // getting the vaule from the sensor
  long total3 =  cs_6_A4.capacitiveSensor(30); // getting the vaule from the sensor
  long total4 =  cs_6_A5.capacitiveSensor(30); // getting the vaule from the sensor
  long total5 =  cs_6_A7.capacitiveSensor(30); // getting the vaule from the sensor
  long total6 =  cs_6_A8.capacitiveSensor(30); // getting the vaule from the sensor
  long total7 =  cs_6_A9.capacitiveSensor(30); // getting the vaule from the sensor
  long total8 =  cs_6_10.capacitiveSensor(30); // getting the vaule from the sensor
  long total9 =  cs_6_11.capacitiveSensor(30); // getting the vaule from the sensor

  if (total1 >= Distance) 
  {
    midiEventPacket_t noteOn = {0x09, 0x90, 60, 100}; // sending the musical note
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
    delay(Time); // the time between the note on, and note off
    midiEventPacket_t noteOff = {0x08, 0x80, 61, 0}; // turning off the musical note 
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }

  if (total2 >= Distance)
  {
    midiEventPacket_t noteOn = {0x09, 0x90, 61, 100}; // sending the musical note
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
    delay(Time);
    midiEventPacket_t noteOff = {0x08, 0x80, 61, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }

  if (total3 >= Distance)
  {
    midiEventPacket_t noteOn = {0x09, 0x90, 62, 100}; // sending the musical note
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
    delay(Time);
    midiEventPacket_t noteOff = {0x08, 0x80, 62, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }
  if (total4 >= Distance)
  {
    midiEventPacket_t noteOn = {0x09, 0x90, 63, 100}; // sending the musical note
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
    delay(Time);
    midiEventPacket_t noteOff = {0x08, 0x80, 63, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }

  if (total5 >= Distance)
  {
    midiEventPacket_t noteOn = {0x09, 0x90, 64, 100}; // sending the musical note
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
    delay(Time);
    midiEventPacket_t noteOff = {0x08, 0x80, 64, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }

  if (total6 >= Distance)
  {
    midiEventPacket_t noteOn = {0x09, 0x90, 65, 100}; // sending the musical note
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
    delay(Time);
    midiEventPacket_t noteOff = {0x08, 0x80, 65, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }
  if (total7 >= Distance)
  {
    midiEventPacket_t noteOn = {0x09, 0x90, 66, 100}; // sending the musical note
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
    delay(Time);
    midiEventPacket_t noteOff = {0x08, 0x80, 66, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }

  if (total8 >= Distance)
  {
    midiEventPacket_t noteOn = {0x09, 0x90, 67, 100}; // sending the musical note
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
    delay(Time);
    midiEventPacket_t noteOff = {0x08, 0x80, 67, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }

  if (total9 >= Distance)
  {
    midiEventPacket_t noteOn = {0x09, 0x90, 68, 100}; // sending the musical note
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
    delay(Time);
    midiEventPacket_t noteOff = {0x08, 0x80, 68, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }                            // arbitrary delay to limit data to serial port
}
