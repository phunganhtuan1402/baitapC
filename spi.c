#include <xc.h>
#include<stdio.h>
#include<stdint.h>
#include<pic16f877a.h>
#define _XTAL_FREQ 20000000

#define SCK  RC3    // chân SCK
#define MOSI RC4   // Chân MOSI
#define SS   RE2     // Chân SS
#define MISO RC5  // chân MISO


void SPI_Soft_init();/*ch??ng trình kh?i t?o SPI*/ 
void Clock();  /*---ch??ng trình kh?i 1 xung clock---------*/
void SPI_Soft_Transmit(uint8_t mData);/*------ch??ng trình g?i 1 byte---------*/
uint8_t SPI_Soft_Receive();   /*------ch??ng trình nh?n 1 byte---------*/

// ham khoi tao SPI
void SPI_Soft_init(){
  SCK   = 0;  /*sck = 0 ch?a t?o xung clock */
  MOSI  = 0; /*ch?a truy?n data ? chân mosi*/
  SS    = 1;  /*ch?a cho phép slave truy?n*/
}

// ham tao xung clock
void Clock(){
  SCK = 1; 
  __delay_us(5); 
  SCK = 0; 
  __delay_us(5); 
}

/*------ch??ng trình g?i 1 byte---------*/
void SPI_Soft_Transmit(uint8_t Data){ 
  uint8_t i = 0, x = 0;   
  SS = 0;   
  for(i = 0; i < 8; i++){ 
    x = Data&0x80; /*bit cao nh?t c?a byte Data AND 0x80*/
    if(x!=0)      
    {
      MOSI = 1;  /*N?u bit cao nh?t c?a Data AND v?i 0x80 = 1 thì giá tr? bit chân MOSI = 1*/
    }
    else
      MOSI=0;   
    Clock(); /* phát 1 xung clock g?i d? li?u ?i*/ 
    Data = Data<<1; /* d?ch 1 bit Data sang trái*/   
  }  
  SS=1; /*?ã g?i xong,??a chân SS lên m?c 1*/
}

/*------ch??ng trình master nh?n v? 1 byte t? slave---------*/

uint8_t SPI_Soft_Receive(){  
  uint8_t _data=0x00, i=0;  
  while(i<8){     
    _data = _data<<1;       /*d?ch d? li?u sang trái 1 bit*/  
    if(MISO)
      _data |= 0x01;    /* N?u chân MISO ? m?c 1 thì s? tr? v? giá tr? _data = _data OR v?i 0x01 */ 
    Clock();                /*phát m?t xung clock ?? ??c bit */
  }   
  return _data;             /*tr? v? d? li?u ??c ???c */
}
main()
{
    SPI_Soft_Transmit(01001101);
    SPI_Soft_Receive();
}