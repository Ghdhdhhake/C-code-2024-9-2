#include "delay.h"

void delay_us(u16 time)
{    
   u16 i=0;  
   while(time--)
   {
      i=10;  
      while(i--) ;    
   }
}

void delay_ms(u16 time)
{    
   u16 i=0;  
   while(time--)
   {
      i=12000; 
      while(i--) ;    
   }
}
