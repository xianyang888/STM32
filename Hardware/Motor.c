#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);						
	
	PWM_Init();													
}

void Motor_SetSpeed(int8_t SpeedLeft,int8_t SpeedRight)
{	
	GPIO_SetBits(GPIOB, GPIO_Pin_13);	
	GPIO_ResetBits(GPIOB, GPIO_Pin_12);	
	PWM_SetCompare1(SpeedLeft);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_15);
	GPIO_ResetBits(GPIOB, GPIO_Pin_14);	
	PWM_SetCompare2(SpeedRight);		
}

void Forward(void)
{
	Motor_SetSpeed(65,65);
}
void Turn_Right(void)
{
	Motor_SetSpeed(55,35);
}
void Turn_Left(void)
{
	Motor_SetSpeed(35,55);
}
void Stop(void)
{
	Motor_SetSpeed(0,0);
}
