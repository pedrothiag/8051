/* main.c
 * Recepcao serial por interrupcao com buffer circular
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 7 - Comunicacao Serial (UART)
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define TAM 16
volatile unsigned char buf[TAM];
volatile unsigned char cabeca = 0, cauda = 0;

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
    ES = 1;  // habilita a interrupcao serial
    EA = 1;  // chave geral
}

// retorna 1 se ha dado disponivel no buffer
__bit uart_tem_dado(void)
{
    return (cabeca != cauda);
}

// le um dado do buffer (chame apenas se
// uart_tem_dado() == 1)
unsigned char uart_le(void)
{
    unsigned char c = buf[cauda];
    cauda = (cauda + 1) % TAM;
    return c;
}

void main(void)
{
    uart_init();
    while (1) {
        if (uart_tem_dado()) {
            unsigned char c = uart_le();
            // usa o dado (ex.: mostra nos LEDs)
            P2 = c;
        }
    }
}

void serial_isr(void) __interrupt(4)
{
    if (RI) {  // chegou um byte?
        unsigned char recebido;
        unsigned char proxima;
        recebido = SBUF;
        RI = 0;  // limpa a flag de recepcao
        proxima = (cabeca + 1) % TAM;
        // descarta se o buffer estiver cheio
        if (proxima != cauda) {
            buf[cabeca] = recebido;
            cabeca = proxima;
        }
    }
    // if (TI) { TI = 0; }           // trate a
    // transmissao se usar por ISR
}
