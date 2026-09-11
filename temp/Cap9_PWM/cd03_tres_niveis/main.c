/* main.c
 * Tres niveis de brilho selecionados por botoes
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 9 - Geracao de PWM
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define PWM     P1_0
#define B_BAIXO P3_2
#define B_MEDIO P3_3
#define B_ALTO  P3_4

volatile unsigned char duty = 50;
volatile unsigned char cont = 0;

void main(void)
{
    B_BAIXO = 1;  // libera os tres pinos para entrada
    B_MEDIO = 1;
    B_ALTO  = 1;

    // temporizador 0 no modo 2 (recarga automatica)
    TMOD = 0x02;
    TH0 = 0xA4;  // base de tempo de 100 us
    TL0 = 0xA4;
    // habilita a interrupcao do temporizador 0
    ET0 = 1;
    EA  = 1;
    TR0 = 1;  // inicia a contagem

    while (1) {
        if (B_BAIXO == 0) duty = 20;
        if (B_MEDIO == 0) duty = 50;
        if (B_ALTO  == 0) duty = 90;
    }
}

void timer0_isr(void) __interrupt(1)
{
    PWM = (cont < duty) ? 1 : 0;
    if (++cont >= 100) cont = 0;
}
