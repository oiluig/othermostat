#include "ThermostatDisplay.h"

ThermostatDisplay::ThermostatDisplay() : display(128, 64, &Wire, -1), thermostat(nullptr)
{
    // Constructor
}

void ThermostatDisplay::init()
{
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.display();
    delay(2000);
    display.clearDisplay();
}

// Inside the ThermostatDisplay class's drawInterface function

void ThermostatDisplay::drawInterface(float currentTemp, float targetTemp, bool heating, bool cooling)
{
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);

    // Draw temperature readings
    display.setTextSize(3);
    display.setCursor(10, 5);
    display.print(currentTemp, 1);
    display.setTextSize(1);
    display.setCursor(90, 15);
    display.println("C");

    // Draw target temperature
    display.setTextSize(1);
    display.setCursor(10, 35);
    display.print("Target:");
    display.setTextSize(2);
    display.setCursor(10, 45);
    display.print(targetTemp, 1);
    display.setTextSize(1);
    display.setCursor(90, 50);
    display.println("C");

    // Draw separator line
    display.drawLine(0, 60, display.width(), 60, SSD1306_WHITE);

    // Draw status icons
    if (heating)
    {
        // Draw heating icon (flame)
        display.drawBitmap(105, 15, flameIcon, 16, 16, SSD1306_WHITE);
    }

    if (cooling)
    {
        // Draw cooling icon (snowflake)
        display.drawBitmap(105, 15, snowflakeIcon, 16, 16, SSD1306_WHITE);
    }

    display.display();
}

void ThermostatDisplay::update()
{
    // float currentTemp = thermostat->getCurrentTemperature();
    drawInterface(27, 25, false, true);
}
