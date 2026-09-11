/* main.c
 * Controle de uma bomba por maquina de estados
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 3 - Entrada e Saida Digital
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define SENSOR_MIN P3_0
#define SENSOR_MAX P3_1
#define BOMBA      P1_0
#define FALHA      P1_1

typedef enum {
    DESLIGADA,
    LIGADA,
    ERRO
} estado_bomba_t;

void main(void)
{
    volatile estado_bomba_t estado = DESLIGADA;

    // Escreve 1 para liberar os pinos de entrada.
    SENSOR_MIN = 1;
    SENSOR_MAX = 1;

    while (1) {
        switch (estado) {
        case DESLIGADA:
            BOMBA = 1;  // saidas deste estado
            FALHA = 1;
            // maximo molhado com o minimo seco:
            // combinacao fisicamente impossivel
            if ((SENSOR_MAX == 0) && (SENSOR_MIN != 0))
                estado = ERRO;
            else if (SENSOR_MIN != 0)
                estado = LIGADA;
            break;

        case LIGADA:
            BOMBA = 0;
            FALHA = 1;
            if ((SENSOR_MAX == 0) && (SENSOR_MIN != 0))
                estado = ERRO;
            else if (SENSOR_MAX == 0)
                estado = DESLIGADA;
            break;

        case ERRO:
            BOMBA = 1;
            FALHA = 0;
            // negacao da condicao acima
            if ((SENSOR_MAX != 0) || (SENSOR_MIN == 0))
                estado = DESLIGADA;
            break;
        }
    }
}
