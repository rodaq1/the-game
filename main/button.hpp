#pragma once
#include "driver/gpio.h"

class Button {
private: 
    gpio_num_t pin;
public:
    Button(gpio_num_t pin);

    bool isPressed();
    bool isReleased();
}; 