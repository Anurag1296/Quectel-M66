/**
 *    @file BLE_Configuration.c
 *  @author Anurag Maheshwari (anu-maheshwari)
 *    @date 21 March 2023
 *   @brief This code function will start Nimble-BLE and will have one server with once service
 *          ID and one characterstic ID
 */


#ifndef CHARGER_CONFIGURATION_H_
#define CHARGER_CONFIGURATION_H_


#include "ql_trace.h"
#include "ql_system.h"
#include "ql_gpio.h"
#include "ql_stdlib.h"
#include "ql_error.h"
#include "ql_uart.h"
#include <string.h>
#include "ql_type.h"
#include "ql_timer.h"
#include "ril_bluetooth.h"
#include "ril.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#include "cJSON/cJSON.h"


#define RGB
#define RELAY
#define TIMER
#define CHARGER_INFO
#define BT_CLASSIC



#define DEBUG_ENABLE 1
#if DEBUG_ENABLE > 0
#define DEBUG_PORT  UART_PORT1
#define DBG_BUF_LEN   2048
static char DBG_BUFFER[DBG_BUF_LEN];
#define APP_DEBUG(FORMAT,...) {\
   Ql_memset(DBG_BUFFER, 0, DBG_BUF_LEN);\
   Ql_sprintf(DBG_BUFFER,FORMAT,##__VA_ARGS__); \
   if (UART_PORT2 == (DEBUG_PORT)) \
   {\
       Ql_Debug_Trace(DBG_BUFFER);\
   } else {\
       Ql_UART_Write((Enum_SerialPort)(DEBUG_PORT), (u8*)(DBG_BUFFER), Ql_strlen((const char *)(DBG_BUFFER)));\
   }\
}
#else
#define APP_DEBUG(FORMAT,...)
#endif


#define DELAY_IN_MILLIS_500        500
#define DELAY_IN_MILLIS_100        100
#define DELAY_IN_MILLIS_1000       1000
#define DELAY_IN_MILLIS_10         10
#define DELAY_IN_MILLIS_20         20


#ifdef TIMER

/**
 * @paragraph: Timer ID is specified by customer/user in this we have taken random ID's but making
 * sure that these timer ID are unique
*/
#define HEARTBEAT_TIMER_ID          100
#define SESSION_TIMER_ID            101
#define HEARTBEAT_TIMER_PARAM       0
#define SESSION_TIMER_PARAM         0

#define HEARTBEAT_PUBLISHING_RATE_IN_SEC       60
#define SESSION_PUBLISHING_RATE_IN_SEC         60

/**
 * @fn void vTimerInit(u8 heartbeatRate, u8 sessionRate);
 * @param heartbeatRate  HeartBeat Publishing Rate in Seconds
 * @param sessionRate    Session Publishing Rate in Seconds
*/
void vTimerInit(u8 heartbeatRate, u8 sessionRate);

#endif /********TIMER******/


#ifdef CHARGER_INFO

#define OAKTER_CHARGER_ID			"WA000822LAC1S000010-1"
#define OAKTER_FIRMWARE_VERSION		"1.0.0"
#define HEARTBEAT_PACKET			"HEARTBEAT"
#define SESSION_PACKET				"SESSION"
#define DEVICE_INFO_PACKET			"DEVICE_INFO"
#define CHARGER_ID                                  "\"WA000822LAC1S010088\"\n\t"
#define CHARGER_ID_OBJECT                           "\"dId\" :"
#define EPOCH_OBJECT                                "\"epoch\" :"
#define GSM_STRENGTH_OBJECT                         "\"gsmSignalStrength\" :"
#define CUM_KWH_VAL_OBJECT                          "\"cKwh\" :"
#define SOCKET_OBJECT                               "\n\t\"sockets\" :{\n"
#define SOCKET1_OBJECT                              "\t\t\"socket_1\" :{\n"
#define CURRENT_OBJECT                              "\t\t\t\"current\":"
#define STATE_OBJECT                                "\n\t\t\t\"state\" :"
#define NEXT_LINE_OBJECT_WITH_SINGLE_TAB            "\n\t"
#define NEXT_LINE_OBJECT_WITH_DOUBLE_TAB            "\n\t\t"
#define HEARTBEAT_PACKET_END                        "\n}\n}\n}"
char mqttSting[250] ;

//char *xSendMqttData(float cKwh, float kwh, float current,u8 state, u8 reconnect, char *packet_Name, u8 version);

#endif /***********CHARGER_INFO***********/

#endif /*******CHARGER_CONFIGURATION_H_******/
