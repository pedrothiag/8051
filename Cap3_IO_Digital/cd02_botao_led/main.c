/* main.c
 * Leitura de um botao e acionamento de um LED
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 3 - Entrada e Saida Digital
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define LED   P1_0
#define BOTAO P3_2

void main(void) {
    BOTAO = 1;  // configura P3.2 como entrada
    while (1) {
        // botao pressionado (nivel baixo)
        if (BOTAO == 0)
            LED = 0;  // acende
        else
            LED = 1;  // apaga
    }
}
