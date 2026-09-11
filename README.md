# Códigos do livro

Programas em C apresentados em *Programação de Microcontroladores 8051
em Linguagem C*, organizados por capítulo. Cada pasta contém um projeto
completo, com `main.c` e, quando o programa depende de um módulo
apresentado separadamente no texto, os arquivos de apoio correspondentes.

Compilação típica, a partir da pasta do projeto:

```
sdcc -mmcs51 --model-small --iram-size 256 --xram-size 0 \
     --code-size 8192 main.c
```

Nos projetos do Capítulo 11 a opção `--xram-size` passa a 32768. Quando há
mais de um arquivo `.c`, todos entram na mesma linha de comando, com o
arquivo que contém `main` em primeiro lugar.

## Capítulo 3 — Entrada e Saída Digital

| Pasta | Programa | Arquivos |
|---|---|---|
| `cd01_led_pisca` | LED piscando a cada 500 ms | [main.c](./Cap3_IO_Digital/cd01_led_pisca/main.c) |
| `cd02_botao_led` | Leitura de um botão e acionamento de um LED | [main.c](./Cap3_IO_Digital/cd02_botao_led/main.c) |
| `cd03_debounce` | Antirrepique de um botão por *software* | [main.c](./Cap3_IO_Digital/cd03_debounce/main.c) |
| `cd04_maquina_estados` | Controle de uma bomba por máquina de estados | [main.c](./Cap3_IO_Digital/cd04_maquina_estados/main.c) |
| `cd05_oito_leds` | Oito LEDs ligados a uma porta inteira | [main.c](./Cap3_IO_Digital/cd05_oito_leds/main.c) |

## Capítulo 4 — Temporizadores

| Pasta | Programa | Arquivos |
|---|---|---|
| `cd01_timer0_modo1_1ms` | Temporizador 0 em modo 1: base de 1 ms | [main.c](./Cap4_Temporizadores/cd01_timer0_modo1_1ms/main.c) |
| `cd02_timer_modo2_250us` | Temporizador em modo 2: base de 250 µs | [main.c](./Cap4_Temporizadores/cd02_timer_modo2_250us/main.c) |
| `cd03_timer0_modo3` | Temporizador 0 em modo 3: dois contadores de 8 *bits* | [main.c](./Cap4_Temporizadores/cd03_timer0_modo3/main.c) |
| `cd04_contador_externo` | Contagem de pulsos externos no pino T1 | [main.c](./Cap4_Temporizadores/cd04_contador_externo/main.c) |
| `cd05_timer2_recarga` | Temporizador 2 com recarga automática | [main.c](./Cap4_Temporizadores/cd05_timer2_recarga/main.c) |
| `cd06_timer2_captura`*** | Medida de período com o modo de captura do temporizador 2 | [main.c](./Cap4_Temporizadores/cd06_timer2_captura/main.c) |

<!--## Capítulo 6 — Interrupções

| Pasta | Programa | Arquivos |
|---|---|---|
| `cd01_int0_led` | Botão em INT0 alternando um LED | main.c |
| `cd02_duas_externas` | Duas interrupções externas simultâneas | main.c |
| `cd03_int_timer0` | LED alternado a cada segundo pela interrupção do temporizador 0 | main.c |
| `cd04_int_timer2` | Base de tempo pela interrupção do temporizador 2 | main.c |
| `cd05_captura_por_int` | Captura do temporizador 2 atendida por interrupção | main.c |
| `cd06_integracao` | Temporizador 0, INT0 e INT1 em conjunto | main.c |

## Capítulo 7 — Comunicação Serial (UART)

| Pasta | Programa | Arquivos |
|---|---|---|
| `cd01_contador_serial` | Transmissão periódica de um contador pela serial | main.c, uart.c |
| `cd02_printf` | printf redirecionado para a UART | main.c |
| `cd03_recepcao_por_int` | Recepção serial por interrupção com *buffer* circular | main.c |
| `cd04_terminal` | Controle de um LED por comandos recebidos pela serial | main.c |

## Capítulo 8 — Modos de Baixo Consumo

| Pasta | Programa | Arquivos |
|---|---|---|
| `cd01_idle_periodico` | Tarefa periódica com *Idle* entre as execuções | main.c |
| `cd02_power_down_botao` | *Power-Down* com despertar por botão em INT0 | main.c |

## Capítulo 9 — Geração de PWM

| Pasta | Programa | Arquivos |
|---|---|---|
| `cd01_pwm_software` | PWM elementar por atraso de *software* | main.c |
| `cd02_pwm_por_int` | PWM de um canal por interrupção do temporizador 0 | main.c |
| `cd03_tres_niveis` | Três níveis de brilho selecionados por botões | main.c |
| `cd04_fade` | Efeito *fade*: LED que acende e apaga suavemente | main.c |
| `cd05_rgb` | Três canais de PWM independentes para um LED RGB | main.c |

## Capítulo 10 — Comunicação I²C e SPI

| Pasta | Programa | Arquivos |
|---|---|---|
| `cd01_eeprom_at24c08` | Leitura e escrita de um byte na EEPROM AT24C08 | main.c, i2c.c |
| `cd02_hc595_leds` | Oito LEDs comandados por três pinos com o 74HC595 | main.c, spi.c |

## Capítulo 11 — Memória Externa e E/S Mapeada em Memória

| Pasta | Programa | Arquivos |
|---|---|---|
| `cd01_xdata_basico` | Declaração de variáveis na memória externa | main.c |
| `cd02_teste_sram` | Teste da memória SRAM externa | main.c, uart.c |
| `cd03_registrador_eventos` | Registrador de eventos com memória externa e periféricos mapeados | main.c, uart.c, perifericos.h, perifericos.c |

## Capítulo 12 — Aplicações com Microcontroladores 8051

| Pasta | Programa | Arquivos |
|---|---|---|
| `cd01_7seg_contador` | Contagem de 0 a 9 em um *display* de sete segmentos | main.c |
| `cd02_7seg_mux` | Multiplexação de dois dígitos no laço principal | main.c |
| `cd03_7seg_mux_int` | Multiplexação de dois dígitos por interrupção | main.c |
| `cd04_lcd_mensagem` | Escrevendo mensagens no *display* LCD | main.c, lcd.c |
| `cd05_teclado` | Varredura de um teclado matricial 4×4 | main.c |
| `cd06_hcsr04` | Medida de distância com o HC-SR04 | main.c |
| `cd07_servo` | Controle de posição de um servomotor | main.c |
| `cd08_motor_velocidade` | Velocidade do motor ajustada por dois botões | main.c |
| `cd09_ponte_h` | Controle de velocidade e sentido com ponte H | main.c |
| `cd10_motor_passo` | Acionamento em meio passo de um motor unipolar | main.c |
| `cd11_rele_escada` | Temporizador de escada com relé e fotoacoplador | main.c |
| `cd12_esteira` | Contador de peças com parada automática da esteira | main.c |
| `cd13_irrigacao` | Irrigador automático com sensor de umidade do solo | main.c |
| `cd14_forno` | Controle de forno com dois termostatos e histerese | main.c |
| `cd15_adc0804` | Leitura de uma tensão com o ADC0804 | main.c, uart.c |
| `cd16_r2r_triangular` | Onda triangular gerada pela rede R-2R | main.c |
| `cd17_cronometro` | Cronômetro digital completo com LCD e serial | main.c, lcd.c |
| `cd18_relogio_ds1307` | Relógio com DS1307 e *display* LCD | main.c, lcd.c, i2c.c, ds1307.c |
| `cd19_dht22` | Leitura do DHT22 e envio pela porta serial | main.c, uart.c |

## Capítulo 13 — Introdução à Multitarefa Cooperativa

| Pasta | Programa | Arquivos |
|---|---|---|
| `cd01_escalonador` | Escalonador cooperativo com tabela de tarefas | main.c, tique.c |
| `cd02_sobrecarga` | Detecção de sobrecarga e alimentação do *watchdog* | main.c |
| `cd03_estacao` | Estação de monitoramento com escalonador cooperativo | main.c, tique.c |

## Anexo B — Conversão de SDCC para Keil C51

| Pasta | Programa | Arquivos |
|---|---|---|
| `cd01_versao_sdcc` | Mesmo programa na sintaxe do SDCC | main.c |
| `cd02_versao_keil` | Mesmo programa na sintaxe do Keil C51 | main.c |-->
