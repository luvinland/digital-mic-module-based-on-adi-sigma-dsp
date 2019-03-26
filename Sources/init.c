///////////////////////////////////////////////////////////////////////
// Copyright (C) BSE Co., Ltd. 2012-2013
//
// Description : 122Q Hyundai Mobis Project
//
// @file    init.c
// @brief   This file contains MCU and other chips init.
///////////////////////////////////////////////////////////////////////


// Header files ///////////////////////////////////////////////////////
#include "init.h"
#include "i2c.h"


// Defines      ///////////////////////////////////////////////////////


// Functions    ///////////////////////////////////////////////////////
// MCU - PIC16LF1847
void init_MCU(void)
{
    OSCCON = 0x78;      // 4x PLL disable, 16MHz HF, Clock determined by FOSC<2:0>

    // Analog I/O Configuration
    ANSELA = 0x00;
    ANSELB = 0x00;

    // I2C Configuration
    TRISB1 = 1;             // Set SDA pins as inputs for ADAU
    TRISB4 = 1;             // Set SCL pins as inputs for ADAU
#ifndef RX_MODULE // TX_MODULE
    TRISB2 = 1;             // Set SDA pins as inputs for CS
    TRISB5 = 1;             // Set SCL pins as inputs for CS
#endif

    SSP1CON1 = 0x38;        // Set I2C Master mode for ADAU
    SSP1CON2 = 0x00;
    SSP1ADD = 0x27;         // 100kHz bus with 16MHz Internal Oscillator, Fscl = Fosc / (SSP1ADD + 1) * 4
#ifndef RX_MODULE // TX_MODULE
    SSP2CON1 = 0x38;        // Set I2C Master mode for CS
    SSP2CON2 = 0x00;
    SSP2ADD = 0x27;         // 100kHz bus with 16MHz Internal Oscillator, Fscl = Fosc / (SSP1ADD + 1) * 4
#endif

    SSP1STATbits.CKE = 1;   // For ADAU, Enable input logic so that thresholds are compliant with SMBus specification
    SSP1STATbits.SMP = 1;   // For ADAU, Slew rate control disabled for standard speed mode
#ifndef RX_MODULE // TX_MODULE
    SSP2STATbits.CKE = 1;   // For CS, Enable input logic so that thresholds are compliant with SMBus specification
    SSP2STATbits.SMP = 1;   // For CS, Slew rate control disabled for standard speed mode
#endif

    // I/O Configuration
    RST_1_DIR = 0;          // RA2 pin configured as an output
    RST_1 = 1;              // RST_1 high

#ifndef RX_MODULE // TX_MODULE
    // LED
    LED_TEST2_DIR = 0;      // RA3 pin configured as an output
    LED_TEST1_DIR = 0;      // RA4 pin configured as an output
    LED_TEST2 = 0;          // TEST2 low
    LED_TEST1 = 0;          // TEST1 low
#endif
}

#ifndef RX_MODULE // TX_MODULE
// CS8406
void init_CS(void)
{
    CS_Write(CS_REG_CSC,    RUNCS_RESET);
    CS_Write(CS_REG_CSC,    RUNCS | CLKCS);
    CS_Write(CS_REG_CONT1,  VSET | MUTEAES | INT10 | TCBLD);
    CS_Write(CS_REG_CONT2,  MMT | MMTCS | MMTLR);
    CS_Write(CS_REG_DFC,    TXOFF | AESBP);
    CS_Write(CS_REG_SIF,    SIMS | SISF | SIRES | SIJUST | SIDEL | SISPOL | SILRPOL);
}
#endif

// ADAU1461
static void ADAU_Write_Pll_Control(void)
{
    unsigned char addr_h;
    unsigned char addr_l;

    addr_h = (ADAU_REG_PLL >> 8) & 0xFF;
    addr_l = ADAU_REG_PLL & 0xFF;

    i2c1_Start();
    i2c1_Write(DEV_ADAU | I2C_CTL_W);
    i2c1_Write(addr_h);
    i2c1_Write(addr_l);
    i2c1_Write(M_MSB);
    i2c1_Write(M_LSB);
    i2c1_Write(N_MSB);
    i2c1_Write(N_LSB);
    i2c1_Write(R_VALUE | X_VALUE | TYPE);
    i2c1_Write(LOCK | PLLEN);
    i2c1_Stop();
}

void init_ADAU(void)
{
    ADAU_Write(ADAU_REG_DSPSR,  DSPSR_RESET);
    ADAU_Write(ADAU_REG_DSPRUN, DSPRUN_RESET);
    ADAU_Write(ADAU_REG_CLK,    CLKSRC | INFREQ | COREN);
    ADAU_Write_Pll_Control();
}

