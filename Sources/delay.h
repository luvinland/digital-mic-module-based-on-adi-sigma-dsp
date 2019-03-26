///////////////////////////////////////////////////////////////////////
// Copyright (C) BSE Co., Ltd. 2012-2013
//
// Description : 122Q Hyundai Mobis Project
//
// @file    delay.h
// @brief   This file contains delay function.
///////////////////////////////////////////////////////////////////////


// Header files ///////////////////////////////////////////////////////


// Defines      ///////////////////////////////////////////////////////
#ifndef XTAL_FREQ
#define XTAL_FREQ   4MHZ    // Crystal frequency in MHz
#endif

#define MHZ         *1000L  // number of KHz in a MHz
#define KHZ         *1      // number of KHz in a KHz

#if XTAL_FREQ >= 12MHZ
#define DelayUs(x) { unsigned char _dcnt; \
            _dcnt = (x) * ((XTAL_FREQ) / (12MHZ)); \
            while(--_dcnt != 0) \
            continue; }
#else
#define DelayUs(x) { unsigned char _dcnt; \
            _dcnt = (x) / ((12MHZ) / (XTAL_FREQ)) | 1; \
            while(--_dcnt != 0) \
            continue; }
#endif
                                                                                
        
// Functions    ///////////////////////////////////////////////////////
extern void DelayMs(unsigned int);

