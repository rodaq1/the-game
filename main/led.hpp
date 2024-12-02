#pragma once
#include <cstdint>
#include "driver/gpio.h"

class Led {
private:
    gpio_num_t pin;
    uint8_t state;
    bool isOn;

public:
    Led(gpio_num_t pin, uint8_t state = 0, bool isOn = false);
    void changeState(uint8_t desiredState);
};