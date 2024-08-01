/**
 * @brief      This file contains all the register addresses and function prototypes used.
 *
 * @author     Némo CAZIN & Antoine CEGARRA
 * @date       2024
 */
#include <stdio.h>
#include <stdint.h>

/**
 * @details These defines are used for testing. If the program is run on a computer (X86), 
 *          the defines replace those of the volatile type used for the microcontroller.
 */
#if defined(__x86_64__) || defined(_M_X64)

#define GPIOA_BASE      0x48000000
extern  uint32_t        GPIOA_MODER;
extern  uint32_t        GPIOA_IDR;
extern  uint32_t        GPIOA_ODR;
#define GPIOA_INPUT     0UL
#define GPIOA_OUTPUT    1UL

#else
// Memory mapped addresses for GPIO
#define GPIOA_BASE      0x48000000 
#define RCC_BASE        0x40021000 

// RCC registers
#define RCC_AHBENR      (*(volatile uint32_t *)(RCC_BASE + 0x14))
#define RCC_APB2ENR     (*(volatile uint32_t *)(RCC_BASE + 0x18))

// GPIO registers
#define GPIOA_MODER     (*(volatile uint32_t *)(GPIOA_BASE + 0x00)) //I/O pins configuration
#define GPIOA_IDR       (*(volatile uint32_t *)(GPIOA_BASE + 0x10)) //Input 
#define GPIOA_ODR       (*(volatile uint32_t *)(GPIOA_BASE + 0x14)) //Output
#define GPIOA_INPUT     0UL
#define GPIOA_OUTPUT    1UL
#define GPIOAEN         (1 << 17) // I/O port A clock enable

#endif

// Pins
#define LED1            0
#define TEMP            1
#define BIT2            2
#define BIT1            3
#define BIT0            4
#define LED2            5
#define EPROM           6
#define SCL             7
#define SDA             10
#define SWDAT           13
#define SDCLK           14

#define TWO_BITS        2
#define ON              1UL
#define OFF             1UL

// Prototypes

/**
* @brief Create a delay with a for loop
* 
* @return Number of iterations
*/
uint32_t delay (uint32_t iterations);


/**
* @brief Configures the register GPIOA_MODER to set LED1 to output
* 
* @return 1
*/
uint32_t LED1_config (void);


/**
* @brief Configures the register GPIOA_ODR to turn off LED1
* 
* @return 1
*/
uint32_t LED1_off (void);


/**
* @brief Configures the register GPIOA_ODR to turn on LED1
* 
* @return 1
*/
uint32_t LED1_on (void);


/**
* @brief Blink LED1
* 
* @return 1
*/
uint32_t LED1_blink (void);


/**
* @brief Configures the register GPIOA_MODER to set LED2 to output
* 
* @return 1
*/
uint32_t LED2_config (void);


/**
* @brief Configures the register GPIOA_ODR to turn off LED2
* 
* @return 1
*/
uint32_t LED2_off (void);


/**
* @brief Configures the register GPIOA_ODR to turn on LED2
* 
* @return 1
*/
uint32_t LED2_on (void);


/**
* @brief Blink LED2
* 
* @return 1
*/
uint32_t LED2_blink (void);


/**
* @brief Configures the register GPIOA_MODER to set the temperature sensor to input
* 
* @return 1
*/
uint32_t temp_sensor_config (void);


/**
* @brief Converts the voltage recovered from the temperature sensor into °C
* 
* @return The temperature (float)
*/
uint32_t temperature_conversion (uint32_t analogVoltageValue);