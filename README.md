# 1.54in e-Paper Display Codes for Arduino
Arduino codes for a 1.54 inch E-Paper Display, that works with Uno, Nano boards and other ATmega328P-based boards

Based on the codes at: https://github.com/waveshare/e-Paper

Get your 1.54in e-Paper Display here: [1.54in e-Paper Display](https://makersportal.com/shop/solar-panel-datalogger-kit-for-arduino) <br>
See full tutorial here: [1.54in e-Paper Display with Arduino](https://makersportal.com/blog/solar-panel-characterization-and-experiments-with-arduino) <br>

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


The second example allows users to send text from a smartphone (we use the BLExAR app) to a BLE-Nano Arduino board that updates the 1.54in e-Paper display:

- BLE_text_display.ino
