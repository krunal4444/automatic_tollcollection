unsigned char a[11]={0},i=0,temp;
#include<reg51.h>
#include"delay.h"
#include"lcd4bit.h"
#include"uart.h"
#include"keypad.h"
#include"i2c.h"
#include"i2c_device.h"
#include"rtc_main.h"
#include"serch_id.h"
sbit LED1 = P1^7;


void UART_HANDLER(void) interrupt 4
{
if(RI==1)
{
	RI=0;
	a[i++]=SBUF;
	if(i==10)
	serch_id(a);
}
}
void EXT0_HANDLER(void) interrupt 1
{
 motor_work();
}
main()
{
LED1 = 0; //indicator led on
ES=EA=EX0=1;
lcd_init();
rtc_init();
uart_init();	
delay_ms(5);
	while(1)
	{
	rtc_main();
	lcd_string(a);
	delay_ms(1000);
	lcd_cmd(0x01);
	i=0;
	delay_ms(2);
	}
}
