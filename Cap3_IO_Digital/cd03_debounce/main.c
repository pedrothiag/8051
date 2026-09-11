/* main.c
 * Antirrepique de um botao por software
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 3 - Entrada e Saida Digital
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define LED   P1_0
#define BOTAO P3_2

void delay_ms(unsigned int ms) { 
    volatile unsigned int i, j;
    for(i=0;i<ms;i++) 
        for(j=0;j<120;j++); 
}

void main(void) {
    BOTAO = 1;
    LED = 1;
    while (1) {
        if (BOTAO == 0) {      // parece pressionado
            // espera o repique passar
            delay_ms(20);
            if (BOTAO == 0) {  // confirma
                LED = !LED;    // alterna o LED
                // espera soltar o botao
                while (BOTAO == 0);
            }
        }
    }
}
