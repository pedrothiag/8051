/* main.c
 * Efeito fade: LED que acende e apaga suavemente
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 9 - Geracao de PWM
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define PWM P1_0
volatile unsigned char duty = 0;
volatile unsigned char cont = 0;

void delay_ms(unsigned int ms)
{
    volatile unsigned int i, j;

    for (i = 0; i < ms; i++)
        for (j = 0; j < 114; j++);
}

void main(void)
{
    unsigned char nivel;

    // temporizador 0 no modo 2 (recarga automatica)
    TMOD = 0x02;
    TH0 = 0xA4;  // base de tempo de 100 us
    TL0 = 0xA4;
    // habilita a interrupcao do temporizador 0
    ET0 = 1;
    EA  = 1;
    TR0 = 1;  // inicia a contagem

    while (1) {
        // clareia
        for (nivel = 0; nivel < 100; nivel++) {
            duty = nivel;
            delay_ms(15);
        }
        // escurece
        for (nivel = 100; nivel > 0; nivel--) {
            duty = nivel;
            delay_ms(15);
        }
    }
}

void timer0_isr(void) __interrupt(1)
{
    PWM = (cont < duty) ? 1 : 0;
    if (++cont >= 100) cont = 0;
}
