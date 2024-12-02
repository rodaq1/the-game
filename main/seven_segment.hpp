#pragma once

#include "soc/gpio_num.h"
#include <cstdint>
#include "led.hpp"

class SevenSegment {
private:
    Led ledA;
    Led ledB;
    Led ledC;
    Led ledD;
    Led ledE;
    Led ledF;
    Led ledG;

    static const uint8_t SEVEN_SEGMENT_NUMBERS[10];

public:
    SevenSegment(gpio_num_t ledA, gpio_num_t ledB, gpio_num_t ledC, gpio_num_t ledD, gpio_num_t ledE, gpio_num_t ledF, gpio_num_t ledG);

    void display(int number);
    void clear();
};