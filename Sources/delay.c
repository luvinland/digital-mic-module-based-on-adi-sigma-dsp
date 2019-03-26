///////////////////////////////////////////////////////////////////////
// Copyright (C) BSE Co., Ltd. 2012-2013
//
// Description : 122Q Hyundai Mobis Project
//
// @file    delay.c
// @brief   This file contains delay function.
///////////////////////////////////////////////////////////////////////


// Header files ///////////////////////////////////////////////////////
#include "delay.h"


// Defines      ///////////////////////////////////////////////////////


// Functions    ///////////////////////////////////////////////////////
#if XTAL_FREQ <= 2MHZ
void DelayMs(unsigned int cnt)
{
    do 
    {
        DelayUs(996);
    } while(--cnt);
}
#endif

#if XTAL_FREQ > 2MHZ  
#ifdef __PIC16F877A_H
void DelayMs(unsigned int cnt)
{
    unsigned int i;
    do
    {
        i = 4;
        do
        {
            DelayUs(250);
        } while(--i);
    } while(--cnt);
}
#else
void DelayMs(unsigned int cnt)
{
    unsigned int i;
    do
    {
        i = 10;
        do
        {
            //101.3us
            DelayUs(165);
        } while(--i);
    } while(--cnt);
}
#endif
#endif

