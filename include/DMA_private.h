/*
 * DMA_private.h
 *
 *  Created on: Apr 18, 2025
 *      Author: Mostafa Mohamed
 */

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

#define DMA1_BASE_ADDRESS (0x40026000)
#define DMA2_BASE_ADDRESS (0x40026400)

typedef struct
{
	u32_t CR;
	u32_t NDTR;
	u32_t PAR;
	u32_t M0AR;
	u32_t M1AR;
	u32_t FCR;
}DMA_STREAM_t;

typedef struct
{
	u32_t LISR;
	u32_t HISR;
	u32_t LIFCR;
	u32_t HIFCR;
	DMA_STREAM_t STREAM[8];
}DMA_t;

#define DMA1 ((volatile DMA_t*)DMA1_BASE_ADDRESS)
#define DMA2 ((volatile DMA_t*)DMA2_BASE_ADDRESS)

#define CHSEL 25
#define DIR 6
#define PINC 9
#define MINC 10
#define DMDIS 2
#define PL 16
#define PSIZE 11
#define MSIZE 13
#define FTH 0

#endif /* DMA_PRIVATE_H_ */
