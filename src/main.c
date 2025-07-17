
#include <stdio.h>

#include "stm32f4xx_hal.h"
#include "system_config.h"
#include "encoder.h"
#include "error.h"

USART_HandleTypeDef husart1 = {
    .Instance = USART1,
    .Init = {
        .Mode = USART_MODE_TX,
        .BaudRate = 9600,
        .Parity = USART_PARITY_NONE,
        .StopBits = USART_STOPBITS_1,
        .WordLength = USART_WORDLENGTH_8B,
    }
};

TIM_HandleTypeDef htim2 = {
    .Instance = TIM2,
    .Init = {
        .AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE,
        .ClockDivision = TIM_CLOCKDIVISION_DIV1,
        .CounterMode = TIM_COUNTERMODE_UP,
        .Period = ENCODER_TIM_ARR_VALUE - 1,
        .Prescaler = 0x00
    }
};

System_Config_t systemConfig = {
    .pTIMHandle = &htim2,
    .pUSARTHandle = &husart1
};

int __io_putchar(int ch) {
    HAL_USART_Transmit(systemConfig.pUSARTHandle, (uint8_t*)&ch, 1, HAL_MAX_DELAY);
    return ch;
}

int main(void) {
    if (HAL_Init() != HAL_OK) {
        while (1);
    }

    if (HAL_USART_Init(systemConfig.pUSARTHandle) != HAL_OK) {
        TriggerError(NULL);
        HAL_Delay(1000);
        NVIC_SystemReset();
    }

    // Init encoder
    if (SetupEncoder() != HAL_OK) {
        TriggerError("Encoder could not be initialized!");
        HAL_Delay(1000);
        NVIC_SystemReset();
    };

    while (1);
}