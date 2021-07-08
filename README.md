# 1.54in e-Paper Display Codes for Arduino
Arduino codes for a 1.54 inch E-Paper Display that works with Arduino Uno, Nano and other ATmega328P-based boards

Based on the codes at: https://github.com/waveshare/e-Paper

Get your 1.54in e-Paper Display here: [1.54in e-Paper Display](https://makersportal.com/shop/e-paper-display-for-arduino) <br>
Get the BLExAR App: [BLExAR App Link](https://makersportal.com/blexar) <br>
See full tutorial here: [1.54in e-Paper Display with Arduino](https://makersportal.com/blog/) <br>

# 
### JUMP TO:
<a href="#wiring">- Wiring Diagram</a><br>
<a href="#arduino">- Arduino Codes</a><br>

The 1_54in_epaper library can be downloaded using git:

    git clone https://github.com/makerportal/1_54in_epaper

<a id="wiring"></a>
# - Wiring the 1.54in e-Paper Display to Arduino Uno -
We are wiring the 1.54in e-Paper display via SPI on the Arduino Uno board:

![1.54in e-paper wiring with BLE Nano](/images/1_54in_epaper_wiring_w_BLE_nano.jpg)

![1.54in e-paper wiring table with BLE Nano](/images/epaper_BLE_nano_wiring_table.png)

<a id="arduino"></a>
# - Arduino Example Code Descriptions -
The first example is a simple updating text display and can be found in the example folder:

- simple_text_display.ino

This simple example will print out integer values starting with 0 and marching forward until the count overflows:

![1.54in e-paper simple output](https://images.squarespace-cdn.com/content/v1/59b037304c0dbfb092fbe894/1625758194858-ULANDH0XWTN2BFPMTR8S/epaper_display_simple_counter.JPG?format=1000w)

The second example allows users to send text from a smartphone (we use the BLExAR app) to a BLE-Nano Arduino board that updates the 1.54in e-Paper display:

- BLE_text_display.ino

An example output is shown below:

![1.54in e-paper BLE output](https://images.squarespace-cdn.com/content/v1/59b037304c0dbfb092fbe894/1625758054341-JR6QSP5KLM0XP7UCJWM1/epaper_display_BLE_hi_arduino.JPG?format=1500w)
