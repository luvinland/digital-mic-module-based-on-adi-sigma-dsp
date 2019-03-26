///////////////////////////////////////////////////////////////////////
// Copyright (C) BSE Co., Ltd. 2012-2013
//
// Description : 122Q Hyundai Mobis Project
//
// @file    adau.c
// @brief   This file contains ADAU control interfaces.
///////////////////////////////////////////////////////////////////////


// Header files ///////////////////////////////////////////////////////
#include "adau.h"
#include "i2c.h"
#include "delay.h"


// Defines      ///////////////////////////////////////////////////////


// Functions    ///////////////////////////////////////////////////////
static void download_ProgramRAM_ADAU(void)
{
    unsigned char addr_h;
    unsigned char addr_l;

    addr_h = (ADAU_REG_PROG >> 8) & 0xFF;
    addr_l = ADAU_REG_PROG & 0xFF;

    i2c1_Start();
    i2c1_Write(DEV_ADAU | I2C_CTL_W);
    i2c1_Write(addr_h);
    i2c1_Write(addr_l);

    // Program RAM Data
#ifdef RX_MODULE
    for(unsigned int index = 0; index < 225; index++)
    {
        i2c1_Write(programData[index]);
    }
#else // TX_MODULE
    for(unsigned int index = 0; index < 255; index++)
    {
        i2c1_Write(programData[index]);
    }
#endif

    i2c1_Stop();
}

static void download_ParameterRAM_ADAU(void)
{
    unsigned char addr_h;
    unsigned char addr_l;

    addr_h = (ADAU_REG_PARA >> 8) & 0xFF;
    addr_l = ADAU_REG_PARA & 0xFF;

    i2c1_Start();
    i2c1_Write(DEV_ADAU | I2C_CTL_W);
    i2c1_Write(addr_h);
    i2c1_Write(addr_l);

    // Parameter RAM Data
#ifdef RX_MODULE
    for(unsigned int index = 0; index < 32; index++)
    {
        i2c1_Write(paramData[index]);
    }
#else // TX_MODULE
    for(unsigned int index = 0; index < 40; index++)
    {
        i2c1_Write(paramData[index]);
    }
#endif

    i2c1_Stop();
}

/* Not download Non Modulo RAM
static void download_NonModuloRAM_ADAU(void)
{
    unsigned char addr_h;
    unsigned char addr_l;

    addr_h = (ADAU_REG_NONMOD >> 8) & 0xFF;
    addr_l = ADAU_REG_NONMOD & 0xFF;

    i2c1_Start();
    i2c1_Write(DEV_ADAU | I2C_CTL_W);
    i2c1_Write(addr_h);
    i2c1_Write(addr_l);

    // Non Modulo RAM Data
    for(unsigned int index = 0; index < 4; index++)
    {
        i2c1_Write(nonmoduloData[index]);
    }

    i2c1_Stop();
}
*/

void interface_ADAU(void)
{
    // Serial Port Control Registers
    ADAU_Write(ADAU_REG_SP0,    SPSRS | LRMOD | BPOL | LRPOL | CHPF | MS);
    ADAU_Write(ADAU_REG_SP1,    BPF | ADTDM | DATDM | MSBP | LRDEL);

    // ALC Control Registers
    ADAU_Write(ADAU_REG_ALC0,   PGASLEW | ALCMAX | ALCSEL);
    ADAU_Write(ADAU_REG_ALC1,   ALCHOLD | ALCTARG);
    ADAU_Write(ADAU_REG_ALC2,   ALCATCK | ALCDEC);
    ADAU_Write(ADAU_REG_ALC3,   NGTYP | NGEN | NGTHR);

    // Microphone Control Register
    ADAU_Write(ADAU_REG_DM,     JDDB | JDFUNC | JDPOL);

    // Record Input Signal Path Registers
    ADAU_Write(ADAU_REG_MX10,   LINPG | LINNG | MX1EN);
    ADAU_Write(ADAU_REG_MX11,   LDBOOST | MX1AUXG);
    ADAU_Write(ADAU_REG_MX20,   RINPG | RINNG | MX2EN);
    ADAU_Write(ADAU_REG_MX21,   RDBOOST | MX2AUXG);
    ADAU_Write(ADAU_REG_DIFFL,  LDVOL | LDMUTE | LDEN);
    ADAU_Write(ADAU_REG_DIFFR,  RDVOL | RDMUTE | RDEN);
    ADAU_Write(ADAU_REG_MB,     MPERF | MBI | MBIEN);

    // ADC Control Registers
    ADAU_Write(ADAU_REG_ADC,    ADCPOL | HPF | DMPOL | DMSW | INSEL | ADCEN);
    ADAU_Write(ADAU_REG_LIDV,   LADVOL);
    ADAU_Write(ADAU_REG_RIDV,   RADVOL);

    // Playback Output Signal Path Registers
    ADAU_Write(ADAU_REG_MX30,   MX3RM | MX3LM | MX3AUXG | MX3EN);
    ADAU_Write(ADAU_REG_MX31,   MX3G2 | MX3G1);
    ADAU_Write(ADAU_REG_MX40,   MX4RM | MX4LM | MX4AUXG | MX4EN);
    ADAU_Write(ADAU_REG_MX41,   MX4G2 | MX4G1);
    ADAU_Write(ADAU_REG_MX5,    MX5G4 | MX5G3 | MX5EN);
    ADAU_Write(ADAU_REG_MX6,    MX6G4 | MX6G3 | MX6EN);
    ADAU_Write(ADAU_REG_MX7,    MX7 | MX7EN);
    ADAU_Write(ADAU_REG_LHP,    LHPVOL | LHPM | HPEN);
    ADAU_Write(ADAU_REG_RHP,    RHPVOL | RHPM | HPMODE);
    ADAU_Write(ADAU_REG_LOUT,   LOUTVOL | LOUTM | LOMODE);
    ADAU_Write(ADAU_REG_ROUT,   ROUTVOL | ROUTM | ROMODE);
    ADAU_Write(ADAU_REG_MONO,   MONOVOL | MONOM | MOMODE);
    ADAU_Write(ADAU_REG_POP,    POPMODE | POPLESS | ASLEW);
    ADAU_Write(ADAU_REG_PM,     PREN | PLEN);

    // Converter Control Registers
    ADAU_Write(ADAU_REG_CONV0,  DAPAIR | DAOSR | ADOSR | CONVSR);
    ADAU_Write(ADAU_REG_CONV1,  ADPAIR);

    // DAC Control Registers
    ADAU_Write(ADAU_REG_DAC0,   DACMONO | DACPOL | DEMPH | DACEN);
    ADAU_Write(ADAU_REG_DAC1,   LDAVOL);
    ADAU_Write(ADAU_REG_DAC2,   RDAVOL);

    // Serial Port Pad Control Registers
    ADAU_Write(ADAU_REG_SPP,    ADCSDP | DACSDP | LRCLKP | BCLKP);

    // Communication Port Pad Control Registers
    ADAU_Write(ADAU_REG_CPP0,   CDATP | CLCHP | SCLP | SDAP);
    ADAU_Write(ADAU_REG_CPP1,   SDASTR);

    // Jack Detect Pad Control Register
    ADAU_Write(ADAU_REG_JDP,    JDSTR | JDP);

    // DSP ON Register
    ADAU_Write(ADAU_REG_DSPEN,  DSPEN);

    // CRC Registers
    ADAU_Write(ADAU_REG_CRC0,   CRC0);
    ADAU_Write(ADAU_REG_CRC1,   CRC1);
    ADAU_Write(ADAU_REG_CRC2,   CRC2);
    ADAU_Write(ADAU_REG_CRC3,   CRC3);
    ADAU_Write(ADAU_REG_CRC4,   CRCEN);

    // GPIO Registers
    ADAU_Write(ADAU_REG_GPIO0,  GPIO0);
    ADAU_Write(ADAU_REG_GPIO1,  GPIO1);
    ADAU_Write(ADAU_REG_GPIO2,  GPIO2);
    ADAU_Write(ADAU_REG_GPIO3,  GPIO3);

    // Non Modulo Registers
    ADAU_Write(ADAU_REG_NONMD1, NONMD1);
    ADAU_Write(ADAU_REG_NONMD2, NONMD2);

    // Watchdog Registers
    ADAU_Write(ADAU_REG_DOGEN,  DOGEN);
    ADAU_Write(ADAU_REG_DOG0,   DOG0);
    ADAU_Write(ADAU_REG_DOG1,   DOG1);
    ADAU_Write(ADAU_REG_DOG2,   DOG2);
    ADAU_Write(ADAU_REG_DOGER,  DOGER);

    // Sampling Rate Setting Register
    ADAU_Write(ADAU_REG_DSPSR,  DSPSR_RESET);

    // Routing Matrix Inputs Register
    ADAU_Write(ADAU_REG_SINR,   SINRT);

    // Routing Matrix Outputs Register
    ADAU_Write(ADAU_REG_SOUTR,  SOUTRT);

    // Serial Data Configuration Register
    ADAU_Write(ADAU_REG_SDPC,   LRGP3 | BGP2 | SDOGP1 | SDIGP0);

    // DSP Slew Mode Register
    ADAU_Write(ADAU_REG_SLEW,   MOSLW | ROSLW | LOSLW | RHPSLW | LHPSLW);

    // Serial Port Sample Rate Register
    ADAU_Write(ADAU_REG_SPSR,   SPSR);

    // Clock Enable Registers
    ADAU_Write(ADAU_REG_CE0,    SLEWPD | ALCPD | DECPD | SOUTPD | INTPD | SINPD | SPPD);
    ADAU_Write(ADAU_REG_CE1,    CLK1 | CLK0);

    // Download Program RAM & Parameter RAM
    download_ProgramRAM_ADAU();
    download_ParameterRAM_ADAU();
    //download_NonModuloRAM_ADAU(); // Not download Non Modulo RAM
}

void start_ADAU(void)
{
    // Sample Rate Setting
    ADAU_Write(ADAU_REG_DSPSR,  DSPSR);

    // DSP Run Register
    ADAU_Write(ADAU_REG_DSPRUN, DSPRUN);

    // Dejitter Register Control
    ADAU_Write(ADAU_REG_DEJIT,  DEJIT_RESET);
    DelayMs(20);
    ADAU_Write(ADAU_REG_DEJIT,  DEJIT);
}

