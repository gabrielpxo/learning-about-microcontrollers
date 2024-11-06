#include <Questao_4.h>

#include <KBD.C>

#define LCD_DATA_PORT getenv("SFR:PORTB")
#include <lcd.c>

char c;

void main()
{
   kbd_init();

   lcd_init();
   
   printf(lcd_putc,"\fDigite um numero: ");
   delay_ms(50);
   
   while(TRUE)
   {   
      c = kbd_getc(); 
      delay_ms(1);
      
      if(c != 0)
      {
      printf(lcd_putc,"\fNumero: %c", c);
      delay_ms(300);
      }
   }

}
