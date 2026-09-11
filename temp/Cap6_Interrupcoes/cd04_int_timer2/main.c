/* main.c
 * Base de tempo pela interrupcao do temporizador 2
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 6 - Interrupcoes
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define LED P1_0
volatile unsigned char ticks = 0;

void main(void)
{
    // timer, recarga automatica de 16 bits
    T2CON = 0x00;
    RCAP2H = 0x3C;  // valor de recarga: 50 ms @ 12 MHz
    RCAP2L = 0xB0;
    TH2 = 0x3C;  // primeira contagem
    TL2 = 0xB0;
    TF2 = 0;
    EXF2 = 0;
    ET2 = 1;  // habilita interrupcao do Timer 2
    EA  = 1;
    TR2 = 1;  // inicia

    while (1) { /* livre */ }
}

void timer2_isr(void) __interrupt(5)
{
    // OBRIGATORIO: limpar a flag explicitamente
    TF2 = 0;
    if (++ticks >= 20) {
        ticks = 0;
        LED = !LED;
    }
}
