#ifndef THERMOSTATDISPLAY_H
#define THERMOSTATDISPLAY_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Thermostat.h"

const unsigned char flameIcon[] PROGMEM = {
    0b00000100, 0b00000100,
    0b00011111, 0b11111110,
    0b00011111, 0b11111110,
    0b00011111, 0b11111110,
    0b00011111, 0b11111110,
    0b00101111, 0b11111100,
    0b01100110, 0b11001100,
    0b01100110, 0b11001100,
    0b01100110, 0b11001100,
    0b00101110, 0b11001000,
    0b00011111, 0b11111110,
    0b00011111, 0b11111110,
    0b00011111, 0b11111110,
    0b00011111, 0b11111110,
    0b00000100, 0b00000100};

const unsigned char snowflakeIcon[] PROGMEM = {
    0b00000000, 0b01000000,
    0b00000001, 0b11000000,
    0b00000111, 0b11100000,
    0b00001111, 0b11110000,
    0b00111111, 0b11111000,
    0b00111111, 0b11111000,
    0b00111111, 0b11111000,
    0b00001111, 0b11110000,
    0b00000111, 0b11100000,
    0b00000001, 0b11000000,
    0b00000000, 0b01000000};

class ThermostatDisplay
{
private:
    Adafruit_SSD1306 display;
    Thermostat *thermostat;

    void drawInterface(float currentTemp, float targetTemp, bool heating, bool cooling);

public:
    ThermostatDisplay();
    void init();
    void update();
};

#endif // THERMOSTATDISPLAY_H
