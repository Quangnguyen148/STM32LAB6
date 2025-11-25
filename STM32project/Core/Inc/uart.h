/*
 * uart.h
 *
 *  Created on: Nov 24, 2025
 *      Author: Admin
 */

#ifndef INC_UART_H_
#define INC_UART_H_
#include "global.h"

#define MAX_BUFFER_SIZE  30

#define	IDLE	0
#define	SEND	1
#define RESEND	2

extern int uart_status;
extern uint8_t temp;
extern uint32_t ADC_value;
extern uint8_t buffer_flag;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;

void uart_communication_fsm();

#endif /* INC_UART_H_ */
