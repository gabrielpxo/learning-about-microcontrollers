#include <16f628a.h>
#use delay(clock=400000)
#fuses INTRC_IO,NOWDT,PUT,BROWNOUT,NOLVP,NOMCLR


void main(){
  // Inicialização
int contador = 0;
   while(1) {
      if (input(pin_a0) == 1) {
            // Aguarda o botão ser solto
            if (input(pin_a0) == 0);
            // Incrementa a contagem
            contador++;
            delay_ms(5000);
            // Pisca o LED de acordo com a contagem
            for (unsigned char i = 0; i < contador; i++) {
                output_high(pin_b2);
                delay_ms(1000);
                output_low(pin_b2);
                delay_ms(1000);
            }
        }
    }
}

