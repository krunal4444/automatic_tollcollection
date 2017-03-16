// #include<reg51.h>
// #include"delay.h"

sfr LED = 0x80;

sbit R0 = P2^4;
sbit R1 = P2^5;
sbit R2 = P2^6;
sbit R3 = P2^7;

sbit c0 = P2^0;
sbit c1 = P2^1;
sbit c2 = P2^2;
sbit c3 = P2^3;

code unsigned char keypad_lut[4][4]={ '0','1','2','3',
									  '4','5','6','7',
									  '8','9','A','B',
									  'C','D','E','F'};

bit colscan()
{
	return (c0&c1&c2&c3);
}

unsigned char keyscan()
{
		unsigned char row,col;
		R0=R1=R2=R3=0;
		c0=c1=c2=c3=1;
		
		while(colscan()==1); // waiting for key pressing

		R0 =0;
		R1 =1;
		R2 =1;
		R3 =1;
	if(colscan()==0)
	{
		row =0;
		goto colcheck;
	}
	R0=1;
	R1=0;
	R2=1;
	R3=1;
	if(colscan()==0)
	{
		row= 1;
		goto colcheck;
	}
	R0=1;
	R1=1;
	R2=0;
	R3=1;
	if(colscan()==0)
	{
		row= 2;
		goto colcheck;
	}
	R0=1;
	R1=1;
	R2=1;
	R3=0;
	if(colscan()==0)
	{
		row= 3;
		goto colcheck;
	}
	
colcheck:
		 if(c0==0)
			 col=0;
		 else if(c1==0)
			 col=1;
		 else if(c2==0)
			 col=2;
		 else if(c3==0)
			 col=3;

			delay_ms(50);   // key bouncing 
		 
			while(colscan()==0); // waiting for key realising 
				return (keypad_lut[row][col]);
}


