/* main.c
 * Controle de um LED por comandos recebidos pela serial
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 7 - Comunicacao Serial (UART)
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define LED P1_0

void uart_init(void)
{
    TR1 = 0;
    PCON &= 0x7F;  // SMOD = 0
    // modo 1, recepcao habilitada
    SCON = 0x50;
    // temporizador 1 no modo 2
    TMOD = (TMOD & 0x0F) | 0x20;
    TH1 = 0xFD;    // 9600 bps com 11,0592 MHz
    TL1 = 0xFD;
    TF1 = 0;
    TR1 = 1;
    TI  = 1;
}

void uart_putchar(char c)
{
    while (!TI);
    TI = 0;
    SBUF = c;
}

char uart_getchar(void)
{
    char c;

    while (!RI);
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
    char cmd;
    uart_init();
    LED = 1;  // comeca apagado
    uart_puts("Comandos: 1=liga 0=desliga "
              "?=estado\r\n");

    while (1) {
        cmd = uart_getchar();
        switch (cmd) {
            case '1':
                LED = 0;
                uart_puts("LED ligado\r\n");
                break;

            case '0':
                LED = 1;
                uart_puts("LED apagado\r\n");
                break;

            case '?':
                uart_puts(LED ? "Estado: OFF\r\n"
                              : "Estado: ON\r\n");
                break;

            default:
                uart_puts("Comando invalido\r\n");
                break;
        }
    }
}
