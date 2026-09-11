/* main.c
 * Onda triangular gerada pela rede R-2R
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

// os oito bits vao ao 74HC245 e dali a rede R-2R
#define DAC P2

// atraso curto: define a frequencia da onda
void passo(void)
{
    volatile unsigned char k;

    for (k = 0; k < 20; k++)
        ;
}

void main(void)
{
    unsigned char n;

    DAC = 0x00;

    while (1) {
        // rampa de subida: 0 -> 255
        for (n = 0; n < 255; n++) {
            DAC = n;
            passo();
        }
        // rampa de descida: 255 -> 0
        for (n = 255; n > 0; n--) {
            DAC = n;
            passo();
        }
    }
}
