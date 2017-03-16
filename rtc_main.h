char *day[]={"son","mon","tue","wen","thu","fri","sat"};
unsigned char sec, min, hr, date, month, year;
void rtc_init()
{
	lcd_cmd(0x80);
	lcd_string("Time ");
i2c_device_write(0xD0, 0x05, 0x16); // year
i2c_device_write(0xD0, 0x04, 0x01); // month
i2c_device_write(0xD0, 0x03, 0x02); // date
i2c_device_write(0xD0, 0x03, 0x02); // date
	
	lcd_cmd(0xc0);
	lcd_string("Date ");
	
lcd_string(day[1]);
i2c_device_write(0xD0, 0x02, 0x05); // hour
i2c_device_write(0xD0, 0x01, 0x06); // min
i2c_device_write(0xD0, 0x00, 0x15); // sec
}

void rtc_main()
{

	year = i2c_device_read(0xD0, 0x05);
	month = i2c_device_read(0xD0, 0x04);
	date = i2c_device_read(0xD0, 0x03);
	
	hr = i2c_device_read(0xD0, 0x02);
	min = i2c_device_read(0xD0, 0x01);
	sec = i2c_device_read(0xD0, 0x00);
	
	lcd_cmd(0x85);
	lcd_data(hr/16 + '0');
	lcd_data(hr%16 + '0');
	lcd_data(':');
	lcd_data(min/16 + '0');
	lcd_data(min%16 + '0');
	lcd_data(':');
	lcd_data(sec/16 + '0');
	lcd_data(sec%16 + '0');

	lcd_cmd(0xc5);
	lcd_data(date/16 + '0');
	lcd_data(date%16 + '0');
	lcd_data('-');
	lcd_data(month/16 + '0');
	lcd_data(month%16 + '0');
//	lcd_str(buf[month-1]);
	lcd_string("-20");
	lcd_data(year/16 + '0');
	lcd_data(year%16 + '0');

}
