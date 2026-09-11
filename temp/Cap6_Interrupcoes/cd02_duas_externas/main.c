/* main.c
 * Duas interrupcoes externas simultaneas
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 6 - Interrupcoes
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define LED_INT0 P1_0
#define LED_INT1 P1_1

void main(void)
{
    LED_INT0 = 1;
    LED_INT1 = 1;

    IT0 = 1;  // ambas por borda de descida
    IT1 = 1;
    PX0 = 0;  // INT0: prioridade baixa
    PX1 = 1;  // INT1: prioridade alta
    EX0 = 1;
    EX1 = 1;
    EA = 1;

    while (1) {
        // outras tarefas podem ser executadas aqui
    }
}

void int0_isr(void) __interrupt(0)
{
    LED_INT0 = !LED_INT0;
}

void int1_isr(void) __interrupt(2)
{
    LED_INT1 = !LED_INT1;
}
