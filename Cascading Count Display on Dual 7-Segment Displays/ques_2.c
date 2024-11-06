#include <16F877A.h>
//#fuses INTRC_IO,NOWDT,PUT,BROWNOUT,NOLVP,NOMCLR
#use delay(clock=4MHz)
// Definindo os pinos dos displays de 7 segmentos


int8 segmentos[] = {
   0b00111111, 0b00000110, 0b01011011, 0b01001111,
   0b01100110, 0b01101101, 0b01111100, 0b00000111,
   0b01111111, 0b01100111
};


void main () {

   int numero = 0;
   int i,j;
     
   // Configurando os pinos dos displays como saída
   //output_c;
   //output_d;
   While(True){
      for(i=0;i<10;i++){
         for(j=0;j<10;j++){
            output_c(segmentos[numero/10]);
            output_d(segmentos[numero%10]);
                  
         numero++;
         //reinicia a contagem
         if(numero==100){
         numero=0;
         }  delay_ms(100);
   }

}}  
}



