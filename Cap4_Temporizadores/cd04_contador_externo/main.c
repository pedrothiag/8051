/* main.c
 * Contagem de pulsos externos no pino T1
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 4 - Temporizadores
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

void main(void) {
    // Temporizador 1: modo 1 (16 bits) + C/T=1
    TMOD = 0x50;
    TL1 = 0x00;
    TH1 = 0x00;
    TR1 = 1;  // Habilita a contagem

    while (1) {
        // Mostra o byte baixo da contagem em P0
        P0 = TL1;
    }
}
