/* perifericos.h
 * Modulo de apoio reproduzido do livro
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 11 - Memoria Externa e E/S Mapeada em Memoria
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 32768 --code-size 8192 main.c uart.c perifericos.c
 */

#ifndef PERIFERICOS_H
#define PERIFERICOS_H

// mapa de memoria do sistema
#define SRAM_BASE     0x0000
#define SAIDA_BASE    0x8000
#define ENTRADA_BASE  0x9000

// porta de saida (somente escrita)
void saida_init(void);
void saida_escreve(unsigned char valor);
void saida_liga(unsigned char mascara);
void saida_desliga(unsigned char mascara);
void saida_alterna(unsigned char mascara);
unsigned char saida_estado(void);

// porta de entrada (somente leitura)
unsigned char entrada_le(void);
unsigned char entrada_bit(unsigned char n);

#endif
