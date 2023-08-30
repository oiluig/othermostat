#include <Thermostat.h>

Thermostat *Thermostat::instance = nullptr;

Thermostat::Thermostat(int pin, int type, float targetTemp) : dht(pin, type), targetTemperature(targetTemp)
{
    dht.begin();
}

Thermostat *Thermostat::getInstance(int pin, int type, float targetTemp)
{
    if (!instance)
    {
        instance = new Thermostat(pin, type, targetTemp);
    }
    return instance;
}

void Thermostat::setTargetTemperature(float temp)
{
    targetTemperature = temp;
}

float Thermostat::getCurrentTemperature()
{
    return dht.readTemperature();
}

void Thermostat::run()
{
    float currentTemp = getCurrentTemperature();

    if (currentTemp <= targetTemperature - hysteresis)
    {
        // Turn on heater or cooling system
        // Implement your control logic here
    }
    else if (currentTemp >= targetTemperature + hysteresis)
    {
        // Turn off heater or cooling system
        // Implement your control logic here
    }
}
