/*
 * MDMA_program.c
 *
 *  Created on: Apr 5, 2025
 *      Author: mohamed.hagag
 */
#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "DMA_private.h"
#include "DMA_interface.h"

static void(*GLB_ptr[8])(void);

void DMA2_Peripheral_init(DMA_Handler_t *hdma)
{
	/*__________________CHANNEL SELECT______________________*/
    DMA2 -> STREAM[hdma->Stream].CR &= ~(7<<CHSEL);
    DMA2 -> STREAM[hdma->Stream].CR |= (hdma->Channel<<CHSEL);
    /*__________________DIRECTION SET_______________________*/
    DMA2 -> STREAM[hdma->Stream].CR &= ~(3<<DIR);
    DMA2 -> STREAM[hdma->Stream].CR |= (hdma->Direction<<DIR);
    /*___________PERIPHERAL INCREMENT MODE SET_______________*/
    DMA2 -> STREAM[hdma->Stream].CR &= ~(1<<PINC);
    DMA2 -> STREAM[hdma->Stream].CR |= (hdma->PeripheralIncrement<<PINC);
    /*_____________MEMORY INCREMENT MODE SET_________________*/
    DMA2 -> STREAM[hdma->Stream].CR &= ~(1<<MINC);
    DMA2 -> STREAM[hdma->Stream].CR |= (hdma->MemoryIncrement<<MINC);
    /*_________________DIRECT MODE SET_______________________*/
    DMA2 -> STREAM[hdma->Stream].FCR &= ~(1<<DMDIS);
    DMA2 -> STREAM[hdma->Stream].FCR |= (hdma->DMA_Mode<<DMDIS);
    /*______________________PRIORITY__________________________*/
    DMA2 -> STREAM[hdma->Stream].CR &= ~(3<<PL);
    DMA2 -> STREAM[hdma->Stream].CR |= (hdma->Priority<<PL);
}

void DMA2_Stream_Config(
		u8_t Stream_ID,
		volatile u8_t *Source_Address,
		volatile u32_t *Destination_Address,
		DMA_Size_t Transfer_Size,
		u16_t Block_Size,
		DMA_Threshold_t FIFO_THRESHOLD
		)
{
	DMA2->STREAM[Stream_ID].M0AR=(u8_t)Source_Address;
	DMA2->STREAM[Stream_ID].PAR=(u32_t)Destination_Address;
	/*_____________________DATA SIZE__________________*/
	DMA2->STREAM[Stream_ID].CR &=~(15<<PSIZE); // -> Clear 4 bits
	DMA2->STREAM[Stream_ID].CR |=(Transfer_Size<<PSIZE); // -> Set 2 bits for Peripheral
	DMA2->STREAM[Stream_ID].CR |=(Transfer_Size<<MSIZE); // -> Set 2 bits for Memory

	DMA2->STREAM[Stream_ID].NDTR =Block_Size;

	DMA2->STREAM[Stream_ID].FCR &=~(3<<FTH);
	DMA2->STREAM[Stream_ID].FCR |= FIFO_THRESHOLD;
}

void DMA2_Stream_Enable(u8_t Stream_ID)
{
	DMA2->STREAM[Stream_ID].CR |=1;
}

void DMA2_Call_Back_Function(u8_t Stream_ID, void (*ptr)(void))
{
	GLB_ptr[Stream_ID]=ptr;
}

void DMA2_Stream0_IRQHandler(void)
{
	GLB_ptr[0]();
	DMA2->LIFCR |=(1<<5);
}



