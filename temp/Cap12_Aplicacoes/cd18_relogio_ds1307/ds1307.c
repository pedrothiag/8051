/* ds1307.c
 * Modulo de apoio reproduzido do livro
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c lcd.c i2c.c ds1307.c
 */

// BCD -> decimal: 0x45 (dois nibbles) vira 45.
unsigned char bcd_para_dec(unsigned char b)
{
    return (b >> 4) * 10 + (b & 0x0F);
}

// Decimal -> BCD: 45 vira 0x45.
unsigned char dec_para_bcd(unsigned char d)
{
    return ((d / 10) << 4) | (d % 10);
}

// As primitivas i2c_* estao no capitulo anterior.
extern void i2c_start(void);
extern void i2c_stop(void);
extern __bit i2c_write(unsigned char dado);
extern unsigned char i2c_read(__bit enviar_ack);

#define DS1307_WR 0xD0  // endereco 0x68 com R/W = 0
#define DS1307_RD 0xD1  // endereco 0x68 com R/W = 1

void ds1307_escreve(unsigned char reg,
                    unsigned char valor)
{
    i2c_start();
    i2c_write(DS1307_WR);  // seleciona o DS1307
    i2c_write(reg);        // aponta o registrador
    i2c_write(valor);      // grava o valor
    i2c_stop();
}

unsigned char ds1307_le(unsigned char reg)
{
    unsigned char valor;

    i2c_start();
    i2c_write(DS1307_WR);  // aponta o registrador...
    i2c_write(reg);
    i2c_start();           // ...START repetido...
    i2c_write(DS1307_RD);  // ...e muda para leitura
    // um unico byte: responde NACK
    valor = i2c_read(0);
    i2c_stop();

    return valor;
}
