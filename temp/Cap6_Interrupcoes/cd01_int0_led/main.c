/* main.c
 * Botao em INT0 alternando um LED
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 6 - Interrupcoes
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define LED P1_0

void main(void)
{
    IT0 = 1;  // INT0 sensivel a borda de descida
    EX0 = 1;  // habilita a interrupcao externa 0
    EA  = 1;  // chave geral

    while (1) {
        // o programa principal fica livre
    }
}

void int0_isr(void) __interrupt(0)
{
    // executado a cada acionamento do botao
    LED = !LED;
}
