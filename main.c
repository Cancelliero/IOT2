#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/timer.h"

const uint TEMPERATURE_SENSOR_PIN = 26;

void timer_callback(uint gpio, uint32_t events) {
    uint32_t raw_value = adc_read();
    float voltage = (float) raw_value * (3.3f / 65535.0f);
    float temperature = (voltage - 0.5f) * 100.0f;
    printf("Temperatura do Nucleo: %.2f°C\n", temperature);
}

void setup() {
    stdio_init_all();
    
    adc_init();
    adc_gpio_init(TEMPERATURE_SENSOR_PIN);
    adc_select_input(0);

    // Configure o timer para disparar a cada segundo
    struct repeating_timer timer;
    add_repeating_timer_ms(5000, timer_callback, NULL, &timer);
}

int main() {
    setup();

    while (1) {
        tight_loop_contents();
    }
    return 0;
}
