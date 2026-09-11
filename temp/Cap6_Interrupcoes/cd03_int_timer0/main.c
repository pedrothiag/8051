/* main.c
 * LED alternado a cada segundo pela interrupcao do temporizador 0
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
    TMOD = 0x01;  // Timer 0, modo 1
    TH0 = 0x3C;   // 65536 - 50000 = 0x3CB0
    TL0 = 0xB0;
    ET0 = 1;  // habilita interrupcao do Timer 0
    EA  = 1;  // chave geral
    TR0 = 1;  // inicia o timer

    while (1) { /* livre */ }
}

void timer0_isr(void) __interrupt(1)
{
    TH0 = 0x3C;  // recarrega para o proximo ciclo
    TL0 = 0xB0;
    if (++ticks >= 20) {// 20 x 50 ms = 1 s
        ticks = 0;
        LED = !LED;
    }
}
