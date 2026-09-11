/* main.c
 * Deteccao de sobrecarga e alimentacao do watchdog
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 13 - Introducao a Multitarefa Cooperativa
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

__sfr __at (0xA6) WDTRST;

volatile unsigned char tique_novo   = 0;
volatile unsigned char sobrecarga   = 0;

void tique_isr(void) __interrupt(5)
{
    TF2 = 0;
    ticks++;

    if (tique_novo)          // o laco nao consumiu
        sobrecarga = 1;      // o tique anterior
    tique_novo = 1;
}

void watchdog_alimentar(void)
{
    WDTRST = 0x1E;           // sequencia obrigatoria
    WDTRST = 0xE1;
}

void main(void)
{
    unsigned char i;

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
