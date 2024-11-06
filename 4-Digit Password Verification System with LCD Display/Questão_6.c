#include <Questao_4.h>
#include <KBD.C>

#define LCD_DATA_PORT getenv("SFR:PORTB")
#include <lcd.c>

char c;
char pass[5];
char senha[5];
int cont = 0;
int ver = 0;

void main()
{
   kbd_init();
   lcd_init();
   
   printf(lcd_putc,"\fCrie a senha:\n");
   delay_ms(50);
   
   while(cont < 4)
   {   
      c = kbd_getc(); 
      delay_ms(1);
      
      if(c != 0)
      {
         pass[cont] = c;
         printf(lcd_putc,"%c", c);
         delay_ms(300);
         cont++;
      }
   }
   
   pass[cont] = '\0'; // Adiciona o caractere nulo no final da string
   
   while(TRUE)
   {
      cont = 0; // Reseta o contador para a próxima senha
      printf(lcd_putc,"\fDigite a senha:\n");
      delay_ms(50);
      
      while(cont < 4)
      {   
         c = kbd_getc(); 
         delay_ms(1);
         
         if(c != 0)
         {
            senha[cont] = c;
            printf(lcd_putc,"%c", c);
            delay_ms(300);
           
            if(c == pass[cont]){
               ver++;
            }
            if(cont == 3){
               if(ver == 4){
                  printf(lcd_putc,"\nSenha correta");
                  output_high(pin_c0);
                  output_low(pin_c1);
                  output_high(pin_c2);
                  delay_ms(2000);
                  output_low(pin_c0);
                  output_low(pin_c1);
                  output_low(pin_c2);
                  
                  senha[cont] = '\0'; // Adiciona o caractere nulo no final da string
                  ver = 0;
               }else {
                  printf(lcd_putc,"\nSenha incorreta");
                  output_high(pin_c3);
                  delay_ms(2000);
                  output_low(pin_c3);
                  ver = 0;
               }
            }
            cont++;
         }
      }
   }
}

