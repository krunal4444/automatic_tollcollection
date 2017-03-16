unsigned char rs=0,ad,op;
////////////////////////////////////////////
void add_id(char *a1)
{
unsigned char v=0,i=0,num=0,k=0; 
v=i2c_device_read(0XA0,0x00);
if(v==0)
{
ad=0x01;
for(i=0;i<8;i++)
{
i2c_device_write(0XA0,ad+i,a[i+1]);
}
L2:
lcd_string("enter the amount");
for(i=0;i<3;i++)
{
num=(num*10)+keyscan();
}
if(num>256)
{
 lcd_string("ent blw amnt 256");
 goto L2;
}
else
{
i2c_device_write(0XA0,ad+9,num);
}
i2c_device_write(0XA0,0x00,ad+10);
}
else
{
ad=i2c_device_read(0xA0,0x00);
for(i=0;i<8;i++)
{
i2c_device_write(0XA0,ad+i,a[i+1]);
}
L3:
lcd_string("enter the amount");
for(i=0;i<3;i++)
{
k=keyscan();
lcd_cmd(0xC0);
lcd_data(k);
delay_ms(100);
num=(num*10)+k;
}
if(num>256)
{
 lcd_string("ent blw amnt 256");
 goto L3;
}
else
{
i2c_device_write(0XA0,ad+9,num);
ad = ad+9;
}
i2c_device_write(0XA0,0x00,ad+10);
}
}

//////////////////////////////////////////////
void serch_id(char *a1)
{
unsigned char i=0,v=0;
ad=0x01;
///////////////////////////////
v=i2c_device_read(0X0A,0x00);
if(v!=0)
{
L1:
for(i=0;i<8;i++)
{
  v=i2c_device_read(0X0A,ad+i);
  if(v!=a[i+1])
  break;
}
 if(i==8)
 {
 rs=i2c_device_read(0x0A,ad+i);
 }
 else
 {
  ad=ad+9;
  goto L1;
 }
}
else
{
 lcd_string("NO ENTRY");
 delay_ms(1000);
 lcd_string("DO U WNT REG");
 delay_ms(1000);
 lcd_string("PRESS 1(y)/2(n)");
 delay_ms(1000);
 op=keyscan();
 delay_ms(5);
 if(op==1)
 add_id(a);
 else
 {
 lcd_string("PAY MANUALLY");
 delay_ms(1000);
 }
}
}
 
