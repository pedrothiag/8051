/* main.c
 * Modo de Contagem do TIMER2
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 4 - Temporizadores
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define LED P1_0

void timer2_setup(void) {
    T2CON = 0x00;   // Temporizador, recarga automatica
    RCAP2H = 0xFC;  // Valor de recarga (byte alto)
    RCAP2L = 0x18;  // Valor de recarga (byte baixo)
    
    TH2 = 0xFC;     // Valor inicial igual ao da recarga
    TL2 = 0x18;
    
    TF2 = 0;        // Limpa TF2
    TR2 = 0;        // Deixa o temporizador 2 parado
}

void delay_ms(unsigned int n) {
    TF2 = 0;        // Descarta um estouro anterior
    TR2 = 1;        // Inicia a contagem
    while (n--) {
        while (TF2 == 0);   // Aguarda o estouro (1 ms)
        TF2 = 0;            // TF2 nao e limpa pelo hardware
    }
    TR2 = 0; // Para o temporizador 2
}

void main(void) {
    timer2_setup();
    while (1) {
        LED = !LED; // Inverte o estado do LED
        delay_ms(300); // Aproximadamente 500 ms
    }
}
