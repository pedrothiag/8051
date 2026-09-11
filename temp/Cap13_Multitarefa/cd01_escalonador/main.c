/* main.c
 * Escalonador cooperativo com tabela de tarefas
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 13 - Introducao a Multitarefa Cooperativa
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c tique.c
 */

#define N_TAREFAS 4

typedef struct {
    void (*funcao)(void);   // funcao da tarefa
    unsigned int periodo;   // em tiques (ms)
    unsigned int conta;     // tiques restantes
} tarefa_t;

tarefa_t tabela[N_TAREFAS] = {
    { tarefa_botao,   1,   1 },
    { tarefa_display, 2,   2 },
    { tarefa_sensor,  100, 100 },
    { tarefa_serial,  1000, 1000 }
};

void main(void)
{
    unsigned char i;
    unsigned int anterior, agora;

    tique_iniciar();
    anterior = 0;

    while (1) {
        EA = 0;
        agora = ticks;
        EA = 1;

        if (agora == anterior)
            continue;        // ainda no mesmo tique
        anterior = agora;

        for (i = 0; i < N_TAREFAS; i++) {
            if (--tabela[i].conta == 0) {
                tabela[i].conta = tabela[i].periodo;
                tabela[i].funcao();
            }
        }
    }
}
