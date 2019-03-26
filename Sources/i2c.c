///////////////////////////////////////////////////////////////////////
// Copyright (C) BSE Co., Ltd. 2012-2013
//
// Description : 122Q Hyundai Mobis Project
//
// @file    i2c.c
// @brief   This file contains i2c control interfaces.
///////////////////////////////////////////////////////////////////////


// Header files ///////////////////////////////////////////////////////
#include "i2c.h"


// Defines      ///////////////////////////////////////////////////////


// Functions    ///////////////////////////////////////////////////////
void i2c1_Wait(void)
{
    while((SSP1CON2 & 0x1F) | SSP1STATbits.R_nW) { }; // wait for idle and not writing
}

void i2c1_Start(void)
{
    i2c1_Wait();
    SSP1CON2bits.SEN = 1;
}

void i2c1_Stop(void)
{
    i2c1_Wait();
    SSP1CON2bits.PEN = 1;
}

unsigned char i2c1_Write(unsigned char i2cWriteData)
{
    i2c1_Wait();
    SSP1BUF = i2cWriteData;

    return (!SSP1CON2bits.ACKSTAT); // function returns '1' if transmission is acknowledged
}

#if 0 /* For RX Code */
void i2c2_Wait(void)
{
    while((SSP2CON2 & 0x1F) | SSP2STATbits.R_nW) { }; // wait for idle and not writing
}

void i2c2_Start(void)
{
    i2c2_Wait();
    SSP2CON2bits.SEN = 1;
}

void i2c2_Stop(void)
{
    i2c2_Wait();
    SSP2CON2bits.PEN = 1;
}

unsigned char i2c2_Write(unsigned char i2cWriteData)
{
    i2c2_Wait();
    SSP2BUF = i2cWriteData;

    return (!SSP2CON2bits.ACKSTAT); // function returns '1' if transmission is acknowledged
}

void write_Byte(unsigned char ctlr, unsigned char addr, unsigned char data)
{
    i2c2_Start();
    i2c2_Write(ctlr);
    i2c2_Write(addr | I2C_INCR_DIS);
    i2c2_Write(data);
    i2c2_Stop();
}
#endif

void write_Word(unsigned char ctlr, unsigned int addr, unsigned char data)
{
    unsigned char addr_h;
    unsigned char addr_l;

    addr_h = (addr >> 8) & 0xFF;
    addr_l = addr & 0xFF;

    i2c1_Start();
    i2c1_Write(ctlr | I2C_CTL_W);
    i2c1_Write(addr_h);
    i2c1_Write(addr_l);
    i2c1_Write(data);
    i2c1_Stop();
}

#if 0 /* For RX Code */
void CS_Write(unsigned char addr, unsigned char data)
{
    write_Byte(DEV_CS, addr, data);
}
#endif

void ADAU_Write(unsigned int addr, unsigned char data)
{
    write_Word(DEV_ADAU, addr, data);
}

