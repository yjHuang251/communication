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
int r=0;
int t=0;
uint8_t text[5]={'h','e','l','l','o'};
uint8_t text_from_arduino[10];
extern TIM_HandleTypeDef htim6;
extern UART_HandleTypeDef huart3;

void setup(){
	HAL_UART_Receive_IT(&huart3, text, sizeof(text));
	HAL_TIM_Base_Start_IT(&htim6);
}

void main_function(){
	setup();
//	HAL_UART_Receive_IT(&huart3,text_from_arduino,sizeof(text_from_arduino));
	while(1){
//		HAL_UART_Receive_IT(&huart3,text_from_arduino,sizeof(text_from_arduino));
//		if(text_from_arduino=="Hi"){
//			counter++;
//		}
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef*huart){
	if(huart -> Instance == USART3){
	    HAL_UART_Receive_IT(&huart3, text_from_arduino, sizeof(text_from_arduino));
		r++;
	}
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
	if(huart -> Instance == USART3){
		t++;
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM6){
		HAL_UART_Transmit_IT(&huart3, text, sizeof(text));
//		counter++;
	}
}
