/* main.c
 * Leitura de uma tensao com o ADC0804
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c uart.c
 */

#include <8052.h>

#define ADC_WR   P1_0  // pulso de partida (ativo em 0)
#define ADC_RD   P1_1  // habilita a saida (ativo em 0)
#define ADC_INTR P1_2  // fim de conversao (0 = pronto)

// rotinas da porta serial, do Capitulo 6
extern void uart_init(void);
extern void uart_puts(const char *s);
extern void uart_num(unsigned int valor);

void delay_ms(unsigned int ms)
{
    volatile unsigned int i, j;

    for (i = 0; i < ms; i++)
        for (j = 0; j < 114; j++);
}

unsigned char adc_le(void)
{
    unsigned char valor;

    // 1) um pulso em WR inicia a conversao
    ADC_WR = 0;
    ADC_WR = 1;

    // 2) INTR cai quando o resultado esta pronto
    while (ADC_INTR == 1)
        ;

    // 3) RD em zero apresenta o dado no barramento
    P2 = 0xFF;      // libera P2 para entrada
    ADC_RD = 0;
    valor = P2;
    ADC_RD = 1;

    return valor;
}

void main(void)
{
    unsigned char bruto;
    unsigned int mv;

    uart_init();

    // repouso das linhas de controle
    ADC_WR   = 1;
    ADC_RD   = 1;
    ADC_INTR = 1;   // libera o pino como entrada

    while (1) {
        bruto = adc_le();

        // 5000 mV / 255 = 19,6 mV por degrau
        mv = (unsigned int)bruto * 196U / 10U;

        uart_puts("valor=");
        uart_num(bruto);
        uart_puts("  tensao=");
        uart_num(mv);
        uart_puts(" mV\r\n");

        delay_ms(500);
    }
}
