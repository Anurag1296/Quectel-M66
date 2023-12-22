/*
 * BT_Configuration.h
 *
 *  Created on: Dec 13, 2023
 *      Author: Admin
 */

#ifndef BT_CONFIGURATION_H_
#define BT_CONFIGURATION_H_

#include "configuration.h"

#ifdef BT_CLASSIC

#define BL_POWERON                      1
#define BL_POWERDOWN                    0
#define MAX_BLDEV_CNT                   20
#define DEFA_CON_ID                     0
#define SCAN_TIME_OUT                   60   
#define SERIAL_RX_BUFFER_LEN            2048
#define BL_RX_BUFFER_LEN                10245
#define BT_EVENT_PAIR                   0x00000004
#define BT_EVTGRP_NAME                  "BT_EVETNGRP"
#define BT_MODE_INVISBLE_FOREVER        0
#define BT_MODE_VISIBLE_FOREVER         1
#define BT_MODE_VISIBLE_TMEPORARY       2
#define BT_MODE_SCAN_TIMEOUT_IN_SEC     10
#define BT_MAX_NUM_DEVICE_SCAN          5
#define BT_MAX_NUM_CLASS_OF_DEVICE      0
/**
 * @brief When mode is set to "BT_MODE_VISIBLE_TMEPORARY", this timeout decides which time bluetooth can be fond
 * by others and this value can be in between 1-255
*/
#define BT_VISIBILITY_MODE_TIMEOUT      60   // in seconds 



ST_BT_BasicInfo pSppRecHdl;
char pinCode[BT_PIN_LEN];
ST_BT_DevInfo BTSppDev1;

typedef struct  
{
ST_BT_DevInfo **gDevInfo;
char btName[BT_NAME_LEN];
u8 btRead[1024];
u32 btReadAcLen;
}BT_ParamStruct;

typedef BT_ParamStruct BTParam;


void vBluetoothInit(void);

#endif


#endif /* BT_CONFIGURATION_H_ */
