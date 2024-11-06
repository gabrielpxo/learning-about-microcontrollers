#include <16F628A.h>
#fuses XT, NOMCLR, NOWDT
#use delay(clock=4MHz)

/* 2020102404 */

int8 segmentos[] = {

   0b1011011, 0b0111111, 0b1011011, 0b0111111,
   0b0000110, 0b0111111, 0b1011011, 0b1100110,
   0b0111111, 0b1100110

};

/* 2020102404 */

void main(){
int numero = 0;
while(true){
   output_b(segmentos[numero]);
   numero++;
   if(numero>9){
   numero=0;
   }
   delay_ms(100);

}

}
