
#include <avr/io.h>
#include "delay.h"
#include "LCD_4bits.h"
#include <stdio.h>
#include "DHT11.h"
float temp = 0;
float humi = 0;
int m,n;


int main(void)
{
	DDRD = 0xFF; /*set up out put*/
	DDRC = 0xFF; 
	LCD_Init();
	LCD_Gotoxy(5,0);
	LCD_Puts("Welcome");
	LCD_Gotoxy(2,1);
	LCD_Puts("Enter reset ");
    while (1) 
    {
		
			DHT11_Read_Data(&humi, &temp);  // doc du lieu 
			m = humi * 10;  // humi = 20,9 => m = 209 tach 2,0, 9 de hien thi len lcd
			n = temp * 10;
			LCD_Gotoxy(0,0);
				LCD_Puts("HUMI: ");
				LCD_PutChar( m /100 + 48);  // 2 + 48 = 50 => 
				LCD_PutChar((m%100)/10 + 48); // 
				LCD_PutChar('.');
				LCD_PutChar( m %10 + 48);
				LCD_Puts(" %");
				LCD_Gotoxy(0,1);
				LCD_Puts("TEMP: ");
				LCD_PutChar( n /100 + 48);
				LCD_PutChar((n%100)/10 + 48);
				LCD_PutChar('.');
				LCD_PutChar( n %10 + 48);
				LCD_Puts(" *C");
				delay_ms(500);		
    }
}
