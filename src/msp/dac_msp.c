//
// Created by Kok on 7/18/25.
//

#include "stm32f4xx_hal.h"

void HAL_DAC_MspInit(DAC_HandleTypeDef *hdac) {
    GPIO_InitTypeDef GPIO_Config = {
        .Mode = GPIO_MODE_ANALOG,
        .Pull = GPIO_PULLDOWN,
        .Speed = GPIO_SPEED_FREQ_MEDIUM,
        .Pin = GPIO_PIN_4
    };

    // Init DAC output 1
    HAL_GPIO_Init(GPIOA, &GPIO_Config);
}