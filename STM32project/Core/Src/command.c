/*
 * command.c
 *
 *  Created on: Nov 24, 2025
 *      Author: Admin
 */
#include "global.h"

int cmd_status = CM_INIT;
int cmd_flag = CM_NONE;
char str[100];

void command_parser_fsm(){
	switch(cmd_status){
	case CM_INIT:
		if (buffer[index_buffer-1] == '!'){
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-1], 1, 50);
			cmd_status = CM_FIRST;
		}
		break;

	case CM_FIRST:
		if (buffer[index_buffer-1] == 'R'){
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-1], 1, 50);
			cmd_status = CM_R;
		}
		else if (buffer[index_buffer-1] == 'O'){
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-1], 1, 50);
			cmd_status = CM_O;
		}
		else cmd_status = CM_INIT;
		break;

	case CM_R:
		if (buffer[index_buffer-1] == 'S'){
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-1], 1, 50);
			cmd_status = CM_S;
		}
		else cmd_status = CM_INIT;
		break;

	case CM_S:
		if (buffer[index_buffer-1] == 'T'){
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-1], 1, 50);
			cmd_status = CM_T;
		}
		else cmd_status = CM_INIT;
		break;

	case CM_T:
		if (buffer[index_buffer-1] == '#'){
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-1], 1, 50);
			cmd_status = CM_RST_FINISHED;
		}
		else cmd_status = CM_INIT;
		break;

	case CM_RST_FINISHED:
		HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "\r\n"), 1000);
		cmd_flag = RST;
		cmd_status = CM_INIT;
		break;

	case CM_O:
		if (buffer[index_buffer-1] == 'K'){
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-1], 1, 50);
			cmd_status = CM_K;
		}
		else cmd_status = CM_INIT;
		break;

	case CM_K:
		if (buffer[index_buffer-1] == '#'){
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-1], 1, 50);
			cmd_status = CM_OK_FINISHED;
		}
		else cmd_status = CM_INIT;
		break;

	case CM_OK_FINISHED:
		HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "\r\n"), 1000);
		cmd_flag = OK;
		cmd_status = CM_INIT;
		break;
	}
}
