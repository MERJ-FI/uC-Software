/*
 * UART.h
 *
 *  Created on: 6 abr 2023
 *      Author: mgnar
 */

#ifndef INC_UART_H_
#define INC_UART_H_

uint8_t initUART(void);
void UARTRx(char *buf, uint8_t len);
void UARTTx(char TxBuffer[]);

#endif /* INC_UART_H_ */
