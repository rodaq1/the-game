#include <button.hpp>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

Button::Button(gpio_num_t pin) : pin(pin) {
    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pin_bit_mask = (1ULL << pin);
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    gpio_config(&io_conf);
}

bool Button::isPressed() {
    return gpio_get_level(pin) == 0; 
}

bool Button::isReleased() {
    return gpio_get_level(pin) == 1;
}


