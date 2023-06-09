/* Based on CPU DB MC9S12VR64_48, version 3.00.014 (RegistersPrg V2.33) */
/*
** ###################################################################
**     Filename  : mc9s12vr64.h
**     Processor : MC9S12VR64MLF
**     FileFormat: V2.33
**     DataSheet : MC9S12VRRMV3 Rev. 3.1 November 20, 2012
**     Compiler  : CodeWarrior compiler
**     Date/Time : 1/14/2013, 1:37 PM
**     Abstract  :
**         This header implements the mapping of I/O devices.
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
**
**     CPU Registers Revisions:
**      - 29.3.2011, V3.00.0:
**              - Corrected names of bits HSSR[HSOL1:0],HSIF[HSOCIF1:0].
**      - 30.6.2011, V3.00.1:
**              - Added registers for PWM channels 2-7. Added bit CSAD in register CPMUCLKS.
**              - Added bit BVLS[1] in register BATE. BVHS moved to register bit 6.
**              - Renamed routing register(PTTRR) to MODRR. Added bits PTADIRL,PTABYPL,PTPSL,PTTEL in register PTAL.
**      - 30.11.2011, V3.00.2:
**              - Renamed routing register PTSRR to MODRR2.
**      - 20.12.2011, V3.00.3:
**              - New features : SCI V6, OC_Masking on HSDRV, LINPHY V2 coresp to LIN spec 2.2
**
**     File-Format-Revisions:
**      - 15.09.2010, V2.33 :
**               - Empty union is not generated for data overlapping registers, cause there is no bit access
**
**     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
**     derivative device. To avoid extra current drain from floating input pins, the user�s reset
**     initialization routine in the application program must either enable on-chip pull-up devices
**     or change the direction of unconnected pins to outputs so the pins do not float.
** ###################################################################
*/

#ifndef _MC9S12VR64_H
#define _MC9S12VR64_H

/*lint -save  -e950 -esym(960,18.4) -e46 -esym(961,19.7) Disable MISRA rule (1.1,18.4,6.4,19.7) checking. */
/* Types definition */
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];

#define REG_BASE 0x0000                /* Base address for the I/O register block */


#pragma MESSAGE DISABLE C1106 /* WARNING C1106: Non-standard bitfield type */
#pragma OPTION ADD V30toV31Compatible "-BfaGapLimitBits4294967295" /*this guarantee correct bitfield positions*/

/**************** interrupt vector numbers ****************/
#define VectorNumber_Vsi                63U
#define VectorNumber_Vportad            62U
#define VectorNumber_Vatdcompare        61U
#define VectorNumber_Vhti               60U
#define VectorNumber_Vapi               59U
#define VectorNumber_Vlvi               58U
#define VectorNumber_Vportp2            57U
#define VectorNumber_Vportp             56U
#define VectorNumber_VReserved55        55U
#define VectorNumber_VReserved54        54U
#define VectorNumber_VReserved53        53U
#define VectorNumber_VReserved52        52U
#define VectorNumber_VReserved51        51U
#define VectorNumber_VReserved50        50U
#define VectorNumber_VReserved49        49U
#define VectorNumber_VReserved48        48U
#define VectorNumber_VReserved47        47U
#define VectorNumber_VReserved46        46U
#define VectorNumber_VReserved45        45U
#define VectorNumber_VReserved44        44U
#define VectorNumber_Vbats              43U
#define VectorNumber_Vlinphy            42U
#define VectorNumber_Vlsdrv             41U
#define VectorNumber_Vhsdrv             40U
#define VectorNumber_VReserved43        39U
#define VectorNumber_VReserved42        38U
#define VectorNumber_VReserved41        37U
#define VectorNumber_VReserved40        36U
#define VectorNumber_Vflash             35U
#define VectorNumber_Vflashfd           34U
#define VectorNumber_VReserved33        33U
#define VectorNumber_VReserved32        32U
#define VectorNumber_VReserved31        31U
#define VectorNumber_VReserved30        30U
#define VectorNumber_VReserved29        29U
#define VectorNumber_Vcpmuplllck        28U
#define VectorNumber_Vcpmuocsns         27U
#define VectorNumber_VReserved26        26U
#define VectorNumber_VReserved25        25U
#define VectorNumber_Vportl             24U
#define VectorNumber_VReserved23        23U
#define VectorNumber_Vatd               22U
#define VectorNumber_Vsci1              21U
#define VectorNumber_Vsci0              20U
#define VectorNumber_Vspi               19U
#define VectorNumber_VReserved18        18U
#define VectorNumber_VReserved17        17U
#define VectorNumber_Vtimovf            16U
#define VectorNumber_VReserved15        15U
#define VectorNumber_VReserved14        14U
#define VectorNumber_VReserved13        13U
#define VectorNumber_VReserved12        12U
#define VectorNumber_Vtimch3            11U
#define VectorNumber_Vtimch2            10U
#define VectorNumber_Vtimch1            9U
#define VectorNumber_Vtimch0            8U
#define VectorNumber_Vrti               7U
#define VectorNumber_Virq               6U
#define VectorNumber_Vxirq              5U
#define VectorNumber_Vswi               4U
#define VectorNumber_Vtrap              3U
#define VectorNumber_Vcop               2U
#define VectorNumber_Vclkmon            1U
#define VectorNumber_Vreset             0U

/**************** interrupt vector table ****************/
#define Vsi                             0xFF80U
#define Vportad                         0xFF82U
#define Vatdcompare                     0xFF84U
#define Vhti                            0xFF86U
#define Vapi                            0xFF88U
#define Vlvi                            0xFF8AU
#define Vportp2                         0xFF8CU
#define Vportp                          0xFF8EU
#define VReserved55                     0xFF90U
#define VReserved54                     0xFF92U
#define VReserved53                     0xFF94U
#define VReserved52                     0xFF96U
#define VReserved51                     0xFF98U
#define VReserved50                     0xFF9AU
#define VReserved49                     0xFF9CU
#define VReserved48                     0xFF9EU
#define VReserved47                     0xFFA0U
#define VReserved46                     0xFFA2U
#define VReserved45                     0xFFA4U
#define VReserved44                     0xFFA6U
#define Vbats                           0xFFA8U
#define Vlinphy                         0xFFAAU
#define Vlsdrv                          0xFFACU
#define Vhsdrv                          0xFFAEU
#define VReserved43                     0xFFB0U
#define VReserved42                     0xFFB2U
#define VReserved41                     0xFFB4U
#define VReserved40                     0xFFB6U
#define Vflash                          0xFFB8U
#define Vflashfd                        0xFFBAU
#define VReserved33                     0xFFBCU
#define VReserved32                     0xFFBEU
#define VReserved31                     0xFFC0U
#define VReserved30                     0xFFC2U
#define VReserved29                     0xFFC4U
#define Vcpmuplllck                     0xFFC6U
#define Vcpmuocsns                      0xFFC8U
#define VReserved26                     0xFFCAU
#define VReserved25                     0xFFCCU
#define Vportl                          0xFFCEU
#define VReserved23                     0xFFD0U
#define Vatd                            0xFFD2U
#define Vsci1                           0xFFD4U
#define Vsci0                           0xFFD6U
#define Vspi                            0xFFD8U
#define VReserved18                     0xFFDAU
#define VReserved17                     0xFFDCU
#define Vtimovf                         0xFFDEU
#define VReserved15                     0xFFE0U
#define VReserved14                     0xFFE2U
#define VReserved13                     0xFFE4U
#define VReserved12                     0xFFE6U
#define Vtimch3                         0xFFE8U
#define Vtimch2                         0xFFEAU
#define Vtimch1                         0xFFECU
#define Vtimch0                         0xFFEEU
#define Vrti                            0xFFF0U
#define Virq                            0xFFF2U
#define Vxirq                           0xFFF4U
#define Vswi                            0xFFF6U
#define Vtrap                           0xFFF8U
#define Vcop                            0xFFFAU
#define Vclkmon                         0xFFFCU
#define Vreset                          0xFFFEU

/**************** registers I/O map ****************/

/*** PORTE - Port E Data Register; 0x00000008 ***/
typedef union {
  byte Byte;
  struct {
    byte PE0         :1;                                       /* Port E Bit 0 */
    byte PE1         :1;                                       /* Port E Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPE   :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PORTESTR;
extern volatile PORTESTR _PORTE @(REG_BASE + 0x00000008UL);
#define PORTE                           _PORTE.Byte
#define PORTE_PE0                       _PORTE.Bits.PE0
#define PORTE_PE1                       _PORTE.Bits.PE1
#define PORTE_PE                        _PORTE.MergedBits.grpPE

#define PORTE_PE0_MASK                  1U
#define PORTE_PE1_MASK                  2U
#define PORTE_PE_MASK                   3U
#define PORTE_PE_BITNUM                 0U


/*** DDRE - Port E Data Direction Register; 0x00000009 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRE0       :1;                                       /* Data Direction Port E Bit 0 */
    byte DDRE1       :1;                                       /* Data Direction Port E Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDDRE :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DDRESTR;
extern volatile DDRESTR _DDRE @(REG_BASE + 0x00000009UL);
#define DDRE                            _DDRE.Byte
#define DDRE_DDRE0                      _DDRE.Bits.DDRE0
#define DDRE_DDRE1                      _DDRE.Bits.DDRE1
#define DDRE_DDRE                       _DDRE.MergedBits.grpDDRE

#define DDRE_DDRE0_MASK                 1U
#define DDRE_DDRE1_MASK                 2U
#define DDRE_DDRE_MASK                  3U
#define DDRE_DDRE_BITNUM                0U


/*** MODE - Mode Register; 0x0000000B ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODC        :1;                                       /* Mode Select Bit */
  } Bits;
} MODESTR;
extern volatile MODESTR _MODE @(REG_BASE + 0x0000000BUL);
#define MODE                            _MODE.Byte
#define MODE_MODC                       _MODE.Bits.MODC

#define MODE_MODC_MASK                  128U


/*** PUCR - Pull-Up Control Register; 0x0000000C ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PDPEE       :1;                                       /* Pull-up Port E Enable */
    byte             :1; 
    byte BKPUE       :1;                                       /* BKGD and VREGEN Pin Pull-up Enable */
    byte             :1; 
  } Bits;
} PUCRSTR;
extern volatile PUCRSTR _PUCR @(REG_BASE + 0x0000000CUL);
#define PUCR                            _PUCR.Byte
#define PUCR_PDPEE                      _PUCR.Bits.PDPEE
#define PUCR_BKPUE                      _PUCR.Bits.BKPUE

#define PUCR_PDPEE_MASK                 16U
#define PUCR_BKPUE_MASK                 64U


/*** DIRECT - Direct Page Register; 0x00000011 ***/
typedef union {
  byte Byte;
  struct {
    byte DP8         :1;                                       /* Direct Page Index Bit 8 */
    byte DP9         :1;                                       /* Direct Page Index Bit 9 */
    byte DP10        :1;                                       /* Direct Page Index Bit 10 */
    byte DP11        :1;                                       /* Direct Page Index Bit 11 */
    byte DP12        :1;                                       /* Direct Page Index Bit 12 */
    byte DP13        :1;                                       /* Direct Page Index Bit 13 */
    byte DP14        :1;                                       /* Direct Page Index Bit 14 */
    byte DP15        :1;                                       /* Direct Page Index Bit 15 */
  } Bits;
} DIRECTSTR;
extern volatile DIRECTSTR _DIRECT @(REG_BASE + 0x00000011UL);
#define DIRECT                          _DIRECT.Byte
#define DIRECT_DP8                      _DIRECT.Bits.DP8
#define DIRECT_DP9                      _DIRECT.Bits.DP9
#define DIRECT_DP10                     _DIRECT.Bits.DP10
#define DIRECT_DP11                     _DIRECT.Bits.DP11
#define DIRECT_DP12                     _DIRECT.Bits.DP12
#define DIRECT_DP13                     _DIRECT.Bits.DP13
#define DIRECT_DP14                     _DIRECT.Bits.DP14
#define DIRECT_DP15                     _DIRECT.Bits.DP15

#define DIRECT_DP8_MASK                 1U
#define DIRECT_DP9_MASK                 2U
#define DIRECT_DP10_MASK                4U
#define DIRECT_DP11_MASK                8U
#define DIRECT_DP12_MASK                16U
#define DIRECT_DP13_MASK                32U
#define DIRECT_DP14_MASK                64U
#define DIRECT_DP15_MASK                128U


/*** MMCCTL1 - MMC Control Register; 0x00000013 ***/
typedef union {
  byte Byte;
  struct {
    byte NVMRES      :1;                                       /* Map internal NVM resources into the global memory map */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} MMCCTL1STR;
extern volatile MMCCTL1STR _MMCCTL1 @(REG_BASE + 0x00000013UL);
#define MMCCTL1                         _MMCCTL1.Byte
#define MMCCTL1_NVMRES                  _MMCCTL1.Bits.NVMRES

#define MMCCTL1_NVMRES_MASK             1U


/*** PPAGE - Program Page Index Register; 0x00000015 ***/
typedef union {
  byte Byte;
  struct {
    byte PIX0        :1;                                       /* Program Page Index Bit 0 */
    byte PIX1        :1;                                       /* Program Page Index Bit 1 */
    byte PIX2        :1;                                       /* Program Page Index Bit 2 */
    byte PIX3        :1;                                       /* Program Page Index Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPIX  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPAGESTR;
extern volatile PPAGESTR _PPAGE @(REG_BASE + 0x00000015UL);
#define PPAGE                           _PPAGE.Byte
#define PPAGE_PIX0                      _PPAGE.Bits.PIX0
#define PPAGE_PIX1                      _PPAGE.Bits.PIX1
#define PPAGE_PIX2                      _PPAGE.Bits.PIX2
#define PPAGE_PIX3                      _PPAGE.Bits.PIX3
#define PPAGE_PIX                       _PPAGE.MergedBits.grpPIX

#define PPAGE_PIX0_MASK                 1U
#define PPAGE_PIX1_MASK                 2U
#define PPAGE_PIX2_MASK                 4U
#define PPAGE_PIX3_MASK                 8U
#define PPAGE_PIX_MASK                  15U
#define PPAGE_PIX_BITNUM                0U


/*** PARTID - Part ID Register; 0x0000001A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PARTIDH - Part ID Register High; 0x0000001A ***/
    union {
      byte Byte;
      struct {
        byte ID8         :1;                                       /* Part ID Register Bit 8 */
        byte ID9         :1;                                       /* Part ID Register Bit 9 */
        byte ID10        :1;                                       /* Part ID Register Bit 10 */
        byte ID11        :1;                                       /* Part ID Register Bit 11 */
        byte ID12        :1;                                       /* Part ID Register Bit 12 */
        byte ID13        :1;                                       /* Part ID Register Bit 13 */
        byte ID14        :1;                                       /* Part ID Register Bit 14 */
        byte ID15        :1;                                       /* Part ID Register Bit 15 */
      } Bits;
    } PARTIDHSTR;
    #define PARTIDH                     _PARTID.Overlap_STR.PARTIDHSTR.Byte
    #define PARTIDH_ID8                 _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID8
    #define PARTIDH_ID9                 _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID9
    #define PARTIDH_ID10                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID10
    #define PARTIDH_ID11                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID11
    #define PARTIDH_ID12                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID12
    #define PARTIDH_ID13                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID13
    #define PARTIDH_ID14                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID14
    #define PARTIDH_ID15                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID15
    
    #define PARTIDH_ID8_MASK            1U
    #define PARTIDH_ID9_MASK            2U
    #define PARTIDH_ID10_MASK           4U
    #define PARTIDH_ID11_MASK           8U
    #define PARTIDH_ID12_MASK           16U
    #define PARTIDH_ID13_MASK           32U
    #define PARTIDH_ID14_MASK           64U
    #define PARTIDH_ID15_MASK           128U
    

    /*** PARTIDL - Part ID Register Low; 0x0000001B ***/
    union {
      byte Byte;
      struct {
        byte ID0         :1;                                       /* Part ID Register Bit 0 */
        byte ID1         :1;                                       /* Part ID Register Bit 1 */
        byte ID2         :1;                                       /* Part ID Register Bit 2 */
        byte ID3         :1;                                       /* Part ID Register Bit 3 */
        byte ID4         :1;                                       /* Part ID Register Bit 4 */
        byte ID5         :1;                                       /* Part ID Register Bit 5 */
        byte ID6         :1;                                       /* Part ID Register Bit 6 */
        byte ID7         :1;                                       /* Part ID Register Bit 7 */
      } Bits;
    } PARTIDLSTR;
    #define PARTIDL                     _PARTID.Overlap_STR.PARTIDLSTR.Byte
    #define PARTIDL_ID0                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID0
    #define PARTIDL_ID1                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID1
    #define PARTIDL_ID2                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID2
    #define PARTIDL_ID3                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID3
    #define PARTIDL_ID4                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID4
    #define PARTIDL_ID5                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID5
    #define PARTIDL_ID6                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID6
    #define PARTIDL_ID7                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID7
    
    #define PARTIDL_ID0_MASK            1U
    #define PARTIDL_ID1_MASK            2U
    #define PARTIDL_ID2_MASK            4U
    #define PARTIDL_ID3_MASK            8U
    #define PARTIDL_ID4_MASK            16U
    #define PARTIDL_ID5_MASK            32U
    #define PARTIDL_ID6_MASK            64U
    #define PARTIDL_ID7_MASK            128U
    
  } Overlap_STR;

  struct {
    word ID0         :1;                                       /* Part ID Register Bit 0 */
    word ID1         :1;                                       /* Part ID Register Bit 1 */
    word ID2         :1;                                       /* Part ID Register Bit 2 */
    word ID3         :1;                                       /* Part ID Register Bit 3 */
    word ID4         :1;                                       /* Part ID Register Bit 4 */
    word ID5         :1;                                       /* Part ID Register Bit 5 */
    word ID6         :1;                                       /* Part ID Register Bit 6 */
    word ID7         :1;                                       /* Part ID Register Bit 7 */
    word ID8         :1;                                       /* Part ID Register Bit 8 */
    word ID9         :1;                                       /* Part ID Register Bit 9 */
    word ID10        :1;                                       /* Part ID Register Bit 10 */
    word ID11        :1;                                       /* Part ID Register Bit 11 */
    word ID12        :1;                                       /* Part ID Register Bit 12 */
    word ID13        :1;                                       /* Part ID Register Bit 13 */
    word ID14        :1;                                       /* Part ID Register Bit 14 */
    word ID15        :1;                                       /* Part ID Register Bit 15 */
  } Bits;
} PARTIDSTR;
extern volatile PARTIDSTR _PARTID @(REG_BASE + 0x0000001AUL);
#define PARTID                          _PARTID.Word
#define PARTID_ID0                      _PARTID.Bits.ID0
#define PARTID_ID1                      _PARTID.Bits.ID1
#define PARTID_ID2                      _PARTID.Bits.ID2
#define PARTID_ID3                      _PARTID.Bits.ID3
#define PARTID_ID4                      _PARTID.Bits.ID4
#define PARTID_ID5                      _PARTID.Bits.ID5
#define PARTID_ID6                      _PARTID.Bits.ID6
#define PARTID_ID7                      _PARTID.Bits.ID7
#define PARTID_ID8                      _PARTID.Bits.ID8
#define PARTID_ID9                      _PARTID.Bits.ID9
#define PARTID_ID10                     _PARTID.Bits.ID10
#define PARTID_ID11                     _PARTID.Bits.ID11
#define PARTID_ID12                     _PARTID.Bits.ID12
#define PARTID_ID13                     _PARTID.Bits.ID13
#define PARTID_ID14                     _PARTID.Bits.ID14
#define PARTID_ID15                     _PARTID.Bits.ID15

#define PARTID_ID0_MASK                 1U
#define PARTID_ID1_MASK                 2U
#define PARTID_ID2_MASK                 4U
#define PARTID_ID3_MASK                 8U
#define PARTID_ID4_MASK                 16U
#define PARTID_ID5_MASK                 32U
#define PARTID_ID6_MASK                 64U
#define PARTID_ID7_MASK                 128U
#define PARTID_ID8_MASK                 256U
#define PARTID_ID9_MASK                 512U
#define PARTID_ID10_MASK                1024U
#define PARTID_ID11_MASK                2048U
#define PARTID_ID12_MASK                4096U
#define PARTID_ID13_MASK                8192U
#define PARTID_ID14_MASK                16384U
#define PARTID_ID15_MASK                32768U


/*** ECLKCTL - ECLK Control Register; 0x0000001C ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte NECLK       :1;                                       /* No ECLK */
  } Bits;
} ECLKCTLSTR;
extern volatile ECLKCTLSTR _ECLKCTL @(REG_BASE + 0x0000001CUL);
#define ECLKCTL                         _ECLKCTL.Byte
#define ECLKCTL_NECLK                   _ECLKCTL.Bits.NECLK

#define ECLKCTL_NECLK_MASK              128U


/*** PIMMISC - PIM Miscellaneous Register; 0x0000001D ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte OCPE        :1;                                       /* Over-Current Protection Enable */
  } Bits;
} PIMMISCSTR;
extern volatile PIMMISCSTR _PIMMISC @(REG_BASE + 0x0000001DUL);
#define PIMMISC                         _PIMMISC.Byte
#define PIMMISC_OCPE                    _PIMMISC.Bits.OCPE

#define PIMMISC_OCPE_MASK               128U


/*** IRQCR - Interrupt Control Register; 0x0000001E ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte IRQEN       :1;                                       /* External IRQ Enable */
    byte IRQE        :1;                                       /* IRQ Select Edge Sensitive Only */
  } Bits;
} IRQCRSTR;
extern volatile IRQCRSTR _IRQCR @(REG_BASE + 0x0000001EUL);
#define IRQCR                           _IRQCR.Byte
#define IRQCR_IRQEN                     _IRQCR.Bits.IRQEN
#define IRQCR_IRQE                      _IRQCR.Bits.IRQE

#define IRQCR_IRQEN_MASK                64U
#define IRQCR_IRQE_MASK                 128U


/*** DBGC1 - Debug Control Register 1; 0x00000020 ***/
typedef union {
  byte Byte;
  struct {
    byte COMRV0      :1;                                       /* Comparator Register Visibility Bits, bit 0 */
    byte COMRV1      :1;                                       /* Comparator Register Visibility Bits, bit 1 */
    byte             :1; 
    byte DBGBRK      :1;                                       /* S12XDBG Breakpoint Enable Bit 1 */
    byte BDM         :1;                                       /* Background Debug Mode Enable */
    byte             :1; 
    byte TRIG        :1;                                       /* Immediate Trigger Request Bit */
    byte ARM         :1;                                       /* Arm Bit */
  } Bits;
  struct {
    byte grpCOMRV :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGC1STR;
extern volatile DBGC1STR _DBGC1 @(REG_BASE + 0x00000020UL);
#define DBGC1                           _DBGC1.Byte
#define DBGC1_COMRV0                    _DBGC1.Bits.COMRV0
#define DBGC1_COMRV1                    _DBGC1.Bits.COMRV1
#define DBGC1_DBGBRK                    _DBGC1.Bits.DBGBRK
#define DBGC1_BDM                       _DBGC1.Bits.BDM
#define DBGC1_TRIG                      _DBGC1.Bits.TRIG
#define DBGC1_ARM                       _DBGC1.Bits.ARM
#define DBGC1_COMRV                     _DBGC1.MergedBits.grpCOMRV

#define DBGC1_COMRV0_MASK               1U
#define DBGC1_COMRV1_MASK               2U
#define DBGC1_DBGBRK_MASK               8U
#define DBGC1_BDM_MASK                  16U
#define DBGC1_TRIG_MASK                 64U
#define DBGC1_ARM_MASK                  128U
#define DBGC1_COMRV_MASK                3U
#define DBGC1_COMRV_BITNUM              0U


/*** DBGSR - Debug Status Register; 0x00000021 ***/
typedef union {
  byte Byte;
  struct {
    byte SSF0        :1;                                       /* State Sequencer Flag Bits */
    byte SSF1        :1;                                       /* State Sequencer Flag Bit 1 */
    byte SSF2        :1;                                       /* State Sequencer Flag Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TBF         :1;                                       /* Trace Buffer Full */
  } Bits;
  struct {
    byte grpSSF  :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGSRSTR;
extern volatile DBGSRSTR _DBGSR @(REG_BASE + 0x00000021UL);
#define DBGSR                           _DBGSR.Byte
#define DBGSR_SSF0                      _DBGSR.Bits.SSF0
#define DBGSR_SSF1                      _DBGSR.Bits.SSF1
#define DBGSR_SSF2                      _DBGSR.Bits.SSF2
#define DBGSR_TBF                       _DBGSR.Bits.TBF
#define DBGSR_SSF                       _DBGSR.MergedBits.grpSSF

#define DBGSR_SSF0_MASK                 1U
#define DBGSR_SSF1_MASK                 2U
#define DBGSR_SSF2_MASK                 4U
#define DBGSR_TBF_MASK                  128U
#define DBGSR_SSF_MASK                  7U
#define DBGSR_SSF_BITNUM                0U


/*** DBGTCR - Debug Trace Control Register; 0x00000022 ***/
typedef union {
  byte Byte;
  struct {
    byte TALIGN      :1;                                       /* Trigger Align Bit */
    byte             :1; 
    byte TRCMOD0     :1;                                       /* Trace Mode Bits, bit 0 */
    byte TRCMOD1     :1;                                       /* Trace Mode Bits, bit 1 */
    byte             :1; 
    byte             :1; 
    byte TSOURCE     :1;                                       /* Trace Source Control Bits */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpTRCMOD :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGTCRSTR;
extern volatile DBGTCRSTR _DBGTCR @(REG_BASE + 0x00000022UL);
#define DBGTCR                          _DBGTCR.Byte
#define DBGTCR_TALIGN                   _DBGTCR.Bits.TALIGN
#define DBGTCR_TRCMOD0                  _DBGTCR.Bits.TRCMOD0
#define DBGTCR_TRCMOD1                  _DBGTCR.Bits.TRCMOD1
#define DBGTCR_TSOURCE                  _DBGTCR.Bits.TSOURCE
#define DBGTCR_TRCMOD                   _DBGTCR.MergedBits.grpTRCMOD

#define DBGTCR_TALIGN_MASK              1U
#define DBGTCR_TRCMOD0_MASK             4U
#define DBGTCR_TRCMOD1_MASK             8U
#define DBGTCR_TSOURCE_MASK             64U
#define DBGTCR_TRCMOD_MASK              12U
#define DBGTCR_TRCMOD_BITNUM            2U


/*** DBGC2 - Debug Control Register 2; 0x00000023 ***/
typedef union {
  byte Byte;
  struct {
    byte ABCM0       :1;                                       /* A and B Comparator Match Control, bit 0 */
    byte ABCM1       :1;                                       /* A and B Comparator Match Control, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpABCM :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGC2STR;
extern volatile DBGC2STR _DBGC2 @(REG_BASE + 0x00000023UL);
#define DBGC2                           _DBGC2.Byte
#define DBGC2_ABCM0                     _DBGC2.Bits.ABCM0
#define DBGC2_ABCM1                     _DBGC2.Bits.ABCM1
#define DBGC2_ABCM                      _DBGC2.MergedBits.grpABCM

#define DBGC2_ABCM0_MASK                1U
#define DBGC2_ABCM1_MASK                2U
#define DBGC2_ABCM_MASK                 3U
#define DBGC2_ABCM_BITNUM               0U


/*** DBGTB - Debug Trace Buffer Register; 0x00000024 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGTBH - Debug Trace Buffer Register High; 0x00000024 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Trace Buffer Data Bits */
        byte BIT9        :1;                                       /* Trace Buffer Data Bit 9 */
        byte BIT10       :1;                                       /* Trace Buffer Data Bit 10 */
        byte BIT11       :1;                                       /* Trace Buffer Data Bit 11 */
        byte BIT12       :1;                                       /* Trace Buffer Data Bit 12 */
        byte BIT13       :1;                                       /* Trace Buffer Data Bit 13 */
        byte BIT14       :1;                                       /* Trace Buffer Data Bit 14 */
        byte BIT15       :1;                                       /* Trace Buffer Data Bit 15 */
      } Bits;
    } DBGTBHSTR;
    #define DBGTBH                      _DBGTB.Overlap_STR.DBGTBHSTR.Byte
    #define DBGTBH_BIT8                 _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT8
    #define DBGTBH_BIT9                 _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT9
    #define DBGTBH_BIT10                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT10
    #define DBGTBH_BIT11                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT11
    #define DBGTBH_BIT12                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT12
    #define DBGTBH_BIT13                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT13
    #define DBGTBH_BIT14                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT14
    #define DBGTBH_BIT15                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT15
    
    #define DBGTBH_BIT8_MASK            1U
    #define DBGTBH_BIT9_MASK            2U
    #define DBGTBH_BIT10_MASK           4U
    #define DBGTBH_BIT11_MASK           8U
    #define DBGTBH_BIT12_MASK           16U
    #define DBGTBH_BIT13_MASK           32U
    #define DBGTBH_BIT14_MASK           64U
    #define DBGTBH_BIT15_MASK           128U
    

    /*** DBGTBL - Debug Trace Buffer Register Low; 0x00000025 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Trace Buffer Data Bits */
        byte BIT1        :1;                                       /* Trace Buffer Data Bit 1 */
        byte BIT2        :1;                                       /* Trace Buffer Data Bit 2 */
        byte BIT3        :1;                                       /* Trace Buffer Data Bit 3 */
        byte BIT4        :1;                                       /* Trace Buffer Data Bit 4 */
        byte BIT5        :1;                                       /* Trace Buffer Data Bit 5 */
        byte BIT6        :1;                                       /* Trace Buffer Data Bit 6 */
        byte BIT7        :1;                                       /* Trace Buffer Data Bit 7 */
      } Bits;
    } DBGTBLSTR;
    #define DBGTBL                      _DBGTB.Overlap_STR.DBGTBLSTR.Byte
    #define DBGTBL_BIT0                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT0
    #define DBGTBL_BIT1                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT1
    #define DBGTBL_BIT2                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT2
    #define DBGTBL_BIT3                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT3
    #define DBGTBL_BIT4                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT4
    #define DBGTBL_BIT5                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT5
    #define DBGTBL_BIT6                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT6
    #define DBGTBL_BIT7                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT7
    
    #define DBGTBL_BIT0_MASK            1U
    #define DBGTBL_BIT1_MASK            2U
    #define DBGTBL_BIT2_MASK            4U
    #define DBGTBL_BIT3_MASK            8U
    #define DBGTBL_BIT4_MASK            16U
    #define DBGTBL_BIT5_MASK            32U
    #define DBGTBL_BIT6_MASK            64U
    #define DBGTBL_BIT7_MASK            128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Trace Buffer Data Bits */
    word BIT1        :1;                                       /* Trace Buffer Data Bit 1 */
    word BIT2        :1;                                       /* Trace Buffer Data Bit 2 */
    word BIT3        :1;                                       /* Trace Buffer Data Bit 3 */
    word BIT4        :1;                                       /* Trace Buffer Data Bit 4 */
    word BIT5        :1;                                       /* Trace Buffer Data Bit 5 */
    word BIT6        :1;                                       /* Trace Buffer Data Bit 6 */
    word BIT7        :1;                                       /* Trace Buffer Data Bit 7 */
    word BIT8        :1;                                       /* Trace Buffer Data Bit 8 */
    word BIT9        :1;                                       /* Trace Buffer Data Bit 9 */
    word BIT10       :1;                                       /* Trace Buffer Data Bit 10 */
    word BIT11       :1;                                       /* Trace Buffer Data Bit 11 */
    word BIT12       :1;                                       /* Trace Buffer Data Bit 12 */
    word BIT13       :1;                                       /* Trace Buffer Data Bit 13 */
    word BIT14       :1;                                       /* Trace Buffer Data Bit 14 */
    word BIT15       :1;                                       /* Trace Buffer Data Bit 15 */
  } Bits;
} DBGTBSTR;
extern volatile DBGTBSTR _DBGTB @(REG_BASE + 0x00000024UL);
#define DBGTB                           _DBGTB.Word
#define DBGTB_BIT0                      _DBGTB.Bits.BIT0
#define DBGTB_BIT1                      _DBGTB.Bits.BIT1
#define DBGTB_BIT2                      _DBGTB.Bits.BIT2
#define DBGTB_BIT3                      _DBGTB.Bits.BIT3
#define DBGTB_BIT4                      _DBGTB.Bits.BIT4
#define DBGTB_BIT5                      _DBGTB.Bits.BIT5
#define DBGTB_BIT6                      _DBGTB.Bits.BIT6
#define DBGTB_BIT7                      _DBGTB.Bits.BIT7
#define DBGTB_BIT8                      _DBGTB.Bits.BIT8
#define DBGTB_BIT9                      _DBGTB.Bits.BIT9
#define DBGTB_BIT10                     _DBGTB.Bits.BIT10
#define DBGTB_BIT11                     _DBGTB.Bits.BIT11
#define DBGTB_BIT12                     _DBGTB.Bits.BIT12
#define DBGTB_BIT13                     _DBGTB.Bits.BIT13
#define DBGTB_BIT14                     _DBGTB.Bits.BIT14
#define DBGTB_BIT15                     _DBGTB.Bits.BIT15

#define DBGTB_BIT0_MASK                 1U
#define DBGTB_BIT1_MASK                 2U
#define DBGTB_BIT2_MASK                 4U
#define DBGTB_BIT3_MASK                 8U
#define DBGTB_BIT4_MASK                 16U
#define DBGTB_BIT5_MASK                 32U
#define DBGTB_BIT6_MASK                 64U
#define DBGTB_BIT7_MASK                 128U
#define DBGTB_BIT8_MASK                 256U
#define DBGTB_BIT9_MASK                 512U
#define DBGTB_BIT10_MASK                1024U
#define DBGTB_BIT11_MASK                2048U
#define DBGTB_BIT12_MASK                4096U
#define DBGTB_BIT13_MASK                8192U
#define DBGTB_BIT14_MASK                16384U
#define DBGTB_BIT15_MASK                32768U


/*** DBGCNT - Debug Count Register; 0x00000026 ***/
typedef union {
  byte Byte;
  struct {
    byte CNT0        :1;                                       /* Count Value, bit 0 */
    byte CNT1        :1;                                       /* Count Value, bit 1 */
    byte CNT2        :1;                                       /* Count Value, bit 2 */
    byte CNT3        :1;                                       /* Count Value, bit 3 */
    byte CNT4        :1;                                       /* Count Value, bit 4 */
    byte CNT5        :1;                                       /* Count Value, bit 5 */
    byte             :1; 
    byte TBF         :1;                                       /* Trace Buffer Full */
  } Bits;
  struct {
    byte grpCNT  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGCNTSTR;
extern volatile DBGCNTSTR _DBGCNT @(REG_BASE + 0x00000026UL);
#define DBGCNT                          _DBGCNT.Byte
#define DBGCNT_CNT0                     _DBGCNT.Bits.CNT0
#define DBGCNT_CNT1                     _DBGCNT.Bits.CNT1
#define DBGCNT_CNT2                     _DBGCNT.Bits.CNT2
#define DBGCNT_CNT3                     _DBGCNT.Bits.CNT3
#define DBGCNT_CNT4                     _DBGCNT.Bits.CNT4
#define DBGCNT_CNT5                     _DBGCNT.Bits.CNT5
#define DBGCNT_TBF                      _DBGCNT.Bits.TBF
#define DBGCNT_CNT                      _DBGCNT.MergedBits.grpCNT

#define DBGCNT_CNT0_MASK                1U
#define DBGCNT_CNT1_MASK                2U
#define DBGCNT_CNT2_MASK                4U
#define DBGCNT_CNT3_MASK                8U
#define DBGCNT_CNT4_MASK                16U
#define DBGCNT_CNT5_MASK                32U
#define DBGCNT_TBF_MASK                 128U
#define DBGCNT_CNT_MASK                 63U
#define DBGCNT_CNT_BITNUM               0U


/*** DBGSCRX - Debug State Control Register; 0x00000027 ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** DBGSCRX - Debug State Control Register; Several registers at the same address ***/
    union {
      struct {
        byte SC0         :1;                                       /* State X Sequencer Next State Selection Bit 0 */
        byte SC1         :1;                                       /* State X Sequencer Next State Selection Bit 1 */
        byte SC2         :1;                                       /* State X Sequencer Next State Selection Bit 2 */
        byte SC3         :1;                                       /* State X Sequencer Next State Selection Bit 3 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpSC :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DBGSCRXSTR;
    #define DBGSCRX                     _DBGSCRX.Byte
    #define DBGSCRX_SC0                 _DBGSCRX.SameAddr_STR.DBGSCRXSTR.Bits.SC0
    #define DBGSCRX_SC1                 _DBGSCRX.SameAddr_STR.DBGSCRXSTR.Bits.SC1
    #define DBGSCRX_SC2                 _DBGSCRX.SameAddr_STR.DBGSCRXSTR.Bits.SC2
    #define DBGSCRX_SC3                 _DBGSCRX.SameAddr_STR.DBGSCRXSTR.Bits.SC3
    #define DBGSCRX_SC                  _DBGSCRX.SameAddr_STR.DBGSCRXSTR.MergedBits.grpSC
    
    #define DBGSCRX_SC0_MASK            1U
    #define DBGSCRX_SC1_MASK            2U
    #define DBGSCRX_SC2_MASK            4U
    #define DBGSCRX_SC3_MASK            8U
    #define DBGSCRX_SC_MASK             15U
    #define DBGSCRX_SC_BITNUM           0U
    
    /*** DBGMFR - Debug Match Flag Register; Several registers at the same address ***/
    union {
      struct {
        byte MC0         :1;                                       /* Debug Match Flag Bit 0 */
        byte MC1         :1;                                       /* Debug Match Flag Bit 1 */
        byte MC2         :1;                                       /* Debug Match Flag Bit 2 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpMC :3;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DBGMFRSTR;
    #define DBGMFR                      _DBGSCRX.Byte
    #define DBGMFR_MC0                  _DBGSCRX.SameAddr_STR.DBGMFRSTR.Bits.MC0
    #define DBGMFR_MC1                  _DBGSCRX.SameAddr_STR.DBGMFRSTR.Bits.MC1
    #define DBGMFR_MC2                  _DBGSCRX.SameAddr_STR.DBGMFRSTR.Bits.MC2
    #define DBGMFR_MC                   _DBGSCRX.SameAddr_STR.DBGMFRSTR.MergedBits.grpMC
    
    #define DBGMFR_MC0_MASK             1U
    #define DBGMFR_MC1_MASK             2U
    #define DBGMFR_MC2_MASK             4U
    #define DBGMFR_MC_MASK              7U
    #define DBGMFR_MC_BITNUM            0U
    
  } SameAddr_STR; /*Several registers at the same address */

} DBGSCRXSTR;
extern volatile DBGSCRXSTR _DBGSCRX @(REG_BASE + 0x00000027UL);


/*** DBGXCTL - Debug Comparator Control Register; 0x00000028 ***/
typedef union {
  byte Byte;
  struct {
    byte COMPE       :1;                                       /* Determines if comparator is enabled */
    byte NDB         :1;                                       /* Not Data Bus(Comparators A and C), Size Comparator Value Bit(Comparators B and D) */
    byte RWE         :1;                                       /* Read/Write Enable Bit */
    byte RW          :1;                                       /* Read/Write Comparator Value Bit */
    byte BRK         :1;                                       /* Break */
    byte TAG         :1;                                       /* Tag Select */
    byte SZ          :1;                                       /* Size Comparator Value Bit */
    byte SZE         :1;                                       /* Size Comparator Enable Bit */
  } Bits;
} DBGXCTLSTR;
extern volatile DBGXCTLSTR _DBGXCTL @(REG_BASE + 0x00000028UL);
#define DBGXCTL                         _DBGXCTL.Byte
#define DBGXCTL_COMPE                   _DBGXCTL.Bits.COMPE
#define DBGXCTL_NDB                     _DBGXCTL.Bits.NDB
#define DBGXCTL_RWE                     _DBGXCTL.Bits.RWE
#define DBGXCTL_RW                      _DBGXCTL.Bits.RW
#define DBGXCTL_BRK                     _DBGXCTL.Bits.BRK
#define DBGXCTL_TAG                     _DBGXCTL.Bits.TAG
#define DBGXCTL_SZ                      _DBGXCTL.Bits.SZ
#define DBGXCTL_SZE                     _DBGXCTL.Bits.SZE

#define DBGXCTL_COMPE_MASK              1U
#define DBGXCTL_NDB_MASK                2U
#define DBGXCTL_RWE_MASK                4U
#define DBGXCTL_RW_MASK                 8U
#define DBGXCTL_BRK_MASK                16U
#define DBGXCTL_TAG_MASK                32U
#define DBGXCTL_SZ_MASK                 64U
#define DBGXCTL_SZE_MASK                128U


/*** DBGXAH - Debug Comparator Address High Register; 0x00000029 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT16       :1;                                       /* Comparator Address High Compare Bits */
    byte BIT17       :1;                                       /* Comparator Address High Compare Bit 17 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpBIT_16 :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGXAHSTR;
extern volatile DBGXAHSTR _DBGXAH @(REG_BASE + 0x00000029UL);
#define DBGXAH                          _DBGXAH.Byte
#define DBGXAH_BIT16                    _DBGXAH.Bits.BIT16
#define DBGXAH_BIT17                    _DBGXAH.Bits.BIT17
#define DBGXAH_BIT_16                   _DBGXAH.MergedBits.grpBIT_16
#define DBGXAH_BIT                      DBGXAH_BIT_16

#define DBGXAH_BIT16_MASK               1U
#define DBGXAH_BIT17_MASK               2U
#define DBGXAH_BIT_16_MASK              3U
#define DBGXAH_BIT_16_BITNUM            0U


/*** DBGXAM - Debug Comparator Address Mid Register; 0x0000002A ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* Comparator Address Mid Compare Bits */
    byte BIT9        :1;                                       /* Comparator Address Mid Compare Bit 9 */
    byte BIT10       :1;                                       /* Comparator Address Mid Compare Bit 10 */
    byte BIT11       :1;                                       /* Comparator Address Mid Compare Bit 11 */
    byte BIT12       :1;                                       /* Comparator Address Mid Compare Bit 12 */
    byte BIT13       :1;                                       /* Comparator Address Mid Compare Bit 13 */
    byte BIT14       :1;                                       /* Comparator Address Mid Compare Bit 14 */
    byte BIT15       :1;                                       /* Comparator Address Mid Compare Bit 15 */
  } Bits;
} DBGXAMSTR;
extern volatile DBGXAMSTR _DBGXAM @(REG_BASE + 0x0000002AUL);
#define DBGXAM                          _DBGXAM.Byte
#define DBGXAM_BIT8                     _DBGXAM.Bits.BIT8
#define DBGXAM_BIT9                     _DBGXAM.Bits.BIT9
#define DBGXAM_BIT10                    _DBGXAM.Bits.BIT10
#define DBGXAM_BIT11                    _DBGXAM.Bits.BIT11
#define DBGXAM_BIT12                    _DBGXAM.Bits.BIT12
#define DBGXAM_BIT13                    _DBGXAM.Bits.BIT13
#define DBGXAM_BIT14                    _DBGXAM.Bits.BIT14
#define DBGXAM_BIT15                    _DBGXAM.Bits.BIT15

#define DBGXAM_BIT8_MASK                1U
#define DBGXAM_BIT9_MASK                2U
#define DBGXAM_BIT10_MASK               4U
#define DBGXAM_BIT11_MASK               8U
#define DBGXAM_BIT12_MASK               16U
#define DBGXAM_BIT13_MASK               32U
#define DBGXAM_BIT14_MASK               64U
#define DBGXAM_BIT15_MASK               128U


/*** DBGXAL - Debug Comparator Address Low Register; 0x0000002B ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Comparator Address Low Compare Bits */
    byte BIT1        :1;                                       /* Comparator Address Low Compare Bit 1 */
    byte BIT2        :1;                                       /* Comparator Address Low Compare Bit 2 */
    byte BIT3        :1;                                       /* Comparator Address Low Compare Bit 3 */
    byte BIT4        :1;                                       /* Comparator Address Low Compare Bit 4 */
    byte BIT5        :1;                                       /* Comparator Address Low Compare Bit 5 */
    byte BIT6        :1;                                       /* Comparator Address Low Compare Bit 6 */
    byte BIT7        :1;                                       /* Comparator Address Low Compare Bit 7 */
  } Bits;
} DBGXALSTR;
extern volatile DBGXALSTR _DBGXAL @(REG_BASE + 0x0000002BUL);
#define DBGXAL                          _DBGXAL.Byte
#define DBGXAL_BIT0                     _DBGXAL.Bits.BIT0
#define DBGXAL_BIT1                     _DBGXAL.Bits.BIT1
#define DBGXAL_BIT2                     _DBGXAL.Bits.BIT2
#define DBGXAL_BIT3                     _DBGXAL.Bits.BIT3
#define DBGXAL_BIT4                     _DBGXAL.Bits.BIT4
#define DBGXAL_BIT5                     _DBGXAL.Bits.BIT5
#define DBGXAL_BIT6                     _DBGXAL.Bits.BIT6
#define DBGXAL_BIT7                     _DBGXAL.Bits.BIT7

#define DBGXAL_BIT0_MASK                1U
#define DBGXAL_BIT1_MASK                2U
#define DBGXAL_BIT2_MASK                4U
#define DBGXAL_BIT3_MASK                8U
#define DBGXAL_BIT4_MASK                16U
#define DBGXAL_BIT5_MASK                32U
#define DBGXAL_BIT6_MASK                64U
#define DBGXAL_BIT7_MASK                128U


/*** DBGADH - Debug Comparator Data High Register; 0x0000002C ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* Comparator Data High Compare Bit 8 */
    byte BIT9        :1;                                       /* Comparator Data High Compare Bit 9 */
    byte BIT10       :1;                                       /* Comparator Data High Compare Bit 10 */
    byte BIT11       :1;                                       /* Comparator Data High Compare Bit 11 */
    byte BIT12       :1;                                       /* Comparator Data High Compare Bit 12 */
    byte BIT13       :1;                                       /* Comparator Data High Compare Bit 13 */
    byte BIT14       :1;                                       /* Comparator Data High Compare Bit 14 */
    byte BIT15       :1;                                       /* Comparator Data High Compare Bit 15 */
  } Bits;
} DBGADHSTR;
extern volatile DBGADHSTR _DBGADH @(REG_BASE + 0x0000002CUL);
#define DBGADH                          _DBGADH.Byte
#define DBGADH_BIT8                     _DBGADH.Bits.BIT8
#define DBGADH_BIT9                     _DBGADH.Bits.BIT9
#define DBGADH_BIT10                    _DBGADH.Bits.BIT10
#define DBGADH_BIT11                    _DBGADH.Bits.BIT11
#define DBGADH_BIT12                    _DBGADH.Bits.BIT12
#define DBGADH_BIT13                    _DBGADH.Bits.BIT13
#define DBGADH_BIT14                    _DBGADH.Bits.BIT14
#define DBGADH_BIT15                    _DBGADH.Bits.BIT15

#define DBGADH_BIT8_MASK                1U
#define DBGADH_BIT9_MASK                2U
#define DBGADH_BIT10_MASK               4U
#define DBGADH_BIT11_MASK               8U
#define DBGADH_BIT12_MASK               16U
#define DBGADH_BIT13_MASK               32U
#define DBGADH_BIT14_MASK               64U
#define DBGADH_BIT15_MASK               128U


/*** DBGADL - Debug Comparator Data Low Register; 0x0000002D ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Comparator Data Low Compare Bit 0 */
    byte BIT1        :1;                                       /* Comparator Data Low Compare Bit 1 */
    byte BIT2        :1;                                       /* Comparator Data Low Compare Bit 2 */
    byte BIT3        :1;                                       /* Comparator Data Low Compare Bit 3 */
    byte BIT4        :1;                                       /* Comparator Data Low Compare Bit 4 */
    byte BIT5        :1;                                       /* Comparator Data Low Compare Bit 5 */
    byte BIT6        :1;                                       /* Comparator Data Low Compare Bit 6 */
    byte BIT7        :1;                                       /* Comparator Data Low Compare Bit 7 */
  } Bits;
} DBGADLSTR;
extern volatile DBGADLSTR _DBGADL @(REG_BASE + 0x0000002DUL);
#define DBGADL                          _DBGADL.Byte
#define DBGADL_BIT0                     _DBGADL.Bits.BIT0
#define DBGADL_BIT1                     _DBGADL.Bits.BIT1
#define DBGADL_BIT2                     _DBGADL.Bits.BIT2
#define DBGADL_BIT3                     _DBGADL.Bits.BIT3
#define DBGADL_BIT4                     _DBGADL.Bits.BIT4
#define DBGADL_BIT5                     _DBGADL.Bits.BIT5
#define DBGADL_BIT6                     _DBGADL.Bits.BIT6
#define DBGADL_BIT7                     _DBGADL.Bits.BIT7

#define DBGADL_BIT0_MASK                1U
#define DBGADL_BIT1_MASK                2U
#define DBGADL_BIT2_MASK                4U
#define DBGADL_BIT3_MASK                8U
#define DBGADL_BIT4_MASK                16U
#define DBGADL_BIT5_MASK                32U
#define DBGADL_BIT6_MASK                64U
#define DBGADL_BIT7_MASK                128U


/*** DBGADHM - Debug Comparator Data High Mask Register; 0x0000002E ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* Comparator Data High Mask Bit 8 */
    byte BIT9        :1;                                       /* Comparator Data High Mask Bit 9 */
    byte BIT10       :1;                                       /* Comparator Data High Mask Bit 10 */
    byte BIT11       :1;                                       /* Comparator Data High Mask Bit 11 */
    byte BIT12       :1;                                       /* Comparator Data High Mask Bit 12 */
    byte BIT13       :1;                                       /* Comparator Data High Mask Bit 13 */
    byte BIT14       :1;                                       /* Comparator Data High Mask Bit 14 */
    byte BIT15       :1;                                       /* Comparator Data High Mask Bit 15 */
  } Bits;
} DBGADHMSTR;
extern volatile DBGADHMSTR _DBGADHM @(REG_BASE + 0x0000002EUL);
#define DBGADHM                         _DBGADHM.Byte
#define DBGADHM_BIT8                    _DBGADHM.Bits.BIT8
#define DBGADHM_BIT9                    _DBGADHM.Bits.BIT9
#define DBGADHM_BIT10                   _DBGADHM.Bits.BIT10
#define DBGADHM_BIT11                   _DBGADHM.Bits.BIT11
#define DBGADHM_BIT12                   _DBGADHM.Bits.BIT12
#define DBGADHM_BIT13                   _DBGADHM.Bits.BIT13
#define DBGADHM_BIT14                   _DBGADHM.Bits.BIT14
#define DBGADHM_BIT15                   _DBGADHM.Bits.BIT15

#define DBGADHM_BIT8_MASK               1U
#define DBGADHM_BIT9_MASK               2U
#define DBGADHM_BIT10_MASK              4U
#define DBGADHM_BIT11_MASK              8U
#define DBGADHM_BIT12_MASK              16U
#define DBGADHM_BIT13_MASK              32U
#define DBGADHM_BIT14_MASK              64U
#define DBGADHM_BIT15_MASK              128U


/*** DBGADLM - Debug Comparator Data Low Mask Register; 0x0000002F ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Comparator Data Low Mask Bit 0 */
    byte BIT1        :1;                                       /* Comparator Data Low Mask Bit 1 */
    byte BIT2        :1;                                       /* Comparator Data Low Mask Bit 2 */
    byte BIT3        :1;                                       /* Comparator Data Low Mask Bit 3 */
    byte BIT4        :1;                                       /* Comparator Data Low Mask Bit 4 */
    byte BIT5        :1;                                       /* Comparator Data Low Mask Bit 5 */
    byte BIT6        :1;                                       /* Comparator Data Low Mask Bit 6 */
    byte BIT7        :1;                                       /* Comparator Data Low Mask Bit 7 */
  } Bits;
} DBGADLMSTR;
extern volatile DBGADLMSTR _DBGADLM @(REG_BASE + 0x0000002FUL);
#define DBGADLM                         _DBGADLM.Byte
#define DBGADLM_BIT0                    _DBGADLM.Bits.BIT0
#define DBGADLM_BIT1                    _DBGADLM.Bits.BIT1
#define DBGADLM_BIT2                    _DBGADLM.Bits.BIT2
#define DBGADLM_BIT3                    _DBGADLM.Bits.BIT3
#define DBGADLM_BIT4                    _DBGADLM.Bits.BIT4
#define DBGADLM_BIT5                    _DBGADLM.Bits.BIT5
#define DBGADLM_BIT6                    _DBGADLM.Bits.BIT6
#define DBGADLM_BIT7                    _DBGADLM.Bits.BIT7

#define DBGADLM_BIT0_MASK               1U
#define DBGADLM_BIT1_MASK               2U
#define DBGADLM_BIT2_MASK               4U
#define DBGADLM_BIT3_MASK               8U
#define DBGADLM_BIT4_MASK               16U
#define DBGADLM_BIT5_MASK               32U
#define DBGADLM_BIT6_MASK               64U
#define DBGADLM_BIT7_MASK               128U


/*** CPMUSYNR - S12CPMU Synthesizer Register; 0x00000034 ***/
typedef union {
  byte Byte;
  struct {
    byte SYNDIV0     :1;                                       /* Multiplication factor of the IPLL bit 0 */
    byte SYNDIV1     :1;                                       /* Multiplication factor of the IPLL bit 1 */
    byte SYNDIV2     :1;                                       /* Multiplication factor of the IPLL bit 2 */
    byte SYNDIV3     :1;                                       /* Multiplication factor of the IPLL bit 3 */
    byte SYNDIV4     :1;                                       /* Multiplication factor of the IPLL bit 4 */
    byte SYNDIV5     :1;                                       /* Multiplication factor of the IPLL bit 5 */
    byte VCOFRQ0     :1;                                       /* VCO frequency range bit 0 */
    byte VCOFRQ1     :1;                                       /* VCO frequency range bit 1 */
  } Bits;
  struct {
    byte grpSYNDIV :6;
    byte grpVCOFRQ :2;
  } MergedBits;
} CPMUSYNRSTR;
extern volatile CPMUSYNRSTR _CPMUSYNR @(REG_BASE + 0x00000034UL);
#define CPMUSYNR                        _CPMUSYNR.Byte
#define CPMUSYNR_SYNDIV0                _CPMUSYNR.Bits.SYNDIV0
#define CPMUSYNR_SYNDIV1                _CPMUSYNR.Bits.SYNDIV1
#define CPMUSYNR_SYNDIV2                _CPMUSYNR.Bits.SYNDIV2
#define CPMUSYNR_SYNDIV3                _CPMUSYNR.Bits.SYNDIV3
#define CPMUSYNR_SYNDIV4                _CPMUSYNR.Bits.SYNDIV4
#define CPMUSYNR_SYNDIV5                _CPMUSYNR.Bits.SYNDIV5
#define CPMUSYNR_VCOFRQ0                _CPMUSYNR.Bits.VCOFRQ0
#define CPMUSYNR_VCOFRQ1                _CPMUSYNR.Bits.VCOFRQ1
#define CPMUSYNR_SYNDIV                 _CPMUSYNR.MergedBits.grpSYNDIV
#define CPMUSYNR_VCOFRQ                 _CPMUSYNR.MergedBits.grpVCOFRQ

#define CPMUSYNR_SYNDIV0_MASK           1U
#define CPMUSYNR_SYNDIV1_MASK           2U
#define CPMUSYNR_SYNDIV2_MASK           4U
#define CPMUSYNR_SYNDIV3_MASK           8U
#define CPMUSYNR_SYNDIV4_MASK           16U
#define CPMUSYNR_SYNDIV5_MASK           32U
#define CPMUSYNR_VCOFRQ0_MASK           64U
#define CPMUSYNR_VCOFRQ1_MASK           128U
#define CPMUSYNR_SYNDIV_MASK            63U
#define CPMUSYNR_SYNDIV_BITNUM          0U
#define CPMUSYNR_VCOFRQ_MASK            192U
#define CPMUSYNR_VCOFRQ_BITNUM          6U


/*** CPMUREFDIV - S12CPMU Reference Divider Register; 0x00000035 ***/
typedef union {
  byte Byte;
  struct {
    byte REFDIV0     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 0 */
    byte REFDIV1     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 1 */
    byte REFDIV2     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 2 */
    byte REFDIV3     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 3 */
    byte             :1; 
    byte             :1; 
    byte REFFRQ0     :1;                                       /* IPLL optimal stability and lock time configuration bit 0 */
    byte REFFRQ1     :1;                                       /* IPLL optimal stability and lock time configuration bit 1 */
  } Bits;
  struct {
    byte grpREFDIV :4;
    byte         :1;
    byte         :1;
    byte grpREFFRQ :2;
  } MergedBits;
} CPMUREFDIVSTR;
extern volatile CPMUREFDIVSTR _CPMUREFDIV @(REG_BASE + 0x00000035UL);
#define CPMUREFDIV                      _CPMUREFDIV.Byte
#define CPMUREFDIV_REFDIV0              _CPMUREFDIV.Bits.REFDIV0
#define CPMUREFDIV_REFDIV1              _CPMUREFDIV.Bits.REFDIV1
#define CPMUREFDIV_REFDIV2              _CPMUREFDIV.Bits.REFDIV2
#define CPMUREFDIV_REFDIV3              _CPMUREFDIV.Bits.REFDIV3
#define CPMUREFDIV_REFFRQ0              _CPMUREFDIV.Bits.REFFRQ0
#define CPMUREFDIV_REFFRQ1              _CPMUREFDIV.Bits.REFFRQ1
#define CPMUREFDIV_REFDIV               _CPMUREFDIV.MergedBits.grpREFDIV
#define CPMUREFDIV_REFFRQ               _CPMUREFDIV.MergedBits.grpREFFRQ

#define CPMUREFDIV_REFDIV0_MASK         1U
#define CPMUREFDIV_REFDIV1_MASK         2U
#define CPMUREFDIV_REFDIV2_MASK         4U
#define CPMUREFDIV_REFDIV3_MASK         8U
#define CPMUREFDIV_REFFRQ0_MASK         64U
#define CPMUREFDIV_REFFRQ1_MASK         128U
#define CPMUREFDIV_REFDIV_MASK          15U
#define CPMUREFDIV_REFDIV_BITNUM        0U
#define CPMUREFDIV_REFFRQ_MASK          192U
#define CPMUREFDIV_REFFRQ_BITNUM        6U


/*** CPMUPOSTDIV - S12CPMU Post Divider Register; 0x00000036 ***/
typedef union {
  byte Byte;
  struct {
    byte POSTDIV0    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 0 */
    byte POSTDIV1    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 1 */
    byte POSTDIV2    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 2 */
    byte POSTDIV3    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 3 */
    byte POSTDIV4    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPOSTDIV :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CPMUPOSTDIVSTR;
extern volatile CPMUPOSTDIVSTR _CPMUPOSTDIV @(REG_BASE + 0x00000036UL);
#define CPMUPOSTDIV                     _CPMUPOSTDIV.Byte
#define CPMUPOSTDIV_POSTDIV0            _CPMUPOSTDIV.Bits.POSTDIV0
#define CPMUPOSTDIV_POSTDIV1            _CPMUPOSTDIV.Bits.POSTDIV1
#define CPMUPOSTDIV_POSTDIV2            _CPMUPOSTDIV.Bits.POSTDIV2
#define CPMUPOSTDIV_POSTDIV3            _CPMUPOSTDIV.Bits.POSTDIV3
#define CPMUPOSTDIV_POSTDIV4            _CPMUPOSTDIV.Bits.POSTDIV4
#define CPMUPOSTDIV_POSTDIV             _CPMUPOSTDIV.MergedBits.grpPOSTDIV

#define CPMUPOSTDIV_POSTDIV0_MASK       1U
#define CPMUPOSTDIV_POSTDIV1_MASK       2U
#define CPMUPOSTDIV_POSTDIV2_MASK       4U
#define CPMUPOSTDIV_POSTDIV3_MASK       8U
#define CPMUPOSTDIV_POSTDIV4_MASK       16U
#define CPMUPOSTDIV_POSTDIV_MASK        31U
#define CPMUPOSTDIV_POSTDIV_BITNUM      0U


/*** CPMUFLG - S12CPMU Flags Register; 0x00000037 ***/
typedef union {
  byte Byte;
  struct {
    byte UPOSC       :1;                                       /* Oscillator Status Bit */
    byte OSCIF       :1;                                       /* Oscillator Interrupt Flag */
    byte ILAF        :1;                                       /* Illegal Address Reset Flag */
    byte LOCK        :1;                                       /* Lock Status Bit */
    byte LOCKIF      :1;                                       /* IPLL Lock Interrupt Flag */
    byte LVRF        :1;                                       /* Low Voltage Reset Flag */
    byte PORF        :1;                                       /* Power on Reset Flag */
    byte RTIF        :1;                                       /* Real Time Interrupt Flag */
  } Bits;
} CPMUFLGSTR;
extern volatile CPMUFLGSTR _CPMUFLG @(REG_BASE + 0x00000037UL);
#define CPMUFLG                         _CPMUFLG.Byte
#define CPMUFLG_UPOSC                   _CPMUFLG.Bits.UPOSC
#define CPMUFLG_OSCIF                   _CPMUFLG.Bits.OSCIF
#define CPMUFLG_ILAF                    _CPMUFLG.Bits.ILAF
#define CPMUFLG_LOCK                    _CPMUFLG.Bits.LOCK
#define CPMUFLG_LOCKIF                  _CPMUFLG.Bits.LOCKIF
#define CPMUFLG_LVRF                    _CPMUFLG.Bits.LVRF
#define CPMUFLG_PORF                    _CPMUFLG.Bits.PORF
#define CPMUFLG_RTIF                    _CPMUFLG.Bits.RTIF

#define CPMUFLG_UPOSC_MASK              1U
#define CPMUFLG_OSCIF_MASK              2U
#define CPMUFLG_ILAF_MASK               4U
#define CPMUFLG_LOCK_MASK               8U
#define CPMUFLG_LOCKIF_MASK             16U
#define CPMUFLG_LVRF_MASK               32U
#define CPMUFLG_PORF_MASK               64U
#define CPMUFLG_RTIF_MASK               128U


/*** CPMUINT - S12CPMU Interrupt Enable Register; 0x00000038 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte OSCIE       :1;                                       /* Oscillator Corrupt Interrupt Enable Bit */
    byte             :1; 
    byte             :1; 
    byte LOCKIE      :1;                                       /* Lock Interrupt Enable Bit */
    byte             :1; 
    byte             :1; 
    byte RTIE        :1;                                       /* Real Time Interrupt Enable Bit */
  } Bits;
} CPMUINTSTR;
extern volatile CPMUINTSTR _CPMUINT @(REG_BASE + 0x00000038UL);
#define CPMUINT                         _CPMUINT.Byte
#define CPMUINT_OSCIE                   _CPMUINT.Bits.OSCIE
#define CPMUINT_LOCKIE                  _CPMUINT.Bits.LOCKIE
#define CPMUINT_RTIE                    _CPMUINT.Bits.RTIE

#define CPMUINT_OSCIE_MASK              2U
#define CPMUINT_LOCKIE_MASK             16U
#define CPMUINT_RTIE_MASK               128U


/*** CPMUCLKS - S12CPMU Clock Select Register; 0x00000039 ***/
typedef union {
  byte Byte;
  struct {
    byte COPOSCSEL0  :1;                                       /* COP Clock Select 0 */
    byte RTIOSCSEL   :1;                                       /* RTI Clock Select */
    byte PCE         :1;                                       /* COP Enable During Pseudo Stop Bit */
    byte PRE         :1;                                       /* RTI Enable During Pseudo Stop Bit */
    byte COPOSCSEL1  :1;                                       /* COP Clock Select 1 */
    byte CSAD        :1;                                       /* COP in Stop Mode ACLK Disable */
    byte PSTP        :1;                                       /* Pseudo Stop Bit */
    byte PLLSEL      :1;                                       /* PLL Select Bit */
  } Bits;
} CPMUCLKSSTR;
extern volatile CPMUCLKSSTR _CPMUCLKS @(REG_BASE + 0x00000039UL);
#define CPMUCLKS                        _CPMUCLKS.Byte
#define CPMUCLKS_COPOSCSEL0             _CPMUCLKS.Bits.COPOSCSEL0
#define CPMUCLKS_RTIOSCSEL              _CPMUCLKS.Bits.RTIOSCSEL
#define CPMUCLKS_PCE                    _CPMUCLKS.Bits.PCE
#define CPMUCLKS_PRE                    _CPMUCLKS.Bits.PRE
#define CPMUCLKS_COPOSCSEL1             _CPMUCLKS.Bits.COPOSCSEL1
#define CPMUCLKS_CSAD                   _CPMUCLKS.Bits.CSAD
#define CPMUCLKS_PSTP                   _CPMUCLKS.Bits.PSTP
#define CPMUCLKS_PLLSEL                 _CPMUCLKS.Bits.PLLSEL

#define CPMUCLKS_COPOSCSEL0_MASK        1U
#define CPMUCLKS_RTIOSCSEL_MASK         2U
#define CPMUCLKS_PCE_MASK               4U
#define CPMUCLKS_PRE_MASK               8U
#define CPMUCLKS_COPOSCSEL1_MASK        16U
#define CPMUCLKS_CSAD_MASK              32U
#define CPMUCLKS_PSTP_MASK              64U
#define CPMUCLKS_PLLSEL_MASK            128U


/*** CPMUPLL - S12CPMU PLL Control Register; 0x0000003A ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FM0         :1;                                       /* PLL Frequency Modulation Enable Bit 0 */
    byte FM1         :1;                                       /* PLL Frequency Modulation Enable Bit 1 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpFM   :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CPMUPLLSTR;
extern volatile CPMUPLLSTR _CPMUPLL @(REG_BASE + 0x0000003AUL);
#define CPMUPLL                         _CPMUPLL.Byte
#define CPMUPLL_FM0                     _CPMUPLL.Bits.FM0
#define CPMUPLL_FM1                     _CPMUPLL.Bits.FM1
#define CPMUPLL_FM                      _CPMUPLL.MergedBits.grpFM

#define CPMUPLL_FM0_MASK                16U
#define CPMUPLL_FM1_MASK                32U
#define CPMUPLL_FM_MASK                 48U
#define CPMUPLL_FM_BITNUM               4U


/*** CPMURTI - CPMU RTI Control Register; 0x0000003B ***/
typedef union {
  byte Byte;
  struct {
    byte RTR0        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 0 */
    byte RTR1        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 1 */
    byte RTR2        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 2 */
    byte RTR3        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 3 */
    byte RTR4        :1;                                       /* Real Time Interrupt Prescale Rate Select Bit 4 */
    byte RTR5        :1;                                       /* Real Time Interrupt Prescale Rate Select Bit 5 */
    byte RTR6        :1;                                       /* Real Time Interrupt Prescale Rate Select Bit 6 */
    byte RTDEC       :1;                                       /* Decimal or Binary Divider Select Bit */
  } Bits;
  struct {
    byte grpRTR  :7;
    byte         :1;
  } MergedBits;
} CPMURTISTR;
extern volatile CPMURTISTR _CPMURTI @(REG_BASE + 0x0000003BUL);
#define CPMURTI                         _CPMURTI.Byte
#define CPMURTI_RTR0                    _CPMURTI.Bits.RTR0
#define CPMURTI_RTR1                    _CPMURTI.Bits.RTR1
#define CPMURTI_RTR2                    _CPMURTI.Bits.RTR2
#define CPMURTI_RTR3                    _CPMURTI.Bits.RTR3
#define CPMURTI_RTR4                    _CPMURTI.Bits.RTR4
#define CPMURTI_RTR5                    _CPMURTI.Bits.RTR5
#define CPMURTI_RTR6                    _CPMURTI.Bits.RTR6
#define CPMURTI_RTDEC                   _CPMURTI.Bits.RTDEC
#define CPMURTI_RTR                     _CPMURTI.MergedBits.grpRTR

#define CPMURTI_RTR0_MASK               1U
#define CPMURTI_RTR1_MASK               2U
#define CPMURTI_RTR2_MASK               4U
#define CPMURTI_RTR3_MASK               8U
#define CPMURTI_RTR4_MASK               16U
#define CPMURTI_RTR5_MASK               32U
#define CPMURTI_RTR6_MASK               64U
#define CPMURTI_RTDEC_MASK              128U
#define CPMURTI_RTR_MASK                127U
#define CPMURTI_RTR_BITNUM              0U


/*** CPMUCOP - CPMU COP Control Register; 0x0000003C ***/
typedef union {
  byte Byte;
  struct {
    byte CR0         :1;                                       /* COP Watchdog Timer Rate select Bit 0 */
    byte CR1         :1;                                       /* COP Watchdog Timer Rate select Bit 1 */
    byte CR2         :1;                                       /* COP Watchdog Timer Rate select Bit 2 */
    byte             :1; 
    byte             :1; 
    byte WRTMASK     :1;                                       /* Write Mask for WCOP */
    byte RSBCK       :1;                                       /* COP and RTI stop in Active BDM mode Bit */
    byte WCOP        :1;                                       /* Window COP mode */
  } Bits;
  struct {
    byte grpCR   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CPMUCOPSTR;
extern volatile CPMUCOPSTR _CPMUCOP @(REG_BASE + 0x0000003CUL);
#define CPMUCOP                         _CPMUCOP.Byte
#define CPMUCOP_CR0                     _CPMUCOP.Bits.CR0
#define CPMUCOP_CR1                     _CPMUCOP.Bits.CR1
#define CPMUCOP_CR2                     _CPMUCOP.Bits.CR2
#define CPMUCOP_WRTMASK                 _CPMUCOP.Bits.WRTMASK
#define CPMUCOP_RSBCK                   _CPMUCOP.Bits.RSBCK
#define CPMUCOP_WCOP                    _CPMUCOP.Bits.WCOP
#define CPMUCOP_CR                      _CPMUCOP.MergedBits.grpCR

#define CPMUCOP_CR0_MASK                1U
#define CPMUCOP_CR1_MASK                2U
#define CPMUCOP_CR2_MASK                4U
#define CPMUCOP_WRTMASK_MASK            32U
#define CPMUCOP_RSBCK_MASK              64U
#define CPMUCOP_WCOP_MASK               128U
#define CPMUCOP_CR_MASK                 7U
#define CPMUCOP_CR_BITNUM               0U


/*** CPMUARMCOP - CPMU COP Timer Arm/Reset Register; 0x0000003F ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* CPMU COP Timer Arm/Reset Bit 0 */
    byte BIT1        :1;                                       /* CPMU COP Timer Arm/Reset Bit 1 */
    byte BIT2        :1;                                       /* CPMU COP Timer Arm/Reset Bit 2 */
    byte BIT3        :1;                                       /* CPMU COP Timer Arm/Reset Bit 3 */
    byte BIT4        :1;                                       /* CPMU COP Timer Arm/Reset Bit 4 */
    byte BIT5        :1;                                       /* CPMU COP Timer Arm/Reset Bit 5 */
    byte BIT6        :1;                                       /* CPMU COP Timer Arm/Reset Bit 6 */
    byte BIT7        :1;                                       /* CPMU COP Timer Arm/Reset Bit 7 */
  } Bits;
} CPMUARMCOPSTR;
extern volatile CPMUARMCOPSTR _CPMUARMCOP @(REG_BASE + 0x0000003FUL);
#define CPMUARMCOP                      _CPMUARMCOP.Byte
#define CPMUARMCOP_BIT0                 _CPMUARMCOP.Bits.BIT0
#define CPMUARMCOP_BIT1                 _CPMUARMCOP.Bits.BIT1
#define CPMUARMCOP_BIT2                 _CPMUARMCOP.Bits.BIT2
#define CPMUARMCOP_BIT3                 _CPMUARMCOP.Bits.BIT3
#define CPMUARMCOP_BIT4                 _CPMUARMCOP.Bits.BIT4
#define CPMUARMCOP_BIT5                 _CPMUARMCOP.Bits.BIT5
#define CPMUARMCOP_BIT6                 _CPMUARMCOP.Bits.BIT6
#define CPMUARMCOP_BIT7                 _CPMUARMCOP.Bits.BIT7

#define CPMUARMCOP_BIT0_MASK            1U
#define CPMUARMCOP_BIT1_MASK            2U
#define CPMUARMCOP_BIT2_MASK            4U
#define CPMUARMCOP_BIT3_MASK            8U
#define CPMUARMCOP_BIT4_MASK            16U
#define CPMUARMCOP_BIT5_MASK            32U
#define CPMUARMCOP_BIT6_MASK            64U
#define CPMUARMCOP_BIT7_MASK            128U


/*** TIOS - Timer Input Capture/Output Compare Select; 0x00000040 ***/
typedef union {
  byte Byte;
  struct {
    byte IOS0        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 0 */
    byte IOS1        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 1 */
    byte IOS2        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 2 */
    byte IOS3        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpIOS  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TIOSSTR;
extern volatile TIOSSTR _TIOS @(REG_BASE + 0x00000040UL);
#define TIOS                            _TIOS.Byte
#define TIOS_IOS0                       _TIOS.Bits.IOS0
#define TIOS_IOS1                       _TIOS.Bits.IOS1
#define TIOS_IOS2                       _TIOS.Bits.IOS2
#define TIOS_IOS3                       _TIOS.Bits.IOS3
#define TIOS_IOS                        _TIOS.MergedBits.grpIOS

#define TIOS_IOS0_MASK                  1U
#define TIOS_IOS1_MASK                  2U
#define TIOS_IOS2_MASK                  4U
#define TIOS_IOS3_MASK                  8U
#define TIOS_IOS_MASK                   15U
#define TIOS_IOS_BITNUM                 0U


/*** CFORC - Timer Compare Force Register; 0x00000041 ***/
typedef union {
  byte Byte;
  struct {
    byte FOC0        :1;                                       /* Force Output Compare Action for Channel 0 */
    byte FOC1        :1;                                       /* Force Output Compare Action for Channel 1 */
    byte FOC2        :1;                                       /* Force Output Compare Action for Channel 2 */
    byte FOC3        :1;                                       /* Force Output Compare Action for Channel 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpFOC  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CFORCSTR;
extern volatile CFORCSTR _CFORC @(REG_BASE + 0x00000041UL);
#define CFORC                           _CFORC.Byte
#define CFORC_FOC0                      _CFORC.Bits.FOC0
#define CFORC_FOC1                      _CFORC.Bits.FOC1
#define CFORC_FOC2                      _CFORC.Bits.FOC2
#define CFORC_FOC3                      _CFORC.Bits.FOC3
#define CFORC_FOC                       _CFORC.MergedBits.grpFOC

#define CFORC_FOC0_MASK                 1U
#define CFORC_FOC1_MASK                 2U
#define CFORC_FOC2_MASK                 4U
#define CFORC_FOC3_MASK                 8U
#define CFORC_FOC_MASK                  15U
#define CFORC_FOC_BITNUM                0U


/*** TCNT - Timer Count Register; 0x00000044 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TCNTHi - Timer Count Register High; 0x00000044 ***/
    union {
      byte Byte;
    } TCNTHiSTR;
    #define TCNTHi                      _TCNT.Overlap_STR.TCNTHiSTR.Byte
    

    /*** TCNTLo - Timer Count Register Low; 0x00000045 ***/
    union {
      byte Byte;
    } TCNTLoSTR;
    #define TCNTLo                      _TCNT.Overlap_STR.TCNTLoSTR.Byte
    
  } Overlap_STR;

} TCNTSTR;
extern volatile TCNTSTR _TCNT @(REG_BASE + 0x00000044UL);
#define TCNT                            _TCNT.Word


/*** TSCR1 - Timer System Control Register1; 0x00000046 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PRNT        :1;                                       /* Precision Timer */
    byte TFFCA       :1;                                       /* Timer Fast Flag Clear All */
    byte TSFRZ       :1;                                       /* Timer and Modulus Counter Stop While in Freeze Mode */
    byte TSWAI       :1;                                       /* Timer Module Stops While in Wait */
    byte TEN         :1;                                       /* Timer Enable */
  } Bits;
} TSCR1STR;
extern volatile TSCR1STR _TSCR1 @(REG_BASE + 0x00000046UL);
#define TSCR1                           _TSCR1.Byte
#define TSCR1_PRNT                      _TSCR1.Bits.PRNT
#define TSCR1_TFFCA                     _TSCR1.Bits.TFFCA
#define TSCR1_TSFRZ                     _TSCR1.Bits.TSFRZ
#define TSCR1_TSWAI                     _TSCR1.Bits.TSWAI
#define TSCR1_TEN                       _TSCR1.Bits.TEN

#define TSCR1_PRNT_MASK                 8U
#define TSCR1_TFFCA_MASK                16U
#define TSCR1_TSFRZ_MASK                32U
#define TSCR1_TSWAI_MASK                64U
#define TSCR1_TEN_MASK                  128U


/*** TTOV - Timer Toggle On Overflow Register; 0x00000047 ***/
typedef union {
  byte Byte;
  struct {
    byte TOV0        :1;                                       /* Toggle On Overflow Bit 0 */
    byte TOV1        :1;                                       /* Toggle On Overflow Bit 1 */
    byte TOV2        :1;                                       /* Toggle On Overflow Bit 2 */
    byte TOV3        :1;                                       /* Toggle On Overflow Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTOV  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TTOVSTR;
extern volatile TTOVSTR _TTOV @(REG_BASE + 0x00000047UL);
#define TTOV                            _TTOV.Byte
#define TTOV_TOV0                       _TTOV.Bits.TOV0
#define TTOV_TOV1                       _TTOV.Bits.TOV1
#define TTOV_TOV2                       _TTOV.Bits.TOV2
#define TTOV_TOV3                       _TTOV.Bits.TOV3
#define TTOV_TOV                        _TTOV.MergedBits.grpTOV

#define TTOV_TOV0_MASK                  1U
#define TTOV_TOV1_MASK                  2U
#define TTOV_TOV2_MASK                  4U
#define TTOV_TOV3_MASK                  8U
#define TTOV_TOV_MASK                   15U
#define TTOV_TOV_BITNUM                 0U


/*** TCTL2 - Timer Control Register 2; 0x00000049 ***/
typedef union {
  byte Byte;
  struct {
    byte OL0         :1;                                       /* Output Level Bit 0 */
    byte OM0         :1;                                       /* Output Mode Bit 0 */
    byte OL1         :1;                                       /* Output Lecel Bit 1 */
    byte OM1         :1;                                       /* Output Mode Bit 1 */
    byte OL2         :1;                                       /* Output Level Bit 2 */
    byte OM2         :1;                                       /* Output Mode Bit 2 */
    byte OL3         :1;                                       /* Output Level Bit 3 */
    byte OM3         :1;                                       /* Output Mode Bit 3 */
  } Bits;
} TCTL2STR;
extern volatile TCTL2STR _TCTL2 @(REG_BASE + 0x00000049UL);
#define TCTL2                           _TCTL2.Byte
#define TCTL2_OL0                       _TCTL2.Bits.OL0
#define TCTL2_OM0                       _TCTL2.Bits.OM0
#define TCTL2_OL1                       _TCTL2.Bits.OL1
#define TCTL2_OM1                       _TCTL2.Bits.OM1
#define TCTL2_OL2                       _TCTL2.Bits.OL2
#define TCTL2_OM2                       _TCTL2.Bits.OM2
#define TCTL2_OL3                       _TCTL2.Bits.OL3
#define TCTL2_OM3                       _TCTL2.Bits.OM3

#define TCTL2_OL0_MASK                  1U
#define TCTL2_OM0_MASK                  2U
#define TCTL2_OL1_MASK                  4U
#define TCTL2_OM1_MASK                  8U
#define TCTL2_OL2_MASK                  16U
#define TCTL2_OM2_MASK                  32U
#define TCTL2_OL3_MASK                  64U
#define TCTL2_OM3_MASK                  128U


/*** TCTL4 - Timer Control Register 4; 0x0000004B ***/
typedef union {
  byte Byte;
  struct {
    byte EDG0A       :1;                                       /* Input Capture Edge Control 0A */
    byte EDG0B       :1;                                       /* Input Capture Edge Control 0B */
    byte EDG1A       :1;                                       /* Input Capture Edge Control 1A */
    byte EDG1B       :1;                                       /* Input Capture Edge Control 1B */
    byte EDG2A       :1;                                       /* Input Capture Edge Control 2A */
    byte EDG2B       :1;                                       /* Input Capture Edge Control 2B */
    byte EDG3A       :1;                                       /* Input Capture Edge Control 3A */
    byte EDG3B       :1;                                       /* Input Capture Edge Control 3B */
  } Bits;
  struct {
    byte grpEDG0x :2;
    byte grpEDG1x :2;
    byte grpEDG2x :2;
    byte grpEDG3x :2;
  } MergedBits;
} TCTL4STR;
extern volatile TCTL4STR _TCTL4 @(REG_BASE + 0x0000004BUL);
#define TCTL4                           _TCTL4.Byte
#define TCTL4_EDG0A                     _TCTL4.Bits.EDG0A
#define TCTL4_EDG0B                     _TCTL4.Bits.EDG0B
#define TCTL4_EDG1A                     _TCTL4.Bits.EDG1A
#define TCTL4_EDG1B                     _TCTL4.Bits.EDG1B
#define TCTL4_EDG2A                     _TCTL4.Bits.EDG2A
#define TCTL4_EDG2B                     _TCTL4.Bits.EDG2B
#define TCTL4_EDG3A                     _TCTL4.Bits.EDG3A
#define TCTL4_EDG3B                     _TCTL4.Bits.EDG3B
#define TCTL4_EDG0x                     _TCTL4.MergedBits.grpEDG0x
#define TCTL4_EDG1x                     _TCTL4.MergedBits.grpEDG1x
#define TCTL4_EDG2x                     _TCTL4.MergedBits.grpEDG2x
#define TCTL4_EDG3x                     _TCTL4.MergedBits.grpEDG3x

#define TCTL4_EDG0A_MASK                1U
#define TCTL4_EDG0B_MASK                2U
#define TCTL4_EDG1A_MASK                4U
#define TCTL4_EDG1B_MASK                8U
#define TCTL4_EDG2A_MASK                16U
#define TCTL4_EDG2B_MASK                32U
#define TCTL4_EDG3A_MASK                64U
#define TCTL4_EDG3B_MASK                128U
#define TCTL4_EDG0x_MASK                3U
#define TCTL4_EDG0x_BITNUM              0U
#define TCTL4_EDG1x_MASK                12U
#define TCTL4_EDG1x_BITNUM              2U
#define TCTL4_EDG2x_MASK                48U
#define TCTL4_EDG2x_BITNUM              4U
#define TCTL4_EDG3x_MASK                192U
#define TCTL4_EDG3x_BITNUM              6U


/*** TIE - Timer Interrupt Enable Register; 0x0000004C ***/
typedef union {
  byte Byte;
  struct {
    byte C0I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 0 */
    byte C1I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 1 */
    byte C2I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 2 */
    byte C3I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} TIESTR;
extern volatile TIESTR _TIE @(REG_BASE + 0x0000004CUL);
#define TIE                             _TIE.Byte
#define TIE_C0I                         _TIE.Bits.C0I
#define TIE_C1I                         _TIE.Bits.C1I
#define TIE_C2I                         _TIE.Bits.C2I
#define TIE_C3I                         _TIE.Bits.C3I

#define TIE_C0I_MASK                    1U
#define TIE_C1I_MASK                    2U
#define TIE_C2I_MASK                    4U
#define TIE_C3I_MASK                    8U


/*** TSCR2 - Timer System Control Register 2; 0x0000004D ***/
typedef union {
  byte Byte;
  struct {
    byte PR0         :1;                                       /* Timer Prescaler Select Bit 0 */
    byte PR1         :1;                                       /* Timer Prescaler Select Bit 1 */
    byte PR2         :1;                                       /* Timer Prescaler Select Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TOI         :1;                                       /* Timer Overflow Interrupt Enable */
  } Bits;
  struct {
    byte grpPR   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TSCR2STR;
extern volatile TSCR2STR _TSCR2 @(REG_BASE + 0x0000004DUL);
#define TSCR2                           _TSCR2.Byte
#define TSCR2_PR0                       _TSCR2.Bits.PR0
#define TSCR2_PR1                       _TSCR2.Bits.PR1
#define TSCR2_PR2                       _TSCR2.Bits.PR2
#define TSCR2_TOI                       _TSCR2.Bits.TOI
#define TSCR2_PR                        _TSCR2.MergedBits.grpPR

#define TSCR2_PR0_MASK                  1U
#define TSCR2_PR1_MASK                  2U
#define TSCR2_PR2_MASK                  4U
#define TSCR2_TOI_MASK                  128U
#define TSCR2_PR_MASK                   7U
#define TSCR2_PR_BITNUM                 0U


/*** TFLG1 - Main Timer Interrupt Flag 1; 0x0000004E ***/
typedef union {
  byte Byte;
  struct {
    byte C0F         :1;                                       /* Input Capture/Output Compare Channel Flag 0 */
    byte C1F         :1;                                       /* Input Capture/Output Compare Channel Flag 1 */
    byte C2F         :1;                                       /* Input Capture/Output Compare Channel Flag 2 */
    byte C3F         :1;                                       /* Input Capture/Output Compare Channel Flag 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} TFLG1STR;
extern volatile TFLG1STR _TFLG1 @(REG_BASE + 0x0000004EUL);
#define TFLG1                           _TFLG1.Byte
#define TFLG1_C0F                       _TFLG1.Bits.C0F
#define TFLG1_C1F                       _TFLG1.Bits.C1F
#define TFLG1_C2F                       _TFLG1.Bits.C2F
#define TFLG1_C3F                       _TFLG1.Bits.C3F

#define TFLG1_C0F_MASK                  1U
#define TFLG1_C1F_MASK                  2U
#define TFLG1_C2F_MASK                  4U
#define TFLG1_C3F_MASK                  8U


/*** TFLG2 - Main Timer Interrupt Flag 2; 0x0000004F ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
} TFLG2STR;
extern volatile TFLG2STR _TFLG2 @(REG_BASE + 0x0000004FUL);
#define TFLG2                           _TFLG2.Byte
#define TFLG2_TOF                       _TFLG2.Bits.TOF

#define TFLG2_TOF_MASK                  128U


/*** TC0 - Timer Input Capture/Output Compare Register 0; 0x00000050 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC0Hi - Timer Input Capture/Output Compare Register 0 High; 0x00000050 ***/
    union {
      byte Byte;
    } TC0HiSTR;
    #define TC0Hi                       _TC0.Overlap_STR.TC0HiSTR.Byte
    

    /*** TC0Lo - Timer Input Capture/Output Compare Register 0 Low; 0x00000051 ***/
    union {
      byte Byte;
    } TC0LoSTR;
    #define TC0Lo                       _TC0.Overlap_STR.TC0LoSTR.Byte
    
  } Overlap_STR;

} TC0STR;
extern volatile TC0STR _TC0 @(REG_BASE + 0x00000050UL);
#define TC0                             _TC0.Word
/* TC_ARR: Access 4 TCx registers in an array */
#define TC_ARR                          ((volatile word *) &TC0)


/*** TC1 - Timer Input Capture/Output Compare Register 1; 0x00000052 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC1Hi - Timer Input Capture/Output Compare Register 1 High; 0x00000052 ***/
    union {
      byte Byte;
    } TC1HiSTR;
    #define TC1Hi                       _TC1.Overlap_STR.TC1HiSTR.Byte
    

    /*** TC1Lo - Timer Input Capture/Output Compare Register 1 Low; 0x00000053 ***/
    union {
      byte Byte;
    } TC1LoSTR;
    #define TC1Lo                       _TC1.Overlap_STR.TC1LoSTR.Byte
    
  } Overlap_STR;

} TC1STR;
extern volatile TC1STR _TC1 @(REG_BASE + 0x00000052UL);
#define TC1                             _TC1.Word


/*** TC2 - Timer Input Capture/Output Compare Register 2; 0x00000054 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC2Hi - Timer Input Capture/Output Compare Register 2 High; 0x00000054 ***/
    union {
      byte Byte;
    } TC2HiSTR;
    #define TC2Hi                       _TC2.Overlap_STR.TC2HiSTR.Byte
    

    /*** TC2Lo - Timer Input Capture/Output Compare Register 2 Low; 0x00000055 ***/
    union {
      byte Byte;
    } TC2LoSTR;
    #define TC2Lo                       _TC2.Overlap_STR.TC2LoSTR.Byte
    
  } Overlap_STR;

} TC2STR;
extern volatile TC2STR _TC2 @(REG_BASE + 0x00000054UL);
#define TC2                             _TC2.Word


/*** TC3 - Timer Input Capture/Output Compare Register 3; 0x00000056 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC3Hi - Timer Input Capture/Output Compare Register 3 High; 0x00000056 ***/
    union {
      byte Byte;
    } TC3HiSTR;
    #define TC3Hi                       _TC3.Overlap_STR.TC3HiSTR.Byte
    

    /*** TC3Lo - Timer Input Capture/Output Compare Register 3 Low; 0x00000057 ***/
    union {
      byte Byte;
    } TC3LoSTR;
    #define TC3Lo                       _TC3.Overlap_STR.TC3LoSTR.Byte
    
  } Overlap_STR;

} TC3STR;
extern volatile TC3STR _TC3 @(REG_BASE + 0x00000056UL);
#define TC3                             _TC3.Word


/*** OCPD - Output Compare Pin Disconnect Register; 0x0000006C ***/
typedef union {
  byte Byte;
  struct {
    byte OCPD0       :1;                                       /* Output Compare Pin Disconnect Bit 0 */
    byte OCPD1       :1;                                       /* Output Compare Pin Disconnect Bit 1 */
    byte OCPD2       :1;                                       /* Output Compare Pin Disconnect Bit 2 */
    byte OCPD3       :1;                                       /* Output Compare Pin Disconnect Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpOCPD :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} OCPDSTR;
extern volatile OCPDSTR _OCPD @(REG_BASE + 0x0000006CUL);
#define OCPD                            _OCPD.Byte
#define OCPD_OCPD0                      _OCPD.Bits.OCPD0
#define OCPD_OCPD1                      _OCPD.Bits.OCPD1
#define OCPD_OCPD2                      _OCPD.Bits.OCPD2
#define OCPD_OCPD3                      _OCPD.Bits.OCPD3
#define OCPD_OCPD                       _OCPD.MergedBits.grpOCPD

#define OCPD_OCPD0_MASK                 1U
#define OCPD_OCPD1_MASK                 2U
#define OCPD_OCPD2_MASK                 4U
#define OCPD_OCPD3_MASK                 8U
#define OCPD_OCPD_MASK                  15U
#define OCPD_OCPD_BITNUM                0U


/*** PTPSR - Precision Timer Prescaler Select Register; 0x0000006E ***/
typedef union {
  byte Byte;
  struct {
    byte PTPS0       :1;                                       /* Precision Timer Prescaler Select Bit 0 */
    byte PTPS1       :1;                                       /* Precision Timer Prescaler Select Bit 1 */
    byte PTPS2       :1;                                       /* Precision Timer Prescaler Select Bit 2 */
    byte PTPS3       :1;                                       /* Precision Timer Prescaler Select Bit 3 */
    byte PTPS4       :1;                                       /* Precision Timer Prescaler Select Bit 4 */
    byte PTPS5       :1;                                       /* Precision Timer Prescaler Select Bit 5 */
    byte PTPS6       :1;                                       /* Precision Timer Prescaler Select Bit 6 */
    byte PTPS7       :1;                                       /* Precision Timer Prescaler Select Bit 7 */
  } Bits;
} PTPSRSTR;
extern volatile PTPSRSTR _PTPSR @(REG_BASE + 0x0000006EUL);
#define PTPSR                           _PTPSR.Byte
#define PTPSR_PTPS0                     _PTPSR.Bits.PTPS0
#define PTPSR_PTPS1                     _PTPSR.Bits.PTPS1
#define PTPSR_PTPS2                     _PTPSR.Bits.PTPS2
#define PTPSR_PTPS3                     _PTPSR.Bits.PTPS3
#define PTPSR_PTPS4                     _PTPSR.Bits.PTPS4
#define PTPSR_PTPS5                     _PTPSR.Bits.PTPS5
#define PTPSR_PTPS6                     _PTPSR.Bits.PTPS6
#define PTPSR_PTPS7                     _PTPSR.Bits.PTPS7

#define PTPSR_PTPS0_MASK                1U
#define PTPSR_PTPS1_MASK                2U
#define PTPSR_PTPS2_MASK                4U
#define PTPSR_PTPS3_MASK                8U
#define PTPSR_PTPS4_MASK                16U
#define PTPSR_PTPS5_MASK                32U
#define PTPSR_PTPS6_MASK                64U
#define PTPSR_PTPS7_MASK                128U


/*** ATDCTL01 - ATD  Control Register 01; 0x00000070 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDCTL0 - ATD  Control Register 0; 0x00000070 ***/
    union {
      byte Byte;
      struct {
        byte WRAP0       :1;                                       /* Wrap Around Channel Select Bit 0 */
        byte WRAP1       :1;                                       /* Wrap Around Channel Select Bit 1 */
        byte WRAP2       :1;                                       /* Wrap Around Channel Select Bit 2 */
        byte WRAP3       :1;                                       /* Wrap Around Channel Select Bit 3 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpWRAP :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ATDCTL0STR;
    #define ATDCTL0                     _ATDCTL01.Overlap_STR.ATDCTL0STR.Byte
    #define ATDCTL0_WRAP0               _ATDCTL01.Overlap_STR.ATDCTL0STR.Bits.WRAP0
    #define ATDCTL0_WRAP1               _ATDCTL01.Overlap_STR.ATDCTL0STR.Bits.WRAP1
    #define ATDCTL0_WRAP2               _ATDCTL01.Overlap_STR.ATDCTL0STR.Bits.WRAP2
    #define ATDCTL0_WRAP3               _ATDCTL01.Overlap_STR.ATDCTL0STR.Bits.WRAP3
    /* ATDCTL_ARR: Access 6 ATDCTLx registers in an array */
    #define ATDCTL_ARR                  ((volatile byte *) &ATDCTL0)
    #define ATDCTL0_WRAP                _ATDCTL01.Overlap_STR.ATDCTL0STR.MergedBits.grpWRAP
    
    #define ATDCTL0_WRAP0_MASK          1U
    #define ATDCTL0_WRAP1_MASK          2U
    #define ATDCTL0_WRAP2_MASK          4U
    #define ATDCTL0_WRAP3_MASK          8U
    #define ATDCTL0_WRAP_MASK           15U
    #define ATDCTL0_WRAP_BITNUM         0U
    

    /*** ATDCTL1 - ATD  Control Register 1; 0x00000071 ***/
    union {
      byte Byte;
      struct {
        byte ETRIGCH0    :1;                                       /* External Trigger Channel Select Bit 0 */
        byte ETRIGCH1    :1;                                       /* External Trigger Channel Select Bit 1 */
        byte ETRIGCH2    :1;                                       /* External Trigger Channel Select Bit 2 */
        byte ETRIGCH3    :1;                                       /* External Trigger Channel Select Bit 3 */
        byte SMP_DIS     :1;                                       /* Discharge Before Sampling Bit */
        byte SRES0       :1;                                       /* A/D Resolution Select Bit 0 */
        byte SRES1       :1;                                       /* A/D Resolution Select Bit 1 */
        byte ETRIGSEL    :1;                                       /* External Trigger Source Select */
      } Bits;
      struct {
        byte grpETRIGCH :4;
        byte     :1;
        byte grpSRES :2;
        byte     :1;
      } MergedBits;
    } ATDCTL1STR;
    #define ATDCTL1                     _ATDCTL01.Overlap_STR.ATDCTL1STR.Byte
    #define ATDCTL1_ETRIGCH0            _ATDCTL01.Overlap_STR.ATDCTL1STR.Bits.ETRIGCH0
    #define ATDCTL1_ETRIGCH1            _ATDCTL01.Overlap_STR.ATDCTL1STR.Bits.ETRIGCH1
    #define ATDCTL1_ETRIGCH2            _ATDCTL01.Overlap_STR.ATDCTL1STR.Bits.ETRIGCH2
    #define ATDCTL1_ETRIGCH3            _ATDCTL01.Overlap_STR.ATDCTL1STR.Bits.ETRIGCH3
    #define ATDCTL1_SMP_DIS             _ATDCTL01.Overlap_STR.ATDCTL1STR.Bits.SMP_DIS
    #define ATDCTL1_SRES0               _ATDCTL01.Overlap_STR.ATDCTL1STR.Bits.SRES0
    #define ATDCTL1_SRES1               _ATDCTL01.Overlap_STR.ATDCTL1STR.Bits.SRES1
    #define ATDCTL1_ETRIGSEL            _ATDCTL01.Overlap_STR.ATDCTL1STR.Bits.ETRIGSEL
    #define ATDCTL1_ETRIGCH             _ATDCTL01.Overlap_STR.ATDCTL1STR.MergedBits.grpETRIGCH
    #define ATDCTL1_SRES                _ATDCTL01.Overlap_STR.ATDCTL1STR.MergedBits.grpSRES
    
    #define ATDCTL1_ETRIGCH0_MASK       1U
    #define ATDCTL1_ETRIGCH1_MASK       2U
    #define ATDCTL1_ETRIGCH2_MASK       4U
    #define ATDCTL1_ETRIGCH3_MASK       8U
    #define ATDCTL1_SMP_DIS_MASK        16U
    #define ATDCTL1_SRES0_MASK          32U
    #define ATDCTL1_SRES1_MASK          64U
    #define ATDCTL1_ETRIGSEL_MASK       128U
    #define ATDCTL1_ETRIGCH_MASK        15U
    #define ATDCTL1_ETRIGCH_BITNUM      0U
    #define ATDCTL1_SRES_MASK           96U
    #define ATDCTL1_SRES_BITNUM         5U
    
  } Overlap_STR;

  struct {
    word ETRIGCH0    :1;                                       /* External Trigger Channel Select Bit 0 */
    word ETRIGCH1    :1;                                       /* External Trigger Channel Select Bit 1 */
    word ETRIGCH2    :1;                                       /* External Trigger Channel Select Bit 2 */
    word ETRIGCH3    :1;                                       /* External Trigger Channel Select Bit 3 */
    word SMP_DIS     :1;                                       /* Discharge Before Sampling Bit */
    word SRES0       :1;                                       /* A/D Resolution Select Bit 0 */
    word SRES1       :1;                                       /* A/D Resolution Select Bit 1 */
    word ETRIGSEL    :1;                                       /* External Trigger Source Select */
    word WRAP0       :1;                                       /* Wrap Around Channel Select Bit 0 */
    word WRAP1       :1;                                       /* Wrap Around Channel Select Bit 1 */
    word WRAP2       :1;                                       /* Wrap Around Channel Select Bit 2 */
    word WRAP3       :1;                                       /* Wrap Around Channel Select Bit 3 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpETRIGCH :4;
    word         :1;
    word grpSRES :2;
    word         :1;
    word grpWRAP :4;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ATDCTL01STR;
extern volatile ATDCTL01STR _ATDCTL01 @(REG_BASE + 0x00000070UL);
#define ATDCTL01                        _ATDCTL01.Word
#define ATDCTL01_ETRIGCH0               _ATDCTL01.Bits.ETRIGCH0
#define ATDCTL01_ETRIGCH1               _ATDCTL01.Bits.ETRIGCH1
#define ATDCTL01_ETRIGCH2               _ATDCTL01.Bits.ETRIGCH2
#define ATDCTL01_ETRIGCH3               _ATDCTL01.Bits.ETRIGCH3
#define ATDCTL01_SMP_DIS                _ATDCTL01.Bits.SMP_DIS
#define ATDCTL01_SRES0                  _ATDCTL01.Bits.SRES0
#define ATDCTL01_SRES1                  _ATDCTL01.Bits.SRES1
#define ATDCTL01_ETRIGSEL               _ATDCTL01.Bits.ETRIGSEL
#define ATDCTL01_WRAP0                  _ATDCTL01.Bits.WRAP0
#define ATDCTL01_WRAP1                  _ATDCTL01.Bits.WRAP1
#define ATDCTL01_WRAP2                  _ATDCTL01.Bits.WRAP2
#define ATDCTL01_WRAP3                  _ATDCTL01.Bits.WRAP3
#define ATDCTL01_ETRIGCH                _ATDCTL01.MergedBits.grpETRIGCH
#define ATDCTL01_SRES                   _ATDCTL01.MergedBits.grpSRES
#define ATDCTL01_WRAP                   _ATDCTL01.MergedBits.grpWRAP

#define ATDCTL01_ETRIGCH0_MASK          1U
#define ATDCTL01_ETRIGCH1_MASK          2U
#define ATDCTL01_ETRIGCH2_MASK          4U
#define ATDCTL01_ETRIGCH3_MASK          8U
#define ATDCTL01_SMP_DIS_MASK           16U
#define ATDCTL01_SRES0_MASK             32U
#define ATDCTL01_SRES1_MASK             64U
#define ATDCTL01_ETRIGSEL_MASK          128U
#define ATDCTL01_WRAP0_MASK             256U
#define ATDCTL01_WRAP1_MASK             512U
#define ATDCTL01_WRAP2_MASK             1024U
#define ATDCTL01_WRAP3_MASK             2048U
#define ATDCTL01_ETRIGCH_MASK           15U
#define ATDCTL01_ETRIGCH_BITNUM         0U
#define ATDCTL01_SRES_MASK              96U
#define ATDCTL01_SRES_BITNUM            5U
#define ATDCTL01_WRAP_MASK              3840U
#define ATDCTL01_WRAP_BITNUM            8U


/*** ATDCTL23 - ATD  Control Register 23; 0x00000072 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDCTL2 - ATD  Control Register 2; 0x00000072 ***/
    union {
      byte Byte;
      struct {
        byte ACMPIE      :1;                                       /* ATD Compare Interrupt Enable */
        byte ASCIE       :1;                                       /* ATD Sequence Complete Interrupt Enable */
        byte ETRIGE      :1;                                       /* External Trigger Mode enable */
        byte ETRIGP      :1;                                       /* External Trigger Polarity */
        byte ETRIGLE     :1;                                       /* External Trigger Level/Edge control */
        byte             :1; 
        byte AFFC        :1;                                       /* ATD Fast Conversion Complete Flag Clear */
        byte             :1; 
      } Bits;
    } ATDCTL2STR;
    #define ATDCTL2                     _ATDCTL23.Overlap_STR.ATDCTL2STR.Byte
    #define ATDCTL2_ACMPIE              _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ACMPIE
    #define ATDCTL2_ASCIE               _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ASCIE
    #define ATDCTL2_ETRIGE              _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ETRIGE
    #define ATDCTL2_ETRIGP              _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ETRIGP
    #define ATDCTL2_ETRIGLE             _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ETRIGLE
    #define ATDCTL2_AFFC                _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.AFFC
    
    #define ATDCTL2_ACMPIE_MASK         1U
    #define ATDCTL2_ASCIE_MASK          2U
    #define ATDCTL2_ETRIGE_MASK         4U
    #define ATDCTL2_ETRIGP_MASK         8U
    #define ATDCTL2_ETRIGLE_MASK        16U
    #define ATDCTL2_AFFC_MASK           64U
    

    /*** ATDCTL3 - ATD  Control Register 3; 0x00000073 ***/
    union {
      byte Byte;
      struct {
        byte FRZ0        :1;                                       /* Background Debug Freeze Enable Bit 0 */
        byte FRZ1        :1;                                       /* Background Debug Freeze Enable Bit 1 */
        byte FIFO        :1;                                       /* Result Register FIFO Mode */
        byte S1C         :1;                                       /* Conversion Sequence Length 1 */
        byte S2C         :1;                                       /* Conversion Sequence Length 2 */
        byte S4C         :1;                                       /* Conversion Sequence Length 4 */
        byte S8C         :1;                                       /* Conversion Sequence Length 8 */
        byte DJM         :1;                                       /* Result Register Data Justification */
      } Bits;
      struct {
        byte grpFRZ :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ATDCTL3STR;
    #define ATDCTL3                     _ATDCTL23.Overlap_STR.ATDCTL3STR.Byte
    #define ATDCTL3_FRZ0                _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.FRZ0
    #define ATDCTL3_FRZ1                _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.FRZ1
    #define ATDCTL3_FIFO                _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.FIFO
    #define ATDCTL3_S1C                 _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.S1C
    #define ATDCTL3_S2C                 _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.S2C
    #define ATDCTL3_S4C                 _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.S4C
    #define ATDCTL3_S8C                 _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.S8C
    #define ATDCTL3_DJM                 _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.DJM
    #define ATDCTL3_FRZ                 _ATDCTL23.Overlap_STR.ATDCTL3STR.MergedBits.grpFRZ
    
    #define ATDCTL3_FRZ0_MASK           1U
    #define ATDCTL3_FRZ1_MASK           2U
    #define ATDCTL3_FIFO_MASK           4U
    #define ATDCTL3_S1C_MASK            8U
    #define ATDCTL3_S2C_MASK            16U
    #define ATDCTL3_S4C_MASK            32U
    #define ATDCTL3_S8C_MASK            64U
    #define ATDCTL3_DJM_MASK            128U
    #define ATDCTL3_FRZ_MASK            3U
    #define ATDCTL3_FRZ_BITNUM          0U
    
  } Overlap_STR;

  struct {
    word FRZ0        :1;                                       /* Background Debug Freeze Enable Bit 0 */
    word FRZ1        :1;                                       /* Background Debug Freeze Enable Bit 1 */
    word FIFO        :1;                                       /* Result Register FIFO Mode */
    word S1C         :1;                                       /* Conversion Sequence Length 1 */
    word S2C         :1;                                       /* Conversion Sequence Length 2 */
    word S4C         :1;                                       /* Conversion Sequence Length 4 */
    word S8C         :1;                                       /* Conversion Sequence Length 8 */
    word DJM         :1;                                       /* Result Register Data Justification */
    word ACMPIE      :1;                                       /* ATD Compare Interrupt Enable */
    word ASCIE       :1;                                       /* ATD Sequence Complete Interrupt Enable */
    word ETRIGE      :1;                                       /* External Trigger Mode enable */
    word ETRIGP      :1;                                       /* External Trigger Polarity */
    word ETRIGLE     :1;                                       /* External Trigger Level/Edge control */
    word             :1; 
    word AFFC        :1;                                       /* ATD Fast Conversion Complete Flag Clear */
    word             :1; 
  } Bits;
  struct {
    word grpFRZ  :2;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ATDCTL23STR;
extern volatile ATDCTL23STR _ATDCTL23 @(REG_BASE + 0x00000072UL);
#define ATDCTL23                        _ATDCTL23.Word
#define ATDCTL23_FRZ0                   _ATDCTL23.Bits.FRZ0
#define ATDCTL23_FRZ1                   _ATDCTL23.Bits.FRZ1
#define ATDCTL23_FIFO                   _ATDCTL23.Bits.FIFO
#define ATDCTL23_S1C                    _ATDCTL23.Bits.S1C
#define ATDCTL23_S2C                    _ATDCTL23.Bits.S2C
#define ATDCTL23_S4C                    _ATDCTL23.Bits.S4C
#define ATDCTL23_S8C                    _ATDCTL23.Bits.S8C
#define ATDCTL23_DJM                    _ATDCTL23.Bits.DJM
#define ATDCTL23_ACMPIE                 _ATDCTL23.Bits.ACMPIE
#define ATDCTL23_ASCIE                  _ATDCTL23.Bits.ASCIE
#define ATDCTL23_ETRIGE                 _ATDCTL23.Bits.ETRIGE
#define ATDCTL23_ETRIGP                 _ATDCTL23.Bits.ETRIGP
#define ATDCTL23_ETRIGLE                _ATDCTL23.Bits.ETRIGLE
#define ATDCTL23_AFFC                   _ATDCTL23.Bits.AFFC
#define ATDCTL23_FRZ                    _ATDCTL23.MergedBits.grpFRZ

#define ATDCTL23_FRZ0_MASK              1U
#define ATDCTL23_FRZ1_MASK              2U
#define ATDCTL23_FIFO_MASK              4U
#define ATDCTL23_S1C_MASK               8U
#define ATDCTL23_S2C_MASK               16U
#define ATDCTL23_S4C_MASK               32U
#define ATDCTL23_S8C_MASK               64U
#define ATDCTL23_DJM_MASK               128U
#define ATDCTL23_ACMPIE_MASK            256U
#define ATDCTL23_ASCIE_MASK             512U
#define ATDCTL23_ETRIGE_MASK            1024U
#define ATDCTL23_ETRIGP_MASK            2048U
#define ATDCTL23_ETRIGLE_MASK           4096U
#define ATDCTL23_AFFC_MASK              16384U
#define ATDCTL23_FRZ_MASK               3U
#define ATDCTL23_FRZ_BITNUM             0U


/*** ATDCTL45 - ATD  Control Register 45; 0x00000074 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDCTL4 - ATD  Control Register 4; 0x00000074 ***/
    union {
      byte Byte;
      struct {
        byte PRS0        :1;                                       /* ATD Clock Prescaler 0 */
        byte PRS1        :1;                                       /* ATD Clock Prescaler 1 */
        byte PRS2        :1;                                       /* ATD Clock Prescaler 2 */
        byte PRS3        :1;                                       /* ATD Clock Prescaler 3 */
        byte PRS4        :1;                                       /* ATD Clock Prescaler 4 */
        byte SMP0        :1;                                       /* Sample Time Select 0 */
        byte SMP1        :1;                                       /* Sample Time Select 1 */
        byte SMP2        :1;                                       /* Sample Time Select 2 */
      } Bits;
      struct {
        byte grpPRS :5;
        byte grpSMP :3;
      } MergedBits;
    } ATDCTL4STR;
    #define ATDCTL4                     _ATDCTL45.Overlap_STR.ATDCTL4STR.Byte
    #define ATDCTL4_PRS0                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.PRS0
    #define ATDCTL4_PRS1                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.PRS1
    #define ATDCTL4_PRS2                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.PRS2
    #define ATDCTL4_PRS3                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.PRS3
    #define ATDCTL4_PRS4                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.PRS4
    #define ATDCTL4_SMP0                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.SMP0
    #define ATDCTL4_SMP1                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.SMP1
    #define ATDCTL4_SMP2                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.SMP2
    #define ATDCTL4_PRS                 _ATDCTL45.Overlap_STR.ATDCTL4STR.MergedBits.grpPRS
    #define ATDCTL4_SMP                 _ATDCTL45.Overlap_STR.ATDCTL4STR.MergedBits.grpSMP
    
    #define ATDCTL4_PRS0_MASK           1U
    #define ATDCTL4_PRS1_MASK           2U
    #define ATDCTL4_PRS2_MASK           4U
    #define ATDCTL4_PRS3_MASK           8U
    #define ATDCTL4_PRS4_MASK           16U
    #define ATDCTL4_SMP0_MASK           32U
    #define ATDCTL4_SMP1_MASK           64U
    #define ATDCTL4_SMP2_MASK           128U
    #define ATDCTL4_PRS_MASK            31U
    #define ATDCTL4_PRS_BITNUM          0U
    #define ATDCTL4_SMP_MASK            224U
    #define ATDCTL4_SMP_BITNUM          5U
    

    /*** ATDCTL5 - ATD  Control Register 5; 0x00000075 ***/
    union {
      byte Byte;
      struct {
        byte CA          :1;                                       /* Analog Input Channel Select Code A */
        byte CB          :1;                                       /* Analog Input Channel Select Code B */
        byte CC          :1;                                       /* Analog Input Channel Select Code C */
        byte CD          :1;                                       /* Analog Input Channel Select Code D */
        byte MULT        :1;                                       /* Multi-Channel Sample Mode */
        byte SCAN        :1;                                       /* Continuous Conversion Sequence Mode */
        byte SC          :1;                                       /* Special Channel Conversion Bit */
        byte             :1; 
      } Bits;
      struct {
        byte grpCx :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ATDCTL5STR;
    #define ATDCTL5                     _ATDCTL45.Overlap_STR.ATDCTL5STR.Byte
    #define ATDCTL5_CA                  _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.CA
    #define ATDCTL5_CB                  _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.CB
    #define ATDCTL5_CC                  _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.CC
    #define ATDCTL5_CD                  _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.CD
    #define ATDCTL5_MULT                _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.MULT
    #define ATDCTL5_SCAN                _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.SCAN
    #define ATDCTL5_SC                  _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.SC
    #define ATDCTL5_Cx                  _ATDCTL45.Overlap_STR.ATDCTL5STR.MergedBits.grpCx
    
    #define ATDCTL5_CA_MASK             1U
    #define ATDCTL5_CB_MASK             2U
    #define ATDCTL5_CC_MASK             4U
    #define ATDCTL5_CD_MASK             8U
    #define ATDCTL5_MULT_MASK           16U
    #define ATDCTL5_SCAN_MASK           32U
    #define ATDCTL5_SC_MASK             64U
    #define ATDCTL5_Cx_MASK             15U
    #define ATDCTL5_Cx_BITNUM           0U
    
  } Overlap_STR;

  struct {
    word CA          :1;                                       /* Analog Input Channel Select Code A */
    word CB          :1;                                       /* Analog Input Channel Select Code B */
    word CC          :1;                                       /* Analog Input Channel Select Code C */
    word CD          :1;                                       /* Analog Input Channel Select Code D */
    word MULT        :1;                                       /* Multi-Channel Sample Mode */
    word SCAN        :1;                                       /* Continuous Conversion Sequence Mode */
    word SC          :1;                                       /* Special Channel Conversion Bit */
    word             :1; 
    word PRS0        :1;                                       /* ATD Clock Prescaler 0 */
    word PRS1        :1;                                       /* ATD Clock Prescaler 1 */
    word PRS2        :1;                                       /* ATD Clock Prescaler 2 */
    word PRS3        :1;                                       /* ATD Clock Prescaler 3 */
    word PRS4        :1;                                       /* ATD Clock Prescaler 4 */
    word SMP0        :1;                                       /* Sample Time Select 0 */
    word SMP1        :1;                                       /* Sample Time Select 1 */
    word SMP2        :1;                                       /* Sample Time Select 2 */
  } Bits;
  struct {
    word grpCx   :4;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpPRS  :5;
    word grpSMP  :3;
  } MergedBits;
} ATDCTL45STR;
extern volatile ATDCTL45STR _ATDCTL45 @(REG_BASE + 0x00000074UL);
#define ATDCTL45                        _ATDCTL45.Word
#define ATDCTL45_CA                     _ATDCTL45.Bits.CA
#define ATDCTL45_CB                     _ATDCTL45.Bits.CB
#define ATDCTL45_CC                     _ATDCTL45.Bits.CC
#define ATDCTL45_CD                     _ATDCTL45.Bits.CD
#define ATDCTL45_MULT                   _ATDCTL45.Bits.MULT
#define ATDCTL45_SCAN                   _ATDCTL45.Bits.SCAN
#define ATDCTL45_SC                     _ATDCTL45.Bits.SC
#define ATDCTL45_PRS0                   _ATDCTL45.Bits.PRS0
#define ATDCTL45_PRS1                   _ATDCTL45.Bits.PRS1
#define ATDCTL45_PRS2                   _ATDCTL45.Bits.PRS2
#define ATDCTL45_PRS3                   _ATDCTL45.Bits.PRS3
#define ATDCTL45_PRS4                   _ATDCTL45.Bits.PRS4
#define ATDCTL45_SMP0                   _ATDCTL45.Bits.SMP0
#define ATDCTL45_SMP1                   _ATDCTL45.Bits.SMP1
#define ATDCTL45_SMP2                   _ATDCTL45.Bits.SMP2
#define ATDCTL45_Cx                     _ATDCTL45.MergedBits.grpCx
#define ATDCTL45_PRS                    _ATDCTL45.MergedBits.grpPRS
#define ATDCTL45_SMP                    _ATDCTL45.MergedBits.grpSMP

#define ATDCTL45_CA_MASK                1U
#define ATDCTL45_CB_MASK                2U
#define ATDCTL45_CC_MASK                4U
#define ATDCTL45_CD_MASK                8U
#define ATDCTL45_MULT_MASK              16U
#define ATDCTL45_SCAN_MASK              32U
#define ATDCTL45_SC_MASK                64U
#define ATDCTL45_PRS0_MASK              256U
#define ATDCTL45_PRS1_MASK              512U
#define ATDCTL45_PRS2_MASK              1024U
#define ATDCTL45_PRS3_MASK              2048U
#define ATDCTL45_PRS4_MASK              4096U
#define ATDCTL45_SMP0_MASK              8192U
#define ATDCTL45_SMP1_MASK              16384U
#define ATDCTL45_SMP2_MASK              32768U
#define ATDCTL45_Cx_MASK                15U
#define ATDCTL45_Cx_BITNUM              0U
#define ATDCTL45_PRS_MASK               7936U
#define ATDCTL45_PRS_BITNUM             8U
#define ATDCTL45_SMP_MASK               57344U
#define ATDCTL45_SMP_BITNUM             13U


/*** ATDSTAT0 - ATD  Status Register 0; 0x00000076 ***/
typedef union {
  byte Byte;
  struct {
    byte CC0         :1;                                       /* Conversion Counter 0 */
    byte CC1         :1;                                       /* Conversion Counter 1 */
    byte CC2         :1;                                       /* Conversion Counter 2 */
    byte CC3         :1;                                       /* Conversion Counter 3 */
    byte FIFOR       :1;                                       /* FIFO Over Run Flag */
    byte ETORF       :1;                                       /* External Trigger Overrun Flag */
    byte             :1; 
    byte SCF         :1;                                       /* Sequence Complete Flag */
  } Bits;
  struct {
    byte grpCC   :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ATDSTAT0STR;
extern volatile ATDSTAT0STR _ATDSTAT0 @(REG_BASE + 0x00000076UL);
#define ATDSTAT0                        _ATDSTAT0.Byte
#define ATDSTAT0_CC0                    _ATDSTAT0.Bits.CC0
#define ATDSTAT0_CC1                    _ATDSTAT0.Bits.CC1
#define ATDSTAT0_CC2                    _ATDSTAT0.Bits.CC2
#define ATDSTAT0_CC3                    _ATDSTAT0.Bits.CC3
#define ATDSTAT0_FIFOR                  _ATDSTAT0.Bits.FIFOR
#define ATDSTAT0_ETORF                  _ATDSTAT0.Bits.ETORF
#define ATDSTAT0_SCF                    _ATDSTAT0.Bits.SCF
#define ATDSTAT0_CC                     _ATDSTAT0.MergedBits.grpCC

#define ATDSTAT0_CC0_MASK               1U
#define ATDSTAT0_CC1_MASK               2U
#define ATDSTAT0_CC2_MASK               4U
#define ATDSTAT0_CC3_MASK               8U
#define ATDSTAT0_FIFOR_MASK             16U
#define ATDSTAT0_ETORF_MASK             32U
#define ATDSTAT0_SCF_MASK               128U
#define ATDSTAT0_CC_MASK                15U
#define ATDSTAT0_CC_BITNUM              0U


/*** ATDCMPE - ATD  Compare Enable Register; 0x00000078 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDCMPEH - ATD  Compare Enable Register High; 0x00000078 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } ATDCMPEHSTR;
    #define ATDCMPEH                    _ATDCMPE.Overlap_STR.ATDCMPEHSTR.Byte
    

    /*** ATDCMPEL - ATD  Compare Enable Register Low; 0x00000079 ***/
    union {
      byte Byte;
      struct {
        byte CMPE0       :1;                                       /* Compare Enable for Conversion Number 0 of a Sequence */
        byte CMPE1       :1;                                       /* Compare Enable for Conversion Number 1 of a Sequence */
        byte CMPE2       :1;                                       /* Compare Enable for Conversion Number 2 of a Sequence */
        byte CMPE3       :1;                                       /* Compare Enable for Conversion Number 3 of a Sequence */
        byte CMPE4       :1;                                       /* Compare Enable for Conversion Number 4 of a Sequence */
        byte CMPE5       :1;                                       /* Compare Enable for Conversion Number 5 of a Sequence */
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpCMPE :6;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ATDCMPELSTR;
    #define ATDCMPEL                    _ATDCMPE.Overlap_STR.ATDCMPELSTR.Byte
    #define ATDCMPEL_CMPE0              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE0
    #define ATDCMPEL_CMPE1              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE1
    #define ATDCMPEL_CMPE2              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE2
    #define ATDCMPEL_CMPE3              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE3
    #define ATDCMPEL_CMPE4              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE4
    #define ATDCMPEL_CMPE5              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE5
    #define ATDCMPEL_CMPE               _ATDCMPE.Overlap_STR.ATDCMPELSTR.MergedBits.grpCMPE
    
    #define ATDCMPEL_CMPE0_MASK         1U
    #define ATDCMPEL_CMPE1_MASK         2U
    #define ATDCMPEL_CMPE2_MASK         4U
    #define ATDCMPEL_CMPE3_MASK         8U
    #define ATDCMPEL_CMPE4_MASK         16U
    #define ATDCMPEL_CMPE5_MASK         32U
    #define ATDCMPEL_CMPE_MASK          63U
    #define ATDCMPEL_CMPE_BITNUM        0U
    
  } Overlap_STR;

  struct {
    word CMPE0       :1;                                       /* Compare Enable for Conversion Number 0 of a Sequence */
    word CMPE1       :1;                                       /* Compare Enable for Conversion Number 1 of a Sequence */
    word CMPE2       :1;                                       /* Compare Enable for Conversion Number 2 of a Sequence */
    word CMPE3       :1;                                       /* Compare Enable for Conversion Number 3 of a Sequence */
    word CMPE4       :1;                                       /* Compare Enable for Conversion Number 4 of a Sequence */
    word CMPE5       :1;                                       /* Compare Enable for Conversion Number 5 of a Sequence */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpCMPE :6;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ATDCMPESTR;
extern volatile ATDCMPESTR _ATDCMPE @(REG_BASE + 0x00000078UL);
#define ATDCMPE                         _ATDCMPE.Word
#define ATDCMPE_CMPE0                   _ATDCMPE.Bits.CMPE0
#define ATDCMPE_CMPE1                   _ATDCMPE.Bits.CMPE1
#define ATDCMPE_CMPE2                   _ATDCMPE.Bits.CMPE2
#define ATDCMPE_CMPE3                   _ATDCMPE.Bits.CMPE3
#define ATDCMPE_CMPE4                   _ATDCMPE.Bits.CMPE4
#define ATDCMPE_CMPE5                   _ATDCMPE.Bits.CMPE5
#define ATDCMPE_CMPE                    _ATDCMPE.MergedBits.grpCMPE

#define ATDCMPE_CMPE0_MASK              1U
#define ATDCMPE_CMPE1_MASK              2U
#define ATDCMPE_CMPE2_MASK              4U
#define ATDCMPE_CMPE3_MASK              8U
#define ATDCMPE_CMPE4_MASK              16U
#define ATDCMPE_CMPE5_MASK              32U
#define ATDCMPE_CMPE_MASK               63U
#define ATDCMPE_CMPE_BITNUM             0U


/*** ATDSTAT2 - ATD  Status Register 2; 0x0000007A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDSTAT2H - ATD  Status Register 2 High; 0x0000007A ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } ATDSTAT2HSTR;
    #define ATDSTAT2H                   _ATDSTAT2.Overlap_STR.ATDSTAT2HSTR.Byte
    

    /*** ATDSTAT2L - ATD  Status Register 2 Low; 0x0000007B ***/
    union {
      byte Byte;
      struct {
        byte CCF0        :1;                                       /* Conversion Complete Flag 0 */
        byte CCF1        :1;                                       /* Conversion Complete Flag 1 */
        byte CCF2        :1;                                       /* Conversion Complete Flag 2 */
        byte CCF3        :1;                                       /* Conversion Complete Flag 3 */
        byte CCF4        :1;                                       /* Conversion Complete Flag 4 */
        byte CCF5        :1;                                       /* Conversion Complete Flag 5 */
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpCCF :6;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ATDSTAT2LSTR;
    #define ATDSTAT2L                   _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Byte
    #define ATDSTAT2L_CCF0              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF0
    #define ATDSTAT2L_CCF1              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF1
    #define ATDSTAT2L_CCF2              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF2
    #define ATDSTAT2L_CCF3              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF3
    #define ATDSTAT2L_CCF4              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF4
    #define ATDSTAT2L_CCF5              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF5
    #define ATDSTAT2L_CCF               _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.MergedBits.grpCCF
    
    #define ATDSTAT2L_CCF0_MASK         1U
    #define ATDSTAT2L_CCF1_MASK         2U
    #define ATDSTAT2L_CCF2_MASK         4U
    #define ATDSTAT2L_CCF3_MASK         8U
    #define ATDSTAT2L_CCF4_MASK         16U
    #define ATDSTAT2L_CCF5_MASK         32U
    #define ATDSTAT2L_CCF_MASK          63U
    #define ATDSTAT2L_CCF_BITNUM        0U
    
  } Overlap_STR;

  struct {
    word CCF0        :1;                                       /* Conversion Complete Flag 0 */
    word CCF1        :1;                                       /* Conversion Complete Flag 1 */
    word CCF2        :1;                                       /* Conversion Complete Flag 2 */
    word CCF3        :1;                                       /* Conversion Complete Flag 3 */
    word CCF4        :1;                                       /* Conversion Complete Flag 4 */
    word CCF5        :1;                                       /* Conversion Complete Flag 5 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpCCF  :6;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ATDSTAT2STR;
extern volatile ATDSTAT2STR _ATDSTAT2 @(REG_BASE + 0x0000007AUL);
#define ATDSTAT2                        _ATDSTAT2.Word
#define ATDSTAT2_CCF0                   _ATDSTAT2.Bits.CCF0
#define ATDSTAT2_CCF1                   _ATDSTAT2.Bits.CCF1
#define ATDSTAT2_CCF2                   _ATDSTAT2.Bits.CCF2
#define ATDSTAT2_CCF3                   _ATDSTAT2.Bits.CCF3
#define ATDSTAT2_CCF4                   _ATDSTAT2.Bits.CCF4
#define ATDSTAT2_CCF5                   _ATDSTAT2.Bits.CCF5
#define ATDSTAT2_CCF                    _ATDSTAT2.MergedBits.grpCCF

#define ATDSTAT2_CCF0_MASK              1U
#define ATDSTAT2_CCF1_MASK              2U
#define ATDSTAT2_CCF2_MASK              4U
#define ATDSTAT2_CCF3_MASK              8U
#define ATDSTAT2_CCF4_MASK              16U
#define ATDSTAT2_CCF5_MASK              32U
#define ATDSTAT2_CCF_MASK               63U
#define ATDSTAT2_CCF_BITNUM             0U


/*** ATDDIEN - ATD  Input Enable Register; 0x0000007C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDIENH - ATD  Input Enable Register High; 0x0000007C ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } ATDDIENHSTR;
    #define ATDDIENH                    _ATDDIEN.Overlap_STR.ATDDIENHSTR.Byte
    

    /*** ATDDIENL - ATD  Input Enable Register Low; 0x0000007D ***/
    union {
      byte Byte;
      struct {
        byte IEN0        :1;                                       /* ATD Digital Input Enable on channel 0 */
        byte IEN1        :1;                                       /* ATD Digital Input Enable on channel 1 */
        byte IEN2        :1;                                       /* ATD Digital Input Enable on channel 2 */
        byte IEN3        :1;                                       /* ATD Digital Input Enable on channel 3 */
        byte IEN4        :1;                                       /* ATD Digital Input Enable on channel 4 */
        byte IEN5        :1;                                       /* ATD Digital Input Enable on channel 5 */
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpIEN :6;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ATDDIENLSTR;
    #define ATDDIENL                    _ATDDIEN.Overlap_STR.ATDDIENLSTR.Byte
    #define ATDDIENL_IEN0               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN0
    #define ATDDIENL_IEN1               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN1
    #define ATDDIENL_IEN2               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN2
    #define ATDDIENL_IEN3               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN3
    #define ATDDIENL_IEN4               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN4
    #define ATDDIENL_IEN5               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN5
    #define ATDDIENL_IEN                _ATDDIEN.Overlap_STR.ATDDIENLSTR.MergedBits.grpIEN
    
    #define ATDDIENL_IEN0_MASK          1U
    #define ATDDIENL_IEN1_MASK          2U
    #define ATDDIENL_IEN2_MASK          4U
    #define ATDDIENL_IEN3_MASK          8U
    #define ATDDIENL_IEN4_MASK          16U
    #define ATDDIENL_IEN5_MASK          32U
    #define ATDDIENL_IEN_MASK           63U
    #define ATDDIENL_IEN_BITNUM         0U
    
  } Overlap_STR;

  struct {
    word IEN0        :1;                                       /* ATD Digital Input Enable on channel 0 */
    word IEN1        :1;                                       /* ATD Digital Input Enable on channel 1 */
    word IEN2        :1;                                       /* ATD Digital Input Enable on channel 2 */
    word IEN3        :1;                                       /* ATD Digital Input Enable on channel 3 */
    word IEN4        :1;                                       /* ATD Digital Input Enable on channel 4 */
    word IEN5        :1;                                       /* ATD Digital Input Enable on channel 5 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpIEN  :6;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ATDDIENSTR;
extern volatile ATDDIENSTR _ATDDIEN @(REG_BASE + 0x0000007CUL);
#define ATDDIEN                         _ATDDIEN.Word
#define ATDDIEN_IEN0                    _ATDDIEN.Bits.IEN0
#define ATDDIEN_IEN1                    _ATDDIEN.Bits.IEN1
#define ATDDIEN_IEN2                    _ATDDIEN.Bits.IEN2
#define ATDDIEN_IEN3                    _ATDDIEN.Bits.IEN3
#define ATDDIEN_IEN4                    _ATDDIEN.Bits.IEN4
#define ATDDIEN_IEN5                    _ATDDIEN.Bits.IEN5
#define ATDDIEN_IEN                     _ATDDIEN.MergedBits.grpIEN

#define ATDDIEN_IEN0_MASK               1U
#define ATDDIEN_IEN1_MASK               2U
#define ATDDIEN_IEN2_MASK               4U
#define ATDDIEN_IEN3_MASK               8U
#define ATDDIEN_IEN4_MASK               16U
#define ATDDIEN_IEN5_MASK               32U
#define ATDDIEN_IEN_MASK                63U
#define ATDDIEN_IEN_BITNUM              0U


/*** ATDCMPHT - ATD  Compare Higher Than Register; 0x0000007E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDCMPHTH - ATD  Compare Higher Than Register High; 0x0000007E ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } ATDCMPHTHSTR;
    #define ATDCMPHTH                   _ATDCMPHT.Overlap_STR.ATDCMPHTHSTR.Byte
    

    /*** ATDCMPHTL - ATD  Compare Higher Than Register Low; 0x0000007F ***/
    union {
      byte Byte;
      struct {
        byte CMPHT0      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 0 of a Sequence */
        byte CMPHT1      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 1 of a Sequence */
        byte CMPHT2      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 2 of a Sequence */
        byte CMPHT3      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 3 of a Sequence */
        byte CMPHT4      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 4 of a Sequence */
        byte CMPHT5      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 5 of a Sequence */
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpCMPHT :6;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ATDCMPHTLSTR;
    #define ATDCMPHTL                   _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Byte
    #define ATDCMPHTL_CMPHT0            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT0
    #define ATDCMPHTL_CMPHT1            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT1
    #define ATDCMPHTL_CMPHT2            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT2
    #define ATDCMPHTL_CMPHT3            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT3
    #define ATDCMPHTL_CMPHT4            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT4
    #define ATDCMPHTL_CMPHT5            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT5
    #define ATDCMPHTL_CMPHT             _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.MergedBits.grpCMPHT
    
    #define ATDCMPHTL_CMPHT0_MASK       1U
    #define ATDCMPHTL_CMPHT1_MASK       2U
    #define ATDCMPHTL_CMPHT2_MASK       4U
    #define ATDCMPHTL_CMPHT3_MASK       8U
    #define ATDCMPHTL_CMPHT4_MASK       16U
    #define ATDCMPHTL_CMPHT5_MASK       32U
    #define ATDCMPHTL_CMPHT_MASK        63U
    #define ATDCMPHTL_CMPHT_BITNUM      0U
    
  } Overlap_STR;

  struct {
    word CMPHT0      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 0 of a Sequence */
    word CMPHT1      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 1 of a Sequence */
    word CMPHT2      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 2 of a Sequence */
    word CMPHT3      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 3 of a Sequence */
    word CMPHT4      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 4 of a Sequence */
    word CMPHT5      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 5 of a Sequence */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpCMPHT :6;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ATDCMPHTSTR;
extern volatile ATDCMPHTSTR _ATDCMPHT @(REG_BASE + 0x0000007EUL);
#define ATDCMPHT                        _ATDCMPHT.Word
#define ATDCMPHT_CMPHT0                 _ATDCMPHT.Bits.CMPHT0
#define ATDCMPHT_CMPHT1                 _ATDCMPHT.Bits.CMPHT1
#define ATDCMPHT_CMPHT2                 _ATDCMPHT.Bits.CMPHT2
#define ATDCMPHT_CMPHT3                 _ATDCMPHT.Bits.CMPHT3
#define ATDCMPHT_CMPHT4                 _ATDCMPHT.Bits.CMPHT4
#define ATDCMPHT_CMPHT5                 _ATDCMPHT.Bits.CMPHT5
#define ATDCMPHT_CMPHT                  _ATDCMPHT.MergedBits.grpCMPHT

#define ATDCMPHT_CMPHT0_MASK            1U
#define ATDCMPHT_CMPHT1_MASK            2U
#define ATDCMPHT_CMPHT2_MASK            4U
#define ATDCMPHT_CMPHT3_MASK            8U
#define ATDCMPHT_CMPHT4_MASK            16U
#define ATDCMPHT_CMPHT5_MASK            32U
#define ATDCMPHT_CMPHT_MASK             63U
#define ATDCMPHT_CMPHT_BITNUM           0U


/*** ATDDR0 - ATD  Conversion Result Register 0; 0x00000080 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR0H - ATD  Conversion Result Register 0 High; 0x00000080 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR0HSTR;
    #define ATDDR0H                     _ATDDR0.Overlap_STR.ATDDR0HSTR.Byte
    #define ATDDR0H_BIT8                _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT8
    #define ATDDR0H_BIT9                _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT9
    #define ATDDR0H_BIT10               _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT10
    #define ATDDR0H_BIT11               _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT11
    #define ATDDR0H_BIT12               _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT12
    #define ATDDR0H_BIT13               _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT13
    #define ATDDR0H_BIT14               _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT14
    #define ATDDR0H_BIT15               _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT15
    
    #define ATDDR0H_BIT8_MASK           1U
    #define ATDDR0H_BIT9_MASK           2U
    #define ATDDR0H_BIT10_MASK          4U
    #define ATDDR0H_BIT11_MASK          8U
    #define ATDDR0H_BIT12_MASK          16U
    #define ATDDR0H_BIT13_MASK          32U
    #define ATDDR0H_BIT14_MASK          64U
    #define ATDDR0H_BIT15_MASK          128U
    

    /*** ATDDR0L - ATD  Conversion Result Register 0 Low; 0x00000081 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATDDR0LSTR;
    #define ATDDR0L                     _ATDDR0.Overlap_STR.ATDDR0LSTR.Byte
    #define ATDDR0L_BIT0                _ATDDR0.Overlap_STR.ATDDR0LSTR.Bits.BIT0
    #define ATDDR0L_BIT1                _ATDDR0.Overlap_STR.ATDDR0LSTR.Bits.BIT1
    #define ATDDR0L_BIT2                _ATDDR0.Overlap_STR.ATDDR0LSTR.Bits.BIT2
    #define ATDDR0L_BIT3                _ATDDR0.Overlap_STR.ATDDR0LSTR.Bits.BIT3
    #define ATDDR0L_BIT4                _ATDDR0.Overlap_STR.ATDDR0LSTR.Bits.BIT4
    #define ATDDR0L_BIT5                _ATDDR0.Overlap_STR.ATDDR0LSTR.Bits.BIT5
    #define ATDDR0L_BIT6                _ATDDR0.Overlap_STR.ATDDR0LSTR.Bits.BIT6
    #define ATDDR0L_BIT7                _ATDDR0.Overlap_STR.ATDDR0LSTR.Bits.BIT7
    
    #define ATDDR0L_BIT0_MASK           1U
    #define ATDDR0L_BIT1_MASK           2U
    #define ATDDR0L_BIT2_MASK           4U
    #define ATDDR0L_BIT3_MASK           8U
    #define ATDDR0L_BIT4_MASK           16U
    #define ATDDR0L_BIT5_MASK           32U
    #define ATDDR0L_BIT6_MASK           64U
    #define ATDDR0L_BIT7_MASK           128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATDDR0STR;
extern volatile ATDDR0STR _ATDDR0 @(REG_BASE + 0x00000080UL);
#define ATDDR0                          _ATDDR0.Word
#define ATDDR0_BIT0                     _ATDDR0.Bits.BIT0
#define ATDDR0_BIT1                     _ATDDR0.Bits.BIT1
#define ATDDR0_BIT2                     _ATDDR0.Bits.BIT2
#define ATDDR0_BIT3                     _ATDDR0.Bits.BIT3
#define ATDDR0_BIT4                     _ATDDR0.Bits.BIT4
#define ATDDR0_BIT5                     _ATDDR0.Bits.BIT5
#define ATDDR0_BIT6                     _ATDDR0.Bits.BIT6
#define ATDDR0_BIT7                     _ATDDR0.Bits.BIT7
#define ATDDR0_BIT8                     _ATDDR0.Bits.BIT8
#define ATDDR0_BIT9                     _ATDDR0.Bits.BIT9
#define ATDDR0_BIT10                    _ATDDR0.Bits.BIT10
#define ATDDR0_BIT11                    _ATDDR0.Bits.BIT11
#define ATDDR0_BIT12                    _ATDDR0.Bits.BIT12
#define ATDDR0_BIT13                    _ATDDR0.Bits.BIT13
#define ATDDR0_BIT14                    _ATDDR0.Bits.BIT14
#define ATDDR0_BIT15                    _ATDDR0.Bits.BIT15
/* ATDDR_ARR: Access 6 ATDDRx registers in an array */
#define ATDDR_ARR                       ((volatile word *) &ATDDR0)

#define ATDDR0_BIT0_MASK                1U
#define ATDDR0_BIT1_MASK                2U
#define ATDDR0_BIT2_MASK                4U
#define ATDDR0_BIT3_MASK                8U
#define ATDDR0_BIT4_MASK                16U
#define ATDDR0_BIT5_MASK                32U
#define ATDDR0_BIT6_MASK                64U
#define ATDDR0_BIT7_MASK                128U
#define ATDDR0_BIT8_MASK                256U
#define ATDDR0_BIT9_MASK                512U
#define ATDDR0_BIT10_MASK               1024U
#define ATDDR0_BIT11_MASK               2048U
#define ATDDR0_BIT12_MASK               4096U
#define ATDDR0_BIT13_MASK               8192U
#define ATDDR0_BIT14_MASK               16384U
#define ATDDR0_BIT15_MASK               32768U


/*** ATDDR1 - ATD  Conversion Result Register 1; 0x00000082 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR1H - ATD  Conversion Result Register 1 High; 0x00000082 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR1HSTR;
    #define ATDDR1H                     _ATDDR1.Overlap_STR.ATDDR1HSTR.Byte
    #define ATDDR1H_BIT8                _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT8
    #define ATDDR1H_BIT9                _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT9
    #define ATDDR1H_BIT10               _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT10
    #define ATDDR1H_BIT11               _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT11
    #define ATDDR1H_BIT12               _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT12
    #define ATDDR1H_BIT13               _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT13
    #define ATDDR1H_BIT14               _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT14
    #define ATDDR1H_BIT15               _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT15
    
    #define ATDDR1H_BIT8_MASK           1U
    #define ATDDR1H_BIT9_MASK           2U
    #define ATDDR1H_BIT10_MASK          4U
    #define ATDDR1H_BIT11_MASK          8U
    #define ATDDR1H_BIT12_MASK          16U
    #define ATDDR1H_BIT13_MASK          32U
    #define ATDDR1H_BIT14_MASK          64U
    #define ATDDR1H_BIT15_MASK          128U
    

    /*** ATDDR1L - ATD  Conversion Result Register 1 Low; 0x00000083 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATDDR1LSTR;
    #define ATDDR1L                     _ATDDR1.Overlap_STR.ATDDR1LSTR.Byte
    #define ATDDR1L_BIT0                _ATDDR1.Overlap_STR.ATDDR1LSTR.Bits.BIT0
    #define ATDDR1L_BIT1                _ATDDR1.Overlap_STR.ATDDR1LSTR.Bits.BIT1
    #define ATDDR1L_BIT2                _ATDDR1.Overlap_STR.ATDDR1LSTR.Bits.BIT2
    #define ATDDR1L_BIT3                _ATDDR1.Overlap_STR.ATDDR1LSTR.Bits.BIT3
    #define ATDDR1L_BIT4                _ATDDR1.Overlap_STR.ATDDR1LSTR.Bits.BIT4
    #define ATDDR1L_BIT5                _ATDDR1.Overlap_STR.ATDDR1LSTR.Bits.BIT5
    #define ATDDR1L_BIT6                _ATDDR1.Overlap_STR.ATDDR1LSTR.Bits.BIT6
    #define ATDDR1L_BIT7                _ATDDR1.Overlap_STR.ATDDR1LSTR.Bits.BIT7
    
    #define ATDDR1L_BIT0_MASK           1U
    #define ATDDR1L_BIT1_MASK           2U
    #define ATDDR1L_BIT2_MASK           4U
    #define ATDDR1L_BIT3_MASK           8U
    #define ATDDR1L_BIT4_MASK           16U
    #define ATDDR1L_BIT5_MASK           32U
    #define ATDDR1L_BIT6_MASK           64U
    #define ATDDR1L_BIT7_MASK           128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATDDR1STR;
extern volatile ATDDR1STR _ATDDR1 @(REG_BASE + 0x00000082UL);
#define ATDDR1                          _ATDDR1.Word
#define ATDDR1_BIT0                     _ATDDR1.Bits.BIT0
#define ATDDR1_BIT1                     _ATDDR1.Bits.BIT1
#define ATDDR1_BIT2                     _ATDDR1.Bits.BIT2
#define ATDDR1_BIT3                     _ATDDR1.Bits.BIT3
#define ATDDR1_BIT4                     _ATDDR1.Bits.BIT4
#define ATDDR1_BIT5                     _ATDDR1.Bits.BIT5
#define ATDDR1_BIT6                     _ATDDR1.Bits.BIT6
#define ATDDR1_BIT7                     _ATDDR1.Bits.BIT7
#define ATDDR1_BIT8                     _ATDDR1.Bits.BIT8
#define ATDDR1_BIT9                     _ATDDR1.Bits.BIT9
#define ATDDR1_BIT10                    _ATDDR1.Bits.BIT10
#define ATDDR1_BIT11                    _ATDDR1.Bits.BIT11
#define ATDDR1_BIT12                    _ATDDR1.Bits.BIT12
#define ATDDR1_BIT13                    _ATDDR1.Bits.BIT13
#define ATDDR1_BIT14                    _ATDDR1.Bits.BIT14
#define ATDDR1_BIT15                    _ATDDR1.Bits.BIT15

#define ATDDR1_BIT0_MASK                1U
#define ATDDR1_BIT1_MASK                2U
#define ATDDR1_BIT2_MASK                4U
#define ATDDR1_BIT3_MASK                8U
#define ATDDR1_BIT4_MASK                16U
#define ATDDR1_BIT5_MASK                32U
#define ATDDR1_BIT6_MASK                64U
#define ATDDR1_BIT7_MASK                128U
#define ATDDR1_BIT8_MASK                256U
#define ATDDR1_BIT9_MASK                512U
#define ATDDR1_BIT10_MASK               1024U
#define ATDDR1_BIT11_MASK               2048U
#define ATDDR1_BIT12_MASK               4096U
#define ATDDR1_BIT13_MASK               8192U
#define ATDDR1_BIT14_MASK               16384U
#define ATDDR1_BIT15_MASK               32768U


/*** ATDDR2 - ATD  Conversion Result Register 2; 0x00000084 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR2H - ATD  Conversion Result Register 2 High; 0x00000084 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR2HSTR;
    #define ATDDR2H                     _ATDDR2.Overlap_STR.ATDDR2HSTR.Byte
    #define ATDDR2H_BIT8                _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT8
    #define ATDDR2H_BIT9                _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT9
    #define ATDDR2H_BIT10               _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT10
    #define ATDDR2H_BIT11               _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT11
    #define ATDDR2H_BIT12               _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT12
    #define ATDDR2H_BIT13               _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT13
    #define ATDDR2H_BIT14               _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT14
    #define ATDDR2H_BIT15               _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT15
    
    #define ATDDR2H_BIT8_MASK           1U
    #define ATDDR2H_BIT9_MASK           2U
    #define ATDDR2H_BIT10_MASK          4U
    #define ATDDR2H_BIT11_MASK          8U
    #define ATDDR2H_BIT12_MASK          16U
    #define ATDDR2H_BIT13_MASK          32U
    #define ATDDR2H_BIT14_MASK          64U
    #define ATDDR2H_BIT15_MASK          128U
    

    /*** ATDDR2L - ATD  Conversion Result Register 2 Low; 0x00000085 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATDDR2LSTR;
    #define ATDDR2L                     _ATDDR2.Overlap_STR.ATDDR2LSTR.Byte
    #define ATDDR2L_BIT0                _ATDDR2.Overlap_STR.ATDDR2LSTR.Bits.BIT0
    #define ATDDR2L_BIT1                _ATDDR2.Overlap_STR.ATDDR2LSTR.Bits.BIT1
    #define ATDDR2L_BIT2                _ATDDR2.Overlap_STR.ATDDR2LSTR.Bits.BIT2
    #define ATDDR2L_BIT3                _ATDDR2.Overlap_STR.ATDDR2LSTR.Bits.BIT3
    #define ATDDR2L_BIT4                _ATDDR2.Overlap_STR.ATDDR2LSTR.Bits.BIT4
    #define ATDDR2L_BIT5                _ATDDR2.Overlap_STR.ATDDR2LSTR.Bits.BIT5
    #define ATDDR2L_BIT6                _ATDDR2.Overlap_STR.ATDDR2LSTR.Bits.BIT6
    #define ATDDR2L_BIT7                _ATDDR2.Overlap_STR.ATDDR2LSTR.Bits.BIT7
    
    #define ATDDR2L_BIT0_MASK           1U
    #define ATDDR2L_BIT1_MASK           2U
    #define ATDDR2L_BIT2_MASK           4U
    #define ATDDR2L_BIT3_MASK           8U
    #define ATDDR2L_BIT4_MASK           16U
    #define ATDDR2L_BIT5_MASK           32U
    #define ATDDR2L_BIT6_MASK           64U
    #define ATDDR2L_BIT7_MASK           128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATDDR2STR;
extern volatile ATDDR2STR _ATDDR2 @(REG_BASE + 0x00000084UL);
#define ATDDR2                          _ATDDR2.Word
#define ATDDR2_BIT0                     _ATDDR2.Bits.BIT0
#define ATDDR2_BIT1                     _ATDDR2.Bits.BIT1
#define ATDDR2_BIT2                     _ATDDR2.Bits.BIT2
#define ATDDR2_BIT3                     _ATDDR2.Bits.BIT3
#define ATDDR2_BIT4                     _ATDDR2.Bits.BIT4
#define ATDDR2_BIT5                     _ATDDR2.Bits.BIT5
#define ATDDR2_BIT6                     _ATDDR2.Bits.BIT6
#define ATDDR2_BIT7                     _ATDDR2.Bits.BIT7
#define ATDDR2_BIT8                     _ATDDR2.Bits.BIT8
#define ATDDR2_BIT9                     _ATDDR2.Bits.BIT9
#define ATDDR2_BIT10                    _ATDDR2.Bits.BIT10
#define ATDDR2_BIT11                    _ATDDR2.Bits.BIT11
#define ATDDR2_BIT12                    _ATDDR2.Bits.BIT12
#define ATDDR2_BIT13                    _ATDDR2.Bits.BIT13
#define ATDDR2_BIT14                    _ATDDR2.Bits.BIT14
#define ATDDR2_BIT15                    _ATDDR2.Bits.BIT15

#define ATDDR2_BIT0_MASK                1U
#define ATDDR2_BIT1_MASK                2U
#define ATDDR2_BIT2_MASK                4U
#define ATDDR2_BIT3_MASK                8U
#define ATDDR2_BIT4_MASK                16U
#define ATDDR2_BIT5_MASK                32U
#define ATDDR2_BIT6_MASK                64U
#define ATDDR2_BIT7_MASK                128U
#define ATDDR2_BIT8_MASK                256U
#define ATDDR2_BIT9_MASK                512U
#define ATDDR2_BIT10_MASK               1024U
#define ATDDR2_BIT11_MASK               2048U
#define ATDDR2_BIT12_MASK               4096U
#define ATDDR2_BIT13_MASK               8192U
#define ATDDR2_BIT14_MASK               16384U
#define ATDDR2_BIT15_MASK               32768U


/*** ATDDR3 - ATD  Conversion Result Register 3; 0x00000086 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR3H - ATD  Conversion Result Register 3 High; 0x00000086 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR3HSTR;
    #define ATDDR3H                     _ATDDR3.Overlap_STR.ATDDR3HSTR.Byte
    #define ATDDR3H_BIT8                _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT8
    #define ATDDR3H_BIT9                _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT9
    #define ATDDR3H_BIT10               _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT10
    #define ATDDR3H_BIT11               _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT11
    #define ATDDR3H_BIT12               _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT12
    #define ATDDR3H_BIT13               _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT13
    #define ATDDR3H_BIT14               _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT14
    #define ATDDR3H_BIT15               _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT15
    
    #define ATDDR3H_BIT8_MASK           1U
    #define ATDDR3H_BIT9_MASK           2U
    #define ATDDR3H_BIT10_MASK          4U
    #define ATDDR3H_BIT11_MASK          8U
    #define ATDDR3H_BIT12_MASK          16U
    #define ATDDR3H_BIT13_MASK          32U
    #define ATDDR3H_BIT14_MASK          64U
    #define ATDDR3H_BIT15_MASK          128U
    

    /*** ATDDR3L - ATD  Conversion Result Register 3 Low; 0x00000087 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATDDR3LSTR;
    #define ATDDR3L                     _ATDDR3.Overlap_STR.ATDDR3LSTR.Byte
    #define ATDDR3L_BIT0                _ATDDR3.Overlap_STR.ATDDR3LSTR.Bits.BIT0
    #define ATDDR3L_BIT1                _ATDDR3.Overlap_STR.ATDDR3LSTR.Bits.BIT1
    #define ATDDR3L_BIT2                _ATDDR3.Overlap_STR.ATDDR3LSTR.Bits.BIT2
    #define ATDDR3L_BIT3                _ATDDR3.Overlap_STR.ATDDR3LSTR.Bits.BIT3
    #define ATDDR3L_BIT4                _ATDDR3.Overlap_STR.ATDDR3LSTR.Bits.BIT4
    #define ATDDR3L_BIT5                _ATDDR3.Overlap_STR.ATDDR3LSTR.Bits.BIT5
    #define ATDDR3L_BIT6                _ATDDR3.Overlap_STR.ATDDR3LSTR.Bits.BIT6
    #define ATDDR3L_BIT7                _ATDDR3.Overlap_STR.ATDDR3LSTR.Bits.BIT7
    
    #define ATDDR3L_BIT0_MASK           1U
    #define ATDDR3L_BIT1_MASK           2U
    #define ATDDR3L_BIT2_MASK           4U
    #define ATDDR3L_BIT3_MASK           8U
    #define ATDDR3L_BIT4_MASK           16U
    #define ATDDR3L_BIT5_MASK           32U
    #define ATDDR3L_BIT6_MASK           64U
    #define ATDDR3L_BIT7_MASK           128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATDDR3STR;
extern volatile ATDDR3STR _ATDDR3 @(REG_BASE + 0x00000086UL);
#define ATDDR3                          _ATDDR3.Word
#define ATDDR3_BIT0                     _ATDDR3.Bits.BIT0
#define ATDDR3_BIT1                     _ATDDR3.Bits.BIT1
#define ATDDR3_BIT2                     _ATDDR3.Bits.BIT2
#define ATDDR3_BIT3                     _ATDDR3.Bits.BIT3
#define ATDDR3_BIT4                     _ATDDR3.Bits.BIT4
#define ATDDR3_BIT5                     _ATDDR3.Bits.BIT5
#define ATDDR3_BIT6                     _ATDDR3.Bits.BIT6
#define ATDDR3_BIT7                     _ATDDR3.Bits.BIT7
#define ATDDR3_BIT8                     _ATDDR3.Bits.BIT8
#define ATDDR3_BIT9                     _ATDDR3.Bits.BIT9
#define ATDDR3_BIT10                    _ATDDR3.Bits.BIT10
#define ATDDR3_BIT11                    _ATDDR3.Bits.BIT11
#define ATDDR3_BIT12                    _ATDDR3.Bits.BIT12
#define ATDDR3_BIT13                    _ATDDR3.Bits.BIT13
#define ATDDR3_BIT14                    _ATDDR3.Bits.BIT14
#define ATDDR3_BIT15                    _ATDDR3.Bits.BIT15

#define ATDDR3_BIT0_MASK                1U
#define ATDDR3_BIT1_MASK                2U
#define ATDDR3_BIT2_MASK                4U
#define ATDDR3_BIT3_MASK                8U
#define ATDDR3_BIT4_MASK                16U
#define ATDDR3_BIT5_MASK                32U
#define ATDDR3_BIT6_MASK                64U
#define ATDDR3_BIT7_MASK                128U
#define ATDDR3_BIT8_MASK                256U
#define ATDDR3_BIT9_MASK                512U
#define ATDDR3_BIT10_MASK               1024U
#define ATDDR3_BIT11_MASK               2048U
#define ATDDR3_BIT12_MASK               4096U
#define ATDDR3_BIT13_MASK               8192U
#define ATDDR3_BIT14_MASK               16384U
#define ATDDR3_BIT15_MASK               32768U


/*** ATDDR4 - ATD  Conversion Result Register 4; 0x00000088 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR4H - ATD  Conversion Result Register 4 High; 0x00000088 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR4HSTR;
    #define ATDDR4H                     _ATDDR4.Overlap_STR.ATDDR4HSTR.Byte
    #define ATDDR4H_BIT8                _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT8
    #define ATDDR4H_BIT9                _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT9
    #define ATDDR4H_BIT10               _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT10
    #define ATDDR4H_BIT11               _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT11
    #define ATDDR4H_BIT12               _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT12
    #define ATDDR4H_BIT13               _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT13
    #define ATDDR4H_BIT14               _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT14
    #define ATDDR4H_BIT15               _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT15
    
    #define ATDDR4H_BIT8_MASK           1U
    #define ATDDR4H_BIT9_MASK           2U
    #define ATDDR4H_BIT10_MASK          4U
    #define ATDDR4H_BIT11_MASK          8U
    #define ATDDR4H_BIT12_MASK          16U
    #define ATDDR4H_BIT13_MASK          32U
    #define ATDDR4H_BIT14_MASK          64U
    #define ATDDR4H_BIT15_MASK          128U
    

    /*** ATDDR4L - ATD  Conversion Result Register 4 Low; 0x00000089 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATDDR4LSTR;
    #define ATDDR4L                     _ATDDR4.Overlap_STR.ATDDR4LSTR.Byte
    #define ATDDR4L_BIT0                _ATDDR4.Overlap_STR.ATDDR4LSTR.Bits.BIT0
    #define ATDDR4L_BIT1                _ATDDR4.Overlap_STR.ATDDR4LSTR.Bits.BIT1
    #define ATDDR4L_BIT2                _ATDDR4.Overlap_STR.ATDDR4LSTR.Bits.BIT2
    #define ATDDR4L_BIT3                _ATDDR4.Overlap_STR.ATDDR4LSTR.Bits.BIT3
    #define ATDDR4L_BIT4                _ATDDR4.Overlap_STR.ATDDR4LSTR.Bits.BIT4
    #define ATDDR4L_BIT5                _ATDDR4.Overlap_STR.ATDDR4LSTR.Bits.BIT5
    #define ATDDR4L_BIT6                _ATDDR4.Overlap_STR.ATDDR4LSTR.Bits.BIT6
    #define ATDDR4L_BIT7                _ATDDR4.Overlap_STR.ATDDR4LSTR.Bits.BIT7
    
    #define ATDDR4L_BIT0_MASK           1U
    #define ATDDR4L_BIT1_MASK           2U
    #define ATDDR4L_BIT2_MASK           4U
    #define ATDDR4L_BIT3_MASK           8U
    #define ATDDR4L_BIT4_MASK           16U
    #define ATDDR4L_BIT5_MASK           32U
    #define ATDDR4L_BIT6_MASK           64U
    #define ATDDR4L_BIT7_MASK           128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATDDR4STR;
extern volatile ATDDR4STR _ATDDR4 @(REG_BASE + 0x00000088UL);
#define ATDDR4                          _ATDDR4.Word
#define ATDDR4_BIT0                     _ATDDR4.Bits.BIT0
#define ATDDR4_BIT1                     _ATDDR4.Bits.BIT1
#define ATDDR4_BIT2                     _ATDDR4.Bits.BIT2
#define ATDDR4_BIT3                     _ATDDR4.Bits.BIT3
#define ATDDR4_BIT4                     _ATDDR4.Bits.BIT4
#define ATDDR4_BIT5                     _ATDDR4.Bits.BIT5
#define ATDDR4_BIT6                     _ATDDR4.Bits.BIT6
#define ATDDR4_BIT7                     _ATDDR4.Bits.BIT7
#define ATDDR4_BIT8                     _ATDDR4.Bits.BIT8
#define ATDDR4_BIT9                     _ATDDR4.Bits.BIT9
#define ATDDR4_BIT10                    _ATDDR4.Bits.BIT10
#define ATDDR4_BIT11                    _ATDDR4.Bits.BIT11
#define ATDDR4_BIT12                    _ATDDR4.Bits.BIT12
#define ATDDR4_BIT13                    _ATDDR4.Bits.BIT13
#define ATDDR4_BIT14                    _ATDDR4.Bits.BIT14
#define ATDDR4_BIT15                    _ATDDR4.Bits.BIT15

#define ATDDR4_BIT0_MASK                1U
#define ATDDR4_BIT1_MASK                2U
#define ATDDR4_BIT2_MASK                4U
#define ATDDR4_BIT3_MASK                8U
#define ATDDR4_BIT4_MASK                16U
#define ATDDR4_BIT5_MASK                32U
#define ATDDR4_BIT6_MASK                64U
#define ATDDR4_BIT7_MASK                128U
#define ATDDR4_BIT8_MASK                256U
#define ATDDR4_BIT9_MASK                512U
#define ATDDR4_BIT10_MASK               1024U
#define ATDDR4_BIT11_MASK               2048U
#define ATDDR4_BIT12_MASK               4096U
#define ATDDR4_BIT13_MASK               8192U
#define ATDDR4_BIT14_MASK               16384U
#define ATDDR4_BIT15_MASK               32768U


/*** ATDDR5 - ATD  Conversion Result Register 5; 0x0000008A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR5H - ATD  Conversion Result Register 5 High; 0x0000008A ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR5HSTR;
    #define ATDDR5H                     _ATDDR5.Overlap_STR.ATDDR5HSTR.Byte
    #define ATDDR5H_BIT8                _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT8
    #define ATDDR5H_BIT9                _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT9
    #define ATDDR5H_BIT10               _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT10
    #define ATDDR5H_BIT11               _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT11
    #define ATDDR5H_BIT12               _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT12
    #define ATDDR5H_BIT13               _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT13
    #define ATDDR5H_BIT14               _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT14
    #define ATDDR5H_BIT15               _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT15
    
    #define ATDDR5H_BIT8_MASK           1U
    #define ATDDR5H_BIT9_MASK           2U
    #define ATDDR5H_BIT10_MASK          4U
    #define ATDDR5H_BIT11_MASK          8U
    #define ATDDR5H_BIT12_MASK          16U
    #define ATDDR5H_BIT13_MASK          32U
    #define ATDDR5H_BIT14_MASK          64U
    #define ATDDR5H_BIT15_MASK          128U
    

    /*** ATDDR5L - ATD  Conversion Result Register 5 Low; 0x0000008B ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATDDR5LSTR;
    #define ATDDR5L                     _ATDDR5.Overlap_STR.ATDDR5LSTR.Byte
    #define ATDDR5L_BIT0                _ATDDR5.Overlap_STR.ATDDR5LSTR.Bits.BIT0
    #define ATDDR5L_BIT1                _ATDDR5.Overlap_STR.ATDDR5LSTR.Bits.BIT1
    #define ATDDR5L_BIT2                _ATDDR5.Overlap_STR.ATDDR5LSTR.Bits.BIT2
    #define ATDDR5L_BIT3                _ATDDR5.Overlap_STR.ATDDR5LSTR.Bits.BIT3
    #define ATDDR5L_BIT4                _ATDDR5.Overlap_STR.ATDDR5LSTR.Bits.BIT4
    #define ATDDR5L_BIT5                _ATDDR5.Overlap_STR.ATDDR5LSTR.Bits.BIT5
    #define ATDDR5L_BIT6                _ATDDR5.Overlap_STR.ATDDR5LSTR.Bits.BIT6
    #define ATDDR5L_BIT7                _ATDDR5.Overlap_STR.ATDDR5LSTR.Bits.BIT7
    
    #define ATDDR5L_BIT0_MASK           1U
    #define ATDDR5L_BIT1_MASK           2U
    #define ATDDR5L_BIT2_MASK           4U
    #define ATDDR5L_BIT3_MASK           8U
    #define ATDDR5L_BIT4_MASK           16U
    #define ATDDR5L_BIT5_MASK           32U
    #define ATDDR5L_BIT6_MASK           64U
    #define ATDDR5L_BIT7_MASK           128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATDDR5STR;
extern volatile ATDDR5STR _ATDDR5 @(REG_BASE + 0x0000008AUL);
#define ATDDR5                          _ATDDR5.Word
#define ATDDR5_BIT0                     _ATDDR5.Bits.BIT0
#define ATDDR5_BIT1                     _ATDDR5.Bits.BIT1
#define ATDDR5_BIT2                     _ATDDR5.Bits.BIT2
#define ATDDR5_BIT3                     _ATDDR5.Bits.BIT3
#define ATDDR5_BIT4                     _ATDDR5.Bits.BIT4
#define ATDDR5_BIT5                     _ATDDR5.Bits.BIT5
#define ATDDR5_BIT6                     _ATDDR5.Bits.BIT6
#define ATDDR5_BIT7                     _ATDDR5.Bits.BIT7
#define ATDDR5_BIT8                     _ATDDR5.Bits.BIT8
#define ATDDR5_BIT9                     _ATDDR5.Bits.BIT9
#define ATDDR5_BIT10                    _ATDDR5.Bits.BIT10
#define ATDDR5_BIT11                    _ATDDR5.Bits.BIT11
#define ATDDR5_BIT12                    _ATDDR5.Bits.BIT12
#define ATDDR5_BIT13                    _ATDDR5.Bits.BIT13
#define ATDDR5_BIT14                    _ATDDR5.Bits.BIT14
#define ATDDR5_BIT15                    _ATDDR5.Bits.BIT15

#define ATDDR5_BIT0_MASK                1U
#define ATDDR5_BIT1_MASK                2U
#define ATDDR5_BIT2_MASK                4U
#define ATDDR5_BIT3_MASK                8U
#define ATDDR5_BIT4_MASK                16U
#define ATDDR5_BIT5_MASK                32U
#define ATDDR5_BIT6_MASK                64U
#define ATDDR5_BIT7_MASK                128U
#define ATDDR5_BIT8_MASK                256U
#define ATDDR5_BIT9_MASK                512U
#define ATDDR5_BIT10_MASK               1024U
#define ATDDR5_BIT11_MASK               2048U
#define ATDDR5_BIT12_MASK               4096U
#define ATDDR5_BIT13_MASK               8192U
#define ATDDR5_BIT14_MASK               16384U
#define ATDDR5_BIT15_MASK               32768U


/*** PWME - PWM Enable Register; 0x000000A0 ***/
typedef union {
  byte Byte;
  struct {
    byte PWME0       :1;                                       /* Pulse Width Channel 0 Enable */
    byte PWME1       :1;                                       /* Pulse Width Channel 1 Enable */
    byte PWME2       :1;                                       /* Pulse Width Channel 2 Enable */
    byte PWME3       :1;                                       /* Pulse Width Channel 3 Enable */
    byte PWME4       :1;                                       /* Pulse Width Channel 4 Enable */
    byte PWME5       :1;                                       /* Pulse Width Channel 5 Enable */
    byte PWME6       :1;                                       /* Pulse Width Channel 6 Enable */
    byte PWME7       :1;                                       /* Pulse Width Channel 7 Enable */
  } Bits;
} PWMESTR;
extern volatile PWMESTR _PWME @(REG_BASE + 0x000000A0UL);
#define PWME                            _PWME.Byte
#define PWME_PWME0                      _PWME.Bits.PWME0
#define PWME_PWME1                      _PWME.Bits.PWME1
#define PWME_PWME2                      _PWME.Bits.PWME2
#define PWME_PWME3                      _PWME.Bits.PWME3
#define PWME_PWME4                      _PWME.Bits.PWME4
#define PWME_PWME5                      _PWME.Bits.PWME5
#define PWME_PWME6                      _PWME.Bits.PWME6
#define PWME_PWME7                      _PWME.Bits.PWME7

#define PWME_PWME0_MASK                 1U
#define PWME_PWME1_MASK                 2U
#define PWME_PWME2_MASK                 4U
#define PWME_PWME3_MASK                 8U
#define PWME_PWME4_MASK                 16U
#define PWME_PWME5_MASK                 32U
#define PWME_PWME6_MASK                 64U
#define PWME_PWME7_MASK                 128U


/*** PWMPOL - PWM Polarity Register; 0x000000A1 ***/
typedef union {
  byte Byte;
  struct {
    byte PPOL0       :1;                                       /* Pulse Width Channel 0 Polarity */
    byte PPOL1       :1;                                       /* Pulse Width Channel 1 Polarity */
    byte PPOL2       :1;                                       /* Pulse Width Channel 2 Polarity */
    byte PPOL3       :1;                                       /* Pulse Width Channel 3 Polarity */
    byte PPOL4       :1;                                       /* Pulse Width Channel 4 Polarity */
    byte PPOL5       :1;                                       /* Pulse Width Channel 5 Polarity */
    byte PPOL6       :1;                                       /* Pulse Width Channel 6 Polarity */
    byte PPOL7       :1;                                       /* Pulse Width Channel 7 Polarity */
  } Bits;
} PWMPOLSTR;
extern volatile PWMPOLSTR _PWMPOL @(REG_BASE + 0x000000A1UL);
#define PWMPOL                          _PWMPOL.Byte
#define PWMPOL_PPOL0                    _PWMPOL.Bits.PPOL0
#define PWMPOL_PPOL1                    _PWMPOL.Bits.PPOL1
#define PWMPOL_PPOL2                    _PWMPOL.Bits.PPOL2
#define PWMPOL_PPOL3                    _PWMPOL.Bits.PPOL3
#define PWMPOL_PPOL4                    _PWMPOL.Bits.PPOL4
#define PWMPOL_PPOL5                    _PWMPOL.Bits.PPOL5
#define PWMPOL_PPOL6                    _PWMPOL.Bits.PPOL6
#define PWMPOL_PPOL7                    _PWMPOL.Bits.PPOL7

#define PWMPOL_PPOL0_MASK               1U
#define PWMPOL_PPOL1_MASK               2U
#define PWMPOL_PPOL2_MASK               4U
#define PWMPOL_PPOL3_MASK               8U
#define PWMPOL_PPOL4_MASK               16U
#define PWMPOL_PPOL5_MASK               32U
#define PWMPOL_PPOL6_MASK               64U
#define PWMPOL_PPOL7_MASK               128U


/*** PWMCLK - PWM Clock Select Register; 0x000000A2 ***/
typedef union {
  byte Byte;
  struct {
    byte PCLK0       :1;                                       /* Pulse Width Channel 0 Clock Select */
    byte PCLK1       :1;                                       /* Pulse Width Channel 1 Clock Select */
    byte PCLK2       :1;                                       /* Pulse Width Channel 2 Clock Select */
    byte PCLK3       :1;                                       /* Pulse Width Channel 3 Clock Select */
    byte PCLK4       :1;                                       /* Pulse Width Channel 4 Clock Select */
    byte PCLK5       :1;                                       /* Pulse Width Channel 5 Clock Select */
    byte PCLK6       :1;                                       /* Pulse Width Channel 6 Clock Select */
    byte PCLK7       :1;                                       /* Pulse Width Channel 7 Clock Select */
  } Bits;
} PWMCLKSTR;
extern volatile PWMCLKSTR _PWMCLK @(REG_BASE + 0x000000A2UL);
#define PWMCLK                          _PWMCLK.Byte
#define PWMCLK_PCLK0                    _PWMCLK.Bits.PCLK0
#define PWMCLK_PCLK1                    _PWMCLK.Bits.PCLK1
#define PWMCLK_PCLK2                    _PWMCLK.Bits.PCLK2
#define PWMCLK_PCLK3                    _PWMCLK.Bits.PCLK3
#define PWMCLK_PCLK4                    _PWMCLK.Bits.PCLK4
#define PWMCLK_PCLK5                    _PWMCLK.Bits.PCLK5
#define PWMCLK_PCLK6                    _PWMCLK.Bits.PCLK6
#define PWMCLK_PCLK7                    _PWMCLK.Bits.PCLK7

#define PWMCLK_PCLK0_MASK               1U
#define PWMCLK_PCLK1_MASK               2U
#define PWMCLK_PCLK2_MASK               4U
#define PWMCLK_PCLK3_MASK               8U
#define PWMCLK_PCLK4_MASK               16U
#define PWMCLK_PCLK5_MASK               32U
#define PWMCLK_PCLK6_MASK               64U
#define PWMCLK_PCLK7_MASK               128U


/*** PWMPRCLK - PWM Prescale Clock Select Register; 0x000000A3 ***/
typedef union {
  byte Byte;
  struct {
    byte PCKA0       :1;                                       /* Prescaler Select for Clock A 0 */
    byte PCKA1       :1;                                       /* Prescaler Select for Clock A 1 */
    byte PCKA2       :1;                                       /* Prescaler Select for Clock A 2 */
    byte             :1; 
    byte PCKB0       :1;                                       /* Prescaler Select for Clock B 0 */
    byte PCKB1       :1;                                       /* Prescaler Select for Clock B 1 */
    byte PCKB2       :1;                                       /* Prescaler Select for Clock B 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPCKA :3;
    byte         :1;
    byte grpPCKB :3;
    byte         :1;
  } MergedBits;
} PWMPRCLKSTR;
extern volatile PWMPRCLKSTR _PWMPRCLK @(REG_BASE + 0x000000A3UL);
#define PWMPRCLK                        _PWMPRCLK.Byte
#define PWMPRCLK_PCKA0                  _PWMPRCLK.Bits.PCKA0
#define PWMPRCLK_PCKA1                  _PWMPRCLK.Bits.PCKA1
#define PWMPRCLK_PCKA2                  _PWMPRCLK.Bits.PCKA2
#define PWMPRCLK_PCKB0                  _PWMPRCLK.Bits.PCKB0
#define PWMPRCLK_PCKB1                  _PWMPRCLK.Bits.PCKB1
#define PWMPRCLK_PCKB2                  _PWMPRCLK.Bits.PCKB2
#define PWMPRCLK_PCKA                   _PWMPRCLK.MergedBits.grpPCKA
#define PWMPRCLK_PCKB                   _PWMPRCLK.MergedBits.grpPCKB

#define PWMPRCLK_PCKA0_MASK             1U
#define PWMPRCLK_PCKA1_MASK             2U
#define PWMPRCLK_PCKA2_MASK             4U
#define PWMPRCLK_PCKB0_MASK             16U
#define PWMPRCLK_PCKB1_MASK             32U
#define PWMPRCLK_PCKB2_MASK             64U
#define PWMPRCLK_PCKA_MASK              7U
#define PWMPRCLK_PCKA_BITNUM            0U
#define PWMPRCLK_PCKB_MASK              112U
#define PWMPRCLK_PCKB_BITNUM            4U


/*** PWMCAE - PWM Center Align Enable Register; 0x000000A4 ***/
typedef union {
  byte Byte;
  struct {
    byte CAE0        :1;                                       /* Center Aligned Output Mode on channel 0 */
    byte CAE1        :1;                                       /* Center Aligned Output Mode on channel 1 */
    byte CAE2        :1;                                       /* Center Aligned Output Mode on channel 2 */
    byte CAE3        :1;                                       /* Center Aligned Output Mode on channel 3 */
    byte CAE4        :1;                                       /* Center Aligned Output Mode on channel 4 */
    byte CAE5        :1;                                       /* Center Aligned Output Mode on channel 5 */
    byte CAE6        :1;                                       /* Center Aligned Output Mode on channel 6 */
    byte CAE7        :1;                                       /* Center Aligned Output Mode on channel 7 */
  } Bits;
} PWMCAESTR;
extern volatile PWMCAESTR _PWMCAE @(REG_BASE + 0x000000A4UL);
#define PWMCAE                          _PWMCAE.Byte
#define PWMCAE_CAE0                     _PWMCAE.Bits.CAE0
#define PWMCAE_CAE1                     _PWMCAE.Bits.CAE1
#define PWMCAE_CAE2                     _PWMCAE.Bits.CAE2
#define PWMCAE_CAE3                     _PWMCAE.Bits.CAE3
#define PWMCAE_CAE4                     _PWMCAE.Bits.CAE4
#define PWMCAE_CAE5                     _PWMCAE.Bits.CAE5
#define PWMCAE_CAE6                     _PWMCAE.Bits.CAE6
#define PWMCAE_CAE7                     _PWMCAE.Bits.CAE7

#define PWMCAE_CAE0_MASK                1U
#define PWMCAE_CAE1_MASK                2U
#define PWMCAE_CAE2_MASK                4U
#define PWMCAE_CAE3_MASK                8U
#define PWMCAE_CAE4_MASK                16U
#define PWMCAE_CAE5_MASK                32U
#define PWMCAE_CAE6_MASK                64U
#define PWMCAE_CAE7_MASK                128U


/*** PWMCTL - PWM Control Register; 0x000000A5 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte PFRZ        :1;                                       /* PWM Counters Stop in Freeze Mode */
    byte PSWAI       :1;                                       /* PWM Stops in Wait Mode */
    byte CON01       :1;                                       /* Concatenate channels 0 and 1 */
    byte CON23       :1;                                       /* Concatenate channels 2 and 3 */
    byte CON45       :1;                                       /* Concatenate channels 4 and 5 */
    byte CON67       :1;                                       /* Concatenate channels 6 and 7 */
  } Bits;
} PWMCTLSTR;
extern volatile PWMCTLSTR _PWMCTL @(REG_BASE + 0x000000A5UL);
#define PWMCTL                          _PWMCTL.Byte
#define PWMCTL_PFRZ                     _PWMCTL.Bits.PFRZ
#define PWMCTL_PSWAI                    _PWMCTL.Bits.PSWAI
#define PWMCTL_CON01                    _PWMCTL.Bits.CON01
#define PWMCTL_CON23                    _PWMCTL.Bits.CON23
#define PWMCTL_CON45                    _PWMCTL.Bits.CON45
#define PWMCTL_CON67                    _PWMCTL.Bits.CON67

#define PWMCTL_PFRZ_MASK                4U
#define PWMCTL_PSWAI_MASK               8U
#define PWMCTL_CON01_MASK               16U
#define PWMCTL_CON23_MASK               32U
#define PWMCTL_CON45_MASK               64U
#define PWMCTL_CON67_MASK               128U


/*** PWMCLKAB - PWM Clock Select Register; 0x000000A6 ***/
typedef union {
  byte Byte;
  struct {
    byte PCLKAB0     :1;                                       /* Pulse Width Channel 0 Clock A/B Select */
    byte PCLKAB1     :1;                                       /* Pulse Width Channel 1 Clock A/B Select */
    byte PCLKAB2     :1;                                       /* Pulse Width Channel 2 Clock A/B Select */
    byte PCLKAB3     :1;                                       /* Pulse Width Channel 3 Clock A/B Select */
    byte PCLKAB4     :1;                                       /* Pulse Width Channel 4 Clock A/B Select */
    byte PCLKAB5     :1;                                       /* Pulse Width Channel 5 Clock A/B Select */
    byte PCLKAB6     :1;                                       /* Pulse Width Channel 6 Clock A/B Select */
    byte PCLKAB7     :1;                                       /* Pulse Width Channel 7 Clock A/B Select */
  } Bits;
} PWMCLKABSTR;
extern volatile PWMCLKABSTR _PWMCLKAB @(REG_BASE + 0x000000A6UL);
#define PWMCLKAB                        _PWMCLKAB.Byte
#define PWMCLKAB_PCLKAB0                _PWMCLKAB.Bits.PCLKAB0
#define PWMCLKAB_PCLKAB1                _PWMCLKAB.Bits.PCLKAB1
#define PWMCLKAB_PCLKAB2                _PWMCLKAB.Bits.PCLKAB2
#define PWMCLKAB_PCLKAB3                _PWMCLKAB.Bits.PCLKAB3
#define PWMCLKAB_PCLKAB4                _PWMCLKAB.Bits.PCLKAB4
#define PWMCLKAB_PCLKAB5                _PWMCLKAB.Bits.PCLKAB5
#define PWMCLKAB_PCLKAB6                _PWMCLKAB.Bits.PCLKAB6
#define PWMCLKAB_PCLKAB7                _PWMCLKAB.Bits.PCLKAB7

#define PWMCLKAB_PCLKAB0_MASK           1U
#define PWMCLKAB_PCLKAB1_MASK           2U
#define PWMCLKAB_PCLKAB2_MASK           4U
#define PWMCLKAB_PCLKAB3_MASK           8U
#define PWMCLKAB_PCLKAB4_MASK           16U
#define PWMCLKAB_PCLKAB5_MASK           32U
#define PWMCLKAB_PCLKAB6_MASK           64U
#define PWMCLKAB_PCLKAB7_MASK           128U


/*** PWMSCLA - PWM Scale A Register; 0x000000A8 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* PWM Scale A Bit 0 */
    byte BIT1        :1;                                       /* PWM Scale A Bit 1 */
    byte BIT2        :1;                                       /* PWM Scale A Bit 2 */
    byte BIT3        :1;                                       /* PWM Scale A Bit 3 */
    byte BIT4        :1;                                       /* PWM Scale A Bit 4 */
    byte BIT5        :1;                                       /* PWM Scale A Bit 5 */
    byte BIT6        :1;                                       /* PWM Scale A Bit 6 */
    byte BIT7        :1;                                       /* PWM Scale A Bit 7 */
  } Bits;
} PWMSCLASTR;
extern volatile PWMSCLASTR _PWMSCLA @(REG_BASE + 0x000000A8UL);
#define PWMSCLA                         _PWMSCLA.Byte
#define PWMSCLA_BIT0                    _PWMSCLA.Bits.BIT0
#define PWMSCLA_BIT1                    _PWMSCLA.Bits.BIT1
#define PWMSCLA_BIT2                    _PWMSCLA.Bits.BIT2
#define PWMSCLA_BIT3                    _PWMSCLA.Bits.BIT3
#define PWMSCLA_BIT4                    _PWMSCLA.Bits.BIT4
#define PWMSCLA_BIT5                    _PWMSCLA.Bits.BIT5
#define PWMSCLA_BIT6                    _PWMSCLA.Bits.BIT6
#define PWMSCLA_BIT7                    _PWMSCLA.Bits.BIT7

#define PWMSCLA_BIT0_MASK               1U
#define PWMSCLA_BIT1_MASK               2U
#define PWMSCLA_BIT2_MASK               4U
#define PWMSCLA_BIT3_MASK               8U
#define PWMSCLA_BIT4_MASK               16U
#define PWMSCLA_BIT5_MASK               32U
#define PWMSCLA_BIT6_MASK               64U
#define PWMSCLA_BIT7_MASK               128U


/*** PWMSCLB - PWM Scale B Register; 0x000000A9 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* PWM Scale B Bit 0 */
    byte BIT1        :1;                                       /* PWM Scale B Bit 1 */
    byte BIT2        :1;                                       /* PWM Scale B Bit 2 */
    byte BIT3        :1;                                       /* PWM Scale B Bit 3 */
    byte BIT4        :1;                                       /* PWM Scale B Bit 4 */
    byte BIT5        :1;                                       /* PWM Scale B Bit 5 */
    byte BIT6        :1;                                       /* PWM Scale B Bit 6 */
    byte BIT7        :1;                                       /* PWM Scale B Bit 7 */
  } Bits;
} PWMSCLBSTR;
extern volatile PWMSCLBSTR _PWMSCLB @(REG_BASE + 0x000000A9UL);
#define PWMSCLB                         _PWMSCLB.Byte
#define PWMSCLB_BIT0                    _PWMSCLB.Bits.BIT0
#define PWMSCLB_BIT1                    _PWMSCLB.Bits.BIT1
#define PWMSCLB_BIT2                    _PWMSCLB.Bits.BIT2
#define PWMSCLB_BIT3                    _PWMSCLB.Bits.BIT3
#define PWMSCLB_BIT4                    _PWMSCLB.Bits.BIT4
#define PWMSCLB_BIT5                    _PWMSCLB.Bits.BIT5
#define PWMSCLB_BIT6                    _PWMSCLB.Bits.BIT6
#define PWMSCLB_BIT7                    _PWMSCLB.Bits.BIT7

#define PWMSCLB_BIT0_MASK               1U
#define PWMSCLB_BIT1_MASK               2U
#define PWMSCLB_BIT2_MASK               4U
#define PWMSCLB_BIT3_MASK               8U
#define PWMSCLB_BIT4_MASK               16U
#define PWMSCLB_BIT5_MASK               32U
#define PWMSCLB_BIT6_MASK               64U
#define PWMSCLB_BIT7_MASK               128U


/*** PWMCNT01 - PWM Channel Counter 01 Register; 0x000000AC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMCNT0 - PWM Channel Counter 0 Register; 0x000000AC ***/
    union {
      byte Byte;
    } PWMCNT0STR;
    #define PWMCNT0                     _PWMCNT01.Overlap_STR.PWMCNT0STR.Byte
    /* PWMCNT_ARR: Access 8 PWMCNTx registers in an array */
    #define PWMCNT_ARR                  ((volatile byte *) &PWMCNT0)
    

    /*** PWMCNT1 - PWM Channel Counter 1 Register; 0x000000AD ***/
    union {
      byte Byte;
    } PWMCNT1STR;
    #define PWMCNT1                     _PWMCNT01.Overlap_STR.PWMCNT1STR.Byte
    
  } Overlap_STR;

} PWMCNT01STR;
extern volatile PWMCNT01STR _PWMCNT01 @(REG_BASE + 0x000000ACUL);
#define PWMCNT01                        _PWMCNT01.Word


/*** PWMCNT23 - PWM Channel Counter 23 Register; 0x000000AE ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMCNT2 - PWM Channel Counter 2 Register; 0x000000AE ***/
    union {
      byte Byte;
    } PWMCNT2STR;
    #define PWMCNT2                     _PWMCNT23.Overlap_STR.PWMCNT2STR.Byte
    

    /*** PWMCNT3 - PWM Channel Counter 3 Register; 0x000000AF ***/
    union {
      byte Byte;
    } PWMCNT3STR;
    #define PWMCNT3                     _PWMCNT23.Overlap_STR.PWMCNT3STR.Byte
    
  } Overlap_STR;

} PWMCNT23STR;
extern volatile PWMCNT23STR _PWMCNT23 @(REG_BASE + 0x000000AEUL);
#define PWMCNT23                        _PWMCNT23.Word


/*** PWMCNT45 - PWM Channel Counter 45 Register; 0x000000B0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMCNT4 - PWM Channel Counter 4 Register; 0x000000B0 ***/
    union {
      byte Byte;
    } PWMCNT4STR;
    #define PWMCNT4                     _PWMCNT45.Overlap_STR.PWMCNT4STR.Byte
    

    /*** PWMCNT5 - PWM Channel Counter 5 Register; 0x000000B1 ***/
    union {
      byte Byte;
    } PWMCNT5STR;
    #define PWMCNT5                     _PWMCNT45.Overlap_STR.PWMCNT5STR.Byte
    
  } Overlap_STR;

} PWMCNT45STR;
extern volatile PWMCNT45STR _PWMCNT45 @(REG_BASE + 0x000000B0UL);
#define PWMCNT45                        _PWMCNT45.Word


/*** PWMCNT67 - PWM Channel Counter 67 Register; 0x000000B2 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMCNT6 - PWM Channel Counter 6 Register; 0x000000B2 ***/
    union {
      byte Byte;
    } PWMCNT6STR;
    #define PWMCNT6                     _PWMCNT67.Overlap_STR.PWMCNT6STR.Byte
    

    /*** PWMCNT7 - PWM Channel Counter 7 Register; 0x000000B3 ***/
    union {
      byte Byte;
    } PWMCNT7STR;
    #define PWMCNT7                     _PWMCNT67.Overlap_STR.PWMCNT7STR.Byte
    
  } Overlap_STR;

} PWMCNT67STR;
extern volatile PWMCNT67STR _PWMCNT67 @(REG_BASE + 0x000000B2UL);
#define PWMCNT67                        _PWMCNT67.Word


/*** PWMPER01 - PWM Channel Period 01 Register; 0x000000B4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMPER0 - PWM Channel Period 0 Register; 0x000000B4 ***/
    union {
      byte Byte;
    } PWMPER0STR;
    #define PWMPER0                     _PWMPER01.Overlap_STR.PWMPER0STR.Byte
    /* PWMPER_ARR: Access 8 PWMPERx registers in an array */
    #define PWMPER_ARR                  ((volatile byte *) &PWMPER0)
    

    /*** PWMPER1 - PWM Channel Period 1 Register; 0x000000B5 ***/
    union {
      byte Byte;
    } PWMPER1STR;
    #define PWMPER1                     _PWMPER01.Overlap_STR.PWMPER1STR.Byte
    
  } Overlap_STR;

} PWMPER01STR;
extern volatile PWMPER01STR _PWMPER01 @(REG_BASE + 0x000000B4UL);
#define PWMPER01                        _PWMPER01.Word


/*** PWMPER23 - PWM Channel Period 23 Register; 0x000000B6 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMPER2 - PWM Channel Period 2 Register; 0x000000B6 ***/
    union {
      byte Byte;
    } PWMPER2STR;
    #define PWMPER2                     _PWMPER23.Overlap_STR.PWMPER2STR.Byte
    

    /*** PWMPER3 - PWM Channel Period 3 Register; 0x000000B7 ***/
    union {
      byte Byte;
    } PWMPER3STR;
    #define PWMPER3                     _PWMPER23.Overlap_STR.PWMPER3STR.Byte
    
  } Overlap_STR;

} PWMPER23STR;
extern volatile PWMPER23STR _PWMPER23 @(REG_BASE + 0x000000B6UL);
#define PWMPER23                        _PWMPER23.Word


/*** PWMPER45 - PWM Channel Period 45 Register; 0x000000B8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMPER4 - PWM Channel Period 4 Register; 0x000000B8 ***/
    union {
      byte Byte;
    } PWMPER4STR;
    #define PWMPER4                     _PWMPER45.Overlap_STR.PWMPER4STR.Byte
    

    /*** PWMPER5 - PWM Channel Period 5 Register; 0x000000B9 ***/
    union {
      byte Byte;
    } PWMPER5STR;
    #define PWMPER5                     _PWMPER45.Overlap_STR.PWMPER5STR.Byte
    
  } Overlap_STR;

} PWMPER45STR;
extern volatile PWMPER45STR _PWMPER45 @(REG_BASE + 0x000000B8UL);
#define PWMPER45                        _PWMPER45.Word


/*** PWMPER67 - PWM Channel Period 67 Register; 0x000000BA ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMPER6 - PWM Channel Period 6 Register; 0x000000BA ***/
    union {
      byte Byte;
    } PWMPER6STR;
    #define PWMPER6                     _PWMPER67.Overlap_STR.PWMPER6STR.Byte
    

    /*** PWMPER7 - PWM Channel Period 7 Register; 0x000000BB ***/
    union {
      byte Byte;
    } PWMPER7STR;
    #define PWMPER7                     _PWMPER67.Overlap_STR.PWMPER7STR.Byte
    
  } Overlap_STR;

} PWMPER67STR;
extern volatile PWMPER67STR _PWMPER67 @(REG_BASE + 0x000000BAUL);
#define PWMPER67                        _PWMPER67.Word


/*** PWMDTY01 - PWM Channel Duty 01 Register; 0x000000BC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMDTY0 - PWM Channel Duty 0 Register; 0x000000BC ***/
    union {
      byte Byte;
    } PWMDTY0STR;
    #define PWMDTY0                     _PWMDTY01.Overlap_STR.PWMDTY0STR.Byte
    /* PWMDTY_ARR: Access 8 PWMDTYx registers in an array */
    #define PWMDTY_ARR                  ((volatile byte *) &PWMDTY0)
    

    /*** PWMDTY1 - PWM Channel Duty 1 Register; 0x000000BD ***/
    union {
      byte Byte;
    } PWMDTY1STR;
    #define PWMDTY1                     _PWMDTY01.Overlap_STR.PWMDTY1STR.Byte
    
  } Overlap_STR;

} PWMDTY01STR;
extern volatile PWMDTY01STR _PWMDTY01 @(REG_BASE + 0x000000BCUL);
#define PWMDTY01                        _PWMDTY01.Word


/*** PWMDTY23 - PWM Channel Duty 23 Register; 0x000000BE ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMDTY2 - PWM Channel Duty 2 Register; 0x000000BE ***/
    union {
      byte Byte;
    } PWMDTY2STR;
    #define PWMDTY2                     _PWMDTY23.Overlap_STR.PWMDTY2STR.Byte
    

    /*** PWMDTY3 - PWM Channel Duty 3 Register; 0x000000BF ***/
    union {
      byte Byte;
    } PWMDTY3STR;
    #define PWMDTY3                     _PWMDTY23.Overlap_STR.PWMDTY3STR.Byte
    
  } Overlap_STR;

} PWMDTY23STR;
extern volatile PWMDTY23STR _PWMDTY23 @(REG_BASE + 0x000000BEUL);
#define PWMDTY23                        _PWMDTY23.Word


/*** PWMDTY45 - PWM Channel Duty 45 Register; 0x000000C0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMDTY4 - PWM Channel Duty 4 Register; 0x000000C0 ***/
    union {
      byte Byte;
    } PWMDTY4STR;
    #define PWMDTY4                     _PWMDTY45.Overlap_STR.PWMDTY4STR.Byte
    

    /*** PWMDTY5 - PWM Channel Duty 5 Register; 0x000000C1 ***/
    union {
      byte Byte;
    } PWMDTY5STR;
    #define PWMDTY5                     _PWMDTY45.Overlap_STR.PWMDTY5STR.Byte
    
  } Overlap_STR;

} PWMDTY45STR;
extern volatile PWMDTY45STR _PWMDTY45 @(REG_BASE + 0x000000C0UL);
#define PWMDTY45                        _PWMDTY45.Word


/*** PWMDTY67 - PWM Channel Duty 67 Register; 0x000000C2 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMDTY6 - PWM Channel Duty 6 Register; 0x000000C2 ***/
    union {
      byte Byte;
    } PWMDTY6STR;
    #define PWMDTY6                     _PWMDTY67.Overlap_STR.PWMDTY6STR.Byte
    

    /*** PWMDTY7 - PWM Channel Duty 7 Register; 0x000000C3 ***/
    union {
      byte Byte;
    } PWMDTY7STR;
    #define PWMDTY7                     _PWMDTY67.Overlap_STR.PWMDTY7STR.Byte
    
  } Overlap_STR;

} PWMDTY67STR;
extern volatile PWMDTY67STR _PWMDTY67 @(REG_BASE + 0x000000C2UL);
#define PWMDTY67                        _PWMDTY67.Word


/*** SCI0BD - SCI 0 Baud Rate Register; 0x000000C8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI0ASR1 - SCI 0 Alternative Status Register 1; 0x000000C8 ***/
    union {
      byte Byte;
      union { /* Several registers at the same address */
        /*** SCI0ASR1 - SCI 0 Alternative Status Register 1; Several registers at the same address ***/
        union {
          struct {
            byte BKDIF       :1;                                       /* Break Detect Interrupt Flag */
            byte BERRIF      :1;                                       /* Bit Error Interrupt Flag */
            byte BERRV       :1;                                       /* Bit Error Value */
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte RXEDGIF     :1;                                       /* Receive Input Active Edge Interrupt Flag */
          } Bits;
        } SCI0ASR1STR;
        #define SCI0ASR1                _SCI0BD.Overlap_STR.SCI0ASR1STR.Byte
        #define SCI0ASR1_BKDIF          _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0ASR1STR.Bits.BKDIF
        #define SCI0ASR1_BERRIF         _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0ASR1STR.Bits.BERRIF
        #define SCI0ASR1_BERRV          _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0ASR1STR.Bits.BERRV
        #define SCI0ASR1_RXEDGIF        _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0ASR1STR.Bits.RXEDGIF
        
        #define SCI0ASR1_BKDIF_MASK     1U
        #define SCI0ASR1_BERRIF_MASK    2U
        #define SCI0ASR1_BERRV_MASK     4U
        #define SCI0ASR1_RXEDGIF_MASK   128U
        
        /*** SCI0BDH - SCI 0 Baud Rate Register High; Several registers at the same address ***/
        union {
          struct {
            byte SBR8        :1;                                       /* SCI Baud Rate Bit 8 */
            byte SBR9        :1;                                       /* SCI Baud Rate Bit 9 */
            byte SBR10       :1;                                       /* SCI Baud Rate Bit 10 */
            byte SBR11       :1;                                       /* SCI Baud Rate Bit 11 */
            byte SBR12       :1;                                       /* SCI Baud Rate Bit 12 */
            byte SBR13       :1;                                       /* SCI Baud Rate Bit 13 */
            byte SBR14       :1;                                       /* SCI Baud Rate Bit 14 */
            byte SBR15       :1;                                       /* SCI Baud Rate Bit 15 */
          } Bits;
        } SCI0BDHSTR;
        #define SCI0BDH                 _SCI0BD.Overlap_STR.SCI0ASR1STR.Byte
        #define SCI0BDH_SBR8            _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR8
        #define SCI0BDH_SBR9            _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR9
        #define SCI0BDH_SBR10           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR10
        #define SCI0BDH_SBR11           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR11
        #define SCI0BDH_SBR12           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR12
        #define SCI0BDH_SBR13           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR13
        #define SCI0BDH_SBR14           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR14
        #define SCI0BDH_SBR15           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR15
        
        #define SCI0BDH_SBR8_MASK       1U
        #define SCI0BDH_SBR9_MASK       2U
        #define SCI0BDH_SBR10_MASK      4U
        #define SCI0BDH_SBR11_MASK      8U
        #define SCI0BDH_SBR12_MASK      16U
        #define SCI0BDH_SBR13_MASK      32U
        #define SCI0BDH_SBR14_MASK      64U
        #define SCI0BDH_SBR15_MASK      128U
        
      } SameAddr_STR; /*Several registers at the same address */
    
    } SCI0ASR1STR;
    

    /*** SCI0ACR1 - SCI 0 Alternative Control Register 1; 0x000000C9 ***/
    union {
      byte Byte;
      union { /* Several registers at the same address */
        /*** SCI0ACR1 - SCI 0 Alternative Control Register 1; Several registers at the same address ***/
        union {
          struct {
            byte BKDIE       :1;                                       /* Break Detect Interrupt Enable */
            byte BERRIE      :1;                                       /* Bit Error Interrupt Enable */
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte RXEDGIE     :1;                                       /* Receive Input Active Edge Interrupt Enable */
          } Bits;
        } SCI0ACR1STR;
        #define SCI0ACR1                _SCI0BD.Overlap_STR.SCI0ACR1STR.Byte
        #define SCI0ACR1_BKDIE          _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0ACR1STR.Bits.BKDIE
        #define SCI0ACR1_BERRIE         _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0ACR1STR.Bits.BERRIE
        #define SCI0ACR1_RXEDGIE        _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0ACR1STR.Bits.RXEDGIE
        
        #define SCI0ACR1_BKDIE_MASK     1U
        #define SCI0ACR1_BERRIE_MASK    2U
        #define SCI0ACR1_RXEDGIE_MASK   128U
        
        /*** SCI0BDL - SCI 0 Baud Rate Register Low; Several registers at the same address ***/
        union {
          struct {
            byte SBR0        :1;                                       /* SCI Baud Rate Bit 0 */
            byte SBR1        :1;                                       /* SCI Baud Rate Bit 1 */
            byte SBR2        :1;                                       /* SCI Baud Rate Bit 2 */
            byte SBR3        :1;                                       /* SCI Baud Rate Bit 3 */
            byte SBR4        :1;                                       /* SCI Baud Rate Bit 4 */
            byte SBR5        :1;                                       /* SCI Baud Rate Bit 5 */
            byte SBR6        :1;                                       /* SCI Baud Rate Bit 6 */
            byte SBR7        :1;                                       /* SCI Baud Rate Bit 7 */
          } Bits;
        } SCI0BDLSTR;
        #define SCI0BDL                 _SCI0BD.Overlap_STR.SCI0ACR1STR.Byte
        #define SCI0BDL_SBR0            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR0
        #define SCI0BDL_SBR1            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR1
        #define SCI0BDL_SBR2            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR2
        #define SCI0BDL_SBR3            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR3
        #define SCI0BDL_SBR4            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR4
        #define SCI0BDL_SBR5            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR5
        #define SCI0BDL_SBR6            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR6
        #define SCI0BDL_SBR7            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR7
        
        #define SCI0BDL_SBR0_MASK       1U
        #define SCI0BDL_SBR1_MASK       2U
        #define SCI0BDL_SBR2_MASK       4U
        #define SCI0BDL_SBR3_MASK       8U
        #define SCI0BDL_SBR4_MASK       16U
        #define SCI0BDL_SBR5_MASK       32U
        #define SCI0BDL_SBR6_MASK       64U
        #define SCI0BDL_SBR7_MASK       128U
        
      } SameAddr_STR; /*Several registers at the same address */
    
    } SCI0ACR1STR;
    
  } Overlap_STR;

  struct {
    word SBR0        :1;                                       /* SCI Baud Rate Bit 0 */
    word SBR1        :1;                                       /* SCI Baud Rate Bit 1 */
    word SBR2        :1;                                       /* SCI Baud Rate Bit 2 */
    word SBR3        :1;                                       /* SCI Baud Rate Bit 3 */
    word SBR4        :1;                                       /* SCI Baud Rate Bit 4 */
    word SBR5        :1;                                       /* SCI Baud Rate Bit 5 */
    word SBR6        :1;                                       /* SCI Baud Rate Bit 6 */
    word SBR7        :1;                                       /* SCI Baud Rate Bit 7 */
    word SBR8        :1;                                       /* SCI Baud Rate Bit 8 */
    word SBR9        :1;                                       /* SCI Baud Rate Bit 9 */
    word SBR10       :1;                                       /* SCI Baud Rate Bit 10 */
    word SBR11       :1;                                       /* SCI Baud Rate Bit 11 */
    word SBR12       :1;                                       /* SCI Baud Rate Bit 12 */
    word SBR13       :1;                                       /* SCI Baud Rate Bit 13 */
    word SBR14       :1;                                       /* SCI Baud Rate Bit 14 */
    word SBR15       :1;                                       /* SCI Baud Rate Bit 15 */
  } Bits;
} SCI0BDSTR;
extern volatile SCI0BDSTR _SCI0BD @(REG_BASE + 0x000000C8UL);
#define SCI0BD                          _SCI0BD.Word
#define SCI0BD_SBR0                     _SCI0BD.Bits.SBR0
#define SCI0BD_SBR1                     _SCI0BD.Bits.SBR1
#define SCI0BD_SBR2                     _SCI0BD.Bits.SBR2
#define SCI0BD_SBR3                     _SCI0BD.Bits.SBR3
#define SCI0BD_SBR4                     _SCI0BD.Bits.SBR4
#define SCI0BD_SBR5                     _SCI0BD.Bits.SBR5
#define SCI0BD_SBR6                     _SCI0BD.Bits.SBR6
#define SCI0BD_SBR7                     _SCI0BD.Bits.SBR7
#define SCI0BD_SBR8                     _SCI0BD.Bits.SBR8
#define SCI0BD_SBR9                     _SCI0BD.Bits.SBR9
#define SCI0BD_SBR10                    _SCI0BD.Bits.SBR10
#define SCI0BD_SBR11                    _SCI0BD.Bits.SBR11
#define SCI0BD_SBR12                    _SCI0BD.Bits.SBR12
#define SCI0BD_SBR13                    _SCI0BD.Bits.SBR13
#define SCI0BD_SBR14                    _SCI0BD.Bits.SBR14
#define SCI0BD_SBR15                    _SCI0BD.Bits.SBR15

#define SCI0BD_SBR0_MASK                1U
#define SCI0BD_SBR1_MASK                2U
#define SCI0BD_SBR2_MASK                4U
#define SCI0BD_SBR3_MASK                8U
#define SCI0BD_SBR4_MASK                16U
#define SCI0BD_SBR5_MASK                32U
#define SCI0BD_SBR6_MASK                64U
#define SCI0BD_SBR7_MASK                128U
#define SCI0BD_SBR8_MASK                256U
#define SCI0BD_SBR9_MASK                512U
#define SCI0BD_SBR10_MASK               1024U
#define SCI0BD_SBR11_MASK               2048U
#define SCI0BD_SBR12_MASK               4096U
#define SCI0BD_SBR13_MASK               8192U
#define SCI0BD_SBR14_MASK               16384U
#define SCI0BD_SBR15_MASK               32768U


/*** SCI0ACR2 - SCI 0 Alternative Control Register 2; 0x000000CA ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** SCI0ACR2 - SCI 0 Alternative Control Register 2; Several registers at the same address ***/
    union {
      struct {
        byte BKDFE       :1;                                       /* Break Detect Feature Enable */
        byte BERRM0      :1;                                       /* Bit Error Mode 0 */
        byte BERRM1      :1;                                       /* Bit Error Mode 1 */
        byte             :1; 
        byte             :1; 
        byte TNP0        :1;                                       /* Transmitter Narrow Pulse Bit 0 */
        byte TNP1        :1;                                       /* Transmitter Narrow Pulse Bit 1 */
        byte IREN        :1;                                       /* Infrared Enable Bit */
      } Bits;
      struct {
        byte     :1;
        byte grpBERRM :2;
        byte     :1;
        byte     :1;
        byte grpTNP :2;
        byte     :1;
      } MergedBits;
    } SCI0ACR2STR;
    #define SCI0ACR2                    _SCI0ACR2.Byte
    #define SCI0ACR2_BKDFE              _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.BKDFE
    #define SCI0ACR2_BERRM0             _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.BERRM0
    #define SCI0ACR2_BERRM1             _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.BERRM1
    #define SCI0ACR2_TNP0               _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.TNP0
    #define SCI0ACR2_TNP1               _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.TNP1
    #define SCI0ACR2_IREN               _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.IREN
    #define SCI0ACR2_BERRM              _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.MergedBits.grpBERRM
    #define SCI0ACR2_TNP                _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.MergedBits.grpTNP
    
    #define SCI0ACR2_BKDFE_MASK         1U
    #define SCI0ACR2_BERRM0_MASK        2U
    #define SCI0ACR2_BERRM1_MASK        4U
    #define SCI0ACR2_TNP0_MASK          32U
    #define SCI0ACR2_TNP1_MASK          64U
    #define SCI0ACR2_IREN_MASK          128U
    #define SCI0ACR2_BERRM_MASK         6U
    #define SCI0ACR2_BERRM_BITNUM       1U
    #define SCI0ACR2_TNP_MASK           96U
    #define SCI0ACR2_TNP_BITNUM         5U
    
    /*** SCI0CR1 - SCI 0 Control Register 1; Several registers at the same address ***/
    union {
      struct {
        byte PT          :1;                                       /* Parity Type Bit */
        byte PE          :1;                                       /* Parity Enable Bit */
        byte ILT         :1;                                       /* Idle Line Type Bit */
        byte WAKE        :1;                                       /* Wakeup Condition Bit */
        byte M           :1;                                       /* Data Format Mode Bit */
        byte RSRC        :1;                                       /* Receiver Source Bit */
        byte SCISWAI     :1;                                       /* SCI Stop in Wait Mode Bit */
        byte LOOPS       :1;                                       /* Loop Select Bit */
      } Bits;
    } SCI0CR1STR;
    #define SCI0CR1                     _SCI0ACR2.Byte
    #define SCI0CR1_PT                  _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.PT
    #define SCI0CR1_PE                  _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.PE
    #define SCI0CR1_ILT                 _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.ILT
    #define SCI0CR1_WAKE                _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.WAKE
    #define SCI0CR1_M                   _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.M
    #define SCI0CR1_RSRC                _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.RSRC
    #define SCI0CR1_SCISWAI             _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.SCISWAI
    #define SCI0CR1_LOOPS               _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.LOOPS
    
    #define SCI0CR1_PT_MASK             1U
    #define SCI0CR1_PE_MASK             2U
    #define SCI0CR1_ILT_MASK            4U
    #define SCI0CR1_WAKE_MASK           8U
    #define SCI0CR1_M_MASK              16U
    #define SCI0CR1_RSRC_MASK           32U
    #define SCI0CR1_SCISWAI_MASK        64U
    #define SCI0CR1_LOOPS_MASK          128U
    
  } SameAddr_STR; /*Several registers at the same address */

} SCI0ACR2STR;
extern volatile SCI0ACR2STR _SCI0ACR2 @(REG_BASE + 0x000000CAUL);


/*** SCI0CR2 - SCI 0 Control Register 2; 0x000000CB ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break Bit */
    byte RWU         :1;                                       /* Receiver Wakeup Bit */
    byte RE          :1;                                       /* Receiver Enable Bit */
    byte TE          :1;                                       /* Transmitter Enable Bit */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable Bit */
    byte RIE         :1;                                       /* Receiver Full Interrupt Enable Bit */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable Bit */
    byte TIE_bit     :1;                                       /* Transmitter Interrupt Enable Bit */ /*Warning: bit name is duplicated with register name*/
  } Bits;
} SCI0CR2STR;
extern volatile SCI0CR2STR _SCI0CR2 @(REG_BASE + 0x000000CBUL);
#define SCI0CR2                         _SCI0CR2.Byte
#define SCI0CR2_SBK                     _SCI0CR2.Bits.SBK
#define SCI0CR2_RWU                     _SCI0CR2.Bits.RWU
#define SCI0CR2_RE                      _SCI0CR2.Bits.RE
#define SCI0CR2_TE                      _SCI0CR2.Bits.TE
#define SCI0CR2_ILIE                    _SCI0CR2.Bits.ILIE
#define SCI0CR2_RIE                     _SCI0CR2.Bits.RIE
#define SCI0CR2_TCIE                    _SCI0CR2.Bits.TCIE
#define SCI0CR2_TIE                     _SCI0CR2.Bits.TIE_bit

#define SCI0CR2_SBK_MASK                1U
#define SCI0CR2_RWU_MASK                2U
#define SCI0CR2_RE_MASK                 4U
#define SCI0CR2_TE_MASK                 8U
#define SCI0CR2_ILIE_MASK               16U
#define SCI0CR2_RIE_MASK                32U
#define SCI0CR2_TCIE_MASK               64U
#define SCI0CR2_TIE_MASK                128U


/*** SCI0SR1 - SCI 0 Status Register 1; 0x000000CC ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmit Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCI0SR1STR;
extern volatile SCI0SR1STR _SCI0SR1 @(REG_BASE + 0x000000CCUL);
#define SCI0SR1                         _SCI0SR1.Byte
#define SCI0SR1_PF                      _SCI0SR1.Bits.PF
#define SCI0SR1_FE                      _SCI0SR1.Bits.FE
#define SCI0SR1_NF                      _SCI0SR1.Bits.NF
#define SCI0SR1_OR                      _SCI0SR1.Bits.OR
#define SCI0SR1_IDLE                    _SCI0SR1.Bits.IDLE
#define SCI0SR1_RDRF                    _SCI0SR1.Bits.RDRF
#define SCI0SR1_TC                      _SCI0SR1.Bits.TC
#define SCI0SR1_TDRE                    _SCI0SR1.Bits.TDRE

#define SCI0SR1_PF_MASK                 1U
#define SCI0SR1_FE_MASK                 2U
#define SCI0SR1_NF_MASK                 4U
#define SCI0SR1_OR_MASK                 8U
#define SCI0SR1_IDLE_MASK               16U
#define SCI0SR1_RDRF_MASK               32U
#define SCI0SR1_TC_MASK                 64U
#define SCI0SR1_TDRE_MASK               128U


/*** SCI0SR2 - SCI 0 Status Register 2; 0x000000CD ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte TXDIR       :1;                                       /* Transmitter pin data direction in Single-Wire mode */
    byte BRK13       :1;                                       /* Break Transmit character length */
    byte RXPOL       :1;                                       /* Receive Polarity */
    byte TXPOL       :1;                                       /* Transmit Polarity */
    byte             :1; 
    byte             :1; 
    byte AMAP        :1;                                       /* Alternative Map */
  } Bits;
} SCI0SR2STR;
extern volatile SCI0SR2STR _SCI0SR2 @(REG_BASE + 0x000000CDUL);
#define SCI0SR2                         _SCI0SR2.Byte
#define SCI0SR2_RAF                     _SCI0SR2.Bits.RAF
#define SCI0SR2_TXDIR                   _SCI0SR2.Bits.TXDIR
#define SCI0SR2_BRK13                   _SCI0SR2.Bits.BRK13
#define SCI0SR2_RXPOL                   _SCI0SR2.Bits.RXPOL
#define SCI0SR2_TXPOL                   _SCI0SR2.Bits.TXPOL
#define SCI0SR2_AMAP                    _SCI0SR2.Bits.AMAP

#define SCI0SR2_RAF_MASK                1U
#define SCI0SR2_TXDIR_MASK              2U
#define SCI0SR2_BRK13_MASK              4U
#define SCI0SR2_RXPOL_MASK              8U
#define SCI0SR2_TXPOL_MASK              16U
#define SCI0SR2_AMAP_MASK               128U


/*** SCI0DRH - SCI 0 Data Register High; 0x000000CE ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte T8          :1;                                       /* Transmit Bit 8 */
    byte R8          :1;                                       /* Received Bit 8 */
  } Bits;
} SCI0DRHSTR;
extern volatile SCI0DRHSTR _SCI0DRH @(REG_BASE + 0x000000CEUL);
#define SCI0DRH                         _SCI0DRH.Byte
#define SCI0DRH_T8                      _SCI0DRH.Bits.T8
#define SCI0DRH_R8                      _SCI0DRH.Bits.R8

#define SCI0DRH_T8_MASK                 64U
#define SCI0DRH_R8_MASK                 128U


/*** SCI0DRL - SCI 0 Data Register Low; 0x000000CF ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Received bit 0 or Transmit bit 0 */
    byte R1_T1       :1;                                       /* Received bit 1 or Transmit bit 1 */
    byte R2_T2       :1;                                       /* Received bit 2 or Transmit bit 2 */
    byte R3_T3       :1;                                       /* Received bit 3 or Transmit bit 3 */
    byte R4_T4       :1;                                       /* Received bit 4 or Transmit bit 4 */
    byte R5_T5       :1;                                       /* Received bit 5 or Transmit bit 5 */
    byte R6_T6       :1;                                       /* Received bit 6 or Transmit bit 6 */
    byte R7_T7       :1;                                       /* Received bit 7 or Transmit bit 7 */
  } Bits;
} SCI0DRLSTR;
extern volatile SCI0DRLSTR _SCI0DRL @(REG_BASE + 0x000000CFUL);
#define SCI0DRL                         _SCI0DRL.Byte
#define SCI0DRL_R0_T0                   _SCI0DRL.Bits.R0_T0
#define SCI0DRL_R1_T1                   _SCI0DRL.Bits.R1_T1
#define SCI0DRL_R2_T2                   _SCI0DRL.Bits.R2_T2
#define SCI0DRL_R3_T3                   _SCI0DRL.Bits.R3_T3
#define SCI0DRL_R4_T4                   _SCI0DRL.Bits.R4_T4
#define SCI0DRL_R5_T5                   _SCI0DRL.Bits.R5_T5
#define SCI0DRL_R6_T6                   _SCI0DRL.Bits.R6_T6
#define SCI0DRL_R7_T7                   _SCI0DRL.Bits.R7_T7

#define SCI0DRL_R0_T0_MASK              1U
#define SCI0DRL_R1_T1_MASK              2U
#define SCI0DRL_R2_T2_MASK              4U
#define SCI0DRL_R3_T3_MASK              8U
#define SCI0DRL_R4_T4_MASK              16U
#define SCI0DRL_R5_T5_MASK              32U
#define SCI0DRL_R6_T6_MASK              64U
#define SCI0DRL_R7_T7_MASK              128U


/*** SCI1BD - SCI 1 Baud Rate Register; 0x000000D0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI1ASR1 - SCI 1 Alternative Status Register 1; 0x000000D0 ***/
    union {
      byte Byte;
      union { /* Several registers at the same address */
        /*** SCI1ASR1 - SCI 1 Alternative Status Register 1; Several registers at the same address ***/
        union {
          struct {
            byte BKDIF       :1;                                       /* Break Detect Interrupt Flag */
            byte BERRIF      :1;                                       /* Bit Error Interrupt Flag */
            byte BERRV       :1;                                       /* Bit Error Value */
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte RXEDGIF     :1;                                       /* Receive Input Active Edge Interrupt Flag */
          } Bits;
        } SCI1ASR1STR;
        #define SCI1ASR1                _SCI1BD.Overlap_STR.SCI1ASR1STR.Byte
        #define SCI1ASR1_BKDIF          _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1ASR1STR.Bits.BKDIF
        #define SCI1ASR1_BERRIF         _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1ASR1STR.Bits.BERRIF
        #define SCI1ASR1_BERRV          _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1ASR1STR.Bits.BERRV
        #define SCI1ASR1_RXEDGIF        _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1ASR1STR.Bits.RXEDGIF
        
        #define SCI1ASR1_BKDIF_MASK     1U
        #define SCI1ASR1_BERRIF_MASK    2U
        #define SCI1ASR1_BERRV_MASK     4U
        #define SCI1ASR1_RXEDGIF_MASK   128U
        
        /*** SCI1BDH - SCI 1 Baud Rate Register High; Several registers at the same address ***/
        union {
          struct {
            byte SBR8        :1;                                       /* SCI Baud Rate Bit 8 */
            byte SBR9        :1;                                       /* SCI Baud Rate Bit 9 */
            byte SBR10       :1;                                       /* SCI Baud Rate Bit 10 */
            byte SBR11       :1;                                       /* SCI Baud Rate Bit 11 */
            byte SBR12       :1;                                       /* SCI Baud Rate Bit 12 */
            byte SBR13       :1;                                       /* SCI Baud Rate Bit 13 */
            byte SBR14       :1;                                       /* SCI Baud Rate Bit 14 */
            byte SBR15       :1;                                       /* SCI Baud Rate Bit 15 */
          } Bits;
        } SCI1BDHSTR;
        #define SCI1BDH                 _SCI1BD.Overlap_STR.SCI1ASR1STR.Byte
        #define SCI1BDH_SBR8            _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR8
        #define SCI1BDH_SBR9            _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR9
        #define SCI1BDH_SBR10           _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR10
        #define SCI1BDH_SBR11           _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR11
        #define SCI1BDH_SBR12           _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR12
        #define SCI1BDH_SBR13           _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR13
        #define SCI1BDH_SBR14           _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR14
        #define SCI1BDH_SBR15           _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR15
        
        #define SCI1BDH_SBR8_MASK       1U
        #define SCI1BDH_SBR9_MASK       2U
        #define SCI1BDH_SBR10_MASK      4U
        #define SCI1BDH_SBR11_MASK      8U
        #define SCI1BDH_SBR12_MASK      16U
        #define SCI1BDH_SBR13_MASK      32U
        #define SCI1BDH_SBR14_MASK      64U
        #define SCI1BDH_SBR15_MASK      128U
        
      } SameAddr_STR; /*Several registers at the same address */
    
    } SCI1ASR1STR;
    

    /*** SCI1ACR1 - SCI 1 Alternative Control Register 1; 0x000000D1 ***/
    union {
      byte Byte;
      union { /* Several registers at the same address */
        /*** SCI1ACR1 - SCI 1 Alternative Control Register 1; Several registers at the same address ***/
        union {
          struct {
            byte BKDIE       :1;                                       /* Break Detect Interrupt Enable */
            byte BERRIE      :1;                                       /* Bit Error Interrupt Enable */
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte RXEDGIE     :1;                                       /* Receive Input Active Edge Interrupt Enable */
          } Bits;
        } SCI1ACR1STR;
        #define SCI1ACR1                _SCI1BD.Overlap_STR.SCI1ACR1STR.Byte
        #define SCI1ACR1_BKDIE          _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1ACR1STR.Bits.BKDIE
        #define SCI1ACR1_BERRIE         _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1ACR1STR.Bits.BERRIE
        #define SCI1ACR1_RXEDGIE        _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1ACR1STR.Bits.RXEDGIE
        
        #define SCI1ACR1_BKDIE_MASK     1U
        #define SCI1ACR1_BERRIE_MASK    2U
        #define SCI1ACR1_RXEDGIE_MASK   128U
        
        /*** SCI1BDL - SCI 1 Baud Rate Register Low; Several registers at the same address ***/
        union {
          struct {
            byte SBR0        :1;                                       /* SCI Baud Rate Bit 0 */
            byte SBR1        :1;                                       /* SCI Baud Rate Bit 1 */
            byte SBR2        :1;                                       /* SCI Baud Rate Bit 2 */
            byte SBR3        :1;                                       /* SCI Baud Rate Bit 3 */
            byte SBR4        :1;                                       /* SCI Baud Rate Bit 4 */
            byte SBR5        :1;                                       /* SCI Baud Rate Bit 5 */
            byte SBR6        :1;                                       /* SCI Baud Rate Bit 6 */
            byte SBR7        :1;                                       /* SCI Baud Rate Bit 7 */
          } Bits;
        } SCI1BDLSTR;
        #define SCI1BDL                 _SCI1BD.Overlap_STR.SCI1ACR1STR.Byte
        #define SCI1BDL_SBR0            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR0
        #define SCI1BDL_SBR1            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR1
        #define SCI1BDL_SBR2            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR2
        #define SCI1BDL_SBR3            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR3
        #define SCI1BDL_SBR4            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR4
        #define SCI1BDL_SBR5            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR5
        #define SCI1BDL_SBR6            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR6
        #define SCI1BDL_SBR7            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR7
        
        #define SCI1BDL_SBR0_MASK       1U
        #define SCI1BDL_SBR1_MASK       2U
        #define SCI1BDL_SBR2_MASK       4U
        #define SCI1BDL_SBR3_MASK       8U
        #define SCI1BDL_SBR4_MASK       16U
        #define SCI1BDL_SBR5_MASK       32U
        #define SCI1BDL_SBR6_MASK       64U
        #define SCI1BDL_SBR7_MASK       128U
        
      } SameAddr_STR; /*Several registers at the same address */
    
    } SCI1ACR1STR;
    
  } Overlap_STR;

  struct {
    word SBR0        :1;                                       /* SCI Baud Rate Bit 0 */
    word SBR1        :1;                                       /* SCI Baud Rate Bit 1 */
    word SBR2        :1;                                       /* SCI Baud Rate Bit 2 */
    word SBR3        :1;                                       /* SCI Baud Rate Bit 3 */
    word SBR4        :1;                                       /* SCI Baud Rate Bit 4 */
    word SBR5        :1;                                       /* SCI Baud Rate Bit 5 */
    word SBR6        :1;                                       /* SCI Baud Rate Bit 6 */
    word SBR7        :1;                                       /* SCI Baud Rate Bit 7 */
    word SBR8        :1;                                       /* SCI Baud Rate Bit 8 */
    word SBR9        :1;                                       /* SCI Baud Rate Bit 9 */
    word SBR10       :1;                                       /* SCI Baud Rate Bit 10 */
    word SBR11       :1;                                       /* SCI Baud Rate Bit 11 */
    word SBR12       :1;                                       /* SCI Baud Rate Bit 12 */
    word SBR13       :1;                                       /* SCI Baud Rate Bit 13 */
    word SBR14       :1;                                       /* SCI Baud Rate Bit 14 */
    word SBR15       :1;                                       /* SCI Baud Rate Bit 15 */
  } Bits;
} SCI1BDSTR;
extern volatile SCI1BDSTR _SCI1BD @(REG_BASE + 0x000000D0UL);
#define SCI1BD                          _SCI1BD.Word
#define SCI1BD_SBR0                     _SCI1BD.Bits.SBR0
#define SCI1BD_SBR1                     _SCI1BD.Bits.SBR1
#define SCI1BD_SBR2                     _SCI1BD.Bits.SBR2
#define SCI1BD_SBR3                     _SCI1BD.Bits.SBR3
#define SCI1BD_SBR4                     _SCI1BD.Bits.SBR4
#define SCI1BD_SBR5                     _SCI1BD.Bits.SBR5
#define SCI1BD_SBR6                     _SCI1BD.Bits.SBR6
#define SCI1BD_SBR7                     _SCI1BD.Bits.SBR7
#define SCI1BD_SBR8                     _SCI1BD.Bits.SBR8
#define SCI1BD_SBR9                     _SCI1BD.Bits.SBR9
#define SCI1BD_SBR10                    _SCI1BD.Bits.SBR10
#define SCI1BD_SBR11                    _SCI1BD.Bits.SBR11
#define SCI1BD_SBR12                    _SCI1BD.Bits.SBR12
#define SCI1BD_SBR13                    _SCI1BD.Bits.SBR13
#define SCI1BD_SBR14                    _SCI1BD.Bits.SBR14
#define SCI1BD_SBR15                    _SCI1BD.Bits.SBR15

#define SCI1BD_SBR0_MASK                1U
#define SCI1BD_SBR1_MASK                2U
#define SCI1BD_SBR2_MASK                4U
#define SCI1BD_SBR3_MASK                8U
#define SCI1BD_SBR4_MASK                16U
#define SCI1BD_SBR5_MASK                32U
#define SCI1BD_SBR6_MASK                64U
#define SCI1BD_SBR7_MASK                128U
#define SCI1BD_SBR8_MASK                256U
#define SCI1BD_SBR9_MASK                512U
#define SCI1BD_SBR10_MASK               1024U
#define SCI1BD_SBR11_MASK               2048U
#define SCI1BD_SBR12_MASK               4096U
#define SCI1BD_SBR13_MASK               8192U
#define SCI1BD_SBR14_MASK               16384U
#define SCI1BD_SBR15_MASK               32768U


/*** SCI1ACR2 - SCI 1 Alternative Control Register 2; 0x000000D2 ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** SCI1ACR2 - SCI 1 Alternative Control Register 2; Several registers at the same address ***/
    union {
      struct {
        byte BKDFE       :1;                                       /* Break Detect Feature Enable */
        byte BERRM0      :1;                                       /* Bit Error Mode 0 */
        byte BERRM1      :1;                                       /* Bit Error Mode 1 */
        byte             :1; 
        byte             :1; 
        byte TNP0        :1;                                       /* Transmitter Narrow Pulse Bit 0 */
        byte TNP1        :1;                                       /* Transmitter Narrow Pulse Bit 1 */
        byte IREN        :1;                                       /* Infrared Enable Bit */
      } Bits;
      struct {
        byte     :1;
        byte grpBERRM :2;
        byte     :1;
        byte     :1;
        byte grpTNP :2;
        byte     :1;
      } MergedBits;
    } SCI1ACR2STR;
    #define SCI1ACR2                    _SCI1ACR2.Byte
    #define SCI1ACR2_BKDFE              _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.Bits.BKDFE
    #define SCI1ACR2_BERRM0             _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.Bits.BERRM0
    #define SCI1ACR2_BERRM1             _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.Bits.BERRM1
    #define SCI1ACR2_TNP0               _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.Bits.TNP0
    #define SCI1ACR2_TNP1               _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.Bits.TNP1
    #define SCI1ACR2_IREN               _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.Bits.IREN
    #define SCI1ACR2_BERRM              _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.MergedBits.grpBERRM
    #define SCI1ACR2_TNP                _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.MergedBits.grpTNP
    
    #define SCI1ACR2_BKDFE_MASK         1U
    #define SCI1ACR2_BERRM0_MASK        2U
    #define SCI1ACR2_BERRM1_MASK        4U
    #define SCI1ACR2_TNP0_MASK          32U
    #define SCI1ACR2_TNP1_MASK          64U
    #define SCI1ACR2_IREN_MASK          128U
    #define SCI1ACR2_BERRM_MASK         6U
    #define SCI1ACR2_BERRM_BITNUM       1U
    #define SCI1ACR2_TNP_MASK           96U
    #define SCI1ACR2_TNP_BITNUM         5U
    
    /*** SCI1CR1 - SCI 1 Control Register 1; Several registers at the same address ***/
    union {
      struct {
        byte PT          :1;                                       /* Parity Type Bit */
        byte PE          :1;                                       /* Parity Enable Bit */
        byte ILT         :1;                                       /* Idle Line Type Bit */
        byte WAKE        :1;                                       /* Wakeup Condition Bit */
        byte M           :1;                                       /* Data Format Mode Bit */
        byte RSRC        :1;                                       /* Receiver Source Bit */
        byte SCISWAI     :1;                                       /* SCI Stop in Wait Mode Bit */
        byte LOOPS       :1;                                       /* Loop Select Bit */
      } Bits;
    } SCI1CR1STR;
    #define SCI1CR1                     _SCI1ACR2.Byte
    #define SCI1CR1_PT                  _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.PT
    #define SCI1CR1_PE                  _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.PE
    #define SCI1CR1_ILT                 _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.ILT
    #define SCI1CR1_WAKE                _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.WAKE
    #define SCI1CR1_M                   _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.M
    #define SCI1CR1_RSRC                _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.RSRC
    #define SCI1CR1_SCISWAI             _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.SCISWAI
    #define SCI1CR1_LOOPS               _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.LOOPS
    
    #define SCI1CR1_PT_MASK             1U
    #define SCI1CR1_PE_MASK             2U
    #define SCI1CR1_ILT_MASK            4U
    #define SCI1CR1_WAKE_MASK           8U
    #define SCI1CR1_M_MASK              16U
    #define SCI1CR1_RSRC_MASK           32U
    #define SCI1CR1_SCISWAI_MASK        64U
    #define SCI1CR1_LOOPS_MASK          128U
    
  } SameAddr_STR; /*Several registers at the same address */

} SCI1ACR2STR;
extern volatile SCI1ACR2STR _SCI1ACR2 @(REG_BASE + 0x000000D2UL);


/*** SCI1CR2 - SCI 1 Control Register 2; 0x000000D3 ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break Bit */
    byte RWU         :1;                                       /* Receiver Wakeup Bit */
    byte RE          :1;                                       /* Receiver Enable Bit */
    byte TE          :1;                                       /* Transmitter Enable Bit */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable Bit */
    byte RIE         :1;                                       /* Receiver Full Interrupt Enable Bit */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable Bit */
    byte TIE_bit     :1;                                       /* Transmitter Interrupt Enable Bit */ /*Warning: bit name is duplicated with register name*/
  } Bits;
} SCI1CR2STR;
extern volatile SCI1CR2STR _SCI1CR2 @(REG_BASE + 0x000000D3UL);
#define SCI1CR2                         _SCI1CR2.Byte
#define SCI1CR2_SBK                     _SCI1CR2.Bits.SBK
#define SCI1CR2_RWU                     _SCI1CR2.Bits.RWU
#define SCI1CR2_RE                      _SCI1CR2.Bits.RE
#define SCI1CR2_TE                      _SCI1CR2.Bits.TE
#define SCI1CR2_ILIE                    _SCI1CR2.Bits.ILIE
#define SCI1CR2_RIE                     _SCI1CR2.Bits.RIE
#define SCI1CR2_TCIE                    _SCI1CR2.Bits.TCIE
#define SCI1CR2_TIE                     _SCI1CR2.Bits.TIE_bit

#define SCI1CR2_SBK_MASK                1U
#define SCI1CR2_RWU_MASK                2U
#define SCI1CR2_RE_MASK                 4U
#define SCI1CR2_TE_MASK                 8U
#define SCI1CR2_ILIE_MASK               16U
#define SCI1CR2_RIE_MASK                32U
#define SCI1CR2_TCIE_MASK               64U
#define SCI1CR2_TIE_MASK                128U


/*** SCI1SR1 - SCI 1 Status Register 1; 0x000000D4 ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmit Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCI1SR1STR;
extern volatile SCI1SR1STR _SCI1SR1 @(REG_BASE + 0x000000D4UL);
#define SCI1SR1                         _SCI1SR1.Byte
#define SCI1SR1_PF                      _SCI1SR1.Bits.PF
#define SCI1SR1_FE                      _SCI1SR1.Bits.FE
#define SCI1SR1_NF                      _SCI1SR1.Bits.NF
#define SCI1SR1_OR                      _SCI1SR1.Bits.OR
#define SCI1SR1_IDLE                    _SCI1SR1.Bits.IDLE
#define SCI1SR1_RDRF                    _SCI1SR1.Bits.RDRF
#define SCI1SR1_TC                      _SCI1SR1.Bits.TC
#define SCI1SR1_TDRE                    _SCI1SR1.Bits.TDRE

#define SCI1SR1_PF_MASK                 1U
#define SCI1SR1_FE_MASK                 2U
#define SCI1SR1_NF_MASK                 4U
#define SCI1SR1_OR_MASK                 8U
#define SCI1SR1_IDLE_MASK               16U
#define SCI1SR1_RDRF_MASK               32U
#define SCI1SR1_TC_MASK                 64U
#define SCI1SR1_TDRE_MASK               128U


/*** SCI1SR2 - SCI 1 Status Register 2; 0x000000D5 ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte TXDIR       :1;                                       /* Transmitter pin data direction in Single-Wire mode */
    byte BRK13       :1;                                       /* Break Transmit character length */
    byte RXPOL       :1;                                       /* Receive Polarity */
    byte TXPOL       :1;                                       /* Transmit Polarity */
    byte             :1; 
    byte             :1; 
    byte AMAP        :1;                                       /* Alternative Map */
  } Bits;
} SCI1SR2STR;
extern volatile SCI1SR2STR _SCI1SR2 @(REG_BASE + 0x000000D5UL);
#define SCI1SR2                         _SCI1SR2.Byte
#define SCI1SR2_RAF                     _SCI1SR2.Bits.RAF
#define SCI1SR2_TXDIR                   _SCI1SR2.Bits.TXDIR
#define SCI1SR2_BRK13                   _SCI1SR2.Bits.BRK13
#define SCI1SR2_RXPOL                   _SCI1SR2.Bits.RXPOL
#define SCI1SR2_TXPOL                   _SCI1SR2.Bits.TXPOL
#define SCI1SR2_AMAP                    _SCI1SR2.Bits.AMAP

#define SCI1SR2_RAF_MASK                1U
#define SCI1SR2_TXDIR_MASK              2U
#define SCI1SR2_BRK13_MASK              4U
#define SCI1SR2_RXPOL_MASK              8U
#define SCI1SR2_TXPOL_MASK              16U
#define SCI1SR2_AMAP_MASK               128U


/*** SCI1DRH - SCI 1 Data Register High; 0x000000D6 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte T8          :1;                                       /* Transmit Bit 8 */
    byte R8          :1;                                       /* Received Bit 8 */
  } Bits;
} SCI1DRHSTR;
extern volatile SCI1DRHSTR _SCI1DRH @(REG_BASE + 0x000000D6UL);
#define SCI1DRH                         _SCI1DRH.Byte
#define SCI1DRH_T8                      _SCI1DRH.Bits.T8
#define SCI1DRH_R8                      _SCI1DRH.Bits.R8

#define SCI1DRH_T8_MASK                 64U
#define SCI1DRH_R8_MASK                 128U


/*** SCI1DRL - SCI 1 Data Register Low; 0x000000D7 ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Received bit 0 or Transmit bit 0 */
    byte R1_T1       :1;                                       /* Received bit 1 or Transmit bit 1 */
    byte R2_T2       :1;                                       /* Received bit 2 or Transmit bit 2 */
    byte R3_T3       :1;                                       /* Received bit 3 or Transmit bit 3 */
    byte R4_T4       :1;                                       /* Received bit 4 or Transmit bit 4 */
    byte R5_T5       :1;                                       /* Received bit 5 or Transmit bit 5 */
    byte R6_T6       :1;                                       /* Received bit 6 or Transmit bit 6 */
    byte R7_T7       :1;                                       /* Received bit 7 or Transmit bit 7 */
  } Bits;
} SCI1DRLSTR;
extern volatile SCI1DRLSTR _SCI1DRL @(REG_BASE + 0x000000D7UL);
#define SCI1DRL                         _SCI1DRL.Byte
#define SCI1DRL_R0_T0                   _SCI1DRL.Bits.R0_T0
#define SCI1DRL_R1_T1                   _SCI1DRL.Bits.R1_T1
#define SCI1DRL_R2_T2                   _SCI1DRL.Bits.R2_T2
#define SCI1DRL_R3_T3                   _SCI1DRL.Bits.R3_T3
#define SCI1DRL_R4_T4                   _SCI1DRL.Bits.R4_T4
#define SCI1DRL_R5_T5                   _SCI1DRL.Bits.R5_T5
#define SCI1DRL_R6_T6                   _SCI1DRL.Bits.R6_T6
#define SCI1DRL_R7_T7                   _SCI1DRL.Bits.R7_T7

#define SCI1DRL_R0_T0_MASK              1U
#define SCI1DRL_R1_T1_MASK              2U
#define SCI1DRL_R2_T2_MASK              4U
#define SCI1DRL_R3_T3_MASK              8U
#define SCI1DRL_R4_T4_MASK              16U
#define SCI1DRL_R5_T5_MASK              32U
#define SCI1DRL_R6_T6_MASK              64U
#define SCI1DRL_R7_T7_MASK              128U


/*** SPICR1 - SPI  Control Register 1; 0x000000D8 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* SPI LSB-First Enable */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* SPI Clock Phase Bit */
    byte CPOL        :1;                                       /* SPI Clock Polarity Bit */
    byte MSTR        :1;                                       /* SPI Master/Slave Mode Select Bit */
    byte SPTIE       :1;                                       /* SPI Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI System Enable Bit */
    byte SPIE        :1;                                       /* SPI Interrupt Enable Bit */
  } Bits;
} SPICR1STR;
extern volatile SPICR1STR _SPICR1 @(REG_BASE + 0x000000D8UL);
#define SPICR1                          _SPICR1.Byte
#define SPICR1_LSBFE                    _SPICR1.Bits.LSBFE
#define SPICR1_SSOE                     _SPICR1.Bits.SSOE
#define SPICR1_CPHA                     _SPICR1.Bits.CPHA
#define SPICR1_CPOL                     _SPICR1.Bits.CPOL
#define SPICR1_MSTR                     _SPICR1.Bits.MSTR
#define SPICR1_SPTIE                    _SPICR1.Bits.SPTIE
#define SPICR1_SPE                      _SPICR1.Bits.SPE
#define SPICR1_SPIE                     _SPICR1.Bits.SPIE

#define SPICR1_LSBFE_MASK               1U
#define SPICR1_SSOE_MASK                2U
#define SPICR1_CPHA_MASK                4U
#define SPICR1_CPOL_MASK                8U
#define SPICR1_MSTR_MASK                16U
#define SPICR1_SPTIE_MASK               32U
#define SPICR1_SPE_MASK                 64U
#define SPICR1_SPIE_MASK                128U


/*** SPICR2 - SPI  Control Register 2; 0x000000D9 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* Serial Pin Control Bit 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode Bit */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Output enable in the Bidirectional mode of operation */
    byte MODFEN      :1;                                       /* Mode Fault Enable Bit */
    byte             :1; 
    byte XFRW        :1;                                       /* Transfer Width */
    byte             :1; 
  } Bits;
} SPICR2STR;
extern volatile SPICR2STR _SPICR2 @(REG_BASE + 0x000000D9UL);
#define SPICR2                          _SPICR2.Byte
#define SPICR2_SPC0                     _SPICR2.Bits.SPC0
#define SPICR2_SPISWAI                  _SPICR2.Bits.SPISWAI
#define SPICR2_BIDIROE                  _SPICR2.Bits.BIDIROE
#define SPICR2_MODFEN                   _SPICR2.Bits.MODFEN
#define SPICR2_XFRW                     _SPICR2.Bits.XFRW

#define SPICR2_SPC0_MASK                1U
#define SPICR2_SPISWAI_MASK             2U
#define SPICR2_BIDIROE_MASK             8U
#define SPICR2_MODFEN_MASK              16U
#define SPICR2_XFRW_MASK                64U


/*** SPIBR - SPI  Baud Rate Register; 0x000000DA ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI Baud Rate Selection Bit 0 */
    byte SPR1        :1;                                       /* SPI Baud Rate Selection Bit 1 */
    byte SPR2        :1;                                       /* SPI Baud Rate Selection Bit 2 */
    byte             :1; 
    byte SPPR0       :1;                                       /* SPI Baud Rate Preselection Bits 0 */
    byte SPPR1       :1;                                       /* SPI Baud Rate Preselection Bits 1 */
    byte SPPR2       :1;                                       /* SPI Baud Rate Preselection Bits 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :3;
    byte         :1;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPIBRSTR;
extern volatile SPIBRSTR _SPIBR @(REG_BASE + 0x000000DAUL);
#define SPIBR                           _SPIBR.Byte
#define SPIBR_SPR0                      _SPIBR.Bits.SPR0
#define SPIBR_SPR1                      _SPIBR.Bits.SPR1
#define SPIBR_SPR2                      _SPIBR.Bits.SPR2
#define SPIBR_SPPR0                     _SPIBR.Bits.SPPR0
#define SPIBR_SPPR1                     _SPIBR.Bits.SPPR1
#define SPIBR_SPPR2                     _SPIBR.Bits.SPPR2
#define SPIBR_SPR                       _SPIBR.MergedBits.grpSPR
#define SPIBR_SPPR                      _SPIBR.MergedBits.grpSPPR

#define SPIBR_SPR0_MASK                 1U
#define SPIBR_SPR1_MASK                 2U
#define SPIBR_SPR2_MASK                 4U
#define SPIBR_SPPR0_MASK                16U
#define SPIBR_SPPR1_MASK                32U
#define SPIBR_SPPR2_MASK                64U
#define SPIBR_SPR_MASK                  7U
#define SPIBR_SPR_BITNUM                0U
#define SPIBR_SPPR_MASK                 112U
#define SPIBR_SPPR_BITNUM               4U


/*** SPISR - SPI  Status Register; 0x000000DB ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       /* Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Empty Interrupt Flag */
    byte             :1; 
    byte SPIF        :1;                                       /* SPIF Receive Interrupt Flag */
  } Bits;
} SPISRSTR;
extern volatile SPISRSTR _SPISR @(REG_BASE + 0x000000DBUL);
#define SPISR                           _SPISR.Byte
#define SPISR_MODF                      _SPISR.Bits.MODF
#define SPISR_SPTEF                     _SPISR.Bits.SPTEF
#define SPISR_SPIF                      _SPISR.Bits.SPIF

#define SPISR_MODF_MASK                 16U
#define SPISR_SPTEF_MASK                32U
#define SPISR_SPIF_MASK                 128U


/*** SPIDR - SPI  Data Register; 0x000000DC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SPIDRH - SPI  Data Register High; 0x000000DC ***/
    union {
      byte Byte;
      struct {
        byte R8_T8       :1;                                       /* SPI  Data Bit 8 */
        byte R9_T9       :1;                                       /* SPI  Data Bit 9 */
        byte R10_T10     :1;                                       /* SPI  Data Bit 10 */
        byte R11_T11     :1;                                       /* SPI  Data Bit 11 */
        byte R12_T12     :1;                                       /* SPI  Data Bit 12 */
        byte R13_T13     :1;                                       /* SPI  Data Bit 13 */
        byte R14_T14     :1;                                       /* SPI  Data Bit 14 */
        byte R15_T15     :1;                                       /* SPI  Data Bit 15 */
      } Bits;
    } SPIDRHSTR;
    #define SPIDRH                      _SPIDR.Overlap_STR.SPIDRHSTR.Byte
    #define SPIDRH_R8_T8                _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R8_T8
    #define SPIDRH_R9_T9                _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R9_T9
    #define SPIDRH_R10_T10              _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R10_T10
    #define SPIDRH_R11_T11              _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R11_T11
    #define SPIDRH_R12_T12              _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R12_T12
    #define SPIDRH_R13_T13              _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R13_T13
    #define SPIDRH_R14_T14              _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R14_T14
    #define SPIDRH_R15_T15              _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R15_T15
    
    #define SPIDRH_R8_T8_MASK           1U
    #define SPIDRH_R9_T9_MASK           2U
    #define SPIDRH_R10_T10_MASK         4U
    #define SPIDRH_R11_T11_MASK         8U
    #define SPIDRH_R12_T12_MASK         16U
    #define SPIDRH_R13_T13_MASK         32U
    #define SPIDRH_R14_T14_MASK         64U
    #define SPIDRH_R15_T15_MASK         128U
    

    /*** SPIDRL - SPI  Data Register Low; 0x000000DD ***/
    union {
      byte Byte;
      struct {
        byte R0_T0       :1;                                       /* SPI  Data Bit 0 */
        byte R1_T1       :1;                                       /* SPI  Data Bit 1 */
        byte R2_T2       :1;                                       /* SPI  Data Bit 2 */
        byte R3_T3       :1;                                       /* SPI  Data Bit 3 */
        byte R4_T4       :1;                                       /* SPI  Data Bit 4 */
        byte R5_T5       :1;                                       /* SPI  Data Bit 5 */
        byte R6_T6       :1;                                       /* SPI  Data Bit 6 */
        byte R7_T7       :1;                                       /* SPI  Data Bit 7 */
      } Bits;
    } SPIDRLSTR;
    #define SPIDRL                      _SPIDR.Overlap_STR.SPIDRLSTR.Byte
    #define SPIDRL_R0_T0                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R0_T0
    #define SPIDRL_R1_T1                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R1_T1
    #define SPIDRL_R2_T2                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R2_T2
    #define SPIDRL_R3_T3                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R3_T3
    #define SPIDRL_R4_T4                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R4_T4
    #define SPIDRL_R5_T5                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R5_T5
    #define SPIDRL_R6_T6                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R6_T6
    #define SPIDRL_R7_T7                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R7_T7
    
    #define SPIDRL_R0_T0_MASK           1U
    #define SPIDRL_R1_T1_MASK           2U
    #define SPIDRL_R2_T2_MASK           4U
    #define SPIDRL_R3_T3_MASK           8U
    #define SPIDRL_R4_T4_MASK           16U
    #define SPIDRL_R5_T5_MASK           32U
    #define SPIDRL_R6_T6_MASK           64U
    #define SPIDRL_R7_T7_MASK           128U
    
  } Overlap_STR;

  struct {
    word R0_T0       :1;                                       /* SPI  Data Bit 0 */
    word R1_T1       :1;                                       /* SPI  Data Bit 1 */
    word R2_T2       :1;                                       /* SPI  Data Bit 2 */
    word R3_T3       :1;                                       /* SPI  Data Bit 3 */
    word R4_T4       :1;                                       /* SPI  Data Bit 4 */
    word R5_T5       :1;                                       /* SPI  Data Bit 5 */
    word R6_T6       :1;                                       /* SPI  Data Bit 6 */
    word R7_T7       :1;                                       /* SPI  Data Bit 7 */
    word R8_T8       :1;                                       /* SPI  Data Bit 8 */
    word R9_T9       :1;                                       /* SPI  Data Bit 9 */
    word R10_T10     :1;                                       /* SPI  Data Bit 10 */
    word R11_T11     :1;                                       /* SPI  Data Bit 11 */
    word R12_T12     :1;                                       /* SPI  Data Bit 12 */
    word R13_T13     :1;                                       /* SPI  Data Bit 13 */
    word R14_T14     :1;                                       /* SPI  Data Bit 14 */
    word R15_T15     :1;                                       /* SPI  Data Bit 15 */
  } Bits;
} SPIDRSTR;
extern volatile SPIDRSTR _SPIDR @(REG_BASE + 0x000000DCUL);
#define SPIDR                           _SPIDR.Word
#define SPIDR_R0_T0                     _SPIDR.Bits.R0_T0
#define SPIDR_R1_T1                     _SPIDR.Bits.R1_T1
#define SPIDR_R2_T2                     _SPIDR.Bits.R2_T2
#define SPIDR_R3_T3                     _SPIDR.Bits.R3_T3
#define SPIDR_R4_T4                     _SPIDR.Bits.R4_T4
#define SPIDR_R5_T5                     _SPIDR.Bits.R5_T5
#define SPIDR_R6_T6                     _SPIDR.Bits.R6_T6
#define SPIDR_R7_T7                     _SPIDR.Bits.R7_T7
#define SPIDR_R8_T8                     _SPIDR.Bits.R8_T8
#define SPIDR_R9_T9                     _SPIDR.Bits.R9_T9
#define SPIDR_R10_T10                   _SPIDR.Bits.R10_T10
#define SPIDR_R11_T11                   _SPIDR.Bits.R11_T11
#define SPIDR_R12_T12                   _SPIDR.Bits.R12_T12
#define SPIDR_R13_T13                   _SPIDR.Bits.R13_T13
#define SPIDR_R14_T14                   _SPIDR.Bits.R14_T14
#define SPIDR_R15_T15                   _SPIDR.Bits.R15_T15

#define SPIDR_R0_T0_MASK                1U
#define SPIDR_R1_T1_MASK                2U
#define SPIDR_R2_T2_MASK                4U
#define SPIDR_R3_T3_MASK                8U
#define SPIDR_R4_T4_MASK                16U
#define SPIDR_R5_T5_MASK                32U
#define SPIDR_R6_T6_MASK                64U
#define SPIDR_R7_T7_MASK                128U
#define SPIDR_R8_T8_MASK                256U
#define SPIDR_R9_T9_MASK                512U
#define SPIDR_R10_T10_MASK              1024U
#define SPIDR_R11_T11_MASK              2048U
#define SPIDR_R12_T12_MASK              4096U
#define SPIDR_R13_T13_MASK              8192U
#define SPIDR_R14_T14_MASK              16384U
#define SPIDR_R15_T15_MASK              32768U


/*** FCLKDIV - Flash Clock Divider Register; 0x00000100 ***/
typedef union {
  byte Byte;
  struct {
    byte FDIV0       :1;                                       /* Clock Divider Bit 0 */
    byte FDIV1       :1;                                       /* Clock Divider Bit 1 */
    byte FDIV2       :1;                                       /* Clock Divider Bit 2 */
    byte FDIV3       :1;                                       /* Clock Divider Bit 3 */
    byte FDIV4       :1;                                       /* Clock Divider Bit 4 */
    byte FDIV5       :1;                                       /* Clock Divider Bit 5 */
    byte FDIVLCK     :1;                                       /* Clock divider locked */
    byte FDIVLD      :1;                                       /* Clock Divider Loaded */
  } Bits;
  struct {
    byte grpFDIV :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} FCLKDIVSTR;
extern volatile FCLKDIVSTR _FCLKDIV @(REG_BASE + 0x00000100UL);
#define FCLKDIV                         _FCLKDIV.Byte
#define FCLKDIV_FDIV0                   _FCLKDIV.Bits.FDIV0
#define FCLKDIV_FDIV1                   _FCLKDIV.Bits.FDIV1
#define FCLKDIV_FDIV2                   _FCLKDIV.Bits.FDIV2
#define FCLKDIV_FDIV3                   _FCLKDIV.Bits.FDIV3
#define FCLKDIV_FDIV4                   _FCLKDIV.Bits.FDIV4
#define FCLKDIV_FDIV5                   _FCLKDIV.Bits.FDIV5
#define FCLKDIV_FDIVLCK                 _FCLKDIV.Bits.FDIVLCK
#define FCLKDIV_FDIVLD                  _FCLKDIV.Bits.FDIVLD
#define FCLKDIV_FDIV                    _FCLKDIV.MergedBits.grpFDIV

#define FCLKDIV_FDIV0_MASK              1U
#define FCLKDIV_FDIV1_MASK              2U
#define FCLKDIV_FDIV2_MASK              4U
#define FCLKDIV_FDIV3_MASK              8U
#define FCLKDIV_FDIV4_MASK              16U
#define FCLKDIV_FDIV5_MASK              32U
#define FCLKDIV_FDIVLCK_MASK            64U
#define FCLKDIV_FDIVLD_MASK             128U
#define FCLKDIV_FDIV_MASK               63U
#define FCLKDIV_FDIV_BITNUM             0U


/*** FSEC - Flash Security Register; 0x00000101 ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Flash Security Bit 0 */
    byte SEC1        :1;                                       /* Flash Security Bit 1 */
    byte RNV2        :1;                                       /* Reserved Nonvolatile Bit 2 */
    byte RNV3        :1;                                       /* Reserved Nonvolatile Bit 3 */
    byte RNV4        :1;                                       /* Reserved Nonvolatile Bit 4 */
    byte RNV5        :1;                                       /* Reserved Nonvolatile Bit 5 */
    byte KEYEN0      :1;                                       /* Backdoor Key Security Enable Bit 0 */
    byte KEYEN1      :1;                                       /* Backdoor Key Security Enable Bit 1 */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte grpRNV_2 :4;
    byte grpKEYEN :2;
  } MergedBits;
} FSECSTR;
extern volatile FSECSTR _FSEC @(REG_BASE + 0x00000101UL);
#define FSEC                            _FSEC.Byte
#define FSEC_SEC0                       _FSEC.Bits.SEC0
#define FSEC_SEC1                       _FSEC.Bits.SEC1
#define FSEC_RNV2                       _FSEC.Bits.RNV2
#define FSEC_RNV3                       _FSEC.Bits.RNV3
#define FSEC_RNV4                       _FSEC.Bits.RNV4
#define FSEC_RNV5                       _FSEC.Bits.RNV5
#define FSEC_KEYEN0                     _FSEC.Bits.KEYEN0
#define FSEC_KEYEN1                     _FSEC.Bits.KEYEN1
#define FSEC_SEC                        _FSEC.MergedBits.grpSEC
#define FSEC_RNV_2                      _FSEC.MergedBits.grpRNV_2
#define FSEC_KEYEN                      _FSEC.MergedBits.grpKEYEN
#define FSEC_RNV                        FSEC_RNV_2

#define FSEC_SEC0_MASK                  1U
#define FSEC_SEC1_MASK                  2U
#define FSEC_RNV2_MASK                  4U
#define FSEC_RNV3_MASK                  8U
#define FSEC_RNV4_MASK                  16U
#define FSEC_RNV5_MASK                  32U
#define FSEC_KEYEN0_MASK                64U
#define FSEC_KEYEN1_MASK                128U
#define FSEC_SEC_MASK                   3U
#define FSEC_SEC_BITNUM                 0U
#define FSEC_RNV_2_MASK                 60U
#define FSEC_RNV_2_BITNUM               2U
#define FSEC_KEYEN_MASK                 192U
#define FSEC_KEYEN_BITNUM               6U


/*** FCCOBIX - Flash CCOB Index Register; 0x00000102 ***/
typedef union {
  byte Byte;
  struct {
    byte CCOBIX0     :1;                                       /* Common Command Register Index Bit 0 */
    byte CCOBIX1     :1;                                       /* Common Command Register Index Bit 1 */
    byte CCOBIX2     :1;                                       /* Common Command Register Index Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCCOBIX :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FCCOBIXSTR;
extern volatile FCCOBIXSTR _FCCOBIX @(REG_BASE + 0x00000102UL);
#define FCCOBIX                         _FCCOBIX.Byte
#define FCCOBIX_CCOBIX0                 _FCCOBIX.Bits.CCOBIX0
#define FCCOBIX_CCOBIX1                 _FCCOBIX.Bits.CCOBIX1
#define FCCOBIX_CCOBIX2                 _FCCOBIX.Bits.CCOBIX2
#define FCCOBIX_CCOBIX                  _FCCOBIX.MergedBits.grpCCOBIX

#define FCCOBIX_CCOBIX0_MASK            1U
#define FCCOBIX_CCOBIX1_MASK            2U
#define FCCOBIX_CCOBIX2_MASK            4U
#define FCCOBIX_CCOBIX_MASK             7U
#define FCCOBIX_CCOBIX_BITNUM           0U


/*** FCNFG - Flash Configuration Register; 0x00000104 ***/
typedef union {
  byte Byte;
  struct {
    byte FSFD        :1;                                       /* Force Single Bit Fault Detect */
    byte FDFD        :1;                                       /* Force Double Bit Fault Detect */
    byte             :1; 
    byte             :1; 
    byte IGNSF       :1;                                       /* Ignore Single Bit Fault */
    byte             :1; 
    byte             :1; 
    byte CCIE        :1;                                       /* Command Complete Interrupt Enable */
  } Bits;
} FCNFGSTR;
extern volatile FCNFGSTR _FCNFG @(REG_BASE + 0x00000104UL);
#define FCNFG                           _FCNFG.Byte
#define FCNFG_FSFD                      _FCNFG.Bits.FSFD
#define FCNFG_FDFD                      _FCNFG.Bits.FDFD
#define FCNFG_IGNSF                     _FCNFG.Bits.IGNSF
#define FCNFG_CCIE                      _FCNFG.Bits.CCIE

#define FCNFG_FSFD_MASK                 1U
#define FCNFG_FDFD_MASK                 2U
#define FCNFG_IGNSF_MASK                16U
#define FCNFG_CCIE_MASK                 128U


/*** FERCNFG - Flash Error Configuration Register; 0x00000105 ***/
typedef union {
  byte Byte;
  struct {
    byte SFDIE       :1;                                       /* Single Bit Fault Detect Interrupt Enable */
    byte DFDIE       :1;                                       /* Double Bit Fault Detect Interrupt Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FERCNFGSTR;
extern volatile FERCNFGSTR _FERCNFG @(REG_BASE + 0x00000105UL);
#define FERCNFG                         _FERCNFG.Byte
#define FERCNFG_SFDIE                   _FERCNFG.Bits.SFDIE
#define FERCNFG_DFDIE                   _FERCNFG.Bits.DFDIE

#define FERCNFG_SFDIE_MASK              1U
#define FERCNFG_DFDIE_MASK              2U


/*** FSTAT - Flash Status Register; 0x00000106 ***/
typedef union {
  byte Byte;
  struct {
    byte MGSTAT0     :1;                                       /* Memory Controller Command Completion Status Flag 0 */
    byte MGSTAT1     :1;                                       /* Memory Controller Command Completion Status Flag 1 */
    byte             :1; 
    byte MGBUSY      :1;                                       /* Memory Controller Busy Flag */
    byte FPVIOL      :1;                                       /* Flash Protection Violation Flag */
    byte ACCERR      :1;                                       /* Flash Access Error Flag */
    byte             :1; 
    byte CCIF        :1;                                       /* Command Complete Interrupt Flag */
  } Bits;
  struct {
    byte grpMGSTAT :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FSTATSTR;
extern volatile FSTATSTR _FSTAT @(REG_BASE + 0x00000106UL);
#define FSTAT                           _FSTAT.Byte
#define FSTAT_MGSTAT0                   _FSTAT.Bits.MGSTAT0
#define FSTAT_MGSTAT1                   _FSTAT.Bits.MGSTAT1
#define FSTAT_MGBUSY                    _FSTAT.Bits.MGBUSY
#define FSTAT_FPVIOL                    _FSTAT.Bits.FPVIOL
#define FSTAT_ACCERR                    _FSTAT.Bits.ACCERR
#define FSTAT_CCIF                      _FSTAT.Bits.CCIF
#define FSTAT_MGSTAT                    _FSTAT.MergedBits.grpMGSTAT

#define FSTAT_MGSTAT0_MASK              1U
#define FSTAT_MGSTAT1_MASK              2U
#define FSTAT_MGBUSY_MASK               8U
#define FSTAT_FPVIOL_MASK               16U
#define FSTAT_ACCERR_MASK               32U
#define FSTAT_CCIF_MASK                 128U
#define FSTAT_MGSTAT_MASK               3U
#define FSTAT_MGSTAT_BITNUM             0U


/*** FERSTAT - Flash Error Status Register; 0x00000107 ***/
typedef union {
  byte Byte;
  struct {
    byte SFDIF       :1;                                       /* Single Bit Fault Detect Interrupt Flag */
    byte DFDIF       :1;                                       /* Double Bit Fault Detect Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FERSTATSTR;
extern volatile FERSTATSTR _FERSTAT @(REG_BASE + 0x00000107UL);
#define FERSTAT                         _FERSTAT.Byte
#define FERSTAT_SFDIF                   _FERSTAT.Bits.SFDIF
#define FERSTAT_DFDIF                   _FERSTAT.Bits.DFDIF

#define FERSTAT_SFDIF_MASK              1U
#define FERSTAT_DFDIF_MASK              2U


/*** FPROT - P-Flash Protection Register; 0x00000108 ***/
typedef union {
  byte Byte;
  struct {
    byte FPLS0       :1;                                       /* Flash Protection Lower Address Size Bit 0 */
    byte FPLS1       :1;                                       /* Flash Protection Lower Address Size Bit 1 */
    byte FPLDIS      :1;                                       /* Flash Protection Lower Address Range Disable */
    byte FPHS0       :1;                                       /* Flash Protection Higher Address Size Bit 0 */
    byte FPHS1       :1;                                       /* Flash Protection Higher Address Size Bit 1 */
    byte FPHDIS      :1;                                       /* Flash Protection Higher Address Range Disable */
    byte RNV6        :1;                                       /* Reserved Nonvolatile Bit */
    byte FPOPEN      :1;                                       /* Flash Protection Operation Enable */
  } Bits;
  struct {
    byte grpFPLS :2;
    byte         :1;
    byte grpFPHS :2;
    byte         :1;
    byte grpRNV_6 :1;
    byte         :1;
  } MergedBits;
} FPROTSTR;
extern volatile FPROTSTR _FPROT @(REG_BASE + 0x00000108UL);
#define FPROT                           _FPROT.Byte
#define FPROT_FPLS0                     _FPROT.Bits.FPLS0
#define FPROT_FPLS1                     _FPROT.Bits.FPLS1
#define FPROT_FPLDIS                    _FPROT.Bits.FPLDIS
#define FPROT_FPHS0                     _FPROT.Bits.FPHS0
#define FPROT_FPHS1                     _FPROT.Bits.FPHS1
#define FPROT_FPHDIS                    _FPROT.Bits.FPHDIS
#define FPROT_RNV6                      _FPROT.Bits.RNV6
#define FPROT_FPOPEN                    _FPROT.Bits.FPOPEN
#define FPROT_FPLS                      _FPROT.MergedBits.grpFPLS
#define FPROT_FPHS                      _FPROT.MergedBits.grpFPHS

#define FPROT_FPLS0_MASK                1U
#define FPROT_FPLS1_MASK                2U
#define FPROT_FPLDIS_MASK               4U
#define FPROT_FPHS0_MASK                8U
#define FPROT_FPHS1_MASK                16U
#define FPROT_FPHDIS_MASK               32U
#define FPROT_RNV6_MASK                 64U
#define FPROT_FPOPEN_MASK               128U
#define FPROT_FPLS_MASK                 3U
#define FPROT_FPLS_BITNUM               0U
#define FPROT_FPHS_MASK                 24U
#define FPROT_FPHS_BITNUM               3U


/*** DFPROT - D-Flash Protection Register; 0x00000109 ***/
typedef union {
  byte Byte;
  struct {
    byte DPS0        :1;                                       /* D-Flash Protection Size Bit 0 */
    byte DPS1        :1;                                       /* D-Flash Protection Size Bit 1 */
    byte DPS2        :1;                                       /* D-Flash Protection Size Bit 2 */
    byte DPS3        :1;                                       /* D-Flash Protection Size Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte DPOPEN      :1;                                       /* D-Flash Protection Control */
  } Bits;
  struct {
    byte grpDPS  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DFPROTSTR;
extern volatile DFPROTSTR _DFPROT @(REG_BASE + 0x00000109UL);
#define DFPROT                          _DFPROT.Byte
#define DFPROT_DPS0                     _DFPROT.Bits.DPS0
#define DFPROT_DPS1                     _DFPROT.Bits.DPS1
#define DFPROT_DPS2                     _DFPROT.Bits.DPS2
#define DFPROT_DPS3                     _DFPROT.Bits.DPS3
#define DFPROT_DPOPEN                   _DFPROT.Bits.DPOPEN
#define DFPROT_DPS                      _DFPROT.MergedBits.grpDPS

#define DFPROT_DPS0_MASK                1U
#define DFPROT_DPS1_MASK                2U
#define DFPROT_DPS2_MASK                4U
#define DFPROT_DPS3_MASK                8U
#define DFPROT_DPOPEN_MASK              128U
#define DFPROT_DPS_MASK                 15U
#define DFPROT_DPS_BITNUM               0U


/*** FCCOB - Flash Common Command Object Register; 0x0000010A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FCCOBHI - Flash Common Command Object Register High; 0x0000010A ***/
    union {
      byte Byte;
      struct {
        byte CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
        byte CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
        byte CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
        byte CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
        byte CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
        byte CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
        byte CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
        byte CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
      } Bits;
    } FCCOBHISTR;
    #define FCCOBHI                     _FCCOB.Overlap_STR.FCCOBHISTR.Byte
    #define FCCOBHI_CCOB8               _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB8
    #define FCCOBHI_CCOB9               _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB9
    #define FCCOBHI_CCOB10              _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB10
    #define FCCOBHI_CCOB11              _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB11
    #define FCCOBHI_CCOB12              _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB12
    #define FCCOBHI_CCOB13              _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB13
    #define FCCOBHI_CCOB14              _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB14
    #define FCCOBHI_CCOB15              _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB15
    
    #define FCCOBHI_CCOB8_MASK          1U
    #define FCCOBHI_CCOB9_MASK          2U
    #define FCCOBHI_CCOB10_MASK         4U
    #define FCCOBHI_CCOB11_MASK         8U
    #define FCCOBHI_CCOB12_MASK         16U
    #define FCCOBHI_CCOB13_MASK         32U
    #define FCCOBHI_CCOB14_MASK         64U
    #define FCCOBHI_CCOB15_MASK         128U
    

    /*** FCCOBLO - Flash Common Command Object Register Low; 0x0000010B ***/
    union {
      byte Byte;
      struct {
        byte CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
        byte CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
        byte CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
        byte CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
        byte CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
        byte CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
        byte CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
        byte CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
      } Bits;
    } FCCOBLOSTR;
    #define FCCOBLO                     _FCCOB.Overlap_STR.FCCOBLOSTR.Byte
    #define FCCOBLO_CCOB0               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB0
    #define FCCOBLO_CCOB1               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB1
    #define FCCOBLO_CCOB2               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB2
    #define FCCOBLO_CCOB3               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB3
    #define FCCOBLO_CCOB4               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB4
    #define FCCOBLO_CCOB5               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB5
    #define FCCOBLO_CCOB6               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB6
    #define FCCOBLO_CCOB7               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB7
    
    #define FCCOBLO_CCOB0_MASK          1U
    #define FCCOBLO_CCOB1_MASK          2U
    #define FCCOBLO_CCOB2_MASK          4U
    #define FCCOBLO_CCOB3_MASK          8U
    #define FCCOBLO_CCOB4_MASK          16U
    #define FCCOBLO_CCOB5_MASK          32U
    #define FCCOBLO_CCOB6_MASK          64U
    #define FCCOBLO_CCOB7_MASK          128U
    
  } Overlap_STR;

  struct {
    word CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
    word CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
    word CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
    word CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
    word CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
    word CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
    word CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
    word CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
    word CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
    word CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
    word CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
    word CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
    word CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
    word CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
    word CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
    word CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
  } Bits;
} FCCOBSTR;
extern volatile FCCOBSTR _FCCOB @(REG_BASE + 0x0000010AUL);
#define FCCOB                           _FCCOB.Word
#define FCCOB_CCOB0                     _FCCOB.Bits.CCOB0
#define FCCOB_CCOB1                     _FCCOB.Bits.CCOB1
#define FCCOB_CCOB2                     _FCCOB.Bits.CCOB2
#define FCCOB_CCOB3                     _FCCOB.Bits.CCOB3
#define FCCOB_CCOB4                     _FCCOB.Bits.CCOB4
#define FCCOB_CCOB5                     _FCCOB.Bits.CCOB5
#define FCCOB_CCOB6                     _FCCOB.Bits.CCOB6
#define FCCOB_CCOB7                     _FCCOB.Bits.CCOB7
#define FCCOB_CCOB8                     _FCCOB.Bits.CCOB8
#define FCCOB_CCOB9                     _FCCOB.Bits.CCOB9
#define FCCOB_CCOB10                    _FCCOB.Bits.CCOB10
#define FCCOB_CCOB11                    _FCCOB.Bits.CCOB11
#define FCCOB_CCOB12                    _FCCOB.Bits.CCOB12
#define FCCOB_CCOB13                    _FCCOB.Bits.CCOB13
#define FCCOB_CCOB14                    _FCCOB.Bits.CCOB14
#define FCCOB_CCOB15                    _FCCOB.Bits.CCOB15

#define FCCOB_CCOB0_MASK                1U
#define FCCOB_CCOB1_MASK                2U
#define FCCOB_CCOB2_MASK                4U
#define FCCOB_CCOB3_MASK                8U
#define FCCOB_CCOB4_MASK                16U
#define FCCOB_CCOB5_MASK                32U
#define FCCOB_CCOB6_MASK                64U
#define FCCOB_CCOB7_MASK                128U
#define FCCOB_CCOB8_MASK                256U
#define FCCOB_CCOB9_MASK                512U
#define FCCOB_CCOB10_MASK               1024U
#define FCCOB_CCOB11_MASK               2048U
#define FCCOB_CCOB12_MASK               4096U
#define FCCOB_CCOB13_MASK               8192U
#define FCCOB_CCOB14_MASK               16384U
#define FCCOB_CCOB15_MASK               32768U


/*** FOPT - Flash Option Register; 0x00000110 ***/
typedef union {
  byte Byte;
  struct {
    byte NV0         :1;                                       /* Nonvolatile Bit 0 */
    byte NV1         :1;                                       /* Nonvolatile Bit 1 */
    byte NV2         :1;                                       /* Nonvolatile Bit 2 */
    byte NV3         :1;                                       /* Nonvolatile Bit 3 */
    byte NV4         :1;                                       /* Nonvolatile Bit 4 */
    byte NV5         :1;                                       /* Nonvolatile Bit 5 */
    byte NV6         :1;                                       /* Nonvolatile Bit 6 */
    byte NV7         :1;                                       /* Nonvolatile Bit 7 */
  } Bits;
} FOPTSTR;
extern volatile FOPTSTR _FOPT @(REG_BASE + 0x00000110UL);
#define FOPT                            _FOPT.Byte
#define FOPT_NV0                        _FOPT.Bits.NV0
#define FOPT_NV1                        _FOPT.Bits.NV1
#define FOPT_NV2                        _FOPT.Bits.NV2
#define FOPT_NV3                        _FOPT.Bits.NV3
#define FOPT_NV4                        _FOPT.Bits.NV4
#define FOPT_NV5                        _FOPT.Bits.NV5
#define FOPT_NV6                        _FOPT.Bits.NV6
#define FOPT_NV7                        _FOPT.Bits.NV7

#define FOPT_NV0_MASK                   1U
#define FOPT_NV1_MASK                   2U
#define FOPT_NV2_MASK                   4U
#define FOPT_NV3_MASK                   8U
#define FOPT_NV4_MASK                   16U
#define FOPT_NV5_MASK                   32U
#define FOPT_NV6_MASK                   64U
#define FOPT_NV7_MASK                   128U


/*** IVBR - Interrupt Vector Base Register; 0x00000120 ***/
typedef union {
  byte Byte;
  struct {
    byte IVB_ADDR0   :1;                                       /* Interrupt Vector Base Address Bits, bit 0 */
    byte IVB_ADDR1   :1;                                       /* Interrupt Vector Base Address Bits, bit 1 */
    byte IVB_ADDR2   :1;                                       /* Interrupt Vector Base Address Bits, bit 2 */
    byte IVB_ADDR3   :1;                                       /* Interrupt Vector Base Address Bits, bit 3 */
    byte IVB_ADDR4   :1;                                       /* Interrupt Vector Base Address Bits, bit 4 */
    byte IVB_ADDR5   :1;                                       /* Interrupt Vector Base Address Bits, bit 5 */
    byte IVB_ADDR6   :1;                                       /* Interrupt Vector Base Address Bits, bit 6 */
    byte IVB_ADDR7   :1;                                       /* Interrupt Vector Base Address Bits, bit 7 */
  } Bits;
} IVBRSTR;
extern volatile IVBRSTR _IVBR @(REG_BASE + 0x00000120UL);
#define IVBR                            _IVBR.Byte
#define IVBR_IVB_ADDR0                  _IVBR.Bits.IVB_ADDR0
#define IVBR_IVB_ADDR1                  _IVBR.Bits.IVB_ADDR1
#define IVBR_IVB_ADDR2                  _IVBR.Bits.IVB_ADDR2
#define IVBR_IVB_ADDR3                  _IVBR.Bits.IVB_ADDR3
#define IVBR_IVB_ADDR4                  _IVBR.Bits.IVB_ADDR4
#define IVBR_IVB_ADDR5                  _IVBR.Bits.IVB_ADDR5
#define IVBR_IVB_ADDR6                  _IVBR.Bits.IVB_ADDR6
#define IVBR_IVB_ADDR7                  _IVBR.Bits.IVB_ADDR7

#define IVBR_IVB_ADDR0_MASK             1U
#define IVBR_IVB_ADDR1_MASK             2U
#define IVBR_IVB_ADDR2_MASK             4U
#define IVBR_IVB_ADDR3_MASK             8U
#define IVBR_IVB_ADDR4_MASK             16U
#define IVBR_IVB_ADDR5_MASK             32U
#define IVBR_IVB_ADDR6_MASK             64U
#define IVBR_IVB_ADDR7_MASK             128U


/*** HSDR - Port HS Data Register; 0x00000140 ***/
typedef union {
  byte Byte;
  struct {
    byte HSDR0       :1;                                       /* Port HS Data Bit 0 */
    byte HSDR1       :1;                                       /* Port HS Data Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpHSDR :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} HSDRSTR;
extern volatile HSDRSTR _HSDR @(REG_BASE + 0x00000140UL);
#define HSDR                            _HSDR.Byte
#define HSDR_HSDR0                      _HSDR.Bits.HSDR0
#define HSDR_HSDR1                      _HSDR.Bits.HSDR1
#define HSDR_HSDR                       _HSDR.MergedBits.grpHSDR

#define HSDR_HSDR0_MASK                 1U
#define HSDR_HSDR1_MASK                 2U
#define HSDR_HSDR_MASK                  3U
#define HSDR_HSDR_BITNUM                0U


/*** HSCR - HSDRV Configuration Register; 0x00000141 ***/
typedef union {
  byte Byte;
  struct {
    byte HSE0        :1;                                       /* HSDRV Enable Bit 0 */
    byte HSE1        :1;                                       /* HSDRV Enable Bit 1 */
    byte HSOLE0      :1;                                       /* HSDRV High-Load resistance Open-Load Detection Enable Bit 0 */
    byte HSOLE1      :1;                                       /* HSDRV High-Load resistance Open-Load Detection Enable Bit 1 */
    byte HSOCME0     :1;                                       /* HSDRV Over-Current Mask Enable Bit0 */
    byte HSOCME1     :1;                                       /* HSDRV Over-Current Mask Enable Bit1 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpHSE  :2;
    byte grpHSOLE :2;
    byte grpHSOCME :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} HSCRSTR;
extern volatile HSCRSTR _HSCR @(REG_BASE + 0x00000141UL);
#define HSCR                            _HSCR.Byte
#define HSCR_HSE0                       _HSCR.Bits.HSE0
#define HSCR_HSE1                       _HSCR.Bits.HSE1
#define HSCR_HSOLE0                     _HSCR.Bits.HSOLE0
#define HSCR_HSOLE1                     _HSCR.Bits.HSOLE1
#define HSCR_HSOCME0                    _HSCR.Bits.HSOCME0
#define HSCR_HSOCME1                    _HSCR.Bits.HSOCME1
#define HSCR_HSE                        _HSCR.MergedBits.grpHSE
#define HSCR_HSOLE                      _HSCR.MergedBits.grpHSOLE
#define HSCR_HSOCME                     _HSCR.MergedBits.grpHSOCME

#define HSCR_HSE0_MASK                  1U
#define HSCR_HSE1_MASK                  2U
#define HSCR_HSOLE0_MASK                4U
#define HSCR_HSOLE1_MASK                8U
#define HSCR_HSOCME0_MASK               16U
#define HSCR_HSOCME1_MASK               32U
#define HSCR_HSE_MASK                   3U
#define HSCR_HSE_BITNUM                 0U
#define HSCR_HSOLE_MASK                 12U
#define HSCR_HSOLE_BITNUM               2U
#define HSCR_HSOCME_MASK                48U
#define HSCR_HSOCME_BITNUM              4U


/*** HSSR - HSDRV Open Load Status Register; 0x00000145 ***/
typedef union {
  byte Byte;
  struct {
    byte HSOL0       :1;                                       /* HSDRV Open-Load Status Bit 0 */
    byte HSOL1       :1;                                       /* HSDRV Open-Load Status Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpHSOL :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} HSSRSTR;
extern volatile HSSRSTR _HSSR @(REG_BASE + 0x00000145UL);
#define HSSR                            _HSSR.Byte
#define HSSR_HSOL0                      _HSSR.Bits.HSOL0
#define HSSR_HSOL1                      _HSSR.Bits.HSOL1
#define HSSR_HSOL                       _HSSR.MergedBits.grpHSOL

#define HSSR_HSOL0_MASK                 1U
#define HSSR_HSOL1_MASK                 2U
#define HSSR_HSOL_MASK                  3U
#define HSSR_HSOL_BITNUM                0U


/*** HSIE - HSDRV Over Current Interrupt Enable Register; 0x00000146 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte HSOCIE      :1;                                       /* HSDRV Over-Current Interrupt Enable */
  } Bits;
} HSIESTR;
extern volatile HSIESTR _HSIE @(REG_BASE + 0x00000146UL);
#define HSIE                            _HSIE.Byte
#define HSIE_HSOCIE                     _HSIE.Bits.HSOCIE

#define HSIE_HSOCIE_MASK                128U


/*** HSIF - HSDRV Over Current Interrupt Flag Register; 0x00000147 ***/
typedef union {
  byte Byte;
  struct {
    byte HSOCIF0     :1;                                       /* HSDRV Over-Current Interrupt Flag 0 */
    byte HSOCIF1     :1;                                       /* HSDRV Over-Current Interrupt Flag 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpHSOCIF :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} HSIFSTR;
extern volatile HSIFSTR _HSIF @(REG_BASE + 0x00000147UL);
#define HSIF                            _HSIF.Byte
#define HSIF_HSOCIF0                    _HSIF.Bits.HSOCIF0
#define HSIF_HSOCIF1                    _HSIF.Bits.HSOCIF1
#define HSIF_HSOCIF                     _HSIF.MergedBits.grpHSOCIF

#define HSIF_HSOCIF0_MASK               1U
#define HSIF_HSOCIF1_MASK               2U
#define HSIF_HSOCIF_MASK                3U
#define HSIF_HSOCIF_BITNUM              0U


/*** LSDR - Port LS Data Register; 0x00000150 ***/
typedef union {
  byte Byte;
  struct {
    byte LSDR0       :1;                                       /* Port LS Data Bit 0 */
    byte LSDR1       :1;                                       /* Port LS Data Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpLSDR :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} LSDRSTR;
extern volatile LSDRSTR _LSDR @(REG_BASE + 0x00000150UL);
#define LSDR                            _LSDR.Byte
#define LSDR_LSDR0                      _LSDR.Bits.LSDR0
#define LSDR_LSDR1                      _LSDR.Bits.LSDR1
#define LSDR_LSDR                       _LSDR.MergedBits.grpLSDR

#define LSDR_LSDR0_MASK                 1U
#define LSDR_LSDR1_MASK                 2U
#define LSDR_LSDR_MASK                  3U
#define LSDR_LSDR_BITNUM                0U


/*** LSCR - LSDRV Configuration Register; 0x00000151 ***/
typedef union {
  byte Byte;
  struct {
    byte LSE0        :1;                                       /* LSDRV Enable Bit 0 */
    byte LSE1        :1;                                       /* LSDRV Enable Bit 1 */
    byte LSOLE0      :1;                                       /* LSDRV High-Load resistance Open-Load Detection Enable Bit 0 */
    byte LSOLE1      :1;                                       /* LSDRV High-Load resistance Open-Load Detection Enable Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpLSE  :2;
    byte grpLSOLE :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} LSCRSTR;
extern volatile LSCRSTR _LSCR @(REG_BASE + 0x00000151UL);
#define LSCR                            _LSCR.Byte
#define LSCR_LSE0                       _LSCR.Bits.LSE0
#define LSCR_LSE1                       _LSCR.Bits.LSE1
#define LSCR_LSOLE0                     _LSCR.Bits.LSOLE0
#define LSCR_LSOLE1                     _LSCR.Bits.LSOLE1
#define LSCR_LSE                        _LSCR.MergedBits.grpLSE
#define LSCR_LSOLE                      _LSCR.MergedBits.grpLSOLE

#define LSCR_LSE0_MASK                  1U
#define LSCR_LSE1_MASK                  2U
#define LSCR_LSOLE0_MASK                4U
#define LSCR_LSOLE1_MASK                8U
#define LSCR_LSE_MASK                   3U
#define LSCR_LSE_BITNUM                 0U
#define LSCR_LSOLE_MASK                 12U
#define LSCR_LSOLE_BITNUM               2U


/*** LSSR - LSDRV Open Load Status Register; 0x00000155 ***/
typedef union {
  byte Byte;
  struct {
    byte LSOL0       :1;                                       /* LSDRV Open-Load Status Bit 0 */
    byte LSOL1       :1;                                       /* LSDRV Open-Load Status Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpLSOL :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} LSSRSTR;
extern volatile LSSRSTR _LSSR @(REG_BASE + 0x00000155UL);
#define LSSR                            _LSSR.Byte
#define LSSR_LSOL0                      _LSSR.Bits.LSOL0
#define LSSR_LSOL1                      _LSSR.Bits.LSOL1
#define LSSR_LSOL                       _LSSR.MergedBits.grpLSOL

#define LSSR_LSOL0_MASK                 1U
#define LSSR_LSOL1_MASK                 2U
#define LSSR_LSOL_MASK                  3U
#define LSSR_LSOL_BITNUM                0U


/*** LSIE - LSDRV Over Current Interrupt Enable Register; 0x00000156 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LSOCIE      :1;                                       /* LSDRV Over-Current Interrupt Enable */
  } Bits;
} LSIESTR;
extern volatile LSIESTR _LSIE @(REG_BASE + 0x00000156UL);
#define LSIE                            _LSIE.Byte
#define LSIE_LSOCIE                     _LSIE.Bits.LSOCIE

#define LSIE_LSOCIE_MASK                128U


/*** LSIF - LSDRV Over Current Interrupt Flag Register; 0x00000157 ***/
typedef union {
  byte Byte;
  struct {
    byte LSOCIF0     :1;                                       /* LSDRV Over-Current Interrupt Flag 0 */
    byte LSOCIF1     :1;                                       /* LSDRV Over-Current Interrupt Flag 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpLSOCIF :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} LSIFSTR;
extern volatile LSIFSTR _LSIF @(REG_BASE + 0x00000157UL);
#define LSIF                            _LSIF.Byte
#define LSIF_LSOCIF0                    _LSIF.Bits.LSOCIF0
#define LSIF_LSOCIF1                    _LSIF.Bits.LSOCIF1
#define LSIF_LSOCIF                     _LSIF.MergedBits.grpLSOCIF

#define LSIF_LSOCIF0_MASK               1U
#define LSIF_LSOCIF1_MASK               2U
#define LSIF_LSOCIF_MASK                3U
#define LSIF_LSOCIF_BITNUM              0U


/*** LPDR - Port LP Data Register; 0x00000160 ***/
typedef union {
  byte Byte;
  struct {
    byte LPDR0       :1;                                       /* LIN Rx data */
    byte LPDR1       :1;                                       /* LIN Tx data */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpLPDR :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} LPDRSTR;
extern volatile LPDRSTR _LPDR @(REG_BASE + 0x00000160UL);
#define LPDR                            _LPDR.Byte
#define LPDR_LPDR0                      _LPDR.Bits.LPDR0
#define LPDR_LPDR1                      _LPDR.Bits.LPDR1
#define LPDR_LPDR                       _LPDR.MergedBits.grpLPDR

#define LPDR_LPDR0_MASK                 1U
#define LPDR_LPDR1_MASK                 2U
#define LPDR_LPDR_MASK                  3U
#define LPDR_LPDR_BITNUM                0U


/*** LPCR - LIN Control Register; 0x00000161 ***/
typedef union {
  byte Byte;
  struct {
    byte LPPUE       :1;                                       /* LIN pull-up enable */
    byte LPWUE       :1;                                       /* LIN wake-up enable */
    byte RXONLY      :1;                                       /* Receive only mode */
    byte LPE         :1;                                       /* LIN enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} LPCRSTR;
extern volatile LPCRSTR _LPCR @(REG_BASE + 0x00000161UL);
#define LPCR                            _LPCR.Byte
#define LPCR_LPPUE                      _LPCR.Bits.LPPUE
#define LPCR_LPWUE                      _LPCR.Bits.LPWUE
#define LPCR_RXONLY                     _LPCR.Bits.RXONLY
#define LPCR_LPE                        _LPCR.Bits.LPE

#define LPCR_LPPUE_MASK                 1U
#define LPCR_LPWUE_MASK                 2U
#define LPCR_RXONLY_MASK                4U
#define LPCR_LPE_MASK                   8U


/*** LPSLRM - LIN Slew Rate Register; 0x00000163 ***/
typedef union {
  byte Byte;
  struct {
    byte LPSLR       :2;                                       /* Slew rate select */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LPDTDIS     :1;                                       /* TxD-dominant timeout disable */
  } Bits;
} LPSLRMSTR;
extern volatile LPSLRMSTR _LPSLRM @(REG_BASE + 0x00000163UL);
#define LPSLRM                          _LPSLRM.Byte
#define LPSLRM_LPSLR                    _LPSLRM.Bits.LPSLR
#define LPSLRM_LPDTDIS                  _LPSLRM.Bits.LPDTDIS

#define LPSLRM_LPSLR_MASK               3U
#define LPSLRM_LPSLR_BITNUM             0U
#define LPSLRM_LPDTDIS_MASK             128U


/*** LPSR - LIN Status Register; 0x00000165 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LPDT        :1;                                       /* LIN Transmitter TxD-dominant timeout Status */
  } Bits;
} LPSRSTR;
extern volatile LPSRSTR _LPSR @(REG_BASE + 0x00000165UL);
#define LPSR                            _LPSR.Byte
#define LPSR_LPDT                       _LPSR.Bits.LPDT

#define LPSR_LPDT_MASK                  128U


/*** LPIE - LIN Interrupt Enable Register; 0x00000166 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LPOCIE      :1;                                       /* LIN over-current interrupt enable */
    byte LPDTIE      :1;                                       /* LIN TxD-dominant timeout Interrupt Enable */
  } Bits;
} LPIESTR;
extern volatile LPIESTR _LPIE @(REG_BASE + 0x00000166UL);
#define LPIE                            _LPIE.Byte
#define LPIE_LPOCIE                     _LPIE.Bits.LPOCIE
#define LPIE_LPDTIE                     _LPIE.Bits.LPDTIE

#define LPIE_LPOCIE_MASK                64U
#define LPIE_LPDTIE_MASK                128U


/*** LPIF - LIN Interrupt Flags Register; 0x00000167 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LPOCIF      :1;                                       /* LIN transmitter over-current interrupt flag */
    byte LPDTIF      :1;                                       /* LIN Transmitter TxD-dominant timeout Interrupt Flag */
  } Bits;
} LPIFSTR;
extern volatile LPIFSTR _LPIF @(REG_BASE + 0x00000167UL);
#define LPIF                            _LPIF.Byte
#define LPIF_LPOCIF                     _LPIF.Bits.LPOCIF
#define LPIF_LPDTIF                     _LPIF.Bits.LPDTIF

#define LPIF_LPOCIF_MASK                64U
#define LPIF_LPDTIF_MASK                128U


/*** BATE - BATS Module Enable Register; 0x00000170 ***/
typedef union {
  byte Byte;
  struct {
    byte BSESE       :1;                                       /* BATS VSENSE Level Sense Enable */
    byte BSEAE       :1;                                       /* BATS VSENSE ADC Connection Enable */
    byte BSUSE       :1;                                       /* BATS VSUP Level Sense Enable */
    byte BSUAE       :1;                                       /* BATS VSUP ADC Connection Enable */
    byte BVLS        :2;                                       /* BATS Voltage Low Select */
    byte BVHS        :1;                                       /* BATS Voltage High Select */
    byte             :1; 
  } Bits;
} BATESTR;
extern volatile BATESTR _BATE @(REG_BASE + 0x00000170UL);
#define BATE                            _BATE.Byte
#define BATE_BSESE                      _BATE.Bits.BSESE
#define BATE_BSEAE                      _BATE.Bits.BSEAE
#define BATE_BSUSE                      _BATE.Bits.BSUSE
#define BATE_BSUAE                      _BATE.Bits.BSUAE
#define BATE_BVLS                       _BATE.Bits.BVLS
#define BATE_BVHS                       _BATE.Bits.BVHS

#define BATE_BSESE_MASK                 1U
#define BATE_BSEAE_MASK                 2U
#define BATE_BSUSE_MASK                 4U
#define BATE_BSUAE_MASK                 8U
#define BATE_BVLS_MASK                  48U
#define BATE_BVLS_BITNUM                4U
#define BATE_BVHS_MASK                  64U


/*** BATSR - BATS Module Status Register; 0x00000171 ***/
typedef union {
  byte Byte;
  struct {
    byte BVLC        :1;                                       /* BATS Voltage Sense Low Condition Bit */
    byte BVHC        :1;                                       /* BATS Voltage Sense High Condition Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} BATSRSTR;
extern volatile BATSRSTR _BATSR @(REG_BASE + 0x00000171UL);
#define BATSR                           _BATSR.Byte
#define BATSR_BVLC                      _BATSR.Bits.BVLC
#define BATSR_BVHC                      _BATSR.Bits.BVHC

#define BATSR_BVLC_MASK                 1U
#define BATSR_BVHC_MASK                 2U


/*** BATIE - BATS Interrupt Enable Register; 0x00000172 ***/
typedef union {
  byte Byte;
  struct {
    byte BVLIE       :1;                                       /* BATS Interrupt Enable Low */
    byte BVHIE       :1;                                       /* BATS Interrupt Enable High */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} BATIESTR;
extern volatile BATIESTR _BATIE @(REG_BASE + 0x00000172UL);
#define BATIE                           _BATIE.Byte
#define BATIE_BVLIE                     _BATIE.Bits.BVLIE
#define BATIE_BVHIE                     _BATIE.Bits.BVHIE

#define BATIE_BVLIE_MASK                1U
#define BATIE_BVHIE_MASK                2U


/*** BATIF - BATS Interrupt Flag Register; 0x00000173 ***/
typedef union {
  byte Byte;
  struct {
    byte BVLIF       :1;                                       /* BATS Interrupt Flag Low Detect */
    byte BVHIF       :1;                                       /* BATS Interrupt Flag High Detect */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} BATIFSTR;
extern volatile BATIFSTR _BATIF @(REG_BASE + 0x00000173UL);
#define BATIF                           _BATIF.Byte
#define BATIF_BVLIF                     _BATIF.Bits.BVLIF
#define BATIF_BVHIF                     _BATIF.Bits.BVHIF

#define BATIF_BVLIF_MASK                1U
#define BATIF_BVHIF_MASK                2U


/*** PTT - Port T Data Register; 0x00000240 ***/
typedef union {
  byte Byte;
  struct {
    byte PTT0        :1;                                       /* Port T general purpose input/output data bit 0 */
    byte PTT1        :1;                                       /* Port T general purpose input/output data bit 1 */
    byte PTT2        :1;                                       /* Port T general purpose input/output data bit 2 */
    byte PTT3        :1;                                       /* Port T general purpose input/output data bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTT  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTTSTR;
extern volatile PTTSTR _PTT @(REG_BASE + 0x00000240UL);
#define PTT                             _PTT.Byte
#define PTT_PTT0                        _PTT.Bits.PTT0
#define PTT_PTT1                        _PTT.Bits.PTT1
#define PTT_PTT2                        _PTT.Bits.PTT2
#define PTT_PTT3                        _PTT.Bits.PTT3
#define PTT_PTT                         _PTT.MergedBits.grpPTT

#define PTT_PTT0_MASK                   1U
#define PTT_PTT1_MASK                   2U
#define PTT_PTT2_MASK                   4U
#define PTT_PTT3_MASK                   8U
#define PTT_PTT_MASK                    15U
#define PTT_PTT_BITNUM                  0U


/*** PTIT - Port T Input Register; 0x00000241 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIT0       :1;                                       /* Port T input data bit 0 */
    byte PTIT1       :1;                                       /* Port T input data bit 1 */
    byte PTIT2       :1;                                       /* Port T input data bit 2 */
    byte PTIT3       :1;                                       /* Port T input data bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTIT :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTITSTR;
extern volatile PTITSTR _PTIT @(REG_BASE + 0x00000241UL);
#define PTIT                            _PTIT.Byte
#define PTIT_PTIT0                      _PTIT.Bits.PTIT0
#define PTIT_PTIT1                      _PTIT.Bits.PTIT1
#define PTIT_PTIT2                      _PTIT.Bits.PTIT2
#define PTIT_PTIT3                      _PTIT.Bits.PTIT3
#define PTIT_PTIT                       _PTIT.MergedBits.grpPTIT

#define PTIT_PTIT0_MASK                 1U
#define PTIT_PTIT1_MASK                 2U
#define PTIT_PTIT2_MASK                 4U
#define PTIT_PTIT3_MASK                 8U
#define PTIT_PTIT_MASK                  15U
#define PTIT_PTIT_BITNUM                0U


/*** DDRT - Port T Data Direction Register; 0x00000242 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRT0       :1;                                       /* Port T data direction bit 0 */
    byte DDRT1       :1;                                       /* Port T data direction bit 1 */
    byte DDRT2       :1;                                       /* Port T data direction bit 2 */
    byte DDRT3       :1;                                       /* Port T data direction bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDDRT :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DDRTSTR;
extern volatile DDRTSTR _DDRT @(REG_BASE + 0x00000242UL);
#define DDRT                            _DDRT.Byte
#define DDRT_DDRT0                      _DDRT.Bits.DDRT0
#define DDRT_DDRT1                      _DDRT.Bits.DDRT1
#define DDRT_DDRT2                      _DDRT.Bits.DDRT2
#define DDRT_DDRT3                      _DDRT.Bits.DDRT3
#define DDRT_DDRT                       _DDRT.MergedBits.grpDDRT

#define DDRT_DDRT0_MASK                 1U
#define DDRT_DDRT1_MASK                 2U
#define DDRT_DDRT2_MASK                 4U
#define DDRT_DDRT3_MASK                 8U
#define DDRT_DDRT_MASK                  15U
#define DDRT_DDRT_BITNUM                0U


/*** PERT - Port T Pull Device Enable Register; 0x00000244 ***/
typedef union {
  byte Byte;
  struct {
    byte PERT0       :1;                                       /* Port T pull device enable bit 0 */
    byte PERT1       :1;                                       /* Port T pull device enable bit 1 */
    byte PERT2       :1;                                       /* Port T pull device enable bit 2 */
    byte PERT3       :1;                                       /* Port T pull device enable bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPERT :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PERTSTR;
extern volatile PERTSTR _PERT @(REG_BASE + 0x00000244UL);
#define PERT                            _PERT.Byte
#define PERT_PERT0                      _PERT.Bits.PERT0
#define PERT_PERT1                      _PERT.Bits.PERT1
#define PERT_PERT2                      _PERT.Bits.PERT2
#define PERT_PERT3                      _PERT.Bits.PERT3
#define PERT_PERT                       _PERT.MergedBits.grpPERT

#define PERT_PERT0_MASK                 1U
#define PERT_PERT1_MASK                 2U
#define PERT_PERT2_MASK                 4U
#define PERT_PERT3_MASK                 8U
#define PERT_PERT_MASK                  15U
#define PERT_PERT_BITNUM                0U


/*** PPST - Port T Polarity Select Register; 0x00000245 ***/
typedef union {
  byte Byte;
  struct {
    byte PPST0       :1;                                       /* Port T pull device select bit 0 */
    byte PPST1       :1;                                       /* Port T pull device select bit 1 */
    byte PPST2       :1;                                       /* Port T pull device select bit 2 */
    byte PPST3       :1;                                       /* Port T pull device select bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPPST :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPSTSTR;
extern volatile PPSTSTR _PPST @(REG_BASE + 0x00000245UL);
#define PPST                            _PPST.Byte
#define PPST_PPST0                      _PPST.Bits.PPST0
#define PPST_PPST1                      _PPST.Bits.PPST1
#define PPST_PPST2                      _PPST.Bits.PPST2
#define PPST_PPST3                      _PPST.Bits.PPST3
#define PPST_PPST                       _PPST.MergedBits.grpPPST

#define PPST_PPST0_MASK                 1U
#define PPST_PPST1_MASK                 2U
#define PPST_PPST2_MASK                 4U
#define PPST_PPST3_MASK                 8U
#define PPST_PPST_MASK                  15U
#define PPST_PPST_BITNUM                0U


/*** MODRR - Port T Routing Register; 0x00000246 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** MODRR0 - Port T Routing Register Low; 0x00000246 ***/
    union {
      byte Byte;
      struct {
        byte MODRR00     :1;                                       /* Port T  routing */
        byte MODRR01     :1;                                       /* Port T  routing */
        byte MODRR02     :1;                                       /* Port T  routing */
        byte MODRR03     :1;                                       /* Port T  routing */
        byte MODRR04     :1;                                       /* Port T  routing */
        byte MODRR05     :1;                                       /* Port T  routing */
        byte MODRR06     :1;                                       /* Port T  routing */
        byte MODRR07     :1;                                       /* Port T  routing */
      } Bits;
    } MODRR0STR;
    #define MODRR0                      _MODRR.Overlap_STR.MODRR0STR.Byte
    #define MODRR0_MODRR00              _MODRR.Overlap_STR.MODRR0STR.Bits.MODRR00
    #define MODRR0_MODRR01              _MODRR.Overlap_STR.MODRR0STR.Bits.MODRR01
    #define MODRR0_MODRR02              _MODRR.Overlap_STR.MODRR0STR.Bits.MODRR02
    #define MODRR0_MODRR03              _MODRR.Overlap_STR.MODRR0STR.Bits.MODRR03
    #define MODRR0_MODRR04              _MODRR.Overlap_STR.MODRR0STR.Bits.MODRR04
    #define MODRR0_MODRR05              _MODRR.Overlap_STR.MODRR0STR.Bits.MODRR05
    #define MODRR0_MODRR06              _MODRR.Overlap_STR.MODRR0STR.Bits.MODRR06
    #define MODRR0_MODRR07              _MODRR.Overlap_STR.MODRR0STR.Bits.MODRR07
    /* MODRR_ARR: Access 2 MODRRx registers in an array */
    #define MODRR_ARR                   ((volatile byte *) &MODRR0)
    
    #define MODRR0_MODRR00_MASK         1U
    #define MODRR0_MODRR01_MASK         2U
    #define MODRR0_MODRR02_MASK         4U
    #define MODRR0_MODRR03_MASK         8U
    #define MODRR0_MODRR04_MASK         16U
    #define MODRR0_MODRR05_MASK         32U
    #define MODRR0_MODRR06_MASK         64U
    #define MODRR0_MODRR07_MASK         128U
    

    /*** MODRR1 - Port T Routing Register High; 0x00000247 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte MODRR14     :1;                                       /* Port T  routing */
        byte MODRR15     :1;                                       /* Port T  routing */
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte grpMODRR_14 :2;
        byte     :1;
        byte     :1;
      } MergedBits;
    } MODRR1STR;
    #define MODRR1                      _MODRR.Overlap_STR.MODRR1STR.Byte
    #define MODRR1_MODRR14              _MODRR.Overlap_STR.MODRR1STR.Bits.MODRR14
    #define MODRR1_MODRR15              _MODRR.Overlap_STR.MODRR1STR.Bits.MODRR15
    #define MODRR1_MODRR_14             _MODRR.Overlap_STR.MODRR1STR.MergedBits.grpMODRR_14
    #define MODRR1_MODRR                MODRR1_MODRR_14
    
    #define MODRR1_MODRR14_MASK         16U
    #define MODRR1_MODRR15_MASK         32U
    #define MODRR1_MODRR_14_MASK        48U
    #define MODRR1_MODRR_14_BITNUM      4U
    
  } Overlap_STR;

  struct {
    word MODRR00     :1;                                       /* Port T  routing */
    word MODRR01     :1;                                       /* Port T  routing */
    word MODRR02     :1;                                       /* Port T  routing */
    word MODRR03     :1;                                       /* Port T  routing */
    word MODRR04     :1;                                       /* Port T  routing */
    word MODRR05     :1;                                       /* Port T  routing */
    word MODRR06     :1;                                       /* Port T  routing */
    word MODRR07     :1;                                       /* Port T  routing */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word MODRR14     :1;                                       /* Port T  routing */
    word MODRR15     :1;                                       /* Port T  routing */
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpMODRR0 :8;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpMODRR_14 :2;
    word         :1;
    word         :1;
  } MergedBits;
} MODRRSTR;
extern volatile MODRRSTR _MODRR @(REG_BASE + 0x00000246UL);
#define MODRR                           _MODRR.Word
#define MODRR_MODRR00                   _MODRR.Bits.MODRR00
#define MODRR_MODRR01                   _MODRR.Bits.MODRR01
#define MODRR_MODRR02                   _MODRR.Bits.MODRR02
#define MODRR_MODRR03                   _MODRR.Bits.MODRR03
#define MODRR_MODRR04                   _MODRR.Bits.MODRR04
#define MODRR_MODRR05                   _MODRR.Bits.MODRR05
#define MODRR_MODRR06                   _MODRR.Bits.MODRR06
#define MODRR_MODRR07                   _MODRR.Bits.MODRR07
#define MODRR_MODRR14                   _MODRR.Bits.MODRR14
#define MODRR_MODRR15                   _MODRR.Bits.MODRR15
#define MODRR_MODRR0                    _MODRR.MergedBits.grpMODRR0
#define MODRR_MODRR_14                  _MODRR.MergedBits.grpMODRR_14

#define MODRR_MODRR00_MASK              1U
#define MODRR_MODRR01_MASK              2U
#define MODRR_MODRR02_MASK              4U
#define MODRR_MODRR03_MASK              8U
#define MODRR_MODRR04_MASK              16U
#define MODRR_MODRR05_MASK              32U
#define MODRR_MODRR06_MASK              64U
#define MODRR_MODRR07_MASK              128U
#define MODRR_MODRR14_MASK              4096U
#define MODRR_MODRR15_MASK              8192U
#define MODRR_MODRR0_MASK               255U
#define MODRR_MODRR0_BITNUM             0U
#define MODRR_MODRR_14_MASK             12288U
#define MODRR_MODRR_14_BITNUM           12U


/*** PTS - Port S Data Register; 0x00000248 ***/
typedef union {
  byte Byte;
  struct {
    byte PTS0        :1;                                       /* Port S general purpose input/output data bit 0 */
    byte PTS1        :1;                                       /* Port S general purpose input/output data bit 1 */
    byte PTS2        :1;                                       /* Port S general purpose input/output data bit 2 */
    byte PTS3        :1;                                       /* Port S general purpose input/output data bit 3 */
    byte PTS4        :1;                                       /* Port S general purpose input/output data bit 4 */
    byte PTS5        :1;                                       /* Port S general purpose input/output data bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTS  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTSSTR;
extern volatile PTSSTR _PTS @(REG_BASE + 0x00000248UL);
#define PTS                             _PTS.Byte
#define PTS_PTS0                        _PTS.Bits.PTS0
#define PTS_PTS1                        _PTS.Bits.PTS1
#define PTS_PTS2                        _PTS.Bits.PTS2
#define PTS_PTS3                        _PTS.Bits.PTS3
#define PTS_PTS4                        _PTS.Bits.PTS4
#define PTS_PTS5                        _PTS.Bits.PTS5
#define PTS_PTS                         _PTS.MergedBits.grpPTS

#define PTS_PTS0_MASK                   1U
#define PTS_PTS1_MASK                   2U
#define PTS_PTS2_MASK                   4U
#define PTS_PTS3_MASK                   8U
#define PTS_PTS4_MASK                   16U
#define PTS_PTS5_MASK                   32U
#define PTS_PTS_MASK                    63U
#define PTS_PTS_BITNUM                  0U


/*** PTIS - Port S Input Register; 0x00000249 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIS0       :1;                                       /* Port S input data bit 0 */
    byte PTIS1       :1;                                       /* Port S input data bit 1 */
    byte PTIS2       :1;                                       /* Port S input data bit 2 */
    byte PTIS3       :1;                                       /* Port S input data bit 3 */
    byte PTIS4       :1;                                       /* Port S input data bit 4 */
    byte PTIS5       :1;                                       /* Port S input data bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTIS :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTISSTR;
extern volatile PTISSTR _PTIS @(REG_BASE + 0x00000249UL);
#define PTIS                            _PTIS.Byte
#define PTIS_PTIS0                      _PTIS.Bits.PTIS0
#define PTIS_PTIS1                      _PTIS.Bits.PTIS1
#define PTIS_PTIS2                      _PTIS.Bits.PTIS2
#define PTIS_PTIS3                      _PTIS.Bits.PTIS3
#define PTIS_PTIS4                      _PTIS.Bits.PTIS4
#define PTIS_PTIS5                      _PTIS.Bits.PTIS5
#define PTIS_PTIS                       _PTIS.MergedBits.grpPTIS

#define PTIS_PTIS0_MASK                 1U
#define PTIS_PTIS1_MASK                 2U
#define PTIS_PTIS2_MASK                 4U
#define PTIS_PTIS3_MASK                 8U
#define PTIS_PTIS4_MASK                 16U
#define PTIS_PTIS5_MASK                 32U
#define PTIS_PTIS_MASK                  63U
#define PTIS_PTIS_BITNUM                0U


/*** DDRS - Port S Data Direction Register; 0x0000024A ***/
typedef union {
  byte Byte;
  struct {
    byte DDRS0       :1;                                       /* Port S data direction bit 0 */
    byte DDRS1       :1;                                       /* Port S data direction bit 1 */
    byte DDRS2       :1;                                       /* Port S data direction bit 2 */
    byte DDRS3       :1;                                       /* Port S data direction bit 3 */
    byte DDRS4       :1;                                       /* Port S data direction bit 4 */
    byte DDRS5       :1;                                       /* Port S data direction bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDDRS :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} DDRSSTR;
extern volatile DDRSSTR _DDRS @(REG_BASE + 0x0000024AUL);
#define DDRS                            _DDRS.Byte
#define DDRS_DDRS0                      _DDRS.Bits.DDRS0
#define DDRS_DDRS1                      _DDRS.Bits.DDRS1
#define DDRS_DDRS2                      _DDRS.Bits.DDRS2
#define DDRS_DDRS3                      _DDRS.Bits.DDRS3
#define DDRS_DDRS4                      _DDRS.Bits.DDRS4
#define DDRS_DDRS5                      _DDRS.Bits.DDRS5
#define DDRS_DDRS                       _DDRS.MergedBits.grpDDRS

#define DDRS_DDRS0_MASK                 1U
#define DDRS_DDRS1_MASK                 2U
#define DDRS_DDRS2_MASK                 4U
#define DDRS_DDRS3_MASK                 8U
#define DDRS_DDRS4_MASK                 16U
#define DDRS_DDRS5_MASK                 32U
#define DDRS_DDRS_MASK                  63U
#define DDRS_DDRS_BITNUM                0U


/*** PERS - Port S Pull Device Enable Register; 0x0000024C ***/
typedef union {
  byte Byte;
  struct {
    byte PERS0       :1;                                       /* Port S pull device enable bit 0 */
    byte PERS1       :1;                                       /* Port S pull device enable bit 1 */
    byte PERS2       :1;                                       /* Port S pull device enable bit 2 */
    byte PERS3       :1;                                       /* Port S pull device enable bit 3 */
    byte PERS4       :1;                                       /* Port S pull device enable bit 4 */
    byte PERS5       :1;                                       /* Port S pull device enable bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPERS :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PERSSTR;
extern volatile PERSSTR _PERS @(REG_BASE + 0x0000024CUL);
#define PERS                            _PERS.Byte
#define PERS_PERS0                      _PERS.Bits.PERS0
#define PERS_PERS1                      _PERS.Bits.PERS1
#define PERS_PERS2                      _PERS.Bits.PERS2
#define PERS_PERS3                      _PERS.Bits.PERS3
#define PERS_PERS4                      _PERS.Bits.PERS4
#define PERS_PERS5                      _PERS.Bits.PERS5
#define PERS_PERS                       _PERS.MergedBits.grpPERS

#define PERS_PERS0_MASK                 1U
#define PERS_PERS1_MASK                 2U
#define PERS_PERS2_MASK                 4U
#define PERS_PERS3_MASK                 8U
#define PERS_PERS4_MASK                 16U
#define PERS_PERS5_MASK                 32U
#define PERS_PERS_MASK                  63U
#define PERS_PERS_BITNUM                0U


/*** PPSS - Port S Polarity Select Register; 0x0000024D ***/
typedef union {
  byte Byte;
  struct {
    byte PPSS0       :1;                                       /* Port S pull device select bit 0 */
    byte PPSS1       :1;                                       /* Port S pull device select bit 1 */
    byte PPSS2       :1;                                       /* Port S pull device select bit 2 */
    byte PPSS3       :1;                                       /* Port S pull device select bit 3 */
    byte PPSS4       :1;                                       /* Port S pull device select bit 4 */
    byte PPSS5       :1;                                       /* Port S pull device select bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPPSS :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPSSSTR;
extern volatile PPSSSTR _PPSS @(REG_BASE + 0x0000024DUL);
#define PPSS                            _PPSS.Byte
#define PPSS_PPSS0                      _PPSS.Bits.PPSS0
#define PPSS_PPSS1                      _PPSS.Bits.PPSS1
#define PPSS_PPSS2                      _PPSS.Bits.PPSS2
#define PPSS_PPSS3                      _PPSS.Bits.PPSS3
#define PPSS_PPSS4                      _PPSS.Bits.PPSS4
#define PPSS_PPSS5                      _PPSS.Bits.PPSS5
#define PPSS_PPSS                       _PPSS.MergedBits.grpPPSS

#define PPSS_PPSS0_MASK                 1U
#define PPSS_PPSS1_MASK                 2U
#define PPSS_PPSS2_MASK                 4U
#define PPSS_PPSS3_MASK                 8U
#define PPSS_PPSS4_MASK                 16U
#define PPSS_PPSS5_MASK                 32U
#define PPSS_PPSS_MASK                  63U
#define PPSS_PPSS_BITNUM                0U


/*** WOMS - Port S Wired-Or Mode Register; 0x0000024E ***/
typedef union {
  byte Byte;
  struct {
    byte WOMS0       :1;                                       /* Port S wired-or mode bit 0 */
    byte WOMS1       :1;                                       /* Port S wired-or mode bit 1 */
    byte WOMS2       :1;                                       /* Port S wired-or mode bit 2 */
    byte WOMS3       :1;                                       /* Port S wired-or mode bit 3 */
    byte WOMS4       :1;                                       /* Port S wired-or mode bit 4 */
    byte WOMS5       :1;                                       /* Port S wired-or mode bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpWOMS :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} WOMSSTR;
extern volatile WOMSSTR _WOMS @(REG_BASE + 0x0000024EUL);
#define WOMS                            _WOMS.Byte
#define WOMS_WOMS0                      _WOMS.Bits.WOMS0
#define WOMS_WOMS1                      _WOMS.Bits.WOMS1
#define WOMS_WOMS2                      _WOMS.Bits.WOMS2
#define WOMS_WOMS3                      _WOMS.Bits.WOMS3
#define WOMS_WOMS4                      _WOMS.Bits.WOMS4
#define WOMS_WOMS5                      _WOMS.Bits.WOMS5
#define WOMS_WOMS                       _WOMS.MergedBits.grpWOMS

#define WOMS_WOMS0_MASK                 1U
#define WOMS_WOMS1_MASK                 2U
#define WOMS_WOMS2_MASK                 4U
#define WOMS_WOMS3_MASK                 8U
#define WOMS_WOMS4_MASK                 16U
#define WOMS_WOMS5_MASK                 32U
#define WOMS_WOMS_MASK                  63U
#define WOMS_WOMS_BITNUM                0U


/*** MODRR2 - Module Routing Register; 0x0000024F ***/
typedef union {
  byte Byte;
  struct {
    byte MODRR20     :1;                                       /* Module Routing bit 0 */
    byte MODRR21     :1;                                       /* Module Routing bit 1 */
    byte MODRR22     :1;                                       /* Module Routing bit 2 */
    byte MODRR23     :1;                                       /* Module Routing bit 3 */
    byte MODRR24     :1;                                       /* Module Routing bit 4 */
    byte MODRR25     :1;                                       /* Module Routing bit 5 */
    byte             :1; 
    byte MODRR27     :1;                                       /* Module Routing bit 7 */
  } Bits;
  struct {
    byte grpMODRR_20 :6;
    byte         :1;
    byte grpMODRR_27 :1;
  } MergedBits;
} MODRR2STR;
extern volatile MODRR2STR _MODRR2 @(REG_BASE + 0x0000024FUL);
#define MODRR2                          _MODRR2.Byte
#define MODRR2_MODRR20                  _MODRR2.Bits.MODRR20
#define MODRR2_MODRR21                  _MODRR2.Bits.MODRR21
#define MODRR2_MODRR22                  _MODRR2.Bits.MODRR22
#define MODRR2_MODRR23                  _MODRR2.Bits.MODRR23
#define MODRR2_MODRR24                  _MODRR2.Bits.MODRR24
#define MODRR2_MODRR25                  _MODRR2.Bits.MODRR25
#define MODRR2_MODRR27                  _MODRR2.Bits.MODRR27
#define MODRR2_MODRR_20                 _MODRR2.MergedBits.grpMODRR_20
#define MODRR2_MODRR                    MODRR2_MODRR_20

#define MODRR2_MODRR20_MASK             1U
#define MODRR2_MODRR21_MASK             2U
#define MODRR2_MODRR22_MASK             4U
#define MODRR2_MODRR23_MASK             8U
#define MODRR2_MODRR24_MASK             16U
#define MODRR2_MODRR25_MASK             32U
#define MODRR2_MODRR27_MASK             128U
#define MODRR2_MODRR_20_MASK            63U
#define MODRR2_MODRR_20_BITNUM          0U


/*** PTP - Port P Data Register; 0x00000258 ***/
typedef union {
  byte Byte;
  struct {
    byte PTP0        :1;                                       /* Port P general purpose input/output data bit 0 */
    byte PTP1        :1;                                       /* Port P general purpose input/output data bit 1 */
    byte PTP2        :1;                                       /* Port P general purpose input/output data bit 2 */
    byte PTP3        :1;                                       /* Port P general purpose input/output data bit 3 */
    byte PTP4        :1;                                       /* Port P general purpose input/output data bit 4 */
    byte PTP5        :1;                                       /* Port P general purpose input/output data bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTP  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTPSTR;
extern volatile PTPSTR _PTP @(REG_BASE + 0x00000258UL);
#define PTP                             _PTP.Byte
#define PTP_PTP0                        _PTP.Bits.PTP0
#define PTP_PTP1                        _PTP.Bits.PTP1
#define PTP_PTP2                        _PTP.Bits.PTP2
#define PTP_PTP3                        _PTP.Bits.PTP3
#define PTP_PTP4                        _PTP.Bits.PTP4
#define PTP_PTP5                        _PTP.Bits.PTP5
#define PTP_PTP                         _PTP.MergedBits.grpPTP

#define PTP_PTP0_MASK                   1U
#define PTP_PTP1_MASK                   2U
#define PTP_PTP2_MASK                   4U
#define PTP_PTP3_MASK                   8U
#define PTP_PTP4_MASK                   16U
#define PTP_PTP5_MASK                   32U
#define PTP_PTP_MASK                    63U
#define PTP_PTP_BITNUM                  0U


/*** PTIP - Port P Input Register; 0x00000259 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIP0       :1;                                       /* Port P input data bit 0 */
    byte PTIP1       :1;                                       /* Port P input data bit 1 */
    byte PTIP2       :1;                                       /* Port P input data bit 2 */
    byte PTIP3       :1;                                       /* Port P input data bit 3 */
    byte PTIP4       :1;                                       /* Port P input data bit 4 */
    byte PTIP5       :1;                                       /* Port P input data bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTIP :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTIPSTR;
extern volatile PTIPSTR _PTIP @(REG_BASE + 0x00000259UL);
#define PTIP                            _PTIP.Byte
#define PTIP_PTIP0                      _PTIP.Bits.PTIP0
#define PTIP_PTIP1                      _PTIP.Bits.PTIP1
#define PTIP_PTIP2                      _PTIP.Bits.PTIP2
#define PTIP_PTIP3                      _PTIP.Bits.PTIP3
#define PTIP_PTIP4                      _PTIP.Bits.PTIP4
#define PTIP_PTIP5                      _PTIP.Bits.PTIP5
#define PTIP_PTIP                       _PTIP.MergedBits.grpPTIP

#define PTIP_PTIP0_MASK                 1U
#define PTIP_PTIP1_MASK                 2U
#define PTIP_PTIP2_MASK                 4U
#define PTIP_PTIP3_MASK                 8U
#define PTIP_PTIP4_MASK                 16U
#define PTIP_PTIP5_MASK                 32U
#define PTIP_PTIP_MASK                  63U
#define PTIP_PTIP_BITNUM                0U


/*** DDRP - Port P Data Direction Register; 0x0000025A ***/
typedef union {
  byte Byte;
  struct {
    byte DDRP0       :1;                                       /* Port P data direction bit 0 */
    byte DDRP1       :1;                                       /* Port P data direction bit 1 */
    byte DDRP2       :1;                                       /* Port P data direction bit 2 */
    byte DDRP3       :1;                                       /* Port P data direction bit 3 */
    byte DDRP4       :1;                                       /* Port P data direction bit 4 */
    byte DDRP5       :1;                                       /* Port P data direction bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDDRP :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} DDRPSTR;
extern volatile DDRPSTR _DDRP @(REG_BASE + 0x0000025AUL);
#define DDRP                            _DDRP.Byte
#define DDRP_DDRP0                      _DDRP.Bits.DDRP0
#define DDRP_DDRP1                      _DDRP.Bits.DDRP1
#define DDRP_DDRP2                      _DDRP.Bits.DDRP2
#define DDRP_DDRP3                      _DDRP.Bits.DDRP3
#define DDRP_DDRP4                      _DDRP.Bits.DDRP4
#define DDRP_DDRP5                      _DDRP.Bits.DDRP5
#define DDRP_DDRP                       _DDRP.MergedBits.grpDDRP

#define DDRP_DDRP0_MASK                 1U
#define DDRP_DDRP1_MASK                 2U
#define DDRP_DDRP2_MASK                 4U
#define DDRP_DDRP3_MASK                 8U
#define DDRP_DDRP4_MASK                 16U
#define DDRP_DDRP5_MASK                 32U
#define DDRP_DDRP_MASK                  63U
#define DDRP_DDRP_BITNUM                0U


/*** RDRP - Port P Reduced Drive Register; 0x0000025B ***/
typedef union {
  byte Byte;
  struct {
    byte RDRP0       :1;                                       /* Port P reduced drive bit 0 */
    byte RDRP1       :1;                                       /* Port P reduced drive bit 1 */
    byte RDRP2       :1;                                       /* Port P reduced drive bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpRDRP :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} RDRPSTR;
extern volatile RDRPSTR _RDRP @(REG_BASE + 0x0000025BUL);
#define RDRP                            _RDRP.Byte
#define RDRP_RDRP0                      _RDRP.Bits.RDRP0
#define RDRP_RDRP1                      _RDRP.Bits.RDRP1
#define RDRP_RDRP2                      _RDRP.Bits.RDRP2
#define RDRP_RDRP                       _RDRP.MergedBits.grpRDRP

#define RDRP_RDRP0_MASK                 1U
#define RDRP_RDRP1_MASK                 2U
#define RDRP_RDRP2_MASK                 4U
#define RDRP_RDRP_MASK                  7U
#define RDRP_RDRP_BITNUM                0U


/*** PERP - Port P Pull Device Enable Register; 0x0000025C ***/
typedef union {
  byte Byte;
  struct {
    byte PERP0       :1;                                       /* Port P pull device enable bit 0 */
    byte PERP1       :1;                                       /* Port P pull device enable bit 1 */
    byte PERP2       :1;                                       /* Port P pull device enable bit 2 */
    byte PERP3       :1;                                       /* Port P pull device enable bit 3 */
    byte PERP4       :1;                                       /* Port P pull device enable bit 4 */
    byte PERP5       :1;                                       /* Port P pull device enable bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPERP :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PERPSTR;
extern volatile PERPSTR _PERP @(REG_BASE + 0x0000025CUL);
#define PERP                            _PERP.Byte
#define PERP_PERP0                      _PERP.Bits.PERP0
#define PERP_PERP1                      _PERP.Bits.PERP1
#define PERP_PERP2                      _PERP.Bits.PERP2
#define PERP_PERP3                      _PERP.Bits.PERP3
#define PERP_PERP4                      _PERP.Bits.PERP4
#define PERP_PERP5                      _PERP.Bits.PERP5
#define PERP_PERP                       _PERP.MergedBits.grpPERP

#define PERP_PERP0_MASK                 1U
#define PERP_PERP1_MASK                 2U
#define PERP_PERP2_MASK                 4U
#define PERP_PERP3_MASK                 8U
#define PERP_PERP4_MASK                 16U
#define PERP_PERP5_MASK                 32U
#define PERP_PERP_MASK                  63U
#define PERP_PERP_BITNUM                0U


/*** PPSP - Port P Polarity Select Register; 0x0000025D ***/
typedef union {
  byte Byte;
  struct {
    byte PPSP0       :1;                                       /* Port P pull device select bit 0 */
    byte PPSP1       :1;                                       /* Port P pull device select bit 1 */
    byte PPSP2       :1;                                       /* Port P pull device select bit 2 */
    byte PPSP3       :1;                                       /* Port P pull device select bit 3 */
    byte PPSP4       :1;                                       /* Port P pull device select bit 4 */
    byte PPSP5       :1;                                       /* Port P pull device select bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPPSP :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPSPSTR;
extern volatile PPSPSTR _PPSP @(REG_BASE + 0x0000025DUL);
#define PPSP                            _PPSP.Byte
#define PPSP_PPSP0                      _PPSP.Bits.PPSP0
#define PPSP_PPSP1                      _PPSP.Bits.PPSP1
#define PPSP_PPSP2                      _PPSP.Bits.PPSP2
#define PPSP_PPSP3                      _PPSP.Bits.PPSP3
#define PPSP_PPSP4                      _PPSP.Bits.PPSP4
#define PPSP_PPSP5                      _PPSP.Bits.PPSP5
#define PPSP_PPSP                       _PPSP.MergedBits.grpPPSP

#define PPSP_PPSP0_MASK                 1U
#define PPSP_PPSP1_MASK                 2U
#define PPSP_PPSP2_MASK                 4U
#define PPSP_PPSP3_MASK                 8U
#define PPSP_PPSP4_MASK                 16U
#define PPSP_PPSP5_MASK                 32U
#define PPSP_PPSP_MASK                  63U
#define PPSP_PPSP_BITNUM                0U


/*** PIEP - Port P Interrupt Enable Register; 0x0000025E ***/
typedef union {
  byte Byte;
  struct {
    byte PIEP0       :1;                                       /* Port P interrupt enable bit 0 */
    byte PIEP1       :1;                                       /* Port P interrupt enable bit 1 */
    byte PIEP2       :1;                                       /* Port P interrupt enable bit 2 */
    byte PIEP3       :1;                                       /* Port P interrupt enable bit 3 */
    byte PIEP4       :1;                                       /* Port P interrupt enable bit 4 */
    byte PIEP5       :1;                                       /* Port P interrupt enable bit 5 */
    byte             :1; 
    byte OCIE        :1;                                       /* Over-Current Interrupt Enable */
  } Bits;
  struct {
    byte grpPIEP :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PIEPSTR;
extern volatile PIEPSTR _PIEP @(REG_BASE + 0x0000025EUL);
#define PIEP                            _PIEP.Byte
#define PIEP_PIEP0                      _PIEP.Bits.PIEP0
#define PIEP_PIEP1                      _PIEP.Bits.PIEP1
#define PIEP_PIEP2                      _PIEP.Bits.PIEP2
#define PIEP_PIEP3                      _PIEP.Bits.PIEP3
#define PIEP_PIEP4                      _PIEP.Bits.PIEP4
#define PIEP_PIEP5                      _PIEP.Bits.PIEP5
#define PIEP_OCIE                       _PIEP.Bits.OCIE
#define PIEP_PIEP                       _PIEP.MergedBits.grpPIEP

#define PIEP_PIEP0_MASK                 1U
#define PIEP_PIEP1_MASK                 2U
#define PIEP_PIEP2_MASK                 4U
#define PIEP_PIEP3_MASK                 8U
#define PIEP_PIEP4_MASK                 16U
#define PIEP_PIEP5_MASK                 32U
#define PIEP_OCIE_MASK                  128U
#define PIEP_PIEP_MASK                  63U
#define PIEP_PIEP_BITNUM                0U


/*** PIFP - Port P Interrupt Flag Register; 0x0000025F ***/
typedef union {
  byte Byte;
  struct {
    byte PIFP0       :1;                                       /* Port P interrupt flag bit 0 */
    byte PIFP1       :1;                                       /* Port P interrupt flag bit 1 */
    byte PIFP2       :1;                                       /* Port P interrupt flag bit 2 */
    byte PIFP3       :1;                                       /* Port P interrupt flag bit 3 */
    byte PIFP4       :1;                                       /* Port P interrupt flag bit 4 */
    byte PIFP5       :1;                                       /* Port P interrupt flag bit 5 */
    byte             :1; 
    byte OCIF        :1;                                       /* Over-Current Interrupt Flag */
  } Bits;
  struct {
    byte grpPIFP :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PIFPSTR;
extern volatile PIFPSTR _PIFP @(REG_BASE + 0x0000025FUL);
#define PIFP                            _PIFP.Byte
#define PIFP_PIFP0                      _PIFP.Bits.PIFP0
#define PIFP_PIFP1                      _PIFP.Bits.PIFP1
#define PIFP_PIFP2                      _PIFP.Bits.PIFP2
#define PIFP_PIFP3                      _PIFP.Bits.PIFP3
#define PIFP_PIFP4                      _PIFP.Bits.PIFP4
#define PIFP_PIFP5                      _PIFP.Bits.PIFP5
#define PIFP_OCIF                       _PIFP.Bits.OCIF
#define PIFP_PIFP                       _PIFP.MergedBits.grpPIFP

#define PIFP_PIFP0_MASK                 1U
#define PIFP_PIFP1_MASK                 2U
#define PIFP_PIFP2_MASK                 4U
#define PIFP_PIFP3_MASK                 8U
#define PIFP_PIFP4_MASK                 16U
#define PIFP_PIFP5_MASK                 32U
#define PIFP_OCIF_MASK                  128U
#define PIFP_PIFP_MASK                  63U
#define PIFP_PIFP_BITNUM                0U


/*** PTIL - Port L Input Register; 0x00000269 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIL0       :1;                                       /* Port L Bit 0 */
    byte PTIL1       :1;                                       /* Port L Bit 1 */
    byte PTIL2       :1;                                       /* Port L Bit 2 */
    byte PTIL3       :1;                                       /* Port L Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTIL :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTILSTR;
extern volatile PTILSTR _PTIL @(REG_BASE + 0x00000269UL);
#define PTIL                            _PTIL.Byte
#define PTIL_PTIL0                      _PTIL.Bits.PTIL0
#define PTIL_PTIL1                      _PTIL.Bits.PTIL1
#define PTIL_PTIL2                      _PTIL.Bits.PTIL2
#define PTIL_PTIL3                      _PTIL.Bits.PTIL3
#define PTIL_PTIL                       _PTIL.MergedBits.grpPTIL

#define PTIL_PTIL0_MASK                 1U
#define PTIL_PTIL1_MASK                 2U
#define PTIL_PTIL2_MASK                 4U
#define PTIL_PTIL3_MASK                 8U
#define PTIL_PTIL_MASK                  15U
#define PTIL_PTIL_BITNUM                0U


/*** DIENL - Port L Digital Input Enable Register; 0x0000026A ***/
typedef union {
  byte Byte;
  struct {
    byte DIENL0      :1;                                       /* Digital Input Enable Port L Bit 0 */
    byte DIENL1      :1;                                       /* Digital Input Enable Port L Bit 1 */
    byte DIENL2      :1;                                       /* Digital Input Enable Port L Bit 2 */
    byte DIENL3      :1;                                       /* Digital Input Enable Port L Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDIENL :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DIENLSTR;
extern volatile DIENLSTR _DIENL @(REG_BASE + 0x0000026AUL);
#define DIENL                           _DIENL.Byte
#define DIENL_DIENL0                    _DIENL.Bits.DIENL0
#define DIENL_DIENL1                    _DIENL.Bits.DIENL1
#define DIENL_DIENL2                    _DIENL.Bits.DIENL2
#define DIENL_DIENL3                    _DIENL.Bits.DIENL3
#define DIENL_DIENL                     _DIENL.MergedBits.grpDIENL

#define DIENL_DIENL0_MASK               1U
#define DIENL_DIENL1_MASK               2U
#define DIENL_DIENL2_MASK               4U
#define DIENL_DIENL3_MASK               8U
#define DIENL_DIENL_MASK                15U
#define DIENL_DIENL_BITNUM              0U


/*** PTAL - Port L Analog Access Register; 0x0000026B ***/
typedef union {
  byte Byte;
  struct {
    byte PTAL0       :1;                                       /* Port ADC connection selector, bit 0 */
    byte PTAL1       :1;                                       /* Port ADC connection selector, bit 1 */
    byte             :1; 
    byte PTAENL      :1;                                       /* Port ADC connection enable */
    byte PTADIRL     :1;                                       /* Port ADC direct connection */
    byte PTABYPL     :1;                                       /* Port ADC connection bypass */
    byte PTPSL       :1;                                       /* Port pull select */
    byte PTTEL       :1;                                       /* Port test enable */
  } Bits;
  struct {
    byte grpPTAL :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTALSTR;
extern volatile PTALSTR _PTAL @(REG_BASE + 0x0000026BUL);
#define PTAL                            _PTAL.Byte
#define PTAL_PTAL0                      _PTAL.Bits.PTAL0
#define PTAL_PTAL1                      _PTAL.Bits.PTAL1
#define PTAL_PTAENL                     _PTAL.Bits.PTAENL
#define PTAL_PTADIRL                    _PTAL.Bits.PTADIRL
#define PTAL_PTABYPL                    _PTAL.Bits.PTABYPL
#define PTAL_PTPSL                      _PTAL.Bits.PTPSL
#define PTAL_PTTEL                      _PTAL.Bits.PTTEL
#define PTAL_PTAL                       _PTAL.MergedBits.grpPTAL

#define PTAL_PTAL0_MASK                 1U
#define PTAL_PTAL1_MASK                 2U
#define PTAL_PTAENL_MASK                8U
#define PTAL_PTADIRL_MASK               16U
#define PTAL_PTABYPL_MASK               32U
#define PTAL_PTPSL_MASK                 64U
#define PTAL_PTTEL_MASK                 128U
#define PTAL_PTAL_MASK                  3U
#define PTAL_PTAL_BITNUM                0U


/*** PIRL - Port L Input Divider Ratio Selection Register; 0x0000026C ***/
typedef union {
  byte Byte;
  struct {
    byte PIRL0       :1;                                       /* Port L Input Divider Ratio SelectBit 0 */
    byte PIRL1       :1;                                       /* Port L Input Divider Ratio SelectBit 1 */
    byte PIRL2       :1;                                       /* Port L Input Divider Ratio SelectBit 2 */
    byte PIRL3       :1;                                       /* Port L Input Divider Ratio SelectBit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPIRL :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PIRLSTR;
extern volatile PIRLSTR _PIRL @(REG_BASE + 0x0000026CUL);
#define PIRL                            _PIRL.Byte
#define PIRL_PIRL0                      _PIRL.Bits.PIRL0
#define PIRL_PIRL1                      _PIRL.Bits.PIRL1
#define PIRL_PIRL2                      _PIRL.Bits.PIRL2
#define PIRL_PIRL3                      _PIRL.Bits.PIRL3
#define PIRL_PIRL                       _PIRL.MergedBits.grpPIRL

#define PIRL_PIRL0_MASK                 1U
#define PIRL_PIRL1_MASK                 2U
#define PIRL_PIRL2_MASK                 4U
#define PIRL_PIRL3_MASK                 8U
#define PIRL_PIRL_MASK                  15U
#define PIRL_PIRL_BITNUM                0U


/*** PPSL - Port L Polarity Select Register; 0x0000026D ***/
typedef union {
  byte Byte;
  struct {
    byte PPSL0       :1;                                       /* Pin Interrupt Polarity Select Port L Bit 0 */
    byte PPSL1       :1;                                       /* Pin Interrupt Polarity Select Port L Bit 1 */
    byte PPSL2       :1;                                       /* Pin Interrupt Polarity Select Port L Bit 2 */
    byte PPSL3       :1;                                       /* Pin Interrupt Polarity Select Port L Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPPSL :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPSLSTR;
extern volatile PPSLSTR _PPSL @(REG_BASE + 0x0000026DUL);
#define PPSL                            _PPSL.Byte
#define PPSL_PPSL0                      _PPSL.Bits.PPSL0
#define PPSL_PPSL1                      _PPSL.Bits.PPSL1
#define PPSL_PPSL2                      _PPSL.Bits.PPSL2
#define PPSL_PPSL3                      _PPSL.Bits.PPSL3
#define PPSL_PPSL                       _PPSL.MergedBits.grpPPSL

#define PPSL_PPSL0_MASK                 1U
#define PPSL_PPSL1_MASK                 2U
#define PPSL_PPSL2_MASK                 4U
#define PPSL_PPSL3_MASK                 8U
#define PPSL_PPSL_MASK                  15U
#define PPSL_PPSL_BITNUM                0U


/*** PIEL - Port L Interrupt Enable Register; 0x0000026E ***/
typedef union {
  byte Byte;
  struct {
    byte PIEL0       :1;                                       /* Interrupt Enable Port L Bit 0 */
    byte PIEL1       :1;                                       /* Interrupt Enable Port L Bit 1 */
    byte PIEL2       :1;                                       /* Interrupt Enable Port L Bit 2 */
    byte PIEL3       :1;                                       /* Interrupt Enable Port L Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPIEL :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PIELSTR;
extern volatile PIELSTR _PIEL @(REG_BASE + 0x0000026EUL);
#define PIEL                            _PIEL.Byte
#define PIEL_PIEL0                      _PIEL.Bits.PIEL0
#define PIEL_PIEL1                      _PIEL.Bits.PIEL1
#define PIEL_PIEL2                      _PIEL.Bits.PIEL2
#define PIEL_PIEL3                      _PIEL.Bits.PIEL3
#define PIEL_PIEL                       _PIEL.MergedBits.grpPIEL

#define PIEL_PIEL0_MASK                 1U
#define PIEL_PIEL1_MASK                 2U
#define PIEL_PIEL2_MASK                 4U
#define PIEL_PIEL3_MASK                 8U
#define PIEL_PIEL_MASK                  15U
#define PIEL_PIEL_BITNUM                0U


/*** PIFL - Port L Interrupt Flag Register; 0x0000026F ***/
typedef union {
  byte Byte;
  struct {
    byte PIFL0       :1;                                       /* Interrupt Flags Port L Bit 0 */
    byte PIFL1       :1;                                       /* Interrupt Flags Port L Bit 1 */
    byte PIFL2       :1;                                       /* Interrupt Flags Port L Bit 2 */
    byte PIFL3       :1;                                       /* Interrupt Flags Port L Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPIFL :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PIFLSTR;
extern volatile PIFLSTR _PIFL @(REG_BASE + 0x0000026FUL);
#define PIFL                            _PIFL.Byte
#define PIFL_PIFL0                      _PIFL.Bits.PIFL0
#define PIFL_PIFL1                      _PIFL.Bits.PIFL1
#define PIFL_PIFL2                      _PIFL.Bits.PIFL2
#define PIFL_PIFL3                      _PIFL.Bits.PIFL3
#define PIFL_PIFL                       _PIFL.MergedBits.grpPIFL

#define PIFL_PIFL0_MASK                 1U
#define PIFL_PIFL1_MASK                 2U
#define PIFL_PIFL2_MASK                 4U
#define PIFL_PIFL3_MASK                 8U
#define PIFL_PIFL_MASK                  15U
#define PIFL_PIFL_BITNUM                0U


/*** PT1AD - Port ADL Data Register; 0x00000271 ***/
typedef union {
  byte Byte;
  struct {
    byte PT1AD0      :1;                                       /* Port AD data bit 0 */
    byte PT1AD1      :1;                                       /* Port AD data bit 1 */
    byte PT1AD2      :1;                                       /* Port AD data bit 2 */
    byte PT1AD3      :1;                                       /* Port AD data bit 3 */
    byte PT1AD4      :1;                                       /* Port AD data bit 4 */
    byte PT1AD5      :1;                                       /* Port AD data bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPT1AD :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PT1ADSTR;
extern volatile PT1ADSTR _PT1AD @(REG_BASE + 0x00000271UL);
#define PT1AD                           _PT1AD.Byte
#define PT1AD_PT1AD0                    _PT1AD.Bits.PT1AD0
#define PT1AD_PT1AD1                    _PT1AD.Bits.PT1AD1
#define PT1AD_PT1AD2                    _PT1AD.Bits.PT1AD2
#define PT1AD_PT1AD3                    _PT1AD.Bits.PT1AD3
#define PT1AD_PT1AD4                    _PT1AD.Bits.PT1AD4
#define PT1AD_PT1AD5                    _PT1AD.Bits.PT1AD5
#define PT1AD_PT1AD                     _PT1AD.MergedBits.grpPT1AD

#define PT1AD_PT1AD0_MASK               1U
#define PT1AD_PT1AD1_MASK               2U
#define PT1AD_PT1AD2_MASK               4U
#define PT1AD_PT1AD3_MASK               8U
#define PT1AD_PT1AD4_MASK               16U
#define PT1AD_PT1AD5_MASK               32U
#define PT1AD_PT1AD_MASK                63U
#define PT1AD_PT1AD_BITNUM              0U


/*** PTI1AD - Port ADL Input Register; 0x00000273 ***/
typedef union {
  byte Byte;
  struct {
    byte PTI1AD0     :1;                                       /* Port ADL Bit 0 */
    byte PTI1AD1     :1;                                       /* Port ADL Bit 1 */
    byte PTI1AD2     :1;                                       /* Port ADL Bit 2 */
    byte PTI1AD3     :1;                                       /* Port ADL Bit 3 */
    byte PTI1AD4     :1;                                       /* Port ADL Bit 4 */
    byte PTI1AD5     :1;                                       /* Port ADL Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTI1AD :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTI1ADSTR;
extern volatile PTI1ADSTR _PTI1AD @(REG_BASE + 0x00000273UL);
#define PTI1AD                          _PTI1AD.Byte
#define PTI1AD_PTI1AD0                  _PTI1AD.Bits.PTI1AD0
#define PTI1AD_PTI1AD1                  _PTI1AD.Bits.PTI1AD1
#define PTI1AD_PTI1AD2                  _PTI1AD.Bits.PTI1AD2
#define PTI1AD_PTI1AD3                  _PTI1AD.Bits.PTI1AD3
#define PTI1AD_PTI1AD4                  _PTI1AD.Bits.PTI1AD4
#define PTI1AD_PTI1AD5                  _PTI1AD.Bits.PTI1AD5
#define PTI1AD_PTI1AD                   _PTI1AD.MergedBits.grpPTI1AD

#define PTI1AD_PTI1AD0_MASK             1U
#define PTI1AD_PTI1AD1_MASK             2U
#define PTI1AD_PTI1AD2_MASK             4U
#define PTI1AD_PTI1AD3_MASK             8U
#define PTI1AD_PTI1AD4_MASK             16U
#define PTI1AD_PTI1AD5_MASK             32U
#define PTI1AD_PTI1AD_MASK              63U
#define PTI1AD_PTI1AD_BITNUM            0U


/*** DDR1AD - Port ADL Data Direction Register; 0x00000275 ***/
typedef union {
  byte Byte;
  struct {
    byte DDR1AD0     :1;                                       /* Port AD data direction bit 0 */
    byte DDR1AD1     :1;                                       /* Port AD data direction bit 1 */
    byte DDR1AD2     :1;                                       /* Port AD data direction bit 2 */
    byte DDR1AD3     :1;                                       /* Port AD data direction bit 3 */
    byte DDR1AD4     :1;                                       /* Port AD data direction bit 4 */
    byte DDR1AD5     :1;                                       /* Port AD data direction bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDDR1AD :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} DDR1ADSTR;
extern volatile DDR1ADSTR _DDR1AD @(REG_BASE + 0x00000275UL);
#define DDR1AD                          _DDR1AD.Byte
#define DDR1AD_DDR1AD0                  _DDR1AD.Bits.DDR1AD0
#define DDR1AD_DDR1AD1                  _DDR1AD.Bits.DDR1AD1
#define DDR1AD_DDR1AD2                  _DDR1AD.Bits.DDR1AD2
#define DDR1AD_DDR1AD3                  _DDR1AD.Bits.DDR1AD3
#define DDR1AD_DDR1AD4                  _DDR1AD.Bits.DDR1AD4
#define DDR1AD_DDR1AD5                  _DDR1AD.Bits.DDR1AD5
#define DDR1AD_DDR1AD                   _DDR1AD.MergedBits.grpDDR1AD

#define DDR1AD_DDR1AD0_MASK             1U
#define DDR1AD_DDR1AD1_MASK             2U
#define DDR1AD_DDR1AD2_MASK             4U
#define DDR1AD_DDR1AD3_MASK             8U
#define DDR1AD_DDR1AD4_MASK             16U
#define DDR1AD_DDR1AD5_MASK             32U
#define DDR1AD_DDR1AD_MASK              63U
#define DDR1AD_DDR1AD_BITNUM            0U


/*** PER1AD - Port ADL Pull Up Enable Register; 0x00000279 ***/
typedef union {
  byte Byte;
  struct {
    byte PER1AD0     :1;                                       /* Port ADL pull up enable bit 0 */
    byte PER1AD1     :1;                                       /* Port ADL pull up enable bit 1 */
    byte PER1AD2     :1;                                       /* Port ADL pull up enable bit 2 */
    byte PER1AD3     :1;                                       /* Port ADL pull up enable bit 3 */
    byte PER1AD4     :1;                                       /* Port ADL pull up enable bit 4 */
    byte PER1AD5     :1;                                       /* Port ADL pull up enable bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPER1AD :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PER1ADSTR;
extern volatile PER1ADSTR _PER1AD @(REG_BASE + 0x00000279UL);
#define PER1AD                          _PER1AD.Byte
#define PER1AD_PER1AD0                  _PER1AD.Bits.PER1AD0
#define PER1AD_PER1AD1                  _PER1AD.Bits.PER1AD1
#define PER1AD_PER1AD2                  _PER1AD.Bits.PER1AD2
#define PER1AD_PER1AD3                  _PER1AD.Bits.PER1AD3
#define PER1AD_PER1AD4                  _PER1AD.Bits.PER1AD4
#define PER1AD_PER1AD5                  _PER1AD.Bits.PER1AD5
#define PER1AD_PER1AD                   _PER1AD.MergedBits.grpPER1AD

#define PER1AD_PER1AD0_MASK             1U
#define PER1AD_PER1AD1_MASK             2U
#define PER1AD_PER1AD2_MASK             4U
#define PER1AD_PER1AD3_MASK             8U
#define PER1AD_PER1AD4_MASK             16U
#define PER1AD_PER1AD5_MASK             32U
#define PER1AD_PER1AD_MASK              63U
#define PER1AD_PER1AD_BITNUM            0U


/*** PPS1AD - Port ADL Polarity Select Register; 0x0000027B ***/
typedef union {
  byte Byte;
  struct {
    byte PPS1AD0     :1;                                       /* Port ADL Polarity Select Bit 0 */
    byte PPS1AD1     :1;                                       /* Port ADL Polarity Select Bit 1 */
    byte PPS1AD2     :1;                                       /* Port ADL Polarity Select Bit 2 */
    byte PPS1AD3     :1;                                       /* Port ADL Polarity Select Bit 3 */
    byte PPS1AD4     :1;                                       /* Port ADL Polarity Select Bit 4 */
    byte PPS1AD5     :1;                                       /* Port ADL Polarity Select Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPPS1AD :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPS1ADSTR;
extern volatile PPS1ADSTR _PPS1AD @(REG_BASE + 0x0000027BUL);
#define PPS1AD                          _PPS1AD.Byte
#define PPS1AD_PPS1AD0                  _PPS1AD.Bits.PPS1AD0
#define PPS1AD_PPS1AD1                  _PPS1AD.Bits.PPS1AD1
#define PPS1AD_PPS1AD2                  _PPS1AD.Bits.PPS1AD2
#define PPS1AD_PPS1AD3                  _PPS1AD.Bits.PPS1AD3
#define PPS1AD_PPS1AD4                  _PPS1AD.Bits.PPS1AD4
#define PPS1AD_PPS1AD5                  _PPS1AD.Bits.PPS1AD5
#define PPS1AD_PPS1AD                   _PPS1AD.MergedBits.grpPPS1AD

#define PPS1AD_PPS1AD0_MASK             1U
#define PPS1AD_PPS1AD1_MASK             2U
#define PPS1AD_PPS1AD2_MASK             4U
#define PPS1AD_PPS1AD3_MASK             8U
#define PPS1AD_PPS1AD4_MASK             16U
#define PPS1AD_PPS1AD5_MASK             32U
#define PPS1AD_PPS1AD_MASK              63U
#define PPS1AD_PPS1AD_BITNUM            0U


/*** PIE1AD - Port ADL Interrupt Enable Register; 0x0000027D ***/
typedef union {
  byte Byte;
  struct {
    byte PIE1AD0     :1;                                       /* Port ADL Interrupt Enable Bit 0 */
    byte PIE1AD1     :1;                                       /* Port ADL Interrupt Enable Bit 1 */
    byte PIE1AD2     :1;                                       /* Port ADL Interrupt Enable Bit 2 */
    byte PIE1AD3     :1;                                       /* Port ADL Interrupt Enable Bit 3 */
    byte PIE1AD4     :1;                                       /* Port ADL Interrupt Enable Bit 4 */
    byte PIE1AD5     :1;                                       /* Port ADL Interrupt Enable Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPIE1AD :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PIE1ADSTR;
extern volatile PIE1ADSTR _PIE1AD @(REG_BASE + 0x0000027DUL);
#define PIE1AD                          _PIE1AD.Byte
#define PIE1AD_PIE1AD0                  _PIE1AD.Bits.PIE1AD0
#define PIE1AD_PIE1AD1                  _PIE1AD.Bits.PIE1AD1
#define PIE1AD_PIE1AD2                  _PIE1AD.Bits.PIE1AD2
#define PIE1AD_PIE1AD3                  _PIE1AD.Bits.PIE1AD3
#define PIE1AD_PIE1AD4                  _PIE1AD.Bits.PIE1AD4
#define PIE1AD_PIE1AD5                  _PIE1AD.Bits.PIE1AD5
#define PIE1AD_PIE1AD                   _PIE1AD.MergedBits.grpPIE1AD

#define PIE1AD_PIE1AD0_MASK             1U
#define PIE1AD_PIE1AD1_MASK             2U
#define PIE1AD_PIE1AD2_MASK             4U
#define PIE1AD_PIE1AD3_MASK             8U
#define PIE1AD_PIE1AD4_MASK             16U
#define PIE1AD_PIE1AD5_MASK             32U
#define PIE1AD_PIE1AD_MASK              63U
#define PIE1AD_PIE1AD_BITNUM            0U


/*** PIF1AD - Port ADL Interrupt Flag Register; 0x0000027F ***/
typedef union {
  byte Byte;
  struct {
    byte PIF1AD0     :1;                                       /* Port ADL Bit 0 */
    byte PIF1AD1     :1;                                       /* Port ADL Bit 1 */
    byte PIF1AD2     :1;                                       /* Port ADL Bit 2 */
    byte PIF1AD3     :1;                                       /* Port ADL Bit 3 */
    byte PIF1AD4     :1;                                       /* Port ADL Bit 4 */
    byte PIF1AD5     :1;                                       /* Port ADL Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPIF1AD :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PIF1ADSTR;
extern volatile PIF1ADSTR _PIF1AD @(REG_BASE + 0x0000027FUL);
#define PIF1AD                          _PIF1AD.Byte
#define PIF1AD_PIF1AD0                  _PIF1AD.Bits.PIF1AD0
#define PIF1AD_PIF1AD1                  _PIF1AD.Bits.PIF1AD1
#define PIF1AD_PIF1AD2                  _PIF1AD.Bits.PIF1AD2
#define PIF1AD_PIF1AD3                  _PIF1AD.Bits.PIF1AD3
#define PIF1AD_PIF1AD4                  _PIF1AD.Bits.PIF1AD4
#define PIF1AD_PIF1AD5                  _PIF1AD.Bits.PIF1AD5
#define PIF1AD_PIF1AD                   _PIF1AD.MergedBits.grpPIF1AD

#define PIF1AD_PIF1AD0_MASK             1U
#define PIF1AD_PIF1AD1_MASK             2U
#define PIF1AD_PIF1AD2_MASK             4U
#define PIF1AD_PIF1AD3_MASK             8U
#define PIF1AD_PIF1AD4_MASK             16U
#define PIF1AD_PIF1AD5_MASK             32U
#define PIF1AD_PIF1AD_MASK              63U
#define PIF1AD_PIF1AD_BITNUM            0U


/*** CPMUHTCTL - High Temperature Control Register; 0x000002F0 ***/
typedef union {
  byte Byte;
  struct {
    byte HTIF        :1;                                       /* High Temperature Interrupt Flag */
    byte HTIE        :1;                                       /* High Temperature Interrupt Enable Bit */
    byte HTDS        :1;                                       /* High Temperature Detect Status Bi */
    byte HTE         :1;                                       /* High Temperature Enable Bit */
    byte             :1; 
    byte VSEL        :1;                                       /* Voltage Access Select Bit */
    byte             :1; 
    byte             :1; 
  } Bits;
} CPMUHTCTLSTR;
extern volatile CPMUHTCTLSTR _CPMUHTCTL @(REG_BASE + 0x000002F0UL);
#define CPMUHTCTL                       _CPMUHTCTL.Byte
#define CPMUHTCTL_HTIF                  _CPMUHTCTL.Bits.HTIF
#define CPMUHTCTL_HTIE                  _CPMUHTCTL.Bits.HTIE
#define CPMUHTCTL_HTDS                  _CPMUHTCTL.Bits.HTDS
#define CPMUHTCTL_HTE                   _CPMUHTCTL.Bits.HTE
#define CPMUHTCTL_VSEL                  _CPMUHTCTL.Bits.VSEL

#define CPMUHTCTL_HTIF_MASK             1U
#define CPMUHTCTL_HTIE_MASK             2U
#define CPMUHTCTL_HTDS_MASK             4U
#define CPMUHTCTL_HTE_MASK              8U
#define CPMUHTCTL_VSEL_MASK             32U


/*** CPMULVCTL - Low Voltage Control Register; 0x000002F1 ***/
typedef union {
  byte Byte;
  struct {
    byte LVIF        :1;                                       /* Low-Voltage Interrupt Flag */
    byte LVIE        :1;                                       /* Low-Voltage Interrupt Enable Bit */
    byte LVDS        :1;                                       /* Low-Voltage Detect Status Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} CPMULVCTLSTR;
extern volatile CPMULVCTLSTR _CPMULVCTL @(REG_BASE + 0x000002F1UL);
#define CPMULVCTL                       _CPMULVCTL.Byte
#define CPMULVCTL_LVIF                  _CPMULVCTL.Bits.LVIF
#define CPMULVCTL_LVIE                  _CPMULVCTL.Bits.LVIE
#define CPMULVCTL_LVDS                  _CPMULVCTL.Bits.LVDS

#define CPMULVCTL_LVIF_MASK             1U
#define CPMULVCTL_LVIE_MASK             2U
#define CPMULVCTL_LVDS_MASK             4U


/*** CPMUAPICTL - Autonomous Periodical Interrupt Control Register; 0x000002F2 ***/
typedef union {
  byte Byte;
  struct {
    byte APIF        :1;                                       /* Autonomous Periodical Interrupt Flag */
    byte APIE        :1;                                       /* Autonomous Periodical Interrupt Enable Bit */
    byte APIFE       :1;                                       /* Autonomous Periodical Interrupt Feature Enable Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte APICLK      :1;                                       /* Autonomous Periodical Interrupt Clock Select Bit */
  } Bits;
} CPMUAPICTLSTR;
extern volatile CPMUAPICTLSTR _CPMUAPICTL @(REG_BASE + 0x000002F2UL);
#define CPMUAPICTL                      _CPMUAPICTL.Byte
#define CPMUAPICTL_APIF                 _CPMUAPICTL.Bits.APIF
#define CPMUAPICTL_APIE                 _CPMUAPICTL.Bits.APIE
#define CPMUAPICTL_APIFE                _CPMUAPICTL.Bits.APIFE
#define CPMUAPICTL_APICLK               _CPMUAPICTL.Bits.APICLK

#define CPMUAPICTL_APIF_MASK            1U
#define CPMUAPICTL_APIE_MASK            2U
#define CPMUAPICTL_APIFE_MASK           4U
#define CPMUAPICTL_APICLK_MASK          128U


/*** CPMUACLKTR - Autonomous Clock Trimming Register; 0x000002F3 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ACLKTR0     :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 0 */
    byte ACLKTR1     :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 1 */
    byte ACLKTR2     :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 2 */
    byte ACLKTR3     :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 3 */
    byte ACLKTR4     :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 4 */
    byte ACLKTR5     :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 5 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpACLKTR :6;
  } MergedBits;
} CPMUACLKTRSTR;
extern volatile CPMUACLKTRSTR _CPMUACLKTR @(REG_BASE + 0x000002F3UL);
#define CPMUACLKTR                      _CPMUACLKTR.Byte
#define CPMUACLKTR_ACLKTR0              _CPMUACLKTR.Bits.ACLKTR0
#define CPMUACLKTR_ACLKTR1              _CPMUACLKTR.Bits.ACLKTR1
#define CPMUACLKTR_ACLKTR2              _CPMUACLKTR.Bits.ACLKTR2
#define CPMUACLKTR_ACLKTR3              _CPMUACLKTR.Bits.ACLKTR3
#define CPMUACLKTR_ACLKTR4              _CPMUACLKTR.Bits.ACLKTR4
#define CPMUACLKTR_ACLKTR5              _CPMUACLKTR.Bits.ACLKTR5
#define CPMUACLKTR_ACLKTR               _CPMUACLKTR.MergedBits.grpACLKTR

#define CPMUACLKTR_ACLKTR0_MASK         4U
#define CPMUACLKTR_ACLKTR1_MASK         8U
#define CPMUACLKTR_ACLKTR2_MASK         16U
#define CPMUACLKTR_ACLKTR3_MASK         32U
#define CPMUACLKTR_ACLKTR4_MASK         64U
#define CPMUACLKTR_ACLKTR5_MASK         128U
#define CPMUACLKTR_ACLKTR_MASK          252U
#define CPMUACLKTR_ACLKTR_BITNUM        2U


/*** CPMUAPIR - Autonomous Periodical Interrupt Rate Register; 0x000002F4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CPMUAPIRH - Autonomous Periodical Interrupt Rate Register High; 0x000002F4 ***/
    union {
      byte Byte;
      struct {
        byte APIR8       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 8 */
        byte APIR9       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 9 */
        byte APIR10      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 10 */
        byte APIR11      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 11 */
        byte APIR12      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 12 */
        byte APIR13      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 13 */
        byte APIR14      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 14 */
        byte APIR15      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 15 */
      } Bits;
    } CPMUAPIRHSTR;
    #define CPMUAPIRH                   _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Byte
    #define CPMUAPIRH_APIR8             _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR8
    #define CPMUAPIRH_APIR9             _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR9
    #define CPMUAPIRH_APIR10            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR10
    #define CPMUAPIRH_APIR11            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR11
    #define CPMUAPIRH_APIR12            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR12
    #define CPMUAPIRH_APIR13            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR13
    #define CPMUAPIRH_APIR14            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR14
    #define CPMUAPIRH_APIR15            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR15
    
    #define CPMUAPIRH_APIR8_MASK        1U
    #define CPMUAPIRH_APIR9_MASK        2U
    #define CPMUAPIRH_APIR10_MASK       4U
    #define CPMUAPIRH_APIR11_MASK       8U
    #define CPMUAPIRH_APIR12_MASK       16U
    #define CPMUAPIRH_APIR13_MASK       32U
    #define CPMUAPIRH_APIR14_MASK       64U
    #define CPMUAPIRH_APIR15_MASK       128U
    

    /*** CPMUAPIRL - Autonomous Periodical Interrupt Rate Register Low; 0x000002F5 ***/
    union {
      byte Byte;
      struct {
        byte APIR0       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 0 */
        byte APIR1       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 1 */
        byte APIR2       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 2 */
        byte APIR3       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 3 */
        byte APIR4       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 4 */
        byte APIR5       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 5 */
        byte APIR6       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 6 */
        byte APIR7       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 7 */
      } Bits;
    } CPMUAPIRLSTR;
    #define CPMUAPIRL                   _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Byte
    #define CPMUAPIRL_APIR0             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR0
    #define CPMUAPIRL_APIR1             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR1
    #define CPMUAPIRL_APIR2             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR2
    #define CPMUAPIRL_APIR3             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR3
    #define CPMUAPIRL_APIR4             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR4
    #define CPMUAPIRL_APIR5             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR5
    #define CPMUAPIRL_APIR6             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR6
    #define CPMUAPIRL_APIR7             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR7
    
    #define CPMUAPIRL_APIR0_MASK        1U
    #define CPMUAPIRL_APIR1_MASK        2U
    #define CPMUAPIRL_APIR2_MASK        4U
    #define CPMUAPIRL_APIR3_MASK        8U
    #define CPMUAPIRL_APIR4_MASK        16U
    #define CPMUAPIRL_APIR5_MASK        32U
    #define CPMUAPIRL_APIR6_MASK        64U
    #define CPMUAPIRL_APIR7_MASK        128U
    
  } Overlap_STR;

  struct {
    word APIR0       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 0 */
    word APIR1       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 1 */
    word APIR2       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 2 */
    word APIR3       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 3 */
    word APIR4       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 4 */
    word APIR5       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 5 */
    word APIR6       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 6 */
    word APIR7       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 7 */
    word APIR8       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 8 */
    word APIR9       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 9 */
    word APIR10      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 10 */
    word APIR11      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 11 */
    word APIR12      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 12 */
    word APIR13      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 13 */
    word APIR14      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 14 */
    word APIR15      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 15 */
  } Bits;
} CPMUAPIRSTR;
extern volatile CPMUAPIRSTR _CPMUAPIR @(REG_BASE + 0x000002F4UL);
#define CPMUAPIR                        _CPMUAPIR.Word
#define CPMUAPIR_APIR0                  _CPMUAPIR.Bits.APIR0
#define CPMUAPIR_APIR1                  _CPMUAPIR.Bits.APIR1
#define CPMUAPIR_APIR2                  _CPMUAPIR.Bits.APIR2
#define CPMUAPIR_APIR3                  _CPMUAPIR.Bits.APIR3
#define CPMUAPIR_APIR4                  _CPMUAPIR.Bits.APIR4
#define CPMUAPIR_APIR5                  _CPMUAPIR.Bits.APIR5
#define CPMUAPIR_APIR6                  _CPMUAPIR.Bits.APIR6
#define CPMUAPIR_APIR7                  _CPMUAPIR.Bits.APIR7
#define CPMUAPIR_APIR8                  _CPMUAPIR.Bits.APIR8
#define CPMUAPIR_APIR9                  _CPMUAPIR.Bits.APIR9
#define CPMUAPIR_APIR10                 _CPMUAPIR.Bits.APIR10
#define CPMUAPIR_APIR11                 _CPMUAPIR.Bits.APIR11
#define CPMUAPIR_APIR12                 _CPMUAPIR.Bits.APIR12
#define CPMUAPIR_APIR13                 _CPMUAPIR.Bits.APIR13
#define CPMUAPIR_APIR14                 _CPMUAPIR.Bits.APIR14
#define CPMUAPIR_APIR15                 _CPMUAPIR.Bits.APIR15

#define CPMUAPIR_APIR0_MASK             1U
#define CPMUAPIR_APIR1_MASK             2U
#define CPMUAPIR_APIR2_MASK             4U
#define CPMUAPIR_APIR3_MASK             8U
#define CPMUAPIR_APIR4_MASK             16U
#define CPMUAPIR_APIR5_MASK             32U
#define CPMUAPIR_APIR6_MASK             64U
#define CPMUAPIR_APIR7_MASK             128U
#define CPMUAPIR_APIR8_MASK             256U
#define CPMUAPIR_APIR9_MASK             512U
#define CPMUAPIR_APIR10_MASK            1024U
#define CPMUAPIR_APIR11_MASK            2048U
#define CPMUAPIR_APIR12_MASK            4096U
#define CPMUAPIR_APIR13_MASK            8192U
#define CPMUAPIR_APIR14_MASK            16384U
#define CPMUAPIR_APIR15_MASK            32768U


/*** CPMUHTTR - High Temperature Trimming Register; 0x000002F7 ***/
typedef union {
  byte Byte;
  struct {
    byte HTTR0       :1;                                       /* High Temperature Trimming Bits, bit 0 */
    byte HTTR1       :1;                                       /* High Temperature Trimming Bits, bit 1 */
    byte HTTR2       :1;                                       /* High Temperature Trimming Bits, bit 2 */
    byte HTTR3       :1;                                       /* High Temperature Trimming Bits, bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte HTOE        :1;                                       /* High Temperature Offeset Enable Bit */
  } Bits;
  struct {
    byte grpHTTR :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CPMUHTTRSTR;
extern volatile CPMUHTTRSTR _CPMUHTTR @(REG_BASE + 0x000002F7UL);
#define CPMUHTTR                        _CPMUHTTR.Byte
#define CPMUHTTR_HTTR0                  _CPMUHTTR.Bits.HTTR0
#define CPMUHTTR_HTTR1                  _CPMUHTTR.Bits.HTTR1
#define CPMUHTTR_HTTR2                  _CPMUHTTR.Bits.HTTR2
#define CPMUHTTR_HTTR3                  _CPMUHTTR.Bits.HTTR3
#define CPMUHTTR_HTOE                   _CPMUHTTR.Bits.HTOE
#define CPMUHTTR_HTTR                   _CPMUHTTR.MergedBits.grpHTTR

#define CPMUHTTR_HTTR0_MASK             1U
#define CPMUHTTR_HTTR1_MASK             2U
#define CPMUHTTR_HTTR2_MASK             4U
#define CPMUHTTR_HTTR3_MASK             8U
#define CPMUHTTR_HTOE_MASK              128U
#define CPMUHTTR_HTTR_MASK              15U
#define CPMUHTTR_HTTR_BITNUM            0U


/*** CPMUIRCTRIM - S12CPMU IRC1M Trim Registers; 0x000002F8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CPMUIRCTRIMH - S12CPMU IRC1M Trim Registers High; 0x000002F8 ***/
    union {
      byte Byte;
      struct {
        byte IRCTRIM8    :1;                                       /* IRC1M Frequency Trim Bit 8 */
        byte IRCTRIM9    :1;                                       /* IRC1M Frequency Trim Bit 9 */
        byte             :1; 
        byte TCTRIM0     :1;                                       /* IRC1M temperature coeficient Trim Bit 0 */
        byte TCTRIM1     :1;                                       /* IRC1M temperature coeficient Trim Bit 1 */
        byte TCTRIM2     :1;                                       /* IRC1M temperature coeficient Trim Bit 2 */
        byte TCTRIM3     :1;                                       /* IRC1M temperature coeficient Trim Bit 3 */
        byte TCTRIM4     :1;                                       /* IRC1M temperature coeficient Trim Bit 4 */
      } Bits;
      struct {
        byte grpIRCTRIM_8 :2;
        byte     :1;
        byte grpTCTRIM :5;
      } MergedBits;
    } CPMUIRCTRIMHSTR;
    #define CPMUIRCTRIMH                _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Byte
    #define CPMUIRCTRIMH_IRCTRIM8       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.IRCTRIM8
    #define CPMUIRCTRIMH_IRCTRIM9       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.IRCTRIM9
    #define CPMUIRCTRIMH_TCTRIM0        _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.TCTRIM0
    #define CPMUIRCTRIMH_TCTRIM1        _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.TCTRIM1
    #define CPMUIRCTRIMH_TCTRIM2        _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.TCTRIM2
    #define CPMUIRCTRIMH_TCTRIM3        _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.TCTRIM3
    #define CPMUIRCTRIMH_TCTRIM4        _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.TCTRIM4
    #define CPMUIRCTRIMH_IRCTRIM_8      _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.MergedBits.grpIRCTRIM_8
    #define CPMUIRCTRIMH_TCTRIM         _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.MergedBits.grpTCTRIM
    #define CPMUIRCTRIMH_IRCTRIM        CPMUIRCTRIMH_IRCTRIM_8
    
    #define CPMUIRCTRIMH_IRCTRIM8_MASK  1U
    #define CPMUIRCTRIMH_IRCTRIM9_MASK  2U
    #define CPMUIRCTRIMH_TCTRIM0_MASK   8U
    #define CPMUIRCTRIMH_TCTRIM1_MASK   16U
    #define CPMUIRCTRIMH_TCTRIM2_MASK   32U
    #define CPMUIRCTRIMH_TCTRIM3_MASK   64U
    #define CPMUIRCTRIMH_TCTRIM4_MASK   128U
    #define CPMUIRCTRIMH_IRCTRIM_8_MASK 3U
    #define CPMUIRCTRIMH_IRCTRIM_8_BITNUM 0U
    #define CPMUIRCTRIMH_TCTRIM_MASK    248U
    #define CPMUIRCTRIMH_TCTRIM_BITNUM  3U
    

    /*** CPMUIRCTRIML - S12CPMU IRC1M Trim Registers Low; 0x000002F9 ***/
    union {
      byte Byte;
      struct {
        byte IRCTRIM0    :1;                                       /* IRC1M Frequency Trim Bit 0 */
        byte IRCTRIM1    :1;                                       /* IRC1M Frequency Trim Bit 1 */
        byte IRCTRIM2    :1;                                       /* IRC1M Frequency Trim Bit 2 */
        byte IRCTRIM3    :1;                                       /* IRC1M Frequency Trim Bit 3 */
        byte IRCTRIM4    :1;                                       /* IRC1M Frequency Trim Bit 4 */
        byte IRCTRIM5    :1;                                       /* IRC1M Frequency Trim Bit 5 */
        byte IRCTRIM6    :1;                                       /* IRC1M Frequency Trim Bit 6 */
        byte IRCTRIM7    :1;                                       /* IRC1M Frequency Trim Bit 7 */
      } Bits;
    } CPMUIRCTRIMLSTR;
    #define CPMUIRCTRIML                _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Byte
    #define CPMUIRCTRIML_IRCTRIM0       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM0
    #define CPMUIRCTRIML_IRCTRIM1       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM1
    #define CPMUIRCTRIML_IRCTRIM2       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM2
    #define CPMUIRCTRIML_IRCTRIM3       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM3
    #define CPMUIRCTRIML_IRCTRIM4       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM4
    #define CPMUIRCTRIML_IRCTRIM5       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM5
    #define CPMUIRCTRIML_IRCTRIM6       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM6
    #define CPMUIRCTRIML_IRCTRIM7       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM7
    
    #define CPMUIRCTRIML_IRCTRIM0_MASK  1U
    #define CPMUIRCTRIML_IRCTRIM1_MASK  2U
    #define CPMUIRCTRIML_IRCTRIM2_MASK  4U
    #define CPMUIRCTRIML_IRCTRIM3_MASK  8U
    #define CPMUIRCTRIML_IRCTRIM4_MASK  16U
    #define CPMUIRCTRIML_IRCTRIM5_MASK  32U
    #define CPMUIRCTRIML_IRCTRIM6_MASK  64U
    #define CPMUIRCTRIML_IRCTRIM7_MASK  128U
    
  } Overlap_STR;

  struct {
    word IRCTRIM0    :1;                                       /* IRC1M Frequency Trim Bit 0 */
    word IRCTRIM1    :1;                                       /* IRC1M Frequency Trim Bit 1 */
    word IRCTRIM2    :1;                                       /* IRC1M Frequency Trim Bit 2 */
    word IRCTRIM3    :1;                                       /* IRC1M Frequency Trim Bit 3 */
    word IRCTRIM4    :1;                                       /* IRC1M Frequency Trim Bit 4 */
    word IRCTRIM5    :1;                                       /* IRC1M Frequency Trim Bit 5 */
    word IRCTRIM6    :1;                                       /* IRC1M Frequency Trim Bit 6 */
    word IRCTRIM7    :1;                                       /* IRC1M Frequency Trim Bit 7 */
    word IRCTRIM8    :1;                                       /* IRC1M Frequency Trim Bit 8 */
    word IRCTRIM9    :1;                                       /* IRC1M Frequency Trim Bit 9 */
    word             :1; 
    word TCTRIM0     :1;                                       /* IRC1M temperature coeficient Trim Bit 0 */
    word TCTRIM1     :1;                                       /* IRC1M temperature coeficient Trim Bit 1 */
    word TCTRIM2     :1;                                       /* IRC1M temperature coeficient Trim Bit 2 */
    word TCTRIM3     :1;                                       /* IRC1M temperature coeficient Trim Bit 3 */
    word TCTRIM4     :1;                                       /* IRC1M temperature coeficient Trim Bit 4 */
  } Bits;
  struct {
    word grpIRCTRIM :10;
    word         :1;
    word grpTCTRIM :5;
  } MergedBits;
} CPMUIRCTRIMSTR;
extern volatile CPMUIRCTRIMSTR _CPMUIRCTRIM @(REG_BASE + 0x000002F8UL);
#define CPMUIRCTRIM                     _CPMUIRCTRIM.Word
#define CPMUIRCTRIM_IRCTRIM0            _CPMUIRCTRIM.Bits.IRCTRIM0
#define CPMUIRCTRIM_IRCTRIM1            _CPMUIRCTRIM.Bits.IRCTRIM1
#define CPMUIRCTRIM_IRCTRIM2            _CPMUIRCTRIM.Bits.IRCTRIM2
#define CPMUIRCTRIM_IRCTRIM3            _CPMUIRCTRIM.Bits.IRCTRIM3
#define CPMUIRCTRIM_IRCTRIM4            _CPMUIRCTRIM.Bits.IRCTRIM4
#define CPMUIRCTRIM_IRCTRIM5            _CPMUIRCTRIM.Bits.IRCTRIM5
#define CPMUIRCTRIM_IRCTRIM6            _CPMUIRCTRIM.Bits.IRCTRIM6
#define CPMUIRCTRIM_IRCTRIM7            _CPMUIRCTRIM.Bits.IRCTRIM7
#define CPMUIRCTRIM_IRCTRIM8            _CPMUIRCTRIM.Bits.IRCTRIM8
#define CPMUIRCTRIM_IRCTRIM9            _CPMUIRCTRIM.Bits.IRCTRIM9
#define CPMUIRCTRIM_TCTRIM0             _CPMUIRCTRIM.Bits.TCTRIM0
#define CPMUIRCTRIM_TCTRIM1             _CPMUIRCTRIM.Bits.TCTRIM1
#define CPMUIRCTRIM_TCTRIM2             _CPMUIRCTRIM.Bits.TCTRIM2
#define CPMUIRCTRIM_TCTRIM3             _CPMUIRCTRIM.Bits.TCTRIM3
#define CPMUIRCTRIM_TCTRIM4             _CPMUIRCTRIM.Bits.TCTRIM4
#define CPMUIRCTRIM_IRCTRIM             _CPMUIRCTRIM.MergedBits.grpIRCTRIM
#define CPMUIRCTRIM_TCTRIM              _CPMUIRCTRIM.MergedBits.grpTCTRIM

#define CPMUIRCTRIM_IRCTRIM0_MASK       1U
#define CPMUIRCTRIM_IRCTRIM1_MASK       2U
#define CPMUIRCTRIM_IRCTRIM2_MASK       4U
#define CPMUIRCTRIM_IRCTRIM3_MASK       8U
#define CPMUIRCTRIM_IRCTRIM4_MASK       16U
#define CPMUIRCTRIM_IRCTRIM5_MASK       32U
#define CPMUIRCTRIM_IRCTRIM6_MASK       64U
#define CPMUIRCTRIM_IRCTRIM7_MASK       128U
#define CPMUIRCTRIM_IRCTRIM8_MASK       256U
#define CPMUIRCTRIM_IRCTRIM9_MASK       512U
#define CPMUIRCTRIM_TCTRIM0_MASK        2048U
#define CPMUIRCTRIM_TCTRIM1_MASK        4096U
#define CPMUIRCTRIM_TCTRIM2_MASK        8192U
#define CPMUIRCTRIM_TCTRIM3_MASK        16384U
#define CPMUIRCTRIM_TCTRIM4_MASK        32768U
#define CPMUIRCTRIM_IRCTRIM_MASK        1023U
#define CPMUIRCTRIM_IRCTRIM_BITNUM      0U
#define CPMUIRCTRIM_TCTRIM_MASK         63488U
#define CPMUIRCTRIM_TCTRIM_BITNUM       11U


/*** CPMUOSC - S12CPMU Oscillator Register; 0x000002FA ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte OSCE        :1;                                       /* Oscillator Enable Bit */
  } Bits;
} CPMUOSCSTR;
extern volatile CPMUOSCSTR _CPMUOSC @(REG_BASE + 0x000002FAUL);
#define CPMUOSC                         _CPMUOSC.Byte
#define CPMUOSC_OSCE                    _CPMUOSC.Bits.OSCE

#define CPMUOSC_OSCE_MASK               128U


/*** CPMUPROT - S12CPMUV1 Protection Register; 0x000002FB ***/
typedef union {
  byte Byte;
  struct {
    byte PROT        :1;                                       /* Clock Configuration Registers Protection Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} CPMUPROTSTR;
extern volatile CPMUPROTSTR _CPMUPROT @(REG_BASE + 0x000002FBUL);
#define CPMUPROT                        _CPMUPROT.Byte
#define CPMUPROT_PROT                   _CPMUPROT.Bits.PROT

#define CPMUPROT_PROT_MASK              1U


/*** BAKEY0 - Backdoor Comparison Key 0; 0x0000FF00 ***/
typedef union {
  word Word;
  struct {
    word KEY0        :1;                                       /* Backdoor Comparison Key Bits, bit 0 */
    word KEY1        :1;                                       /* Backdoor Comparison Key Bits, bit 1 */
    word KEY2        :1;                                       /* Backdoor Comparison Key Bits, bit 2 */
    word KEY3        :1;                                       /* Backdoor Comparison Key Bits, bit 3 */
    word KEY4        :1;                                       /* Backdoor Comparison Key Bits, bit 4 */
    word KEY5        :1;                                       /* Backdoor Comparison Key Bits, bit 5 */
    word KEY6        :1;                                       /* Backdoor Comparison Key Bits, bit 6 */
    word KEY7        :1;                                       /* Backdoor Comparison Key Bits, bit 7 */
    word KEY8        :1;                                       /* Backdoor Comparison Key Bits, bit 8 */
    word KEY9        :1;                                       /* Backdoor Comparison Key Bits, bit 9 */
    word KEY10       :1;                                       /* Backdoor Comparison Key Bits, bit 10 */
    word KEY11       :1;                                       /* Backdoor Comparison Key Bits, bit 11 */
    word KEY12       :1;                                       /* Backdoor Comparison Key Bits, bit 12 */
    word KEY13       :1;                                       /* Backdoor Comparison Key Bits, bit 13 */
    word KEY14       :1;                                       /* Backdoor Comparison Key Bits, bit 14 */
    word KEY15       :1;                                       /* Backdoor Comparison Key Bits, bit 15 */
  } Bits;
} BAKEY0STR;
/* Tip for register initialization in the user code:  const word BAKEY0_INIT @0x0000FF00 = <BAKEY0_INITVAL>; */
#define _BAKEY0 (*(const BAKEY0STR *)0x0000FF00)
#define BAKEY0                          _BAKEY0.Word
#define BAKEY0_KEY0                     _BAKEY0.Bits.KEY0
#define BAKEY0_KEY1                     _BAKEY0.Bits.KEY1
#define BAKEY0_KEY2                     _BAKEY0.Bits.KEY2
#define BAKEY0_KEY3                     _BAKEY0.Bits.KEY3
#define BAKEY0_KEY4                     _BAKEY0.Bits.KEY4
#define BAKEY0_KEY5                     _BAKEY0.Bits.KEY5
#define BAKEY0_KEY6                     _BAKEY0.Bits.KEY6
#define BAKEY0_KEY7                     _BAKEY0.Bits.KEY7
#define BAKEY0_KEY8                     _BAKEY0.Bits.KEY8
#define BAKEY0_KEY9                     _BAKEY0.Bits.KEY9
#define BAKEY0_KEY10                    _BAKEY0.Bits.KEY10
#define BAKEY0_KEY11                    _BAKEY0.Bits.KEY11
#define BAKEY0_KEY12                    _BAKEY0.Bits.KEY12
#define BAKEY0_KEY13                    _BAKEY0.Bits.KEY13
#define BAKEY0_KEY14                    _BAKEY0.Bits.KEY14
#define BAKEY0_KEY15                    _BAKEY0.Bits.KEY15
/* BAKEY_ARR: Access 4 BAKEYx registers in an array */
#define BAKEY_ARR                       ((volatile word *) &BAKEY0)

#define BAKEY0_KEY0_MASK                1U
#define BAKEY0_KEY1_MASK                2U
#define BAKEY0_KEY2_MASK                4U
#define BAKEY0_KEY3_MASK                8U
#define BAKEY0_KEY4_MASK                16U
#define BAKEY0_KEY5_MASK                32U
#define BAKEY0_KEY6_MASK                64U
#define BAKEY0_KEY7_MASK                128U
#define BAKEY0_KEY8_MASK                256U
#define BAKEY0_KEY9_MASK                512U
#define BAKEY0_KEY10_MASK               1024U
#define BAKEY0_KEY11_MASK               2048U
#define BAKEY0_KEY12_MASK               4096U
#define BAKEY0_KEY13_MASK               8192U
#define BAKEY0_KEY14_MASK               16384U
#define BAKEY0_KEY15_MASK               32768U


/*** BAKEY1 - Backdoor Comparison Key 1; 0x0000FF02 ***/
typedef union {
  word Word;
  struct {
    word KEY0        :1;                                       /* Backdoor Comparison Key Bits, bit 0 */
    word KEY1        :1;                                       /* Backdoor Comparison Key Bits, bit 1 */
    word KEY2        :1;                                       /* Backdoor Comparison Key Bits, bit 2 */
    word KEY3        :1;                                       /* Backdoor Comparison Key Bits, bit 3 */
    word KEY4        :1;                                       /* Backdoor Comparison Key Bits, bit 4 */
    word KEY5        :1;                                       /* Backdoor Comparison Key Bits, bit 5 */
    word KEY6        :1;                                       /* Backdoor Comparison Key Bits, bit 6 */
    word KEY7        :1;                                       /* Backdoor Comparison Key Bits, bit 7 */
    word KEY8        :1;                                       /* Backdoor Comparison Key Bits, bit 8 */
    word KEY9        :1;                                       /* Backdoor Comparison Key Bits, bit 9 */
    word KEY10       :1;                                       /* Backdoor Comparison Key Bits, bit 10 */
    word KEY11       :1;                                       /* Backdoor Comparison Key Bits, bit 11 */
    word KEY12       :1;                                       /* Backdoor Comparison Key Bits, bit 12 */
    word KEY13       :1;                                       /* Backdoor Comparison Key Bits, bit 13 */
    word KEY14       :1;                                       /* Backdoor Comparison Key Bits, bit 14 */
    word KEY15       :1;                                       /* Backdoor Comparison Key Bits, bit 15 */
  } Bits;
} BAKEY1STR;
/* Tip for register initialization in the user code:  const word BAKEY1_INIT @0x0000FF02 = <BAKEY1_INITVAL>; */
#define _BAKEY1 (*(const BAKEY1STR *)0x0000FF02)
#define BAKEY1                          _BAKEY1.Word
#define BAKEY1_KEY0                     _BAKEY1.Bits.KEY0
#define BAKEY1_KEY1                     _BAKEY1.Bits.KEY1
#define BAKEY1_KEY2                     _BAKEY1.Bits.KEY2
#define BAKEY1_KEY3                     _BAKEY1.Bits.KEY3
#define BAKEY1_KEY4                     _BAKEY1.Bits.KEY4
#define BAKEY1_KEY5                     _BAKEY1.Bits.KEY5
#define BAKEY1_KEY6                     _BAKEY1.Bits.KEY6
#define BAKEY1_KEY7                     _BAKEY1.Bits.KEY7
#define BAKEY1_KEY8                     _BAKEY1.Bits.KEY8
#define BAKEY1_KEY9                     _BAKEY1.Bits.KEY9
#define BAKEY1_KEY10                    _BAKEY1.Bits.KEY10
#define BAKEY1_KEY11                    _BAKEY1.Bits.KEY11
#define BAKEY1_KEY12                    _BAKEY1.Bits.KEY12
#define BAKEY1_KEY13                    _BAKEY1.Bits.KEY13
#define BAKEY1_KEY14                    _BAKEY1.Bits.KEY14
#define BAKEY1_KEY15                    _BAKEY1.Bits.KEY15

#define BAKEY1_KEY0_MASK                1U
#define BAKEY1_KEY1_MASK                2U
#define BAKEY1_KEY2_MASK                4U
#define BAKEY1_KEY3_MASK                8U
#define BAKEY1_KEY4_MASK                16U
#define BAKEY1_KEY5_MASK                32U
#define BAKEY1_KEY6_MASK                64U
#define BAKEY1_KEY7_MASK                128U
#define BAKEY1_KEY8_MASK                256U
#define BAKEY1_KEY9_MASK                512U
#define BAKEY1_KEY10_MASK               1024U
#define BAKEY1_KEY11_MASK               2048U
#define BAKEY1_KEY12_MASK               4096U
#define BAKEY1_KEY13_MASK               8192U
#define BAKEY1_KEY14_MASK               16384U
#define BAKEY1_KEY15_MASK               32768U


/*** BAKEY2 - Backdoor Comparison Key 2; 0x0000FF04 ***/
typedef union {
  word Word;
  struct {
    word KEY0        :1;                                       /* Backdoor Comparison Key Bits, bit 0 */
    word KEY1        :1;                                       /* Backdoor Comparison Key Bits, bit 1 */
    word KEY2        :1;                                       /* Backdoor Comparison Key Bits, bit 2 */
    word KEY3        :1;                                       /* Backdoor Comparison Key Bits, bit 3 */
    word KEY4        :1;                                       /* Backdoor Comparison Key Bits, bit 4 */
    word KEY5        :1;                                       /* Backdoor Comparison Key Bits, bit 5 */
    word KEY6        :1;                                       /* Backdoor Comparison Key Bits, bit 6 */
    word KEY7        :1;                                       /* Backdoor Comparison Key Bits, bit 7 */
    word KEY8        :1;                                       /* Backdoor Comparison Key Bits, bit 8 */
    word KEY9        :1;                                       /* Backdoor Comparison Key Bits, bit 9 */
    word KEY10       :1;                                       /* Backdoor Comparison Key Bits, bit 10 */
    word KEY11       :1;                                       /* Backdoor Comparison Key Bits, bit 11 */
    word KEY12       :1;                                       /* Backdoor Comparison Key Bits, bit 12 */
    word KEY13       :1;                                       /* Backdoor Comparison Key Bits, bit 13 */
    word KEY14       :1;                                       /* Backdoor Comparison Key Bits, bit 14 */
    word KEY15       :1;                                       /* Backdoor Comparison Key Bits, bit 15 */
  } Bits;
} BAKEY2STR;
/* Tip for register initialization in the user code:  const word BAKEY2_INIT @0x0000FF04 = <BAKEY2_INITVAL>; */
#define _BAKEY2 (*(const BAKEY2STR *)0x0000FF04)
#define BAKEY2                          _BAKEY2.Word
#define BAKEY2_KEY0                     _BAKEY2.Bits.KEY0
#define BAKEY2_KEY1                     _BAKEY2.Bits.KEY1
#define BAKEY2_KEY2                     _BAKEY2.Bits.KEY2
#define BAKEY2_KEY3                     _BAKEY2.Bits.KEY3
#define BAKEY2_KEY4                     _BAKEY2.Bits.KEY4
#define BAKEY2_KEY5                     _BAKEY2.Bits.KEY5
#define BAKEY2_KEY6                     _BAKEY2.Bits.KEY6
#define BAKEY2_KEY7                     _BAKEY2.Bits.KEY7
#define BAKEY2_KEY8                     _BAKEY2.Bits.KEY8
#define BAKEY2_KEY9                     _BAKEY2.Bits.KEY9
#define BAKEY2_KEY10                    _BAKEY2.Bits.KEY10
#define BAKEY2_KEY11                    _BAKEY2.Bits.KEY11
#define BAKEY2_KEY12                    _BAKEY2.Bits.KEY12
#define BAKEY2_KEY13                    _BAKEY2.Bits.KEY13
#define BAKEY2_KEY14                    _BAKEY2.Bits.KEY14
#define BAKEY2_KEY15                    _BAKEY2.Bits.KEY15

#define BAKEY2_KEY0_MASK                1U
#define BAKEY2_KEY1_MASK                2U
#define BAKEY2_KEY2_MASK                4U
#define BAKEY2_KEY3_MASK                8U
#define BAKEY2_KEY4_MASK                16U
#define BAKEY2_KEY5_MASK                32U
#define BAKEY2_KEY6_MASK                64U
#define BAKEY2_KEY7_MASK                128U
#define BAKEY2_KEY8_MASK                256U
#define BAKEY2_KEY9_MASK                512U
#define BAKEY2_KEY10_MASK               1024U
#define BAKEY2_KEY11_MASK               2048U
#define BAKEY2_KEY12_MASK               4096U
#define BAKEY2_KEY13_MASK               8192U
#define BAKEY2_KEY14_MASK               16384U
#define BAKEY2_KEY15_MASK               32768U


/*** BAKEY3 - Backdoor Comparison Key 3; 0x0000FF06 ***/
typedef union {
  word Word;
  struct {
    word KEY0        :1;                                       /* Backdoor Comparison Key Bits, bit 0 */
    word KEY1        :1;                                       /* Backdoor Comparison Key Bits, bit 1 */
    word KEY2        :1;                                       /* Backdoor Comparison Key Bits, bit 2 */
    word KEY3        :1;                                       /* Backdoor Comparison Key Bits, bit 3 */
    word KEY4        :1;                                       /* Backdoor Comparison Key Bits, bit 4 */
    word KEY5        :1;                                       /* Backdoor Comparison Key Bits, bit 5 */
    word KEY6        :1;                                       /* Backdoor Comparison Key Bits, bit 6 */
    word KEY7        :1;                                       /* Backdoor Comparison Key Bits, bit 7 */
    word KEY8        :1;                                       /* Backdoor Comparison Key Bits, bit 8 */
    word KEY9        :1;                                       /* Backdoor Comparison Key Bits, bit 9 */
    word KEY10       :1;                                       /* Backdoor Comparison Key Bits, bit 10 */
    word KEY11       :1;                                       /* Backdoor Comparison Key Bits, bit 11 */
    word KEY12       :1;                                       /* Backdoor Comparison Key Bits, bit 12 */
    word KEY13       :1;                                       /* Backdoor Comparison Key Bits, bit 13 */
    word KEY14       :1;                                       /* Backdoor Comparison Key Bits, bit 14 */
    word KEY15       :1;                                       /* Backdoor Comparison Key Bits, bit 15 */
  } Bits;
} BAKEY3STR;
/* Tip for register initialization in the user code:  const word BAKEY3_INIT @0x0000FF06 = <BAKEY3_INITVAL>; */
#define _BAKEY3 (*(const BAKEY3STR *)0x0000FF06)
#define BAKEY3                          _BAKEY3.Word
#define BAKEY3_KEY0                     _BAKEY3.Bits.KEY0
#define BAKEY3_KEY1                     _BAKEY3.Bits.KEY1
#define BAKEY3_KEY2                     _BAKEY3.Bits.KEY2
#define BAKEY3_KEY3                     _BAKEY3.Bits.KEY3
#define BAKEY3_KEY4                     _BAKEY3.Bits.KEY4
#define BAKEY3_KEY5                     _BAKEY3.Bits.KEY5
#define BAKEY3_KEY6                     _BAKEY3.Bits.KEY6
#define BAKEY3_KEY7                     _BAKEY3.Bits.KEY7
#define BAKEY3_KEY8                     _BAKEY3.Bits.KEY8
#define BAKEY3_KEY9                     _BAKEY3.Bits.KEY9
#define BAKEY3_KEY10                    _BAKEY3.Bits.KEY10
#define BAKEY3_KEY11                    _BAKEY3.Bits.KEY11
#define BAKEY3_KEY12                    _BAKEY3.Bits.KEY12
#define BAKEY3_KEY13                    _BAKEY3.Bits.KEY13
#define BAKEY3_KEY14                    _BAKEY3.Bits.KEY14
#define BAKEY3_KEY15                    _BAKEY3.Bits.KEY15

#define BAKEY3_KEY0_MASK                1U
#define BAKEY3_KEY1_MASK                2U
#define BAKEY3_KEY2_MASK                4U
#define BAKEY3_KEY3_MASK                8U
#define BAKEY3_KEY4_MASK                16U
#define BAKEY3_KEY5_MASK                32U
#define BAKEY3_KEY6_MASK                64U
#define BAKEY3_KEY7_MASK                128U
#define BAKEY3_KEY8_MASK                256U
#define BAKEY3_KEY9_MASK                512U
#define BAKEY3_KEY10_MASK               1024U
#define BAKEY3_KEY11_MASK               2048U
#define BAKEY3_KEY12_MASK               4096U
#define BAKEY3_KEY13_MASK               8192U
#define BAKEY3_KEY14_MASK               16384U
#define BAKEY3_KEY15_MASK               32768U


/*** NVFPROT - Non Volatile P-Flash Protection Register; 0x0000FF0C ***/
typedef union {
  byte Byte;
  struct {
    byte FPLS0       :1;                                       /* Flash Protection Lower Address Size Bit 0 */
    byte FPLS1       :1;                                       /* Flash Protection Lower Address Size Bit 1 */
    byte FPLDIS      :1;                                       /* Flash Protection Lower Address Range Disable */
    byte FPHS0       :1;                                       /* Flash Protection Higher Address Size Bit 0 */
    byte FPHS1       :1;                                       /* Flash Protection Higher Address Size Bit 1 */
    byte FPHDIS      :1;                                       /* Flash Protection Higher Address Range Disable */
    byte RNV6        :1;                                       /* Reserved Nonvolatile Bit */
    byte FPOPEN      :1;                                       /* Flash Protection Operation Enable */
  } Bits;
  struct {
    byte grpFPLS :2;
    byte         :1;
    byte grpFPHS :2;
    byte         :1;
    byte grpRNV_6 :1;
    byte         :1;
  } MergedBits;
} NVFPROTSTR;
/* Tip for register initialization in the user code:  const byte NVFPROT_INIT @0x0000FF0C = <NVFPROT_INITVAL>; */
#define _NVFPROT (*(const NVFPROTSTR *)0x0000FF0C)
#define NVFPROT                         _NVFPROT.Byte
#define NVFPROT_FPLS0                   _NVFPROT.Bits.FPLS0
#define NVFPROT_FPLS1                   _NVFPROT.Bits.FPLS1
#define NVFPROT_FPLDIS                  _NVFPROT.Bits.FPLDIS
#define NVFPROT_FPHS0                   _NVFPROT.Bits.FPHS0
#define NVFPROT_FPHS1                   _NVFPROT.Bits.FPHS1
#define NVFPROT_FPHDIS                  _NVFPROT.Bits.FPHDIS
#define NVFPROT_RNV6                    _NVFPROT.Bits.RNV6
#define NVFPROT_FPOPEN                  _NVFPROT.Bits.FPOPEN
#define NVFPROT_FPLS                    _NVFPROT.MergedBits.grpFPLS
#define NVFPROT_FPHS                    _NVFPROT.MergedBits.grpFPHS

#define NVFPROT_FPLS0_MASK              1U
#define NVFPROT_FPLS1_MASK              2U
#define NVFPROT_FPLDIS_MASK             4U
#define NVFPROT_FPHS0_MASK              8U
#define NVFPROT_FPHS1_MASK              16U
#define NVFPROT_FPHDIS_MASK             32U
#define NVFPROT_RNV6_MASK               64U
#define NVFPROT_FPOPEN_MASK             128U
#define NVFPROT_FPLS_MASK               3U
#define NVFPROT_FPLS_BITNUM             0U
#define NVFPROT_FPHS_MASK               24U
#define NVFPROT_FPHS_BITNUM             3U


/*** NVDFPROT - Non Volatile D-Flash Protection Register; 0x0000FF0D ***/
typedef union {
  byte Byte;
  struct {
    byte DPS0        :1;                                       /* D-Flash Protection Size Bit 0 */
    byte DPS1        :1;                                       /* D-Flash Protection Size Bit 1 */
    byte DPS2        :1;                                       /* D-Flash Protection Size Bit 2 */
    byte DPS3        :1;                                       /* D-Flash Protection Size Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte DPOPEN      :1;                                       /* D-Flash Protection Control */
  } Bits;
  struct {
    byte grpDPS  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NVDFPROTSTR;
/* Tip for register initialization in the user code:  const byte NVDFPROT_INIT @0x0000FF0D = <NVDFPROT_INITVAL>; */
#define _NVDFPROT (*(const NVDFPROTSTR *)0x0000FF0D)
#define NVDFPROT                        _NVDFPROT.Byte
#define NVDFPROT_DPS0                   _NVDFPROT.Bits.DPS0
#define NVDFPROT_DPS1                   _NVDFPROT.Bits.DPS1
#define NVDFPROT_DPS2                   _NVDFPROT.Bits.DPS2
#define NVDFPROT_DPS3                   _NVDFPROT.Bits.DPS3
#define NVDFPROT_DPOPEN                 _NVDFPROT.Bits.DPOPEN
#define NVDFPROT_DPS                    _NVDFPROT.MergedBits.grpDPS

#define NVDFPROT_DPS0_MASK              1U
#define NVDFPROT_DPS1_MASK              2U
#define NVDFPROT_DPS2_MASK              4U
#define NVDFPROT_DPS3_MASK              8U
#define NVDFPROT_DPOPEN_MASK            128U
#define NVDFPROT_DPS_MASK               15U
#define NVDFPROT_DPS_BITNUM             0U


/*** NVFOPT - Non Volatile Flash Option Register; 0x0000FF0E ***/
typedef union {
  byte Byte;
  struct {
    byte NV0         :1;                                       /* Nonvolatile Bit 0 */
    byte NV1         :1;                                       /* Nonvolatile Bit 1 */
    byte NV2         :1;                                       /* Nonvolatile Bit 2 */
    byte NV3         :1;                                       /* Nonvolatile Bit 3 */
    byte NV4         :1;                                       /* Nonvolatile Bit 4 */
    byte NV5         :1;                                       /* Nonvolatile Bit 5 */
    byte NV6         :1;                                       /* Nonvolatile Bit 6 */
    byte NV7         :1;                                       /* Nonvolatile Bit 7 */
  } Bits;
} NVFOPTSTR;
/* Tip for register initialization in the user code:  const byte NVFOPT_INIT @0x0000FF0E = <NVFOPT_INITVAL>; */
#define _NVFOPT (*(const NVFOPTSTR *)0x0000FF0E)
#define NVFOPT                          _NVFOPT.Byte
#define NVFOPT_NV0                      _NVFOPT.Bits.NV0
#define NVFOPT_NV1                      _NVFOPT.Bits.NV1
#define NVFOPT_NV2                      _NVFOPT.Bits.NV2
#define NVFOPT_NV3                      _NVFOPT.Bits.NV3
#define NVFOPT_NV4                      _NVFOPT.Bits.NV4
#define NVFOPT_NV5                      _NVFOPT.Bits.NV5
#define NVFOPT_NV6                      _NVFOPT.Bits.NV6
#define NVFOPT_NV7                      _NVFOPT.Bits.NV7

#define NVFOPT_NV0_MASK                 1U
#define NVFOPT_NV1_MASK                 2U
#define NVFOPT_NV2_MASK                 4U
#define NVFOPT_NV3_MASK                 8U
#define NVFOPT_NV4_MASK                 16U
#define NVFOPT_NV5_MASK                 32U
#define NVFOPT_NV6_MASK                 64U
#define NVFOPT_NV7_MASK                 128U


/*** NVFSEC - Non Volatile Flash Security Register; 0x0000FF0F ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Flash Security Bit 0 */
    byte SEC1        :1;                                       /* Flash Security Bit 1 */
    byte RNV2        :1;                                       /* Reserved Nonvolatile Bit 2 */
    byte RNV3        :1;                                       /* Reserved Nonvolatile Bit 3 */
    byte RNV4        :1;                                       /* Reserved Nonvolatile Bit 4 */
    byte RNV5        :1;                                       /* Reserved Nonvolatile Bit 5 */
    byte KEYEN0      :1;                                       /* Backdoor Key Security Enable Bit 0 */
    byte KEYEN1      :1;                                       /* Backdoor Key Security Enable Bit 1 */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte grpRNV_2 :4;
    byte grpKEYEN :2;
  } MergedBits;
} NVFSECSTR;
/* Tip for register initialization in the user code:  const byte NVFSEC_INIT @0x0000FF0F = <NVFSEC_INITVAL>; */
#define _NVFSEC (*(const NVFSECSTR *)0x0000FF0F)
#define NVFSEC                          _NVFSEC.Byte
#define NVFSEC_SEC0                     _NVFSEC.Bits.SEC0
#define NVFSEC_SEC1                     _NVFSEC.Bits.SEC1
#define NVFSEC_RNV2                     _NVFSEC.Bits.RNV2
#define NVFSEC_RNV3                     _NVFSEC.Bits.RNV3
#define NVFSEC_RNV4                     _NVFSEC.Bits.RNV4
#define NVFSEC_RNV5                     _NVFSEC.Bits.RNV5
#define NVFSEC_KEYEN0                   _NVFSEC.Bits.KEYEN0
#define NVFSEC_KEYEN1                   _NVFSEC.Bits.KEYEN1
#define NVFSEC_SEC                      _NVFSEC.MergedBits.grpSEC
#define NVFSEC_RNV_2                    _NVFSEC.MergedBits.grpRNV_2
#define NVFSEC_KEYEN                    _NVFSEC.MergedBits.grpKEYEN
#define NVFSEC_RNV                      NVFSEC_RNV_2

#define NVFSEC_SEC0_MASK                1U
#define NVFSEC_SEC1_MASK                2U
#define NVFSEC_RNV2_MASK                4U
#define NVFSEC_RNV3_MASK                8U
#define NVFSEC_RNV4_MASK                16U
#define NVFSEC_RNV5_MASK                32U
#define NVFSEC_KEYEN0_MASK              64U
#define NVFSEC_KEYEN1_MASK              128U
#define NVFSEC_SEC_MASK                 3U
#define NVFSEC_SEC_BITNUM               0U
#define NVFSEC_RNV_2_MASK               60U
#define NVFSEC_RNV_2_BITNUM             2U
#define NVFSEC_KEYEN_MASK               192U
#define NVFSEC_KEYEN_BITNUM             6U


  /* Watchdog reset macro */
#ifndef __RESET_WATCHDOG
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() (void)(CPMUARMCOP = 0x55U, CPMUARMCOP = 0xAAU)
#endif
#endif /* __RESET_WATCHDOG */


/***********************************************/
/**   D E P R E C I A T E D   S Y M B O L S   **/
/***********************************************/
/* --------------------------------------------------------------------------- */
/* The following symbols were removed, because they were invalid or irrelevant */
/* --------------------------------------------------------------------------- */



/* **** 30.3.2011 10:50:14 */

#define HSSR_HS0OL                       HSSR_HSOL0
#define HSSR_HS1OL                       HSSR_HSOL1
#define HSSR_HS0OL_MASK                  HSSR_HSOL0_MASK
#define HSSR_HS1OL_MASK                  HSSR_HSOL1_MASK
#define HSIF_HS0OCIF                     HSIF_HSOCIF0
#define HSIF_HS1OCIF                     HSIF_HSOCIF1
#define HSIF_HS0OCIF_MASK                HSIF_HSOCIF0_MASK
#define HSIF_HS1OCIF_MASK                HSIF_HSOCIF1_MASK
#define LSSR_LS0OL                       LSSR_LSOL0
#define LSSR_LS1OL                       LSSR_LSOL1
#define LSSR_LS0OL_MASK                  LSSR_LSOL0_MASK
#define LSSR_LS1OL_MASK                  LSSR_LSOL1_MASK
#define LSIF_LS0OCIF                     LSIF_LSOCIF0
#define LSIF_LS1OCIF                     LSIF_LSOCIF1
#define LSIF_LS0OCIF_MASK                LSIF_LSOCIF0_MASK
#define LSIF_LS1OCIF_MASK                LSIF_LSOCIF1_MASK


/* **** 30.6.2011 15:35:18 */

#define PWME_PWME                        This_symb_has_been_depreciated
#define PWME_PWME_MASK                   This_symb_has_been_depreciated
#define PWME_PWME_BITNUM                 This_symb_has_been_depreciated
#define PWMPOL_PPOL                      This_symb_has_been_depreciated
#define PWMPOL_PPOL_MASK                 This_symb_has_been_depreciated
#define PWMPOL_PPOL_BITNUM               This_symb_has_been_depreciated
#define PWMCLK_PCLK                      This_symb_has_been_depreciated
#define PWMCLK_PCLK_MASK                 This_symb_has_been_depreciated
#define PWMCLK_PCLK_BITNUM               This_symb_has_been_depreciated
#define PWMCAE_CAE                       This_symb_has_been_depreciated
#define PWMCAE_CAE_MASK                  This_symb_has_been_depreciated
#define PWMCAE_CAE_BITNUM                This_symb_has_been_depreciated
#define PWMCLKAB_PCLKAB                  This_symb_has_been_depreciated
#define PWMCLKAB_PCLKAB_MASK             This_symb_has_been_depreciated
#define PWMCLKAB_PCLKAB_BITNUM           This_symb_has_been_depreciated
#define PTTRR0                           MODRR0
#define PTTRR0_PTTRR00                   MODRR0_MODRR00
#define PTTRR0_PTTRR01                   MODRR0_MODRR01
#define PTTRR0_PTTRR02                   MODRR0_MODRR02
#define PTTRR0_PTTRR03                   MODRR0_MODRR03
#define PTTRR0_PTTRR04                   MODRR0_MODRR04
#define PTTRR0_PTTRR05                   MODRR0_MODRR05
#define PTTRR0_PTTRR06                   MODRR0_MODRR06
#define PTTRR0_PTTRR07                   MODRR0_MODRR07
#define PTTRR_ARR                        MODRR_ARR
#define PTTRR0_PTTRR00_MASK              MODRR0_MODRR00_MASK
#define PTTRR0_PTTRR01_MASK              MODRR0_MODRR01_MASK
#define PTTRR0_PTTRR02_MASK              MODRR0_MODRR02_MASK
#define PTTRR0_PTTRR03_MASK              MODRR0_MODRR03_MASK
#define PTTRR0_PTTRR04_MASK              MODRR0_MODRR04_MASK
#define PTTRR0_PTTRR05_MASK              MODRR0_MODRR05_MASK
#define PTTRR0_PTTRR06_MASK              MODRR0_MODRR06_MASK
#define PTTRR0_PTTRR07_MASK              MODRR0_MODRR07_MASK
#define PTTRR1                           MODRR1
#define PTTRR1_PTTRR14                   MODRR1_MODRR14
#define PTTRR1_PTTRR15                   MODRR1_MODRR15
#define PTTRR1_PTTRR_14                  MODRR1_MODRR_14
#define PTTRR1_PTTRR                     MODRR1_MODRR
#define PTTRR1_PTTRR14_MASK              MODRR1_MODRR14_MASK
#define PTTRR1_PTTRR15_MASK              MODRR1_MODRR15_MASK
#define PTTRR1_PTTRR_14_MASK             MODRR1_MODRR_14_MASK
#define PTTRR1_PTTRR_14_BITNUM           MODRR1_MODRR_14_BITNUM
#define PTTRR                            MODRR
#define PTTRR_PTTRR00                    MODRR_MODRR00
#define PTTRR_PTTRR01                    MODRR_MODRR01
#define PTTRR_PTTRR02                    MODRR_MODRR02
#define PTTRR_PTTRR03                    MODRR_MODRR03
#define PTTRR_PTTRR04                    MODRR_MODRR04
#define PTTRR_PTTRR05                    MODRR_MODRR05
#define PTTRR_PTTRR06                    MODRR_MODRR06
#define PTTRR_PTTRR07                    MODRR_MODRR07
#define PTTRR_PTTRR14                    MODRR_MODRR14
#define PTTRR_PTTRR15                    MODRR_MODRR15
#define PTTRR_PTTRR0                     MODRR_MODRR0
#define PTTRR_PTTRR_14                   MODRR_MODRR_14
#define PTTRR_PTTRR00_MASK               MODRR_MODRR00_MASK
#define PTTRR_PTTRR01_MASK               MODRR_MODRR01_MASK
#define PTTRR_PTTRR02_MASK               MODRR_MODRR02_MASK
#define PTTRR_PTTRR03_MASK               MODRR_MODRR03_MASK
#define PTTRR_PTTRR04_MASK               MODRR_MODRR04_MASK
#define PTTRR_PTTRR05_MASK               MODRR_MODRR05_MASK
#define PTTRR_PTTRR06_MASK               MODRR_MODRR06_MASK
#define PTTRR_PTTRR07_MASK               MODRR_MODRR07_MASK
#define PTTRR_PTTRR14_MASK               MODRR_MODRR14_MASK
#define PTTRR_PTTRR15_MASK               MODRR_MODRR15_MASK
#define PTTRR_PTTRR0_MASK                MODRR_MODRR0_MASK
#define PTTRR_PTTRR0_BITNUM              MODRR_MODRR0_BITNUM
#define PTTRR_PTTRR_14_MASK              MODRR_MODRR_14_MASK
#define PTTRR_PTTRR_14_BITNUM            MODRR_MODRR_14_BITNUM


/* **** 11/8/2011 1:07:46 PM */

#define PTSRR                            MODRR2
#define PTSRR_PTSRR0                     MODRR2_MODRR20
#define PTSRR_PTSRR1                     MODRR2_MODRR21
#define PTSRR_PTSRR2                     MODRR2_MODRR22
#define PTSRR_PTSRR3                     MODRR2_MODRR23
#define PTSRR_PTSRR4                     MODRR2_MODRR24
#define PTSRR_PTSRR5                     MODRR2_MODRR25
#define PTSRR_PTSRR7                     MODRR2_MODRR27
#define PTSRR_PTSRR                      MODRR2_MODRR_20
#define PTSRR_PTSRR0_MASK                MODRR2_MODRR20_MASK
#define PTSRR_PTSRR1_MASK                MODRR2_MODRR21_MASK
#define PTSRR_PTSRR2_MASK                MODRR2_MODRR22_MASK
#define PTSRR_PTSRR3_MASK                MODRR2_MODRR23_MASK
#define PTSRR_PTSRR4_MASK                MODRR2_MODRR24_MASK
#define PTSRR_PTSRR5_MASK                MODRR2_MODRR25_MASK
#define PTSRR_PTSRR7_MASK                MODRR2_MODRR27_MASK
#define PTSRR_PTSRR_MASK                 MODRR2_MODRR_20_MASK
#define PTSRR_PTSRR_BITNUM               MODRR2_MODRR_20_BITNUM


/* **** 20/12/2012  */

#define LPSLRSTR                        This_symb_has_been_depreciated
#define LPSLR_LPSLR                     This_symb_has_been_depreciated
#define LPSLR_LPSLRWD                   This_symb_has_been_depreciated
#define LPSLR_LPSLR_MASK                This_symb_has_been_depreciated
#define LPSLR_LPSLR_BITNUM              This_symb_has_been_depreciated
#define LPSLR_LPSLRWD_MASK              This_symb_has_been_depreciated
#define LPSR_LPOC                       This_symb_has_been_depreciated
#define LPSR_LPOC_MASK                  This_symb_has_been_depreciated

#ifndef __V30COMPATIBLE__
#pragma OPTION DEL V30toV31Compatible
#endif
/*lint -restore  +esym(960,18.4) +esym(961,19.7) Enable MISRA rule (1.1,18.4,6.4,19.7) checking. */
#endif
