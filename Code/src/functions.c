/**
 * @brief      This file contains functions for using the components connected to the microcontroller.
 *
 * @author     Némo CAZIN & Antoine CEGARRA
 * @date       2024
 */

#include "functions.h"


/**
 * @details These defines are used for testing. If the program is run on a computer (X86),
 *          the defines replace those of the volatile type used for the microcontroller and
 *          their values are assigned in this file. This is to avoid duplication of defines.
 */
#if defined(__x86_64__) || defined(_M_X64)

uint32_t GPIOA_MODER = (GPIOA_BASE + 0x00);
uint32_t GPIOA_IDR = (GPIOA_BASE + 0x10);
uint32_t GPIOA_ODR = (GPIOA_BASE + 0x14);

#endif



uint32_t delay(uint32_t iterations) {
    for (uint32_t i = 0; i < iterations; i++) {
    }
    return iterations;
}


uint32_t LED1_config (void) {
    GPIOA_MODER |= (GPIOA_OUTPUT << LED1 * TWO_BITS);
    return GPIOA_MODER;
}


uint32_t LED1_off (void) {
    GPIOA_ODR &= ~(OFF << LED1);
    return GPIOA_ODR;
}


uint32_t LED1_on (void) {
    GPIOA_ODR |= (ON << LED1);
    return GPIOA_ODR;
}


uint32_t LED1_blink (void) {
    LED1_off();
    delay(1000);
    LED1_on();
    delay(1000);
    return GPIOA_ODR;
}


uint32_t LED2_config (void) {
    GPIOA_MODER |= (GPIOA_OUTPUT << LED2 * TWO_BITS);
    return GPIOA_MODER;
}


uint32_t LED2_off (void) {
    GPIOA_ODR &= ~(OFF << LED2);
    return GPIOA_ODR;
}


uint32_t LED2_on (void) {
    GPIOA_ODR |= (ON << LED2);
    return GPIOA_ODR;
}


uint32_t LED2_blink (void) {
    LED2_off();
    delay(1000);
    LED2_on();
    delay(1000);
    return GPIOA_ODR;
}


uint32_t temp_sensor_config (void) {
    GPIOA_MODER |= (GPIOA_INPUT << TEMP * TWO_BITS);
    return GPIOA_MODER;
}


uint32_t temperature_conversion(uint32_t analogVoltageValue) {
    //float voltage = analogValue * (5.0 / 1023.0); // (5V reference, 1024 bits)
    uint32_t temperatureC = (uint32_t)(analogVoltageValue - 1/2) * 100; // Convert voltage to temperature in Celsius (0,5V = 0°C)
    return temperatureC;
}