#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void LightSensor_Init(void){
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA ,ENABLE);
	
	GPIO_InitTypeDef GPIO_Structure1;
	GPIO_Structure1.GPIO_Mode =GPIO_Mode_IPU;
	GPIO_Structure1.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_Structure1.GPIO_Pin =GPIO_Pin_1 | GPIO_Pin_4 ;
	GPIO_Init(GPIOA,&GPIO_Structure1);
}	
uint8_t Get_LSLeft(void)
{
	return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4);
}

uint8_t Get_LSRight(void)
{
	return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1);
}

