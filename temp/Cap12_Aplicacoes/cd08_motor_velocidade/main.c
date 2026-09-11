/* main.c
 * Velocidade do motor ajustada por dois botoes
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

// entrada do circuito de acionamento
#define PWM P1_0
#define B_MAIS  P3_2  // acelera
#define B_MENOS P3_3  // desacelera

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
    B_MAIS  = 1;  // libera os dois pinos para entrada
    B_MENOS = 1;

    // temporizador 0 no modo 2 (recarga automatica)
    TMOD = 0x02;
    TH0 = 0xA4;  // base de tempo de 100 us
    TL0 = 0xA4;
    // habilita a interrupcao do temporizador 0
    ET0 = 1;
    EA  = 1;
    TR0 = 1;  // inicia a contagem

    while (1) {
        if (B_MAIS == 0 && duty < 100) {
            duty += 5;
            // debounce e limita a taxa de repeticao
            delay_ms(150);
        }

        if (B_MENOS == 0 && duty > 0) {
            duty -= 5;
            delay_ms(150);
        }
    }
}

void timer0_isr(void) __interrupt(1)
{
    PWM = (cont < duty) ? 1 : 0;
    if (++cont >= 100) cont = 0;
}
