//You should define "eled" which is used to be 8-led port before use me.
//Example:  #define P2 eled
#include <reg51.h>

void osta_8led(int a);

void osta_8led(int a)
{
    int led=0x00;
    a&=0x0f;
    switch(a)
   {case 0x00:{led=0x3f;break;}
    case 0x01:{led=0x06;break;}
    case 0x02:{led=0x5b;break;}
    case 0x03:{led=0x4f;break;}
    case 0x04:{led=0x66;break;}
    case 0x05:{led=0x6d;break;}
    case 0x06:{led=0x7d;break;}
    case 0x07:{led=0x07;break;}
    case 0x08:{led=0x7f;break;}
    case 0x09:{led=0x6f;break;}
    case 0x0a:{led=0x77;break;}
    case 0x0b:{led=0x7c;break;}
    case 0x0c:{led=0x39;break;}
    case 0x0d:{led=0x5e;break;}
    case 0x0e:{led=0x79;break;}
    case 0x0f:{led=0x71;break;}
    default:{led=0xf0;break;}
    }
    eled=~led;
}
