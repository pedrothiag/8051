/* main.c
 * Programa basico em C para o AT89S52 com o SDCC
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 3 - Ferramentas de Desenvolvimento
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

void main(void)
{
    // Configuracao inicial: executada uma unica vez.
    P1 = 0xFF;

    while (1) {
        // Laco principal: executado continuamente.
    }
}
