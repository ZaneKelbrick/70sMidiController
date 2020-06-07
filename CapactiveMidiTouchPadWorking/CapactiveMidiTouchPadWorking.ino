#include <CapacitiveSensor.h>
#include "MIDIUSB.h"
/*
   CapitiveSense Library Demo Sketch
   Paul Badger 2008
   Uses a high value resistor e.g. 10M between send pin and receive pin
   Resistor effects Distance, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
   Receive pin is the sensor pin - try different amounts of foil/metal on this pin
*/

#define Distance 2000

CapacitiveSensor   cs_6_A2 = CapacitiveSensor(6, A2);       // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_6_A3 = CapacitiveSensor(6, A3);       // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_6_A4 = CapacitiveSensor(6, A4);       // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_6_A5 = CapacitiveSensor(6, A5);       // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_6_A7 = CapacitiveSensor(6, A7);       // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_6_A8 = CapacitiveSensor(6, A8);       // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_6_A9 = CapacitiveSensor(6, A9);       // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_6_10 = CapacitiveSensor(6, 10);       // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_6_11 = CapacitiveSensor(6, 11);       // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil

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
  Serial.begin(115200);
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
    midiEventPacket_t noteOn = {0x09, 0x90, 60, 100};
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
    delay(10);
    midiEventPacket_t noteOff = {0x08, 0x80, 0, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }

  if (total2 >= Distance)
  {
    midiEventPacket_t noteOn = {0x09, 0x90, 61, 100};
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
    delay(10);
    midiEventPacket_t noteOff = {0x08, 0x80, 61, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }

  if (total3 >= Distance)
  {
    midiEventPacket_t noteOn = {0x09, 0x90, 62, 100};
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
    delay(10);
    midiEventPacket_t noteOff = {0x08, 0x80, 62, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }
  if (total4 >= Distance)
  {
    midiEventPacket_t noteOn = {0x09, 0x90, 63, 100};
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
    delay(10);
    midiEventPacket_t noteOff = {0x08, 0x80, 63, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }

  if (total5 >= Distance)
  {
    midiEventPacket_t noteOn = {0x09, 0x90, 64, 100};
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
    delay(10);
    midiEventPacket_t noteOff = {0x08, 0x80, 64, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }

  if (total6 >= Distance)
  {
    midiEventPacket_t noteOn = {0x09, 0x90, 65, 100};
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
    delay(10);
    midiEventPacket_t noteOff = {0x08, 0x80, 65, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }
  if (total7 >= Distance)
  {
    midiEventPacket_t noteOn = {0x09, 0x90, 66, 100};
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
    delay(10);
    midiEventPacket_t noteOff = {0x08, 0x80, 66, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }

  if (total8 >= Distance)
  {
    midiEventPacket_t noteOn = {0x09, 0x90, 67, 100};
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
    delay(10);
    midiEventPacket_t noteOff = {0x08, 0x80, 67, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }

  if (total9 >= Distance)
  {
    midiEventPacket_t noteOn = {0x09, 0x90, 68, 100};
    MidiUSB.sendMIDI(noteOn);
    MidiUSB.flush();
    delay(10);
    midiEventPacket_t noteOff = {0x08, 0x80, 68, 0};
    MidiUSB.sendMIDI(noteOff);
    MidiUSB.flush();
  }
  //
  //    Serial.print(millis() - start);        // check on performance in milliseconds
  //    Serial.print("\t");                    // tab character for debug windown spacing
  //
  //    Serial.print(total1);                  // print sensor output 1
  //    Serial.print("\t");
  //    Serial.print(total2);                  // print sensor output 2
  //    Serial.print("\t");
  //    Serial.println(total3);                // print sensor output 3

  delay(10);                             // arbitrary delay to limit data to serial port
}
