/* main.c
 * Temporizador 0 em modo 1: base de 1 ms
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 4 - Temporizadores
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define LED P1_0

void timer_setup(void) {
    TMOD &= 0xF0;  // Limpa o modo do temporizador 0
    // Temporizador 0 em modo 1 (16 bits)
    TMOD |= 0x01;
    TF0 = 0;       // Limpa TF0
    TR0 = 0;       // Deixa o temporizador 0 parado
}

void timer_1ms(void) {
    TR0 = 0;     // Para o temporizador 0
    TH0 = 0xFC;  // Valor inicial: 0xFC18
    TL0 = 0x18;
    TR0 = 1;           // Inicia o temporizador 0
    while (TF0 == 0);  // Aguarda o estouro
    TR0 = 0;           // Para o temporizador 0
    TF0 = 0;           // Limpa TF0
}

void delay_ms(unsigned int n) {
    while (n--)
        timer_1ms();
}

void main(void) {
    timer_setup();
    while (1) {
        LED = !LED;     // Inverte o estado do LED
        delay_ms(200);  // Aproximadamente 500 ms
    }
}
