/* main.c
 * Contador de pecas com parada automatica da esteira
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define MOTOR   P1_0  // 1 = esteira ligada
#define REARME  P3_3  // 0 = botao pressionado

#define LOTE 10u

volatile unsigned char pecas = 0;
// tempo desde a ultima borda aceita, em multiplos
// de 10 ms; serve de debounce por interrupcao
volatile unsigned char desde = 0xFF;

void delay_ms(unsigned int ms)
{
    volatile unsigned int i, j;

    for (i = 0; i < ms; i++)
        for (j = 0; j < 114; j++);
}

void main(void)
{
    unsigned char n;

    REARME = 1;   // libera o pino para entrada
    MOTOR  = 1;   // a esteira comeca andando

    // temporizador 0 em modo 1: base de 10 ms
    TMOD = (TMOD & 0xF0) | 0x01;
    TH0 = 0xDC;   // 65536 - 10000 = 0xDC00
    TL0 = 0x00;
    ET0 = 1;
    TR0 = 1;

    IT0 = 1;      // INT0 sensivel a borda de descida
    EX0 = 1;
    EA  = 1;

    while (1) {
        // leitura atomica do contador
        EA = 0;
        n = pecas;
        EA = 1;

        // o lote fechou: para a esteira
        MOTOR = (n >= LOTE) ? 0 : 1;

        // rearme: zera a contagem e volta a andar
        if (REARME == 0) {
            delay_ms(20);         // debounce
            if (REARME == 0) {
                EA = 0;
                pecas = 0;
                EA = 1;
                while (REARME == 0)
                    ;             // espera soltar
            }
        }
    }
}

// cada peca produz uma borda de descida em INT0
void int0_isr(void) __interrupt(0)
{
    // ignora bordas a menos de 30 ms da anterior:
    // sao repiques do sensor, nao pecas novas
    if (desde < 3)
        return;
    desde = 0;
    if (pecas < 255)
        pecas++;
}

void timer0_isr(void) __interrupt(1)
{
    TH0 = 0xDC;   // recarrega a base de 10 ms
    TL0 = 0x00;
    if (desde < 0xFF)
        desde++;
}
