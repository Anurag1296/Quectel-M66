/*
 * RelayControl.h
 *
 *  Created on: Dec 14, 2023
 *      Author: Admin
 */

#ifndef RELAYCONTROL_H_
#define RELAYCONTROL_H_

#include "configuration.h"

#define UART

#ifdef RELAY
#define CHARGER_RELAY_PIN			    PINNAME_PCM_SYNC
/**
 * @fn void vRelayInit(void);
 * @brief This function is to initialize Realy I/O Pin 
*/
void vRelayInit(void);
/**
 * @fn void vRelayOn(void);
 * @brief This function is to Start/Toggle ON Relay 
*/
void vRelayOn(void);
/**
 * @fn void vRelayOff(void);
 * @brief This function is to Stop/Toggle OFF Relay
*/
void vRelayOff(void);
/**
 * @fn void vRelayTest(void);
 * @brief This function toggles Relay after every 500msec.
*/
void vRelayTest(void);

#endif /**********RELAY*************/


#ifdef UART
#define UART1_BAUD_RATE_4800                4800
#define UART1_BAUD_RATE_9600                9600
#define UART1_BAUD_RATE_57600               57600
#define UART1_BAUD_RATE_115200              115200

/**
 * @fn void vUartInit(void);
 * @brief This function is to Init UART1 with defined baud rate.
*/
void vUart1Init(void);

#endif /**********UART*********/

#endif /* RELAYCONTROL_H_ */
