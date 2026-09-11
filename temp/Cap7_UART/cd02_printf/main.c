/* main.c
 * printf redirecionado para a UART
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 7 - Comunicacao Serial (UART)
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>
#include <stdio.h>

// O SDCC chama esta funcao internamente a partir de
// printf.
int putchar(int c)
{
    while (TI == 0);
    TI = 0;
    SBUF = c;
    return c;
}

void uart_init(void)
{
    TR1 = 0;
    PCON &= 0x7F;
    SCON = 0x50;
    TMOD = (TMOD & 0x0F) | 0x20;
    TH1 = 0xFD;
    TL1 = 0xFD;
    TF1 = 0;
    TR1 = 1;
    TI = 1;
}

void main(void)
{
    unsigned int leitura = 123;
    uart_init();

    while (1) {
        printf("Leitura do sensor: %u\r\n", leitura);
        leitura++;
        // (aqui entraria um atraso)
    }
}
