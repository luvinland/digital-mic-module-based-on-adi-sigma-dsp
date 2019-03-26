///////////////////////////////////////////////////////////////////////
// Copyright (C) BSE Co., Ltd. 2012-2013
//
// Description : 122Q Hyundai Mobis Project
//
// @file    led.c
// @brief   This file contains LED control interfaces.
///////////////////////////////////////////////////////////////////////


// Header files ///////////////////////////////////////////////////////
#ifndef RX_MODULE // TX_MODULE
#include "led.h"
#endif


// Defines      ///////////////////////////////////////////////////////


// Functions    ///////////////////////////////////////////////////////
#ifndef RX_MODULE // TX_MODULE
void set_LED(unsigned char selLed)
{
    if(selLed == LED_OFF)
    {
        LED_TEST2 = 0;
        LED_TEST1 = 0;
    }
    else if(selLed == LED_ON_TEST2)
    {
        LED_TEST2 = 1;
        LED_TEST1 = 0;
    }
    else if(selLed == LED_ON_TEST1)
    {
        LED_TEST2 = 0;
        LED_TEST1 = 1;
    }
    else if(selLed == LED_ON_ALL)
    {
        LED_TEST2 = 1;
        LED_TEST1 = 1;
    }
}
#endif

