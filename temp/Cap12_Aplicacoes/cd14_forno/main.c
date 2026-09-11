/* main.c
 * Controle de forno com dois termostatos e histerese
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

// termostatos digitais: o contato fecha para o terra
// quando a temperatura de ajuste e atingida
#define S80   P3_2  // 0 quando T >= 80 C
#define S120  P3_3  // 0 quando T >= 120 C

// LED do MOC3063: acende (aquece) em nivel baixo
#define AQUEC P1_0

#define DESLIGADO 0
#define LIGADO    1
#define ERRO      2

void delay_ms(unsigned int ms)
{
    volatile unsigned int i, j;

    for (i = 0; i < ms; i++)
        for (j = 0; j < 114; j++);
}

void main(void)
{
    unsigned char estado = DESLIGADO;

    S80  = 1;   // libera os dois pinos para entrada
    S120 = 1;
    AQUEC = 1;  // resistencia desligada na partida

    while (1) {
        // leitura incoerente: o sensor de 120 acusa
        // temperatura atingida e o de 80 nao. Sensor
        // rompido, fio solto ou ajuste trocado.
        if ((S120 == 0) && (S80 != 0)) {
            estado = ERRO;
        } else {
            switch (estado) {
            case DESLIGADO:
                // abaixo de 80 C: pode voltar a aquecer
                if (S80 != 0)
                    estado = LIGADO;
                break;

            case LIGADO:
                // acima de 120 C: desliga
                if (S120 == 0)
                    estado = DESLIGADO;
                break;

            case ERRO:
                // a leitura voltou a ser coerente
                estado = DESLIGADO;
                break;
            }
        }

        // a saida depende apenas do estado
        AQUEC = (estado == LIGADO) ? 0 : 1;

        // amostragem lenta: a temperatura de um forno
        // nao muda em milissegundos
        delay_ms(200);
    }
}
