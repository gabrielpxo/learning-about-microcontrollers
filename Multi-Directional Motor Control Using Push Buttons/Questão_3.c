#include <16f628a.h>
#use delay(clock=400000)
#fuses INTRC_IO,NOWDT,PUT,BROWNOUT,NOLVP,NOMCLR

void main(){ 

   while(true){
      if(input(pin_a0) == 1){
         //Rotaciona os motores sentido horário
         output_low(pin_b0);
         output_high(pin_b1);
         output_high(pin_b2);
         output_low(pin_b3);
         output_high(pin_b4);
      }
      if(input(pin_a1) == 1){
         //Rotaciona os motores sentido anti-horário
         output_high(pin_b0);
         output_low(pin_b1);
         output_high(pin_b2);
         output_high(pin_b3);
         output_low(pin_b4);
      }
      if(input(pin_a2) == 1){
         //Rotaciona os motores ambos os sentidos
         output_low(pin_b0);
         output_high(pin_b1);
         output_high(pin_b2);
         output_high(pin_b3);
         output_low(pin_b4);
      }
   }
}
