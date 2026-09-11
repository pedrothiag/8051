/* main.c
 * Temporizador 0 em modo 3: dois contadores de 8 bits
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 4 - Temporizadores
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define SAIDA_0 P1_0
#define SAIDA_1 P1_1

void timer_setup(void) {
    TMOD = 0x33;               /* TIMER0 em Modo 3 */
    TR0 = 0;                   /* Desligar TL0. */
    TR1 = 0;                   /* Desligar TH0. */

    TL0 = 0x06;                /* 250us */
    TH0 = 0x9C;                /* 100us */

    TF0 = 0;             /* Limpa a flag de TL0. */
    TF1 = 0;             /* Limpa a flag de TH0. */
    TR0 = 1;                   /* Inicia TL0. */
    TR1 = 1;                   /* Inicia TH0. */
}

void main(void) {
    SAIDA_0 = 0;
    SAIDA_1 = 0;
    timer_setup();

    while (1) {
        if (TF0 != 0) {
            TR0 = 0;   /* Para TL0 para recarregar. */
            TL0 = 0x06;
            TF0 = 0;
            SAIDA_0 = !SAIDA_0;
            TR0 = 1;
        }
        if (TF1 != 0) {
            TR1 = 0;   /* Para TH0 para recarregar. */
            TH0 = 0x9C;
            TF1 = 0;
            SAIDA_1 = !SAIDA_1;
            TR1 = 1;
        }
    }
}
