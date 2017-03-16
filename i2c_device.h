// i2c_device.h
#ifndef __I2C_DEVICE__
#define __I2C_DEVICE__
void i2c_device_write(unsigned char sa, unsigned char wa, unsigned char dat)
{
  i2c_start();
  i2c_write(sa);
  i2c_ack();
  i2c_write(wa);
  i2c_ack();
  i2c_write(dat);
  i2c_ack();
  i2c_stop();
  delay_ms(10);
}

unsigned char i2c_device_read(unsigned char sa, unsigned char wa)
{
  unsigned char temp=0;
  i2c_start();
  i2c_write(sa);
  i2c_ack();
  i2c_write(wa);
  i2c_ack();
  i2c_start();
  i2c_write(sa | 1);
  i2c_ack();
  temp = i2c_read();
  i2c_noack();
  i2c_stop();
  return temp;
}

#endif