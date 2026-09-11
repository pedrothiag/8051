/* main.c
 * PWM de um canal por interrupcao do temporizador 0
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 9 - Geracao de PWM
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define PWM P1_0

// ciclo de trabalho 0..100
volatile unsigned char duty = 50;
volatile unsigned char cont = 0;  // contador 0..99

void main(void)
{
    // Timer 0 em modo 2 (8 bits, recarga automatica)
    TMOD = 0x02;
    // recarga: interrupcao a cada ~100 us
    TH0  = 0xA4;
    TL0  = 0xA4;
    ET0  = 1;  // habilita interrupcao do Timer 0
    EA   = 1;  // chave geral
    TR0  = 1;  // inicia o timer

    while (1) {
        // a CPU esta livre; duty pode ser alterado a
        // qualquer momento
    }
}

void timer0_isr(void) __interrupt(1)
{
    if (cont < duty)  // dentro da fracao "ligada"?
        PWM = 1;
    else
        PWM = 0;

    // fechou um periodo de 100 passos
    if (++cont >= 100)
        cont = 0;
}
