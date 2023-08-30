#include <Arduino.h>
#include <Thermostat.h>
#include <ThermostatDisplay.h>

ThermostatDisplay display;
// Thermostat thermostat = Thermostat::getInstance(2, 22, 25.0);

void setup()
{
  display.init();
}

void loop()
{
  // put your main code here, to run repeatedly:
  display.update();
}