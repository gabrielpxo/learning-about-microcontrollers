// EXEMPLO  03. SEMÁFORO SIMPLES

#include <18F2221.h>
#use delay(clock=4000000)
#fuses INTRC_IO,NOWDT,PUT,BROWNOUT,NOLVP,NOMCLR

#DEFINE S1_R PIN_B2
#DEFINE S1_Y PIN_B1
#DEFINE S1_G PIN_B0
#DEFINE S2_R PIN_B5
#DEFINE S2_Y PIN_B4
#DEFINE S2_G PIN_B3

int8 segmentos[] = {
   0b0111111,  // 0
   0b0000110,  // 1
   0b1011011,  // 2
   0b1001111,  // 3
   0b1100110,  // 4
   0b1101101,  // 5
   0b1111101,  // 6
   0b0000111,  // 7
   0b1111111,  // 8
   0b1101111   // 9
};


void main(){ 

   while(1){
//S1
       output_low(S1_R); //VERDE
       output_low(S1_Y); 
       output_high(S1_G); 
        
       //S2
       output_high(S2_R); //VERMELHO
       output_low(S2_Y); 
       output_low(S2_G); 
       
       delay_ms(100);
       
       //S1
       output_high(S1_Y); //AMARELO
       output_low(S1_G); 
       
       //S2
       output_high(S2_R); //VERMELHO
       
        delay_ms(100); //espera 4s
      //S1
       output_high(S1_R); //VERMELHO
       output_low(S1_Y);
       output_low(S1_G); 
       //S2
       output_low(S2_R); //VERDE
       output_high(S2_G); 
        
       delay_ms(100);
       //S1
       output_low(S1_Y); //VERMELHO
       output_high(S1_R);
       //S2
        output_high(S2_Y);
        output_low(S2_G); 
        
        if((input(pin_a0))==1){
            break;}
   }
   
   int numero = 9;
   while(1){
      if((input(pin_a0))==1){
         while(numero>=0){
            output_c(segmentos[numero]);
            numero--;
            delay_ms(100);
            if(numero == 0){
               break;}
         }
         numero = 9;  // reset the count
         //S1
         output_high(S1_G); //VERDE
         output_low(S1_R); 
         output_low(S1_Y);
         //S2
         output_high(S2_R); //VERMELHO
         output_low(S2_Y); 
         output_low(S2_G); 
      }
   }
   
}

