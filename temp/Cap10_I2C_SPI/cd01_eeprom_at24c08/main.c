/* main.c
 * Leitura e escrita de um byte na EEPROM AT24C08
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 10 - Comunicacao I2C e SPI
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c i2c.c
 */

#include <8052.h>

// As primitivas i2c_* estao no Codigo anterior;
// inclua-as no projeto.
extern void i2c_start(void);
extern void i2c_stop(void);
extern __bit i2c_write(unsigned char dado);
extern unsigned char i2c_read(__bit enviar_ack);

// AT24C08: 1024 bytes divididos em 4 blocos de 256 B.
// Os 2 bits de bloco entram no byte de controle. Pino
// A2 ligado ao GND.
static unsigned char at24_ctrl(unsigned int endereco)
{
    return 0xA0 | (((endereco >> 8) & 0x03) << 1);
}

void at24_escreve(unsigned int endereco,
                  unsigned char dado)
{
    unsigned char ctrl = at24_ctrl(endereco);

    i2c_start();
    // controle + bloco, com R/W = 0
    i2c_write(ctrl);
    // endereco dentro do bloco
    i2c_write(endereco & 0xFF);
    i2c_write(dado);
    i2c_stop();  // inicia a gravacao

    // Polling de ACK: repete ate a EEPROM responder.
    do {
        i2c_start();
    } while (i2c_write(ctrl) != 0);
    i2c_stop();
}

unsigned char at24_le(unsigned int endereco)
{
    unsigned char ctrl = at24_ctrl(endereco);
    unsigned char dado;

    i2c_start();
    i2c_write(ctrl);  // aponta o endereco desejado...
    i2c_write(endereco & 0xFF);
    i2c_start();             // ...START repetido...
    i2c_write(ctrl | 0x01);  // ...e muda para leitura
    // um unico byte: responde NACK
    dado = i2c_read(0);
    i2c_stop();

    return dado;
}

void main(void)
{
    // grava na posicao 291
    at24_escreve(0x0123, 0x5A);
    P2 = at24_le(0x0123);  // le de volta e mostra

    while (1);
}
