/* main.c
 * Controle de velocidade e sentido com ponte H
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define ENA P1_0  // habilitacao: recebe o PWM
#define IN1 P1_1  // sentido
#define IN2 P1_2  // sentido

#define B_MAIS    P3_2  // acelera
#define B_MENOS   P3_3  // desacelera
#define B_INVERTE P3_4  // inverte o sentido

volatile unsigned char duty = 0;  // 0..100
volatile unsigned char cont = 0;
__bit sentido = 0;  // 0 = horario, 1 = anti-horario

void delay_ms(unsigned int ms)
{
    volatile unsigned int i, j;

    for (i = 0; i < ms; i++)
        for (j = 0; j < 114; j++);
}

void aplica_sentido(void)
{
    if (sentido) {
        IN1 = 0;
        IN2 = 1;
    } else {
        IN1 = 1;
        IN2 = 0;
    }
}

void inverte(void)
{
    unsigned char guardado = duty;

    duty = 0;       // desacelera ate parar
    delay_ms(500);  // aguarda o motor perder rotacao
    IN1 = 0;        // frenagem: garante corrente nula
    IN2 = 0;
    // dead time antes de trocar o sentido
    delay_ms(50);

    sentido = !sentido;
    aplica_sentido();
    duty = guardado;  // retoma a velocidade anterior
}

void main(void)
{
    // libera os tres pinos para entrada
    B_MAIS    = 1;
    B_MENOS   = 1;
    B_INVERTE = 1;

    IN1 = 0;  // motor parado na partida
    IN2 = 0;
    aplica_sentido();

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
            delay_ms(150);
        }

        if (B_MENOS == 0 && duty > 0) {
            duty -= 5;
            delay_ms(150);
        }

        if (B_INVERTE == 0)
            inverte();
    }
}

void timer0_isr(void) __interrupt(1)
{
    ENA = (cont < duty) ? 1 : 0;
    if (++cont >= 100) cont = 0;
}
