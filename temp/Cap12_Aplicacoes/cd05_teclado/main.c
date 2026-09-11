/* main.c
 * Varredura de um teclado matricial 4x4
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

// linhas em P1.0..P1.3 (saidas)
// colunas em P1.4..P1.7 (entradas)
__code const unsigned char mapa[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

void delay_ms(unsigned int ms)
{
    volatile unsigned int i, j;

    for (i = 0; i < ms; i++)
        for (j = 0; j < 114; j++);
}

// devolve o caractere da tecla, ou 0 se nenhuma
unsigned char teclado_le(void)
{
    unsigned char lin, col, colunas;

    for (lin = 0; lin < 4; lin++) {
        // so a linha atual vai a zero; as colunas
        // permanecem em 1, liberadas para entrada
        P1 = (unsigned char)(~(1 << lin)) | 0xF0;
        colunas = (P1 >> 4) & 0x0F;
        if (colunas == 0x0F)
            continue;  // nada nesta linha
        for (col = 0; col < 4; col++)
            if ((colunas & (1 << col)) == 0)
                return mapa[lin][col];
    }
    return 0;
}

void main(void)
{
    unsigned char tecla, anterior = 0;

    P2 = 0x00;

    while (1) {
        tecla = teclado_le();
        // reage apenas ao ato de pressionar
        if (tecla != 0 && tecla != anterior) {
            delay_ms(20);  // debounce
            if (teclado_le() == tecla)
                P2 = tecla;
        }
        anterior = tecla;
    }
}
