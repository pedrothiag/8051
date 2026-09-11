/* perifericos.c
 * Modulo de apoio reproduzido do livro
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 11 - Memoria Externa e E/S Mapeada em Memoria
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 32768 --code-size 8192 main.c uart.c perifericos.c
 */

#include "perifericos.h"

__xdata __at (SAIDA_BASE)
    volatile unsigned char REG_SAIDA;
__xdata __at (ENTRADA_BASE)
    volatile unsigned char REG_ENTRADA;

// O 74HC574 nao devolve nada ao barramento: a porta de
// saida nao pode ser lida. O driver guarda uma copia.
static unsigned char espelho = 0x00;

void saida_init(void)
{
    espelho = 0x00;
    REG_SAIDA = espelho;
}

void saida_escreve(unsigned char valor)
{
    espelho = valor;
    REG_SAIDA = espelho;
}

void saida_liga(unsigned char mascara)
{
    espelho |= mascara;
    REG_SAIDA = espelho;
}

void saida_desliga(unsigned char mascara)
{
    espelho &= (unsigned char)~mascara;
    REG_SAIDA = espelho;
}

void saida_alterna(unsigned char mascara)
{
    espelho ^= mascara;
    REG_SAIDA = espelho;
}

unsigned char saida_estado(void)
{
    return espelho;
}

unsigned char entrada_le(void)
{
    return REG_ENTRADA;
}

unsigned char entrada_bit(unsigned char n)
{
    return (unsigned char)((REG_ENTRADA >> n) & 0x01);
}
