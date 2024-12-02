#pragma once 
#include "driver/gpio.h"
#include "driver/ledc.h"

class Buzzer {
private:
    gpio_num_t pin;

public:
    Buzzer(gpio_num_t pin);

    void playTone(uint32_t freq, uint32_t duration);
};
