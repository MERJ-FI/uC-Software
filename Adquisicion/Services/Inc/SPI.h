/*
 * SPI.h
 *
 *  Created on: 6 abr 2023
 *      Author: mgnar
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

uint8_t initSPI(void);
void SPIRx(char *buf, uint8_t len);
void SPITx(char TxBuffer[]);

#endif /* INC_SPI_H_ */
