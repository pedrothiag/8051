/* main.c
 * Leitura do DHT22 e envio pela porta serial
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c uart.c
 */

#include <8052.h>
#include <stdio.h>

#define DADOS P1_0

// limiar entre o bit 0 (26 us) e o bit 1 (70 us)
#define LIMIAR 45u

// Use com o putchar e o uart_init do Capitulo 6.
void uart_init(void);

void delay_ms(unsigned int ms)
{
    volatile unsigned int i, j;

    for (i = 0; i < ms; i++)
        for (j = 0; j < 114; j++);
}

// mede a duracao do nivel atual da linha; devolve
// 0xFFFF se o temporizador estourar antes da mudanca
static unsigned int mede(unsigned char nivel)
{
    TR0 = 0;
    TH0 = 0x00;
    TL0 = 0x00;
    TF0 = 0;
    TR0 = 1;
    while ((DADOS != 0) == (nivel != 0) && TF0 == 0)
        ;
    TR0 = 0;
    if (TF0 != 0)
        return 0xFFFFu;
    return ((unsigned int)TH0 << 8) | TL0;
}

// devolve 0 se a leitura foi valida
unsigned char dht22_le(unsigned int *ur, int *temp)
{
    unsigned char b[5];
    unsigned char i, j;
    unsigned int largura;

    // - pedido de leitura: 2 ms em zero
    DADOS = 0;
    delay_ms(2);
    DADOS = 1;  // solta a linha; o pull-up a levanta

    // - resposta do sensor: 80 us baixo, 80 us alto
    if (mede(1) == 0xFFFFu) return 1;
    if (mede(0) == 0xFFFFu) return 2;
    if (mede(1) == 0xFFFFu) return 3;

    // - os quarenta bits
    for (i = 0; i < 5; i++) {
        b[i] = 0;
        for (j = 0; j < 8; j++) {
            if (mede(0) == 0xFFFFu)
                return 4;
            largura = mede(1);
            if (largura == 0xFFFFu)
                return 5;
            b[i] = (unsigned char)(b[i] << 1);
            if (largura > LIMIAR)
                b[i] |= 1;
        }
    }

    // - soma de verificacao
    j = (unsigned char)(b[0] + b[1] + b[2] + b[3]);
    if (j != b[4])
        return 6;

    *ur = ((unsigned int)b[0] << 8) | b[1];
    largura = ((unsigned int)(b[2] & 0x7F) << 8) | b[3];
    *temp = (int)largura;
    if ((b[2] & 0x80) != 0)
        *temp = -*temp;
    return 0;
}

void main(void)
{
    unsigned int ur, mag;
    int temp;
    unsigned char erro;
    char sinal;

    uart_init();
    DADOS = 1;
    // temporizador 0 em modo 1, contando ciclos
    TMOD = (TMOD & 0xF0) | 0x01;
    EA = 0;  // nenhuma interrupcao durante a medida

    while (1) {
        // o DHT22 exige 2 s entre leituras
        delay_ms(2000);

        erro = dht22_le(&ur, &temp);
        if (erro != 0) {
            printf("falha na leitura (%u)\r\n",
                   (unsigned int)erro);
            continue;
        }

        if (temp < 0) {
            sinal = '-';
            mag = (unsigned int)(-temp);
        } else {
            sinal = '+';
            mag = (unsigned int)temp;
        }

        printf("T = %c%u,%u C   UR = %u,%u %%\r\n",
               sinal, mag / 10u, mag % 10u,
               ur / 10u, ur % 10u);
    }
}
