/* main.c
 * Oito LEDs ligados a uma porta inteira
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 3 - Entrada e Saida Digital
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

void delay_ms(unsigned int ms) { 
    volatile unsigned int i, j;
    for(i=0;i<ms;i++) 
        for(j=0;j<120;j++); 
}

void main(void) {
    unsigned char i;

    while (1) {
        // varre da direita para a esquerda
        for (i = 0; i < 8; i++) {
            // acende so o LED i (logica invertida)
            P1 = ~(1 << i);
            delay_ms(100);
        }
        // varre de volta, da esquerda para a direita
        for (i = 6; i > 0; i--) {
            P1 = ~(1 << i);
            delay_ms(100);
        }
    }
}
