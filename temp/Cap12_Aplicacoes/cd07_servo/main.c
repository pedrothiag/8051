/* main.c
 * Controle de posicao de um servomotor
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define SERVO P1_0

// 0..399 (quadro de 20 ms)
volatile unsigned int  contquadro = 0;
// largura em tiques (20..40)
volatile unsigned char pulso = 30;

void delay_ms(unsigned int ms)
{
    volatile unsigned int i, j;

    for (i = 0; i < ms; i++)
        for (j = 0; j < 114; j++);
}

// converte o angulo (0..180) em tiques (20..40)
unsigned char angulo_para_pulso(unsigned char ang)
{
    return 20 + (unsigned char)
                (((unsigned int)ang * 20) / 180);
}

void main(void)
{
    TMOD = 0x02;  // Timer 0, modo 2
    TH0  = 0xD2;  // base de 50 us
    TL0  = 0xD2;
    // habilita a interrupcao do temporizador 0
    ET0 = 1;
    EA  = 1;
    TR0 = 1;

    while (1) {
        pulso = angulo_para_pulso(0);
        delay_ms(1000);

        pulso = angulo_para_pulso(90);
        delay_ms(1000);

        pulso = angulo_para_pulso(180);
        delay_ms(1000);
    }
}

void timer0_isr(void) __interrupt(1)
{
    if (contquadro < pulso)  // parte "alta" do pulso
        SERVO = 1;
    else
        SERVO = 0;

    // fechou o quadro de 20 ms
    if (++contquadro >= 400)
        contquadro = 0;
}
