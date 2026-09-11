                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler
                                      3 ; Version 4.6.0 #16555 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _delay_ms
                                     13 	.globl _timer2_setup
                                     14 	.globl _TF2
                                     15 	.globl _EXF2
                                     16 	.globl _RCLK
                                     17 	.globl _TCLK
                                     18 	.globl _EXEN2
                                     19 	.globl _TR2
                                     20 	.globl _C_T2
                                     21 	.globl _CP_RL2
                                     22 	.globl _T2CON_7
                                     23 	.globl _T2CON_6
                                     24 	.globl _T2CON_5
                                     25 	.globl _T2CON_4
                                     26 	.globl _T2CON_3
                                     27 	.globl _T2CON_2
                                     28 	.globl _T2CON_1
                                     29 	.globl _T2CON_0
                                     30 	.globl _PT2
                                     31 	.globl _ET2
                                     32 	.globl _CY
                                     33 	.globl _AC
                                     34 	.globl _F0
                                     35 	.globl _RS1
                                     36 	.globl _RS0
                                     37 	.globl _OV
                                     38 	.globl _F1
                                     39 	.globl _P
                                     40 	.globl _PS
                                     41 	.globl _PT1
                                     42 	.globl _PX1
                                     43 	.globl _PT0
                                     44 	.globl _PX0
                                     45 	.globl _RD
                                     46 	.globl _WR
                                     47 	.globl _T1
                                     48 	.globl _T0
                                     49 	.globl _INT1
                                     50 	.globl _INT0
                                     51 	.globl _TXD
                                     52 	.globl _RXD
                                     53 	.globl _P3_7
                                     54 	.globl _P3_6
                                     55 	.globl _P3_5
                                     56 	.globl _P3_4
                                     57 	.globl _P3_3
                                     58 	.globl _P3_2
                                     59 	.globl _P3_1
                                     60 	.globl _P3_0
                                     61 	.globl _EA
                                     62 	.globl _ES
                                     63 	.globl _ET1
                                     64 	.globl _EX1
                                     65 	.globl _ET0
                                     66 	.globl _EX0
                                     67 	.globl _P2_7
                                     68 	.globl _P2_6
                                     69 	.globl _P2_5
                                     70 	.globl _P2_4
                                     71 	.globl _P2_3
                                     72 	.globl _P2_2
                                     73 	.globl _P2_1
                                     74 	.globl _P2_0
                                     75 	.globl _SM0
                                     76 	.globl _SM1
                                     77 	.globl _SM2
                                     78 	.globl _REN
                                     79 	.globl _TB8
                                     80 	.globl _RB8
                                     81 	.globl _TI
                                     82 	.globl _RI
                                     83 	.globl _P1_7
                                     84 	.globl _P1_6
                                     85 	.globl _P1_5
                                     86 	.globl _P1_4
                                     87 	.globl _P1_3
                                     88 	.globl _P1_2
                                     89 	.globl _P1_1
                                     90 	.globl _P1_0
                                     91 	.globl _TF1
                                     92 	.globl _TR1
                                     93 	.globl _TF0
                                     94 	.globl _TR0
                                     95 	.globl _IE1
                                     96 	.globl _IT1
                                     97 	.globl _IE0
                                     98 	.globl _IT0
                                     99 	.globl _P0_7
                                    100 	.globl _P0_6
                                    101 	.globl _P0_5
                                    102 	.globl _P0_4
                                    103 	.globl _P0_3
                                    104 	.globl _P0_2
                                    105 	.globl _P0_1
                                    106 	.globl _P0_0
                                    107 	.globl _TH2
                                    108 	.globl _TL2
                                    109 	.globl _RCAP2H
                                    110 	.globl _RCAP2L
                                    111 	.globl _T2CON
                                    112 	.globl _B
                                    113 	.globl _ACC
                                    114 	.globl _PSW
                                    115 	.globl _IP
                                    116 	.globl _P3
                                    117 	.globl _IE
                                    118 	.globl _P2
                                    119 	.globl _SBUF
                                    120 	.globl _SCON
                                    121 	.globl _P1
                                    122 	.globl _TH1
                                    123 	.globl _TH0
                                    124 	.globl _TL1
                                    125 	.globl _TL0
                                    126 	.globl _TMOD
                                    127 	.globl _TCON
                                    128 	.globl _PCON
                                    129 	.globl _DPH
                                    130 	.globl _DPL
                                    131 	.globl _SP
                                    132 	.globl _P0
                                    133 ;--------------------------------------------------------
                                    134 ; special function registers
                                    135 ;--------------------------------------------------------
                                    136 	.area RSEG    (ABS,DATA)
      000000                        137 	.org 0x0000
                           000080   138 _P0	=	0x0080
                           000081   139 _SP	=	0x0081
                           000082   140 _DPL	=	0x0082
                           000083   141 _DPH	=	0x0083
                           000087   142 _PCON	=	0x0087
                           000088   143 _TCON	=	0x0088
                           000089   144 _TMOD	=	0x0089
                           00008A   145 _TL0	=	0x008a
                           00008B   146 _TL1	=	0x008b
                           00008C   147 _TH0	=	0x008c
                           00008D   148 _TH1	=	0x008d
                           000090   149 _P1	=	0x0090
                           000098   150 _SCON	=	0x0098
                           000099   151 _SBUF	=	0x0099
                           0000A0   152 _P2	=	0x00a0
                           0000A8   153 _IE	=	0x00a8
                           0000B0   154 _P3	=	0x00b0
                           0000B8   155 _IP	=	0x00b8
                           0000D0   156 _PSW	=	0x00d0
                           0000E0   157 _ACC	=	0x00e0
                           0000F0   158 _B	=	0x00f0
                           0000C8   159 _T2CON	=	0x00c8
                           0000CA   160 _RCAP2L	=	0x00ca
                           0000CB   161 _RCAP2H	=	0x00cb
                           0000CC   162 _TL2	=	0x00cc
                           0000CD   163 _TH2	=	0x00cd
                                    164 ;--------------------------------------------------------
                                    165 ; special function bits
                                    166 ;--------------------------------------------------------
                                    167 	.area RSEG    (ABS,DATA)
      000000                        168 	.org 0x0000
                           000080   169 _P0_0	=	0x0080
                           000081   170 _P0_1	=	0x0081
                           000082   171 _P0_2	=	0x0082
                           000083   172 _P0_3	=	0x0083
                           000084   173 _P0_4	=	0x0084
                           000085   174 _P0_5	=	0x0085
                           000086   175 _P0_6	=	0x0086
                           000087   176 _P0_7	=	0x0087
                           000088   177 _IT0	=	0x0088
                           000089   178 _IE0	=	0x0089
                           00008A   179 _IT1	=	0x008a
                           00008B   180 _IE1	=	0x008b
                           00008C   181 _TR0	=	0x008c
                           00008D   182 _TF0	=	0x008d
                           00008E   183 _TR1	=	0x008e
                           00008F   184 _TF1	=	0x008f
                           000090   185 _P1_0	=	0x0090
                           000091   186 _P1_1	=	0x0091
                           000092   187 _P1_2	=	0x0092
                           000093   188 _P1_3	=	0x0093
                           000094   189 _P1_4	=	0x0094
                           000095   190 _P1_5	=	0x0095
                           000096   191 _P1_6	=	0x0096
                           000097   192 _P1_7	=	0x0097
                           000098   193 _RI	=	0x0098
                           000099   194 _TI	=	0x0099
                           00009A   195 _RB8	=	0x009a
                           00009B   196 _TB8	=	0x009b
                           00009C   197 _REN	=	0x009c
                           00009D   198 _SM2	=	0x009d
                           00009E   199 _SM1	=	0x009e
                           00009F   200 _SM0	=	0x009f
                           0000A0   201 _P2_0	=	0x00a0
                           0000A1   202 _P2_1	=	0x00a1
                           0000A2   203 _P2_2	=	0x00a2
                           0000A3   204 _P2_3	=	0x00a3
                           0000A4   205 _P2_4	=	0x00a4
                           0000A5   206 _P2_5	=	0x00a5
                           0000A6   207 _P2_6	=	0x00a6
                           0000A7   208 _P2_7	=	0x00a7
                           0000A8   209 _EX0	=	0x00a8
                           0000A9   210 _ET0	=	0x00a9
                           0000AA   211 _EX1	=	0x00aa
                           0000AB   212 _ET1	=	0x00ab
                           0000AC   213 _ES	=	0x00ac
                           0000AF   214 _EA	=	0x00af
                           0000B0   215 _P3_0	=	0x00b0
                           0000B1   216 _P3_1	=	0x00b1
                           0000B2   217 _P3_2	=	0x00b2
                           0000B3   218 _P3_3	=	0x00b3
                           0000B4   219 _P3_4	=	0x00b4
                           0000B5   220 _P3_5	=	0x00b5
                           0000B6   221 _P3_6	=	0x00b6
                           0000B7   222 _P3_7	=	0x00b7
                           0000B0   223 _RXD	=	0x00b0
                           0000B1   224 _TXD	=	0x00b1
                           0000B2   225 _INT0	=	0x00b2
                           0000B3   226 _INT1	=	0x00b3
                           0000B4   227 _T0	=	0x00b4
                           0000B5   228 _T1	=	0x00b5
                           0000B6   229 _WR	=	0x00b6
                           0000B7   230 _RD	=	0x00b7
                           0000B8   231 _PX0	=	0x00b8
                           0000B9   232 _PT0	=	0x00b9
                           0000BA   233 _PX1	=	0x00ba
                           0000BB   234 _PT1	=	0x00bb
                           0000BC   235 _PS	=	0x00bc
                           0000D0   236 _P	=	0x00d0
                           0000D1   237 _F1	=	0x00d1
                           0000D2   238 _OV	=	0x00d2
                           0000D3   239 _RS0	=	0x00d3
                           0000D4   240 _RS1	=	0x00d4
                           0000D5   241 _F0	=	0x00d5
                           0000D6   242 _AC	=	0x00d6
                           0000D7   243 _CY	=	0x00d7
                           0000AD   244 _ET2	=	0x00ad
                           0000BD   245 _PT2	=	0x00bd
                           0000C8   246 _T2CON_0	=	0x00c8
                           0000C9   247 _T2CON_1	=	0x00c9
                           0000CA   248 _T2CON_2	=	0x00ca
                           0000CB   249 _T2CON_3	=	0x00cb
                           0000CC   250 _T2CON_4	=	0x00cc
                           0000CD   251 _T2CON_5	=	0x00cd
                           0000CE   252 _T2CON_6	=	0x00ce
                           0000CF   253 _T2CON_7	=	0x00cf
                           0000C8   254 _CP_RL2	=	0x00c8
                           0000C9   255 _C_T2	=	0x00c9
                           0000CA   256 _TR2	=	0x00ca
                           0000CB   257 _EXEN2	=	0x00cb
                           0000CC   258 _TCLK	=	0x00cc
                           0000CD   259 _RCLK	=	0x00cd
                           0000CE   260 _EXF2	=	0x00ce
                           0000CF   261 _TF2	=	0x00cf
                                    262 ;--------------------------------------------------------
                                    263 ; overlayable register banks
                                    264 ;--------------------------------------------------------
                                    265 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        266 	.ds 8
                                    267 ;--------------------------------------------------------
                                    268 ; internal ram data
                                    269 ;--------------------------------------------------------
                                    270 	.area DSEG    (DATA)
                                    271 ;--------------------------------------------------------
                                    272 ; overlayable items in internal ram
                                    273 ;--------------------------------------------------------
                                    274 	.area	OSEG    (OVR,DATA)
                                    275 ;--------------------------------------------------------
                                    276 ; Stack segment in internal ram
                                    277 ;--------------------------------------------------------
                                    278 	.area SSEG
      000008                        279 __start__stack:
      000008                        280 	.ds	1
                                    281 
                                    282 ;--------------------------------------------------------
                                    283 ; indirectly addressable internal ram data
                                    284 ;--------------------------------------------------------
                                    285 	.area ISEG    (DATA)
                                    286 ;--------------------------------------------------------
                                    287 ; absolute internal ram data
                                    288 ;--------------------------------------------------------
                                    289 	.area IABS    (ABS,DATA)
                                    290 	.area IABS    (ABS,DATA)
                                    291 ;--------------------------------------------------------
                                    292 ; bit data
                                    293 ;--------------------------------------------------------
                                    294 	.area BSEG    (BIT)
                                    295 ;--------------------------------------------------------
                                    296 ; paged external ram data
                                    297 ;--------------------------------------------------------
                                    298 	.area PSEG    (PAG,XDATA)
                                    299 ;--------------------------------------------------------
                                    300 ; uninitialized external ram data
                                    301 ;--------------------------------------------------------
                                    302 	.area XSEG    (XDATA)
                                    303 ;--------------------------------------------------------
                                    304 ; absolute external ram data
                                    305 ;--------------------------------------------------------
                                    306 	.area XABS    (ABS,XDATA)
                                    307 ;--------------------------------------------------------
                                    308 ; initialized external ram data
                                    309 ;--------------------------------------------------------
                                    310 	.area XISEG   (XDATA)
                                    311 	.area HOME    (CODE)
                                    312 	.area GSINIT0 (CODE)
                                    313 	.area GSINIT1 (CODE)
                                    314 	.area GSINIT2 (CODE)
                                    315 	.area GSINIT3 (CODE)
                                    316 	.area GSINIT4 (CODE)
                                    317 	.area GSINIT5 (CODE)
                                    318 	.area GSINIT  (CODE)
                                    319 	.area GSFINAL (CODE)
                                    320 	.area CSEG    (CODE)
                                    321 ;--------------------------------------------------------
                                    322 ; interrupt vector
                                    323 ;--------------------------------------------------------
                                    324 	.area HOME    (CODE)
      000000                        325 __interrupt_vect:
      000000 02 00 4E         [24]  326 	ljmp	__sdcc_gsinit_startup
                                    327 ; restartable atomic support routines
      000003                        328 	.ds	5
      000008                        329 sdcc_atomic_exchange_rollback_start::
      000008 00               [12]  330 	nop
      000009 00               [12]  331 	nop
      00000A                        332 sdcc_atomic_exchange_pdata_impl:
      00000A E2               [24]  333 	movx	a, @r0
      00000B FB               [12]  334 	mov	r3, a
      00000C EA               [12]  335 	mov	a, r2
      00000D F2               [24]  336 	movx	@r0, a
      00000E 80 2C            [24]  337 	sjmp	sdcc_atomic_exchange_exit
      000010 00               [12]  338 	nop
      000011 00               [12]  339 	nop
      000012                        340 sdcc_atomic_exchange_xdata_impl:
      000012 E0               [24]  341 	movx	a, @dptr
      000013 FB               [12]  342 	mov	r3, a
      000014 EA               [12]  343 	mov	a, r2
      000015 F0               [24]  344 	movx	@dptr, a
      000016 80 24            [24]  345 	sjmp	sdcc_atomic_exchange_exit
      000018                        346 sdcc_atomic_compare_exchange_idata_impl:
      000018 E6               [12]  347 	mov	a, @r0
      000019 B5 02 02         [24]  348 	cjne	a, ar2, .+#5
      00001C EB               [12]  349 	mov	a, r3
      00001D F6               [12]  350 	mov	@r0, a
      00001E 22               [24]  351 	ret
      00001F 00               [12]  352 	nop
      000020                        353 sdcc_atomic_compare_exchange_pdata_impl:
      000020 E2               [24]  354 	movx	a, @r0
      000021 B5 02 02         [24]  355 	cjne	a, ar2, .+#5
      000024 EB               [12]  356 	mov	a, r3
      000025 F2               [24]  357 	movx	@r0, a
      000026 22               [24]  358 	ret
      000027 00               [12]  359 	nop
      000028                        360 sdcc_atomic_compare_exchange_xdata_impl:
      000028 E0               [24]  361 	movx	a, @dptr
      000029 B5 02 02         [24]  362 	cjne	a, ar2, .+#5
      00002C EB               [12]  363 	mov	a, r3
      00002D F0               [24]  364 	movx	@dptr, a
      00002E 22               [24]  365 	ret
      00002F                        366 sdcc_atomic_exchange_rollback_end::
                                    367 
      00002F                        368 sdcc_atomic_exchange_gptr_impl::
      00002F 30 F6 E0         [24]  369 	jnb	b.6, sdcc_atomic_exchange_xdata_impl
      000032 A8 82            [24]  370 	mov	r0, dpl
      000034 20 F5 D3         [24]  371 	jb	b.5, sdcc_atomic_exchange_pdata_impl
      000037                        372 sdcc_atomic_exchange_idata_impl:
      000037 EA               [12]  373 	mov	a, r2
      000038 C6               [12]  374 	xch	a, @r0
      000039 F5 82            [12]  375 	mov	dpl, a
      00003B 22               [24]  376 	ret
      00003C                        377 sdcc_atomic_exchange_exit:
      00003C 8B 82            [24]  378 	mov	dpl, r3
      00003E 22               [24]  379 	ret
      00003F                        380 sdcc_atomic_compare_exchange_gptr_impl::
      00003F 30 F6 E6         [24]  381 	jnb	b.6, sdcc_atomic_compare_exchange_xdata_impl
      000042 A8 82            [24]  382 	mov	r0, dpl
      000044 20 F5 D9         [24]  383 	jb	b.5, sdcc_atomic_compare_exchange_pdata_impl
      000047 80 CF            [24]  384 	sjmp	sdcc_atomic_compare_exchange_idata_impl
                                    385 ;--------------------------------------------------------
                                    386 ; global & static initialisations
                                    387 ;--------------------------------------------------------
                                    388 	.area HOME    (CODE)
                                    389 	.area GSINIT  (CODE)
                                    390 	.area GSFINAL (CODE)
                                    391 	.area GSINIT  (CODE)
                                    392 	.globl __sdcc_gsinit_startup
                                    393 	.globl __sdcc_program_startup
                                    394 	.globl __start__stack
                                    395 	.globl __mcs51_genXINIT
                                    396 	.globl __mcs51_genXRAMCLEAR
                                    397 	.globl __mcs51_genRAMCLEAR
                                    398 	.area GSFINAL (CODE)
      0000A7 02 00 49         [24]  399 	ljmp	__sdcc_program_startup
                                    400 ;--------------------------------------------------------
                                    401 ; Home
                                    402 ;--------------------------------------------------------
                                    403 	.area HOME    (CODE)
                                    404 	.area HOME    (CODE)
      000049                        405 __sdcc_program_startup:
      000049 12 00 DB         [24]  406 	lcall	_main
      00004C                        407 __sdcc_program_exit:
      00004C 80 FE            [24]  408 	sjmp	.
                                    409 ;	return from main will return to caller
                                    410 ;--------------------------------------------------------
                                    411 ; code
                                    412 ;--------------------------------------------------------
                                    413 	.area CSEG    (CODE)
                                    414 ;------------------------------------------------------------
                                    415 ;Allocation info for local variables in function 'timer2_setup'
                                    416 ;------------------------------------------------------------
                                    417 ;	main.c:5: void timer2_setup(void) {
                                    418 ;	-----------------------------------------
                                    419 ;	 function timer2_setup
                                    420 ;	-----------------------------------------
      0000AA                        421 _timer2_setup:
                           000007   422 	ar7 = 0x07
                           000006   423 	ar6 = 0x06
                           000005   424 	ar5 = 0x05
                           000004   425 	ar4 = 0x04
                           000003   426 	ar3 = 0x03
                           000002   427 	ar2 = 0x02
                           000001   428 	ar1 = 0x01
                           000000   429 	ar0 = 0x00
                                    430 ;	main.c:6: T2CON = 0x00;   // Temporizador, recarga automatica
      0000AA 75 C8 00         [24]  431 	mov	_T2CON,#0x00
                                    432 ;	main.c:7: RCAP2H = 0xFC;  // Valor de recarga (byte alto)
      0000AD 75 CB FC         [24]  433 	mov	_RCAP2H,#0xfc
                                    434 ;	main.c:8: RCAP2L = 0x18;  // Valor de recarga (byte baixo)
      0000B0 75 CA 18         [24]  435 	mov	_RCAP2L,#0x18
                                    436 ;	main.c:10: TH2 = 0xFC;     // Valor inicial igual ao da recarga
      0000B3 75 CD FC         [24]  437 	mov	_TH2,#0xfc
                                    438 ;	main.c:11: TL2 = 0x18;
      0000B6 75 CC 18         [24]  439 	mov	_TL2,#0x18
                                    440 ;	main.c:13: TF2 = 0;        // Limpa TF2
                                    441 ;	assignBit
      0000B9 C2 CF            [12]  442 	clr	_TF2
                                    443 ;	main.c:14: TR2 = 0;        // Deixa o temporizador 2 parado
                                    444 ;	assignBit
      0000BB C2 CA            [12]  445 	clr	_TR2
                                    446 ;	main.c:15: }
      0000BD 22               [24]  447 	ret
                                    448 ;------------------------------------------------------------
                                    449 ;Allocation info for local variables in function 'delay_ms'
                                    450 ;------------------------------------------------------------
                                    451 ;n             Allocated to registers r6 r7 
                                    452 ;------------------------------------------------------------
                                    453 ;	main.c:17: void delay_ms(unsigned int n) {
                                    454 ;	-----------------------------------------
                                    455 ;	 function delay_ms
                                    456 ;	-----------------------------------------
      0000BE                        457 _delay_ms:
      0000BE AE 82            [24]  458 	mov	r6, dpl
      0000C0 AF 83            [24]  459 	mov	r7, dph
                                    460 ;	main.c:18: TF2 = 0;        // Descarta um estouro anterior
                                    461 ;	assignBit
      0000C2 C2 CF            [12]  462 	clr	_TF2
                                    463 ;	main.c:19: TR2 = 1;        // Inicia a contagem
                                    464 ;	assignBit
      0000C4 D2 CA            [12]  465 	setb	_TR2
                                    466 ;	main.c:20: while (n--) {
      0000C6                        467 00104$:
      0000C6 8E 04            [24]  468 	mov	ar4,r6
      0000C8 8F 05            [24]  469 	mov	ar5,r7
      0000CA 1E               [12]  470 	dec	r6
      0000CB BE FF 01         [24]  471 	cjne	r6,#0xff,00131$
      0000CE 1F               [12]  472 	dec	r7
      0000CF                        473 00131$:
      0000CF EC               [12]  474 	mov	a,r4
      0000D0 4D               [12]  475 	orl	a,r5
      0000D1 60 05            [24]  476 	jz	00106$
                                    477 ;	main.c:21: while (TF2 == 0);   // Aguarda o estouro (1 ms)
      0000D3                        478 00101$:
                                    479 ;	main.c:22: TF2 = 0;            // TF2 nao e limpa pelo hardware
                                    480 ;	assignBit
      0000D3 10 CF F0         [24]  481 	jbc	_TF2,00104$
      0000D6 80 FB            [24]  482 	sjmp	00101$
      0000D8                        483 00106$:
                                    484 ;	main.c:24: TR2 = 0; // Para o temporizador 2
                                    485 ;	assignBit
      0000D8 C2 CA            [12]  486 	clr	_TR2
                                    487 ;	main.c:25: }
      0000DA 22               [24]  488 	ret
                                    489 ;------------------------------------------------------------
                                    490 ;Allocation info for local variables in function 'main'
                                    491 ;------------------------------------------------------------
                                    492 ;	main.c:27: void main(void) {
                                    493 ;	-----------------------------------------
                                    494 ;	 function main
                                    495 ;	-----------------------------------------
      0000DB                        496 _main:
                                    497 ;	main.c:28: timer2_setup();
      0000DB 12 00 AA         [24]  498 	lcall	_timer2_setup
                                    499 ;	main.c:29: while (1) {
      0000DE                        500 00102$:
                                    501 ;	main.c:30: LED = !LED; // Inverte o estado do LED
      0000DE B2 90            [12]  502 	cpl	_P1_0
                                    503 ;	main.c:31: delay_ms(300); // Aproximadamente 500 ms
      0000E0 90 01 2C         [24]  504 	mov	dptr,#0x012c
      0000E3 12 00 BE         [24]  505 	lcall	_delay_ms
                                    506 ;	main.c:33: }
      0000E6 80 F6            [24]  507 	sjmp	00102$
                                    508 	.area CSEG    (CODE)
                                    509 	.area CONST   (CODE)
                                    510 	.area XINIT   (CODE)
                                    511 	.area CABS    (ABS,CODE)
