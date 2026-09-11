/* main.c
 * Estacao de monitoramento com escalonador cooperativo
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 13 - Introducao a Multitarefa Cooperativa
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c tique.c
 */

#include <8052.h>
#include <stdio.h>

#define LED    P1_6
#define BOTAO  P3_2

volatile unsigned int  ticks     = 0;
volatile unsigned char tique_novo = 0;

volatile unsigned char evento_botao = 0;
volatile unsigned char temperatura  = 0;

// - fila de transmissao da serial
char  linha[20];
unsigned char tx_i = 0, tx_n = 0;

// -------------- tarefa do LED --------------
void tarefa_led(void)
{
    LED = !LED;
}

// -------------- tarefa do conversor --------
void tarefa_adc(void)
{
    static unsigned char estado = 0;

    if (estado == 0) {
        adc_iniciar();       // dispara a conversao
        estado = 1;
    } else if (adc_pronto()) {
        temperatura = adc_ler() >> 1;  // 0,5 C/degrau
        estado = 0;
    }
}

// -------------- tarefa do LCD --------------
void tarefa_lcd(void)
{
    lcd_cursor(1, 0);
    lcd_numero(temperatura);
}

// -------------- tarefa da serial -----------
void tarefa_serial(void)
{
    if (tx_i < tx_n) {       // um caractere por vez
        SBUF = linha[tx_i++];
        while (!TI);         // menos de 1,1 ms a 9600
        TI = 0;
    }
}

// -------------- tarefa do relatorio --------
void tarefa_relatorio(void)
{
    if (tx_i >= tx_n) {      // fila vazia
        sprintf(linha, "T=%u C\r\n", temperatura);
        tx_n = strlen(linha);
        tx_i = 0;
    }
}

void main(void)
{
    unsigned char i;

    lcd_iniciar();
    uart_iniciar();
    tique_iniciar();

    while (1) {
        if (!tique_novo)
            continue;
        tique_novo = 0;

        for (i = 0; i < N_TAREFAS; i++) {
            if (--tabela[i].conta == 0) {
                tabela[i].conta = tabela[i].periodo;
                tabela[i].funcao();
            }
        }

        watchdog_alimentar();
    }
}
