/*
 * mainpp.cpp
 *
 *  Created on: Aug 6, 2024
 *      Author: yujungHuang
 */
#include "mainpp.h"
#include "stm32g4xx_hal.h"
#include "string.h"

int counter=0;
uint8_t text[5]={'h','e','l','l','o'};
extern TIM_HandleTypeDef htim6;
extern UART_HandleTypeDef huart3;

void setup(){
//	HAL_UART_Receive_IT(&huart3, text, sizeof(text));
	HAL_TIM_Base_Start_IT(&htim6);
}
void main_function(){
	setup();
	while(1){
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM6){
		HAL_UART_Transmit_IT(&huart3, text, sizeof(text));
		counter++;
	}
}
