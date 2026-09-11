/* main.c
 * Mesmo programa na sintaxe do SDCC
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Anexo B - Conversao de SDCC para Keil C51
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define LED P1_0

__code const unsigned char tabela[3] = {1, 2, 4};

void main(void)
{
    IT0 = 1;
    EX0 = 1;
    EA  = 1;

    while (1) {
        // laco principal livre
    }
}

void int0_isr(void) __interrupt(0) __using(1)
{
    LED = !LED;
}
