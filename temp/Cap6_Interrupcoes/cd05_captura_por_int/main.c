/* main.c
 * Captura do temporizador 2 atendida por interrupcao
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 6 - Interrupcoes
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

volatile unsigned int marca_capturada;
volatile __bit nova_captura = 0;

void main(void)
{
    unsigned int atual;
    unsigned int anterior = 0;
    unsigned int periodo;
    unsigned char primeira = 1;

    P1_1 = 1;  // libera T2EX/P1.1 para entrada
    // captura por borda de descida em T2EX
    T2CON = 0x09;
    TH2 = 0x00;
    TL2 = 0x00;
    TF2 = 0;
    EXF2 = 0;
    ET2 = 1;  // habilita a interrupcao do Timer 2
    EA = 1;
    TR2 = 1;

    while (1) {
        if (nova_captura) {
            // torna atomica a copia de 16 bits
            ET2 = 0;
            atual = marca_capturada;
            nova_captura = 0;
            ET2 = 1;

            if (primeira) {
                anterior = atual;
                primeira = 0;
            } else {
                periodo = atual - anterior;
                anterior = atual;
                P2 = (unsigned char)(periodo >> 8);
                P0 = (unsigned char)periodo;
            }
        }
    }
}

void timer2_isr(void) __interrupt(5)
{
    if (EXF2) {
        // evita alterar RCAP2H:L durante a leitura
        EXEN2 = 0;
        marca_capturada =
            ((unsigned int)RCAP2H << 8) | RCAP2L;
        EXF2 = 0;
        EXEN2 = 1;
        nova_captura = 1;
    }
    if (TF2)
        TF2 = 0;
}
