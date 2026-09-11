/* main.c
 * Relogio com DS1307 e display LCD
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c lcd.c i2c.c ds1307.c
 */

#include <8052.h>

// driver de LCD da Secao 10.2
extern void lcd_init(void);
extern void lcd_gotoxy(unsigned char, unsigned char);
extern void lcd_data(unsigned char);
extern void lcd_string(const char *);
extern void delay_ms(unsigned int ms);

// acesso ao DS1307, apresentado nesta secao
extern unsigned char ds1307_le(unsigned char reg);
extern unsigned char bcd_para_dec(unsigned char b);

// escreve um valor de 0 a 99 com dois algarismos
void lcd_dois(unsigned char v)
{
    lcd_data('0' + v / 10);
    lcd_data('0' + v % 10);
}

void main(void)
{
    unsigned char h, m, s;
    unsigned char dia, mes, ano;

    lcd_init();
    lcd_gotoxy(0, 0);
    lcd_string("Hora ");
    lcd_gotoxy(0, 1);
    lcd_string("Data ");

    while (1) {
        // o bit 7 dos segundos e CH, e nao um digito
        s   = bcd_para_dec(ds1307_le(0x00) & 0x7F);
        m   = bcd_para_dec(ds1307_le(0x01));
        // o bit 6 das horas seleciona o formato
        h   = bcd_para_dec(ds1307_le(0x02) & 0x3F);
        dia = bcd_para_dec(ds1307_le(0x04));
        mes = bcd_para_dec(ds1307_le(0x05));
        ano = bcd_para_dec(ds1307_le(0x06));

        // primeira linha: HH:MM:SS
        lcd_gotoxy(5, 0);
        lcd_dois(h);
        lcd_data(':');
        lcd_dois(m);
        lcd_data(':');
        lcd_dois(s);

        // segunda linha: DD/MM/AA
        lcd_gotoxy(5, 1);
        lcd_dois(dia);
        lcd_data('/');
        lcd_dois(mes);
        lcd_data('/');
        lcd_dois(ano);

        delay_ms(200);
    }
}
