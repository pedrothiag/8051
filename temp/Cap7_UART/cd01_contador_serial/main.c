/* main.c
 * Transmissao periodica de um contador pela serial
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 7 - Comunicacao Serial (UART)
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c uart.c
 */

#include <8052.h>

// Use com as funcoes uart_init, uart_puts e uart_num
// apresentadas acima.
void uart_init(void);
void uart_puts(const char *s);
void uart_num(unsigned int valor);

void delay_ms(unsigned int ms)
{
    volatile unsigned int i, j;

    for (i = 0; i < ms; i++)
        for (j = 0; j < 114; j++);
}

void main(void)
{
    unsigned int contador = 0;

    uart_init();
    uart_puts("AT89S52 iniciando transmissao...\r\n");

    while (1) {
        uart_puts("Contagem: ");
        // envia o valor como texto legivel
        uart_num(contador);
        // pula de linha no terminal
        uart_puts("\r\n");

        contador++;
        delay_ms(1000);  // envia uma vez por segundo
    }
}
