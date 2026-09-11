/* uart.c
 * Modulo de apoio reproduzido do livro
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 11 - Memoria Externa e E/S Mapeada em Memoria
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 32768 --code-size 8192 main.c uart.c
 */

#include <8052.h>

void uart_init(void)
{
    TR1  = 0;
    PCON &= 0x7F;                 // SMOD = 0
    // modo 1 (8 bits), recepcao habilitada (REN=1)
    SCON = 0x50;
    TMOD = (TMOD & 0x0F) | 0x20;  // preserva o Timer 0
    // 9600 baud @ 11,0592 MHz
    TH1  = 0xFD;
    TL1  = 0xFD;
    TF1  = 0;
    TR1  = 1;  // inicia o Timer 1
    TI   = 1;  // marca o transmissor como livre
}

void uart_putchar(char c)
{
    // espera o transmissor ficar livre
    while (TI == 0);
    TI = 0;
    SBUF = c;  // carregar SBUF inicia a transmissao
}

char uart_getchar(void)
{
    char c;
    while (RI == 0);  // espera chegar um dado
    c = SBUF;
    RI = 0;
    return c;
}

void uart_puts(const char *s)
{
    while (*s)
        uart_putchar(*s++);
}

void main(void)
{
    uart_init();
    uart_puts("AT89S52 pronto!\r\n");

    while (1) {
        // eco: devolve tudo que receber
        char c = uart_getchar();
        uart_putchar(c);
    }
}

void uart_num(unsigned int valor)
{
    char buffer[6];  // ate 5 digitos (65535) + folga
    signed char i = 0;

    if (valor == 0) {  // caso especial: o zero
        uart_putchar('0');
        return;
    }
    // extrai os digitos de tras para frente
    while (valor > 0) {
        buffer[i++] = '0' + (valor % 10);
        valor /= 10;
    }
    while (i > 0)  // envia na ordem correta
        uart_putchar(buffer[--i]);
}
