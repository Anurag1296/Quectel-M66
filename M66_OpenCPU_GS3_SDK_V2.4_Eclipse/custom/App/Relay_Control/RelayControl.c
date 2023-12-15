/*
 * RelayControl.c
 *
 *  Created on: Dec 14, 2023
 *      Author: Admin
 */


#include "RelayControl.h"



#ifdef RELAY

void vRelayInit(void)
{
    Ql_GPIO_Init(CHARGER_RELAY_PIN, PINDIRECTION_OUT, PINLEVEL_HIGH, PINPULLSEL_PULLUP);
    vRelayOff();
}
void vRelayOn(void)
{
    Ql_GPIO_SetLevel(CHARGER_RELAY_PIN,    PINLEVEL_HIGH);
}
void vRelayOff(void)
{
    Ql_GPIO_SetLevel(CHARGER_RELAY_PIN,      PINLEVEL_LOW);
}
void vRelayTest(void)
{
    Ql_GPIO_SetLevel(CHARGER_RELAY_PIN,    PINLEVEL_HIGH);
    Ql_Sleep(DELAY_IN_MILLIS_500);
    Ql_GPIO_SetLevel(CHARGER_RELAY_PIN,      PINLEVEL_LOW);
    Ql_Sleep(DELAY_IN_MILLIS_500);
}
#endif  /***********RELAY***********/


#ifdef UART

void vUart1Callback(Enum_SerialPort port, Enum_UARTEventType msg, bool level, void* customizedPara)
{

}

void vUart1Init(void)
{
    // Register & open UART port
    Ql_UART_Register(UART_PORT1, vUart1Callback, NULL);
    Ql_UART_Open(UART_PORT1, UART1_BAUD_RATE_115200, FC_NONE);
}

#endif 