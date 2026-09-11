/* i2c.c
 * Modulo de apoio reproduzido do livro
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c lcd.c i2c.c ds1307.c
 */

#include <8052.h>

#define SDA P1_0  // com pull-up externo de 4,7 k
#define SCL P1_1  // com pull-up externo de 4,7 k

// Meio periodo do clock: define a velocidade.
void i2c_delay(void)
{
    volatile unsigned char i;

    for (i = 0; i < 5; i++);
}

void i2c_start(void)
{
    SDA = 1;  // parte das duas linhas liberadas
    SCL = 1;
    i2c_delay();
    SDA = 0;  // SDA desce com SCL alto -> START
    i2c_delay();
    SCL = 0;  // prepara o primeiro bit
    i2c_delay();
}

void i2c_stop(void)
{
    SDA = 0;  // zera SDA antes de subir SCL
    SCL = 1;
    i2c_delay();
    SDA = 1;  // SDA sobe com SCL alto -> STOP
    i2c_delay();
}

// Envia um byte, do bit mais significativo para o
// menos significativo. Retorna 0 se o escravo
// respondeu ACK e 1 se respondeu NACK.
__bit i2c_write(unsigned char dado)
{
    unsigned char i;
    __bit ack;

    for (i = 0; i < 8; i++) {
        // apresenta o bit com SCL em zero
        SDA = (dado & 0x80) ? 1 : 0;
        dado <<= 1;
        SCL = 1;  // o escravo amostra nesta borda
        i2c_delay();
        SCL = 0;
        i2c_delay();
    }

    SDA = 1;  // libera SDA para o escravo
    SCL = 1;  // nono pulso de clock
    i2c_delay();
    ack = SDA;  // le o bit de confirmacao (0 = ACK)
    SCL = 0;
    i2c_delay();

    return ack;
}

// Le um byte. Se 'enviar_ack' for 1, o mestre responde
// ACK, indicando que ainda quer mais dados.
unsigned char i2c_read(__bit enviar_ack)
{
    unsigned char i;
    unsigned char dado = 0;

    SDA = 1;  // libera a linha ao escravo

    for (i = 0; i < 8; i++) {
        SCL = 1;
        i2c_delay();
        dado <<= 1;
        if (SDA)
            dado |= 0x01;
        SCL = 0;
        i2c_delay();
    }

    SDA = enviar_ack ? 0 : 1;  // ACK = 0, NACK = 1
    SCL = 1;
    i2c_delay();
    SCL = 0;
    i2c_delay();
    SDA = 1;  // devolve a linha ao repouso

    return dado;
}
