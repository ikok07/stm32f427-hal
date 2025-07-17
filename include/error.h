//
// Created by Kok on 7/17/25.
//

#ifndef ERROR_H
#define ERROR_H

#include <stdint.h>


#define ERROR_LED_PORT              GPIOA
#define ERROR_LED_PIN               2

void SetupErrorHandling();

void TriggerError(char *msgFormat, ...);
void ClearError();
uint8_t CheckForError();

#endif //ERROR_H
