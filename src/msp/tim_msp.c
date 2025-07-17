//
// Created by Kok on 7/17/25.
//

#include "stm32f4xx_hal.h"
#include "system_config.h"

void HAL_TIM_Encoder_MspInit(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM2) {
        // Enable RCC Clocks
        __HAL_RCC_GPIOA_CLK_ENABLE();
        __HAL_RCC_TIM2_CLK_ENABLE();

        // Configure GPIOs
        GPIO_InitTypeDef GPIO_Config = {
            .Alternate = GPIO_AF1_TIM2,
            .Mode = GPIO_MODE_AF_PP,
            .Pull = GPIO_PULLDOWN,
            .Speed = GPIO_SPEED_FREQ_LOW
        };

        // TX Pin
        GPIO_Config.Pin = GPIO_PIN_0;
        HAL_GPIO_Init(GPIOA, &GPIO_Config);

        // RX Pin
        GPIO_Config.Pin = GPIO_PIN_1;
        HAL_GPIO_Init(GPIOA, &GPIO_Config);

        // Setup NVIC
        HAL_NVIC_SetPriority(TIM2_IRQn, TIM2_IRQ_PRIORITY, TIM2_IRQ_PRIORITY);
        HAL_NVIC_EnableIRQ(TIM2_IRQn);
    }
}