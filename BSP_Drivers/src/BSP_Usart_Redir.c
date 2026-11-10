#include "BSP_Usart_Redir.h"

UART_HandleTypeDef*ghusart=NULL;
void BSP_UART_Init(UART_HandleTypeDef*husart)
{
 ghusart=husart;
}


int fgetc(FILE*fp)
{
    UNUSED(fp);
    uint8_t ch;
    if(ghusart!=NULL)
    {
        
        while (1)
        {
            if(HAL_OK!=HAL_UART_Receive(ghusart,&ch,1,HAL_MAX_DELAY))
            {
                return EOF;
            }
            if(ch!='\r')
            {
                return (int)ch;  
            }
        }
        
    }
    else
    {
        return EOF;
    }
}
int fputc(int ch,FILE*fp)
{
    UNUSED(fp);
    if(ghusart!=NULL)
    {
        while(1)
        {
            if(HAL_UART_Transmit(ghusart,&ch,1,HAL_MAX_DELAY)==HAL_OK)
            {
                return ch;
            }
            else
            {
                return EOF;
            }
        }
    }
}
