#include "GLOBAL.h"

#define ILOSC_PRZYCISKOW 16

int array[4][4] = {
{1,2,3,4},
{5,6,7,8},
{9,10,11,12},
{13,14,15,16}
};

//for(int i =0;i<ILOSC_PRZYCISKOW;++i)
int get_key()
{
for(unsigned int i = 0; i<4; ++i){
cbi(PORTC, i+4);
for(unsigned int j = 0; j<4; ++j)
{
if(bit_is_clear(PINC, j))
{
sbi(PORTC,i+4);
return array[i][j];
}

}
sbi(PORTC, i+4);
}
return 0;
}
int main()
{
DDRD = 0xFF;
DDRC = 0xF0;
PORTC = 0xFF;
while (1) {
PORTD=~get_key();
}

}
