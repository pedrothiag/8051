/* main.c
 * PWM elementar por atraso de software
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 9 - Geracao de PWM
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define PWM P1_0  // saida PWM (ex.: LED)

void delay_us(unsigned int us)  // atraso aproximado
{
    while (us--) {
        // impede que o laco seja removido
        __asm nop __endasm;
    }
}

void main(void)
{
    // pode ser alterado durante os testes
    volatile unsigned char duty = 30;

    while (1) {
        if (duty != 0) {
            PWM = 1;
            delay_us(duty * 10);
        }
        if (duty != 100) {
            PWM = 0;
            delay_us((100 - duty) * 10);
        }
    }
}
