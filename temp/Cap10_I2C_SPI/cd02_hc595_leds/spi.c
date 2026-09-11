/* spi.c
 * Modulo de apoio reproduzido do livro
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 10 - Comunicacao I2C e SPI
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c spi.c
 */

#include <8052.h>

#define SPI_SS   P1_4  // escravo, ativo em zero
#define SPI_SCK  P1_5  // clock, gerado pelo mestre
#define SPI_MOSI P1_6  // saida de dados do mestre
#define SPI_MISO P1_7  // entrada de dados do mestre

// Troca um byte com o escravo: envia 'dado' e devolve
// o que recebeu. Modo 0: SCK em repouso em zero,
// amostragem na borda de subida.
unsigned char spi_transfer(unsigned char dado)
{
    unsigned char i;
    unsigned char recebido = 0;

    for (i = 0; i < 8; i++) {
        // apresenta o bit
        SPI_MOSI = (dado & 0x80) ? 1 : 0;
        dado <<= 1;

        SPI_SCK = 1;  // borda de subida: amostra
        recebido <<= 1;
        if (SPI_MISO)
            recebido |= 0x01;

        SPI_SCK = 0;  // borda de descida: desloca
    }

    return recebido;
}
