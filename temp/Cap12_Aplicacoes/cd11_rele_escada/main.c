/* main.c
 * Temporizador de escada com rele e fotoacoplador
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define BOTAO P3_2   // botao, ativo em 0
#define RELE  P1_0   // LED do 4N25, ativo em 0

// 50 ms por estouro -> 20 estouros por segundo
#define MINUTOS   3
#define ESTOUROS  (20U * 60U * MINUTOS)

volatile unsigned int contador = 0;
volatile unsigned char ligado  = 0;

void delay_ms(unsigned int ms)
{
    volatile unsigned int i, j;

    for (i = 0; i < ms; i++)
        for (j = 0; j < 114; j++);
}

void timer0_isr(void) __interrupt(1)
{
    TH0 = 0x4C;   // 50 ms com cristal de 11,0592 MHz
    TL0 = 0x00;

    if (ligado && ++contador >= ESTOUROS) {
        ligado   = 0;
        contador = 0;
        RELE     = 1;   // apaga a lampada
    }
}

void main(void)
{
    RELE  = 1;    // rele desligado na energizacao
    BOTAO = 1;    // libera o pino para entrada

    TMOD = (TMOD & 0xF0) | 0x01;  // temporizador 0, modo 1
    TH0 = 0x4C;
    TL0 = 0x00;
    ET0 = 1;
    EA  = 1;
    TR0 = 1;

    while (1) {
        if (BOTAO == 0) {
            delay_ms(20);          // debounce
            if (BOTAO == 0) {
                contador = 0;
                ligado   = 1;
                RELE     = 0;      // acende a lampada
                while (BOTAO == 0)
                    ;              // espera soltar
            }
        }
    }
}
