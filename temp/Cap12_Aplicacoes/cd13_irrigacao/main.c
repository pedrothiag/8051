/* main.c
 * Irrigador automatico com sensor de umidade do solo
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 12 - Aplicacoes com Microcontroladores 8051
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

// Modulo com saida digital: 0 indica solo umido
// e 1 indica solo seco (limiar ajustado no
// trimpot do proprio modulo).
#define SENSOR P3_2
// Nivel 1 satura o transistor e liga a bomba.
#define BOMBA  P1_0

#define CONFIRMA   10   // amostras iguais: 0,5 s
#define TEMPO_MAX  120  // limite de irrigacao, em s
#define ESPERA     600  // pausa apos irrigar, em s

typedef enum {
    MONITORANDO,
    IRRIGANDO,
    ESPERANDO
} estado_t;

volatile __bit novo_tick;
volatile unsigned char decimos;
volatile unsigned int segundos;

void timer0_isr(void) __interrupt(1)
{
    TH0 = 0x4C;  // recarrega para 50 ms
    TL0 = 0x00;

    novo_tick = 1;

    if (++decimos >= 20) {
        decimos = 0;
        segundos++;
    }
}

// A copia de 16 bits precisa ser atomica.
unsigned int le_segundos(void)
{
    unsigned int copia;

    EA = 0;
    copia = segundos;
    EA = 1;
    return copia;
}

void zera_tempo(void)
{
    EA = 0;
    segundos = 0;
    EA = 1;
}

// Aceita um novo valor do sensor apenas apos
// CONFIRMA amostras consecutivas iguais.
unsigned char solo_seco(void)
{
    static unsigned char iguais = 0;
    static unsigned char estavel = 0;

    if (SENSOR == estavel) {
        iguais = 0;
    } else if (++iguais >= CONFIRMA) {
        iguais = 0;
        estavel = SENSOR;
    }
    return estavel;
}

void main(void)
{
    estado_t estado = MONITORANDO;

    SENSOR = 1;  // escreve 1 para usar como entrada
    BOMBA = 0;   // bomba desligada na partida

    TMOD = (TMOD & 0xF0) | 0x01;
    TH0 = 0x4C;
    TL0 = 0x00;
    ET0 = 1;
    TR0 = 1;
    EA = 1;

    while (1) {
        if (!novo_tick)
            continue;
        novo_tick = 0;

        switch (estado) {
        case MONITORANDO:
            BOMBA = 0;
            if (solo_seco()) {
                zera_tempo();
                estado = IRRIGANDO;
            }
            break;

        case IRRIGANDO:
            BOMBA = 1;
            if (!solo_seco() ||
                le_segundos() >= TEMPO_MAX) {
                zera_tempo();
                estado = ESPERANDO;
            }
            break;

        case ESPERANDO:
            BOMBA = 0;
            if (le_segundos() >= ESPERA)
                estado = MONITORANDO;
            break;
        }
    }
}
