/* main.c
 * Registrador de eventos com memoria externa e perifericos mapeados
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 11 - Memoria Externa e E/S Mapeada em Memoria
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 32768 --code-size 8192 main.c uart.c perifericos.c
 */

#include <8052.h>
#include "perifericos.h"

// rotinas da porta serial, do Capitulo 6
extern void uart_init(void);
extern void uart_puts(const char *s);
extern void uart_num(unsigned int valor);

#define LOG_MAX 4096U

// 4 bytes por registro, no inicio da SRAM externa
__xdata __at (SRAM_BASE)
    volatile unsigned char registro[4 * LOG_MAX];

volatile unsigned int segundos = 0;
unsigned int n_registros = 0;

void timer0_isr(void) __interrupt(1)
{
    static unsigned char estouros = 0;

    TH0 = 0x4C;   // 50 ms com cristal de 11,0592 MHz
    TL0 = 0x00;

    if (++estouros >= 20) {
        estouros = 0;
        segundos++;
    }
}

static void grava(unsigned char valor)
{
    __xdata unsigned char *p;

    if (n_registros >= LOG_MAX)
        return;   // memoria cheia

    p = &registro[4 * n_registros];
    p[0] = (unsigned char)(segundos >> 8);
    p[1] = (unsigned char)segundos;
    p[2] = valor;
    p[3] = 0x00;  // reservado
    n_registros++;
}

static void descarrega(void)
{
    __xdata unsigned char *p;
    unsigned int k;
    unsigned int t;

    for (k = 0; k < n_registros; k++) {
        p = &registro[4 * k];
        t = ((unsigned int)p[0] << 8) | p[1];
        uart_num(t);
        uart_puts(" s   ");
        uart_num(p[2]);
        uart_puts("\r\n");
    }
}

void main(void)
{
    unsigned char atual;
    unsigned char anterior;

    uart_init();
    saida_init();

    // temporizador 0 em modo 1, base de 50 ms
    TMOD = (TMOD & 0xF0) | 0x01;
    TH0 = 0x4C;
    TL0 = 0x00;
    ET0 = 1;
    EA  = 1;
    TR0 = 1;

    anterior = entrada_le();
    grava(anterior);
    saida_escreve(anterior);

    while (1) {
        atual = entrada_le();

        if (atual != anterior) {
            grava(atual);
            saida_escreve(atual);
            anterior = atual;
        }

        // 'D' descarrega o registro pela serial
        if (RI) {
            RI = 0;
            if (SBUF == 'D')
                descarrega();
        }
    }
}
