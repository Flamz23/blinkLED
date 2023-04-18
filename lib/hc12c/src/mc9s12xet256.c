/* Based on CPU DB MC9S12XET256_144, version 3.00.028 (RegistersPrg V2.28) */
/* DataSheet : MC9S12XEP100 Rev. 1.19 12/2008 */

#include <mc9s12xet256.h>

/*lint -save -esym(765, *) */


/* * * * *  8-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile PORTESTR _PORTE;                                  /* Port E Data Register; 0x00000008 */
volatile DDRESTR _DDRE;                                    /* Port E Data Direction Register; 0x00000009 */
volatile MMCCTL0STR _MMCCTL0;                              /* MMC Control Register; 0x0000000A */
volatile MODESTR _MODE;                                    /* Mode Register; 0x0000000B */
volatile PUCRSTR _PUCR;                                    /* Pull-Up Control Register; 0x0000000C */
volatile RDRIVSTR _RDRIV;                                  /* Reduced Drive Register; 0x0000000D */
volatile EBICTL0STR _EBICTL0;                              /* External Bus Interface Control Register 0; 0x0000000E */
volatile EBICTL1STR _EBICTL1;                              /* External Bus Interface Control Register 1; 0x0000000F */
volatile GPAGESTR _GPAGE;                                  /* Global Page Index Register; 0x00000010 */
volatile DIRECTSTR _DIRECT;                                /* Direct Page Register; 0x00000011 */
volatile MMCCTL1STR _MMCCTL1;                              /* MMC Control Register; 0x00000013 */
volatile PPAGESTR _PPAGE;                                  /* Program Page Index Register; 0x00000015 */
volatile RPAGESTR _RPAGE;                                  /* RAM Page Index Register; 0x00000016 */
volatile EPAGESTR _EPAGE;                                  /* Data FLASH Page Index Register; 0x00000017 */
volatile ECLKCTLSTR _ECLKCTL;                              /* ECLK Control Register; 0x0000001C */
volatile IRQCRSTR _IRQCR;                                  /* Interrupt Control Register; 0x0000001E */
volatile DBGC1STR _DBGC1;                                  /* Debug Control Register 1; 0x00000020 */
volatile DBGSRSTR _DBGSR;                                  /* Debug Status Register; 0x00000021 */
volatile DBGTCRSTR _DBGTCR;                                /* Debug Trace Control Register; 0x00000022 */
volatile DBGC2STR _DBGC2;                                  /* Debug Control Register 2; 0x00000023 */
volatile DBGCNTSTR _DBGCNT;                                /* Debug Count Register; 0x00000026 */
volatile DBGSCRXSTR _DBGSCRX;                              /* Debug State Control Register; 0x00000027 */
volatile DBGXCTLSTR _DBGXCTL;                              /* Debug Comparator Control Register; 0x00000028 */
volatile DBGXAHSTR _DBGXAH;                                /* Debug Comparator Address High Register; 0x00000029 */
volatile DBGXAMSTR _DBGXAM;                                /* Debug Comparator Address Mid Register; 0x0000002A */
volatile DBGXALSTR _DBGXAL;                                /* Debug Comparator Address Low Register; 0x0000002B */
volatile DBGXDHSTR _DBGXDH;                                /* Debug Comparator Data High Register; 0x0000002C */
volatile DBGXDLSTR _DBGXDL;                                /* Debug Comparator Data Low Register; 0x0000002D */
volatile DBGXDHMSTR _DBGXDHM;                              /* Debug Comparator Data High Mask Register; 0x0000002E */
volatile DBGXDLMSTR _DBGXDLM;                              /* Debug Comparator Data Low Mask Register; 0x0000002F */
volatile PORTKSTR _PORTK;                                  /* Port K Data Register; 0x00000032 */
volatile DDRKSTR _DDRK;                                    /* Port K Data Direction Register; 0x00000033 */
volatile SYNRSTR _SYNR;                                    /* S12XECRG Synthesizer Register; 0x00000034 */
volatile REFDVSTR _REFDV;                                  /* S12XECRG Reference Divider Register; 0x00000035 */
volatile POSTDIVSTR _POSTDIV;                              /* S12XECRG Post Divider Register; 0x00000036 */
volatile CRGFLGSTR _CRGFLG;                                /* S12XECRG Flags Register; 0x00000037 */
volatile CRGINTSTR _CRGINT;                                /* S12XECRG Interrupt Enable Register; 0x00000038 */
volatile CLKSELSTR _CLKSEL;                                /* S12XECRG Clock Select Register; 0x00000039 */
volatile PLLCTLSTR _PLLCTL;                                /* S12XECRG IPLL Control Register; 0x0000003A */
volatile RTICTLSTR _RTICTL;                                /* ECRG RTI Control Register; 0x0000003B */
volatile COPCTLSTR _COPCTL;                                /* CRG COP Control Register; 0x0000003C */
volatile ARMCOPSTR _ARMCOP;                                /* CRG COP Timer Arm/Reset Register; 0x0000003F */
volatile ECT_TIOSSTR _ECT_TIOS;                            /* Timer Input Capture/Output Compare Select; 0x00000040 */
volatile ECT_CFORCSTR _ECT_CFORC;                          /* Timer Compare Force Register; 0x00000041 */
volatile ECT_OC7MSTR _ECT_OC7M;                            /* Output Compare 7 Mask Register; 0x00000042 */
volatile ECT_OC7DSTR _ECT_OC7D;                            /* Output Compare 7 Data Register; 0x00000043 */
volatile ECT_TSCR1STR _ECT_TSCR1;                          /* Timer System Control Register1; 0x00000046 */
volatile ECT_TTOVSTR _ECT_TTOV;                            /* Timer Toggle On Overflow Register; 0x00000047 */
volatile ECT_TCTL1STR _ECT_TCTL1;                          /* Timer Control Register 1; 0x00000048 */
volatile ECT_TCTL2STR _ECT_TCTL2;                          /* Timer Control Register 2; 0x00000049 */
volatile ECT_TCTL3STR _ECT_TCTL3;                          /* Timer Control Register 3; 0x0000004A */
volatile ECT_TCTL4STR _ECT_TCTL4;                          /* Timer Control Register 4; 0x0000004B */
volatile ECT_TIESTR _ECT_TIE;                              /* Timer Interrupt Enable Register; 0x0000004C */
volatile ECT_TSCR2STR _ECT_TSCR2;                          /* Timer System Control Register 2; 0x0000004D */
volatile ECT_TFLG1STR _ECT_TFLG1;                          /* Main Timer Interrupt Flag 1; 0x0000004E */
volatile ECT_TFLG2STR _ECT_TFLG2;                          /* Main Timer Interrupt Flag 2; 0x0000004F */
volatile ECT_PACTLSTR _ECT_PACTL;                          /* 16-Bit Pulse Accumulator A Control Register; 0x00000060 */
volatile ECT_PAFLGSTR _ECT_PAFLG;                          /* Pulse Accumulator A Flag Register; 0x00000061 */
volatile ECT_MCCTLSTR _ECT_MCCTL;                          /* Modulus Down Counter underflow; 0x00000066 */
volatile ECT_MCFLGSTR _ECT_MCFLG;                          /* 16-Bit Modulus Down Counter Flag Register; 0x00000067 */
volatile ECT_ICPARSTR _ECT_ICPAR;                          /* Input Control Pulse Accumulator Register; 0x00000068 */
volatile ECT_DLYCTSTR _ECT_DLYCT;                          /* Delay Counter Control Register; 0x00000069 */
volatile ECT_ICOVWSTR _ECT_ICOVW;                          /* Input Control Overwrite Register; 0x0000006A */
volatile ECT_ICSYSSTR _ECT_ICSYS;                          /* Input Control System Control Register; 0x0000006B */
volatile ECT_OCPDSTR _ECT_OCPD;                            /* Output Compare Pin Disconnect Register; 0x0000006C */
volatile ECT_PTPSRSTR _ECT_PTPSR;                          /* Precision Timer Prescaler Select Register; 0x0000006E */
volatile ECT_PTMCPSRSTR _ECT_PTMCPSR;                      /* Precision Timer Modulus Counter Prescaler Select Register; 0x0000006F */
volatile ECT_PBCTLSTR _ECT_PBCTL;                          /* 16-Bit Pulse Accumulator B Control Register; 0x00000070 */
volatile ECT_PBFLGSTR _ECT_PBFLG;                          /* Pulse Accumulator B Flag Register; 0x00000071 */
volatile ATD1STAT0STR _ATD1STAT0;                          /* ATD 1 Status Register 0; 0x00000086 */
volatile SCI2ACR2STR _SCI2ACR2;                            /* SCI 2 Alternative Control Register 2; 0x000000BA */
volatile SCI2CR2STR _SCI2CR2;                              /* SCI 2 Control Register 2; 0x000000BB */
volatile SCI2SR1STR _SCI2SR1;                              /* SCI 2 Status Register 1; 0x000000BC */
volatile SCI2SR2STR _SCI2SR2;                              /* SCI 2 Status Register 2; 0x000000BD */
volatile SCI2DRHSTR _SCI2DRH;                              /* SCI 2 Data Register High; 0x000000BE */
volatile SCI2DRLSTR _SCI2DRL;                              /* SCI 2 Data Register Low; 0x000000BF */
volatile SCI0ACR2STR _SCI0ACR2;                            /* SCI 0 Alternative Control Register 2; 0x000000CA */
volatile SCI0CR2STR _SCI0CR2;                              /* SCI 0 Control Register 2; 0x000000CB */
volatile SCI0SR1STR _SCI0SR1;                              /* SCI 0 Status Register 1; 0x000000CC */
volatile SCI0SR2STR _SCI0SR2;                              /* SCI 0 Status Register 2; 0x000000CD */
volatile SCI0DRHSTR _SCI0DRH;                              /* SCI 0 Data Register High; 0x000000CE */
volatile SCI0DRLSTR _SCI0DRL;                              /* SCI 0 Data Register Low; 0x000000CF */
volatile SCI1ACR2STR _SCI1ACR2;                            /* SCI 1 Alternative Control Register 2; 0x000000D2 */
volatile SCI1CR2STR _SCI1CR2;                              /* SCI 1 Control Register 2; 0x000000D3 */
volatile SCI1SR1STR _SCI1SR1;                              /* SCI 1 Status Register 1; 0x000000D4 */
volatile SCI1SR2STR _SCI1SR2;                              /* SCI 1 Status Register 2; 0x000000D5 */
volatile SCI1DRHSTR _SCI1DRH;                              /* SCI 1 Data Register High; 0x000000D6 */
volatile SCI1DRLSTR _SCI1DRL;                              /* SCI 1 Data Register Low; 0x000000D7 */
volatile SPI0CR1STR _SPI0CR1;                              /* SPI 0 Control Register 1; 0x000000D8 */
volatile SPI0CR2STR _SPI0CR2;                              /* SPI 0 Control Register 2; 0x000000D9 */
volatile SPI0BRSTR _SPI0BR;                                /* SPI 0 Baud Rate Register; 0x000000DA */
volatile SPI0SRSTR _SPI0SR;                                /* SPI 0 Status Register; 0x000000DB */
volatile IIC0_IBADSTR _IIC0_IBAD;                          /* IIC Address Register; 0x000000E0 */
volatile IIC0_IBFDSTR _IIC0_IBFD;                          /* IIC Frequency Divider Register; 0x000000E1 */
volatile IIC0_IBCRSTR _IIC0_IBCR;                          /* IIC Control Register; 0x000000E2 */
volatile IIC0_IBSRSTR _IIC0_IBSR;                          /* IIC Status Register; 0x000000E3 */
volatile IIC0_IBDRSTR _IIC0_IBDR;                          /* IIC Data I/O Register; 0x000000E4 */
volatile IIC0_IBCR2STR _IIC0_IBCR2;                        /* IIC Control Register 2; 0x000000E5 */
volatile SPI1CR1STR _SPI1CR1;                              /* SPI 1 Control Register 1; 0x000000F0 */
volatile SPI1CR2STR _SPI1CR2;                              /* SPI 1 Control Register 2; 0x000000F1 */
volatile SPI1BRSTR _SPI1BR;                                /* SPI 1 Baud Rate Register; 0x000000F2 */
volatile SPI1SRSTR _SPI1SR;                                /* SPI 1 Status Register; 0x000000F3 */
volatile SPI2CR1STR _SPI2CR1;                              /* SPI 2 Control Register 1; 0x000000F8 */
volatile SPI2CR2STR _SPI2CR2;                              /* SPI 2 Control Register 2; 0x000000F9 */
volatile SPI2BRSTR _SPI2BR;                                /* SPI 2 Baud Rate Register; 0x000000FA */
volatile SPI2SRSTR _SPI2SR;                                /* SPI 2 Status Register; 0x000000FB */
volatile FCLKDIVSTR _FCLKDIV;                              /* Flash Clock Divider Register; 0x00000100 */
volatile FSECSTR _FSEC;                                    /* Flash Security Register; 0x00000101 */
volatile FCCOBIXSTR _FCCOBIX;                              /* Flash CCOB Index Register; 0x00000102 */
volatile FECCRIXSTR _FECCRIX;                              /* Flash ECCR Index Register; 0x00000103 */
volatile FCNFGSTR _FCNFG;                                  /* Flash Configuration Register; 0x00000104 */
volatile FERCNFGSTR _FERCNFG;                              /* Flash Error Configuration Register; 0x00000105 */
volatile FSTATSTR _FSTAT;                                  /* Flash Status Register; 0x00000106 */
volatile FERSTATSTR _FERSTAT;                              /* Flash Error Status Register; 0x00000107 */
volatile FPROTSTR _FPROT;                                  /* P-Flash Protection Register; 0x00000108 */
volatile EPROTSTR _EPROT;                                  /* EEE Protection Register; 0x00000109 */
volatile FOPTSTR _FOPT;                                    /* Flash Option Register; 0x00000110 */
volatile MPUFLGSTR _MPUFLG;                                /* MPU Flag Register; 0x00000114 */
volatile MPUASTAT0STR _MPUASTAT0;                          /* MPU Address Status Register 0; 0x00000115 */
volatile MPUASTAT1STR _MPUASTAT1;                          /* MPU Address Status Register 1; 0x00000116 */
volatile MPUASTAT2STR _MPUASTAT2;                          /* MPU Address Status Register 2; 0x00000117 */
volatile MPUSELSTR _MPUSEL;                                /* MPU Descriptor Select Register; 0x00000119 */
volatile MPUDESC0STR _MPUDESC0;                            /* MPU Descriptor Register 0; 0x0000011A */
volatile MPUDESC1STR _MPUDESC1;                            /* MPU Descriptor Register 1; 0x0000011B */
volatile MPUDESC2STR _MPUDESC2;                            /* MPU Descriptor Register 2; 0x0000011C */
volatile MPUDESC3STR _MPUDESC3;                            /* MPU Descriptor Register 2; 0x0000011D */
volatile MPUDESC4STR _MPUDESC4;                            /* MPU Descriptor Register 2; 0x0000011E */
volatile MPUDESC5STR _MPUDESC5;                            /* MPU Descriptor Register 2; 0x0000011F */
volatile IVBRSTR _IVBR;                                    /* Interrupt Vector Base Register; 0x00000121 */
volatile INT_XGPRIOSTR _INT_XGPRIO;                        /* XGATE Interrupt Priority Configuration Register; 0x00000126 */
volatile INT_CFADDRSTR _INT_CFADDR;                        /* Interrupt Request Configuration Address Register; 0x00000127 */
volatile INT_CFDATA0STR _INT_CFDATA0;                      /* Interrupt Request Configuration Data Register 0; 0x00000128 */
volatile INT_CFDATA1STR _INT_CFDATA1;                      /* Interrupt Request Configuration Data Register 1; 0x00000129 */
volatile INT_CFDATA2STR _INT_CFDATA2;                      /* Interrupt Request Configuration Data Register 2; 0x0000012A */
volatile INT_CFDATA3STR _INT_CFDATA3;                      /* Interrupt Request Configuration Data Register 3; 0x0000012B */
volatile INT_CFDATA4STR _INT_CFDATA4;                      /* Interrupt Request Configuration Data Register 4; 0x0000012C */
volatile INT_CFDATA5STR _INT_CFDATA5;                      /* Interrupt Request Configuration Data Register 5; 0x0000012D */
volatile INT_CFDATA6STR _INT_CFDATA6;                      /* Interrupt Request Configuration Data Register 6; 0x0000012E */
volatile INT_CFDATA7STR _INT_CFDATA7;                      /* Interrupt Request Configuration Data Register 7; 0x0000012F */
volatile SCI4ACR2STR _SCI4ACR2;                            /* SCI 4 Alternative Control Register 2; 0x00000132 */
volatile SCI4CR2STR _SCI4CR2;                              /* SCI 4 Control Register 2; 0x00000133 */
volatile SCI4SR1STR _SCI4SR1;                              /* SCI 4 Status Register 1; 0x00000134 */
volatile SCI4SR2STR _SCI4SR2;                              /* SCI 4 Status Register 2; 0x00000135 */
volatile SCI4DRHSTR _SCI4DRH;                              /* SCI 4 Data Register High; 0x00000136 */
volatile SCI4DRLSTR _SCI4DRL;                              /* SCI 4 Data Register Low; 0x00000137 */
volatile CAN0CTL0STR _CAN0CTL0;                            /* MSCAN0 Control 0 Register; 0x00000140 */
volatile CAN0CTL1STR _CAN0CTL1;                            /* MSCAN0 Control 1 Register; 0x00000141 */
volatile CAN0BTR0STR _CAN0BTR0;                            /* MSCAN0 Bus Timing Register 0; 0x00000142 */
volatile CAN0BTR1STR _CAN0BTR1;                            /* MSCAN0 Bus Timing Register 1; 0x00000143 */
volatile CAN0RFLGSTR _CAN0RFLG;                            /* MSCAN0 Receiver Flag Register; 0x00000144 */
volatile CAN0RIERSTR _CAN0RIER;                            /* MSCAN0 Receiver Interrupt Enable Register; 0x00000145 */
volatile CAN0TFLGSTR _CAN0TFLG;                            /* MSCAN0 Transmitter Flag Register; 0x00000146 */
volatile CAN0TIERSTR _CAN0TIER;                            /* MSCAN0 Transmitter Interrupt Enable Register; 0x00000147 */
volatile CAN0TARQSTR _CAN0TARQ;                            /* MSCAN0 Transmitter Message Abort Request; 0x00000148 */
volatile CAN0TAAKSTR _CAN0TAAK;                            /* MSCAN0 Transmitter Message Abort Acknowledge; 0x00000149 */
volatile CAN0TBSELSTR _CAN0TBSEL;                          /* MSCAN0 Transmit Buffer Selection; 0x0000014A */
volatile CAN0IDACSTR _CAN0IDAC;                            /* MSCAN0 Identifier Acceptance Control Register; 0x0000014B */
volatile CAN0MISCSTR _CAN0MISC;                            /* MSCAN0 Miscellaneous Register; 0x0000014D */
volatile CAN0RXERRSTR _CAN0RXERR;                          /* MSCAN0 Receive Error Counter Register; 0x0000014E */
volatile CAN0TXERRSTR _CAN0TXERR;                          /* MSCAN0 Transmit Error Counter Register; 0x0000014F */
volatile CAN0IDAR0STR _CAN0IDAR0;                          /* MSCAN0 Identifier Acceptance Register 0; 0x00000150 */
volatile CAN0IDAR1STR _CAN0IDAR1;                          /* MSCAN0 Identifier Acceptance Register 1; 0x00000151 */
volatile CAN0IDAR2STR _CAN0IDAR2;                          /* MSCAN0 Identifier Acceptance Register 2; 0x00000152 */
volatile CAN0IDAR3STR _CAN0IDAR3;                          /* MSCAN0 Identifier Acceptance Register 3; 0x00000153 */
volatile CAN0IDMR0STR _CAN0IDMR0;                          /* MSCAN0 Identifier Mask Register 0; 0x00000154 */
volatile CAN0IDMR1STR _CAN0IDMR1;                          /* MSCAN0 Identifier Mask Register 1; 0x00000155 */
volatile CAN0IDMR2STR _CAN0IDMR2;                          /* MSCAN0 Identifier Mask Register 2; 0x00000156 */
volatile CAN0IDMR3STR _CAN0IDMR3;                          /* MSCAN0 Identifier Mask Register 3; 0x00000157 */
volatile CAN0IDAR4STR _CAN0IDAR4;                          /* MSCAN0 Identifier Acceptance Register 4; 0x00000158 */
volatile CAN0IDAR5STR _CAN0IDAR5;                          /* MSCAN0 Identifier Acceptance Register 5; 0x00000159 */
volatile CAN0IDAR6STR _CAN0IDAR6;                          /* MSCAN0 Identifier Acceptance Register 6; 0x0000015A */
volatile CAN0IDAR7STR _CAN0IDAR7;                          /* MSCAN0 Identifier Acceptance Register 7; 0x0000015B */
volatile CAN0IDMR4STR _CAN0IDMR4;                          /* MSCAN0 Identifier Mask Register 4; 0x0000015C */
volatile CAN0IDMR5STR _CAN0IDMR5;                          /* MSCAN0 Identifier Mask Register 5; 0x0000015D */
volatile CAN0IDMR6STR _CAN0IDMR6;                          /* MSCAN0 Identifier Mask Register 6; 0x0000015E */
volatile CAN0IDMR7STR _CAN0IDMR7;                          /* MSCAN0 Identifier Mask Register 7; 0x0000015F */
volatile CAN0RXIDR0STR _CAN0RXIDR0;                        /* MSCAN0 Receive Identifier Register 0; 0x00000160 */
volatile CAN0RXIDR1STR _CAN0RXIDR1;                        /* MSCAN0 Receive Identifier Register 1; 0x00000161 */
volatile CAN0RXIDR2STR _CAN0RXIDR2;                        /* MSCAN0 Receive Identifier Register 2; 0x00000162 */
volatile CAN0RXIDR3STR _CAN0RXIDR3;                        /* MSCAN0 Receive Identifier Register 3; 0x00000163 */
volatile CAN0RXDSR0STR _CAN0RXDSR0;                        /* MSCAN0 Receive Data Segment Register 0; 0x00000164 */
volatile CAN0RXDSR1STR _CAN0RXDSR1;                        /* MSCAN0 Receive Data Segment Register 1; 0x00000165 */
volatile CAN0RXDSR2STR _CAN0RXDSR2;                        /* MSCAN0 Receive Data Segment Register 2; 0x00000166 */
volatile CAN0RXDSR3STR _CAN0RXDSR3;                        /* MSCAN0 Receive Data Segment Register 3; 0x00000167 */
volatile CAN0RXDSR4STR _CAN0RXDSR4;                        /* MSCAN0 Receive Data Segment Register 4; 0x00000168 */
volatile CAN0RXDSR5STR _CAN0RXDSR5;                        /* MSCAN0 Receive Data Segment Register 5; 0x00000169 */
volatile CAN0RXDSR6STR _CAN0RXDSR6;                        /* MSCAN0 Receive Data Segment Register 6; 0x0000016A */
volatile CAN0RXDSR7STR _CAN0RXDSR7;                        /* MSCAN0 Receive Data Segment Register 7; 0x0000016B */
volatile CAN0RXDLRSTR _CAN0RXDLR;                          /* MSCAN0 Receive Data Length Register; 0x0000016C */
volatile CAN0TXIDR0STR _CAN0TXIDR0;                        /* MSCAN0 Transmit Identifier Register 0; 0x00000170 */
volatile CAN0TXIDR1STR _CAN0TXIDR1;                        /* MSCAN0 Transmit Identifier Register 1; 0x00000171 */
volatile CAN0TXIDR2STR _CAN0TXIDR2;                        /* MSCAN0 Transmit Identifier Register 2; 0x00000172 */
volatile CAN0TXIDR3STR _CAN0TXIDR3;                        /* MSCAN0 Transmit Identifier Register 3; 0x00000173 */
volatile CAN0TXDSR0STR _CAN0TXDSR0;                        /* MSCAN0 Transmit Data Segment Register 0; 0x00000174 */
volatile CAN0TXDSR1STR _CAN0TXDSR1;                        /* MSCAN0 Transmit Data Segment Register 1; 0x00000175 */
volatile CAN0TXDSR2STR _CAN0TXDSR2;                        /* MSCAN0 Transmit Data Segment Register 2; 0x00000176 */
volatile CAN0TXDSR3STR _CAN0TXDSR3;                        /* MSCAN0 Transmit Data Segment Register 3; 0x00000177 */
volatile CAN0TXDSR4STR _CAN0TXDSR4;                        /* MSCAN0 Transmit Data Segment Register 4; 0x00000178 */
volatile CAN0TXDSR5STR _CAN0TXDSR5;                        /* MSCAN0 Transmit Data Segment Register 5; 0x00000179 */
volatile CAN0TXDSR6STR _CAN0TXDSR6;                        /* MSCAN0 Transmit Data Segment Register 6; 0x0000017A */
volatile CAN0TXDSR7STR _CAN0TXDSR7;                        /* MSCAN0 Transmit Data Segment Register 7; 0x0000017B */
volatile CAN0TXDLRSTR _CAN0TXDLR;                          /* MSCAN0 Transmit Data Length Register; 0x0000017C */
volatile CAN0TXTBPRSTR _CAN0TXTBPR;                        /* MSCAN0 Transmit Buffer Priority; 0x0000017D */
volatile CAN1CTL0STR _CAN1CTL0;                            /* MSCAN1 Control 0 Register; 0x00000180 */
volatile CAN1CTL1STR _CAN1CTL1;                            /* MSCAN1 Control 1 Register; 0x00000181 */
volatile CAN1BTR0STR _CAN1BTR0;                            /* MSCAN1 Bus Timing Register 0; 0x00000182 */
volatile CAN1BTR1STR _CAN1BTR1;                            /* MSCAN1 Bus Timing Register 1; 0x00000183 */
volatile CAN1RFLGSTR _CAN1RFLG;                            /* MSCAN1 Receiver Flag Register; 0x00000184 */
volatile CAN1RIERSTR _CAN1RIER;                            /* MSCAN1 Receiver Interrupt Enable Register; 0x00000185 */
volatile CAN1TFLGSTR _CAN1TFLG;                            /* MSCAN1 Transmitter Flag Register; 0x00000186 */
volatile CAN1TIERSTR _CAN1TIER;                            /* MSCAN1 Transmitter Interrupt Enable Register; 0x00000187 */
volatile CAN1TARQSTR _CAN1TARQ;                            /* MSCAN1 Transmitter Message Abort Request; 0x00000188 */
volatile CAN1TAAKSTR _CAN1TAAK;                            /* MSCAN1 Transmitter Message Abort Acknowledge; 0x00000189 */
volatile CAN1TBSELSTR _CAN1TBSEL;                          /* MSCAN1 Transmit Buffer Selection; 0x0000018A */
volatile CAN1IDACSTR _CAN1IDAC;                            /* MSCAN1 Identifier Acceptance Control Register; 0x0000018B */
volatile CAN1MISCSTR _CAN1MISC;                            /* MSCAN1 Miscellaneous Register; 0x0000018D */
volatile CAN1RXERRSTR _CAN1RXERR;                          /* MSCAN1 Receive Error Counter Register; 0x0000018E */
volatile CAN1TXERRSTR _CAN1TXERR;                          /* MSCAN1 Transmit Error Counter Register; 0x0000018F */
volatile CAN1IDAR0STR _CAN1IDAR0;                          /* MSCAN1 Identifier Acceptance Register 0; 0x00000190 */
volatile CAN1IDAR1STR _CAN1IDAR1;                          /* MSCAN1 Identifier Acceptance Register 1; 0x00000191 */
volatile CAN1IDAR2STR _CAN1IDAR2;                          /* MSCAN1 Identifier Acceptance Register 2; 0x00000192 */
volatile CAN1IDAR3STR _CAN1IDAR3;                          /* MSCAN1 Identifier Acceptance Register 3; 0x00000193 */
volatile CAN1IDMR0STR _CAN1IDMR0;                          /* MSCAN1 Identifier Mask Register 0; 0x00000194 */
volatile CAN1IDMR1STR _CAN1IDMR1;                          /* MSCAN1 Identifier Mask Register 1; 0x00000195 */
volatile CAN1IDMR2STR _CAN1IDMR2;                          /* MSCAN1 Identifier Mask Register 2; 0x00000196 */
volatile CAN1IDMR3STR _CAN1IDMR3;                          /* MSCAN1 Identifier Mask Register 3; 0x00000197 */
volatile CAN1IDAR4STR _CAN1IDAR4;                          /* MSCAN1 Identifier Acceptance Register 4; 0x00000198 */
volatile CAN1IDAR5STR _CAN1IDAR5;                          /* MSCAN1 Identifier Acceptance Register 5; 0x00000199 */
volatile CAN1IDAR6STR _CAN1IDAR6;                          /* MSCAN1 Identifier Acceptance Register 6; 0x0000019A */
volatile CAN1IDAR7STR _CAN1IDAR7;                          /* MSCAN1 Identifier Acceptance Register 7; 0x0000019B */
volatile CAN1IDMR4STR _CAN1IDMR4;                          /* MSCAN1 Identifier Mask Register 4; 0x0000019C */
volatile CAN1IDMR5STR _CAN1IDMR5;                          /* MSCAN1 Identifier Mask Register 5; 0x0000019D */
volatile CAN1IDMR6STR _CAN1IDMR6;                          /* MSCAN1 Identifier Mask Register 6; 0x0000019E */
volatile CAN1IDMR7STR _CAN1IDMR7;                          /* MSCAN1 Identifier Mask Register 7; 0x0000019F */
volatile CAN1RXIDR0STR _CAN1RXIDR0;                        /* MSCAN1 Receive Identifier Register 0; 0x000001A0 */
volatile CAN1RXIDR1STR _CAN1RXIDR1;                        /* MSCAN1 Receive Identifier Register 1; 0x000001A1 */
volatile CAN1RXIDR2STR _CAN1RXIDR2;                        /* MSCAN1 Receive Identifier Register 2; 0x000001A2 */
volatile CAN1RXIDR3STR _CAN1RXIDR3;                        /* MSCAN1 Receive Identifier Register 3; 0x000001A3 */
volatile CAN1RXDSR0STR _CAN1RXDSR0;                        /* MSCAN1 Receive Data Segment Register 0; 0x000001A4 */
volatile CAN1RXDSR1STR _CAN1RXDSR1;                        /* MSCAN1 Receive Data Segment Register 1; 0x000001A5 */
volatile CAN1RXDSR2STR _CAN1RXDSR2;                        /* MSCAN1 Receive Data Segment Register 2; 0x000001A6 */
volatile CAN1RXDSR3STR _CAN1RXDSR3;                        /* MSCAN1 Receive Data Segment Register 3; 0x000001A7 */
volatile CAN1RXDSR4STR _CAN1RXDSR4;                        /* MSCAN1 Receive Data Segment Register 4; 0x000001A8 */
volatile CAN1RXDSR5STR _CAN1RXDSR5;                        /* MSCAN1 Receive Data Segment Register 5; 0x000001A9 */
volatile CAN1RXDSR6STR _CAN1RXDSR6;                        /* MSCAN1 Receive Data Segment Register 6; 0x000001AA */
volatile CAN1RXDSR7STR _CAN1RXDSR7;                        /* MSCAN1 Receive Data Segment Register 7; 0x000001AB */
volatile CAN1RXDLRSTR _CAN1RXDLR;                          /* MSCAN1 Receive Data Length Register; 0x000001AC */
volatile CAN1TXIDR0STR _CAN1TXIDR0;                        /* MSCAN1 Transmit Identifier Register 0; 0x000001B0 */
volatile CAN1TXIDR1STR _CAN1TXIDR1;                        /* MSCAN1 Transmit Identifier Register 1; 0x000001B1 */
volatile CAN1TXIDR2STR _CAN1TXIDR2;                        /* MSCAN1 Transmit Identifier Register 2; 0x000001B2 */
volatile CAN1TXIDR3STR _CAN1TXIDR3;                        /* MSCAN1 Transmit Identifier Register 3; 0x000001B3 */
volatile CAN1TXDSR0STR _CAN1TXDSR0;                        /* MSCAN1 Transmit Data Segment Register 0; 0x000001B4 */
volatile CAN1TXDSR1STR _CAN1TXDSR1;                        /* MSCAN1 Transmit Data Segment Register 1; 0x000001B5 */
volatile CAN1TXDSR2STR _CAN1TXDSR2;                        /* MSCAN1 Transmit Data Segment Register 2; 0x000001B6 */
volatile CAN1TXDSR3STR _CAN1TXDSR3;                        /* MSCAN1 Transmit Data Segment Register 3; 0x000001B7 */
volatile CAN1TXDSR4STR _CAN1TXDSR4;                        /* MSCAN1 Transmit Data Segment Register 4; 0x000001B8 */
volatile CAN1TXDSR5STR _CAN1TXDSR5;                        /* MSCAN1 Transmit Data Segment Register 5; 0x000001B9 */
volatile CAN1TXDSR6STR _CAN1TXDSR6;                        /* MSCAN1 Transmit Data Segment Register 6; 0x000001BA */
volatile CAN1TXDSR7STR _CAN1TXDSR7;                        /* MSCAN1 Transmit Data Segment Register 7; 0x000001BB */
volatile CAN1TXDLRSTR _CAN1TXDLR;                          /* MSCAN1 Transmit Data Length Register; 0x000001BC */
volatile CAN1TXTBPRSTR _CAN1TXTBPR;                        /* MSCAN1 Transmit Buffer Priority; 0x000001BD */
volatile PTTSTR _PTT;                                      /* Port T Data Register; 0x00000240 */
volatile PTITSTR _PTIT;                                    /* Port T Input Register; 0x00000241 */
volatile DDRTSTR _DDRT;                                    /* Port T Data Direction Register; 0x00000242 */
volatile RDRTSTR _RDRT;                                    /* Port T Reduced Drive Register; 0x00000243 */
volatile PERTSTR _PERT;                                    /* Port T Pull Device Enable Register; 0x00000244 */
volatile PPSTSTR _PPST;                                    /* Port T Polarity Select Register; 0x00000245 */
volatile PTSSTR _PTS;                                      /* Port S Data Register; 0x00000248 */
volatile PTISSTR _PTIS;                                    /* Port S Input Register; 0x00000249 */
volatile DDRSSTR _DDRS;                                    /* Port S Data Direction Register; 0x0000024A */
volatile RDRSSTR _RDRS;                                    /* Port S Reduced Drive Register; 0x0000024B */
volatile PERSSTR _PERS;                                    /* Port S Pull Device Enable Register; 0x0000024C */
volatile PPSSSTR _PPSS;                                    /* Port S Polarity Select Register; 0x0000024D */
volatile WOMSSTR _WOMS;                                    /* Port S Wired-Or Mode Register; 0x0000024E */
volatile PTMSTR _PTM;                                      /* Port M Data Register; 0x00000250 */
volatile PTIMSTR _PTIM;                                    /* Port M Input Register; 0x00000251 */
volatile DDRMSTR _DDRM;                                    /* Port M Data Direction Register; 0x00000252 */
volatile RDRMSTR _RDRM;                                    /* Port M Reduced Drive Register; 0x00000253 */
volatile PERMSTR _PERM;                                    /* Port M Pull Device Enable Register; 0x00000254 */
volatile PPSMSTR _PPSM;                                    /* Port M Polarity Select Register; 0x00000255 */
volatile WOMMSTR _WOMM;                                    /* Port M Wired-Or Mode Register; 0x00000256 */
volatile MODRRSTR _MODRR;                                  /* Module Routing Register; 0x00000257 */
volatile PTPSTR _PTP;                                      /* Port P Data Register; 0x00000258 */
volatile PTIPSTR _PTIP;                                    /* Port P Input Register; 0x00000259 */
volatile DDRPSTR _DDRP;                                    /* Port P Data Direction Register; 0x0000025A */
volatile RDRPSTR _RDRP;                                    /* Port P Reduced Drive Register; 0x0000025B */
volatile PERPSTR _PERP;                                    /* Port P Pull Device Enable Register; 0x0000025C */
volatile PPSPSTR _PPSP;                                    /* Port P Polarity Select Register; 0x0000025D */
volatile PIEPSTR _PIEP;                                    /* Port P Interrupt Enable Register; 0x0000025E */
volatile PIFPSTR _PIFP;                                    /* Port P Interrupt Flag Register; 0x0000025F */
volatile PTHSTR _PTH;                                      /* Port H Data Register; 0x00000260 */
volatile PTIHSTR _PTIH;                                    /* Port H Input Register; 0x00000261 */
volatile DDRHSTR _DDRH;                                    /* Port H Data Direction Register; 0x00000262 */
volatile RDRHSTR _RDRH;                                    /* Port H Reduced Drive Register; 0x00000263 */
volatile PERHSTR _PERH;                                    /* Port H Pull Device Enable Register; 0x00000264 */
volatile PPSHSTR _PPSH;                                    /* Port H Polarity Select Register; 0x00000265 */
volatile PIEHSTR _PIEH;                                    /* Port H Interrupt Enable Register; 0x00000266 */
volatile PIFHSTR _PIFH;                                    /* Port H Interrupt Flag Register; 0x00000267 */
volatile PTJSTR _PTJ;                                      /* Port J Data Register; 0x00000268 */
volatile PTIJSTR _PTIJ;                                    /* Port J Input Register; 0x00000269 */
volatile DDRJSTR _DDRJ;                                    /* Port J Data Direction Register; 0x0000026A */
volatile RDRJSTR _RDRJ;                                    /* Port J Reduced Drive Register; 0x0000026B */
volatile PERJSTR _PERJ;                                    /* Port J Pull Device Enable Register; 0x0000026C */
volatile PPSJSTR _PPSJ;                                    /* Port J Polarity Select Register; 0x0000026D */
volatile PIEJSTR _PIEJ;                                    /* Port J Interrupt Enable Register; 0x0000026E */
volatile PIFJSTR _PIFJ;                                    /* Port J Interrupt Flag Register; 0x0000026F */
volatile CAN4CTL0STR _CAN4CTL0;                            /* MSCAN4 Control 0 Register; 0x00000280 */
volatile CAN4CTL1STR _CAN4CTL1;                            /* MSCAN4 Control 1 Register; 0x00000281 */
volatile CAN4BTR0STR _CAN4BTR0;                            /* MSCAN4 Bus Timing Register 0; 0x00000282 */
volatile CAN4BTR1STR _CAN4BTR1;                            /* MSCAN4 Bus Timing Register 1; 0x00000283 */
volatile CAN4RFLGSTR _CAN4RFLG;                            /* MSCAN4 Receiver Flag Register; 0x00000284 */
volatile CAN4RIERSTR _CAN4RIER;                            /* MSCAN4 Receiver Interrupt Enable Register; 0x00000285 */
volatile CAN4TFLGSTR _CAN4TFLG;                            /* MSCAN4 Transmitter Flag Register; 0x00000286 */
volatile CAN4TIERSTR _CAN4TIER;                            /* MSCAN4 Transmitter Interrupt Enable Register; 0x00000287 */
volatile CAN4TARQSTR _CAN4TARQ;                            /* MSCAN4 Transmitter Message Abort Request; 0x00000288 */
volatile CAN4TAAKSTR _CAN4TAAK;                            /* MSCAN4 Transmitter Message Abort Acknowledge; 0x00000289 */
volatile CAN4TBSELSTR _CAN4TBSEL;                          /* MSCAN4 Transmit Buffer Selection; 0x0000028A */
volatile CAN4IDACSTR _CAN4IDAC;                            /* MSCAN4 Identifier Acceptance Control Register; 0x0000028B */
volatile CAN4MISCSTR _CAN4MISC;                            /* MSCAN4 Miscellaneous Register; 0x0000028D */
volatile CAN4RXERRSTR _CAN4RXERR;                          /* MSCAN4 Receive Error Counter Register; 0x0000028E */
volatile CAN4TXERRSTR _CAN4TXERR;                          /* MSCAN4 Transmit Error Counter Register; 0x0000028F */
volatile CAN4IDAR0STR _CAN4IDAR0;                          /* MSCAN4 Identifier Acceptance Register 0; 0x00000290 */
volatile CAN4IDAR1STR _CAN4IDAR1;                          /* MSCAN4 Identifier Acceptance Register 1; 0x00000291 */
volatile CAN4IDAR2STR _CAN4IDAR2;                          /* MSCAN4 Identifier Acceptance Register 2; 0x00000292 */
volatile CAN4IDAR3STR _CAN4IDAR3;                          /* MSCAN4 Identifier Acceptance Register 3; 0x00000293 */
volatile CAN4IDMR0STR _CAN4IDMR0;                          /* MSCAN4 Identifier Mask Register 0; 0x00000294 */
volatile CAN4IDMR1STR _CAN4IDMR1;                          /* MSCAN4 Identifier Mask Register 1; 0x00000295 */
volatile CAN4IDMR2STR _CAN4IDMR2;                          /* MSCAN4 Identifier Mask Register 2; 0x00000296 */
volatile CAN4IDMR3STR _CAN4IDMR3;                          /* MSCAN4 Identifier Mask Register 3; 0x00000297 */
volatile CAN4IDAR4STR _CAN4IDAR4;                          /* MSCAN4 Identifier Acceptance Register 4; 0x00000298 */
volatile CAN4IDAR5STR _CAN4IDAR5;                          /* MSCAN4 Identifier Acceptance Register 5; 0x00000299 */
volatile CAN4IDAR6STR _CAN4IDAR6;                          /* MSCAN4 Identifier Acceptance Register 6; 0x0000029A */
volatile CAN4IDAR7STR _CAN4IDAR7;                          /* MSCAN4 Identifier Acceptance Register 7; 0x0000029B */
volatile CAN4IDMR4STR _CAN4IDMR4;                          /* MSCAN4 Identifier Mask Register 4; 0x0000029C */
volatile CAN4IDMR5STR _CAN4IDMR5;                          /* MSCAN4 Identifier Mask Register 5; 0x0000029D */
volatile CAN4IDMR6STR _CAN4IDMR6;                          /* MSCAN4 Identifier Mask Register 6; 0x0000029E */
volatile CAN4IDMR7STR _CAN4IDMR7;                          /* MSCAN4 Identifier Mask Register 7; 0x0000029F */
volatile CAN4RXIDR0STR _CAN4RXIDR0;                        /* MSCAN4 Receive Identifier Register 0; 0x000002A0 */
volatile CAN4RXIDR1STR _CAN4RXIDR1;                        /* MSCAN4 Receive Identifier Register 1; 0x000002A1 */
volatile CAN4RXIDR2STR _CAN4RXIDR2;                        /* MSCAN4 Receive Identifier Register 2; 0x000002A2 */
volatile CAN4RXIDR3STR _CAN4RXIDR3;                        /* MSCAN4 Receive Identifier Register 3; 0x000002A3 */
volatile CAN4RXDSR0STR _CAN4RXDSR0;                        /* MSCAN4 Receive Data Segment Register 0; 0x000002A4 */
volatile CAN4RXDSR1STR _CAN4RXDSR1;                        /* MSCAN4 Receive Data Segment Register 1; 0x000002A5 */
volatile CAN4RXDSR2STR _CAN4RXDSR2;                        /* MSCAN4 Receive Data Segment Register 2; 0x000002A6 */
volatile CAN4RXDSR3STR _CAN4RXDSR3;                        /* MSCAN4 Receive Data Segment Register 3; 0x000002A7 */
volatile CAN4RXDSR4STR _CAN4RXDSR4;                        /* MSCAN4 Receive Data Segment Register 4; 0x000002A8 */
volatile CAN4RXDSR5STR _CAN4RXDSR5;                        /* MSCAN4 Receive Data Segment Register 5; 0x000002A9 */
volatile CAN4RXDSR6STR _CAN4RXDSR6;                        /* MSCAN4 Receive Data Segment Register 6; 0x000002AA */
volatile CAN4RXDSR7STR _CAN4RXDSR7;                        /* MSCAN4 Receive Data Segment Register 7; 0x000002AB */
volatile CAN4RXDLRSTR _CAN4RXDLR;                          /* MSCAN4 Receive Data Length Register; 0x000002AC */
volatile CAN4TXIDR0STR _CAN4TXIDR0;                        /* MSCAN4 Transmit Identifier Register 0; 0x000002B0 */
volatile CAN4TXIDR1STR _CAN4TXIDR1;                        /* MSCAN4 Transmit Identifier Register 1; 0x000002B1 */
volatile CAN4TXIDR2STR _CAN4TXIDR2;                        /* MSCAN4 Transmit Identifier Register 2; 0x000002B2 */
volatile CAN4TXIDR3STR _CAN4TXIDR3;                        /* MSCAN4 Transmit Identifier Register 3; 0x000002B3 */
volatile CAN4TXDSR0STR _CAN4TXDSR0;                        /* MSCAN4 Transmit Data Segment Register 0; 0x000002B4 */
volatile CAN4TXDSR1STR _CAN4TXDSR1;                        /* MSCAN4 Transmit Data Segment Register 1; 0x000002B5 */
volatile CAN4TXDSR2STR _CAN4TXDSR2;                        /* MSCAN4 Transmit Data Segment Register 2; 0x000002B6 */
volatile CAN4TXDSR3STR _CAN4TXDSR3;                        /* MSCAN4 Transmit Data Segment Register 3; 0x000002B7 */
volatile CAN4TXDSR4STR _CAN4TXDSR4;                        /* MSCAN4 Transmit Data Segment Register 4; 0x000002B8 */
volatile CAN4TXDSR5STR _CAN4TXDSR5;                        /* MSCAN4 Transmit Data Segment Register 5; 0x000002B9 */
volatile CAN4TXDSR6STR _CAN4TXDSR6;                        /* MSCAN4 Transmit Data Segment Register 6; 0x000002BA */
volatile CAN4TXDSR7STR _CAN4TXDSR7;                        /* MSCAN4 Transmit Data Segment Register 7; 0x000002BB */
volatile CAN4TXDLRSTR _CAN4TXDLR;                          /* MSCAN4 Transmit Data Length Register; 0x000002BC */
volatile CAN4TXTBPRSTR _CAN4TXTBPR;                        /* MSCAN4 Transmit Buffer Priority; 0x000002BD */
volatile ATD0STAT0STR _ATD0STAT0;                          /* ATD 0 Status Register 0; 0x000002C6 */
volatile VREGHTCLSTR _VREGHTCL;                            /* HT Control Register; 0x000002F0 */
volatile VREGCTRLSTR _VREGCTRL;                            /* Control Register; 0x000002F1 */
volatile VREGAPICLSTR _VREGAPICL;                          /* Autonomous Periodical Interrupt Control Register; 0x000002F2 */
volatile VREGAPITRSTR _VREGAPITR;                          /* Autonomous Periodical Interrupt Trimming Register; 0x000002F3 */
volatile VREGHTTRSTR _VREGHTTR;                            /* HTTrimming Register; 0x000002F7 */
volatile PWMESTR _PWME;                                    /* PWM Enable Register; 0x00000300 */
volatile PWMPOLSTR _PWMPOL;                                /* PWM Polarity Register; 0x00000301 */
volatile PWMCLKSTR _PWMCLK;                                /* PWM Clock Select Register; 0x00000302 */
volatile PWMPRCLKSTR _PWMPRCLK;                            /* PWM Prescale Clock Select Register; 0x00000303 */
volatile PWMCAESTR _PWMCAE;                                /* PWM Center Align Enable Register; 0x00000304 */
volatile PWMCTLSTR _PWMCTL;                                /* PWM Control Register; 0x00000305 */
volatile PWMSCLASTR _PWMSCLA;                              /* PWM Scale A Register; 0x00000308 */
volatile PWMSCLBSTR _PWMSCLB;                              /* PWM Scale B Register; 0x00000309 */
volatile PWMSDNSTR _PWMSDN;                                /* PWM Shutdown Register; 0x00000324 */
volatile PITCFLMTSTR _PITCFLMT;                            /* PIT Control and Force Load Micro Timer Register; 0x00000340 */
volatile PITFLTSTR _PITFLT;                                /* PIT Force Load Timer Register; 0x00000341 */
volatile PITCESTR _PITCE;                                  /* PIT Channel Enable Register; 0x00000342 */
volatile PITMUXSTR _PITMUX;                                /* PIT Multiplex Register; 0x00000343 */
volatile PITINTESTR _PITINTE;                              /* PIT Interrupt Enable Register; 0x00000344 */
volatile PITTFSTR _PITTF;                                  /* PIT Time-out Flag Register; 0x00000345 */
volatile PITMTLD0STR _PITMTLD0;                            /* PIT Micro Timer Load Register 0; 0x00000346 */
volatile PITMTLD1STR _PITMTLD1;                            /* PIT Micro Timer Load Register 1; 0x00000347 */
volatile PTRSTR _PTR;                                      /* Port R Data Register; 0x00000368 */
volatile PTIRSTR _PTIR;                                    /* Port R Input Register; 0x00000369 */
volatile DDRRSTR _DDRR;                                    /* Port R Data Direction Register; 0x0000036A */
volatile RDRRSTR _RDRR;                                    /* Port R Reduced Drive Register; 0x0000036B */
volatile PERRSTR _PERR;                                    /* Port R Pull Device Enable Register; 0x0000036C */
volatile PPSRSTR _PPSR;                                    /* Port R Polarity Select Register; 0x0000036D */
volatile PTRRRSTR _PTRRR;                                  /* Port R Routing Register; 0x0000036F */
volatile PTLSTR _PTL;                                      /* Port L Data Register; 0x00000370 */
volatile PTILSTR _PTIL;                                    /* Port L Input Register; 0x00000371 */
volatile DDRLSTR _DDRL;                                    /* Port L Data Direction Register; 0x00000372 */
volatile RDRLSTR _RDRL;                                    /* Port L Reduced Drive Register; 0x00000373 */
volatile PERLSTR _PERL;                                    /* Port L Pull Device Enable Register; 0x00000374 */
volatile PPSLSTR _PPSL;                                    /* Port L Polarity Select Register; 0x00000375 */
volatile WOMLSTR _WOML;                                    /* Port L Wired-Or Mode Register; 0x00000376 */
volatile PTLRRSTR _PTLRR;                                  /* Port L Routing Register; 0x00000377 */
volatile PTFSTR _PTF;                                      /* Port F Data Register; 0x00000378 */
volatile PTIFSTR _PTIF;                                    /* Port F Input Register; 0x00000379 */
volatile DDRFSTR _DDRF;                                    /* Port F Data Direction Register; 0x0000037A */
volatile RDRFSTR _RDRF;                                    /* Port F Reduced Drive Register; 0x0000037B */
volatile PERFSTR _PERF;                                    /* Port F Pull Device Enable Register; 0x0000037C */
volatile PPSFSTR _PPSF;                                    /* Port F Polarity Select Register; 0x0000037D */
volatile PTFRRSTR _PTFRR;                                  /* Port F Routing Register; 0x0000037F */
volatile XGCHIDSTR _XGCHID;                                /* XGATE Channel ID Register; 0x00000382 */
volatile XGCHPLSTR _XGCHPL;                                /* XGATE Channel Priority Level; 0x00000383 */
volatile XGISPSELSTR _XGISPSEL;                            /* XGATE Initial Stack Pointer Select Register; 0x00000385 */
volatile XGCCRSTR _XGCCR;                                  /* XGATE Condition Code Register; 0x0000039D */
/* NVFPROT - macro for reading non volatile register       Non Volatile P-Flash Protection Register; 0x0000FF0C */
/* NVEPROT - macro for reading non volatile register       Non Volatile EEE Protection Register; 0x0000FF0D */
/* NVFOPT - macro for reading non volatile register        Non Volatile Flash Option Register; 0x0000FF0E */
/* NVFSEC - macro for reading non volatile register        Non Volatile Flash Security Register; 0x0000FF0F */


/* * * * *  16-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile PORTABSTR _PORTAB;                                /* Port AB Data Register; 0x00000000 */
volatile DDRABSTR _DDRAB;                                  /* Port AB Data Direction Register; 0x00000002 */
volatile PORTCDSTR _PORTCD;                                /* Port CD Data Register; 0x00000004 */
volatile DDRCDSTR _DDRCD;                                  /* Port CD Data Direction Register; 0x00000006 */
volatile PARTIDSTR _PARTID;                                /* Part ID Register; 0x0000001A */
volatile DBGTBSTR _DBGTB;                                  /* Debug Trace Buffer Register; 0x00000024 */
volatile ECT_TCNTSTR _ECT_TCNT;                            /* Timer Count Register; 0x00000044 */
volatile ECT_TC0STR _ECT_TC0;                              /* Timer Input Capture/Output Compare Register 0; 0x00000050 */
volatile ECT_TC1STR _ECT_TC1;                              /* Timer Input Capture/Output Compare Register 1; 0x00000052 */
volatile ECT_TC2STR _ECT_TC2;                              /* Timer Input Capture/Output Compare Register 2; 0x00000054 */
volatile ECT_TC3STR _ECT_TC3;                              /* Timer Input Capture/Output Compare Register 3; 0x00000056 */
volatile ECT_TC4STR _ECT_TC4;                              /* Timer Input Capture/Output Compare Register 4; 0x00000058 */
volatile ECT_TC5STR _ECT_TC5;                              /* Timer Input Capture/Output Compare Register 5; 0x0000005A */
volatile ECT_TC6STR _ECT_TC6;                              /* Timer Input Capture/Output Compare Register 6; 0x0000005C */
volatile ECT_TC7STR _ECT_TC7;                              /* Timer Input Capture/Output Compare Register 7; 0x0000005E */
volatile ECT_PACN32STR _ECT_PACN32;                        /* Pulse Accumulators Count 32 Register; 0x00000062 */
volatile ECT_PACN10STR _ECT_PACN10;                        /* Pulse Accumulators Count 10 Register; 0x00000064 */
volatile ECT_PA32HSTR _ECT_PA32H;                          /* 8-Bit Pulse Accumulators Holding 32 Register; 0x00000072 */
volatile ECT_PA10HSTR _ECT_PA10H;                          /* 8-Bit Pulse Accumulators Holding 10 Register; 0x00000074 */
volatile ECT_MCCNTSTR _ECT_MCCNT;                          /* Modulus Down-Counter Count Register; 0x00000076 */
volatile ECT_TC0HSTR _ECT_TC0H;                            /* Timer Input Capture Holding Registers 0; 0x00000078 */
volatile ECT_TC1HSTR _ECT_TC1H;                            /* Timer Input Capture Holding Registers 1; 0x0000007A */
volatile ECT_TC2HSTR _ECT_TC2H;                            /* Timer Input Capture Holding Registers 2; 0x0000007C */
volatile ECT_TC3HSTR _ECT_TC3H;                            /* Timer Input Capture Holding Registers 3; 0x0000007E */
volatile ATD1CTL01STR _ATD1CTL01;                          /* ATD 1 Control Register 01; 0x00000080 */
volatile ATD1CTL23STR _ATD1CTL23;                          /* ATD 1 Control Register 23; 0x00000082 */
volatile ATD1CTL45STR _ATD1CTL45;                          /* ATD 1 Control Register 45; 0x00000084 */
volatile ATD1CMPESTR _ATD1CMPE;                            /* ATD 1 Compare Enable Register; 0x00000088 */
volatile ATD1STAT2STR _ATD1STAT2;                          /* ATD 1 Status Register 2; 0x0000008A */
volatile ATD1DIENSTR _ATD1DIEN;                            /* ATD 1 Input Enable Register; 0x0000008C */
volatile ATD1CMPHTSTR _ATD1CMPHT;                          /* ATD 1 Compare Higher Than Register; 0x0000008E */
volatile ATD1DR0STR _ATD1DR0;                              /* ATD 1 Conversion Result Register 0; 0x00000090 */
volatile ATD1DR1STR _ATD1DR1;                              /* ATD 1 Conversion Result Register 1; 0x00000092 */
volatile ATD1DR2STR _ATD1DR2;                              /* ATD 1 Conversion Result Register 2; 0x00000094 */
volatile ATD1DR3STR _ATD1DR3;                              /* ATD 1 Conversion Result Register 3; 0x00000096 */
volatile ATD1DR4STR _ATD1DR4;                              /* ATD 1 Conversion Result Register 4; 0x00000098 */
volatile ATD1DR5STR _ATD1DR5;                              /* ATD 1 Conversion Result Register 5; 0x0000009A */
volatile ATD1DR6STR _ATD1DR6;                              /* ATD 1 Conversion Result Register 6; 0x0000009C */
volatile ATD1DR7STR _ATD1DR7;                              /* ATD 1 Conversion Result Register 7; 0x0000009E */
volatile ATD1DR8STR _ATD1DR8;                              /* ATD 1 Conversion Result Register 8; 0x000000A0 */
volatile ATD1DR9STR _ATD1DR9;                              /* ATD 1 Conversion Result Register 9; 0x000000A2 */
volatile ATD1DR10STR _ATD1DR10;                            /* ATD 1 Conversion Result Register 10; 0x000000A4 */
volatile ATD1DR11STR _ATD1DR11;                            /* ATD 1 Conversion Result Register 11; 0x000000A6 */
volatile ATD1DR12STR _ATD1DR12;                            /* ATD 1 Conversion Result Register 12; 0x000000A8 */
volatile ATD1DR13STR _ATD1DR13;                            /* ATD 1 Conversion Result Register 13; 0x000000AA */
volatile ATD1DR14STR _ATD1DR14;                            /* ATD 1 Conversion Result Register 14; 0x000000AC */
volatile ATD1DR15STR _ATD1DR15;                            /* ATD 1 Conversion Result Register 15; 0x000000AE */
volatile SCI2BDSTR _SCI2BD;                                /* SCI 2 Baud Rate Register; 0x000000B8 */
volatile SCI0BDSTR _SCI0BD;                                /* SCI 0 Baud Rate Register; 0x000000C8 */
volatile SCI1BDSTR _SCI1BD;                                /* SCI 1 Baud Rate Register; 0x000000D0 */
volatile SPI0DRSTR _SPI0DR;                                /* SPI 0 Data Register; 0x000000DC */
volatile SPI1DRSTR _SPI1DR;                                /* SPI 1 Data Register; 0x000000F4 */
volatile SPI2DRSTR _SPI2DR;                                /* SPI 2 Data Register; 0x000000FC */
volatile FCCOBSTR _FCCOB;                                  /* Flash Common Command Object Register; 0x0000010A */
volatile ETAGSTR _ETAG;                                    /* EEE Tag Counter Register; 0x0000010C */
volatile FECCRSTR _FECCR;                                  /* Flash ECC Error Results Register; 0x0000010E */
volatile SCI4BDSTR _SCI4BD;                                /* SCI 4 Baud Rate Register; 0x00000130 */
volatile CAN0RXTSRSTR _CAN0RXTSR;                          /* MSCAN0 Receive Time Stamp Register; 0x0000016E */
volatile CAN0TXTSRSTR _CAN0TXTSR;                          /* MSCAN0 Transmit Time Stamp Register; 0x0000017E */
volatile CAN1RXTSRSTR _CAN1RXTSR;                          /* MSCAN1 Receive Time Stamp Register; 0x000001AE */
volatile CAN1TXTSRSTR _CAN1TXTSR;                          /* MSCAN1 Transmit Time Stamp Register; 0x000001BE */
volatile PT01AD0STR _PT01AD0;                              /* Port AD0 Data Register; 0x00000270 */
volatile DDR01AD0STR _DDR01AD0;                            /* Port AD0 Data Direction Register; 0x00000272 */
volatile RDR01AD0STR _RDR01AD0;                            /* Port AD0 Reduced Drive Register; 0x00000274 */
volatile PER01AD0STR _PER01AD0;                            /* Port AD0 Pull Up Enable Register; 0x00000276 */
volatile PT01AD1STR _PT01AD1;                              /* Port AD1 Data Register; 0x00000278 */
volatile DDR01AD1STR _DDR01AD1;                            /* Port AD1 Data Direction Register; 0x0000027A */
volatile RDR01AD1STR _RDR01AD1;                            /* Port AD1 Reduced Drive Register; 0x0000027C */
volatile PER01AD1STR _PER01AD1;                            /* Port AD1 Pull Up Enable Register; 0x0000027E */
volatile CAN4RXTSRSTR _CAN4RXTSR;                          /* MSCAN4 Receive Time Stamp Register; 0x000002AE */
volatile CAN4TXTSRSTR _CAN4TXTSR;                          /* MSCAN4 Transmit Time Stamp Register; 0x000002BE */
volatile ATD0CTL01STR _ATD0CTL01;                          /* ATD 0 Control Register 01; 0x000002C0 */
volatile ATD0CTL23STR _ATD0CTL23;                          /* ATD 0 Control Register 23; 0x000002C2 */
volatile ATD0CTL45STR _ATD0CTL45;                          /* ATD 0 Control Register 45; 0x000002C4 */
volatile ATD0CMPESTR _ATD0CMPE;                            /* ATD 0 Compare Enable Register; 0x000002C8 */
volatile ATD0STAT2STR _ATD0STAT2;                          /* ATD 0 Status Register 2; 0x000002CA */
volatile ATD0DIENSTR _ATD0DIEN;                            /* ATD 0 Input Enable Register; 0x000002CC */
volatile ATD0CMPHTSTR _ATD0CMPHT;                          /* ATD 0 Compare Higher Than Register; 0x000002CE */
volatile ATD0DR0STR _ATD0DR0;                              /* ATD 0 Conversion Result Register 0; 0x000002D0 */
volatile ATD0DR1STR _ATD0DR1;                              /* ATD 0 Conversion Result Register 1; 0x000002D2 */
volatile ATD0DR2STR _ATD0DR2;                              /* ATD 0 Conversion Result Register 2; 0x000002D4 */
volatile ATD0DR3STR _ATD0DR3;                              /* ATD 0 Conversion Result Register 3; 0x000002D6 */
volatile ATD0DR4STR _ATD0DR4;                              /* ATD 0 Conversion Result Register 4; 0x000002D8 */
volatile ATD0DR5STR _ATD0DR5;                              /* ATD 0 Conversion Result Register 5; 0x000002DA */
volatile ATD0DR6STR _ATD0DR6;                              /* ATD 0 Conversion Result Register 6; 0x000002DC */
volatile ATD0DR7STR _ATD0DR7;                              /* ATD 0 Conversion Result Register 7; 0x000002DE */
volatile ATD0DR8STR _ATD0DR8;                              /* ATD 0 Conversion Result Register 8; 0x000002E0 */
volatile ATD0DR9STR _ATD0DR9;                              /* ATD 0 Conversion Result Register 9; 0x000002E2 */
volatile ATD0DR10STR _ATD0DR10;                            /* ATD 0 Conversion Result Register 10; 0x000002E4 */
volatile ATD0DR11STR _ATD0DR11;                            /* ATD 0 Conversion Result Register 11; 0x000002E6 */
volatile ATD0DR12STR _ATD0DR12;                            /* ATD 0 Conversion Result Register 12; 0x000002E8 */
volatile ATD0DR13STR _ATD0DR13;                            /* ATD 0 Conversion Result Register 13; 0x000002EA */
volatile ATD0DR14STR _ATD0DR14;                            /* ATD 0 Conversion Result Register 14; 0x000002EC */
volatile ATD0DR15STR _ATD0DR15;                            /* ATD 0 Conversion Result Register 15; 0x000002EE */
volatile VREGAPIRSTR _VREGAPIR;                            /* Autonomous Periodical Interrupt Rate Register; 0x000002F4 */
volatile PWMCNT01STR _PWMCNT01;                            /* PWM Channel Counter 01 Register; 0x0000030C */
volatile PWMCNT23STR _PWMCNT23;                            /* PWM Channel Counter 23 Register; 0x0000030E */
volatile PWMCNT45STR _PWMCNT45;                            /* PWM Channel Counter 45 Register; 0x00000310 */
volatile PWMCNT67STR _PWMCNT67;                            /* PWM Channel Counter 67 Register; 0x00000312 */
volatile PWMPER01STR _PWMPER01;                            /* PWM Channel Period 01 Register; 0x00000314 */
volatile PWMPER23STR _PWMPER23;                            /* PWM Channel Period 23 Register; 0x00000316 */
volatile PWMPER45STR _PWMPER45;                            /* PWM Channel Period 45 Register; 0x00000318 */
volatile PWMPER67STR _PWMPER67;                            /* PWM Channel Period 67 Register; 0x0000031A */
volatile PWMDTY01STR _PWMDTY01;                            /* PWM Channel Duty 01 Register; 0x0000031C */
volatile PWMDTY23STR _PWMDTY23;                            /* PWM Channel Duty 23 Register; 0x0000031E */
volatile PWMDTY45STR _PWMDTY45;                            /* PWM Channel Duty 45 Register; 0x00000320 */
volatile PWMDTY67STR _PWMDTY67;                            /* PWM Channel Duty 67 Register; 0x00000322 */
volatile PITLD0STR _PITLD0;                                /* PIT Load Register 0; 0x00000348 */
volatile PITCNT0STR _PITCNT0;                              /* PIT Count Register 0; 0x0000034A */
volatile PITLD1STR _PITLD1;                                /* PIT Load Register 1; 0x0000034C */
volatile PITCNT1STR _PITCNT1;                              /* PIT Count Register 1; 0x0000034E */
volatile PITLD2STR _PITLD2;                                /* PIT Load Register 2; 0x00000350 */
volatile PITCNT2STR _PITCNT2;                              /* PIT Count Register 2; 0x00000352 */
volatile PITLD3STR _PITLD3;                                /* PIT Load Register 3; 0x00000354 */
volatile PITCNT3STR _PITCNT3;                              /* PIT Count Register 3; 0x00000356 */
volatile XGMCTLSTR _XGMCTL;                                /* XGATE Control Register; 0x00000380 */
volatile XGISP31STR _XGISP31;                              /* XGATE Initial Stack Pointer for Interrupt Priorities 3 to 1; 0x00000386 */
volatile XGIF_7F_70STR _XGIF_7F_70;                        /* XGATE Channel Interrupt Flag Vector; 0x00000388 */
volatile XGIF_6F_60STR _XGIF_6F_60;                        /* XGATE Channel Interrupt Flag Vector; 0x0000038A */
volatile XGIF_5F_50STR _XGIF_5F_50;                        /* XGATE Channel Interrupt Flag Vector; 0x0000038C */
volatile XGIF_4F_40STR _XGIF_4F_40;                        /* XGATE Channel Interrupt Flag Vector; 0x0000038E */
volatile XGIF_3F_30STR _XGIF_3F_30;                        /* XGATE Channel Interrupt Flag Vector; 0x00000390 */
volatile XGIF_2F_20STR _XGIF_2F_20;                        /* XGATE Channel Interrupt Flag Vector; 0x00000392 */
volatile XGIF_1F_10STR _XGIF_1F_10;                        /* XGATE Channel Interrupt Flag Vector; 0x00000394 */
volatile XGIF_0F_00STR _XGIF_0F_00;                        /* XGATE Channel Interrupt Flag Vector; 0x00000396 */
volatile XGSWTSTR _XGSWT;                                  /* XGATE Control Register; 0x00000398 */
volatile XGSEMSTR _XGSEM;                                  /* XGATE Semaphore Register; 0x0000039A */
volatile XGPCSTR _XGPC;                                    /* XGATE Program Counter Register; 0x0000039E */
volatile XGR1STR _XGR1;                                    /* XGATE Register 1; 0x000003A2 */
volatile XGR2STR _XGR2;                                    /* XGATE Register 2; 0x000003A4 */
volatile XGR3STR _XGR3;                                    /* XGATE Register 3; 0x000003A6 */
volatile XGR4STR _XGR4;                                    /* XGATE Register 4; 0x000003A8 */
volatile XGR5STR _XGR5;                                    /* XGATE Register 5; 0x000003AA */
volatile XGR6STR _XGR6;                                    /* XGATE Register 6; 0x000003AC */
volatile XGR7STR _XGR7;                                    /* XGATE Register 7; 0x000003AE */
/* BAKEY0 - macro for reading non volatile register        Backdoor Comparison Key 0; 0x0000FF00 */
/* BAKEY1 - macro for reading non volatile register        Backdoor Comparison Key 1; 0x0000FF02 */
/* BAKEY2 - macro for reading non volatile register        Backdoor Comparison Key 2; 0x0000FF04 */
/* BAKEY3 - macro for reading non volatile register        Backdoor Comparison Key 3; 0x0000FF06 */

/*lint -restore */

/* EOF */
