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

String header_txt[4] = {"1.54in e-Paper","Simple Demo","Maker Portal"}; // header text

int initial_space = 10; // initial white/dark space at the top of the display
const int init_row_lines = 3; // counting rows to avoid header overlap
int row_line = 0; // for iterating
int row_height = 24; // row height (based on text size)

const int max_lines = 8; // max lines that can print at font-20 (for this demo)
String line_array[max_lines-init_row_lines]; // More lines than this and the display will overflow 

void setup() {
  Serial.begin(9600); // start serial handling for Bluetooth handling 
  
  clear_func(); // clear display and set header
}

void loop() {
  char val = Serial.read(); // read character from BLE device (iPhone)
  if (int(val)!=-1){ // make sure it's a valid integer pin
    tot_val+=val; // if the input is over 1 character, this handles that
    if (val=='\n'){ // wait for newline
      int str_len = strlen(tot_val.c_str()); // get length of string
      tot_val[str_len-1] = '\0'; // blank out the newline character from BLExAR
      line_array[row_line] = tot_val; // append to string array

      if (row_line<(max_lines-init_row_lines)){
        header_print(); // print header text
        update_txt();
        row_line+=1; // iterate to ensure new text prints to new line
      } else {
        row_line = 0; // reset if going beyond display
        for (int qq=0;qq<(max_lines-1-init_row_lines);qq++){
          line_array[qq] = ""; // reset array too
        }
        clear_func(); // clear entire e-paper and add header
        delay(2000);
        header_print(); // reintroduce header after clear
        line_array[row_line] = tot_val; // append to string array
        update_txt(); // update with text
      }
      tot_val = ""; // clear serial input variable
    }
  }
}

void header_print(){
  paint.SetWidth(200); // set display width
  paint.SetHeight(24); // set initial vertical space

  // loop through header text and print values
  for (int jj=0;jj<init_row_lines;jj++){
    paint.Clear(jj%2); // background
    paint.DrawStringAt(0, 4, header_txt[jj].c_str(), &Font20, int(!bool(jj%2))); // text
    epd.SetFrameMemory(paint.GetImage(), 0, initial_space+(jj*row_height), paint.GetWidth(), paint.GetHeight());
  }
}

void clear_func(){
  epd.LDirInit(); // initialize epaper
  epd.Clear(); // clear old text/imagery
  epd.DisplayPartBaseWhiteImage(); // lay a base white layer down first

  header_print(); // print header text
  epd.DisplayPartFrame(); // display header text
}

void update_txt(){
  for (int ii=0;ii<=row_line;ii++){
    paint.Clear(int(!bool(ii%2))); // clear background
    // below: draw at opposite to background (light vs dark) 
    paint.DrawStringAt(0, 4, line_array[ii].c_str(), &Font20, ii%2);
    epd.SetFrameMemory(paint.GetImage(), 0, initial_space+((ii+init_row_lines)*row_height), paint.GetWidth(), paint.GetHeight());
  }
  epd.DisplayPartFrame(); // display new text
}
