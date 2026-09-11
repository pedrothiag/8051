/* main.c
 * Medida de periodo com o modo de captura do temporizador 2
 *
 * Programacao de Microcontroladores 8051 em Linguagem C
 * Capitulo 4 - Temporizadores
 *
 * Compilacao: sdcc -mmcs51 --model-small --iram-size 256
 *             --xram-size 0 --code-size 8192 main.c
 */

#include <8052.h>

void main(void) {
    unsigned int captura_atual;
    unsigned int captura_anterior = 0;
    unsigned int periodo;
    unsigned char primeira_captura = 1;

    P1_1 = 1;       // Libera T2EX/P1.1 para funcionar como entrada

    T2CON = 0x09;   // EXEN2 = 1 e CP/RL2 = 1: modo de captura

    TH2 = 0x00;     // Inicia o Timer 2 em 0x0000
    TL2 = 0x00;

    TF2 = 0;        // Limpa as flags do Timer 2
    EXF2 = 0;

    TR2 = 1;        // Inicia a contagem do Timer 2

    while (1) {
        // Verifica se ocorreu uma captura em T2EX
        if (EXF2) {
            /*
             * Desabilita temporariamente novas capturas para que
             * RCAP2H e RCAP2L possam ser lidos com segurança.
             */
            EXEN2 = 0;

            // Monta o valor de 16 bits capturado
            captura_atual =
                ((unsigned int)RCAP2H << 8) | RCAP2L;

            // Limpa a flag de captura
            EXF2 = 0;

            // Habilita novamente o modo de captura
            EXEN2 = 1;

            if (primeira_captura) {
                captura_anterior = captura_atual;
                primeira_captura = 0;
            }
            else {
               periodo = captura_atual - captura_anterior;

                // Envia o byte mais significativo para P3
                P3 = (unsigned char)(periodo >> 8);

                // Envia o byte menos significativo para P2
                P2 = (unsigned char)periodo;

                /*
                 * Finaliza a medição:
                 *
                 * EXEN2 = 0 impede novas capturas por T2EX;
                 * TR2 = 0 interrompe a contagem do Timer 2.
                 */
                EXEN2 = 0;
                TR2 = 0;

                /*
                 * Mantém o programa parado e preserva o resultado
                 * apresentado nos portais P2 e P3.
                 */
                while (1);
            }
        }

        /*
         * A subtração sem sinal considera um retorno do contador,
         * mas a flag de transbordamento deve ser limpa por software.
         */
        if (TF2)
        {
            TF2 = 0;
        }
    }
}
