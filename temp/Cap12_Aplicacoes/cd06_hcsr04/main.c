/* main.c
 * Medida de distancia com o HC-SR04
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define TRIG P1_0
#define ECHO P1_1

void delay_us(unsigned int us)
{
    while (us--) {
        __asm nop __endasm;
    }
}

void delay_ms(unsigned int ms)
{
    volatile unsigned int i, j;

    for (i = 0; i < ms; i++)
        for (j = 0; j < 114; j++);
}

// devolve a distancia em cm, ou 0 se nao houve eco
unsigned int hcsr04_mede(void)
{
    unsigned int espera, tempo;

    // 1) pulso de disparo de 10 us
    TRIG = 0;
    delay_us(2);
    TRIG = 1;
    delay_us(10);
    TRIG = 0;

    // 2) espera o inicio do eco, com limite
    for (espera = 0; ECHO == 0; espera++)
        if (espera > 60000u)
            return 0;  // o modulo nao respondeu

    // 3) mede a largura do pulso de eco
    TMOD = (TMOD & 0xF0) | 0x01;  // modo 1, 16 bits
    TH0 = 0x00;
    TL0 = 0x00;
    TF0 = 0;
    TR0 = 1;
    while (ECHO != 0 && TF0 == 0)
        ;
    TR0 = 0;
    if (TF0 != 0)
        return 0;  // estouro: alvo fora de alcance

    tempo = ((unsigned int)TH0 << 8) | TL0;
    // 1 ciclo de maquina = 1 us a 12 MHz
    return tempo / 58u;
}

void main(void)
{
    unsigned int d;

    ECHO = 1;  // libera o pino para entrada
    TRIG = 0;

    while (1) {
        d = hcsr04_mede();
        if (d != 0 && d < 256u)
            P2 = (unsigned char)d;
        else
            P2 = 0xFF;  // sem leitura valida
        // intervalo minimo entre medidas
        delay_ms(60);
    }
}
