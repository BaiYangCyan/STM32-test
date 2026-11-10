#ifndef __BSP_Usart_Redir_H
#define __BSP_Usart_Redir_H

#ifdef  __cplusplus
extern  "C"{
#endif

#include"stm32f1xx_hal.h"

#include<stdio.h>
extern UART_HandleTypeDef*ghusart;

void BSP_UART_Init(UART_HandleTypeDef*husart);

#ifdef __cplusplus
}
#endif



#endif