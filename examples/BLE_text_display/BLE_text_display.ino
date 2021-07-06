/***************************************************************************
* Arduino e-Paper Text Display on Arduino
*  -- with BLE-Nano board for smartphone integration
*
* 
*  by Josh Hrisko | Maker Portal LLC (c) 2021
* 
* 
***************************************************************************/

#include <SPI.h>
#include "1_54in_epaper.h"
#include <stdlib.h>

Epd epd; // initiate e-paper display [epd]
unsigned char image[1024]; // memory for display
Paint paint(image, 0, 0); // setup for text display

#define COLORED     0 // background color handler (dark)
#define UNCOLORED   1 // background color handler (light)

String tot_val = ""; // storage variable for serial data

int initial_space = 10; // initial white/dark space at the top of the display
int row_line = 3; // counting rows to avoid overlap
int row_height = 24; // row height (based on text size)

void setup() {
  Serial.begin(9600); // start serial handling for Bluetooth handling 
  epd.LDirInit(); // init display
  epd.Clear(); // clear display

  paint.SetWidth(200); // set display width
  paint.SetHeight(24); // set initial vertical space
  
  paint.Clear(COLORED); // darkr background
  paint.DrawStringAt(0, 4, "1.54in e-Paper!", &Font20, UNCOLORED); // light text
  epd.SetFrameMemory(paint.GetImage(), 0, initial_space+(0*row_height), paint.GetWidth(), paint.GetHeight());

  paint.Clear(UNCOLORED); // light background
  paint.DrawStringAt(0, 4, "Simple Demo", &Font20, COLORED); // dark text
  epd.SetFrameMemory(paint.GetImage(), 0, initial_space+(1*row_height), paint.GetWidth(), paint.GetHeight());

  paint.Clear(COLORED); // dark background
  paint.DrawStringAt(0, 4, "Maker Portal", &Font20, UNCOLORED); // light text
  epd.SetFrameMemory(paint.GetImage(), 0, initial_space+(2*row_height), paint.GetWidth(), paint.GetHeight());


  epd.DisplayFrame(); // show text
}

void loop() {
  char val = Serial.read(); // read character from BLE device (iPhone)
  if (int(val)!=-1){ // make sure it's a valid integer pin
    tot_val+=val; // if the input is over 1 character, this handles that
    if (val=='\n'){ // wait for newline
      int str_len = strlen(tot_val.c_str()); // get length of string
      tot_val[str_len-1] = '\0'; // blank out the newline character from BLExAR
      
      paint.Clear(row_line%2); // clear background
      // below: draw at opposite to background (light vs dark)
      paint.DrawStringAt(0, 4, tot_val.c_str(), &Font20, int(!bool(row_line%2))); 
      epd.SetFrameMemory(paint.GetImage(), 0, initial_space+(row_line*row_height), paint.GetWidth(), paint.GetHeight());
      epd.DisplayFrame(); // display new text
      tot_val = ""; // clear serial input variable
      row_line+=1; // iterate to ensure new text prints to new line
    }
  }
  
}