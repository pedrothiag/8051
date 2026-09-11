/* main.c
 * Escrevendo mensagens no display LCD
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c lcd.c
 */

void main(void)
{
    lcd_init();

    lcd_gotoxy(0, 0);  // coluna 0, linha 0
    lcd_string("UFERSA - 8051");

    lcd_gotoxy(2, 1);  // coluna 2, linha 1
    lcd_string("LCD 16x2 OK!");

    while (1) {
        // texto permanece na tela
    }
}
