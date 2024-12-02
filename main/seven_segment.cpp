#include <cstdint>
#include <freertos/FreeRTOS.h>
#include "seven_segment.hpp"

const uint8_t SevenSegment::SEVEN_SEGMENT_NUMBERS[10] = {
    0b0111111,
    0b0000110,
    0b1011011,
    0b1001111,
    0b1100110,
    0b1101101,
    0b1111101,
    0b0000111,
    0b1111111,
    0b1101111,
};


SevenSegment::SevenSegment(gpio_num_t ledA, gpio_num_t ledB, gpio_num_t ledC, gpio_num_t ledD, gpio_num_t ledE, gpio_num_t ledF, gpio_num_t ledG) :ledA(ledA), ledB(ledB), ledC(ledC), ledD(ledD), ledE(ledE), ledF(ledF), ledG(ledG) {
}

void SevenSegment::display(int number) {
    if (SEVEN_SEGMENT_NUMBERS[number] & (1 << 0)) ledA.changeState(1);
    else ledA.changeState(0);
    if (SEVEN_SEGMENT_NUMBERS[number] & (1 << 1)) ledB.changeState(1);
    else ledB.changeState(0);
    if (SEVEN_SEGMENT_NUMBERS[number] & (1 << 2)) ledC.changeState(1);
    else ledC.changeState(0);
    if (SEVEN_SEGMENT_NUMBERS[number] & (1 << 3)) ledD.changeState(1);
    else ledD.changeState(0);
    if (SEVEN_SEGMENT_NUMBERS[number] & (1 << 4)) ledE.changeState(1);
    else ledE.changeState(0);
    if (SEVEN_SEGMENT_NUMBERS[number] & (1 << 5)) ledF.changeState(1);
    else ledF.changeState(0);
    if (SEVEN_SEGMENT_NUMBERS[number] & (1 << 6)) ledG.changeState(1);
    else ledG.changeState(0);
}

void SevenSegment::clear() {
    ledA.changeState(0);
    ledB.changeState(0);
    ledC.changeState(0);
    ledD.changeState(0);
    ledE.changeState(0);
    ledF.changeState(0);
    ledG.changeState(0);
}
