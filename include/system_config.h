//
// Created by Kok on 7/17/25.
//

#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#include "stm32f4xx_hal.h"

/* ---------- GENERIC VARIABLES ---------- */

/* ---------- IRQ PRIORITIES ---------- */

#define TIM2_IRQ_PRIORITY                   0
#define EXTI2_IRQ_PRIORITY                  1

typedef struct {
    TIM_HandleTypeDef *pTIMHandle;
    USART_HandleTypeDef *pUSARTHandle;
    RTC_HandleTypeDef *pRTCHandle;
    DAC_HandleTypeDef *pDACHandle;
} System_Config_t;

extern System_Config_t systemConfig;

#endif //SYSTEM_CONFIG_H
