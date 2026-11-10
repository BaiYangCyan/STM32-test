#include"BSP_GPIO_kyeControlLed.h"





bool BSP_KEY_Read(KEY_t key)
{
    GPIO_PinState ret;
    switch (key)
    {
    case KEY1:
    ret=(HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_10)==GPIO_PIN_RESET);
    break;
    case KEY2:
    ret=(HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_6)==GPIO_PIN_RESET);
    break;
    case KEY3:
    ret=(HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_8)==GPIO_PIN_RESET);
    break;
    case KEY4:
    ret=(HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_7)==GPIO_PIN_RESET);
    break;
    }
    return ret;
}
void LED_Control(KEY_t key,bool flag)
{
    GPIO_PinState state=flag?GPIO_PIN_RESET:GPIO_PIN_SET;
    switch (key)
    {
    case KEY1:
    HAL_GPIO_WritePin(GPIOF,GPIO_PIN_8,state);
    break;
    case KEY2:
    HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,state);
    break;
    case KEY3:
    HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,state);
    break;
    case KEY4:
    HAL_GPIO_WritePin(GPIOF,GPIO_PIN_11,state);
    break;
    }
}


void LED_Control_ON(KEY_t key)
{
   LED_Control(key,true);
}
void LED_Control_OFF(KEY_t key)
{
   LED_Control(key,false);
}