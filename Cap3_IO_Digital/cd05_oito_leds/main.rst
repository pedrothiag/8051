                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler
                                      3 ; Version 4.6.0 #16555 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _delay_ms
                                     13 	.globl _TF2
                                     14 	.globl _EXF2
                                     15 	.globl _RCLK
                                     16 	.globl _TCLK
                                     17 	.globl _EXEN2
                                     18 	.globl _TR2
                                     19 	.globl _C_T2
                                     20 	.globl _CP_RL2
                                     21 	.globl _T2CON_7
                                     22 	.globl _T2CON_6
                                     23 	.globl _T2CON_5
                                     24 	.globl _T2CON_4
                                     25 	.globl _T2CON_3
                                     26 	.globl _T2CON_2
                                     27 	.globl _T2CON_1
                                     28 	.globl _T2CON_0
                                     29 	.globl _PT2
                                     30 	.globl _ET2
                                     31 	.globl _CY
                                     32 	.globl _AC
                                     33 	.globl _F0
                                     34 	.globl _RS1
                                     35 	.globl _RS0
                                     36 	.globl _OV
                                     37 	.globl _F1
                                     38 	.globl _P
                                     39 	.globl _PS
                                     40 	.globl _PT1
                                     41 	.globl _PX1
                                     42 	.globl _PT0
                                     43 	.globl _PX0
                                     44 	.globl _RD
                                     45 	.globl _WR
                                     46 	.globl _T1
                                     47 	.globl _T0
                                     48 	.globl _INT1
                                     49 	.globl _INT0
                                     50 	.globl _TXD
                                     51 	.globl _RXD
                                     52 	.globl _P3_7
                                     53 	.globl _P3_6
                                     54 	.globl _P3_5
                                     55 	.globl _P3_4
                                     56 	.globl _P3_3
                                     57 	.globl _P3_2
                                     58 	.globl _P3_1
                                     59 	.globl _P3_0
                                     60 	.globl _EA
                                     61 	.globl _ES
                                     62 	.globl _ET1
                                     63 	.globl _EX1
                                     64 	.globl _ET0
                                     65 	.globl _EX0
                                     66 	.globl _P2_7
                                     67 	.globl _P2_6
                                     68 	.globl _P2_5
                                     69 	.globl _P2_4
                                     70 	.globl _P2_3
                                     71 	.globl _P2_2
                                     72 	.globl _P2_1
                                     73 	.globl _P2_0
                                     74 	.globl _SM0
                                     75 	.globl _SM1
                                     76 	.globl _SM2
                                     77 	.globl _REN
                                     78 	.globl _TB8
                                     79 	.globl _RB8
                                     80 	.globl _TI
                                     81 	.globl _RI
                                     82 	.globl _P1_7
                                     83 	.globl _P1_6
                                     84 	.globl _P1_5
                                     85 	.globl _P1_4
                                     86 	.globl _P1_3
                                     87 	.globl _P1_2
                                     88 	.globl _P1_1
                                     89 	.globl _P1_0
                                     90 	.globl _TF1
                                     91 	.globl _TR1
                                     92 	.globl _TF0
                                     93 	.globl _TR0
                                     94 	.globl _IE1
                                     95 	.globl _IT1
                                     96 	.globl _IE0
                                     97 	.globl _IT0
                                     98 	.globl _P0_7
                                     99 	.globl _P0_6
                                    100 	.globl _P0_5
                                    101 	.globl _P0_4
                                    102 	.globl _P0_3
                                    103 	.globl _P0_2
                                    104 	.globl _P0_1
                                    105 	.globl _P0_0
                                    106 	.globl _TH2
                                    107 	.globl _TL2
                                    108 	.globl _RCAP2H
                                    109 	.globl _RCAP2L
                                    110 	.globl _T2CON
                                    111 	.globl _B
                                    112 	.globl _ACC
                                    113 	.globl _PSW
                                    114 	.globl _IP
                                    115 	.globl _P3
                                    116 	.globl _IE
                                    117 	.globl _P2
                                    118 	.globl _SBUF
                                    119 	.globl _SCON
                                    120 	.globl _P1
                                    121 	.globl _TH1
                                    122 	.globl _TH0
                                    123 	.globl _TL1
                                    124 	.globl _TL0
                                    125 	.globl _TMOD
                                    126 	.globl _TCON
                                    127 	.globl _PCON
                                    128 	.globl _DPH
                                    129 	.globl _DPL
                                    130 	.globl _SP
                                    131 	.globl _P0
                                    132 ;--------------------------------------------------------
                                    133 ; special function registers
                                    134 ;--------------------------------------------------------
                                    135 	.area RSEG    (ABS,DATA)
      000000                        136 	.org 0x0000
                           000080   137 _P0	=	0x0080
                           000081   138 _SP	=	0x0081
                           000082   139 _DPL	=	0x0082
                           000083   140 _DPH	=	0x0083
                           000087   141 _PCON	=	0x0087
                           000088   142 _TCON	=	0x0088
                           000089   143 _TMOD	=	0x0089
                           00008A   144 _TL0	=	0x008a
                           00008B   145 _TL1	=	0x008b
                           00008C   146 _TH0	=	0x008c
                           00008D   147 _TH1	=	0x008d
                           000090   148 _P1	=	0x0090
                           000098   149 _SCON	=	0x0098
                           000099   150 _SBUF	=	0x0099
                           0000A0   151 _P2	=	0x00a0
                           0000A8   152 _IE	=	0x00a8
                           0000B0   153 _P3	=	0x00b0
                           0000B8   154 _IP	=	0x00b8
                           0000D0   155 _PSW	=	0x00d0
                           0000E0   156 _ACC	=	0x00e0
                           0000F0   157 _B	=	0x00f0
                           0000C8   158 _T2CON	=	0x00c8
                           0000CA   159 _RCAP2L	=	0x00ca
                           0000CB   160 _RCAP2H	=	0x00cb
                           0000CC   161 _TL2	=	0x00cc
                           0000CD   162 _TH2	=	0x00cd
                                    163 ;--------------------------------------------------------
                                    164 ; special function bits
                                    165 ;--------------------------------------------------------
                                    166 	.area RSEG    (ABS,DATA)
      000000                        167 	.org 0x0000
                           000080   168 _P0_0	=	0x0080
                           000081   169 _P0_1	=	0x0081
                           000082   170 _P0_2	=	0x0082
                           000083   171 _P0_3	=	0x0083
                           000084   172 _P0_4	=	0x0084
                           000085   173 _P0_5	=	0x0085
                           000086   174 _P0_6	=	0x0086
                           000087   175 _P0_7	=	0x0087
                           000088   176 _IT0	=	0x0088
                           000089   177 _IE0	=	0x0089
                           00008A   178 _IT1	=	0x008a
                           00008B   179 _IE1	=	0x008b
                           00008C   180 _TR0	=	0x008c
                           00008D   181 _TF0	=	0x008d
                           00008E   182 _TR1	=	0x008e
                           00008F   183 _TF1	=	0x008f
                           000090   184 _P1_0	=	0x0090
                           000091   185 _P1_1	=	0x0091
                           000092   186 _P1_2	=	0x0092
                           000093   187 _P1_3	=	0x0093
                           000094   188 _P1_4	=	0x0094
                           000095   189 _P1_5	=	0x0095
                           000096   190 _P1_6	=	0x0096
                           000097   191 _P1_7	=	0x0097
                           000098   192 _RI	=	0x0098
                           000099   193 _TI	=	0x0099
                           00009A   194 _RB8	=	0x009a
                           00009B   195 _TB8	=	0x009b
                           00009C   196 _REN	=	0x009c
                           00009D   197 _SM2	=	0x009d
                           00009E   198 _SM1	=	0x009e
                           00009F   199 _SM0	=	0x009f
                           0000A0   200 _P2_0	=	0x00a0
                           0000A1   201 _P2_1	=	0x00a1
                           0000A2   202 _P2_2	=	0x00a2
                           0000A3   203 _P2_3	=	0x00a3
                           0000A4   204 _P2_4	=	0x00a4
                           0000A5   205 _P2_5	=	0x00a5
                           0000A6   206 _P2_6	=	0x00a6
                           0000A7   207 _P2_7	=	0x00a7
                           0000A8   208 _EX0	=	0x00a8
                           0000A9   209 _ET0	=	0x00a9
                           0000AA   210 _EX1	=	0x00aa
                           0000AB   211 _ET1	=	0x00ab
                           0000AC   212 _ES	=	0x00ac
                           0000AF   213 _EA	=	0x00af
                           0000B0   214 _P3_0	=	0x00b0
                           0000B1   215 _P3_1	=	0x00b1
                           0000B2   216 _P3_2	=	0x00b2
                           0000B3   217 _P3_3	=	0x00b3
                           0000B4   218 _P3_4	=	0x00b4
                           0000B5   219 _P3_5	=	0x00b5
                           0000B6   220 _P3_6	=	0x00b6
                           0000B7   221 _P3_7	=	0x00b7
                           0000B0   222 _RXD	=	0x00b0
                           0000B1   223 _TXD	=	0x00b1
                           0000B2   224 _INT0	=	0x00b2
                           0000B3   225 _INT1	=	0x00b3
                           0000B4   226 _T0	=	0x00b4
                           0000B5   227 _T1	=	0x00b5
                           0000B6   228 _WR	=	0x00b6
                           0000B7   229 _RD	=	0x00b7
                           0000B8   230 _PX0	=	0x00b8
                           0000B9   231 _PT0	=	0x00b9
                           0000BA   232 _PX1	=	0x00ba
                           0000BB   233 _PT1	=	0x00bb
                           0000BC   234 _PS	=	0x00bc
                           0000D0   235 _P	=	0x00d0
                           0000D1   236 _F1	=	0x00d1
                           0000D2   237 _OV	=	0x00d2
                           0000D3   238 _RS0	=	0x00d3
                           0000D4   239 _RS1	=	0x00d4
                           0000D5   240 _F0	=	0x00d5
                           0000D6   241 _AC	=	0x00d6
                           0000D7   242 _CY	=	0x00d7
                           0000AD   243 _ET2	=	0x00ad
                           0000BD   244 _PT2	=	0x00bd
                           0000C8   245 _T2CON_0	=	0x00c8
                           0000C9   246 _T2CON_1	=	0x00c9
                           0000CA   247 _T2CON_2	=	0x00ca
                           0000CB   248 _T2CON_3	=	0x00cb
                           0000CC   249 _T2CON_4	=	0x00cc
                           0000CD   250 _T2CON_5	=	0x00cd
                           0000CE   251 _T2CON_6	=	0x00ce
                           0000CF   252 _T2CON_7	=	0x00cf
                           0000C8   253 _CP_RL2	=	0x00c8
                           0000C9   254 _C_T2	=	0x00c9
                           0000CA   255 _TR2	=	0x00ca
                           0000CB   256 _EXEN2	=	0x00cb
                           0000CC   257 _TCLK	=	0x00cc
                           0000CD   258 _RCLK	=	0x00cd
                           0000CE   259 _EXF2	=	0x00ce
                           0000CF   260 _TF2	=	0x00cf
                                    261 ;--------------------------------------------------------
                                    262 ; overlayable register banks
                                    263 ;--------------------------------------------------------
                                    264 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        265 	.ds 8
                                    266 ;--------------------------------------------------------
                                    267 ; internal ram data
                                    268 ;--------------------------------------------------------
                                    269 	.area DSEG    (DATA)
                                    270 ;--------------------------------------------------------
                                    271 ; overlayable items in internal ram
                                    272 ;--------------------------------------------------------
                                    273 	.area	OSEG    (OVR,DATA)
      000008                        274 _delay_ms_i_10000_2:
      000008                        275 	.ds 2
      00000A                        276 _delay_ms_j_10000_2:
      00000A                        277 	.ds 2
                                    278 ;--------------------------------------------------------
                                    279 ; Stack segment in internal ram
                                    280 ;--------------------------------------------------------
                                    281 	.area SSEG
      00000C                        282 __start__stack:
      00000C                        283 	.ds	1
                                    284 
                                    285 ;--------------------------------------------------------
                                    286 ; indirectly addressable internal ram data
                                    287 ;--------------------------------------------------------
                                    288 	.area ISEG    (DATA)
                                    289 ;--------------------------------------------------------
                                    290 ; absolute internal ram data
                                    291 ;--------------------------------------------------------
                                    292 	.area IABS    (ABS,DATA)
                                    293 	.area IABS    (ABS,DATA)
                                    294 ;--------------------------------------------------------
                                    295 ; bit data
                                    296 ;--------------------------------------------------------
                                    297 	.area BSEG    (BIT)
                                    298 ;--------------------------------------------------------
                                    299 ; paged external ram data
                                    300 ;--------------------------------------------------------
                                    301 	.area PSEG    (PAG,XDATA)
                                    302 ;--------------------------------------------------------
                                    303 ; uninitialized external ram data
                                    304 ;--------------------------------------------------------
                                    305 	.area XSEG    (XDATA)
                                    306 ;--------------------------------------------------------
                                    307 ; absolute external ram data
                                    308 ;--------------------------------------------------------
                                    309 	.area XABS    (ABS,XDATA)
                                    310 ;--------------------------------------------------------
                                    311 ; initialized external ram data
                                    312 ;--------------------------------------------------------
                                    313 	.area XISEG   (XDATA)
                                    314 	.area HOME    (CODE)
                                    315 	.area GSINIT0 (CODE)
                                    316 	.area GSINIT1 (CODE)
                                    317 	.area GSINIT2 (CODE)
                                    318 	.area GSINIT3 (CODE)
                                    319 	.area GSINIT4 (CODE)
                                    320 	.area GSINIT5 (CODE)
                                    321 	.area GSINIT  (CODE)
                                    322 	.area GSFINAL (CODE)
                                    323 	.area CSEG    (CODE)
                                    324 ;--------------------------------------------------------
                                    325 ; interrupt vector
                                    326 ;--------------------------------------------------------
                                    327 	.area HOME    (CODE)
      000000                        328 __interrupt_vect:
      000000 02 00 4E         [24]  329 	ljmp	__sdcc_gsinit_startup
                                    330 ; restartable atomic support routines
      000003                        331 	.ds	5
      000008                        332 sdcc_atomic_exchange_rollback_start::
      000008 00               [12]  333 	nop
      000009 00               [12]  334 	nop
      00000A                        335 sdcc_atomic_exchange_pdata_impl:
      00000A E2               [24]  336 	movx	a, @r0
      00000B FB               [12]  337 	mov	r3, a
      00000C EA               [12]  338 	mov	a, r2
      00000D F2               [24]  339 	movx	@r0, a
      00000E 80 2C            [24]  340 	sjmp	sdcc_atomic_exchange_exit
      000010 00               [12]  341 	nop
      000011 00               [12]  342 	nop
      000012                        343 sdcc_atomic_exchange_xdata_impl:
      000012 E0               [24]  344 	movx	a, @dptr
      000013 FB               [12]  345 	mov	r3, a
      000014 EA               [12]  346 	mov	a, r2
      000015 F0               [24]  347 	movx	@dptr, a
      000016 80 24            [24]  348 	sjmp	sdcc_atomic_exchange_exit
      000018                        349 sdcc_atomic_compare_exchange_idata_impl:
      000018 E6               [12]  350 	mov	a, @r0
      000019 B5 02 02         [24]  351 	cjne	a, ar2, .+#5
      00001C EB               [12]  352 	mov	a, r3
      00001D F6               [12]  353 	mov	@r0, a
      00001E 22               [24]  354 	ret
      00001F 00               [12]  355 	nop
      000020                        356 sdcc_atomic_compare_exchange_pdata_impl:
      000020 E2               [24]  357 	movx	a, @r0
      000021 B5 02 02         [24]  358 	cjne	a, ar2, .+#5
      000024 EB               [12]  359 	mov	a, r3
      000025 F2               [24]  360 	movx	@r0, a
      000026 22               [24]  361 	ret
      000027 00               [12]  362 	nop
      000028                        363 sdcc_atomic_compare_exchange_xdata_impl:
      000028 E0               [24]  364 	movx	a, @dptr
      000029 B5 02 02         [24]  365 	cjne	a, ar2, .+#5
      00002C EB               [12]  366 	mov	a, r3
      00002D F0               [24]  367 	movx	@dptr, a
      00002E 22               [24]  368 	ret
      00002F                        369 sdcc_atomic_exchange_rollback_end::
                                    370 
      00002F                        371 sdcc_atomic_exchange_gptr_impl::
      00002F 30 F6 E0         [24]  372 	jnb	b.6, sdcc_atomic_exchange_xdata_impl
      000032 A8 82            [24]  373 	mov	r0, dpl
      000034 20 F5 D3         [24]  374 	jb	b.5, sdcc_atomic_exchange_pdata_impl
      000037                        375 sdcc_atomic_exchange_idata_impl:
      000037 EA               [12]  376 	mov	a, r2
      000038 C6               [12]  377 	xch	a, @r0
      000039 F5 82            [12]  378 	mov	dpl, a
      00003B 22               [24]  379 	ret
      00003C                        380 sdcc_atomic_exchange_exit:
      00003C 8B 82            [24]  381 	mov	dpl, r3
      00003E 22               [24]  382 	ret
      00003F                        383 sdcc_atomic_compare_exchange_gptr_impl::
      00003F 30 F6 E6         [24]  384 	jnb	b.6, sdcc_atomic_compare_exchange_xdata_impl
      000042 A8 82            [24]  385 	mov	r0, dpl
      000044 20 F5 D9         [24]  386 	jb	b.5, sdcc_atomic_compare_exchange_pdata_impl
      000047 80 CF            [24]  387 	sjmp	sdcc_atomic_compare_exchange_idata_impl
                                    388 ;--------------------------------------------------------
                                    389 ; global & static initialisations
                                    390 ;--------------------------------------------------------
                                    391 	.area HOME    (CODE)
                                    392 	.area GSINIT  (CODE)
                                    393 	.area GSFINAL (CODE)
                                    394 	.area GSINIT  (CODE)
                                    395 	.globl __sdcc_gsinit_startup
                                    396 	.globl __sdcc_program_startup
                                    397 	.globl __start__stack
                                    398 	.globl __mcs51_genXINIT
                                    399 	.globl __mcs51_genXRAMCLEAR
                                    400 	.globl __mcs51_genRAMCLEAR
                                    401 	.area GSFINAL (CODE)
      0000A7 02 00 49         [24]  402 	ljmp	__sdcc_program_startup
                                    403 ;--------------------------------------------------------
                                    404 ; Home
                                    405 ;--------------------------------------------------------
                                    406 	.area HOME    (CODE)
                                    407 	.area HOME    (CODE)
      000049                        408 __sdcc_program_startup:
      000049 12 00 EB         [24]  409 	lcall	_main
      00004C                        410 __sdcc_program_exit:
      00004C 80 FE            [24]  411 	sjmp	.
                                    412 ;	return from main will return to caller
                                    413 ;--------------------------------------------------------
                                    414 ; code
                                    415 ;--------------------------------------------------------
                                    416 	.area CSEG    (CODE)
                                    417 ;------------------------------------------------------------
                                    418 ;Allocation info for local variables in function 'delay_ms'
                                    419 ;------------------------------------------------------------
                                    420 ;ms            Allocated to registers r6 r7 
                                    421 ;i             Allocated with name '_delay_ms_i_10000_2'
                                    422 ;j             Allocated with name '_delay_ms_j_10000_2'
                                    423 ;------------------------------------------------------------
                                    424 ;	main.c:13: void delay_ms(unsigned int ms) { 
                                    425 ;	-----------------------------------------
                                    426 ;	 function delay_ms
                                    427 ;	-----------------------------------------
      0000AA                        428 _delay_ms:
                           000007   429 	ar7 = 0x07
                           000006   430 	ar6 = 0x06
                           000005   431 	ar5 = 0x05
                           000004   432 	ar4 = 0x04
                           000003   433 	ar3 = 0x03
                           000002   434 	ar2 = 0x02
                           000001   435 	ar1 = 0x01
                           000000   436 	ar0 = 0x00
      0000AA AE 82            [24]  437 	mov	r6, dpl
      0000AC AF 83            [24]  438 	mov	r7, dph
                                    439 ;	main.c:15: for(i=0;i<ms;i++) 
      0000AE E4               [12]  440 	clr	a
      0000AF F5 08            [12]  441 	mov	_delay_ms_i_10000_2,a
      0000B1 F5 09            [12]  442 	mov	(_delay_ms_i_10000_2 + 1),a
      0000B3                        443 00107$:
      0000B3 C3               [12]  444 	clr	c
      0000B4 E5 08            [12]  445 	mov	a,_delay_ms_i_10000_2
      0000B6 9E               [12]  446 	subb	a,r6
      0000B7 E5 09            [12]  447 	mov	a,(_delay_ms_i_10000_2 + 1)
      0000B9 9F               [12]  448 	subb	a,r7
      0000BA 50 2E            [24]  449 	jnc	00109$
                                    450 ;	main.c:16: for(j=0;j<120;j++); 
      0000BC E4               [12]  451 	clr	a
      0000BD F5 0A            [12]  452 	mov	_delay_ms_j_10000_2,a
      0000BF F5 0B            [12]  453 	mov	(_delay_ms_j_10000_2 + 1),a
      0000C1                        454 00104$:
      0000C1 C3               [12]  455 	clr	c
      0000C2 E5 0A            [12]  456 	mov	a,_delay_ms_j_10000_2
      0000C4 94 78            [12]  457 	subb	a,#0x78
      0000C6 E5 0B            [12]  458 	mov	a,(_delay_ms_j_10000_2 + 1)
      0000C8 94 00            [12]  459 	subb	a,#0x00
      0000CA 50 0F            [24]  460 	jnc	00108$
      0000CC AC 0A            [24]  461 	mov	r4,_delay_ms_j_10000_2
      0000CE AD 0B            [24]  462 	mov	r5,(_delay_ms_j_10000_2 + 1)
      0000D0 74 01            [12]  463 	mov	a,#0x01
      0000D2 2C               [12]  464 	add	a, r4
      0000D3 F5 0A            [12]  465 	mov	_delay_ms_j_10000_2,a
      0000D5 E4               [12]  466 	clr	a
      0000D6 3D               [12]  467 	addc	a, r5
      0000D7 F5 0B            [12]  468 	mov	(_delay_ms_j_10000_2 + 1),a
      0000D9 80 E6            [24]  469 	sjmp	00104$
      0000DB                        470 00108$:
                                    471 ;	main.c:15: for(i=0;i<ms;i++) 
      0000DB AC 08            [24]  472 	mov	r4,_delay_ms_i_10000_2
      0000DD AD 09            [24]  473 	mov	r5,(_delay_ms_i_10000_2 + 1)
      0000DF 74 01            [12]  474 	mov	a,#0x01
      0000E1 2C               [12]  475 	add	a, r4
      0000E2 F5 08            [12]  476 	mov	_delay_ms_i_10000_2,a
      0000E4 E4               [12]  477 	clr	a
      0000E5 3D               [12]  478 	addc	a, r5
      0000E6 F5 09            [12]  479 	mov	(_delay_ms_i_10000_2 + 1),a
      0000E8 80 C9            [24]  480 	sjmp	00107$
      0000EA                        481 00109$:
                                    482 ;	main.c:17: }
      0000EA 22               [24]  483 	ret
                                    484 ;------------------------------------------------------------
                                    485 ;Allocation info for local variables in function 'main'
                                    486 ;------------------------------------------------------------
                                    487 ;i             Allocated to registers r7 
                                    488 ;------------------------------------------------------------
                                    489 ;	main.c:19: void main(void) {
                                    490 ;	-----------------------------------------
                                    491 ;	 function main
                                    492 ;	-----------------------------------------
      0000EB                        493 _main:
                                    494 ;	main.c:24: for (i = 0; i < 8; i++) {
      0000EB                        495 00119$:
      0000EB 7F 00            [12]  496 	mov	r7,#0x00
      0000ED                        497 00106$:
                                    498 ;	main.c:26: P1 = ~(1 << i);
      0000ED 8F F0            [24]  499 	mov	b,r7
      0000EF 05 F0            [12]  500 	inc	b
      0000F1 74 01            [12]  501 	mov	a,#0x01
      0000F3 80 02            [24]  502 	sjmp	00152$
      0000F5                        503 00151$:
      0000F5 25 E0            [12]  504 	add	a,acc
      0000F7                        505 00152$:
      0000F7 D5 F0 FB         [24]  506 	djnz	b,00151$
      0000FA F4               [12]  507 	cpl	a
      0000FB F5 90            [12]  508 	mov	_P1,a
                                    509 ;	main.c:27: delay_ms(100);
      0000FD 90 00 64         [24]  510 	mov	dptr,#0x0064
      000100 C0 07            [24]  511 	push	ar7
      000102 12 00 AA         [24]  512 	lcall	_delay_ms
      000105 D0 07            [24]  513 	pop	ar7
                                    514 ;	main.c:24: for (i = 0; i < 8; i++) {
      000107 0F               [12]  515 	inc	r7
      000108 BF 08 00         [24]  516 	cjne	r7,#0x08,00153$
      00010B                        517 00153$:
      00010B 40 E0            [24]  518 	jc	00106$
                                    519 ;	main.c:30: for (i = 6; i > 0; i--) {
      00010D 7F 06            [12]  520 	mov	r7,#0x06
      00010F                        521 00108$:
                                    522 ;	main.c:31: P1 = ~(1 << i);
      00010F 8F F0            [24]  523 	mov	b,r7
      000111 05 F0            [12]  524 	inc	b
      000113 74 01            [12]  525 	mov	a,#0x01
      000115 80 02            [24]  526 	sjmp	00156$
      000117                        527 00155$:
      000117 25 E0            [12]  528 	add	a,acc
      000119                        529 00156$:
      000119 D5 F0 FB         [24]  530 	djnz	b,00155$
      00011C F4               [12]  531 	cpl	a
      00011D F5 90            [12]  532 	mov	_P1,a
                                    533 ;	main.c:32: delay_ms(100);
      00011F 90 00 64         [24]  534 	mov	dptr,#0x0064
      000122 C0 07            [24]  535 	push	ar7
      000124 12 00 AA         [24]  536 	lcall	_delay_ms
      000127 D0 07            [24]  537 	pop	ar7
                                    538 ;	main.c:30: for (i = 6; i > 0; i--) {
      000129 DF E4            [24]  539 	djnz	r7,00108$
                                    540 ;	main.c:35: }
      00012B 80 BE            [24]  541 	sjmp	00119$
                                    542 	.area CSEG    (CODE)
                                    543 	.area CONST   (CODE)
                                    544 	.area XINIT   (CODE)
                                    545 	.area CABS    (ABS,CODE)
