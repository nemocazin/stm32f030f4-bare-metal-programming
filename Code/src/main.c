/**
 * @brief      This file contains the main function with calls to component management functions
 *
 * @author     Némo CAZIN & Antoine CEGARRA
 * @date       2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(){
    while(1){
        RCC_AHBENR |= GPIOAEN;
        LED1_blink();
        LED2_blink();
    }
    return 0;
}
