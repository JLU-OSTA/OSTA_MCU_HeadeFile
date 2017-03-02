//You should define "eled" which is used to be 8-led port before use me.
//Example:  #define P2 eled
#include <reg51.h>

void osta_8led(int a);

void osta_8led(int a)
{
    a&=0x0f;
    switch(a)
   {case 0x00:{eled=0x3f;break;}
    case 0x01:{eled=0x06;break;}
    case 0x02:{eled=0x5b;break;}
    case 0x03:{eled=0x4f;break;}
    case 0x04:{eled=0x66;break;}
    case 0x05:{eled=0x6d;break;}
    case 0x06:{eled=0x7d;break;}
    case 0x07:{eled=0x07;break;}
    case 0x08:{eled=0x7f;break;}
    case 0x09:{eled=0x6f;break;}
    case 0x0a:{eled=0x77;break;}
    case 0x0b:{eled=0x7c;break;}
    case 0x0c:{eled=0x39;break;}
    case 0x0d:{eled=0x5e;break;}
    case 0x0e:{eled=0x79;break;}
    case 0x0f:{eled=0x71;break;}
    default:{eled=0xf0;break;}
    }
}
