//This header file define an osta function which is used to operate PWM.
//You must define "out" port before using me.
//Example:
//      sbit pwmout = P2^0;
//You can use two parameter to control me.
//First is numerator of 100 which will be the proportion of full in PWM;
//Second is delay time ms.
#include <reg51.h>
#include <intrins.h>

int osta_1bit_vss100pwm(int n,long t);
void osta_pwmdelay(void);

int osta_1bit_vss100pwm(int n,long t)
{
    long i=0x0000;
    int j=0x00,a=0x00;
    t=(long)t;
    if((n>100)|(n<0))
        {
            return 1;
        }
	for(;t>0;t--)
	{
	for(i=1;i>0;i--)		  //equal to 6x_nop_()
	{
	j=n;
    while(j>0x00)
        {
			pwmout=1;
            osta_pwmdelay();
			j--;
        }
		a=100-n;
		j=a;
    while(j>0x00)
        {
			pwmout=0;
            osta_pwmdelay();
			j--;
        }
	}
	}
	return 0;
}

void osta_pwmdelay(void)
{
	_nop_();
}
