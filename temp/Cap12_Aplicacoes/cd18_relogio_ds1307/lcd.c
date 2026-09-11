/* lcd.c
 * Modulo de apoio reproduzido do livro
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c lcd.c i2c.c ds1307.c
 */

#include <8052.h>

// -- Ligacoes
#define LCD_RS P2_2  // Register Select
#define LCD_EN P2_3  // Enable
// dados D4  (bit menos significativo do nibble)
#define LCD_D4 P2_4
#define LCD_D5 P2_5  // dados D5
#define LCD_D6 P2_6  // dados D6
// dados D7  (bit mais significativo do nibble)
#define LCD_D7 P2_7
// Observacao: o pino R/W do LCD deve ser ligado ao GND
// (modo somente-escrita).

void delay_ms(unsigned int ms) {
    volatile unsigned int i, j;
    for(i=0;i<ms;i++)
        for(j=0;j<120;j++);
}
// Gera o pulso de validacao no pino E
void lcd_pulso(void)
{
    LCD_EN = 1;
    delay_ms(1);
    LCD_EN = 0;
    delay_ms(1);
}
// Envia um nibble (4 bits) acionando cada linha de
// dados individualmente. D4 recebe o bit 0 do nibble;
// D5 o bit 1; D6 o bit 2; D7 o bit 3.
void lcd_nibble(unsigned char nib)
{
    LCD_D4 = (nib >> 0) & 0x01;
    LCD_D5 = (nib >> 1) & 0x01;
    LCD_D6 = (nib >> 2) & 0x01;
    LCD_D7 = (nib >> 3) & 0x01;
    lcd_pulso();
}
// Envia um COMANDO (RS = 0)
void lcd_cmd(unsigned char c)
{
    LCD_RS = 0;
    lcd_nibble(c >> 4);    // nibble alto primeiro
    lcd_nibble(c & 0x0F);  // depois o nibble baixo
    delay_ms(2);
}
// Envia um DADO/caractere (RS = 1)
void lcd_data(unsigned char d)
{
    LCD_RS = 1;
    lcd_nibble(d >> 4);
    lcd_nibble(d & 0x0F);
    delay_ms(2);
}
// Inicializacao obrigatoria do HD44780 em 4 bits
void lcd_init(void)
{
    LCD_EN = 0;
    LCD_RS = 0;
    delay_ms(20);  // aguarda a alimentacao estabilizar
    // sequencia de despertar, repetida tres vezes
    lcd_nibble(0x03);
    delay_ms(5);
    lcd_nibble(0x03);
    delay_ms(1);
    lcd_nibble(0x03);
    delay_ms(1);
    // finalmente entra em modo 4 bits
    lcd_nibble(0x02);
    lcd_cmd(0x28);  // 4 bits, 2 linhas, 5x8
    // display ligado, cursor invisivel
    lcd_cmd(0x0C);
    lcd_cmd(0x06);  // cursor avanca para a direita
    // limpa o display (lcd_cmd ja espera ~2 ms)
    lcd_cmd(0x01);
}
// Escreve uma string terminada em '\0'
void lcd_string(const char *s)
{
    while (*s)
        lcd_data(*s++);
}
// Posiciona o cursor: coluna 0..15, linha 0 ou 1
void lcd_gotoxy(unsigned char col, unsigned char lin)
{
    unsigned char base = (lin == 0) ? 0x80 : 0xC0;
    lcd_cmd(base + col);
}
