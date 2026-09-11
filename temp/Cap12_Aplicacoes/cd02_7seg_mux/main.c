/* main.c
 * Multiplexacao de dois digitos no laco principal
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

__code const unsigned char digito[10] = {
    0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90
};

// habilita o display das unidades
#define COM_UNID P3_0
// habilita o display das dezenas
#define COM_DEZ  P3_1

void delay_curto(void)
{
    volatile unsigned char k;

    for (k = 0; k < 200; k++);
}

void mostra(unsigned char valor)  // valor de 0 a 99
{
    // - unidades -
    // desliga o outro display
    COM_DEZ  = 1;
    P2 = digito[valor % 10];  // codigo das unidades
    COM_UNID = 0;             // liga so as unidades
    delay_curto();

    // - dezenas -
    COM_UNID = 1;
    P2 = digito[valor / 10];  // codigo das dezenas
    COM_DEZ  = 0;             // liga so as dezenas
    delay_curto();
}

void main(void)
{
    unsigned char numero = 42;
    COM_UNID = 1;
    COM_DEZ = 1;
    while (1) {
        // chamada continua = ambos parecem acesos
        mostra(numero);
    }
}
