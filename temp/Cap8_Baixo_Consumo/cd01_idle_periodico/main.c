/* main.c
 * Tarefa periodica com Idle entre as execucoes
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 8 - Modos de Baixo Consumo
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define LED P1_0
volatile __bit acordar = 0;

void main(void)
{
    TMOD = 0x01;  // Timer 0, modo 1
    TH0 = 0x3C;   // 50 ms @ 12 MHz
    TL0 = 0xB0;
    ET0 = 1;  // interrupcao do temporizador 0
    EA  = 1;  // chave geral
    TR0 = 1;  // inicia a contagem

    while (1) {
        // ENTRA EM IDLE: dorme ate a interrupcao
        PCON |= 0x01;

        // ao acordar, a execucao continua aqui:
        if (acordar) {
            acordar = 0;
            // tarefa periodica (a cada ~50 ms)
            LED = !LED;
        }
    }
}

void timer0_isr(void) __interrupt(1)
{
    TH0 = 0x3C;  // recarrega
    TL0 = 0xB0;
    acordar = 1;  // sinaliza o motivo de acordar
}
