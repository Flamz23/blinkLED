/* Based on CPU DB MC9S12GN32_48, version 3.00.002 (RegistersPrg V2.32) */
/*
** ###################################################################
**     Filename  : mc9s12gn16.h
**     Processor : MC9S12GN16CLF
**     FileFormat: V2.32
**     DataSheet : MC9S12GRMV1 Rev. 0.29 April 20, 2010
**     Compiler  : CodeWarrior compiler
**     Date/Time : 29.7.2010, 10:27
**     Abstract  :
**         This header implements the mapping of I/O devices.
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
**
**     CPU Registers Revisions:
**               - none
**
**     File-Format-Revisions:
**               - none
**
**     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
**     derivative device. To avoid extra current drain from floating input pins, the user�s reset
**     initialization routine in the application program must either enable on-chip pull-up devices
**     or change the direction of unconnected pins to outputs so the pins do not float.
** ###################################################################
*/

#ifndef _MC9S12GN16_H
#define _MC9S12GN16_H

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
#define VectorNumber_VReserved60        60U
#define VectorNumber_Vapi               59U
#define VectorNumber_Vlvi               58U
#define VectorNumber_VReserved57        57U
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
#define VectorNumber_VReserved43        43U
#define VectorNumber_VReserved42        42U
#define VectorNumber_VReserved41        41U
#define VectorNumber_VReserved40        40U
#define VectorNumber_VReserved39        39U
#define VectorNumber_VReserved38        38U
#define VectorNumber_VReserved37        37U
#define VectorNumber_VReserved36        36U
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
#define VectorNumber_Vacmp              25U
#define VectorNumber_Vportj             24U
#define VectorNumber_VReserved23        23U
#define VectorNumber_Vatd               22U
#define VectorNumber_VReserved21        21U
#define VectorNumber_Vsci0              20U
#define VectorNumber_Vspi0              19U
#define VectorNumber_VReserved18        18U
#define VectorNumber_VReserved17        17U
#define VectorNumber_Vtimovf            16U
#define VectorNumber_VReserved15        15U
#define VectorNumber_VReserved14        14U
#define VectorNumber_Vtimch5            13U
#define VectorNumber_Vtimch4            12U
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
#define VReserved60                     0xFF86U
#define Vapi                            0xFF88U
#define Vlvi                            0xFF8AU
#define VReserved57                     0xFF8CU
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
#define VReserved43                     0xFFA8U
#define VReserved42                     0xFFAAU
#define VReserved41                     0xFFACU
#define VReserved40                     0xFFAEU
#define VReserved39                     0xFFB0U
#define VReserved38                     0xFFB2U
#define VReserved37                     0xFFB4U
#define VReserved36                     0xFFB6U
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
#define Vacmp                           0xFFCCU
#define Vportj                          0xFFCEU
#define VReserved23                     0xFFD0U
#define Vatd                            0xFFD2U
#define VReserved21                     0xFFD4U
#define Vsci0                           0xFFD6U
#define Vspi0                           0xFFD8U
#define VReserved18                     0xFFDAU
#define VReserved17                     0xFFDCU
#define Vtimovf                         0xFFDEU
#define VReserved15                     0xFFE0U
#define VReserved14                     0xFFE2U
#define Vtimch5                         0xFFE4U
#define Vtimch4                         0xFFE6U
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
    byte EDIV0       :1;                                       /* Free-running ECLK Divider, bit 0 */
    byte EDIV1       :1;                                       /* Free-running ECLK Divider, bit 1 */
    byte EDIV2       :1;                                       /* Free-running ECLK Divider, bit 2 */
    byte EDIV3       :1;                                       /* Free-running ECLK Divider, bit 3 */
    byte EDIV4       :1;                                       /* Free-running ECLK Divider, bit 4 */
    byte DIV16       :1;                                       /* Free-running ECLK predivider */
    byte NCLKX2      :1;                                       /* No ECLKX2 */
    byte NECLK       :1;                                       /* No ECLK */
  } Bits;
  struct {
    byte grpEDIV :5;
    byte grpDIV_16 :1;
    byte grpNCLKX_2 :1;
    byte         :1;
  } MergedBits;
} ECLKCTLSTR;
extern volatile ECLKCTLSTR _ECLKCTL @(REG_BASE + 0x0000001CUL);
#define ECLKCTL                         _ECLKCTL.Byte
#define ECLKCTL_EDIV0                   _ECLKCTL.Bits.EDIV0
#define ECLKCTL_EDIV1                   _ECLKCTL.Bits.EDIV1
#define ECLKCTL_EDIV2                   _ECLKCTL.Bits.EDIV2
#define ECLKCTL_EDIV3                   _ECLKCTL.Bits.EDIV3
#define ECLKCTL_EDIV4                   _ECLKCTL.Bits.EDIV4
#define ECLKCTL_DIV16                   _ECLKCTL.Bits.DIV16
#define ECLKCTL_NCLKX2                  _ECLKCTL.Bits.NCLKX2
#define ECLKCTL_NECLK                   _ECLKCTL.Bits.NECLK
#define ECLKCTL_EDIV                    _ECLKCTL.MergedBits.grpEDIV

#define ECLKCTL_EDIV0_MASK              1U
#define ECLKCTL_EDIV1_MASK              2U
#define ECLKCTL_EDIV2_MASK              4U
#define ECLKCTL_EDIV3_MASK              8U
#define ECLKCTL_EDIV4_MASK              16U
#define ECLKCTL_DIV16_MASK              32U
#define ECLKCTL_NCLKX2_MASK             64U
#define ECLKCTL_NECLK_MASK              128U
#define ECLKCTL_EDIV_MASK               31U
#define ECLKCTL_EDIV_BITNUM             0U


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
    byte             :1; 
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
#define CPMUCLKS_PSTP                   _CPMUCLKS.Bits.PSTP
#define CPMUCLKS_PLLSEL                 _CPMUCLKS.Bits.PLLSEL

#define CPMUCLKS_COPOSCSEL0_MASK        1U
#define CPMUCLKS_RTIOSCSEL_MASK         2U
#define CPMUCLKS_PCE_MASK               4U
#define CPMUCLKS_PRE_MASK               8U
#define CPMUCLKS_COPOSCSEL1_MASK        16U
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
    byte IOS4        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 4 */
    byte IOS5        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpIOS  :6;
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
#define TIOS_IOS4                       _TIOS.Bits.IOS4
#define TIOS_IOS5                       _TIOS.Bits.IOS5
#define TIOS_IOS                        _TIOS.MergedBits.grpIOS

#define TIOS_IOS0_MASK                  1U
#define TIOS_IOS1_MASK                  2U
#define TIOS_IOS2_MASK                  4U
#define TIOS_IOS3_MASK                  8U
#define TIOS_IOS4_MASK                  16U
#define TIOS_IOS5_MASK                  32U
#define TIOS_IOS_MASK                   63U
#define TIOS_IOS_BITNUM                 0U


/*** CFORC - Timer Compare Force Register; 0x00000041 ***/
typedef union {
  byte Byte;
  struct {
    byte FOC0        :1;                                       /* Force Output Compare Action for Channel 0 */
    byte FOC1        :1;                                       /* Force Output Compare Action for Channel 1 */
    byte FOC2        :1;                                       /* Force Output Compare Action for Channel 2 */
    byte FOC3        :1;                                       /* Force Output Compare Action for Channel 3 */
    byte FOC4        :1;                                       /* Force Output Compare Action for Channel 4 */
    byte FOC5        :1;                                       /* Force Output Compare Action for Channel 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpFOC  :6;
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
#define CFORC_FOC4                      _CFORC.Bits.FOC4
#define CFORC_FOC5                      _CFORC.Bits.FOC5
#define CFORC_FOC                       _CFORC.MergedBits.grpFOC

#define CFORC_FOC0_MASK                 1U
#define CFORC_FOC1_MASK                 2U
#define CFORC_FOC2_MASK                 4U
#define CFORC_FOC3_MASK                 8U
#define CFORC_FOC4_MASK                 16U
#define CFORC_FOC5_MASK                 32U
#define CFORC_FOC_MASK                  63U
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
    byte TOV4        :1;                                       /* Toggle On Overflow Bit 4 */
    byte TOV5        :1;                                       /* Toggle On Overflow Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTOV  :6;
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
#define TTOV_TOV4                       _TTOV.Bits.TOV4
#define TTOV_TOV5                       _TTOV.Bits.TOV5
#define TTOV_TOV                        _TTOV.MergedBits.grpTOV

#define TTOV_TOV0_MASK                  1U
#define TTOV_TOV1_MASK                  2U
#define TTOV_TOV2_MASK                  4U
#define TTOV_TOV3_MASK                  8U
#define TTOV_TOV4_MASK                  16U
#define TTOV_TOV5_MASK                  32U
#define TTOV_TOV_MASK                   63U
#define TTOV_TOV_BITNUM                 0U


/*** TCTL1 - Timer Control Register 1; 0x00000048 ***/
typedef union {
  byte Byte;
  struct {
    byte OL4         :1;                                       /* Output Level Bit 4 */
    byte OM4         :1;                                       /* Output Mode Bit 4 */
    byte OL5         :1;                                       /* Output Level Bit 5 */
    byte OM5         :1;                                       /* Output Mode Bit 5 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} TCTL1STR;
extern volatile TCTL1STR _TCTL1 @(REG_BASE + 0x00000048UL);
#define TCTL1                           _TCTL1.Byte
#define TCTL1_OL4                       _TCTL1.Bits.OL4
#define TCTL1_OM4                       _TCTL1.Bits.OM4
#define TCTL1_OL5                       _TCTL1.Bits.OL5
#define TCTL1_OM5                       _TCTL1.Bits.OM5

#define TCTL1_OL4_MASK                  1U
#define TCTL1_OM4_MASK                  2U
#define TCTL1_OL5_MASK                  4U
#define TCTL1_OM5_MASK                  8U


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


/*** TCTL3 - Timer Control Register 3; 0x0000004A ***/
typedef union {
  byte Byte;
  struct {
    byte EDG4A       :1;                                       /* Input Capture Edge Control 4A */
    byte EDG4B       :1;                                       /* Input Capture Edge Control 4B */
    byte EDG5A       :1;                                       /* Input Capture Edge Control 5A */
    byte EDG5B       :1;                                       /* Input Capture Edge Control 5B */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpEDG4x :2;
    byte grpEDG5x :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TCTL3STR;
extern volatile TCTL3STR _TCTL3 @(REG_BASE + 0x0000004AUL);
#define TCTL3                           _TCTL3.Byte
#define TCTL3_EDG4A                     _TCTL3.Bits.EDG4A
#define TCTL3_EDG4B                     _TCTL3.Bits.EDG4B
#define TCTL3_EDG5A                     _TCTL3.Bits.EDG5A
#define TCTL3_EDG5B                     _TCTL3.Bits.EDG5B
#define TCTL3_EDG4x                     _TCTL3.MergedBits.grpEDG4x
#define TCTL3_EDG5x                     _TCTL3.MergedBits.grpEDG5x

#define TCTL3_EDG4A_MASK                1U
#define TCTL3_EDG4B_MASK                2U
#define TCTL3_EDG5A_MASK                4U
#define TCTL3_EDG5B_MASK                8U
#define TCTL3_EDG4x_MASK                3U
#define TCTL3_EDG4x_BITNUM              0U
#define TCTL3_EDG5x_MASK                12U
#define TCTL3_EDG5x_BITNUM              2U


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
    byte C4I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 4 */
    byte C5I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 5 */
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
#define TIE_C4I                         _TIE.Bits.C4I
#define TIE_C5I                         _TIE.Bits.C5I

#define TIE_C0I_MASK                    1U
#define TIE_C1I_MASK                    2U
#define TIE_C2I_MASK                    4U
#define TIE_C3I_MASK                    8U
#define TIE_C4I_MASK                    16U
#define TIE_C5I_MASK                    32U


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
    byte C4F         :1;                                       /* Input Capture/Output Compare Channel Flag 4 */
    byte C5F         :1;                                       /* Input Capture/Output Compare Channel Flag 5 */
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
#define TFLG1_C4F                       _TFLG1.Bits.C4F
#define TFLG1_C5F                       _TFLG1.Bits.C5F

#define TFLG1_C0F_MASK                  1U
#define TFLG1_C1F_MASK                  2U
#define TFLG1_C2F_MASK                  4U
#define TFLG1_C3F_MASK                  8U
#define TFLG1_C4F_MASK                  16U
#define TFLG1_C5F_MASK                  32U


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
/* TC_ARR: Access 6 TCx registers in an array */
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


/*** TC4 - Timer Input Capture/Output Compare Register 4; 0x00000058 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC4Hi - Timer Input Capture/Output Compare Register 4 High; 0x00000058 ***/
    union {
      byte Byte;
    } TC4HiSTR;
    #define TC4Hi                       _TC4.Overlap_STR.TC4HiSTR.Byte
    

    /*** TC4Lo - Timer Input Capture/Output Compare Register 4 Low; 0x00000059 ***/
    union {
      byte Byte;
    } TC4LoSTR;
    #define TC4Lo                       _TC4.Overlap_STR.TC4LoSTR.Byte
    
  } Overlap_STR;

} TC4STR;
extern volatile TC4STR _TC4 @(REG_BASE + 0x00000058UL);
#define TC4                             _TC4.Word


/*** TC5 - Timer Input Capture/Output Compare Register 5; 0x0000005A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TC5Hi - Timer Input Capture/Output Compare Register 5 High; 0x0000005A ***/
    union {
      byte Byte;
    } TC5HiSTR;
    #define TC5Hi                       _TC5.Overlap_STR.TC5HiSTR.Byte
    

    /*** TC5Lo - Timer Input Capture/Output Compare Register 5 Low; 0x0000005B ***/
    union {
      byte Byte;
    } TC5LoSTR;
    #define TC5Lo                       _TC5.Overlap_STR.TC5LoSTR.Byte
    
  } Overlap_STR;

} TC5STR;
extern volatile TC5STR _TC5 @(REG_BASE + 0x0000005AUL);
#define TC5                             _TC5.Word


/*** OCPD - Output Compare Pin Disconnect Register; 0x0000006C ***/
typedef union {
  byte Byte;
  struct {
    byte OCPD0       :1;                                       /* Output Compare Pin Disconnect Bit 0 */
    byte OCPD1       :1;                                       /* Output Compare Pin Disconnect Bit 1 */
    byte OCPD2       :1;                                       /* Output Compare Pin Disconnect Bit 2 */
    byte OCPD3       :1;                                       /* Output Compare Pin Disconnect Bit 3 */
    byte OCPD4       :1;                                       /* Output Compare Pin Disconnect Bit 4 */
    byte OCPD5       :1;                                       /* Output Compare Pin Disconnect Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpOCPD :6;
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
#define OCPD_OCPD4                      _OCPD.Bits.OCPD4
#define OCPD_OCPD5                      _OCPD.Bits.OCPD5
#define OCPD_OCPD                       _OCPD.MergedBits.grpOCPD

#define OCPD_OCPD0_MASK                 1U
#define OCPD_OCPD1_MASK                 2U
#define OCPD_OCPD2_MASK                 4U
#define OCPD_OCPD3_MASK                 8U
#define OCPD_OCPD4_MASK                 16U
#define OCPD_OCPD5_MASK                 32U
#define OCPD_OCPD_MASK                  63U
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
        byte ICLKSTP     :1;                                       /* Internal Clock in Stop Mode Bit */
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
    #define ATDCTL2_ICLKSTP             _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ICLKSTP
    #define ATDCTL2_AFFC                _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.AFFC
    
    #define ATDCTL2_ACMPIE_MASK         1U
    #define ATDCTL2_ASCIE_MASK          2U
    #define ATDCTL2_ETRIGE_MASK         4U
    #define ATDCTL2_ETRIGP_MASK         8U
    #define ATDCTL2_ETRIGLE_MASK        16U
    #define ATDCTL2_ICLKSTP_MASK        32U
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
    word ICLKSTP     :1;                                       /* Internal Clock in Stop Mode Bit */
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
#define ATDCTL23_ICLKSTP                _ATDCTL23.Bits.ICLKSTP
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
#define ATDCTL23_ICLKSTP_MASK           8192U
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
        byte CMPE6       :1;                                       /* Compare Enable for Conversion Number 6 of a Sequence */
        byte CMPE7       :1;                                       /* Compare Enable for Conversion Number 7 of a Sequence */
      } Bits;
    } ATDCMPELSTR;
    #define ATDCMPEL                    _ATDCMPE.Overlap_STR.ATDCMPELSTR.Byte
    #define ATDCMPEL_CMPE0              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE0
    #define ATDCMPEL_CMPE1              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE1
    #define ATDCMPEL_CMPE2              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE2
    #define ATDCMPEL_CMPE3              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE3
    #define ATDCMPEL_CMPE4              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE4
    #define ATDCMPEL_CMPE5              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE5
    #define ATDCMPEL_CMPE6              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE6
    #define ATDCMPEL_CMPE7              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE7
    
    #define ATDCMPEL_CMPE0_MASK         1U
    #define ATDCMPEL_CMPE1_MASK         2U
    #define ATDCMPEL_CMPE2_MASK         4U
    #define ATDCMPEL_CMPE3_MASK         8U
    #define ATDCMPEL_CMPE4_MASK         16U
    #define ATDCMPEL_CMPE5_MASK         32U
    #define ATDCMPEL_CMPE6_MASK         64U
    #define ATDCMPEL_CMPE7_MASK         128U
    
  } Overlap_STR;

  struct {
    word CMPE0       :1;                                       /* Compare Enable for Conversion Number 0 of a Sequence */
    word CMPE1       :1;                                       /* Compare Enable for Conversion Number 1 of a Sequence */
    word CMPE2       :1;                                       /* Compare Enable for Conversion Number 2 of a Sequence */
    word CMPE3       :1;                                       /* Compare Enable for Conversion Number 3 of a Sequence */
    word CMPE4       :1;                                       /* Compare Enable for Conversion Number 4 of a Sequence */
    word CMPE5       :1;                                       /* Compare Enable for Conversion Number 5 of a Sequence */
    word CMPE6       :1;                                       /* Compare Enable for Conversion Number 6 of a Sequence */
    word CMPE7       :1;                                       /* Compare Enable for Conversion Number 7 of a Sequence */
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
    word grpCMPE :8;
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
#define ATDCMPE_CMPE6                   _ATDCMPE.Bits.CMPE6
#define ATDCMPE_CMPE7                   _ATDCMPE.Bits.CMPE7
#define ATDCMPE_CMPE                    _ATDCMPE.MergedBits.grpCMPE

#define ATDCMPE_CMPE0_MASK              1U
#define ATDCMPE_CMPE1_MASK              2U
#define ATDCMPE_CMPE2_MASK              4U
#define ATDCMPE_CMPE3_MASK              8U
#define ATDCMPE_CMPE4_MASK              16U
#define ATDCMPE_CMPE5_MASK              32U
#define ATDCMPE_CMPE6_MASK              64U
#define ATDCMPE_CMPE7_MASK              128U
#define ATDCMPE_CMPE_MASK               255U
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
        byte CCF6        :1;                                       /* Conversion Complete Flag 6 */
        byte CCF7        :1;                                       /* Conversion Complete Flag 7 */
      } Bits;
    } ATDSTAT2LSTR;
    #define ATDSTAT2L                   _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Byte
    #define ATDSTAT2L_CCF0              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF0
    #define ATDSTAT2L_CCF1              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF1
    #define ATDSTAT2L_CCF2              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF2
    #define ATDSTAT2L_CCF3              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF3
    #define ATDSTAT2L_CCF4              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF4
    #define ATDSTAT2L_CCF5              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF5
    #define ATDSTAT2L_CCF6              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF6
    #define ATDSTAT2L_CCF7              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF7
    
    #define ATDSTAT2L_CCF0_MASK         1U
    #define ATDSTAT2L_CCF1_MASK         2U
    #define ATDSTAT2L_CCF2_MASK         4U
    #define ATDSTAT2L_CCF3_MASK         8U
    #define ATDSTAT2L_CCF4_MASK         16U
    #define ATDSTAT2L_CCF5_MASK         32U
    #define ATDSTAT2L_CCF6_MASK         64U
    #define ATDSTAT2L_CCF7_MASK         128U
    
  } Overlap_STR;

  struct {
    word CCF0        :1;                                       /* Conversion Complete Flag 0 */
    word CCF1        :1;                                       /* Conversion Complete Flag 1 */
    word CCF2        :1;                                       /* Conversion Complete Flag 2 */
    word CCF3        :1;                                       /* Conversion Complete Flag 3 */
    word CCF4        :1;                                       /* Conversion Complete Flag 4 */
    word CCF5        :1;                                       /* Conversion Complete Flag 5 */
    word CCF6        :1;                                       /* Conversion Complete Flag 6 */
    word CCF7        :1;                                       /* Conversion Complete Flag 7 */
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
    word grpCCF  :8;
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
#define ATDSTAT2_CCF6                   _ATDSTAT2.Bits.CCF6
#define ATDSTAT2_CCF7                   _ATDSTAT2.Bits.CCF7
#define ATDSTAT2_CCF                    _ATDSTAT2.MergedBits.grpCCF

#define ATDSTAT2_CCF0_MASK              1U
#define ATDSTAT2_CCF1_MASK              2U
#define ATDSTAT2_CCF2_MASK              4U
#define ATDSTAT2_CCF3_MASK              8U
#define ATDSTAT2_CCF4_MASK              16U
#define ATDSTAT2_CCF5_MASK              32U
#define ATDSTAT2_CCF6_MASK              64U
#define ATDSTAT2_CCF7_MASK              128U
#define ATDSTAT2_CCF_MASK               255U
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
        byte IEN6        :1;                                       /* ATD Digital Input Enable on channel 6 */
        byte IEN7        :1;                                       /* ATD Digital Input Enable on channel 7 */
      } Bits;
    } ATDDIENLSTR;
    #define ATDDIENL                    _ATDDIEN.Overlap_STR.ATDDIENLSTR.Byte
    #define ATDDIENL_IEN0               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN0
    #define ATDDIENL_IEN1               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN1
    #define ATDDIENL_IEN2               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN2
    #define ATDDIENL_IEN3               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN3
    #define ATDDIENL_IEN4               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN4
    #define ATDDIENL_IEN5               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN5
    #define ATDDIENL_IEN6               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN6
    #define ATDDIENL_IEN7               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN7
    
    #define ATDDIENL_IEN0_MASK          1U
    #define ATDDIENL_IEN1_MASK          2U
    #define ATDDIENL_IEN2_MASK          4U
    #define ATDDIENL_IEN3_MASK          8U
    #define ATDDIENL_IEN4_MASK          16U
    #define ATDDIENL_IEN5_MASK          32U
    #define ATDDIENL_IEN6_MASK          64U
    #define ATDDIENL_IEN7_MASK          128U
    
  } Overlap_STR;

  struct {
    word IEN0        :1;                                       /* ATD Digital Input Enable on channel 0 */
    word IEN1        :1;                                       /* ATD Digital Input Enable on channel 1 */
    word IEN2        :1;                                       /* ATD Digital Input Enable on channel 2 */
    word IEN3        :1;                                       /* ATD Digital Input Enable on channel 3 */
    word IEN4        :1;                                       /* ATD Digital Input Enable on channel 4 */
    word IEN5        :1;                                       /* ATD Digital Input Enable on channel 5 */
    word IEN6        :1;                                       /* ATD Digital Input Enable on channel 6 */
    word IEN7        :1;                                       /* ATD Digital Input Enable on channel 7 */
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
    word grpIEN  :8;
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
#define ATDDIEN_IEN6                    _ATDDIEN.Bits.IEN6
#define ATDDIEN_IEN7                    _ATDDIEN.Bits.IEN7
#define ATDDIEN_IEN                     _ATDDIEN.MergedBits.grpIEN

#define ATDDIEN_IEN0_MASK               1U
#define ATDDIEN_IEN1_MASK               2U
#define ATDDIEN_IEN2_MASK               4U
#define ATDDIEN_IEN3_MASK               8U
#define ATDDIEN_IEN4_MASK               16U
#define ATDDIEN_IEN5_MASK               32U
#define ATDDIEN_IEN6_MASK               64U
#define ATDDIEN_IEN7_MASK               128U
#define ATDDIEN_IEN_MASK                255U
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
        byte CMPHT6      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 6 of a Sequence */
        byte CMPHT7      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 7 of a Sequence */
      } Bits;
    } ATDCMPHTLSTR;
    #define ATDCMPHTL                   _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Byte
    #define ATDCMPHTL_CMPHT0            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT0
    #define ATDCMPHTL_CMPHT1            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT1
    #define ATDCMPHTL_CMPHT2            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT2
    #define ATDCMPHTL_CMPHT3            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT3
    #define ATDCMPHTL_CMPHT4            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT4
    #define ATDCMPHTL_CMPHT5            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT5
    #define ATDCMPHTL_CMPHT6            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT6
    #define ATDCMPHTL_CMPHT7            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT7
    
    #define ATDCMPHTL_CMPHT0_MASK       1U
    #define ATDCMPHTL_CMPHT1_MASK       2U
    #define ATDCMPHTL_CMPHT2_MASK       4U
    #define ATDCMPHTL_CMPHT3_MASK       8U
    #define ATDCMPHTL_CMPHT4_MASK       16U
    #define ATDCMPHTL_CMPHT5_MASK       32U
    #define ATDCMPHTL_CMPHT6_MASK       64U
    #define ATDCMPHTL_CMPHT7_MASK       128U
    
  } Overlap_STR;

  struct {
    word CMPHT0      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 0 of a Sequence */
    word CMPHT1      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 1 of a Sequence */
    word CMPHT2      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 2 of a Sequence */
    word CMPHT3      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 3 of a Sequence */
    word CMPHT4      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 4 of a Sequence */
    word CMPHT5      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 5 of a Sequence */
    word CMPHT6      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 6 of a Sequence */
    word CMPHT7      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 7 of a Sequence */
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
    word grpCMPHT :8;
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
#define ATDCMPHT_CMPHT6                 _ATDCMPHT.Bits.CMPHT6
#define ATDCMPHT_CMPHT7                 _ATDCMPHT.Bits.CMPHT7
#define ATDCMPHT_CMPHT                  _ATDCMPHT.MergedBits.grpCMPHT

#define ATDCMPHT_CMPHT0_MASK            1U
#define ATDCMPHT_CMPHT1_MASK            2U
#define ATDCMPHT_CMPHT2_MASK            4U
#define ATDCMPHT_CMPHT3_MASK            8U
#define ATDCMPHT_CMPHT4_MASK            16U
#define ATDCMPHT_CMPHT5_MASK            32U
#define ATDCMPHT_CMPHT6_MASK            64U
#define ATDCMPHT_CMPHT7_MASK            128U
#define ATDCMPHT_CMPHT_MASK             255U
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
/* ATDDR_ARR: Access 8 ATDDRx registers in an array */
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


/*** ATDDR6 - ATD  Conversion Result Register 6; 0x0000008C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR6H - ATD  Conversion Result Register 6 High; 0x0000008C ***/
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
    } ATDDR6HSTR;
    #define ATDDR6H                     _ATDDR6.Overlap_STR.ATDDR6HSTR.Byte
    #define ATDDR6H_BIT8                _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT8
    #define ATDDR6H_BIT9                _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT9
    #define ATDDR6H_BIT10               _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT10
    #define ATDDR6H_BIT11               _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT11
    #define ATDDR6H_BIT12               _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT12
    #define ATDDR6H_BIT13               _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT13
    #define ATDDR6H_BIT14               _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT14
    #define ATDDR6H_BIT15               _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT15
    
    #define ATDDR6H_BIT8_MASK           1U
    #define ATDDR6H_BIT9_MASK           2U
    #define ATDDR6H_BIT10_MASK          4U
    #define ATDDR6H_BIT11_MASK          8U
    #define ATDDR6H_BIT12_MASK          16U
    #define ATDDR6H_BIT13_MASK          32U
    #define ATDDR6H_BIT14_MASK          64U
    #define ATDDR6H_BIT15_MASK          128U
    

    /*** ATDDR6L - ATD  Conversion Result Register 6 Low; 0x0000008D ***/
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
    } ATDDR6LSTR;
    #define ATDDR6L                     _ATDDR6.Overlap_STR.ATDDR6LSTR.Byte
    #define ATDDR6L_BIT0                _ATDDR6.Overlap_STR.ATDDR6LSTR.Bits.BIT0
    #define ATDDR6L_BIT1                _ATDDR6.Overlap_STR.ATDDR6LSTR.Bits.BIT1
    #define ATDDR6L_BIT2                _ATDDR6.Overlap_STR.ATDDR6LSTR.Bits.BIT2
    #define ATDDR6L_BIT3                _ATDDR6.Overlap_STR.ATDDR6LSTR.Bits.BIT3
    #define ATDDR6L_BIT4                _ATDDR6.Overlap_STR.ATDDR6LSTR.Bits.BIT4
    #define ATDDR6L_BIT5                _ATDDR6.Overlap_STR.ATDDR6LSTR.Bits.BIT5
    #define ATDDR6L_BIT6                _ATDDR6.Overlap_STR.ATDDR6LSTR.Bits.BIT6
    #define ATDDR6L_BIT7                _ATDDR6.Overlap_STR.ATDDR6LSTR.Bits.BIT7
    
    #define ATDDR6L_BIT0_MASK           1U
    #define ATDDR6L_BIT1_MASK           2U
    #define ATDDR6L_BIT2_MASK           4U
    #define ATDDR6L_BIT3_MASK           8U
    #define ATDDR6L_BIT4_MASK           16U
    #define ATDDR6L_BIT5_MASK           32U
    #define ATDDR6L_BIT6_MASK           64U
    #define ATDDR6L_BIT7_MASK           128U
    
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
} ATDDR6STR;
extern volatile ATDDR6STR _ATDDR6 @(REG_BASE + 0x0000008CUL);
#define ATDDR6                          _ATDDR6.Word
#define ATDDR6_BIT0                     _ATDDR6.Bits.BIT0
#define ATDDR6_BIT1                     _ATDDR6.Bits.BIT1
#define ATDDR6_BIT2                     _ATDDR6.Bits.BIT2
#define ATDDR6_BIT3                     _ATDDR6.Bits.BIT3
#define ATDDR6_BIT4                     _ATDDR6.Bits.BIT4
#define ATDDR6_BIT5                     _ATDDR6.Bits.BIT5
#define ATDDR6_BIT6                     _ATDDR6.Bits.BIT6
#define ATDDR6_BIT7                     _ATDDR6.Bits.BIT7
#define ATDDR6_BIT8                     _ATDDR6.Bits.BIT8
#define ATDDR6_BIT9                     _ATDDR6.Bits.BIT9
#define ATDDR6_BIT10                    _ATDDR6.Bits.BIT10
#define ATDDR6_BIT11                    _ATDDR6.Bits.BIT11
#define ATDDR6_BIT12                    _ATDDR6.Bits.BIT12
#define ATDDR6_BIT13                    _ATDDR6.Bits.BIT13
#define ATDDR6_BIT14                    _ATDDR6.Bits.BIT14
#define ATDDR6_BIT15                    _ATDDR6.Bits.BIT15

#define ATDDR6_BIT0_MASK                1U
#define ATDDR6_BIT1_MASK                2U
#define ATDDR6_BIT2_MASK                4U
#define ATDDR6_BIT3_MASK                8U
#define ATDDR6_BIT4_MASK                16U
#define ATDDR6_BIT5_MASK                32U
#define ATDDR6_BIT6_MASK                64U
#define ATDDR6_BIT7_MASK                128U
#define ATDDR6_BIT8_MASK                256U
#define ATDDR6_BIT9_MASK                512U
#define ATDDR6_BIT10_MASK               1024U
#define ATDDR6_BIT11_MASK               2048U
#define ATDDR6_BIT12_MASK               4096U
#define ATDDR6_BIT13_MASK               8192U
#define ATDDR6_BIT14_MASK               16384U
#define ATDDR6_BIT15_MASK               32768U


/*** ATDDR7 - ATD  Conversion Result Register 7; 0x0000008E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR7H - ATD  Conversion Result Register 7 High; 0x0000008E ***/
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
    } ATDDR7HSTR;
    #define ATDDR7H                     _ATDDR7.Overlap_STR.ATDDR7HSTR.Byte
    #define ATDDR7H_BIT8                _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT8
    #define ATDDR7H_BIT9                _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT9
    #define ATDDR7H_BIT10               _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT10
    #define ATDDR7H_BIT11               _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT11
    #define ATDDR7H_BIT12               _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT12
    #define ATDDR7H_BIT13               _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT13
    #define ATDDR7H_BIT14               _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT14
    #define ATDDR7H_BIT15               _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT15
    
    #define ATDDR7H_BIT8_MASK           1U
    #define ATDDR7H_BIT9_MASK           2U
    #define ATDDR7H_BIT10_MASK          4U
    #define ATDDR7H_BIT11_MASK          8U
    #define ATDDR7H_BIT12_MASK          16U
    #define ATDDR7H_BIT13_MASK          32U
    #define ATDDR7H_BIT14_MASK          64U
    #define ATDDR7H_BIT15_MASK          128U
    

    /*** ATDDR7L - ATD  Conversion Result Register 7 Low; 0x0000008F ***/
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
    } ATDDR7LSTR;
    #define ATDDR7L                     _ATDDR7.Overlap_STR.ATDDR7LSTR.Byte
    #define ATDDR7L_BIT0                _ATDDR7.Overlap_STR.ATDDR7LSTR.Bits.BIT0
    #define ATDDR7L_BIT1                _ATDDR7.Overlap_STR.ATDDR7LSTR.Bits.BIT1
    #define ATDDR7L_BIT2                _ATDDR7.Overlap_STR.ATDDR7LSTR.Bits.BIT2
    #define ATDDR7L_BIT3                _ATDDR7.Overlap_STR.ATDDR7LSTR.Bits.BIT3
    #define ATDDR7L_BIT4                _ATDDR7.Overlap_STR.ATDDR7LSTR.Bits.BIT4
    #define ATDDR7L_BIT5                _ATDDR7.Overlap_STR.ATDDR7LSTR.Bits.BIT5
    #define ATDDR7L_BIT6                _ATDDR7.Overlap_STR.ATDDR7LSTR.Bits.BIT6
    #define ATDDR7L_BIT7                _ATDDR7.Overlap_STR.ATDDR7LSTR.Bits.BIT7
    
    #define ATDDR7L_BIT0_MASK           1U
    #define ATDDR7L_BIT1_MASK           2U
    #define ATDDR7L_BIT2_MASK           4U
    #define ATDDR7L_BIT3_MASK           8U
    #define ATDDR7L_BIT4_MASK           16U
    #define ATDDR7L_BIT5_MASK           32U
    #define ATDDR7L_BIT6_MASK           64U
    #define ATDDR7L_BIT7_MASK           128U
    
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
} ATDDR7STR;
extern volatile ATDDR7STR _ATDDR7 @(REG_BASE + 0x0000008EUL);
#define ATDDR7                          _ATDDR7.Word
#define ATDDR7_BIT0                     _ATDDR7.Bits.BIT0
#define ATDDR7_BIT1                     _ATDDR7.Bits.BIT1
#define ATDDR7_BIT2                     _ATDDR7.Bits.BIT2
#define ATDDR7_BIT3                     _ATDDR7.Bits.BIT3
#define ATDDR7_BIT4                     _ATDDR7.Bits.BIT4
#define ATDDR7_BIT5                     _ATDDR7.Bits.BIT5
#define ATDDR7_BIT6                     _ATDDR7.Bits.BIT6
#define ATDDR7_BIT7                     _ATDDR7.Bits.BIT7
#define ATDDR7_BIT8                     _ATDDR7.Bits.BIT8
#define ATDDR7_BIT9                     _ATDDR7.Bits.BIT9
#define ATDDR7_BIT10                    _ATDDR7.Bits.BIT10
#define ATDDR7_BIT11                    _ATDDR7.Bits.BIT11
#define ATDDR7_BIT12                    _ATDDR7.Bits.BIT12
#define ATDDR7_BIT13                    _ATDDR7.Bits.BIT13
#define ATDDR7_BIT14                    _ATDDR7.Bits.BIT14
#define ATDDR7_BIT15                    _ATDDR7.Bits.BIT15

#define ATDDR7_BIT0_MASK                1U
#define ATDDR7_BIT1_MASK                2U
#define ATDDR7_BIT2_MASK                4U
#define ATDDR7_BIT3_MASK                8U
#define ATDDR7_BIT4_MASK                16U
#define ATDDR7_BIT5_MASK                32U
#define ATDDR7_BIT6_MASK                64U
#define ATDDR7_BIT7_MASK                128U
#define ATDDR7_BIT8_MASK                256U
#define ATDDR7_BIT9_MASK                512U
#define ATDDR7_BIT10_MASK               1024U
#define ATDDR7_BIT11_MASK               2048U
#define ATDDR7_BIT12_MASK               4096U
#define ATDDR7_BIT13_MASK               8192U
#define ATDDR7_BIT14_MASK               16384U
#define ATDDR7_BIT15_MASK               32768U


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
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPWME :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PWMESTR;
extern volatile PWMESTR _PWME @(REG_BASE + 0x000000A0UL);
#define PWME                            _PWME.Byte
#define PWME_PWME0                      _PWME.Bits.PWME0
#define PWME_PWME1                      _PWME.Bits.PWME1
#define PWME_PWME2                      _PWME.Bits.PWME2
#define PWME_PWME3                      _PWME.Bits.PWME3
#define PWME_PWME4                      _PWME.Bits.PWME4
#define PWME_PWME5                      _PWME.Bits.PWME5
#define PWME_PWME                       _PWME.MergedBits.grpPWME

#define PWME_PWME0_MASK                 1U
#define PWME_PWME1_MASK                 2U
#define PWME_PWME2_MASK                 4U
#define PWME_PWME3_MASK                 8U
#define PWME_PWME4_MASK                 16U
#define PWME_PWME5_MASK                 32U
#define PWME_PWME_MASK                  63U
#define PWME_PWME_BITNUM                0U


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
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPPOL :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PWMPOLSTR;
extern volatile PWMPOLSTR _PWMPOL @(REG_BASE + 0x000000A1UL);
#define PWMPOL                          _PWMPOL.Byte
#define PWMPOL_PPOL0                    _PWMPOL.Bits.PPOL0
#define PWMPOL_PPOL1                    _PWMPOL.Bits.PPOL1
#define PWMPOL_PPOL2                    _PWMPOL.Bits.PPOL2
#define PWMPOL_PPOL3                    _PWMPOL.Bits.PPOL3
#define PWMPOL_PPOL4                    _PWMPOL.Bits.PPOL4
#define PWMPOL_PPOL5                    _PWMPOL.Bits.PPOL5
#define PWMPOL_PPOL                     _PWMPOL.MergedBits.grpPPOL

#define PWMPOL_PPOL0_MASK               1U
#define PWMPOL_PPOL1_MASK               2U
#define PWMPOL_PPOL2_MASK               4U
#define PWMPOL_PPOL3_MASK               8U
#define PWMPOL_PPOL4_MASK               16U
#define PWMPOL_PPOL5_MASK               32U
#define PWMPOL_PPOL_MASK                63U
#define PWMPOL_PPOL_BITNUM              0U


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
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPCLK :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PWMCLKSTR;
extern volatile PWMCLKSTR _PWMCLK @(REG_BASE + 0x000000A2UL);
#define PWMCLK                          _PWMCLK.Byte
#define PWMCLK_PCLK0                    _PWMCLK.Bits.PCLK0
#define PWMCLK_PCLK1                    _PWMCLK.Bits.PCLK1
#define PWMCLK_PCLK2                    _PWMCLK.Bits.PCLK2
#define PWMCLK_PCLK3                    _PWMCLK.Bits.PCLK3
#define PWMCLK_PCLK4                    _PWMCLK.Bits.PCLK4
#define PWMCLK_PCLK5                    _PWMCLK.Bits.PCLK5
#define PWMCLK_PCLK                     _PWMCLK.MergedBits.grpPCLK

#define PWMCLK_PCLK0_MASK               1U
#define PWMCLK_PCLK1_MASK               2U
#define PWMCLK_PCLK2_MASK               4U
#define PWMCLK_PCLK3_MASK               8U
#define PWMCLK_PCLK4_MASK               16U
#define PWMCLK_PCLK5_MASK               32U
#define PWMCLK_PCLK_MASK                63U
#define PWMCLK_PCLK_BITNUM              0U


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
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCAE  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PWMCAESTR;
extern volatile PWMCAESTR _PWMCAE @(REG_BASE + 0x000000A4UL);
#define PWMCAE                          _PWMCAE.Byte
#define PWMCAE_CAE0                     _PWMCAE.Bits.CAE0
#define PWMCAE_CAE1                     _PWMCAE.Bits.CAE1
#define PWMCAE_CAE2                     _PWMCAE.Bits.CAE2
#define PWMCAE_CAE3                     _PWMCAE.Bits.CAE3
#define PWMCAE_CAE4                     _PWMCAE.Bits.CAE4
#define PWMCAE_CAE5                     _PWMCAE.Bits.CAE5
#define PWMCAE_CAE                      _PWMCAE.MergedBits.grpCAE

#define PWMCAE_CAE0_MASK                1U
#define PWMCAE_CAE1_MASK                2U
#define PWMCAE_CAE2_MASK                4U
#define PWMCAE_CAE3_MASK                8U
#define PWMCAE_CAE4_MASK                16U
#define PWMCAE_CAE5_MASK                32U
#define PWMCAE_CAE_MASK                 63U
#define PWMCAE_CAE_BITNUM               0U


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
    byte             :1; 
  } Bits;
} PWMCTLSTR;
extern volatile PWMCTLSTR _PWMCTL @(REG_BASE + 0x000000A5UL);
#define PWMCTL                          _PWMCTL.Byte
#define PWMCTL_PFRZ                     _PWMCTL.Bits.PFRZ
#define PWMCTL_PSWAI                    _PWMCTL.Bits.PSWAI
#define PWMCTL_CON01                    _PWMCTL.Bits.CON01
#define PWMCTL_CON23                    _PWMCTL.Bits.CON23
#define PWMCTL_CON45                    _PWMCTL.Bits.CON45

#define PWMCTL_PFRZ_MASK                4U
#define PWMCTL_PSWAI_MASK               8U
#define PWMCTL_CON01_MASK               16U
#define PWMCTL_CON23_MASK               32U
#define PWMCTL_CON45_MASK               64U


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
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPCLKAB :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PWMCLKABSTR;
extern volatile PWMCLKABSTR _PWMCLKAB @(REG_BASE + 0x000000A6UL);
#define PWMCLKAB                        _PWMCLKAB.Byte
#define PWMCLKAB_PCLKAB0                _PWMCLKAB.Bits.PCLKAB0
#define PWMCLKAB_PCLKAB1                _PWMCLKAB.Bits.PCLKAB1
#define PWMCLKAB_PCLKAB2                _PWMCLKAB.Bits.PCLKAB2
#define PWMCLKAB_PCLKAB3                _PWMCLKAB.Bits.PCLKAB3
#define PWMCLKAB_PCLKAB4                _PWMCLKAB.Bits.PCLKAB4
#define PWMCLKAB_PCLKAB5                _PWMCLKAB.Bits.PCLKAB5
#define PWMCLKAB_PCLKAB                 _PWMCLKAB.MergedBits.grpPCLKAB

#define PWMCLKAB_PCLKAB0_MASK           1U
#define PWMCLKAB_PCLKAB1_MASK           2U
#define PWMCLKAB_PCLKAB2_MASK           4U
#define PWMCLKAB_PCLKAB3_MASK           8U
#define PWMCLKAB_PCLKAB4_MASK           16U
#define PWMCLKAB_PCLKAB5_MASK           32U
#define PWMCLKAB_PCLKAB_MASK            63U
#define PWMCLKAB_PCLKAB_BITNUM          0U


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
    /* PWMCNT_ARR: Access 6 PWMCNTx registers in an array */
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
    /* PWMPER_ARR: Access 6 PWMPERx registers in an array */
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
    /* PWMDTY_ARR: Access 6 PWMDTYx registers in an array */
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
            byte TNP0        :1;                                       /* Transmitter Narrow Pulse Bit 0 */
            byte TNP1        :1;                                       /* Transmitter Narrow Pulse Bit 1 */
            byte IREN        :1;                                       /* Infrared Enable Bit */
          } Bits;
          struct {
            byte grpSBR_8 :5;
            byte grpTNP :2;
            byte :1;
          } MergedBits;
        } SCI0BDHSTR;
        #define SCI0BDH                 _SCI0BD.Overlap_STR.SCI0ASR1STR.Byte
        #define SCI0BDH_SBR8            _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR8
        #define SCI0BDH_SBR9            _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR9
        #define SCI0BDH_SBR10           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR10
        #define SCI0BDH_SBR11           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR11
        #define SCI0BDH_SBR12           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR12
        #define SCI0BDH_TNP0            _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.TNP0
        #define SCI0BDH_TNP1            _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.TNP1
        #define SCI0BDH_IREN            _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.IREN
        #define SCI0BDH_SBR_8           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.MergedBits.grpSBR_8
        #define SCI0BDH_TNP             _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.MergedBits.grpTNP
        #define SCI0BDH_SBR             SCI0BDH_SBR_8
        
        #define SCI0BDH_SBR8_MASK       1U
        #define SCI0BDH_SBR9_MASK       2U
        #define SCI0BDH_SBR10_MASK      4U
        #define SCI0BDH_SBR11_MASK      8U
        #define SCI0BDH_SBR12_MASK      16U
        #define SCI0BDH_TNP0_MASK       32U
        #define SCI0BDH_TNP1_MASK       64U
        #define SCI0BDH_IREN_MASK       128U
        #define SCI0BDH_SBR_8_MASK      31U
        #define SCI0BDH_SBR_8_BITNUM    0U
        #define SCI0BDH_TNP_MASK        96U
        #define SCI0BDH_TNP_BITNUM      5U
        
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
    word TNP0        :1;                                       /* Transmitter Narrow Pulse Bit 0 */
    word TNP1        :1;                                       /* Transmitter Narrow Pulse Bit 1 */
    word IREN        :1;                                       /* Infrared Enable Bit */
  } Bits;
  struct {
    word grpSBR  :13;
    word grpTNP  :2;
    word         :1;
  } MergedBits;
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
#define SCI0BD_TNP0                     _SCI0BD.Bits.TNP0
#define SCI0BD_TNP1                     _SCI0BD.Bits.TNP1
#define SCI0BD_IREN                     _SCI0BD.Bits.IREN
#define SCI0BD_SBR                      _SCI0BD.MergedBits.grpSBR
#define SCI0BD_TNP                      _SCI0BD.MergedBits.grpTNP

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
#define SCI0BD_TNP0_MASK                8192U
#define SCI0BD_TNP1_MASK                16384U
#define SCI0BD_IREN_MASK                32768U
#define SCI0BD_SBR_MASK                 8191U
#define SCI0BD_SBR_BITNUM               0U
#define SCI0BD_TNP_MASK                 24576U
#define SCI0BD_TNP_BITNUM               13U


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
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte     :1;
        byte grpBERRM :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCI0ACR2STR;
    #define SCI0ACR2                    _SCI0ACR2.Byte
    #define SCI0ACR2_BKDFE              _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.BKDFE
    #define SCI0ACR2_BERRM0             _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.BERRM0
    #define SCI0ACR2_BERRM1             _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.BERRM1
    #define SCI0ACR2_BERRM              _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.MergedBits.grpBERRM
    
    #define SCI0ACR2_BKDFE_MASK         1U
    #define SCI0ACR2_BERRM0_MASK        2U
    #define SCI0ACR2_BERRM1_MASK        4U
    #define SCI0ACR2_BERRM_MASK         6U
    #define SCI0ACR2_BERRM_BITNUM       1U
    
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


/*** SPI0CR1 - SPI 0 Control Register 1; 0x000000D8 ***/
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
} SPI0CR1STR;
extern volatile SPI0CR1STR _SPI0CR1 @(REG_BASE + 0x000000D8UL);
#define SPI0CR1                         _SPI0CR1.Byte
#define SPI0CR1_LSBFE                   _SPI0CR1.Bits.LSBFE
#define SPI0CR1_SSOE                    _SPI0CR1.Bits.SSOE
#define SPI0CR1_CPHA                    _SPI0CR1.Bits.CPHA
#define SPI0CR1_CPOL                    _SPI0CR1.Bits.CPOL
#define SPI0CR1_MSTR                    _SPI0CR1.Bits.MSTR
#define SPI0CR1_SPTIE                   _SPI0CR1.Bits.SPTIE
#define SPI0CR1_SPE                     _SPI0CR1.Bits.SPE
#define SPI0CR1_SPIE                    _SPI0CR1.Bits.SPIE

#define SPI0CR1_LSBFE_MASK              1U
#define SPI0CR1_SSOE_MASK               2U
#define SPI0CR1_CPHA_MASK               4U
#define SPI0CR1_CPOL_MASK               8U
#define SPI0CR1_MSTR_MASK               16U
#define SPI0CR1_SPTIE_MASK              32U
#define SPI0CR1_SPE_MASK                64U
#define SPI0CR1_SPIE_MASK               128U


/*** SPI0CR2 - SPI 0 Control Register 2; 0x000000D9 ***/
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
} SPI0CR2STR;
extern volatile SPI0CR2STR _SPI0CR2 @(REG_BASE + 0x000000D9UL);
#define SPI0CR2                         _SPI0CR2.Byte
#define SPI0CR2_SPC0                    _SPI0CR2.Bits.SPC0
#define SPI0CR2_SPISWAI                 _SPI0CR2.Bits.SPISWAI
#define SPI0CR2_BIDIROE                 _SPI0CR2.Bits.BIDIROE
#define SPI0CR2_MODFEN                  _SPI0CR2.Bits.MODFEN
#define SPI0CR2_XFRW                    _SPI0CR2.Bits.XFRW

#define SPI0CR2_SPC0_MASK               1U
#define SPI0CR2_SPISWAI_MASK            2U
#define SPI0CR2_BIDIROE_MASK            8U
#define SPI0CR2_MODFEN_MASK             16U
#define SPI0CR2_XFRW_MASK               64U


/*** SPI0BR - SPI 0 Baud Rate Register; 0x000000DA ***/
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
} SPI0BRSTR;
extern volatile SPI0BRSTR _SPI0BR @(REG_BASE + 0x000000DAUL);
#define SPI0BR                          _SPI0BR.Byte
#define SPI0BR_SPR0                     _SPI0BR.Bits.SPR0
#define SPI0BR_SPR1                     _SPI0BR.Bits.SPR1
#define SPI0BR_SPR2                     _SPI0BR.Bits.SPR2
#define SPI0BR_SPPR0                    _SPI0BR.Bits.SPPR0
#define SPI0BR_SPPR1                    _SPI0BR.Bits.SPPR1
#define SPI0BR_SPPR2                    _SPI0BR.Bits.SPPR2
#define SPI0BR_SPR                      _SPI0BR.MergedBits.grpSPR
#define SPI0BR_SPPR                     _SPI0BR.MergedBits.grpSPPR

#define SPI0BR_SPR0_MASK                1U
#define SPI0BR_SPR1_MASK                2U
#define SPI0BR_SPR2_MASK                4U
#define SPI0BR_SPPR0_MASK               16U
#define SPI0BR_SPPR1_MASK               32U
#define SPI0BR_SPPR2_MASK               64U
#define SPI0BR_SPR_MASK                 7U
#define SPI0BR_SPR_BITNUM               0U
#define SPI0BR_SPPR_MASK                112U
#define SPI0BR_SPPR_BITNUM              4U


/*** SPI0SR - SPI 0 Status Register; 0x000000DB ***/
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
} SPI0SRSTR;
extern volatile SPI0SRSTR _SPI0SR @(REG_BASE + 0x000000DBUL);
#define SPI0SR                          _SPI0SR.Byte
#define SPI0SR_MODF                     _SPI0SR.Bits.MODF
#define SPI0SR_SPTEF                    _SPI0SR.Bits.SPTEF
#define SPI0SR_SPIF                     _SPI0SR.Bits.SPIF

#define SPI0SR_MODF_MASK                16U
#define SPI0SR_SPTEF_MASK               32U
#define SPI0SR_SPIF_MASK                128U


/*** SPI0DR - SPI 0 Data Register; 0x000000DC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SPI0DRH - SPI 0 Data Register High; 0x000000DC ***/
    union {
      byte Byte;
      struct {
        byte R8_T8       :1;                                       /* SPI 0 Data Bit 8 */
        byte R9_T9       :1;                                       /* SPI 0 Data Bit 9 */
        byte R10_T10     :1;                                       /* SPI 0 Data Bit 10 */
        byte R11_T11     :1;                                       /* SPI 0 Data Bit 11 */
        byte R12_T12     :1;                                       /* SPI 0 Data Bit 12 */
        byte R13_T13     :1;                                       /* SPI 0 Data Bit 13 */
        byte R14_T14     :1;                                       /* SPI 0 Data Bit 14 */
        byte R15_T15     :1;                                       /* SPI 0 Data Bit 15 */
      } Bits;
    } SPI0DRHSTR;
    #define SPI0DRH                     _SPI0DR.Overlap_STR.SPI0DRHSTR.Byte
    #define SPI0DRH_R8_T8               _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R8_T8
    #define SPI0DRH_R9_T9               _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R9_T9
    #define SPI0DRH_R10_T10             _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R10_T10
    #define SPI0DRH_R11_T11             _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R11_T11
    #define SPI0DRH_R12_T12             _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R12_T12
    #define SPI0DRH_R13_T13             _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R13_T13
    #define SPI0DRH_R14_T14             _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R14_T14
    #define SPI0DRH_R15_T15             _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R15_T15
    
    #define SPI0DRH_R8_T8_MASK          1U
    #define SPI0DRH_R9_T9_MASK          2U
    #define SPI0DRH_R10_T10_MASK        4U
    #define SPI0DRH_R11_T11_MASK        8U
    #define SPI0DRH_R12_T12_MASK        16U
    #define SPI0DRH_R13_T13_MASK        32U
    #define SPI0DRH_R14_T14_MASK        64U
    #define SPI0DRH_R15_T15_MASK        128U
    

    /*** SPI0DRL - SPI 0 Data Register Low; 0x000000DD ***/
    union {
      byte Byte;
      struct {
        byte R0_T0       :1;                                       /* SPI 0 Data Bit 0 */
        byte R1_T1       :1;                                       /* SPI 0 Data Bit 1 */
        byte R2_T2       :1;                                       /* SPI 0 Data Bit 2 */
        byte R3_T3       :1;                                       /* SPI 0 Data Bit 3 */
        byte R4_T4       :1;                                       /* SPI 0 Data Bit 4 */
        byte R5_T5       :1;                                       /* SPI 0 Data Bit 5 */
        byte R6_T6       :1;                                       /* SPI 0 Data Bit 6 */
        byte R7_T7       :1;                                       /* SPI 0 Data Bit 7 */
      } Bits;
    } SPI0DRLSTR;
    #define SPI0DRL                     _SPI0DR.Overlap_STR.SPI0DRLSTR.Byte
    #define SPI0DRL_R0_T0               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R0_T0
    #define SPI0DRL_R1_T1               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R1_T1
    #define SPI0DRL_R2_T2               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R2_T2
    #define SPI0DRL_R3_T3               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R3_T3
    #define SPI0DRL_R4_T4               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R4_T4
    #define SPI0DRL_R5_T5               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R5_T5
    #define SPI0DRL_R6_T6               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R6_T6
    #define SPI0DRL_R7_T7               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R7_T7
    
    #define SPI0DRL_R0_T0_MASK          1U
    #define SPI0DRL_R1_T1_MASK          2U
    #define SPI0DRL_R2_T2_MASK          4U
    #define SPI0DRL_R3_T3_MASK          8U
    #define SPI0DRL_R4_T4_MASK          16U
    #define SPI0DRL_R5_T5_MASK          32U
    #define SPI0DRL_R6_T6_MASK          64U
    #define SPI0DRL_R7_T7_MASK          128U
    
  } Overlap_STR;

  struct {
    word R0_T0       :1;                                       /* SPI 0 Data Bit 0 */
    word R1_T1       :1;                                       /* SPI 0 Data Bit 1 */
    word R2_T2       :1;                                       /* SPI 0 Data Bit 2 */
    word R3_T3       :1;                                       /* SPI 0 Data Bit 3 */
    word R4_T4       :1;                                       /* SPI 0 Data Bit 4 */
    word R5_T5       :1;                                       /* SPI 0 Data Bit 5 */
    word R6_T6       :1;                                       /* SPI 0 Data Bit 6 */
    word R7_T7       :1;                                       /* SPI 0 Data Bit 7 */
    word R8_T8       :1;                                       /* SPI 0 Data Bit 8 */
    word R9_T9       :1;                                       /* SPI 0 Data Bit 9 */
    word R10_T10     :1;                                       /* SPI 0 Data Bit 10 */
    word R11_T11     :1;                                       /* SPI 0 Data Bit 11 */
    word R12_T12     :1;                                       /* SPI 0 Data Bit 12 */
    word R13_T13     :1;                                       /* SPI 0 Data Bit 13 */
    word R14_T14     :1;                                       /* SPI 0 Data Bit 14 */
    word R15_T15     :1;                                       /* SPI 0 Data Bit 15 */
  } Bits;
} SPI0DRSTR;
extern volatile SPI0DRSTR _SPI0DR @(REG_BASE + 0x000000DCUL);
#define SPI0DR                          _SPI0DR.Word
#define SPI0DR_R0_T0                    _SPI0DR.Bits.R0_T0
#define SPI0DR_R1_T1                    _SPI0DR.Bits.R1_T1
#define SPI0DR_R2_T2                    _SPI0DR.Bits.R2_T2
#define SPI0DR_R3_T3                    _SPI0DR.Bits.R3_T3
#define SPI0DR_R4_T4                    _SPI0DR.Bits.R4_T4
#define SPI0DR_R5_T5                    _SPI0DR.Bits.R5_T5
#define SPI0DR_R6_T6                    _SPI0DR.Bits.R6_T6
#define SPI0DR_R7_T7                    _SPI0DR.Bits.R7_T7
#define SPI0DR_R8_T8                    _SPI0DR.Bits.R8_T8
#define SPI0DR_R9_T9                    _SPI0DR.Bits.R9_T9
#define SPI0DR_R10_T10                  _SPI0DR.Bits.R10_T10
#define SPI0DR_R11_T11                  _SPI0DR.Bits.R11_T11
#define SPI0DR_R12_T12                  _SPI0DR.Bits.R12_T12
#define SPI0DR_R13_T13                  _SPI0DR.Bits.R13_T13
#define SPI0DR_R14_T14                  _SPI0DR.Bits.R14_T14
#define SPI0DR_R15_T15                  _SPI0DR.Bits.R15_T15

#define SPI0DR_R0_T0_MASK               1U
#define SPI0DR_R1_T1_MASK               2U
#define SPI0DR_R2_T2_MASK               4U
#define SPI0DR_R3_T3_MASK               8U
#define SPI0DR_R4_T4_MASK               16U
#define SPI0DR_R5_T5_MASK               32U
#define SPI0DR_R6_T6_MASK               64U
#define SPI0DR_R7_T7_MASK               128U
#define SPI0DR_R8_T8_MASK               256U
#define SPI0DR_R9_T9_MASK               512U
#define SPI0DR_R10_T10_MASK             1024U
#define SPI0DR_R11_T11_MASK             2048U
#define SPI0DR_R12_T12_MASK             4096U
#define SPI0DR_R13_T13_MASK             8192U
#define SPI0DR_R14_T14_MASK             16384U
#define SPI0DR_R15_T15_MASK             32768U


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
    byte DPS4        :1;                                       /* D-Flash Protection Size Bit 4 */
    byte             :1; 
    byte             :1; 
    byte DPOPEN      :1;                                       /* D-Flash Protection Control */
  } Bits;
  struct {
    byte grpDPS  :5;
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
#define DFPROT_DPS4                     _DFPROT.Bits.DPS4
#define DFPROT_DPOPEN                   _DFPROT.Bits.DPOPEN
#define DFPROT_DPS                      _DFPROT.MergedBits.grpDPS

#define DFPROT_DPS0_MASK                1U
#define DFPROT_DPS1_MASK                2U
#define DFPROT_DPS2_MASK                4U
#define DFPROT_DPS3_MASK                8U
#define DFPROT_DPS4_MASK                16U
#define DFPROT_DPOPEN_MASK              128U
#define DFPROT_DPS_MASK                 31U
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


/*** PTT - Port T Data Register; 0x00000240 ***/
typedef union {
  byte Byte;
  struct {
    byte PTT0        :1;                                       /* Port T general purpose input/output data bit 0 */
    byte PTT1        :1;                                       /* Port T general purpose input/output data bit 1 */
    byte PTT2        :1;                                       /* Port T general purpose input/output data bit 2 */
    byte PTT3        :1;                                       /* Port T general purpose input/output data bit 3 */
    byte PTT4        :1;                                       /* Port T general purpose input/output data bit 4 */
    byte PTT5        :1;                                       /* Port T general purpose input/output data bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTT  :6;
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
#define PTT_PTT4                        _PTT.Bits.PTT4
#define PTT_PTT5                        _PTT.Bits.PTT5
#define PTT_PTT                         _PTT.MergedBits.grpPTT

#define PTT_PTT0_MASK                   1U
#define PTT_PTT1_MASK                   2U
#define PTT_PTT2_MASK                   4U
#define PTT_PTT3_MASK                   8U
#define PTT_PTT4_MASK                   16U
#define PTT_PTT5_MASK                   32U
#define PTT_PTT_MASK                    63U
#define PTT_PTT_BITNUM                  0U


/*** PTIT - Port T Input Register; 0x00000241 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIT0       :1;                                       /* Port T input data bit 0 */
    byte PTIT1       :1;                                       /* Port T input data bit 1 */
    byte PTIT2       :1;                                       /* Port T input data bit 2 */
    byte PTIT3       :1;                                       /* Port T input data bit 3 */
    byte PTIT4       :1;                                       /* Port T input data bit 4 */
    byte PTIT5       :1;                                       /* Port T input data bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTIT :6;
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
#define PTIT_PTIT4                      _PTIT.Bits.PTIT4
#define PTIT_PTIT5                      _PTIT.Bits.PTIT5
#define PTIT_PTIT                       _PTIT.MergedBits.grpPTIT

#define PTIT_PTIT0_MASK                 1U
#define PTIT_PTIT1_MASK                 2U
#define PTIT_PTIT2_MASK                 4U
#define PTIT_PTIT3_MASK                 8U
#define PTIT_PTIT4_MASK                 16U
#define PTIT_PTIT5_MASK                 32U
#define PTIT_PTIT_MASK                  63U
#define PTIT_PTIT_BITNUM                0U


/*** DDRT - Port T Data Direction Register; 0x00000242 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRT0       :1;                                       /* Port T data direction bit 0 */
    byte DDRT1       :1;                                       /* Port T data direction bit 1 */
    byte DDRT2       :1;                                       /* Port T data direction bit 2 */
    byte DDRT3       :1;                                       /* Port T data direction bit 3 */
    byte DDRT4       :1;                                       /* Port T data direction bit 4 */
    byte DDRT5       :1;                                       /* Port T data direction bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDDRT :6;
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
#define DDRT_DDRT4                      _DDRT.Bits.DDRT4
#define DDRT_DDRT5                      _DDRT.Bits.DDRT5
#define DDRT_DDRT                       _DDRT.MergedBits.grpDDRT

#define DDRT_DDRT0_MASK                 1U
#define DDRT_DDRT1_MASK                 2U
#define DDRT_DDRT2_MASK                 4U
#define DDRT_DDRT3_MASK                 8U
#define DDRT_DDRT4_MASK                 16U
#define DDRT_DDRT5_MASK                 32U
#define DDRT_DDRT_MASK                  63U
#define DDRT_DDRT_BITNUM                0U


/*** PERT - Port T Pull Device Enable Register; 0x00000244 ***/
typedef union {
  byte Byte;
  struct {
    byte PERT0       :1;                                       /* Port T pull device enable bit 0 */
    byte PERT1       :1;                                       /* Port T pull device enable bit 1 */
    byte PERT2       :1;                                       /* Port T pull device enable bit 2 */
    byte PERT3       :1;                                       /* Port T pull device enable bit 3 */
    byte PERT4       :1;                                       /* Port T pull device enable bit 4 */
    byte PERT5       :1;                                       /* Port T pull device enable bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPERT :6;
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
#define PERT_PERT4                      _PERT.Bits.PERT4
#define PERT_PERT5                      _PERT.Bits.PERT5
#define PERT_PERT                       _PERT.MergedBits.grpPERT

#define PERT_PERT0_MASK                 1U
#define PERT_PERT1_MASK                 2U
#define PERT_PERT2_MASK                 4U
#define PERT_PERT3_MASK                 8U
#define PERT_PERT4_MASK                 16U
#define PERT_PERT5_MASK                 32U
#define PERT_PERT_MASK                  63U
#define PERT_PERT_BITNUM                0U


/*** PPST - Port T Polarity Select Register; 0x00000245 ***/
typedef union {
  byte Byte;
  struct {
    byte PPST0       :1;                                       /* Port T pull device select bit 0 */
    byte PPST1       :1;                                       /* Port T pull device select bit 1 */
    byte PPST2       :1;                                       /* Port T pull device select bit 2 */
    byte PPST3       :1;                                       /* Port T pull device select bit 3 */
    byte PPST4       :1;                                       /* Port T pull device select bit 4 */
    byte PPST5       :1;                                       /* Port T pull device select bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPPST :6;
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
#define PPST_PPST4                      _PPST.Bits.PPST4
#define PPST_PPST5                      _PPST.Bits.PPST5
#define PPST_PPST                       _PPST.MergedBits.grpPPST

#define PPST_PPST0_MASK                 1U
#define PPST_PPST1_MASK                 2U
#define PPST_PPST2_MASK                 4U
#define PPST_PPST3_MASK                 8U
#define PPST_PPST4_MASK                 16U
#define PPST_PPST5_MASK                 32U
#define PPST_PPST_MASK                  63U
#define PPST_PPST_BITNUM                0U


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
    byte PTS6        :1;                                       /* Port S general purpose input/output data bit 6 */
    byte PTS7        :1;                                       /* Port S general purpose input/output data bit 7 */
  } Bits;
} PTSSTR;
extern volatile PTSSTR _PTS @(REG_BASE + 0x00000248UL);
#define PTS                             _PTS.Byte
#define PTS_PTS0                        _PTS.Bits.PTS0
#define PTS_PTS1                        _PTS.Bits.PTS1
#define PTS_PTS2                        _PTS.Bits.PTS2
#define PTS_PTS3                        _PTS.Bits.PTS3
#define PTS_PTS4                        _PTS.Bits.PTS4
#define PTS_PTS5                        _PTS.Bits.PTS5
#define PTS_PTS6                        _PTS.Bits.PTS6
#define PTS_PTS7                        _PTS.Bits.PTS7

#define PTS_PTS0_MASK                   1U
#define PTS_PTS1_MASK                   2U
#define PTS_PTS2_MASK                   4U
#define PTS_PTS3_MASK                   8U
#define PTS_PTS4_MASK                   16U
#define PTS_PTS5_MASK                   32U
#define PTS_PTS6_MASK                   64U
#define PTS_PTS7_MASK                   128U


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
    byte PTIS6       :1;                                       /* Port S input data bit 6 */
    byte PTIS7       :1;                                       /* Port S input data bit 7 */
  } Bits;
} PTISSTR;
extern volatile PTISSTR _PTIS @(REG_BASE + 0x00000249UL);
#define PTIS                            _PTIS.Byte
#define PTIS_PTIS0                      _PTIS.Bits.PTIS0
#define PTIS_PTIS1                      _PTIS.Bits.PTIS1
#define PTIS_PTIS2                      _PTIS.Bits.PTIS2
#define PTIS_PTIS3                      _PTIS.Bits.PTIS3
#define PTIS_PTIS4                      _PTIS.Bits.PTIS4
#define PTIS_PTIS5                      _PTIS.Bits.PTIS5
#define PTIS_PTIS6                      _PTIS.Bits.PTIS6
#define PTIS_PTIS7                      _PTIS.Bits.PTIS7

#define PTIS_PTIS0_MASK                 1U
#define PTIS_PTIS1_MASK                 2U
#define PTIS_PTIS2_MASK                 4U
#define PTIS_PTIS3_MASK                 8U
#define PTIS_PTIS4_MASK                 16U
#define PTIS_PTIS5_MASK                 32U
#define PTIS_PTIS6_MASK                 64U
#define PTIS_PTIS7_MASK                 128U


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
    byte DDRS6       :1;                                       /* Port S data direction bit 6 */
    byte DDRS7       :1;                                       /* Port S data direction bit 7 */
  } Bits;
} DDRSSTR;
extern volatile DDRSSTR _DDRS @(REG_BASE + 0x0000024AUL);
#define DDRS                            _DDRS.Byte
#define DDRS_DDRS0                      _DDRS.Bits.DDRS0
#define DDRS_DDRS1                      _DDRS.Bits.DDRS1
#define DDRS_DDRS2                      _DDRS.Bits.DDRS2
#define DDRS_DDRS3                      _DDRS.Bits.DDRS3
#define DDRS_DDRS4                      _DDRS.Bits.DDRS4
#define DDRS_DDRS5                      _DDRS.Bits.DDRS5
#define DDRS_DDRS6                      _DDRS.Bits.DDRS6
#define DDRS_DDRS7                      _DDRS.Bits.DDRS7

#define DDRS_DDRS0_MASK                 1U
#define DDRS_DDRS1_MASK                 2U
#define DDRS_DDRS2_MASK                 4U
#define DDRS_DDRS3_MASK                 8U
#define DDRS_DDRS4_MASK                 16U
#define DDRS_DDRS5_MASK                 32U
#define DDRS_DDRS6_MASK                 64U
#define DDRS_DDRS7_MASK                 128U


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
    byte PERS6       :1;                                       /* Port S pull device enable bit 6 */
    byte PERS7       :1;                                       /* Port S pull device enable bit 7 */
  } Bits;
} PERSSTR;
extern volatile PERSSTR _PERS @(REG_BASE + 0x0000024CUL);
#define PERS                            _PERS.Byte
#define PERS_PERS0                      _PERS.Bits.PERS0
#define PERS_PERS1                      _PERS.Bits.PERS1
#define PERS_PERS2                      _PERS.Bits.PERS2
#define PERS_PERS3                      _PERS.Bits.PERS3
#define PERS_PERS4                      _PERS.Bits.PERS4
#define PERS_PERS5                      _PERS.Bits.PERS5
#define PERS_PERS6                      _PERS.Bits.PERS6
#define PERS_PERS7                      _PERS.Bits.PERS7

#define PERS_PERS0_MASK                 1U
#define PERS_PERS1_MASK                 2U
#define PERS_PERS2_MASK                 4U
#define PERS_PERS3_MASK                 8U
#define PERS_PERS4_MASK                 16U
#define PERS_PERS5_MASK                 32U
#define PERS_PERS6_MASK                 64U
#define PERS_PERS7_MASK                 128U


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
    byte PPSS6       :1;                                       /* Port S pull device select bit 6 */
    byte PPSS7       :1;                                       /* Port S pull device select bit 7 */
  } Bits;
} PPSSSTR;
extern volatile PPSSSTR _PPSS @(REG_BASE + 0x0000024DUL);
#define PPSS                            _PPSS.Byte
#define PPSS_PPSS0                      _PPSS.Bits.PPSS0
#define PPSS_PPSS1                      _PPSS.Bits.PPSS1
#define PPSS_PPSS2                      _PPSS.Bits.PPSS2
#define PPSS_PPSS3                      _PPSS.Bits.PPSS3
#define PPSS_PPSS4                      _PPSS.Bits.PPSS4
#define PPSS_PPSS5                      _PPSS.Bits.PPSS5
#define PPSS_PPSS6                      _PPSS.Bits.PPSS6
#define PPSS_PPSS7                      _PPSS.Bits.PPSS7

#define PPSS_PPSS0_MASK                 1U
#define PPSS_PPSS1_MASK                 2U
#define PPSS_PPSS2_MASK                 4U
#define PPSS_PPSS3_MASK                 8U
#define PPSS_PPSS4_MASK                 16U
#define PPSS_PPSS5_MASK                 32U
#define PPSS_PPSS6_MASK                 64U
#define PPSS_PPSS7_MASK                 128U


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
    byte WOMS6       :1;                                       /* Port S wired-or mode bit 6 */
    byte WOMS7       :1;                                       /* Port S wired-or mode bit 7 */
  } Bits;
} WOMSSTR;
extern volatile WOMSSTR _WOMS @(REG_BASE + 0x0000024EUL);
#define WOMS                            _WOMS.Byte
#define WOMS_WOMS0                      _WOMS.Bits.WOMS0
#define WOMS_WOMS1                      _WOMS.Bits.WOMS1
#define WOMS_WOMS2                      _WOMS.Bits.WOMS2
#define WOMS_WOMS3                      _WOMS.Bits.WOMS3
#define WOMS_WOMS4                      _WOMS.Bits.WOMS4
#define WOMS_WOMS5                      _WOMS.Bits.WOMS5
#define WOMS_WOMS6                      _WOMS.Bits.WOMS6
#define WOMS_WOMS7                      _WOMS.Bits.WOMS7

#define WOMS_WOMS0_MASK                 1U
#define WOMS_WOMS1_MASK                 2U
#define WOMS_WOMS2_MASK                 4U
#define WOMS_WOMS3_MASK                 8U
#define WOMS_WOMS4_MASK                 16U
#define WOMS_WOMS5_MASK                 32U
#define WOMS_WOMS6_MASK                 64U
#define WOMS_WOMS7_MASK                 128U


/*** PRR0 - Pin Routing Register 0; 0x0000024F ***/
typedef union {
  byte Byte;
  struct {
    byte PRR0S0      :1;                                       /* Pin Routing Register Serial Module, bit 0 */
    byte PRR0S1      :1;                                       /* Pin Routing Register Serial Module, bit 1 */
    byte PRR0T20     :1;                                       /* Pin Routing Register IOC2, bit 0 */
    byte PRR0T21     :1;                                       /* Pin Routing Register IOC2, bit 1 */
    byte PRR0T30     :1;                                       /* Pin Routing Register IOC3, bit 0 */
    byte PRR0T31     :1;                                       /* Pin Routing Register IOC3, bit 1 */
    byte PRR0P2      :1;                                       /* Pin Routing Register PWM2 */
    byte PRR0P3      :1;                                       /* Pin Routing Register PWM3 */
  } Bits;
  struct {
    byte grpPRR0S :2;
    byte grpPRR0T_20 :2;
    byte grpPRR0T_30 :2;
    byte grpPRR0P_2 :2;
  } MergedBits;
} PRR0STR;
extern volatile PRR0STR _PRR0 @(REG_BASE + 0x0000024FUL);
#define PRR0                            _PRR0.Byte
#define PRR0_PRR0S0                     _PRR0.Bits.PRR0S0
#define PRR0_PRR0S1                     _PRR0.Bits.PRR0S1
#define PRR0_PRR0T20                    _PRR0.Bits.PRR0T20
#define PRR0_PRR0T21                    _PRR0.Bits.PRR0T21
#define PRR0_PRR0T30                    _PRR0.Bits.PRR0T30
#define PRR0_PRR0T31                    _PRR0.Bits.PRR0T31
#define PRR0_PRR0P2                     _PRR0.Bits.PRR0P2
#define PRR0_PRR0P3                     _PRR0.Bits.PRR0P3
#define PRR0_PRR0S                      _PRR0.MergedBits.grpPRR0S
#define PRR0_PRR0T_20                   _PRR0.MergedBits.grpPRR0T_20
#define PRR0_PRR0T_30                   _PRR0.MergedBits.grpPRR0T_30
#define PRR0_PRR0P_2                    _PRR0.MergedBits.grpPRR0P_2
#define PRR0_PRR0T                      PRR0_PRR0T_20
#define PRR0_PRR0P                      PRR0_PRR0P_2

#define PRR0_PRR0S0_MASK                1U
#define PRR0_PRR0S1_MASK                2U
#define PRR0_PRR0T20_MASK               4U
#define PRR0_PRR0T21_MASK               8U
#define PRR0_PRR0T30_MASK               16U
#define PRR0_PRR0T31_MASK               32U
#define PRR0_PRR0P2_MASK                64U
#define PRR0_PRR0P3_MASK                128U
#define PRR0_PRR0S_MASK                 3U
#define PRR0_PRR0S_BITNUM               0U
#define PRR0_PRR0T_20_MASK              12U
#define PRR0_PRR0T_20_BITNUM            2U
#define PRR0_PRR0T_30_MASK              48U
#define PRR0_PRR0T_30_BITNUM            4U
#define PRR0_PRR0P_2_MASK               192U
#define PRR0_PRR0P_2_BITNUM             6U


/*** PTM - Port M Data Register; 0x00000250 ***/
typedef union {
  byte Byte;
  struct {
    byte PTM0        :1;                                       /* Port M general purpose input/output data bit 0 */
    byte PTM1        :1;                                       /* Port M general purpose input/output data bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTM  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTMSTR;
extern volatile PTMSTR _PTM @(REG_BASE + 0x00000250UL);
#define PTM                             _PTM.Byte
#define PTM_PTM0                        _PTM.Bits.PTM0
#define PTM_PTM1                        _PTM.Bits.PTM1
#define PTM_PTM                         _PTM.MergedBits.grpPTM

#define PTM_PTM0_MASK                   1U
#define PTM_PTM1_MASK                   2U
#define PTM_PTM_MASK                    3U
#define PTM_PTM_BITNUM                  0U


/*** PTIM - Port M Input Register; 0x00000251 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIM0       :1;                                       /* Port M input data bit 0 */
    byte PTIM1       :1;                                       /* Port M input data bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTIM :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTIMSTR;
extern volatile PTIMSTR _PTIM @(REG_BASE + 0x00000251UL);
#define PTIM                            _PTIM.Byte
#define PTIM_PTIM0                      _PTIM.Bits.PTIM0
#define PTIM_PTIM1                      _PTIM.Bits.PTIM1
#define PTIM_PTIM                       _PTIM.MergedBits.grpPTIM

#define PTIM_PTIM0_MASK                 1U
#define PTIM_PTIM1_MASK                 2U
#define PTIM_PTIM_MASK                  3U
#define PTIM_PTIM_BITNUM                0U


/*** DDRM - Port M Data Direction Register; 0x00000252 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRM0       :1;                                       /* Port M data direction bit 0 */
    byte DDRM1       :1;                                       /* Port M data direction bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDDRM :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DDRMSTR;
extern volatile DDRMSTR _DDRM @(REG_BASE + 0x00000252UL);
#define DDRM                            _DDRM.Byte
#define DDRM_DDRM0                      _DDRM.Bits.DDRM0
#define DDRM_DDRM1                      _DDRM.Bits.DDRM1
#define DDRM_DDRM                       _DDRM.MergedBits.grpDDRM

#define DDRM_DDRM0_MASK                 1U
#define DDRM_DDRM1_MASK                 2U
#define DDRM_DDRM_MASK                  3U
#define DDRM_DDRM_BITNUM                0U


/*** PERM - Port M Pull Device Enable Register; 0x00000254 ***/
typedef union {
  byte Byte;
  struct {
    byte PERM0       :1;                                       /* Port M pull device enable bit 0 */
    byte PERM1       :1;                                       /* Port M pull device enable bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPERM :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PERMSTR;
extern volatile PERMSTR _PERM @(REG_BASE + 0x00000254UL);
#define PERM                            _PERM.Byte
#define PERM_PERM0                      _PERM.Bits.PERM0
#define PERM_PERM1                      _PERM.Bits.PERM1
#define PERM_PERM                       _PERM.MergedBits.grpPERM

#define PERM_PERM0_MASK                 1U
#define PERM_PERM1_MASK                 2U
#define PERM_PERM_MASK                  3U
#define PERM_PERM_BITNUM                0U


/*** PPSM - Port M Polarity Select Register; 0x00000255 ***/
typedef union {
  byte Byte;
  struct {
    byte PPSM0       :1;                                       /* Port M pull device select bit 0 */
    byte PPSM1       :1;                                       /* Port M pull device select bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPPSM :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPSMSTR;
extern volatile PPSMSTR _PPSM @(REG_BASE + 0x00000255UL);
#define PPSM                            _PPSM.Byte
#define PPSM_PPSM0                      _PPSM.Bits.PPSM0
#define PPSM_PPSM1                      _PPSM.Bits.PPSM1
#define PPSM_PPSM                       _PPSM.MergedBits.grpPPSM

#define PPSM_PPSM0_MASK                 1U
#define PPSM_PPSM1_MASK                 2U
#define PPSM_PPSM_MASK                  3U
#define PPSM_PPSM_BITNUM                0U


/*** WOMM - Port M Wired-Or Mode Register; 0x00000256 ***/
typedef union {
  byte Byte;
  struct {
    byte WOMM0       :1;                                       /* Port M wired-or mode bit 0 */
    byte WOMM1       :1;                                       /* Port M wired-or mode bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpWOMM :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} WOMMSTR;
extern volatile WOMMSTR _WOMM @(REG_BASE + 0x00000256UL);
#define WOMM                            _WOMM.Byte
#define WOMM_WOMM0                      _WOMM.Bits.WOMM0
#define WOMM_WOMM1                      _WOMM.Bits.WOMM1
#define WOMM_WOMM                       _WOMM.MergedBits.grpWOMM

#define WOMM_WOMM0_MASK                 1U
#define WOMM_WOMM1_MASK                 2U
#define WOMM_WOMM_MASK                  3U
#define WOMM_WOMM_BITNUM                0U


/*** PKGCR - Package Code Register; 0x00000257 ***/
typedef union {
  byte Byte;
  struct {
    byte PKGCR0      :1;                                       /* Package Code, bit 0 */
    byte PKGCR1      :1;                                       /* Package Code, bit 1 */
    byte PKGCR2      :1;                                       /* Package Code, bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte APICLKS7    :1;                                       /* Pin Routing Register API_EXTCLK */
  } Bits;
  struct {
    byte grpPKGCR :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpAPICLKS_7 :1;
  } MergedBits;
} PKGCRSTR;
extern volatile PKGCRSTR _PKGCR @(REG_BASE + 0x00000257UL);
#define PKGCR                           _PKGCR.Byte
#define PKGCR_PKGCR0                    _PKGCR.Bits.PKGCR0
#define PKGCR_PKGCR1                    _PKGCR.Bits.PKGCR1
#define PKGCR_PKGCR2                    _PKGCR.Bits.PKGCR2
#define PKGCR_APICLKS7                  _PKGCR.Bits.APICLKS7
#define PKGCR_PKGCR                     _PKGCR.MergedBits.grpPKGCR

#define PKGCR_PKGCR0_MASK               1U
#define PKGCR_PKGCR1_MASK               2U
#define PKGCR_PKGCR2_MASK               4U
#define PKGCR_APICLKS7_MASK             128U
#define PKGCR_PKGCR_MASK                7U
#define PKGCR_PKGCR_BITNUM              0U


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
    byte             :1; 
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
#define PIEP_PIEP                       _PIEP.MergedBits.grpPIEP

#define PIEP_PIEP0_MASK                 1U
#define PIEP_PIEP1_MASK                 2U
#define PIEP_PIEP2_MASK                 4U
#define PIEP_PIEP3_MASK                 8U
#define PIEP_PIEP4_MASK                 16U
#define PIEP_PIEP5_MASK                 32U
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
    byte             :1; 
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
#define PIFP_PIFP                       _PIFP.MergedBits.grpPIFP

#define PIFP_PIFP0_MASK                 1U
#define PIFP_PIFP1_MASK                 2U
#define PIFP_PIFP2_MASK                 4U
#define PIFP_PIFP3_MASK                 8U
#define PIFP_PIFP4_MASK                 16U
#define PIFP_PIFP5_MASK                 32U
#define PIFP_PIFP_MASK                  63U
#define PIFP_PIFP_BITNUM                0U


/*** ACMPC - ACMP control register; 0x00000260 ***/
typedef union {
  byte Byte;
  struct {
    byte ACE         :1;                                       /* Analog comparator enable */
    byte             :1; 
    byte ACMOD0      :1;                                       /* Analog comparator mode, bit 0 */
    byte ACMOD1      :1;                                       /* Analog comparator mode, bit 1 */
    byte ACDIEN      :1;                                       /* Analog comparator digital input buffer enable */
    byte ACICE       :1;                                       /* Analog comparator input capture enable */
    byte ACOPE       :1;                                       /* Analog comparator output pin enable */
    byte ACIE        :1;                                       /* Analog comparator interrupt enable */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpACMOD :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ACMPCSTR;
extern volatile ACMPCSTR _ACMPC @(REG_BASE + 0x00000260UL);
#define ACMPC                           _ACMPC.Byte
#define ACMPC_ACE                       _ACMPC.Bits.ACE
#define ACMPC_ACMOD0                    _ACMPC.Bits.ACMOD0
#define ACMPC_ACMOD1                    _ACMPC.Bits.ACMOD1
#define ACMPC_ACDIEN                    _ACMPC.Bits.ACDIEN
#define ACMPC_ACICE                     _ACMPC.Bits.ACICE
#define ACMPC_ACOPE                     _ACMPC.Bits.ACOPE
#define ACMPC_ACIE                      _ACMPC.Bits.ACIE
#define ACMPC_ACMOD                     _ACMPC.MergedBits.grpACMOD

#define ACMPC_ACE_MASK                  1U
#define ACMPC_ACMOD0_MASK               4U
#define ACMPC_ACMOD1_MASK               8U
#define ACMPC_ACDIEN_MASK               16U
#define ACMPC_ACICE_MASK                32U
#define ACMPC_ACOPE_MASK                64U
#define ACMPC_ACIE_MASK                 128U
#define ACMPC_ACMOD_MASK                12U
#define ACMPC_ACMOD_BITNUM              2U


/*** ACMPS - ACMP status register; 0x00000261 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ACO         :1;                                       /* Current value of the synchronized analog comparator output */
    byte ACIF        :1;                                       /* Analog comparator interrupt flag */
  } Bits;
} ACMPSSTR;
extern volatile ACMPSSTR _ACMPS @(REG_BASE + 0x00000261UL);
#define ACMPS                           _ACMPS.Byte
#define ACMPS_ACO                       _ACMPS.Bits.ACO
#define ACMPS_ACIF                      _ACMPS.Bits.ACIF

#define ACMPS_ACO_MASK                  64U
#define ACMPS_ACIF_MASK                 128U


/*** PTJ - Port J Data Register; 0x00000268 ***/
typedef union {
  byte Byte;
  struct {
    byte PTJ0        :1;                                       /* Port J general purpose input/output data bit 0 */
    byte PTJ1        :1;                                       /* Port J general purpose input/output data bit 1 */
    byte PTJ2        :1;                                       /* Port J general purpose input/output data bit 2 */
    byte PTJ3        :1;                                       /* Port J general purpose input/output data bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTJ  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTJSTR;
extern volatile PTJSTR _PTJ @(REG_BASE + 0x00000268UL);
#define PTJ                             _PTJ.Byte
#define PTJ_PTJ0                        _PTJ.Bits.PTJ0
#define PTJ_PTJ1                        _PTJ.Bits.PTJ1
#define PTJ_PTJ2                        _PTJ.Bits.PTJ2
#define PTJ_PTJ3                        _PTJ.Bits.PTJ3
#define PTJ_PTJ                         _PTJ.MergedBits.grpPTJ

#define PTJ_PTJ0_MASK                   1U
#define PTJ_PTJ1_MASK                   2U
#define PTJ_PTJ2_MASK                   4U
#define PTJ_PTJ3_MASK                   8U
#define PTJ_PTJ_MASK                    15U
#define PTJ_PTJ_BITNUM                  0U


/*** PTIJ - Port J Input Register; 0x00000269 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIJ0       :1;                                       /* Port J input data bit 0 */
    byte PTIJ1       :1;                                       /* Port J input data bit 1 */
    byte PTIJ2       :1;                                       /* Port J input data bit 2 */
    byte PTIJ3       :1;                                       /* Port J input data bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTIJ :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTIJSTR;
extern volatile PTIJSTR _PTIJ @(REG_BASE + 0x00000269UL);
#define PTIJ                            _PTIJ.Byte
#define PTIJ_PTIJ0                      _PTIJ.Bits.PTIJ0
#define PTIJ_PTIJ1                      _PTIJ.Bits.PTIJ1
#define PTIJ_PTIJ2                      _PTIJ.Bits.PTIJ2
#define PTIJ_PTIJ3                      _PTIJ.Bits.PTIJ3
#define PTIJ_PTIJ                       _PTIJ.MergedBits.grpPTIJ

#define PTIJ_PTIJ0_MASK                 1U
#define PTIJ_PTIJ1_MASK                 2U
#define PTIJ_PTIJ2_MASK                 4U
#define PTIJ_PTIJ3_MASK                 8U
#define PTIJ_PTIJ_MASK                  15U
#define PTIJ_PTIJ_BITNUM                0U


/*** DDRJ - Port J Data Direction Register; 0x0000026A ***/
typedef union {
  byte Byte;
  struct {
    byte DDRJ0       :1;                                       /* Port J data direction bit 0 */
    byte DDRJ1       :1;                                       /* Port J data direction bit 1 */
    byte DDRJ2       :1;                                       /* Port J data direction bit 2 */
    byte DDRJ3       :1;                                       /* Port J data direction bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDDRJ :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DDRJSTR;
extern volatile DDRJSTR _DDRJ @(REG_BASE + 0x0000026AUL);
#define DDRJ                            _DDRJ.Byte
#define DDRJ_DDRJ0                      _DDRJ.Bits.DDRJ0
#define DDRJ_DDRJ1                      _DDRJ.Bits.DDRJ1
#define DDRJ_DDRJ2                      _DDRJ.Bits.DDRJ2
#define DDRJ_DDRJ3                      _DDRJ.Bits.DDRJ3
#define DDRJ_DDRJ                       _DDRJ.MergedBits.grpDDRJ

#define DDRJ_DDRJ0_MASK                 1U
#define DDRJ_DDRJ1_MASK                 2U
#define DDRJ_DDRJ2_MASK                 4U
#define DDRJ_DDRJ3_MASK                 8U
#define DDRJ_DDRJ_MASK                  15U
#define DDRJ_DDRJ_BITNUM                0U


/*** PERJ - Port J Pull Device Enable Register; 0x0000026C ***/
typedef union {
  byte Byte;
  struct {
    byte PERJ0       :1;                                       /* Port J pull device enable bit 0 */
    byte PERJ1       :1;                                       /* Port J pull device enable bit 1 */
    byte PERJ2       :1;                                       /* Port J pull device enable bit 2 */
    byte PERJ3       :1;                                       /* Port J pull device enable bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPERJ :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PERJSTR;
extern volatile PERJSTR _PERJ @(REG_BASE + 0x0000026CUL);
#define PERJ                            _PERJ.Byte
#define PERJ_PERJ0                      _PERJ.Bits.PERJ0
#define PERJ_PERJ1                      _PERJ.Bits.PERJ1
#define PERJ_PERJ2                      _PERJ.Bits.PERJ2
#define PERJ_PERJ3                      _PERJ.Bits.PERJ3
#define PERJ_PERJ                       _PERJ.MergedBits.grpPERJ

#define PERJ_PERJ0_MASK                 1U
#define PERJ_PERJ1_MASK                 2U
#define PERJ_PERJ2_MASK                 4U
#define PERJ_PERJ3_MASK                 8U
#define PERJ_PERJ_MASK                  15U
#define PERJ_PERJ_BITNUM                0U


/*** PPSJ - Port J Polarity Select Register; 0x0000026D ***/
typedef union {
  byte Byte;
  struct {
    byte PPSJ0       :1;                                       /* Port J pull device select bit 0 */
    byte PPSJ1       :1;                                       /* Port J pull device select bit 1 */
    byte PPSJ2       :1;                                       /* Port J pull device select bit 2 */
    byte PPSJ3       :1;                                       /* Port J pull device select bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPPSJ :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPSJSTR;
extern volatile PPSJSTR _PPSJ @(REG_BASE + 0x0000026DUL);
#define PPSJ                            _PPSJ.Byte
#define PPSJ_PPSJ0                      _PPSJ.Bits.PPSJ0
#define PPSJ_PPSJ1                      _PPSJ.Bits.PPSJ1
#define PPSJ_PPSJ2                      _PPSJ.Bits.PPSJ2
#define PPSJ_PPSJ3                      _PPSJ.Bits.PPSJ3
#define PPSJ_PPSJ                       _PPSJ.MergedBits.grpPPSJ

#define PPSJ_PPSJ0_MASK                 1U
#define PPSJ_PPSJ1_MASK                 2U
#define PPSJ_PPSJ2_MASK                 4U
#define PPSJ_PPSJ3_MASK                 8U
#define PPSJ_PPSJ_MASK                  15U
#define PPSJ_PPSJ_BITNUM                0U


/*** PIEJ - Port J Interrupt Enable Register; 0x0000026E ***/
typedef union {
  byte Byte;
  struct {
    byte PIEJ0       :1;                                       /* Port J interrupt enable bit 0 */
    byte PIEJ1       :1;                                       /* Port J interrupt enable bit 1 */
    byte PIEJ2       :1;                                       /* Port J interrupt enable bit 2 */
    byte PIEJ3       :1;                                       /* Port J interrupt enable bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPIEJ :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PIEJSTR;
extern volatile PIEJSTR _PIEJ @(REG_BASE + 0x0000026EUL);
#define PIEJ                            _PIEJ.Byte
#define PIEJ_PIEJ0                      _PIEJ.Bits.PIEJ0
#define PIEJ_PIEJ1                      _PIEJ.Bits.PIEJ1
#define PIEJ_PIEJ2                      _PIEJ.Bits.PIEJ2
#define PIEJ_PIEJ3                      _PIEJ.Bits.PIEJ3
#define PIEJ_PIEJ                       _PIEJ.MergedBits.grpPIEJ

#define PIEJ_PIEJ0_MASK                 1U
#define PIEJ_PIEJ1_MASK                 2U
#define PIEJ_PIEJ2_MASK                 4U
#define PIEJ_PIEJ3_MASK                 8U
#define PIEJ_PIEJ_MASK                  15U
#define PIEJ_PIEJ_BITNUM                0U


/*** PIFJ - Port J Interrupt Flag Register; 0x0000026F ***/
typedef union {
  byte Byte;
  struct {
    byte PIFJ0       :1;                                       /* Port J interrupt flag bit 0 */
    byte PIFJ1       :1;                                       /* Port J interrupt flag bit 1 */
    byte PIFJ2       :1;                                       /* Port J interrupt flag bit 2 */
    byte PIFJ3       :1;                                       /* Port J interrupt flag bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPIFJ :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PIFJSTR;
extern volatile PIFJSTR _PIFJ @(REG_BASE + 0x0000026FUL);
#define PIFJ                            _PIFJ.Byte
#define PIFJ_PIFJ0                      _PIFJ.Bits.PIFJ0
#define PIFJ_PIFJ1                      _PIFJ.Bits.PIFJ1
#define PIFJ_PIFJ2                      _PIFJ.Bits.PIFJ2
#define PIFJ_PIFJ3                      _PIFJ.Bits.PIFJ3
#define PIFJ_PIFJ                       _PIFJ.MergedBits.grpPIFJ

#define PIFJ_PIFJ0_MASK                 1U
#define PIFJ_PIFJ1_MASK                 2U
#define PIFJ_PIFJ2_MASK                 4U
#define PIFJ_PIFJ3_MASK                 8U
#define PIFJ_PIFJ_MASK                  15U
#define PIFJ_PIFJ_BITNUM                0U


/*** PT01AD - Port AD Data Register; 0x00000270 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PT0AD - Port ADH Data Register; 0x00000270 ***/
    union {
      byte Byte;
      struct {
        byte PT0AD0      :1;                                       /* Port AD data bit 0 */
        byte PT0AD1      :1;                                       /* Port AD data bit 1 */
        byte PT0AD2      :1;                                       /* Port AD data bit 2 */
        byte PT0AD3      :1;                                       /* Port AD data bit 3 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpPT0AD :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } PT0ADSTR;
    #define PT0AD                       _PT01AD.Overlap_STR.PT0ADSTR.Byte
    #define PT0AD_PT0AD0                _PT01AD.Overlap_STR.PT0ADSTR.Bits.PT0AD0
    #define PT0AD_PT0AD1                _PT01AD.Overlap_STR.PT0ADSTR.Bits.PT0AD1
    #define PT0AD_PT0AD2                _PT01AD.Overlap_STR.PT0ADSTR.Bits.PT0AD2
    #define PT0AD_PT0AD3                _PT01AD.Overlap_STR.PT0ADSTR.Bits.PT0AD3
    #define PT0AD_PT0AD                 _PT01AD.Overlap_STR.PT0ADSTR.MergedBits.grpPT0AD
    
    #define PT0AD_PT0AD0_MASK           1U
    #define PT0AD_PT0AD1_MASK           2U
    #define PT0AD_PT0AD2_MASK           4U
    #define PT0AD_PT0AD3_MASK           8U
    #define PT0AD_PT0AD_MASK            15U
    #define PT0AD_PT0AD_BITNUM          0U
    

    /*** PT1AD - Port ADL Data Register; 0x00000271 ***/
    union {
      byte Byte;
      struct {
        byte PT1AD0      :1;                                       /* Port AD data bit 0 */
        byte PT1AD1      :1;                                       /* Port AD data bit 1 */
        byte PT1AD2      :1;                                       /* Port AD data bit 2 */
        byte PT1AD3      :1;                                       /* Port AD data bit 3 */
        byte PT1AD4      :1;                                       /* Port AD data bit 4 */
        byte PT1AD5      :1;                                       /* Port AD data bit 5 */
        byte PT1AD6      :1;                                       /* Port AD data bit 6 */
        byte PT1AD7      :1;                                       /* Port AD data bit 7 */
      } Bits;
    } PT1ADSTR;
    #define PT1AD                       _PT01AD.Overlap_STR.PT1ADSTR.Byte
    #define PT1AD_PT1AD0                _PT01AD.Overlap_STR.PT1ADSTR.Bits.PT1AD0
    #define PT1AD_PT1AD1                _PT01AD.Overlap_STR.PT1ADSTR.Bits.PT1AD1
    #define PT1AD_PT1AD2                _PT01AD.Overlap_STR.PT1ADSTR.Bits.PT1AD2
    #define PT1AD_PT1AD3                _PT01AD.Overlap_STR.PT1ADSTR.Bits.PT1AD3
    #define PT1AD_PT1AD4                _PT01AD.Overlap_STR.PT1ADSTR.Bits.PT1AD4
    #define PT1AD_PT1AD5                _PT01AD.Overlap_STR.PT1ADSTR.Bits.PT1AD5
    #define PT1AD_PT1AD6                _PT01AD.Overlap_STR.PT1ADSTR.Bits.PT1AD6
    #define PT1AD_PT1AD7                _PT01AD.Overlap_STR.PT1ADSTR.Bits.PT1AD7
    
    #define PT1AD_PT1AD0_MASK           1U
    #define PT1AD_PT1AD1_MASK           2U
    #define PT1AD_PT1AD2_MASK           4U
    #define PT1AD_PT1AD3_MASK           8U
    #define PT1AD_PT1AD4_MASK           16U
    #define PT1AD_PT1AD5_MASK           32U
    #define PT1AD_PT1AD6_MASK           64U
    #define PT1AD_PT1AD7_MASK           128U
    
  } Overlap_STR;

  struct {
    word PT1AD0      :1;                                       /* Port AD data bit 0 */
    word PT1AD1      :1;                                       /* Port AD data bit 1 */
    word PT1AD2      :1;                                       /* Port AD data bit 2 */
    word PT1AD3      :1;                                       /* Port AD data bit 3 */
    word PT1AD4      :1;                                       /* Port AD data bit 4 */
    word PT1AD5      :1;                                       /* Port AD data bit 5 */
    word PT1AD6      :1;                                       /* Port AD data bit 6 */
    word PT1AD7      :1;                                       /* Port AD data bit 7 */
    word PT0AD0      :1;                                       /* Port AD data bit 8 */
    word PT0AD1      :1;                                       /* Port AD data bit 9 */
    word PT0AD2      :1;                                       /* Port AD data bit 10 */
    word PT0AD3      :1;                                       /* Port AD data bit 11 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpPT1AD :8;
    word grpPT0AD :4;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} PT01ADSTR;
extern volatile PT01ADSTR _PT01AD @(REG_BASE + 0x00000270UL);
#define PT01AD                          _PT01AD.Word
#define PT01AD_PT1AD0                   _PT01AD.Bits.PT1AD0
#define PT01AD_PT1AD1                   _PT01AD.Bits.PT1AD1
#define PT01AD_PT1AD2                   _PT01AD.Bits.PT1AD2
#define PT01AD_PT1AD3                   _PT01AD.Bits.PT1AD3
#define PT01AD_PT1AD4                   _PT01AD.Bits.PT1AD4
#define PT01AD_PT1AD5                   _PT01AD.Bits.PT1AD5
#define PT01AD_PT1AD6                   _PT01AD.Bits.PT1AD6
#define PT01AD_PT1AD7                   _PT01AD.Bits.PT1AD7
#define PT01AD_PT0AD0                   _PT01AD.Bits.PT0AD0
#define PT01AD_PT0AD1                   _PT01AD.Bits.PT0AD1
#define PT01AD_PT0AD2                   _PT01AD.Bits.PT0AD2
#define PT01AD_PT0AD3                   _PT01AD.Bits.PT0AD3
#define PT01AD_PT1AD                    _PT01AD.MergedBits.grpPT1AD
#define PT01AD_PT0AD                    _PT01AD.MergedBits.grpPT0AD

#define PT01AD_PT1AD0_MASK              1U
#define PT01AD_PT1AD1_MASK              2U
#define PT01AD_PT1AD2_MASK              4U
#define PT01AD_PT1AD3_MASK              8U
#define PT01AD_PT1AD4_MASK              16U
#define PT01AD_PT1AD5_MASK              32U
#define PT01AD_PT1AD6_MASK              64U
#define PT01AD_PT1AD7_MASK              128U
#define PT01AD_PT0AD0_MASK              256U
#define PT01AD_PT0AD1_MASK              512U
#define PT01AD_PT0AD2_MASK              1024U
#define PT01AD_PT0AD3_MASK              2048U
#define PT01AD_PT1AD_MASK               255U
#define PT01AD_PT1AD_BITNUM             0U
#define PT01AD_PT0AD_MASK               3840U
#define PT01AD_PT0AD_BITNUM             8U


/*** PTI01AD - Port AD Input Register; 0x00000272 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PTI0AD - Port ADH Input Register; 0x00000272 ***/
    union {
      byte Byte;
      struct {
        byte PTI0AD0     :1;                                       /* Port ADH Bit 0 */
        byte PTI0AD1     :1;                                       /* Port ADH Bit 1 */
        byte PTI0AD2     :1;                                       /* Port ADH Bit 2 */
        byte PTI0AD3     :1;                                       /* Port ADH Bit 3 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpPTI0AD :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } PTI0ADSTR;
    #define PTI0AD                      _PTI01AD.Overlap_STR.PTI0ADSTR.Byte
    #define PTI0AD_PTI0AD0              _PTI01AD.Overlap_STR.PTI0ADSTR.Bits.PTI0AD0
    #define PTI0AD_PTI0AD1              _PTI01AD.Overlap_STR.PTI0ADSTR.Bits.PTI0AD1
    #define PTI0AD_PTI0AD2              _PTI01AD.Overlap_STR.PTI0ADSTR.Bits.PTI0AD2
    #define PTI0AD_PTI0AD3              _PTI01AD.Overlap_STR.PTI0ADSTR.Bits.PTI0AD3
    #define PTI0AD_PTI0AD               _PTI01AD.Overlap_STR.PTI0ADSTR.MergedBits.grpPTI0AD
    
    #define PTI0AD_PTI0AD0_MASK         1U
    #define PTI0AD_PTI0AD1_MASK         2U
    #define PTI0AD_PTI0AD2_MASK         4U
    #define PTI0AD_PTI0AD3_MASK         8U
    #define PTI0AD_PTI0AD_MASK          15U
    #define PTI0AD_PTI0AD_BITNUM        0U
    

    /*** PTI1AD - Port ADL Input Register; 0x00000273 ***/
    union {
      byte Byte;
      struct {
        byte PTI1AD0     :1;                                       /* Port ADL Bit 0 */
        byte PTI1AD1     :1;                                       /* Port ADL Bit 1 */
        byte PTI1AD2     :1;                                       /* Port ADL Bit 2 */
        byte PTI1AD3     :1;                                       /* Port ADL Bit 3 */
        byte PTI1AD4     :1;                                       /* Port ADL Bit 4 */
        byte PTI1AD5     :1;                                       /* Port ADL Bit 5 */
        byte PTI1AD6     :1;                                       /* Port ADL Bit 6 */
        byte PTI1AD7     :1;                                       /* Port ADL Bit 7 */
      } Bits;
    } PTI1ADSTR;
    #define PTI1AD                      _PTI01AD.Overlap_STR.PTI1ADSTR.Byte
    #define PTI1AD_PTI1AD0              _PTI01AD.Overlap_STR.PTI1ADSTR.Bits.PTI1AD0
    #define PTI1AD_PTI1AD1              _PTI01AD.Overlap_STR.PTI1ADSTR.Bits.PTI1AD1
    #define PTI1AD_PTI1AD2              _PTI01AD.Overlap_STR.PTI1ADSTR.Bits.PTI1AD2
    #define PTI1AD_PTI1AD3              _PTI01AD.Overlap_STR.PTI1ADSTR.Bits.PTI1AD3
    #define PTI1AD_PTI1AD4              _PTI01AD.Overlap_STR.PTI1ADSTR.Bits.PTI1AD4
    #define PTI1AD_PTI1AD5              _PTI01AD.Overlap_STR.PTI1ADSTR.Bits.PTI1AD5
    #define PTI1AD_PTI1AD6              _PTI01AD.Overlap_STR.PTI1ADSTR.Bits.PTI1AD6
    #define PTI1AD_PTI1AD7              _PTI01AD.Overlap_STR.PTI1ADSTR.Bits.PTI1AD7
    
    #define PTI1AD_PTI1AD0_MASK         1U
    #define PTI1AD_PTI1AD1_MASK         2U
    #define PTI1AD_PTI1AD2_MASK         4U
    #define PTI1AD_PTI1AD3_MASK         8U
    #define PTI1AD_PTI1AD4_MASK         16U
    #define PTI1AD_PTI1AD5_MASK         32U
    #define PTI1AD_PTI1AD6_MASK         64U
    #define PTI1AD_PTI1AD7_MASK         128U
    
  } Overlap_STR;

  struct {
    word PTI1AD0     :1;                                       /* Port AD Bit 0 */
    word PTI1AD1     :1;                                       /* Port AD Bit 1 */
    word PTI1AD2     :1;                                       /* Port AD Bit 2 */
    word PTI1AD3     :1;                                       /* Port AD Bit 3 */
    word PTI1AD4     :1;                                       /* Port AD Bit 4 */
    word PTI1AD5     :1;                                       /* Port AD Bit 5 */
    word PTI1AD6     :1;                                       /* Port AD Bit 6 */
    word PTI1AD7     :1;                                       /* Port AD Bit 7 */
    word PTI0AD0     :1;                                       /* Port AD Bit 0 */
    word PTI0AD1     :1;                                       /* Port AD Bit 1 */
    word PTI0AD2     :1;                                       /* Port AD Bit 2 */
    word PTI0AD3     :1;                                       /* Port AD Bit 3 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpPTI1AD :8;
    word grpPTI0AD :4;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} PTI01ADSTR;
extern volatile PTI01ADSTR _PTI01AD @(REG_BASE + 0x00000272UL);
#define PTI01AD                         _PTI01AD.Word
#define PTI01AD_PTI1AD0                 _PTI01AD.Bits.PTI1AD0
#define PTI01AD_PTI1AD1                 _PTI01AD.Bits.PTI1AD1
#define PTI01AD_PTI1AD2                 _PTI01AD.Bits.PTI1AD2
#define PTI01AD_PTI1AD3                 _PTI01AD.Bits.PTI1AD3
#define PTI01AD_PTI1AD4                 _PTI01AD.Bits.PTI1AD4
#define PTI01AD_PTI1AD5                 _PTI01AD.Bits.PTI1AD5
#define PTI01AD_PTI1AD6                 _PTI01AD.Bits.PTI1AD6
#define PTI01AD_PTI1AD7                 _PTI01AD.Bits.PTI1AD7
#define PTI01AD_PTI0AD0                 _PTI01AD.Bits.PTI0AD0
#define PTI01AD_PTI0AD1                 _PTI01AD.Bits.PTI0AD1
#define PTI01AD_PTI0AD2                 _PTI01AD.Bits.PTI0AD2
#define PTI01AD_PTI0AD3                 _PTI01AD.Bits.PTI0AD3
#define PTI01AD_PTI1AD                  _PTI01AD.MergedBits.grpPTI1AD
#define PTI01AD_PTI0AD                  _PTI01AD.MergedBits.grpPTI0AD

#define PTI01AD_PTI1AD0_MASK            1U
#define PTI01AD_PTI1AD1_MASK            2U
#define PTI01AD_PTI1AD2_MASK            4U
#define PTI01AD_PTI1AD3_MASK            8U
#define PTI01AD_PTI1AD4_MASK            16U
#define PTI01AD_PTI1AD5_MASK            32U
#define PTI01AD_PTI1AD6_MASK            64U
#define PTI01AD_PTI1AD7_MASK            128U
#define PTI01AD_PTI0AD0_MASK            256U
#define PTI01AD_PTI0AD1_MASK            512U
#define PTI01AD_PTI0AD2_MASK            1024U
#define PTI01AD_PTI0AD3_MASK            2048U
#define PTI01AD_PTI1AD_MASK             255U
#define PTI01AD_PTI1AD_BITNUM           0U
#define PTI01AD_PTI0AD_MASK             3840U
#define PTI01AD_PTI0AD_BITNUM           8U


/*** DDR01AD - Port AD Data Direction Register; 0x00000274 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DDR0AD - Port ADH Data Direction Register; 0x00000274 ***/
    union {
      byte Byte;
      struct {
        byte DDR0AD0     :1;                                       /* Port AD data direction bit 0 */
        byte DDR0AD1     :1;                                       /* Port AD data direction bit 1 */
        byte DDR0AD2     :1;                                       /* Port AD data direction bit 2 */
        byte DDR0AD3     :1;                                       /* Port AD data direction bit 3 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpDDR0AD :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DDR0ADSTR;
    #define DDR0AD                      _DDR01AD.Overlap_STR.DDR0ADSTR.Byte
    #define DDR0AD_DDR0AD0              _DDR01AD.Overlap_STR.DDR0ADSTR.Bits.DDR0AD0
    #define DDR0AD_DDR0AD1              _DDR01AD.Overlap_STR.DDR0ADSTR.Bits.DDR0AD1
    #define DDR0AD_DDR0AD2              _DDR01AD.Overlap_STR.DDR0ADSTR.Bits.DDR0AD2
    #define DDR0AD_DDR0AD3              _DDR01AD.Overlap_STR.DDR0ADSTR.Bits.DDR0AD3
    #define DDR0AD_DDR0AD               _DDR01AD.Overlap_STR.DDR0ADSTR.MergedBits.grpDDR0AD
    
    #define DDR0AD_DDR0AD0_MASK         1U
    #define DDR0AD_DDR0AD1_MASK         2U
    #define DDR0AD_DDR0AD2_MASK         4U
    #define DDR0AD_DDR0AD3_MASK         8U
    #define DDR0AD_DDR0AD_MASK          15U
    #define DDR0AD_DDR0AD_BITNUM        0U
    

    /*** DDR1AD - Port ADL Data Direction Register; 0x00000275 ***/
    union {
      byte Byte;
      struct {
        byte DDR1AD0     :1;                                       /* Port AD data direction bit 0 */
        byte DDR1AD1     :1;                                       /* Port AD data direction bit 1 */
        byte DDR1AD2     :1;                                       /* Port AD data direction bit 2 */
        byte DDR1AD3     :1;                                       /* Port AD data direction bit 3 */
        byte DDR1AD4     :1;                                       /* Port AD data direction bit 4 */
        byte DDR1AD5     :1;                                       /* Port AD data direction bit 5 */
        byte DDR1AD6     :1;                                       /* Port AD data direction bit 6 */
        byte DDR1AD7     :1;                                       /* Port AD data direction bit 7 */
      } Bits;
    } DDR1ADSTR;
    #define DDR1AD                      _DDR01AD.Overlap_STR.DDR1ADSTR.Byte
    #define DDR1AD_DDR1AD0              _DDR01AD.Overlap_STR.DDR1ADSTR.Bits.DDR1AD0
    #define DDR1AD_DDR1AD1              _DDR01AD.Overlap_STR.DDR1ADSTR.Bits.DDR1AD1
    #define DDR1AD_DDR1AD2              _DDR01AD.Overlap_STR.DDR1ADSTR.Bits.DDR1AD2
    #define DDR1AD_DDR1AD3              _DDR01AD.Overlap_STR.DDR1ADSTR.Bits.DDR1AD3
    #define DDR1AD_DDR1AD4              _DDR01AD.Overlap_STR.DDR1ADSTR.Bits.DDR1AD4
    #define DDR1AD_DDR1AD5              _DDR01AD.Overlap_STR.DDR1ADSTR.Bits.DDR1AD5
    #define DDR1AD_DDR1AD6              _DDR01AD.Overlap_STR.DDR1ADSTR.Bits.DDR1AD6
    #define DDR1AD_DDR1AD7              _DDR01AD.Overlap_STR.DDR1ADSTR.Bits.DDR1AD7
    
    #define DDR1AD_DDR1AD0_MASK         1U
    #define DDR1AD_DDR1AD1_MASK         2U
    #define DDR1AD_DDR1AD2_MASK         4U
    #define DDR1AD_DDR1AD3_MASK         8U
    #define DDR1AD_DDR1AD4_MASK         16U
    #define DDR1AD_DDR1AD5_MASK         32U
    #define DDR1AD_DDR1AD6_MASK         64U
    #define DDR1AD_DDR1AD7_MASK         128U
    
  } Overlap_STR;

  struct {
    word DDR1AD0     :1;                                       /* Port AD data direction bit 0 */
    word DDR1AD1     :1;                                       /* Port AD data direction bit 1 */
    word DDR1AD2     :1;                                       /* Port AD data direction bit 2 */
    word DDR1AD3     :1;                                       /* Port AD data direction bit 3 */
    word DDR1AD4     :1;                                       /* Port AD data direction bit 4 */
    word DDR1AD5     :1;                                       /* Port AD data direction bit 5 */
    word DDR1AD6     :1;                                       /* Port AD data direction bit 6 */
    word DDR1AD7     :1;                                       /* Port AD data direction bit 7 */
    word DDR0AD0     :1;                                       /* Port AD data direction bit 8 */
    word DDR0AD1     :1;                                       /* Port AD data direction bit 9 */
    word DDR0AD2     :1;                                       /* Port AD data direction bit 10 */
    word DDR0AD3     :1;                                       /* Port AD data direction bit 11 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpDDR1AD :8;
    word grpDDR0AD :4;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} DDR01ADSTR;
extern volatile DDR01ADSTR _DDR01AD @(REG_BASE + 0x00000274UL);
#define DDR01AD                         _DDR01AD.Word
#define DDR01AD_DDR1AD0                 _DDR01AD.Bits.DDR1AD0
#define DDR01AD_DDR1AD1                 _DDR01AD.Bits.DDR1AD1
#define DDR01AD_DDR1AD2                 _DDR01AD.Bits.DDR1AD2
#define DDR01AD_DDR1AD3                 _DDR01AD.Bits.DDR1AD3
#define DDR01AD_DDR1AD4                 _DDR01AD.Bits.DDR1AD4
#define DDR01AD_DDR1AD5                 _DDR01AD.Bits.DDR1AD5
#define DDR01AD_DDR1AD6                 _DDR01AD.Bits.DDR1AD6
#define DDR01AD_DDR1AD7                 _DDR01AD.Bits.DDR1AD7
#define DDR01AD_DDR0AD0                 _DDR01AD.Bits.DDR0AD0
#define DDR01AD_DDR0AD1                 _DDR01AD.Bits.DDR0AD1
#define DDR01AD_DDR0AD2                 _DDR01AD.Bits.DDR0AD2
#define DDR01AD_DDR0AD3                 _DDR01AD.Bits.DDR0AD3
#define DDR01AD_DDR1AD                  _DDR01AD.MergedBits.grpDDR1AD
#define DDR01AD_DDR0AD                  _DDR01AD.MergedBits.grpDDR0AD

#define DDR01AD_DDR1AD0_MASK            1U
#define DDR01AD_DDR1AD1_MASK            2U
#define DDR01AD_DDR1AD2_MASK            4U
#define DDR01AD_DDR1AD3_MASK            8U
#define DDR01AD_DDR1AD4_MASK            16U
#define DDR01AD_DDR1AD5_MASK            32U
#define DDR01AD_DDR1AD6_MASK            64U
#define DDR01AD_DDR1AD7_MASK            128U
#define DDR01AD_DDR0AD0_MASK            256U
#define DDR01AD_DDR0AD1_MASK            512U
#define DDR01AD_DDR0AD2_MASK            1024U
#define DDR01AD_DDR0AD3_MASK            2048U
#define DDR01AD_DDR1AD_MASK             255U
#define DDR01AD_DDR1AD_BITNUM           0U
#define DDR01AD_DDR0AD_MASK             3840U
#define DDR01AD_DDR0AD_BITNUM           8U


/*** PER01AD - Port AD Pull Up Enable Register; 0x00000278 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PER0AD - Port ADH Pull Up Enable Register; 0x00000278 ***/
    union {
      byte Byte;
      struct {
        byte PER0AD0     :1;                                       /* Port ADH pull up enable bit 0 */
        byte PER0AD1     :1;                                       /* Port ADH pull up enable bit 1 */
        byte PER0AD2     :1;                                       /* Port ADH pull up enable bit 2 */
        byte PER0AD3     :1;                                       /* Port ADH pull up enable bit 3 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpPER0AD :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } PER0ADSTR;
    #define PER0AD                      _PER01AD.Overlap_STR.PER0ADSTR.Byte
    #define PER0AD_PER0AD0              _PER01AD.Overlap_STR.PER0ADSTR.Bits.PER0AD0
    #define PER0AD_PER0AD1              _PER01AD.Overlap_STR.PER0ADSTR.Bits.PER0AD1
    #define PER0AD_PER0AD2              _PER01AD.Overlap_STR.PER0ADSTR.Bits.PER0AD2
    #define PER0AD_PER0AD3              _PER01AD.Overlap_STR.PER0ADSTR.Bits.PER0AD3
    #define PER0AD_PER0AD               _PER01AD.Overlap_STR.PER0ADSTR.MergedBits.grpPER0AD
    
    #define PER0AD_PER0AD0_MASK         1U
    #define PER0AD_PER0AD1_MASK         2U
    #define PER0AD_PER0AD2_MASK         4U
    #define PER0AD_PER0AD3_MASK         8U
    #define PER0AD_PER0AD_MASK          15U
    #define PER0AD_PER0AD_BITNUM        0U
    

    /*** PER1AD - Port ADL Pull Up Enable Register; 0x00000279 ***/
    union {
      byte Byte;
      struct {
        byte PER1AD0     :1;                                       /* Port ADL pull up enable bit 0 */
        byte PER1AD1     :1;                                       /* Port ADL pull up enable bit 1 */
        byte PER1AD2     :1;                                       /* Port ADL pull up enable bit 2 */
        byte PER1AD3     :1;                                       /* Port ADL pull up enable bit 3 */
        byte PER1AD4     :1;                                       /* Port ADL pull up enable bit 4 */
        byte PER1AD5     :1;                                       /* Port ADL pull up enable bit 5 */
        byte PER1AD6     :1;                                       /* Port ADL pull up enable bit 6 */
        byte PER1AD7     :1;                                       /* Port ADL pull up enable bit 7 */
      } Bits;
    } PER1ADSTR;
    #define PER1AD                      _PER01AD.Overlap_STR.PER1ADSTR.Byte
    #define PER1AD_PER1AD0              _PER01AD.Overlap_STR.PER1ADSTR.Bits.PER1AD0
    #define PER1AD_PER1AD1              _PER01AD.Overlap_STR.PER1ADSTR.Bits.PER1AD1
    #define PER1AD_PER1AD2              _PER01AD.Overlap_STR.PER1ADSTR.Bits.PER1AD2
    #define PER1AD_PER1AD3              _PER01AD.Overlap_STR.PER1ADSTR.Bits.PER1AD3
    #define PER1AD_PER1AD4              _PER01AD.Overlap_STR.PER1ADSTR.Bits.PER1AD4
    #define PER1AD_PER1AD5              _PER01AD.Overlap_STR.PER1ADSTR.Bits.PER1AD5
    #define PER1AD_PER1AD6              _PER01AD.Overlap_STR.PER1ADSTR.Bits.PER1AD6
    #define PER1AD_PER1AD7              _PER01AD.Overlap_STR.PER1ADSTR.Bits.PER1AD7
    
    #define PER1AD_PER1AD0_MASK         1U
    #define PER1AD_PER1AD1_MASK         2U
    #define PER1AD_PER1AD2_MASK         4U
    #define PER1AD_PER1AD3_MASK         8U
    #define PER1AD_PER1AD4_MASK         16U
    #define PER1AD_PER1AD5_MASK         32U
    #define PER1AD_PER1AD6_MASK         64U
    #define PER1AD_PER1AD7_MASK         128U
    
  } Overlap_STR;

  struct {
    word PER1AD0     :1;                                       /* Port AD pull up enable bit 0 */
    word PER1AD1     :1;                                       /* Port AD pull up enable bit 1 */
    word PER1AD2     :1;                                       /* Port AD pull up enable bit 2 */
    word PER1AD3     :1;                                       /* Port AD pull up enable bit 3 */
    word PER1AD4     :1;                                       /* Port AD pull up enable bit 4 */
    word PER1AD5     :1;                                       /* Port AD pull up enable bit 5 */
    word PER1AD6     :1;                                       /* Port AD pull up enable bit 6 */
    word PER1AD7     :1;                                       /* Port AD pull up enable bit 7 */
    word PER0AD0     :1;                                       /* Port AD pull up enable bit 8 */
    word PER0AD1     :1;                                       /* Port AD pull up enable bit 9 */
    word PER0AD2     :1;                                       /* Port AD pull up enable bit 10 */
    word PER0AD3     :1;                                       /* Port AD pull up enable bit 11 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpPER1AD :8;
    word grpPER0AD :4;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} PER01ADSTR;
extern volatile PER01ADSTR _PER01AD @(REG_BASE + 0x00000278UL);
#define PER01AD                         _PER01AD.Word
#define PER01AD_PER1AD0                 _PER01AD.Bits.PER1AD0
#define PER01AD_PER1AD1                 _PER01AD.Bits.PER1AD1
#define PER01AD_PER1AD2                 _PER01AD.Bits.PER1AD2
#define PER01AD_PER1AD3                 _PER01AD.Bits.PER1AD3
#define PER01AD_PER1AD4                 _PER01AD.Bits.PER1AD4
#define PER01AD_PER1AD5                 _PER01AD.Bits.PER1AD5
#define PER01AD_PER1AD6                 _PER01AD.Bits.PER1AD6
#define PER01AD_PER1AD7                 _PER01AD.Bits.PER1AD7
#define PER01AD_PER0AD0                 _PER01AD.Bits.PER0AD0
#define PER01AD_PER0AD1                 _PER01AD.Bits.PER0AD1
#define PER01AD_PER0AD2                 _PER01AD.Bits.PER0AD2
#define PER01AD_PER0AD3                 _PER01AD.Bits.PER0AD3
#define PER01AD_PER1AD                  _PER01AD.MergedBits.grpPER1AD
#define PER01AD_PER0AD                  _PER01AD.MergedBits.grpPER0AD

#define PER01AD_PER1AD0_MASK            1U
#define PER01AD_PER1AD1_MASK            2U
#define PER01AD_PER1AD2_MASK            4U
#define PER01AD_PER1AD3_MASK            8U
#define PER01AD_PER1AD4_MASK            16U
#define PER01AD_PER1AD5_MASK            32U
#define PER01AD_PER1AD6_MASK            64U
#define PER01AD_PER1AD7_MASK            128U
#define PER01AD_PER0AD0_MASK            256U
#define PER01AD_PER0AD1_MASK            512U
#define PER01AD_PER0AD2_MASK            1024U
#define PER01AD_PER0AD3_MASK            2048U
#define PER01AD_PER1AD_MASK             255U
#define PER01AD_PER1AD_BITNUM           0U
#define PER01AD_PER0AD_MASK             3840U
#define PER01AD_PER0AD_BITNUM           8U


/*** PPS01AD - Port AD Polarity Select Register; 0x0000027A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PPS0AD - Port ADH Polarity Select Register; 0x0000027A ***/
    union {
      byte Byte;
      struct {
        byte PPS0AD0     :1;                                       /* Port ADH Polarity Select Bit 0 */
        byte PPS0AD1     :1;                                       /* Port ADH Polarity Select Bit 1 */
        byte PPS0AD2     :1;                                       /* Port ADH Polarity Select Bit 2 */
        byte PPS0AD3     :1;                                       /* Port ADH Polarity Select Bit 3 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpPPS0AD :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } PPS0ADSTR;
    #define PPS0AD                      _PPS01AD.Overlap_STR.PPS0ADSTR.Byte
    #define PPS0AD_PPS0AD0              _PPS01AD.Overlap_STR.PPS0ADSTR.Bits.PPS0AD0
    #define PPS0AD_PPS0AD1              _PPS01AD.Overlap_STR.PPS0ADSTR.Bits.PPS0AD1
    #define PPS0AD_PPS0AD2              _PPS01AD.Overlap_STR.PPS0ADSTR.Bits.PPS0AD2
    #define PPS0AD_PPS0AD3              _PPS01AD.Overlap_STR.PPS0ADSTR.Bits.PPS0AD3
    #define PPS0AD_PPS0AD               _PPS01AD.Overlap_STR.PPS0ADSTR.MergedBits.grpPPS0AD
    
    #define PPS0AD_PPS0AD0_MASK         1U
    #define PPS0AD_PPS0AD1_MASK         2U
    #define PPS0AD_PPS0AD2_MASK         4U
    #define PPS0AD_PPS0AD3_MASK         8U
    #define PPS0AD_PPS0AD_MASK          15U
    #define PPS0AD_PPS0AD_BITNUM        0U
    

    /*** PPS1AD - Port ADL Polarity Select Register; 0x0000027B ***/
    union {
      byte Byte;
      struct {
        byte PPS1AD0     :1;                                       /* Port ADL Polarity Select Bit 0 */
        byte PPS1AD1     :1;                                       /* Port ADL Polarity Select Bit 1 */
        byte PPS1AD2     :1;                                       /* Port ADL Polarity Select Bit 2 */
        byte PPS1AD3     :1;                                       /* Port ADL Polarity Select Bit 3 */
        byte PPS1AD4     :1;                                       /* Port ADL Polarity Select Bit 4 */
        byte PPS1AD5     :1;                                       /* Port ADL Polarity Select Bit 5 */
        byte PPS1AD6     :1;                                       /* Port ADL Polarity Select Bit 6 */
        byte PPS1AD7     :1;                                       /* Port ADL Polarity Select Bit 7 */
      } Bits;
    } PPS1ADSTR;
    #define PPS1AD                      _PPS01AD.Overlap_STR.PPS1ADSTR.Byte
    #define PPS1AD_PPS1AD0              _PPS01AD.Overlap_STR.PPS1ADSTR.Bits.PPS1AD0
    #define PPS1AD_PPS1AD1              _PPS01AD.Overlap_STR.PPS1ADSTR.Bits.PPS1AD1
    #define PPS1AD_PPS1AD2              _PPS01AD.Overlap_STR.PPS1ADSTR.Bits.PPS1AD2
    #define PPS1AD_PPS1AD3              _PPS01AD.Overlap_STR.PPS1ADSTR.Bits.PPS1AD3
    #define PPS1AD_PPS1AD4              _PPS01AD.Overlap_STR.PPS1ADSTR.Bits.PPS1AD4
    #define PPS1AD_PPS1AD5              _PPS01AD.Overlap_STR.PPS1ADSTR.Bits.PPS1AD5
    #define PPS1AD_PPS1AD6              _PPS01AD.Overlap_STR.PPS1ADSTR.Bits.PPS1AD6
    #define PPS1AD_PPS1AD7              _PPS01AD.Overlap_STR.PPS1ADSTR.Bits.PPS1AD7
    
    #define PPS1AD_PPS1AD0_MASK         1U
    #define PPS1AD_PPS1AD1_MASK         2U
    #define PPS1AD_PPS1AD2_MASK         4U
    #define PPS1AD_PPS1AD3_MASK         8U
    #define PPS1AD_PPS1AD4_MASK         16U
    #define PPS1AD_PPS1AD5_MASK         32U
    #define PPS1AD_PPS1AD6_MASK         64U
    #define PPS1AD_PPS1AD7_MASK         128U
    
  } Overlap_STR;

  struct {
    word PPS1AD0     :1;                                       /* Port AD Polarity Select Bit 0 */
    word PPS1AD1     :1;                                       /* Port AD Polarity Select Bit 1 */
    word PPS1AD2     :1;                                       /* Port AD Polarity Select Bit 2 */
    word PPS1AD3     :1;                                       /* Port AD Polarity Select Bit 3 */
    word PPS1AD4     :1;                                       /* Port AD Polarity Select Bit 4 */
    word PPS1AD5     :1;                                       /* Port AD Polarity Select Bit 5 */
    word PPS1AD6     :1;                                       /* Port AD Polarity Select Bit 6 */
    word PPS1AD7     :1;                                       /* Port AD Polarity Select Bit 7 */
    word PPS0AD0     :1;                                       /* Port AD Polarity Select Bit 0 */
    word PPS0AD1     :1;                                       /* Port AD Polarity Select Bit 1 */
    word PPS0AD2     :1;                                       /* Port AD Polarity Select Bit 2 */
    word PPS0AD3     :1;                                       /* Port AD Polarity Select Bit 3 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpPPS1AD :8;
    word grpPPS0AD :4;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} PPS01ADSTR;
extern volatile PPS01ADSTR _PPS01AD @(REG_BASE + 0x0000027AUL);
#define PPS01AD                         _PPS01AD.Word
#define PPS01AD_PPS1AD0                 _PPS01AD.Bits.PPS1AD0
#define PPS01AD_PPS1AD1                 _PPS01AD.Bits.PPS1AD1
#define PPS01AD_PPS1AD2                 _PPS01AD.Bits.PPS1AD2
#define PPS01AD_PPS1AD3                 _PPS01AD.Bits.PPS1AD3
#define PPS01AD_PPS1AD4                 _PPS01AD.Bits.PPS1AD4
#define PPS01AD_PPS1AD5                 _PPS01AD.Bits.PPS1AD5
#define PPS01AD_PPS1AD6                 _PPS01AD.Bits.PPS1AD6
#define PPS01AD_PPS1AD7                 _PPS01AD.Bits.PPS1AD7
#define PPS01AD_PPS0AD0                 _PPS01AD.Bits.PPS0AD0
#define PPS01AD_PPS0AD1                 _PPS01AD.Bits.PPS0AD1
#define PPS01AD_PPS0AD2                 _PPS01AD.Bits.PPS0AD2
#define PPS01AD_PPS0AD3                 _PPS01AD.Bits.PPS0AD3
#define PPS01AD_PPS1AD                  _PPS01AD.MergedBits.grpPPS1AD
#define PPS01AD_PPS0AD                  _PPS01AD.MergedBits.grpPPS0AD

#define PPS01AD_PPS1AD0_MASK            1U
#define PPS01AD_PPS1AD1_MASK            2U
#define PPS01AD_PPS1AD2_MASK            4U
#define PPS01AD_PPS1AD3_MASK            8U
#define PPS01AD_PPS1AD4_MASK            16U
#define PPS01AD_PPS1AD5_MASK            32U
#define PPS01AD_PPS1AD6_MASK            64U
#define PPS01AD_PPS1AD7_MASK            128U
#define PPS01AD_PPS0AD0_MASK            256U
#define PPS01AD_PPS0AD1_MASK            512U
#define PPS01AD_PPS0AD2_MASK            1024U
#define PPS01AD_PPS0AD3_MASK            2048U
#define PPS01AD_PPS1AD_MASK             255U
#define PPS01AD_PPS1AD_BITNUM           0U
#define PPS01AD_PPS0AD_MASK             3840U
#define PPS01AD_PPS0AD_BITNUM           8U


/*** PIE01AD - Port AD Interrupt Enable Register; 0x0000027C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PIE0AD - Port ADH Interrupt Enable Register; 0x0000027C ***/
    union {
      byte Byte;
      struct {
        byte PIE0AD0     :1;                                       /* Port ADH Interrupt Enable Bit 0 */
        byte PIE0AD1     :1;                                       /* Port ADH Interrupt Enable Bit 1 */
        byte PIE0AD2     :1;                                       /* Port ADH Interrupt Enable Bit 2 */
        byte PIE0AD3     :1;                                       /* Port ADH Interrupt Enable Bit 3 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpPIE0AD :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } PIE0ADSTR;
    #define PIE0AD                      _PIE01AD.Overlap_STR.PIE0ADSTR.Byte
    #define PIE0AD_PIE0AD0              _PIE01AD.Overlap_STR.PIE0ADSTR.Bits.PIE0AD0
    #define PIE0AD_PIE0AD1              _PIE01AD.Overlap_STR.PIE0ADSTR.Bits.PIE0AD1
    #define PIE0AD_PIE0AD2              _PIE01AD.Overlap_STR.PIE0ADSTR.Bits.PIE0AD2
    #define PIE0AD_PIE0AD3              _PIE01AD.Overlap_STR.PIE0ADSTR.Bits.PIE0AD3
    #define PIE0AD_PIE0AD               _PIE01AD.Overlap_STR.PIE0ADSTR.MergedBits.grpPIE0AD
    
    #define PIE0AD_PIE0AD0_MASK         1U
    #define PIE0AD_PIE0AD1_MASK         2U
    #define PIE0AD_PIE0AD2_MASK         4U
    #define PIE0AD_PIE0AD3_MASK         8U
    #define PIE0AD_PIE0AD_MASK          15U
    #define PIE0AD_PIE0AD_BITNUM        0U
    

    /*** PIE1AD - Port ADL Interrupt Enable Register; 0x0000027D ***/
    union {
      byte Byte;
      struct {
        byte PIE1AD0     :1;                                       /* Port ADL Interrupt Enable Bit 0 */
        byte PIE1AD1     :1;                                       /* Port ADL Interrupt Enable Bit 1 */
        byte PIE1AD2     :1;                                       /* Port ADL Interrupt Enable Bit 2 */
        byte PIE1AD3     :1;                                       /* Port ADL Interrupt Enable Bit 3 */
        byte PIE1AD4     :1;                                       /* Port ADL Interrupt Enable Bit 4 */
        byte PIE1AD5     :1;                                       /* Port ADL Interrupt Enable Bit 5 */
        byte PIE1AD6     :1;                                       /* Port ADL Interrupt Enable Bit 6 */
        byte PIE1AD7     :1;                                       /* Port ADL Interrupt Enable Bit 7 */
      } Bits;
    } PIE1ADSTR;
    #define PIE1AD                      _PIE01AD.Overlap_STR.PIE1ADSTR.Byte
    #define PIE1AD_PIE1AD0              _PIE01AD.Overlap_STR.PIE1ADSTR.Bits.PIE1AD0
    #define PIE1AD_PIE1AD1              _PIE01AD.Overlap_STR.PIE1ADSTR.Bits.PIE1AD1
    #define PIE1AD_PIE1AD2              _PIE01AD.Overlap_STR.PIE1ADSTR.Bits.PIE1AD2
    #define PIE1AD_PIE1AD3              _PIE01AD.Overlap_STR.PIE1ADSTR.Bits.PIE1AD3
    #define PIE1AD_PIE1AD4              _PIE01AD.Overlap_STR.PIE1ADSTR.Bits.PIE1AD4
    #define PIE1AD_PIE1AD5              _PIE01AD.Overlap_STR.PIE1ADSTR.Bits.PIE1AD5
    #define PIE1AD_PIE1AD6              _PIE01AD.Overlap_STR.PIE1ADSTR.Bits.PIE1AD6
    #define PIE1AD_PIE1AD7              _PIE01AD.Overlap_STR.PIE1ADSTR.Bits.PIE1AD7
    
    #define PIE1AD_PIE1AD0_MASK         1U
    #define PIE1AD_PIE1AD1_MASK         2U
    #define PIE1AD_PIE1AD2_MASK         4U
    #define PIE1AD_PIE1AD3_MASK         8U
    #define PIE1AD_PIE1AD4_MASK         16U
    #define PIE1AD_PIE1AD5_MASK         32U
    #define PIE1AD_PIE1AD6_MASK         64U
    #define PIE1AD_PIE1AD7_MASK         128U
    
  } Overlap_STR;

  struct {
    word PIE1AD0     :1;                                       /* Port AD Interrupt Enable Bit 0 */
    word PIE1AD1     :1;                                       /* Port AD Interrupt Enable Bit 1 */
    word PIE1AD2     :1;                                       /* Port AD Interrupt Enable Bit 2 */
    word PIE1AD3     :1;                                       /* Port AD Interrupt Enable Bit 3 */
    word PIE1AD4     :1;                                       /* Port AD Interrupt Enable Bit 4 */
    word PIE1AD5     :1;                                       /* Port AD Interrupt Enable Bit 5 */
    word PIE1AD6     :1;                                       /* Port AD Interrupt Enable Bit 6 */
    word PIE1AD7     :1;                                       /* Port AD Interrupt Enable Bit 7 */
    word PIE0AD0     :1;                                       /* Port AD Interrupt Enable Bit 0 */
    word PIE0AD1     :1;                                       /* Port AD Interrupt Enable Bit 1 */
    word PIE0AD2     :1;                                       /* Port AD Interrupt Enable Bit 2 */
    word PIE0AD3     :1;                                       /* Port AD Interrupt Enable Bit 3 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpPIE1AD :8;
    word grpPIE0AD :4;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} PIE01ADSTR;
extern volatile PIE01ADSTR _PIE01AD @(REG_BASE + 0x0000027CUL);
#define PIE01AD                         _PIE01AD.Word
#define PIE01AD_PIE1AD0                 _PIE01AD.Bits.PIE1AD0
#define PIE01AD_PIE1AD1                 _PIE01AD.Bits.PIE1AD1
#define PIE01AD_PIE1AD2                 _PIE01AD.Bits.PIE1AD2
#define PIE01AD_PIE1AD3                 _PIE01AD.Bits.PIE1AD3
#define PIE01AD_PIE1AD4                 _PIE01AD.Bits.PIE1AD4
#define PIE01AD_PIE1AD5                 _PIE01AD.Bits.PIE1AD5
#define PIE01AD_PIE1AD6                 _PIE01AD.Bits.PIE1AD6
#define PIE01AD_PIE1AD7                 _PIE01AD.Bits.PIE1AD7
#define PIE01AD_PIE0AD0                 _PIE01AD.Bits.PIE0AD0
#define PIE01AD_PIE0AD1                 _PIE01AD.Bits.PIE0AD1
#define PIE01AD_PIE0AD2                 _PIE01AD.Bits.PIE0AD2
#define PIE01AD_PIE0AD3                 _PIE01AD.Bits.PIE0AD3
#define PIE01AD_PIE1AD                  _PIE01AD.MergedBits.grpPIE1AD
#define PIE01AD_PIE0AD                  _PIE01AD.MergedBits.grpPIE0AD

#define PIE01AD_PIE1AD0_MASK            1U
#define PIE01AD_PIE1AD1_MASK            2U
#define PIE01AD_PIE1AD2_MASK            4U
#define PIE01AD_PIE1AD3_MASK            8U
#define PIE01AD_PIE1AD4_MASK            16U
#define PIE01AD_PIE1AD5_MASK            32U
#define PIE01AD_PIE1AD6_MASK            64U
#define PIE01AD_PIE1AD7_MASK            128U
#define PIE01AD_PIE0AD0_MASK            256U
#define PIE01AD_PIE0AD1_MASK            512U
#define PIE01AD_PIE0AD2_MASK            1024U
#define PIE01AD_PIE0AD3_MASK            2048U
#define PIE01AD_PIE1AD_MASK             255U
#define PIE01AD_PIE1AD_BITNUM           0U
#define PIE01AD_PIE0AD_MASK             3840U
#define PIE01AD_PIE0AD_BITNUM           8U


/*** PIF01AD - Port AD Interrupt Flag Register; 0x0000027E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PIF0AD - Port ADH Interrupt Flag Register; 0x0000027E ***/
    union {
      byte Byte;
      struct {
        byte PIF0AD0     :1;                                       /* Port ADH Bit 0 */
        byte PIF0AD1     :1;                                       /* Port ADH Bit 1 */
        byte PIF0AD2     :1;                                       /* Port ADH Bit 2 */
        byte PIF0AD3     :1;                                       /* Port ADH Bit 3 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpPIF0AD :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } PIF0ADSTR;
    #define PIF0AD                      _PIF01AD.Overlap_STR.PIF0ADSTR.Byte
    #define PIF0AD_PIF0AD0              _PIF01AD.Overlap_STR.PIF0ADSTR.Bits.PIF0AD0
    #define PIF0AD_PIF0AD1              _PIF01AD.Overlap_STR.PIF0ADSTR.Bits.PIF0AD1
    #define PIF0AD_PIF0AD2              _PIF01AD.Overlap_STR.PIF0ADSTR.Bits.PIF0AD2
    #define PIF0AD_PIF0AD3              _PIF01AD.Overlap_STR.PIF0ADSTR.Bits.PIF0AD3
    #define PIF0AD_PIF0AD               _PIF01AD.Overlap_STR.PIF0ADSTR.MergedBits.grpPIF0AD
    
    #define PIF0AD_PIF0AD0_MASK         1U
    #define PIF0AD_PIF0AD1_MASK         2U
    #define PIF0AD_PIF0AD2_MASK         4U
    #define PIF0AD_PIF0AD3_MASK         8U
    #define PIF0AD_PIF0AD_MASK          15U
    #define PIF0AD_PIF0AD_BITNUM        0U
    

    /*** PIF1AD - Port ADL Interrupt Flag Register; 0x0000027F ***/
    union {
      byte Byte;
      struct {
        byte PIF1AD0     :1;                                       /* Port ADL Bit 0 */
        byte PIF1AD1     :1;                                       /* Port ADL Bit 1 */
        byte PIF1AD2     :1;                                       /* Port ADL Bit 2 */
        byte PIF1AD3     :1;                                       /* Port ADL Bit 3 */
        byte PIF1AD4     :1;                                       /* Port ADL Bit 4 */
        byte PIF1AD5     :1;                                       /* Port ADL Bit 5 */
        byte PIF1AD6     :1;                                       /* Port ADL Bit 6 */
        byte PIF1AD7     :1;                                       /* Port ADL Bit 7 */
      } Bits;
    } PIF1ADSTR;
    #define PIF1AD                      _PIF01AD.Overlap_STR.PIF1ADSTR.Byte
    #define PIF1AD_PIF1AD0              _PIF01AD.Overlap_STR.PIF1ADSTR.Bits.PIF1AD0
    #define PIF1AD_PIF1AD1              _PIF01AD.Overlap_STR.PIF1ADSTR.Bits.PIF1AD1
    #define PIF1AD_PIF1AD2              _PIF01AD.Overlap_STR.PIF1ADSTR.Bits.PIF1AD2
    #define PIF1AD_PIF1AD3              _PIF01AD.Overlap_STR.PIF1ADSTR.Bits.PIF1AD3
    #define PIF1AD_PIF1AD4              _PIF01AD.Overlap_STR.PIF1ADSTR.Bits.PIF1AD4
    #define PIF1AD_PIF1AD5              _PIF01AD.Overlap_STR.PIF1ADSTR.Bits.PIF1AD5
    #define PIF1AD_PIF1AD6              _PIF01AD.Overlap_STR.PIF1ADSTR.Bits.PIF1AD6
    #define PIF1AD_PIF1AD7              _PIF01AD.Overlap_STR.PIF1ADSTR.Bits.PIF1AD7
    
    #define PIF1AD_PIF1AD0_MASK         1U
    #define PIF1AD_PIF1AD1_MASK         2U
    #define PIF1AD_PIF1AD2_MASK         4U
    #define PIF1AD_PIF1AD3_MASK         8U
    #define PIF1AD_PIF1AD4_MASK         16U
    #define PIF1AD_PIF1AD5_MASK         32U
    #define PIF1AD_PIF1AD6_MASK         64U
    #define PIF1AD_PIF1AD7_MASK         128U
    
  } Overlap_STR;

  struct {
    word PIF1AD0     :1;                                       /* Port AD Bit 0 */
    word PIF1AD1     :1;                                       /* Port AD Bit 1 */
    word PIF1AD2     :1;                                       /* Port AD Bit 2 */
    word PIF1AD3     :1;                                       /* Port AD Bit 3 */
    word PIF1AD4     :1;                                       /* Port AD Bit 4 */
    word PIF1AD5     :1;                                       /* Port AD Bit 5 */
    word PIF1AD6     :1;                                       /* Port AD Bit 6 */
    word PIF1AD7     :1;                                       /* Port AD Bit 7 */
    word PIF0AD0     :1;                                       /* Port AD Bit 0 */
    word PIF0AD1     :1;                                       /* Port AD Bit 1 */
    word PIF0AD2     :1;                                       /* Port AD Bit 2 */
    word PIF0AD3     :1;                                       /* Port AD Bit 3 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpPIF1AD :8;
    word grpPIF0AD :4;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} PIF01ADSTR;
extern volatile PIF01ADSTR _PIF01AD @(REG_BASE + 0x0000027EUL);
#define PIF01AD                         _PIF01AD.Word
#define PIF01AD_PIF1AD0                 _PIF01AD.Bits.PIF1AD0
#define PIF01AD_PIF1AD1                 _PIF01AD.Bits.PIF1AD1
#define PIF01AD_PIF1AD2                 _PIF01AD.Bits.PIF1AD2
#define PIF01AD_PIF1AD3                 _PIF01AD.Bits.PIF1AD3
#define PIF01AD_PIF1AD4                 _PIF01AD.Bits.PIF1AD4
#define PIF01AD_PIF1AD5                 _PIF01AD.Bits.PIF1AD5
#define PIF01AD_PIF1AD6                 _PIF01AD.Bits.PIF1AD6
#define PIF01AD_PIF1AD7                 _PIF01AD.Bits.PIF1AD7
#define PIF01AD_PIF0AD0                 _PIF01AD.Bits.PIF0AD0
#define PIF01AD_PIF0AD1                 _PIF01AD.Bits.PIF0AD1
#define PIF01AD_PIF0AD2                 _PIF01AD.Bits.PIF0AD2
#define PIF01AD_PIF0AD3                 _PIF01AD.Bits.PIF0AD3
#define PIF01AD_PIF1AD                  _PIF01AD.MergedBits.grpPIF1AD
#define PIF01AD_PIF0AD                  _PIF01AD.MergedBits.grpPIF0AD

#define PIF01AD_PIF1AD0_MASK            1U
#define PIF01AD_PIF1AD1_MASK            2U
#define PIF01AD_PIF1AD2_MASK            4U
#define PIF01AD_PIF1AD3_MASK            8U
#define PIF01AD_PIF1AD4_MASK            16U
#define PIF01AD_PIF1AD5_MASK            32U
#define PIF01AD_PIF1AD6_MASK            64U
#define PIF01AD_PIF1AD7_MASK            128U
#define PIF01AD_PIF0AD0_MASK            256U
#define PIF01AD_PIF0AD1_MASK            512U
#define PIF01AD_PIF0AD2_MASK            1024U
#define PIF01AD_PIF0AD3_MASK            2048U
#define PIF01AD_PIF1AD_MASK             255U
#define PIF01AD_PIF1AD_BITNUM           0U
#define PIF01AD_PIF0AD_MASK             3840U
#define PIF01AD_PIF0AD_BITNUM           8U


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
    byte APIEA       :1;                                       /* Autonomous Periodical Interrupt External Access Enable Bit */
    byte APIES       :1;                                       /* Autonomous Periodical Interrupt External Select Bit */
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
#define CPMUAPICTL_APIEA                _CPMUAPICTL.Bits.APIEA
#define CPMUAPICTL_APIES                _CPMUAPICTL.Bits.APIES
#define CPMUAPICTL_APICLK               _CPMUAPICTL.Bits.APICLK

#define CPMUAPICTL_APIF_MASK            1U
#define CPMUAPICTL_APIE_MASK            2U
#define CPMUAPICTL_APIFE_MASK           4U
#define CPMUAPICTL_APIEA_MASK           8U
#define CPMUAPICTL_APIES_MASK           16U
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
    byte OSCFILT0    :1;                                       /* Oscillator Filter Bits, bit 0 */
    byte OSCFILT1    :1;                                       /* Oscillator Filter Bits, bit 1 */
    byte OSCFILT2    :1;                                       /* Oscillator Filter Bits, bit 2 */
    byte OSCFILT3    :1;                                       /* Oscillator Filter Bits, bit 3 */
    byte OSCFILT4    :1;                                       /* Oscillator Filter Bits, bit 4 */
    byte OSCPINS_EN  :1;                                       /* Oscillator Pins EXTAL and XTAL Enable Bit */
    byte OSCBW       :1;                                       /* Oscillator Filter Bandwidth Bit */
    byte OSCE        :1;                                       /* Oscillator Enable Bit */
  } Bits;
  struct {
    byte grpOSCFILT :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CPMUOSCSTR;
extern volatile CPMUOSCSTR _CPMUOSC @(REG_BASE + 0x000002FAUL);
#define CPMUOSC                         _CPMUOSC.Byte
#define CPMUOSC_OSCFILT0                _CPMUOSC.Bits.OSCFILT0
#define CPMUOSC_OSCFILT1                _CPMUOSC.Bits.OSCFILT1
#define CPMUOSC_OSCFILT2                _CPMUOSC.Bits.OSCFILT2
#define CPMUOSC_OSCFILT3                _CPMUOSC.Bits.OSCFILT3
#define CPMUOSC_OSCFILT4                _CPMUOSC.Bits.OSCFILT4
#define CPMUOSC_OSCPINS_EN              _CPMUOSC.Bits.OSCPINS_EN
#define CPMUOSC_OSCBW                   _CPMUOSC.Bits.OSCBW
#define CPMUOSC_OSCE                    _CPMUOSC.Bits.OSCE
#define CPMUOSC_OSCFILT                 _CPMUOSC.MergedBits.grpOSCFILT

#define CPMUOSC_OSCFILT0_MASK           1U
#define CPMUOSC_OSCFILT1_MASK           2U
#define CPMUOSC_OSCFILT2_MASK           4U
#define CPMUOSC_OSCFILT3_MASK           8U
#define CPMUOSC_OSCFILT4_MASK           16U
#define CPMUOSC_OSCPINS_EN_MASK         32U
#define CPMUOSC_OSCBW_MASK              64U
#define CPMUOSC_OSCE_MASK               128U
#define CPMUOSC_OSCFILT_MASK            31U
#define CPMUOSC_OSCFILT_BITNUM          0U


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
    byte DPS4        :1;                                       /* D-Flash Protection Size Bit 4 */
    byte             :1; 
    byte             :1; 
    byte DPOPEN      :1;                                       /* D-Flash Protection Control */
  } Bits;
  struct {
    byte grpDPS  :5;
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
#define NVDFPROT_DPS4                   _NVDFPROT.Bits.DPS4
#define NVDFPROT_DPOPEN                 _NVDFPROT.Bits.DPOPEN
#define NVDFPROT_DPS                    _NVDFPROT.MergedBits.grpDPS

#define NVDFPROT_DPS0_MASK              1U
#define NVDFPROT_DPS1_MASK              2U
#define NVDFPROT_DPS2_MASK              4U
#define NVDFPROT_DPS3_MASK              8U
#define NVDFPROT_DPS4_MASK              16U
#define NVDFPROT_DPOPEN_MASK            128U
#define NVDFPROT_DPS_MASK               31U
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

#ifndef __V30COMPATIBLE__
#pragma OPTION DEL V30toV31Compatible
#endif
/*lint -restore  +esym(961,18.4) +esym(961,19.7) Enable MISRA rule (1.1,18.4,6.4,19.7) checking. */

#endif
