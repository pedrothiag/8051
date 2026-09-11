/* main.c
 * Teste da memoria SRAM externa
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 11 - Memoria Externa e E/S Mapeada em Memoria
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 32768 --code-size 8192 main.c uart.c
 */

#include <8052.h>

// funcoes da porta serial, do Capitulo 6
extern void uart_init(void);
extern void uart_puts(const char *s);
extern void uart_num(unsigned int valor);

#define SRAM_FIM 0x7FFF

// escreve o padrao em toda a faixa e o rele;
// devolve o numero de posicoes com defeito
unsigned int testa(unsigned char padrao)
{
    __xdata unsigned char *p;
    unsigned int endereco;
    unsigned int falhas = 0;

    for (endereco = 0; endereco <= SRAM_FIM; endereco++) {
        p = (__xdata unsigned char *)endereco;
        *p = padrao;
    }

    for (endereco = 0; endereco <= SRAM_FIM; endereco++) {
        p = (__xdata unsigned char *)endereco;
        if (*p != padrao)
            falhas++;
    }

    return falhas;
}

// escreve o byte baixo do proprio endereco em cada
// posicao; detecta linhas de endereco trocadas
unsigned int testa_enderecos(void)
{
    __xdata unsigned char *p;
    unsigned int endereco;
    unsigned int falhas = 0;

    for (endereco = 0; endereco <= SRAM_FIM; endereco++) {
        p = (__xdata unsigned char *)endereco;
        *p = (unsigned char)endereco;
    }

    for (endereco = 0; endereco <= SRAM_FIM; endereco++) {
        p = (__xdata unsigned char *)endereco;
        if (*p != (unsigned char)endereco)
            falhas++;
    }

    return falhas;
}

void main(void)
{
    uart_init();

    uart_puts("0x00: ");
    uart_num(testa(0x00));
    uart_puts(" falhas\r\n0xFF: ");
    uart_num(testa(0xFF));
    uart_puts(" falhas\r\n0x55: ");
    uart_num(testa(0x55));
    uart_puts(" falhas\r\nenderecos: ");
    uart_num(testa_enderecos());
    uart_puts(" falhas\r\n");

    while (1)
        ;
}
