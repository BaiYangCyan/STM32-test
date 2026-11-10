#ifndef __BSP_GPIO_kyeControlLed_H
#define __BSP_GPIO_kyeControlLed_H

#ifdef _cpulspuls
extern 'C'{
#endif
#include<assert.h>
#include<stdbool.h>
#include"stm32f1xx_hal.h"

typedef enum
{
    LED1=0,//8/9/10/11
    LED2,
    LED3,
    LED4
}LED_t;



typedef enum
{
    KEY1=0,//10/6/8/7
    KEY2,
    KEY3,
    KEY4
}KEY_t;
bool BSP_KEY_Read(KEY_t key);
void LED_Control(KEY_t key,bool flag);
void LED_Control_ON(KEY_t key);
void LED_Control_OFF(KEY_t key);




#ifdef _cpulspuls
}
#endif






#endif