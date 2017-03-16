// i2c.h
#ifndef __I2C__
#define __I2C__

sbit SDA = P1^0;
sbit SCL = P1^1;

void i2c_start()
{
	SCL = 1;
	SDA = 1;
	SDA = 0;
}

void i2c_stop()
{
	SCL = 0;
	SDA = 0;
	SCL = 1;
	SDA = 1;	
}

void i2c_write(unsigned char d)
{
	char i;
	for(i=7; i>=0; i--)
	{
	SCL = 0;
	SDA = d & (1 << i )	? 1:0;
	SCL = 1;
	} 
}

unsigned char i2c_read(void)
{
	unsigned char temp = 0;
	char i;
	for(i=7; i>=0; i--)
	{
	SCL = 1;
	if(SDA == 1)
	temp = temp | (1 << i);
	SCL = 0;
	}
return temp; 
}
void i2c_ack()
{
	SCL = 0;
	SDA = 1;
	SCL = 1; // master issuing 9th clock pulse
	while(SDA == 1); // reading SDA
	SCL = 0;
}

void i2c_noack()
{
	SCL = 0;
	SDA = 1;
	SCL = 1;
}
#endif