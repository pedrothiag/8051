/* tique.c
 * Modulo de apoio reproduzido do livro
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 13 - Introducao a Multitarefa Cooperativa
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c tique.c
 */

#include <8052.h>

volatile unsigned int ticks = 0;

void tique_iniciar(void)
{
    T2CON  = 0x00;   // temporizador, autorrecarga
    RCAP2H = 0xFC;   // 1 ms com cristal de 11,0592 MHz
    RCAP2L = 0x66;
    TH2    = 0xFC;
    TL2    = 0x66;
    ET2    = 1;      // habilita a interrupcao do T2
    TR2    = 1;      // parte a contagem
    EA     = 1;
}

void tique_isr(void) __interrupt(5)
{
    TF2 = 0;         // o T2 nao limpa a flag sozinho
    ticks++;
}
