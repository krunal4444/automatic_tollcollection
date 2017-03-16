void uart_init()
{
	SCON = 0x50;
	TMOD = 0x20; // Timer1,mode2
	TH1 = TL1 = 253; // FOR 9600 baud rate
	TR1 = 1; // Start timer 1
}
// void uart_tx(unsigned char dat)
// {
// 	SBUF = dat;
// 	while(TI == 0); // waiting for Tx data
// 	TI = 0;	
// }
unsigned char uart_rx()
{
	while(RI == 0);
	RI = 0;
	return SBUF;	
}
// void uart_string(const char *s)
// {
// 	while(*s)
// 		uart_tx(*s++); // Transmitting data one by one
// }