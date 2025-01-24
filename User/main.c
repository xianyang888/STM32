#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "LED.h"
#include "LightSensor.h"
#include "Key.h"

uint8_t KeyNum,Left,Right,Flag;

int main(void)
{
	LightSensor_Init();
	Motor_Init();
	LED_Init();
	LED1_ON();
	
	while (1)
	{
		KeyNum=Key_GetNum();
		if(KeyNum==1)
		{
			Flag=1;
		}
		else if(KeyNum==2)
		{
			Stop();
			Flag=0;
		}
		if(Flag)
		{
			Left=Get_LSLeft();
			Right=Get_LSRight();
			if(Left==0&&Right==0)Forward();
			else if(Left==1&&Right==0)Turn_Left();
			else if(Left==0&&Right==1)Turn_Right();
		}
					
	}
}
