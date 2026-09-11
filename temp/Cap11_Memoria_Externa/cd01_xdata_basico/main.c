/* main.c
 * Declaracao de variaveis na memoria externa
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 11 - Memoria Externa e E/S Mapeada em Memoria
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 32768 --code-size 8192 main.c
 */

#include <8052.h>

// vetor de 256 bytes, alocado pelo linker no XDATA
__xdata unsigned char buffer[256];

// variavel em pagina de 256 bytes
__pdata unsigned char contador;

// registrador de periferico em endereco fixo
__xdata __at (0x8000) volatile unsigned char SAIDA;

void main(void)
{
    unsigned int i;

    for (i = 0; i < 256; i++)
        buffer[i] = (unsigned char)i;

    SAIDA = 0xAA;

    while (1)
        ;
}
