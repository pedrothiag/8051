/* main.c
 * Contagem de 0 a 9 em um display de sete segmentos
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

// Codigos 0..9 para display de ANODO COMUM (segmento
// acende em 0)
__code const unsigned char digito[10] = {
    0xC0, 0xF9, 0xA4, 0xB0, 0x99,
    0x92, 0x82, 0xF8, 0x80, 0x90
};

void delay_ms(unsigned int ms)
{
    volatile unsigned int i, j;

    for (i = 0; i < ms; i++)
        for (j = 0; j < 120; j++);
}

void main(void)
{
    unsigned char n;

    while (1) {
        for (n = 0; n < 10; n++) {
            P2 = digito[n];  // mostra o algarismo n
            delay_ms(700);
        }
    }
}
