sfr LCD = 0x80;
sbit RS = P0^1;
sbit RW = P0^2;
sbit EN = P0^3;
void lcd_data(unsigned char dat)
{
	LCD=dat & 0xf0;
	RS=1;
	RW=0;
	EN=1;
	delay_ms(2);
	EN=0;
	
	LCD=dat << 4;
	RS=1;
	RW=0;
	EN=1;
	delay_ms(2);
	EN=0;
}

void lcd_cmd(unsigned char cmd)
{
	LCD=cmd & 0xF0;//for higher 4 bit
	RS=0;
	RW=0;
	EN=1;
	delay_ms(2);
	EN=0;
	
	LCD=cmd << 4;//for lower 4 bit
	RS=0;
	RW=0;
	EN=1;
	delay_ms(2);
	EN=0;
}

void lcd_string(char *p)
{
	while(*p)
	{
	lcd_data(*p++);
	}
}

void lcd_init()
{
	lcd_cmd(0x01);
	lcd_cmd(0x02);
	lcd_cmd(0x06);
	lcd_cmd(0x28);
	lcd_cmd(0x0E);
	lcd_cmd(0x80);
}
