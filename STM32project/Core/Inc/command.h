/*
 * command.h
 *
 *  Created on: Nov 24, 2025
 *      Author: Admin
 */

#ifndef INC_COMMAND_H_
#define INC_COMMAND_H_

#include "global.h"

#define 	CM_INIT					0
#define 	CM_NONE					1
#define		CM_FIRST				2

#define		CM_R					3
#define 	CM_S					4
#define 	CM_T					5
#define		CM_RST_FINISHED			6

#define		CM_O					7
#define 	CM_K					8
#define		CM_OK_FINISHED			9

#define		RST						10
#define		OK						11

extern int cmd_flag;
extern int cmd_status;

void command_parser_fsm();

#endif /* INC_COMMAND_H_ */
