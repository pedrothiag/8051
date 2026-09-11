/* main.c
 * Acionamento em meio passo de um motor unipolar
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

// P1.0..P1.3 vao as entradas IN1..IN4 do ULN2003
__code const unsigned char meio_passo[8] = {
    0x01, 0x03, 0x02, 0x06,
    0x04, 0x0C, 0x08, 0x09
};

void delay_ms(unsigned int ms)
{
    volatile unsigned int i, j;

    for (i = 0; i < ms; i++)
        for (j = 0; j < 114; j++);
}

// horario = 1 avanca na tabela; 0 retrocede
void passo(unsigned char horario)
{
    static unsigned char i = 0;

    if (horario)
        i = (unsigned char)((i + 1) & 0x07);
    else
        i = (unsigned char)((i - 1) & 0x07);

    // preserva P1.4..P1.7
    P1 = (P1 & 0xF0) | meio_passo[i];
    delay_ms(2);
}

void gira(unsigned int passos, unsigned char horario)
{
    unsigned int k;

    for (k = 0; k < passos; k++)
        passo(horario);
}

void main(void)
{
    P1 = 0xF0;  // todas as bobinas desligadas

    while (1) {
        // uma volta completa no sentido horario
        gira(4096, 1);
        P1 &= 0xF0;      // libera as bobinas
        delay_ms(1000);

        // e uma volta no sentido oposto
        gira(4096, 0);
        P1 &= 0xF0;
        delay_ms(1000);
    }
}
