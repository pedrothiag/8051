/* main.c
 * Power-Down com despertar por botao em INT0
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 8 - Modos de Baixo Consumo
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define LED P1_0
// botao em INT0, entre P3.2 e o GND
#define BOTAO P3_2

void delay_ms(unsigned int ms)
{
    volatile unsigned int i, j;

    for (i = 0; i < ms; i++)
        for (j = 0; j < 114; j++);
}

void main(void)
{
    // libera P3.2 para funcionar como entrada
    BOTAO = 1;
    LED = 1;
    // INT0 por NIVEL: exigido para sair do power-down
    IT0 = 0;
    EX0 = 1;  // habilita a interrupcao externa 0
    EA  = 1;  // chave geral

    while (1) {
        // - fase de trabalho: pisca 3 vezes para
        // mostrar que acordou -
        unsigned char k;
        for (k = 0; k < 6; k++) {
            LED = !LED;
            delay_ms(150);
        }
        LED = 1;  // apaga

        // Rearma a interrupcao somente depois que o
        // botao estiver solto.
        while (BOTAO == 0);
        delay_ms(20);
        IE0 = 0;
        EX0 = 1;

        // - vai dormir profundamente ate o proximo
        // toque no botao -
        PCON |= 0x02;  // ENTRA EM POWER-DOWN

        // a execucao so retorna aqui depois que o
        // botao (INT0) acordar o chip
    }
}

void int0_isr(void) __interrupt(0)
{
    // evita novo atendimento ate soltar o botao
    EX0 = 0;
}
