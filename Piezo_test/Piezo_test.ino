/*
 * Ardrumo sketch
 *
 * Use with the Ardrumo software here:
 * <a href="http://code.google.com/p/ardrumo/" rel="nofollow"> <a href="http://code.google.com/p/ardrumo/"> <a href="http://code.google.com/p/ardrumo/"> <a href="http://code.google.com/p/ardrumo/" rel="nofollow"> <a href="http://code.google.com/p/ardrumo/" rel="nofollow"> http://code.google.com/p/ardrumo/
</a>
</a>
</a>
</a>
</a>
 * This is designed to let an Arduino act as a drum machine
 * in GarageBand (sorry, Mac OS X only).
 */

#define LEDPIN     13     // status LED pin
#define PIEZOTHRESHOLD 5  // analog threshold for piezo sensing
#define PADNUM 4         // number of pads

int val;

void setup() {
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(57600);   // set serial output rate
}

void loop() {

  // Loop through each piezo and send data
  // on the serial output if the force exceeds
  // the piezo threshold
  for(int i = 0; i < PADNUM; i++) {
    val = analogRead(i);
    if( val >= PIEZOTHRESHOLD ) {
      digitalWrite(LEDPIN,HIGH);  // indicate we're sending MIDI data
      Serial.print(i);
      Serial.print(",");
      Serial.print(val);
      Serial.println();
      digitalWrite(LEDPIN,LOW);
    }
  }
}
