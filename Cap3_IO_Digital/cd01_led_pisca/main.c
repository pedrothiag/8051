/* main.c
 * LED piscando a cada 500 ms
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 3 - Entrada e Saida Digital
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define LED P1_0

void delay_ms(unsigned int ms) {
    volatile unsigned int i, j;
    for (i = 0; i < ms; i++)
        // valor aproximado; calibre no projeto
        for (j = 0; j < 120; j++);
}

void main(void) {
    while (1) {
        LED = 0;  // nivel baixo -> LED acende
        delay_ms(500);
        LED = 1;  // nivel alto  -> LED apaga
        delay_ms(500);
    }
}
