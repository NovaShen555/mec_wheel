//
// Created by 10415 on 25-7-2.
//

#include "../Inc/driver.h"

#include <stdlib.h>


#include <tim.h>

void SetMotor(int motor, int speed) {
    SetPolarity(motor, speed);
    speed = abs(speed);
    if (motor == 1) {
        __HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_1, speed);
    } else if (motor == 2) {
        __HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_2, speed);
    } else if (motor == 3) {
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, speed);
    } else if (motor == 4) {
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, speed);
    }
}

void SetPolarity(int motor, int polarity) {
    if (motor == 1) {
        if (polarity > 0) {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
        } else {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
        }
    } else if (motor == 2) {
        if (polarity > 0) {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
        } else {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
        }
    } else if (motor == 3) {
        if (polarity > 0) {
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
        } else {
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
        }
    } else if (motor == 4) {
        if (polarity > 0) {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
        } else {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
        }
    }
}
