//We always have to include the library
#include "LedControl.h"
#include "anim.h"
#include "anim2.h"
#include "anim3.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime=100;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,4);
  /* and clear the display */
  lc.clearDisplay(0);
}


void loop() { 

  lc.setIntensity(0,4);
  
  for(int i=0; i<sizeof(anim); i) { // For each frame...

    for(uint8_t j=0; j<8; j++) {    // 8 rows...
      lc.setRow(0,j,pgm_read_byte(&anim[i++]));
    }

    delay(pgm_read_byte(&anim[i++]) * 10);
  }

// Repeat above with another array
// Try faster animation speed with this set...(adjusted delay multiplier)
  for(int i=0; i<sizeof(anim2); i) { // For each frame...

    for(uint8_t j=0; j<8; j++) {    // 8 rows...
      lc.setRow(0,j,pgm_read_byte(&anim2[i++]));
    }
    
    delay(pgm_read_byte(&anim2[i++]) * 2);
  }

// Another array, modified to change intensity
  for(int i=0; i<sizeof(anim3); i) { // For each frame...

    for(uint8_t j=0; j<8; j++) {    // 8 rows...
      lc.setRow(0,j,pgm_read_byte(&anim3[i++]));
    }
    lc.setIntensity(0,pgm_read_byte(&anim3[i++]));
    delay(pgm_read_byte(&anim3[i++]) * 10);
  }
}
