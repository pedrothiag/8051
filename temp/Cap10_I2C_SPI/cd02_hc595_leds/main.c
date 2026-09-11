/* main.c
 * Oito LEDs comandados por tres pinos com o 74HC595
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 10 - Comunicacao I2C e SPI
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c spi.c
 */

#include <8052.h>

// A funcao spi_transfer esta no Codigo anterior.
#define SPI_SS   P1_4  // ligado a RCLK do 74HC595
#define SPI_SCK  P1_5  // ligado a SRCLK
#define SPI_MOSI P1_6  // ligado a SER

extern unsigned char spi_transfer(unsigned char d);

void delay_ms(unsigned int ms)
{
    volatile unsigned int i, j;

    for (i = 0; i < ms; i++)
        for (j = 0; j < 114; j++);
}

// Desloca um byte e o transfere para as saidas.
void hc595_escreve(unsigned char valor)
{
    SPI_SS = 0;           // RCLK baixo durante o envio
    spi_transfer(valor);  // oito pulsos em SRCLK
    SPI_SS = 1;           // a subida atualiza QA..QH
}

void main(void)
{
    unsigned char padrao = 0x01;

    SPI_SS = 1;   // RCLK em repouso
    SPI_SCK = 0;  // repouso do modo 0

    while (1) {
        hc595_escreve(padrao);
        delay_ms(120);

        padrao <<= 1;
        if (padrao == 0)
            padrao = 0x01;
    }
}
