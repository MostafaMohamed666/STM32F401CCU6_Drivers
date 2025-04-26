/*
 * DMA_interface.h
 *
 *  Created on: Apr 18, 2025
 *      Author: Mostafa Mohamed
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

typedef enum
{
	DMA_BYTE,
	DMA_HALF_WORD,
	DMA_WORD
} DMA_Size_t;

typedef enum
{
	DMA_FIFO_QUARTER,
	DMA_FIFO_HALF,
	DMA_FIFO_THREEQUARTERS,
	DMA_FIFO_FULL,
} DMA_Threshold_t;

#define DMA_FIFO_OFF 0

typedef enum {
	DMA_Stream0,
	DMA_Stream1,
	DMA_Stream2,
	DMA_Stream3,
	DMA_Stream4,
	DMA_Stream5,
	DMA_Stream6,
	DMA_Stream7
} DMA_Dma2Streams_t;

typedef enum
{
	DMA_Channel0,
	DMA_Channel1,
	DMA_Channel2,
	DMA_Channel3,
	DMA_Channel4,
	DMA_Channel5,
	DMA_Channel6,
	DMA_Channel7
} DMA_Channels_t;

typedef enum
{
	DMA_Periph_To_Mem,
	DMA_Mem_To_Periph,
	DMA_Mem_To_Mem
} DMA_Direction_t;

typedef enum
{
	DMA_PeriphIncDisable,
	DMA_PeriphIncEnable
} DMA_PeriphInc_t;

typedef enum
{
	DMA_MemIncDisable,
	DMA_MemIncEnable
} DMA_MemInc_t;

typedef enum
{
	DMA_DirectModeEnable,
	DMA_DirectModeDisable
} DMA_DirectMode_t;

typedef enum
{
	DMA_LOW_Priority,
	DMA_MEDIUM_Priority,
	DMA_HIGH_Priority,
	DMA_VERY_HIGH_Priority
} DMA_Priority_t;


typedef struct
{
	DMA_Dma2Streams_t Stream;
	DMA_Channels_t Channel;
	DMA_Direction_t Direction;
	DMA_PeriphInc_t PeripheralIncrement;
	DMA_MemInc_t MemoryIncrement;
	DMA_DirectMode_t DMA_Mode;
	DMA_Priority_t Priority;
}DMA_Handler_t;

void DMA2_Peripheral_init(DMA_Handler_t *hdma);
void DMA2_Stream_Config(
		DMA_Dma2Streams_t Stream,
		volatile u8_t *Source_Address,
		volatile u32_t *Destination_Address,
		DMA_Size_t Transfer_Size,
		u16_t Block_Size,
		DMA_Threshold_t FIFO_THRESHOLD
		);
void DMA2_Stream_Enable(u8_t Stream_ID);
void DMA2_Call_Back_Function(u8_t Stream_ID, void (*ptr)(void));


#endif /* DMA_INTERFACE_H_ */
