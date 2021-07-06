/***************************************************************************
* Arduino e-Paper Text Display on Arduino
*  -- looping through integers to show real-time updating
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

int iter_val = 0; // storage variable for serial data

int initial_space = 10; // initial white/dark space at the top of the display
int row_line = 3; // counting rows to avoid overlap
int row_height = 24; // row height (based on text size)

void setup() {
  Serial.begin(9600); // start serial handling for text input 
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
  String str_to_print = "Val: "; // string prepend
  str_to_print+=String(iter_val); // add integer value
  paint.Clear(COLORED); // clear background
  paint.DrawStringAt(0, 4, str_to_print.c_str(), &Font20, UNCOLORED); // light background
  epd.SetFrameMemory(paint.GetImage(), 0, initial_space+(3*row_height), paint.GetWidth(), paint.GetHeight());
  epd.DisplayFrame(); // display new text
  iter_val+=1; // increase integer value to show
  delay(1000); // delay between updates
}