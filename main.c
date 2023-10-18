#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/timer.h"

const uint TEMPERATURE_SENSOR_PIN = 26;

void timer_callback(uint gpio, uint32_t events) {
    uint32_t raw = adc_read();
    float voltage = (float) raw * (3.3f / 65535.0f);
    float temperature = (voltage - 0.5f) * 100.0f;
    printf("Temperatura do Nucleo: %.2f°C\n", temperature);
}


int main(void) {
     stdio_init_all();

    adc_init();
    adc_set_temp_sensor_enabled(TEMPERATURE_SENSOR_PIN);
    adc_select_input(0);

    while(1){
        uint16_t raw = adc_read();
        const float conversion = 3.3f / (1<<12);
        float voltage =raw * conversion;
        float temperature = 27 - (voltage - 0.706)/0.001721;
        printf("Temperatura: %f °C\n", temperature);
        sleep_ms(1000);
    }

    return 0;
}
