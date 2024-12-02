#include <led.hpp>

Led::Led(gpio_num_t pin, uint8_t state, bool isOn)
    : pin(pin), state(state), isOn(isOn) {
        gpio_reset_pin(pin);
        gpio_set_direction(pin, GPIO_MODE_OUTPUT);
}

void Led::changeState(uint8_t desiredState) {
    gpio_set_level(pin, desiredState);
}