void delay_ms(unsigned int dly)
{
	unsigned char i;
	for( ;dly>0;dly--)
	{
		for(i=250;i>0;i--);
		for(i=245;i>0;i--);
	}
}