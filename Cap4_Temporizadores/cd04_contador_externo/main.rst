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
                                     12 	.globl _TF2
                                     13 	.globl _EXF2
                                     14 	.globl _RCLK
                                     15 	.globl _TCLK
                                     16 	.globl _EXEN2
                                     17 	.globl _TR2
                                     18 	.globl _C_T2
                                     19 	.globl _CP_RL2
                                     20 	.globl _T2CON_7
                                     21 	.globl _T2CON_6
                                     22 	.globl _T2CON_5
                                     23 	.globl _T2CON_4
                                     24 	.globl _T2CON_3
                                     25 	.globl _T2CON_2
                                     26 	.globl _T2CON_1
                                     27 	.globl _T2CON_0
                                     28 	.globl _PT2
                                     29 	.globl _ET2
                                     30 	.globl _CY
                                     31 	.globl _AC
                                     32 	.globl _F0
                                     33 	.globl _RS1
                                     34 	.globl _RS0
                                     35 	.globl _OV
                                     36 	.globl _F1
                                     37 	.globl _P
                                     38 	.globl _PS
                                     39 	.globl _PT1
                                     40 	.globl _PX1
                                     41 	.globl _PT0
                                     42 	.globl _PX0
                                     43 	.globl _RD
                                     44 	.globl _WR
                                     45 	.globl _T1
                                     46 	.globl _T0
                                     47 	.globl _INT1
                                     48 	.globl _INT0
                                     49 	.globl _TXD
                                     50 	.globl _RXD
                                     51 	.globl _P3_7
                                     52 	.globl _P3_6
                                     53 	.globl _P3_5
                                     54 	.globl _P3_4
                                     55 	.globl _P3_3
                                     56 	.globl _P3_2
                                     57 	.globl _P3_1
                                     58 	.globl _P3_0
                                     59 	.globl _EA
                                     60 	.globl _ES
                                     61 	.globl _ET1
                                     62 	.globl _EX1
                                     63 	.globl _ET0
                                     64 	.globl _EX0
                                     65 	.globl _P2_7
                                     66 	.globl _P2_6
                                     67 	.globl _P2_5
                                     68 	.globl _P2_4
                                     69 	.globl _P2_3
                                     70 	.globl _P2_2
                                     71 	.globl _P2_1
                                     72 	.globl _P2_0
                                     73 	.globl _SM0
                                     74 	.globl _SM1
                                     75 	.globl _SM2
                                     76 	.globl _REN
                                     77 	.globl _TB8
                                     78 	.globl _RB8
                                     79 	.globl _TI
                                     80 	.globl _RI
                                     81 	.globl _P1_7
                                     82 	.globl _P1_6
                                     83 	.globl _P1_5
                                     84 	.globl _P1_4
                                     85 	.globl _P1_3
                                     86 	.globl _P1_2
                                     87 	.globl _P1_1
                                     88 	.globl _P1_0
                                     89 	.globl _TF1
                                     90 	.globl _TR1
                                     91 	.globl _TF0
                                     92 	.globl _TR0
                                     93 	.globl _IE1
                                     94 	.globl _IT1
                                     95 	.globl _IE0
                                     96 	.globl _IT0
                                     97 	.globl _P0_7
                                     98 	.globl _P0_6
                                     99 	.globl _P0_5
                                    100 	.globl _P0_4
                                    101 	.globl _P0_3
                                    102 	.globl _P0_2
                                    103 	.globl _P0_1
                                    104 	.globl _P0_0
                                    105 	.globl _TH2
                                    106 	.globl _TL2
                                    107 	.globl _RCAP2H
                                    108 	.globl _RCAP2L
                                    109 	.globl _T2CON
                                    110 	.globl _B
                                    111 	.globl _ACC
                                    112 	.globl _PSW
                                    113 	.globl _IP
                                    114 	.globl _P3
                                    115 	.globl _IE
                                    116 	.globl _P2
                                    117 	.globl _SBUF
                                    118 	.globl _SCON
                                    119 	.globl _P1
                                    120 	.globl _TH1
                                    121 	.globl _TH0
                                    122 	.globl _TL1
                                    123 	.globl _TL0
                                    124 	.globl _TMOD
                                    125 	.globl _TCON
                                    126 	.globl _PCON
                                    127 	.globl _DPH
                                    128 	.globl _DPL
                                    129 	.globl _SP
                                    130 	.globl _P0
                                    131 ;--------------------------------------------------------
                                    132 ; special function registers
                                    133 ;--------------------------------------------------------
                                    134 	.area RSEG    (ABS,DATA)
      000000                        135 	.org 0x0000
                           000080   136 _P0	=	0x0080
                           000081   137 _SP	=	0x0081
                           000082   138 _DPL	=	0x0082
                           000083   139 _DPH	=	0x0083
                           000087   140 _PCON	=	0x0087
                           000088   141 _TCON	=	0x0088
                           000089   142 _TMOD	=	0x0089
                           00008A   143 _TL0	=	0x008a
                           00008B   144 _TL1	=	0x008b
                           00008C   145 _TH0	=	0x008c
                           00008D   146 _TH1	=	0x008d
                           000090   147 _P1	=	0x0090
                           000098   148 _SCON	=	0x0098
                           000099   149 _SBUF	=	0x0099
                           0000A0   150 _P2	=	0x00a0
                           0000A8   151 _IE	=	0x00a8
                           0000B0   152 _P3	=	0x00b0
                           0000B8   153 _IP	=	0x00b8
                           0000D0   154 _PSW	=	0x00d0
                           0000E0   155 _ACC	=	0x00e0
                           0000F0   156 _B	=	0x00f0
                           0000C8   157 _T2CON	=	0x00c8
                           0000CA   158 _RCAP2L	=	0x00ca
                           0000CB   159 _RCAP2H	=	0x00cb
                           0000CC   160 _TL2	=	0x00cc
                           0000CD   161 _TH2	=	0x00cd
                                    162 ;--------------------------------------------------------
                                    163 ; special function bits
                                    164 ;--------------------------------------------------------
                                    165 	.area RSEG    (ABS,DATA)
      000000                        166 	.org 0x0000
                           000080   167 _P0_0	=	0x0080
                           000081   168 _P0_1	=	0x0081
                           000082   169 _P0_2	=	0x0082
                           000083   170 _P0_3	=	0x0083
                           000084   171 _P0_4	=	0x0084
                           000085   172 _P0_5	=	0x0085
                           000086   173 _P0_6	=	0x0086
                           000087   174 _P0_7	=	0x0087
                           000088   175 _IT0	=	0x0088
                           000089   176 _IE0	=	0x0089
                           00008A   177 _IT1	=	0x008a
                           00008B   178 _IE1	=	0x008b
                           00008C   179 _TR0	=	0x008c
                           00008D   180 _TF0	=	0x008d
                           00008E   181 _TR1	=	0x008e
                           00008F   182 _TF1	=	0x008f
                           000090   183 _P1_0	=	0x0090
                           000091   184 _P1_1	=	0x0091
                           000092   185 _P1_2	=	0x0092
                           000093   186 _P1_3	=	0x0093
                           000094   187 _P1_4	=	0x0094
                           000095   188 _P1_5	=	0x0095
                           000096   189 _P1_6	=	0x0096
                           000097   190 _P1_7	=	0x0097
                           000098   191 _RI	=	0x0098
                           000099   192 _TI	=	0x0099
                           00009A   193 _RB8	=	0x009a
                           00009B   194 _TB8	=	0x009b
                           00009C   195 _REN	=	0x009c
                           00009D   196 _SM2	=	0x009d
                           00009E   197 _SM1	=	0x009e
                           00009F   198 _SM0	=	0x009f
                           0000A0   199 _P2_0	=	0x00a0
                           0000A1   200 _P2_1	=	0x00a1
                           0000A2   201 _P2_2	=	0x00a2
                           0000A3   202 _P2_3	=	0x00a3
                           0000A4   203 _P2_4	=	0x00a4
                           0000A5   204 _P2_5	=	0x00a5
                           0000A6   205 _P2_6	=	0x00a6
                           0000A7   206 _P2_7	=	0x00a7
                           0000A8   207 _EX0	=	0x00a8
                           0000A9   208 _ET0	=	0x00a9
                           0000AA   209 _EX1	=	0x00aa
                           0000AB   210 _ET1	=	0x00ab
                           0000AC   211 _ES	=	0x00ac
                           0000AF   212 _EA	=	0x00af
                           0000B0   213 _P3_0	=	0x00b0
                           0000B1   214 _P3_1	=	0x00b1
                           0000B2   215 _P3_2	=	0x00b2
                           0000B3   216 _P3_3	=	0x00b3
                           0000B4   217 _P3_4	=	0x00b4
                           0000B5   218 _P3_5	=	0x00b5
                           0000B6   219 _P3_6	=	0x00b6
                           0000B7   220 _P3_7	=	0x00b7
                           0000B0   221 _RXD	=	0x00b0
                           0000B1   222 _TXD	=	0x00b1
                           0000B2   223 _INT0	=	0x00b2
                           0000B3   224 _INT1	=	0x00b3
                           0000B4   225 _T0	=	0x00b4
                           0000B5   226 _T1	=	0x00b5
                           0000B6   227 _WR	=	0x00b6
                           0000B7   228 _RD	=	0x00b7
                           0000B8   229 _PX0	=	0x00b8
                           0000B9   230 _PT0	=	0x00b9
                           0000BA   231 _PX1	=	0x00ba
                           0000BB   232 _PT1	=	0x00bb
                           0000BC   233 _PS	=	0x00bc
                           0000D0   234 _P	=	0x00d0
                           0000D1   235 _F1	=	0x00d1
                           0000D2   236 _OV	=	0x00d2
                           0000D3   237 _RS0	=	0x00d3
                           0000D4   238 _RS1	=	0x00d4
                           0000D5   239 _F0	=	0x00d5
                           0000D6   240 _AC	=	0x00d6
                           0000D7   241 _CY	=	0x00d7
                           0000AD   242 _ET2	=	0x00ad
                           0000BD   243 _PT2	=	0x00bd
                           0000C8   244 _T2CON_0	=	0x00c8
                           0000C9   245 _T2CON_1	=	0x00c9
                           0000CA   246 _T2CON_2	=	0x00ca
                           0000CB   247 _T2CON_3	=	0x00cb
                           0000CC   248 _T2CON_4	=	0x00cc
                           0000CD   249 _T2CON_5	=	0x00cd
                           0000CE   250 _T2CON_6	=	0x00ce
                           0000CF   251 _T2CON_7	=	0x00cf
                           0000C8   252 _CP_RL2	=	0x00c8
                           0000C9   253 _C_T2	=	0x00c9
                           0000CA   254 _TR2	=	0x00ca
                           0000CB   255 _EXEN2	=	0x00cb
                           0000CC   256 _TCLK	=	0x00cc
                           0000CD   257 _RCLK	=	0x00cd
                           0000CE   258 _EXF2	=	0x00ce
                           0000CF   259 _TF2	=	0x00cf
                                    260 ;--------------------------------------------------------
                                    261 ; overlayable register banks
                                    262 ;--------------------------------------------------------
                                    263 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        264 	.ds 8
                                    265 ;--------------------------------------------------------
                                    266 ; internal ram data
                                    267 ;--------------------------------------------------------
                                    268 	.area DSEG    (DATA)
                                    269 ;--------------------------------------------------------
                                    270 ; overlayable items in internal ram
                                    271 ;--------------------------------------------------------
                                    272 ;--------------------------------------------------------
                                    273 ; Stack segment in internal ram
                                    274 ;--------------------------------------------------------
                                    275 	.area SSEG
      000008                        276 __start__stack:
      000008                        277 	.ds	1
                                    278 
                                    279 ;--------------------------------------------------------
                                    280 ; indirectly addressable internal ram data
                                    281 ;--------------------------------------------------------
                                    282 	.area ISEG    (DATA)
                                    283 ;--------------------------------------------------------
                                    284 ; absolute internal ram data
                                    285 ;--------------------------------------------------------
                                    286 	.area IABS    (ABS,DATA)
                                    287 	.area IABS    (ABS,DATA)
                                    288 ;--------------------------------------------------------
                                    289 ; bit data
                                    290 ;--------------------------------------------------------
                                    291 	.area BSEG    (BIT)
                                    292 ;--------------------------------------------------------
                                    293 ; paged external ram data
                                    294 ;--------------------------------------------------------
                                    295 	.area PSEG    (PAG,XDATA)
                                    296 ;--------------------------------------------------------
                                    297 ; uninitialized external ram data
                                    298 ;--------------------------------------------------------
                                    299 	.area XSEG    (XDATA)
                                    300 ;--------------------------------------------------------
                                    301 ; absolute external ram data
                                    302 ;--------------------------------------------------------
                                    303 	.area XABS    (ABS,XDATA)
                                    304 ;--------------------------------------------------------
                                    305 ; initialized external ram data
                                    306 ;--------------------------------------------------------
                                    307 	.area XISEG   (XDATA)
                                    308 	.area HOME    (CODE)
                                    309 	.area GSINIT0 (CODE)
                                    310 	.area GSINIT1 (CODE)
                                    311 	.area GSINIT2 (CODE)
                                    312 	.area GSINIT3 (CODE)
                                    313 	.area GSINIT4 (CODE)
                                    314 	.area GSINIT5 (CODE)
                                    315 	.area GSINIT  (CODE)
                                    316 	.area GSFINAL (CODE)
                                    317 	.area CSEG    (CODE)
                                    318 ;--------------------------------------------------------
                                    319 ; interrupt vector
                                    320 ;--------------------------------------------------------
                                    321 	.area HOME    (CODE)
      000000                        322 __interrupt_vect:
      000000 02 00 4E         [24]  323 	ljmp	__sdcc_gsinit_startup
                                    324 ; restartable atomic support routines
      000003                        325 	.ds	5
      000008                        326 sdcc_atomic_exchange_rollback_start::
      000008 00               [12]  327 	nop
      000009 00               [12]  328 	nop
      00000A                        329 sdcc_atomic_exchange_pdata_impl:
      00000A E2               [24]  330 	movx	a, @r0
      00000B FB               [12]  331 	mov	r3, a
      00000C EA               [12]  332 	mov	a, r2
      00000D F2               [24]  333 	movx	@r0, a
      00000E 80 2C            [24]  334 	sjmp	sdcc_atomic_exchange_exit
      000010 00               [12]  335 	nop
      000011 00               [12]  336 	nop
      000012                        337 sdcc_atomic_exchange_xdata_impl:
      000012 E0               [24]  338 	movx	a, @dptr
      000013 FB               [12]  339 	mov	r3, a
      000014 EA               [12]  340 	mov	a, r2
      000015 F0               [24]  341 	movx	@dptr, a
      000016 80 24            [24]  342 	sjmp	sdcc_atomic_exchange_exit
      000018                        343 sdcc_atomic_compare_exchange_idata_impl:
      000018 E6               [12]  344 	mov	a, @r0
      000019 B5 02 02         [24]  345 	cjne	a, ar2, .+#5
      00001C EB               [12]  346 	mov	a, r3
      00001D F6               [12]  347 	mov	@r0, a
      00001E 22               [24]  348 	ret
      00001F 00               [12]  349 	nop
      000020                        350 sdcc_atomic_compare_exchange_pdata_impl:
      000020 E2               [24]  351 	movx	a, @r0
      000021 B5 02 02         [24]  352 	cjne	a, ar2, .+#5
      000024 EB               [12]  353 	mov	a, r3
      000025 F2               [24]  354 	movx	@r0, a
      000026 22               [24]  355 	ret
      000027 00               [12]  356 	nop
      000028                        357 sdcc_atomic_compare_exchange_xdata_impl:
      000028 E0               [24]  358 	movx	a, @dptr
      000029 B5 02 02         [24]  359 	cjne	a, ar2, .+#5
      00002C EB               [12]  360 	mov	a, r3
      00002D F0               [24]  361 	movx	@dptr, a
      00002E 22               [24]  362 	ret
      00002F                        363 sdcc_atomic_exchange_rollback_end::
                                    364 
      00002F                        365 sdcc_atomic_exchange_gptr_impl::
      00002F 30 F6 E0         [24]  366 	jnb	b.6, sdcc_atomic_exchange_xdata_impl
      000032 A8 82            [24]  367 	mov	r0, dpl
      000034 20 F5 D3         [24]  368 	jb	b.5, sdcc_atomic_exchange_pdata_impl
      000037                        369 sdcc_atomic_exchange_idata_impl:
      000037 EA               [12]  370 	mov	a, r2
      000038 C6               [12]  371 	xch	a, @r0
      000039 F5 82            [12]  372 	mov	dpl, a
      00003B 22               [24]  373 	ret
      00003C                        374 sdcc_atomic_exchange_exit:
      00003C 8B 82            [24]  375 	mov	dpl, r3
      00003E 22               [24]  376 	ret
      00003F                        377 sdcc_atomic_compare_exchange_gptr_impl::
      00003F 30 F6 E6         [24]  378 	jnb	b.6, sdcc_atomic_compare_exchange_xdata_impl
      000042 A8 82            [24]  379 	mov	r0, dpl
      000044 20 F5 D9         [24]  380 	jb	b.5, sdcc_atomic_compare_exchange_pdata_impl
      000047 80 CF            [24]  381 	sjmp	sdcc_atomic_compare_exchange_idata_impl
                                    382 ;--------------------------------------------------------
                                    383 ; global & static initialisations
                                    384 ;--------------------------------------------------------
                                    385 	.area HOME    (CODE)
                                    386 	.area GSINIT  (CODE)
                                    387 	.area GSFINAL (CODE)
                                    388 	.area GSINIT  (CODE)
                                    389 	.globl __sdcc_gsinit_startup
                                    390 	.globl __sdcc_program_startup
                                    391 	.globl __start__stack
                                    392 	.globl __mcs51_genXINIT
                                    393 	.globl __mcs51_genXRAMCLEAR
                                    394 	.globl __mcs51_genRAMCLEAR
                                    395 	.area GSFINAL (CODE)
      0000A7 02 00 49         [24]  396 	ljmp	__sdcc_program_startup
                                    397 ;--------------------------------------------------------
                                    398 ; Home
                                    399 ;--------------------------------------------------------
                                    400 	.area HOME    (CODE)
                                    401 	.area HOME    (CODE)
      000049                        402 __sdcc_program_startup:
      000049 12 00 AA         [24]  403 	lcall	_main
      00004C                        404 __sdcc_program_exit:
      00004C 80 FE            [24]  405 	sjmp	.
                                    406 ;	return from main will return to caller
                                    407 ;--------------------------------------------------------
                                    408 ; code
                                    409 ;--------------------------------------------------------
                                    410 	.area CSEG    (CODE)
                                    411 ;------------------------------------------------------------
                                    412 ;Allocation info for local variables in function 'main'
                                    413 ;------------------------------------------------------------
                                    414 ;	main.c:13: void main(void)
                                    415 ;	-----------------------------------------
                                    416 ;	 function main
                                    417 ;	-----------------------------------------
      0000AA                        418 _main:
                           000007   419 	ar7 = 0x07
                           000006   420 	ar6 = 0x06
                           000005   421 	ar5 = 0x05
                           000004   422 	ar4 = 0x04
                           000003   423 	ar3 = 0x03
                           000002   424 	ar2 = 0x02
                           000001   425 	ar1 = 0x01
                           000000   426 	ar0 = 0x00
                                    427 ;	main.c:16: TMOD = 0x50;
      0000AA 75 89 50         [24]  428 	mov	_TMOD,#0x50
                                    429 ;	main.c:17: TL1 = 0x00;
      0000AD 75 8B 00         [24]  430 	mov	_TL1,#0x00
                                    431 ;	main.c:18: TH1 = 0x00;
      0000B0 75 8D 00         [24]  432 	mov	_TH1,#0x00
                                    433 ;	main.c:19: TR1 = 1;  // Habilita a contagem
                                    434 ;	assignBit
      0000B3 D2 8E            [12]  435 	setb	_TR1
                                    436 ;	main.c:21: while (1) {
      0000B5                        437 00102$:
                                    438 ;	main.c:23: P0 = TL1;
      0000B5 85 8B 80         [24]  439 	mov	_P0,_TL1
                                    440 ;	main.c:25: }
      0000B8 80 FB            [24]  441 	sjmp	00102$
                                    442 	.area CSEG    (CODE)
                                    443 	.area CONST   (CODE)
                                    444 	.area XINIT   (CODE)
                                    445 	.area CABS    (ABS,CODE)
