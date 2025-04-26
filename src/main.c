/*
 * main.c
 *
 *  Created on: Feb 28, 2025
 *      Author: Mostafa Mohamed
 */
#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "NVIC_interface.h"
#include "LEDMATRIX_interface.h"
#include "EXTI_interface.h"
#include "STP_interface.h"
#include "DAC_interface.h"
#include "SEGMENT_interface.h"
#include "UART_interface.h"
#include "SPI_interface.h"
#include "TFT_interface.h"
#include "DMA_interface.h"

u8_t sentChar = 'f';
u8_t *SourcePointer = &sentChar;
u8_t recievedChar;
volatile u32_t *DestinationPointer = (volatile u32_t *)0x40011004;
DMA_Handler_t dma;
void function();

int main(){
    RCC_Peripheral_Enable();
    RCC_Peripheral_CLK_Enable(PERIPH_GPIOB);
    RCC_Peripheral_CLK_Enable(PERIPH_USART1);
    RCC_Peripheral_CLK_Enable(PERIPH_DMA2);
    GPIO_Set_Mode(PORTA, PIN7, OUTPUT);
    GPIO_Set_Mode(PORTB, PIN6, ALT_FUNCTION);
    GPIO_Set_ALT_FUNC_Mode(PORTB, PIN6, AF7);
    GPIO_Set_Mode(PORTB, PIN7, ALT_FUNCTION);
    GPIO_Set_ALT_FUNC_Mode(PORTB, PIN7, AF7);
    UART1_Peripheral_init();

    dma.Stream = DMA_Stream7;
    dma.Channel = DMA_Channel4;
    dma.PeripheralIncrement = DMA_PeriphIncDisable;
    dma.MemoryIncrement = DMA_MemIncDisable;
    dma.Priority = DMA_HIGH_Priority;
    dma.Direction = DMA_Mem_To_Periph;
    dma.DMA_Mode = DMA_DirectModeEnable;
    DMA2_Peripheral_init(&dma);

    DMA2_Stream_Config(dma.Stream, SourcePointer, DestinationPointer, DMA_BYTE, 1, DMA_FIFO_OFF);
    DMA2_Stream_Enable(dma.Stream);
    DMA2_Call_Back_Function(dma.Stream,&function);
    NVIC_Interrupt_Enable(56);

    recievedChar = UART1_Recieve_Data();

	while(1)
	{

	}
	return 0;
}

void function()
{
	GPIO_Set_Atomic_Pin_Value(PORTA, PIN7, HIGH);
}

