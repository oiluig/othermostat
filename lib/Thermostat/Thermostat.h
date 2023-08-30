#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include <DHT.h>

class Thermostat
{
private:
    static Thermostat *instance;
    DHT dht;
    float targetTemperature;
    const float hysteresis = 1.0; // Temperature difference to avoid rapid cycling

    Thermostat(int pin, int type, float targetTemp);

public:
    static Thermostat *getInstance(int pin = 2, int type = DHT22, float targetTemp = 25.0);

    void setTargetTemperature(float temp);
    float getCurrentTemperature();
    void run();
};

#endif // THERMOSTAT_H
