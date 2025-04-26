/*
 * IR_program.c
 *
 *  Created on: Mar 22, 2025
 *      Author: Mostafa Mohamed
 */
/*
 * #include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "NVIC_interface.h"
#include "LEDMATRIX_interface.h"
#include "EXTI_interface.h"
#include "STP_interface.h"
#include "DAC_interface.h"
#include "DAC_audioFile.h"
#include "SEGMENT_interface.h"

u8_t StartFlag = 0;
u8_t Counter = 0;
u32_t arr[40] = {0};
u8_t value = 0;

void func2(void){
    StartFlag = 0;
    Counter = 0;
    for(u8_t i=0; i<8; i++){
    	if((arr[17+i] <= 1250) && (arr[17+i] >= 1000)){
    		CLEAR_BIT(value, i);
    	} else if((arr[17+i] <= 2400) && (arr[17+i] >= 2000)){
    		SET_BIT(value, i);
    	}
    }
}

void func1(void){
    if(!StartFlag){
    	SYSTICK_interrupt_enable();
    	StartFlag = 1;
    	SYSTICK_Call_Back_Function_SingleShot(func2, 15000);
    } else{
    	arr[Counter] = (SYSTICK_Get_Elapsed_TickSingleShot()/2);
    	Counter++;
    	SYSTICK_Call_Back_Function_SingleShot(func2, 4000);
    }
}

int main(){
    RCC_Peripheral_Enable();
    RCC_Peripheral_CLK_Enable(PERIPH_GPIOA);
    RCC_Peripheral_CLK_Enable(PERIPH_GPIOB);
    RCC_Peripheral_CLK_Enable(PERIPH_SYSCFG);
    SYSTICK_peripheral_init();
    GPIO_Set_Mode(PORTB, PIN0, OUTPUT);
    GPIO_Set_Mode(PORTB, PIN1, OUTPUT);
    GPIO_Set_Mode(PORTA, PIN0, INPUT);
    GPIO_Set_Input_Type(PORTA, PIN0, PULL_UP);
    EXTI_Set_Interrupt_Port(EXTI_LINE_0, EXTI_PORTA);
    EXTI_Set_Trigger_Detection(EXTI_LINE_0, EXTI_FALLING);
    EXTI_Call_Back_Function_EXTI0(func1);
    EXTI_Enable_Interrupt(EXTI_LINE_0);
    NVIC_Interrupt_Enable(6);
	while(1)
	{
		switch (value) {
		case 12:
            GPIO_Set_Atomic_Pin_Value(PORTB, PIN0, HIGH);
            GPIO_Set_Atomic_Pin_Value(PORTB, PIN1, LOW);
			break;
		case 24:
            GPIO_Set_Atomic_Pin_Value(PORTB, PIN0, LOW);
            GPIO_Set_Atomic_Pin_Value(PORTB, PIN1, HIGH);
			break;
		default:
			break;
		}
	}
	return 0;
}
 */




