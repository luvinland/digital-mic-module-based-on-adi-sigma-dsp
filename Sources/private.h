///////////////////////////////////////////////////////////////////////
// Copyright (C) BSE Co., Ltd. 2012-2013
//
// Description : 122Q Hyundai Mobis Project
//
// @file    private.h
// @brief   This header file declared global data.
///////////////////////////////////////////////////////////////////////


// Header files ///////////////////////////////////////////////////////
#include <htc.h>


// MCU Defines  ///////////////////////////////////////////////////////
// I/O
#define RST_1           RA2
#define RST_1_DIR       TRISA2

#ifndef RX_MODULE // TX_MODULE
// LED
#define LED_TEST2       RA3
#define LED_TEST1       RA4
#define LED_TEST2_DIR   TRISA3
#define LED_TEST1_DIR   TRISA4

#define LED_OFF         0x00
#define LED_ON_TEST2    0x01
#define LED_ON_TEST1    0x02
#define LED_ON_ALL      0x03
#endif


#ifndef RX_MODULE // TX_MODULE
// CS Defines   ///////////////////////////////////////////////////////
// Control 1
#define CS_REG_CONT1    0x01
#define VSET            0x00
#define MUTEAES         0x00
#define INT10           0x00
#define TCBLD           0x00

// Control 2
#define CS_REG_CONT2    0x02
#define MMT             0x00
#define MMTCS           0x00
#define MMTLR           0x00

// Data Flow Control
#define CS_REG_DFC      0x03
#define TXOFF           0x00
#define AESBP           0x00

// Clock Source Control
#define CS_REG_CSC      0x04
#define RUNCS_RESET     0x00
#define RUNCS           0x40
#define CLKCS           0x00

// Serial Input Format
#define CS_REG_SIF      0x05
#define SIMS            0x00
#define SISF            0x00
#define SIRES           0x00
#define SIJUST          0x00
#define SIDEL           0x04
#define SISPOL          0x00
#define SILRPOL         0x01
#endif


// ADAU Defines ///////////////////////////////////////////////////////
// Parameter RAM
#define ADAU_REG_PARA   0x0000

// Program RAM
#define ADAU_REG_PROG   0x0800

// Non Modulo RAM
//#define ADAU_REG_NONMOD 0x1FFF // Not download Non Modulo RAM

// Clock Control
#define ADAU_REG_CLK    0x4000
#define CLKSRC          0x08
#define INFREQ          0x06
#define COREN           0x01

// PLL Control
#define ADAU_REG_PLL    0x4002
#define M_MSB           0x00
#define M_LSB           0x01
#define N_MSB           0x00
#define N_LSB           0x00
#define R_VALUE         0x20
#define X_VALUE         0x00
#define TYPE            0x00
#define LOCK            0x02
#define PLLEN           0x01

// Digital Microphone/Jack Detection Control
#define ADAU_REG_DM     0x4008
#define JDDB            0x00
#define JDFUNC          0x20
#define JDPOL           0x00

#ifdef RX_MODULE
// Record Mixer Left (Mixer 1) Control 0
#define ADAU_REG_MX10   0x400A
#define LINPG           0x00
#define LINNG           0x00
#define MX1EN           0x01

// Record Mixer Left (Mixer 1) Control 1
#define ADAU_REG_MX11   0x400B
#define LDBOOST         0x00
#define MX1AUXG         0x05

// Record Mixer Right (Mixer 2) Control 0
#define ADAU_REG_MX20   0x400C
#define RINPG           0x00
#define RINNG           0x00
#define MX2EN           0x00

// Record Mixer Right (Mixer 2) Control 1
#define ADAU_REG_MX21   0x400D
#define RDBOOST         0x00
#define MX2AUXG         0x00
#else // TX_MODULE
// Record Mixer Left (Mixer 1) Control 0
#define ADAU_REG_MX10   0x400A
#define LINPG           0x50
#define LINNG           0x0A
#define MX1EN           0x01

// Record Mixer Left (Mixer 1) Control 1
#define ADAU_REG_MX11   0x400B
#define LDBOOST         0x00
#define MX1AUXG         0x05

// Record Mixer Right (Mixer 2) Control 0
#define ADAU_REG_MX20   0x400C
#define RINPG           0x50
#define RINNG           0x0A
#define MX2EN           0x01

// Record Mixer Right (Mixer 2) Control 1
#define ADAU_REG_MX21   0x400D
#define RDBOOST         0x00
#define MX2AUXG         0x05
#endif

// Left Differential Input Volume Control
#define ADAU_REG_DIFFL  0x400E
#define LDVOL           0xC0
#define LDMUTE          0x02
#define LDEN            0x00

// Right Differential Input Volume Control
#define ADAU_REG_DIFFR  0x400F
#define RDVOL           0x00
#define RDMUTE          0x00
#define RDEN            0x00

#ifdef RX_MODULE
// Record Microphone Bias Control
#define ADAU_REG_MB     0x4010
#define MPERF           0x00
#define MBI             0x00
#define MBIEN           0x01
#else // TX_MODULE
// Record Microphone Bias Control
#define ADAU_REG_MB     0x4010
#define MPERF           0x08
#define MBI             0x00
#define MBIEN           0x01
#endif

// ALC Control 0
#define ADAU_REG_ALC0   0x4011
#define PGASLEW         0xC0
#define ALCMAX          0x38
#define ALCSEL          0x03

// ALC Control 1
#define ADAU_REG_ALC1   0x4012
#define ALCHOLD         0x30
#define ALCTARG         0x0B

// ALC Contorl 2
#define ADAU_REG_ALC2   0x4013
#define ALCATCK         0x20
#define ALCDEC          0x05

// ALC Control 3
#define ADAU_REG_ALC3   0x4014
#define NGTYP           0x00
#define NGEN            0x00
#define NGTHR           0x11

// Serial Port Control 0
#define ADAU_REG_SP0    0x4015
#define SPSRS           0x00
#define LRMOD           0x00
#define BPOL            0x00
#define LRPOL           0x00
#define CHPF            0x00
#define MS              0x01

// Serial Port Control 1
#define ADAU_REG_SP1    0x4016
#define BPF             0x00
#define ADTDM           0x00
#define DATDM           0x00
#define MSBP            0x00
#define LRDEL           0x00

// Converter Control 0
#define ADAU_REG_CONV0  0x4017
#define DAPAIR          0x00
#define DAOSR           0x00
#define ADOSR           0x00
#define CONVSR          0x00

// Converter Control 1
#define ADAU_REG_CONV1  0x4018
#define ADPAIR          0x00

// ADC Control
#define ADAU_REG_ADC    0x4019
#define ADCPOL          0x00
#define HPF             0x20
#define DMPOL           0x10
#define DMSW            0x08
#define INSEL           0x00    // Analog MIC 0x00, Digital MIC 0x04
#define ADCEN           0x03

// Left Input Digital Volume
#define ADAU_REG_LIDV   0x401A
#define LADVOL          0x00

// Right Input Digital Volume
#define ADAU_REG_RIDV   0x401B
#define RADVOL          0x00

#ifdef RX_MODULE
// Playback Mixer Left (Mixer 3) Control 0
#define ADAU_REG_MX30   0x401C
#define MX3RM           0x00
#define MX3LM           0x20
#define MX3AUXG         0x00
#define MX3EN           0x01

// Playback Mixer Left (Mixer 3) Control 1
#define ADAU_REG_MX31   0x401D
#define MX3G2           0x00
#define MX3G1           0x00

// Playback Mixer Right (Mixer 4) Control 0
#define ADAU_REG_MX40   0x401E
#define MX4RM           0x40
#define MX4LM           0x00
#define MX4AUXG         0x00
#define MX4EN           0x01

// Playback Mixer Right (Mixer 4) Control 1
#define ADAU_REG_MX41   0x401F
#define MX4G2           0x00
#define MX4G1           0x00

// Playback L/R Mixer Left (Mixer 5) Line Output Control
#define ADAU_REG_MX5    0x4020
#define MX5G4           0x00
#define MX5G3           0x02
#define MX5EN           0x01

// Playback L/R Mixer Right (Mixer 6) Line Output Control
#define ADAU_REG_MX6    0x4021
#define MX6G4           0x08
#define MX6G3           0x00
#define MX6EN           0x01
#else // TX_MODULE
// Playback Mixer Left (Mixer 3) Control 0
#define ADAU_REG_MX30   0x401C
#define MX3RM           0x40
#define MX3LM           0x20
#define MX3AUXG         0x0C
#define MX3EN           0x01

// Playback Mixer Left (Mixer 3) Control 1
#define ADAU_REG_MX31   0x401D
#define MX3G2           0x60
#define MX3G1           0x06

// Playback Mixer Right (Mixer 4) Control 0
#define ADAU_REG_MX40   0x401E
#define MX4RM           0x40
#define MX4LM           0x20
#define MX4AUXG         0x0C
#define MX4EN           0x01

// Playback Mixer Right (Mixer 4) Control 1
#define ADAU_REG_MX41   0x401F
#define MX4G2           0x60
#define MX4G1           0x06

// Playback L/R Mixer Left (Mixer 5) Line Output Control
#define ADAU_REG_MX5    0x4020
#define MX5G4           0x08
#define MX5G3           0x02
#define MX5EN           0x01

// Playback L/R Mixer Right (Mixer 6) Line Output Control
#define ADAU_REG_MX6    0x4021
#define MX6G4           0x08
#define MX6G3           0x02
#define MX6EN           0x01
#endif

// Playback L/R Mixer Mono Output (Mixer 7) Control
#define ADAU_REG_MX7    0x4022
#define MX7             0x02
#define MX7EN           0x01

// Playback Headphone Left Volume Control
#define ADAU_REG_LHP    0x4023
#define LHPVOL          0xE4
#define LHPM            0x02
#define HPEN            0x01

// Playback Headphone Right Volume Control
#define ADAU_REG_RHP    0x4024
#define RHPVOL          0xE4
#define RHPM            0x02
#define HPMODE          0x01

// Playback Line Output Left Volume Control
#define ADAU_REG_LOUT   0x4025
#define LOUTVOL         0xE4
#define LOUTM           0x02
#define LOMODE          0x00

// Playback Line Output Right Volume Control
#define ADAU_REG_ROUT   0x4026
#define ROUTVOL         0xE4
#define ROUTM           0x02
#define ROMODE          0x00

// Playback Mono Output Control
#define ADAU_REG_MONO   0x4027
#define MONOVOL         0xE4
#define MONOM           0x02
#define MOMODE          0x01

// Playback Pop/Click Suppression
#define ADAU_REG_POP    0x4028
#define POPMODE         0x00
#define POPLESS         0x00
#define ASLEW           0x00

// Playback Power Management
#define ADAU_REG_PM     0x4029
#define PREN            0x02
#define PLEN            0x01

#ifdef RX_MODULE
// DAC Control 0
#define ADAU_REG_DAC0   0x402A
#define DACMONO         0x00
#define DACPOL          0x00
#define DEMPH           0x00
#define DACEN           0x07
#else // TX_MODULE
// DAC Control 0
#define ADAU_REG_DAC0   0x402A
#define DACMONO         0x00
#define DACPOL          0x00
#define DEMPH           0x00
#define DACEN           0x03
#endif

// DAC Control 1
#define ADAU_REG_DAC1   0x402B
#define LDAVOL          0x00

// DAC Control 2
#define ADAU_REG_DAC2   0x402C
#define RDAVOL          0x00

// Serial Port Pad Control
#define ADAU_REG_SPP    0x402D
#define ADCSDP          0x80
#define DACSDP          0x20
#define LRCLKP          0x08
#define BCLKP           0x02

// Control Port Pad Control 0
#define ADAU_REG_CPP0   0x402F
#define CDATP           0x80
#define CLCHP           0x20
#define SCLP            0x08
#define SDAP            0x02

// Control Port Pad Control 1
#define ADAU_REG_CPP1   0x4030
#define SDASTR          0x00

// Jack Detect Pin Control
#define ADAU_REG_JDP    0x4031
#define JDSTR           0x00
#define JDP             0x00

// Dejitter Control
#define ADAU_REG_DEJIT  0x4036
#define DEJIT_RESET     0x00
#define DEJIT           0x03

// Cyclic Redundancy Check Registers
#define ADAU_REG_CRC0   0x40C0
#define CRC0            0x00

#define ADAU_REG_CRC1   0x40C1
#define CRC1            0x00

#define ADAU_REG_CRC2   0x40C2
#define CRC2            0x00

#define ADAU_REG_CRC3   0x40C3
#define CRC3            0x00

#define ADAU_REG_CRC4   0x40C4
#define CRCEN           0x01

// GPIO Pin Control
#define ADAU_REG_GPIO0  0x40C6
#define GPIO0           0x00

#define ADAU_REG_GPIO1  0x40C7
#define GPIO1           0x00

#define ADAU_REG_GPIO2  0x40C8
#define GPIO2           0x00

#define ADAU_REG_GPIO3  0x40C9
#define GPIO3           0x00

// Watchdog Registers
#define ADAU_REG_DOGEN  0x40D0
#define DOGEN           0x01

#define ADAU_REG_DOG0   0x40D1
#define DOG0            0x00

#define ADAU_REG_DOG1   0x40D2
#define DOG1            0x00

#define ADAU_REG_DOG2   0x40D3
#define DOG2            0x00

#define ADAU_REG_DOGER  0x40D4
#define DOGER           0x00

// Non Modulo Registers
#define ADAU_REG_NONMD1 0x40E9
#define NONMD1          0x10

#define ADAU_REG_NONMD2 0x40EA
#define NONMD2          0x00

// DSP Sampling Rate Setting
#define ADAU_REG_DSPSR  0x40EB
#define DSPSR_RESET     0x7F
#define DSPSR           0x01

// Serial Input Route Control
#define ADAU_REG_SINR   0x40F2
#define SINRT           0x00

// Serial Output Route Control
#define ADAU_REG_SOUTR  0x40F3
#define SOUTRT          0x00

// Serial Data/GPIO Pin Configuration
#define ADAU_REG_SDPC   0x40F4
#define LRGP3           0x00
#define BGP2            0x00
#define SDOGP1          0x00
#define SDIGP0          0x00

// DSP Enable
#define ADAU_REG_DSPEN  0x40F5
#define DSPEN           0x01

// DSP Run
#define ADAU_REG_DSPRUN 0x40F6
#define DSPRUN_RESET    0x00
#define DSPRUN          0x01

// DSP Slew Modes
#define ADAU_REG_SLEW   0x40F7
#define MOSLW           0x00
#define ROSLW           0x00
#define LOSLW           0x00
#define RHPSLW          0x00
#define LHPSLW          0x00

// Serial Port Sampling Rate
#define ADAU_REG_SPSR   0x40F8
#define SPSR            0x00

// Clock Enable 0
#define ADAU_REG_CE0    0x40F9
#define SLEWPD          0x40
#define ALCPD           0x20
#define DECPD           0x10
#define SOUTPD          0x08
#define INTPD           0x04
#define SINPD           0x02
#define SPPD            0x01

// Clock Enable 1
#define ADAU_REG_CE1    0x40FA
#define CLK1            0x02
#define CLK0            0x01


// Functions    ///////////////////////////////////////////////////////
#ifndef RX_MODULE // TX_MODULE
void start_System(void);
#endif

