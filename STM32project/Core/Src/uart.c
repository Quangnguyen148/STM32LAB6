/*
 * uart.c
 *
 *  Created on: Nov 24, 2025
 *      Author: Admin
 */

#include "global.h"

uint8_t temp = 0;
uint32_t ADC_value = 0;
uint8_t buffer_flag = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;

int uart_status = IDLE;

char str[100];

void uart_communication_fsm(){
	switch(uart_status){
	case IDLE:
		if (cmd_flag == RST){
			uart_status = SEND;
			HAL_ADC_Start(&hadc1);
			ADC_value = HAL_ADC_GetValue(&hadc1);
		}
		break;

	case SEND:
		if (cmd_flag == RST){
			HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "!ADC=%d#\r\n", ADC_value), 1000);
			uart_status = RESEND;
			setTimer(1, 300);
		}
		else if (cmd_flag == OK){
			uart_status = IDLE;
		}
		break;

	case RESEND:
		if (isTimerExpired(1)){
			HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "!ADC=%d#\r\n", ADC_value), 1000);
			uart_status = RESEND;
			setTimer(1, 300);
		}
		if (cmd_flag == OK){
			uart_status = IDLE;
			cmd_flag = CM_NONE;
		}
		break;
	}
}


