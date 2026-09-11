/* main.c
 * Temporizador 0, INT0 e INT1 em conjunto
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 6 - Interrupcoes
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define LED P1_0
volatile unsigned char contador = 0;
volatile unsigned char ticks = 0;

void main(void)
{
    TMOD = 0x01;  // Timer 0 modo 1
    TH0 = 0x3C;   // 50 ms @ 12 MHz
    TL0 = 0xB0;
    ET0 = 1;  // interrupcao do temporizador
    TR0 = 1;  // inicia a contagem

    IT0 = 1;  // INT0 por borda
    EX0 = 1;
    IT1 = 1;  // INT1 por borda
    EX1 = 1;

    EA = 1;  // chave geral

    while (1) {
        // mostra o contador nos LEDs de P2
        P2 = contador;
    }
}

void timer0_isr(void) __interrupt(1)  // base de tempo
{
    TH0 = 0x3C;  // recarrega
    TL0 = 0xB0;

    if (++ticks >= 20) {  // 20 x 50 ms = 1 s
        ticks = 0;
        LED = !LED;
    }
}

void int0_isr(void) __interrupt(0)  // botao 1: zera
{
    contador = 0;
}

// botao 2: incrementa
void int1_isr(void) __interrupt(2)
{
    contador++;
}
