/* main.c
 * Tres canais de PWM independentes para um LED RGB
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 9 - Geracao de PWM
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define PWM_R P1_0
#define PWM_G P1_1
#define PWM_B P1_2

volatile unsigned char dutyR = 80;
volatile unsigned char dutyG = 40;
volatile unsigned char dutyB = 10;
volatile unsigned char cont = 0;

void main(void)
{
    // temporizador 0 no modo 2 (recarga automatica)
    TMOD = 0x02;
    TH0 = 0xA4;  // base de tempo de 100 us
    TL0 = 0xA4;
    // habilita a interrupcao do temporizador 0
    ET0 = 1;
    EA  = 1;
    TR0 = 1;  // inicia a contagem

    while (1) {
        // ajuste dutyR, dutyG e dutyB para as cores
    }
}

void timer0_isr(void) __interrupt(1)
{
    PWM_R = (cont < dutyR) ? 1 : 0;
    PWM_G = (cont < dutyG) ? 1 : 0;
    PWM_B = (cont < dutyB) ? 1 : 0;
    if (++cont >= 100) cont = 0;
}
