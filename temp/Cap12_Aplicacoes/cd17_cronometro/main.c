/* main.c
 * Cronometro digital completo com LCD e serial
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c lcd.c
 */

#include <8052.h>
#include <stdio.h>

// - rotinas de LCD apresentadas acima; inclua a
// implementacao     delas neste projeto. -
extern void lcd_init(void);
extern void lcd_gotoxy(unsigned char, unsigned char);
extern void lcd_data(unsigned char);
extern void lcd_string(const char *);

#define LED_VIDA P1_0

volatile unsigned char segundos = 0, minutos = 0;
volatile unsigned char ticks = 0;
// 1 = contando, 0 = pausado
volatile __bit rodando = 1;
// sinaliza ao main que passou 1 s
volatile __bit novo_seg = 0;
volatile unsigned char bloqueia_int0 = 0;
volatile unsigned char bloqueia_int1 = 0;

int putchar(int c)
{
    while (!TI);
    TI = 0;
    SBUF = c;

    return c;
}

void uart_init(void)
{
    TR1 = 0;
    PCON &= 0x7F;  // SMOD = 0
    // modo 1, recepcao habilitada
    SCON = 0x50;
    // temporizador 1 no modo 2
    TMOD = (TMOD & 0x0F) | 0x20;
    TH1 = 0xFD;    // 9600 bps com 11,0592 MHz
    TL1 = 0xFD;
    TF1 = 0;
    TR1 = 1;
    TI  = 1;
}

void mostra_tempo(unsigned char min, unsigned char seg)
{
    lcd_gotoxy(4,1);
    lcd_data('0' + min/10);
    lcd_data('0' + min%10);
    lcd_data(':');
    lcd_data('0' + seg/10);
    lcd_data('0' + seg%10);
}

void main(void)
{
    // Timer 0: base de tempo por interrupcao (nao
    // apaga a config do Timer 1)
    TMOD = (TMOD & 0xF0) | 0x01;
    TH0 = 0x4C;  // 50 ms @ 11,0592 MHz
    TL0 = 0x00;
    ET0 = 1;
    TR0 = 1;

    IT0 = 1;  // INT0 por borda: pausa e retoma
    EX0 = 1;
    IT1 = 1;  // INT1 por borda: zera
    EX1 = 1;

    uart_init();

    lcd_init();
    lcd_gotoxy(0,0);
    lcd_string("Cronometro:");
    mostra_tempo(0, 0);
    EA = 1;  // liga todas as interrupcoes

    while (1) {
        if (novo_seg) {  // atualiza fora da ISR
            unsigned char min, seg;
            EA = 0;  // obtem uma copia coerente
            novo_seg = 0;
            min = minutos;
            seg = segundos;
            EA = 1;
            mostra_tempo(min, seg);
            printf("%02u:%02u\r\n",
                   (unsigned)min, (unsigned)seg);
        }
    }
}

// dispara a cada ~50 ms
void timer0_isr(void) __interrupt(1)
{
    TH0 = 0x4C;  // recarrega
    TL0 = 0x00;

    if (bloqueia_int0) bloqueia_int0--;
    if (bloqueia_int1) bloqueia_int1--;
    if (!rodando) return;  // pausado: nao conta
    if (++ticks >= 20) {   // 20 x 50 ms = 1 s
        ticks = 0;
        LED_VIDA = !LED_VIDA;  // pisca o LED de vida
        if (++segundos >= 60) {
            segundos = 0;
            if (++minutos >= 60) minutos = 0;
        }
        novo_seg = 1;  // avisa o main
    }
}

// botao pausa/retoma
void int0_isr(void) __interrupt(0)
{
    if (!bloqueia_int0) {
        // bloqueia por pelo menos 50 ms
        bloqueia_int0 = 2;
        rodando = !rodando;
    }
}

void int1_isr(void) __interrupt(2)  // botao zera
{
    if (!bloqueia_int1) {
        // bloqueia por pelo menos 50 ms
        bloqueia_int1 = 2;
        segundos = 0;
        minutos = 0;
        ticks = 0;
        novo_seg = 1;
    }
}
