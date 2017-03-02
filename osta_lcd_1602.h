//ʵ����
//ʹ��ǰӦ��Ԥ�ȶ������ݶ˿�(lcd1602)�Ϳ��ƶ˿�(RSPIN��RWPIN��EPIN)
//���磺
//		���ݶ˿�    #define lcd1602 P1
//		���ƶ˿�     sbit RSPIN   = P3^3;
//                   sbit RWPIN   = P3^4;
//                   sbit EPIN    = P3^2;
//PIN1: VSS  [��Դ��]-------------------VSS
//PIN2: VDD  [��Դ����]-----------------VDD
//PIN3: Vo   [LCD ƫѹ����]-------------��10K�Ŀɵ����赽VSS,0Ϊ��ʾ����
//PIN4: RS   [����/����ѡ�������]------P3.3
//PIN5: RW   [��д�����ź�����]---------P3.4
//PIN6: E    [ʹ���ź�����]-------------P3.2
//PIN7: D0   [Data I/O]-----------------P1.0
//PIN8: D1   [Data I/O]-----------------P1.1
//PIN9: D2   [Data I/O]-----------------P1.2
//PIN10:D3   [Data I/O]-----------------P1.3
//PIN11:D4   [Data I/O]-----------------P1.4
//PIN12:D5   [Data I/O]-----------------P1.5
//PIN13:D6   [Data I/O]-----------------P1.6
//PIN14:D7   [Data I/O]-----------------P1.7
//PIN15:BLA  [����Դ����]---------------��10ŷ���赽+5V.
//PIN16:BLK  [����Դ����]---------------VSS
#include <reg51.h>
#include <intrins.h>

void osta_lcd_1602(unsigned char cx,unsigned char cy,unsigned char code *s);
void putstrxy(unsigned char cx,unsigned char cy,unsigned char code *s);
void delay3ms(void);
void lcdwc(unsigned char c);
void lcdwaitidle(void);
unsigned char data CXPOS;
unsigned char data CYPOS;

void osta_lcd_1602(unsigned char cx,unsigned char cy,unsigned char code *s)
{
	int i=0;
	for(i=4;i>0;i--)
    {
		lcdwc(0x38);
    	delay3ms();
	}
	lcdwc(0x08);
	lcdwc(0x01);
	delay3ms();
	lcdwc(0x06);
	lcdwc(0x0C);
	putstrxy(0,0,"                                ");
	putstrxy(cx,cy,*s);
}

void putstrxy(unsigned char cx,unsigned char cy,unsigned char code *s)
{
    CXPOS=cx;
    CYPOS=cy;
    for(;*s!=0;s++)
    {
		CXPOS&=0X0f;
		CYPOS&=0X01;
		if(CYPOS==0)
        {
            lcdwc(CXPOS|0x80);
        }
	    else
        {
			lcdwc(CXPOS|0xC0);
    	    lcdwaitidle();
        }
		RSPIN=1;
		RWPIN=0;
		lcd1602=*s;
		EPIN=1;
		_nop_();
		EPIN=0;
		CXPOS++;
		if(CXPOS>15)
		{
			CXPOS=0;
			CYPOS++;
			CYPOS&=0X1;
		}
	}
}

void delay3ms(void)
{unsigned char i,j;i = 13;j = 37;
do{while (--j);}while (--i);}

void lcdwc(unsigned char c)
{
    lcdwaitidle();
    RSPIN=0;
    RWPIN=0;
    lcd1602=c;
    EPIN=1;
    _nop_();
    EPIN=0;
}

void lcdwaitidle(void)
{
    unsigned char i;
    lcd1602=0xff;
    RSPIN=0;
    RWPIN=1;
    EPIN=1;
    for(i=0;i<20;i++)
    {
        if((P1&0x80) == 0)
        {
            break;
        }
    }
    EPIN=0;
}
