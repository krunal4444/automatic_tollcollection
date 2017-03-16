sbit M1= P1^5;
sbit M2= P1^6;
void motor_init(void)
{
M1=1;
M2=1;
}
void motor_work(void)
{
 motor_init();
 M1=0;
 M2=1;
 delay_ms(5000);
 M1=1;
 M2=1;
 delay_ms(10000);
 M1=1;
 M2=0;
 delay_ms(5000);
 M1=1;
 M2=1;
}