///////////////////////////////////////////////////////////////////////
// Copyright (C) BSE Co., Ltd. 2012-2013
//
// Description : 122Q Hyundai Mobis Project
//
// @file    i2c.h
// @brief   This header file contains i2c control interfaces.
///////////////////////////////////////////////////////////////////////


// Header files ///////////////////////////////////////////////////////
#include <htc.h>


// Defines      ///////////////////////////////////////////////////////
#define DEV_CS          0x20
#define DEV_ADAU        0x70
#define I2C_INCR_DIS    0x00
#define I2C_CTL_W       0x00


// Functions    ///////////////////////////////////////////////////////
void i2c1_Wait(void);

void i2c1_Start(void);

void i2c1_Stop(void);

unsigned char i2c1_Write(unsigned char i2cWriteData);

#if 0 /* For RX Code */
void i2c2_Wait(void);

void i2c2_Start(void);

void i2c2_Stop(void);

unsigned char i2c2_Write(unsigned char i2cWriteData);

void write_Byte(unsigned char ctlr, unsigned char addr, unsigned char data);
#endif

void write_Word(unsigned char ctlr, unsigned int addr, unsigned char data);

#if 0 /* For RX Code */
void CS_Write(unsigned char addr, unsigned char data);
#endif

void ADAU_Write(unsigned int addr, unsigned char data);

