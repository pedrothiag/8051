/* main.c
 * Multiplexacao de dois digitos por interrupcao
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

__code const unsigned char digito[10] = {
    0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90
};

#define COM_UNID P3_0
#define COM_DEZ  P3_1

// valor exibido (0..99)
volatile unsigned char numero = 0;
// alterna entre os dois displays
__bit vez_das_dezenas = 0;

void delay_ms(unsigned int ms)
{
    volatile unsigned int i, j;

    for (i = 0; i < ms; i++)
        for (j = 0; j < 114; j++);
}

void main(void)
{
    COM_UNID = 1;  // ambos os displays desligados
    COM_DEZ  = 1;

    TMOD = (TMOD & 0xF0) | 0x01;  // Timer 0 em modo 1
    // ~5 ms @ 11,0592 MHz
    TH0 = 0xEE;
    TL0 = 0x00;
    ET0 = 1;  // habilita a interrupcao do temporizador
    EA  = 1;
    TR0 = 1;

    while (1) {
        // O laco principal so decide O QUE mostrar; o
        // rodizio e da ISR.
        for (numero = 0; numero < 100; numero++)
            delay_ms(500);
    }
}

void timer0_isr(void) __interrupt(1)
{
    // recarrega: o modo 1 nao o faz sozinho
    TH0 = 0xEE;
    TL0 = 0x00;

    // apaga os dois antes de trocar o codigo:
    COM_UNID = 1;
    COM_DEZ  = 1;  // evita o ghosting

    if (vez_das_dezenas) {
        P2 = digito[numero / 10];
        COM_DEZ = 0;
    } else {
        P2 = digito[numero % 10];
        COM_UNID = 0;
    }
    vez_das_dezenas = !vez_das_dezenas;
}
