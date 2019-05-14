#ifndef __M5310_H
#define __M5310_H
#include "sys.h"

void M5310A_Clear(void);

void M5310A_USART_init(u32 bound);

_Bool M5310A_WaitRecive(void);

_Bool M5310A_SendCmd(char *cmd, char *res);

void M5310_init(void);

void Usart_SendString(USART_TypeDef *USARTx, unsigned char *str, unsigned short len);

#endif
