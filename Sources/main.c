///////////////////////////////////////////////////////////////////////
// Copyright (C) BSE Co., Ltd. 2012-2013
//
// Description : 122Q Hyundai Mobis Project
//
// @file    main.c
// @brief   This file contains main() and the mcu or other chips init.
///////////////////////////////////////////////////////////////////////


// Header files ///////////////////////////////////////////////////////
#include <htc.h>
#include "delay.h"
#include "private.h"
#ifndef RX_MODULE // TX_MODULE
#include "led.h"
#endif
#include "init.h"
#include "adau.h"

// Defines      ///////////////////////////////////////////////////////


// Configuration Bits   ///////////////////////////////////////////////
__CONFIG(FOSC_INTOSC & WDTE_OFF & PWRTE_ON & MCLRE_ON & CP_OFF & CPD_OFF & BOREN_ON & CLKOUTEN_OFF & PLLEN_OFF);


// Functions    ///////////////////////////////////////////////////////
#ifndef RX_MODULE // TX_MODULE
void start_System(void)
{
    set_LED(LED_ON_TEST2);
    DelayMs(500);
    set_LED(LED_ON_TEST1);
    DelayMs(500);
    set_LED(LED_OFF);
    DelayMs(500);
    set_LED(LED_ON_ALL);
}
#endif

void main(void)
{
    init_MCU();
    init_ADAU();
    DelayMs(100);

    interface_ADAU();
    start_ADAU();

#ifndef RX_MODULE // TX_MODULE
    init_CS();

    start_System();
#endif

    while(1);
}

