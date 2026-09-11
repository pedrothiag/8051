/* main.c
 * Temporizador em modo 2: base de 250 us
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 4 - Temporizadores
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

#define LED P1_0

void timer_setup(void) {
    TR0 = 0;       // Mantem o Timer 0 parado
    TMOD &= 0xF0;  // Limpa a configuracao do Timer 0
    TMOD |= 0x02;  // Timer 0 no Modo 2
    TH0 = 0x06;    // Recarga: 256 - 250 = 6
    // Valor inicial da primeira contagem
    TL0 = 0x06;
    TF0 = 0;       // Limpa o flag de estouro
}

void timer_250us(void) {
    while (TF0 == 0);
    TF0 = 0;  // Limpa o flag para o proximo estouro
}

void delay_ms(unsigned int ms) {
    // Para o Timer antes de iniciar o atraso
    TR0 = 0;
    TL0 = 0x06;  // Reinicia a primeira contagem
    TF0 = 0;     // Limpa um possivel flag anterior
    TR0 = 1;     // Inicia o Timer 0
    while (ms-- > 0) {
        timer_250us();
        timer_250us();
        timer_250us();
        timer_250us();
    }
}

void main(void) {
    LED = 1;
    timer_setup();
    while (1) {
        LED = !LED;     // Inverte o estado do LED
        delay_ms(500);  // Aproximadamente 500 ms
    }
}
