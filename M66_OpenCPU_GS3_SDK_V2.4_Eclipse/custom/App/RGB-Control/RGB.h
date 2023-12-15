/**
 *    @file BLE_Configuration.c
 *  @author Anurag Maheshwari (anu-maheshwari)
 *    @date 21 March 2023
 *   @brief This code function will start Nimble-BLE and will have one server with once service
 *          ID and one characterstic ID 
 */


#ifndef RGB_CONTROL_H_
#define RGB_CONTROL_H_

#include "Charger_Configuration/configuration.h"

#ifdef RGB

#define RGB1_RED_PIN        PINNAME_DTR
#define RGB1_BLUE_PIN       PINNAME_RTS
#define RGB1_GREEN_PIN      PINNAME_CTS
#define RGB2_RED_PIN        PINNAME_TXD_AUX
#define RGB2_BLUE_PIN       PINNAME_PCM_CLK
#define RGB2_GREEN_PIN      PINNAME_RXD_AUX

#define GREEN_RGB           1
#define RED_RGB             2
#define BLUE_RGB            3
#define WHITE_RGB           4
#define GREEN_RGB_BLINK     5
#define RED_RGB_BLINK       6
#define BLUE_RGB_BLINK      7
#define WHITE_RGB_BLINK     8
#define NO_LIGHT            9

void vRgbInit(void);
void vRgbDeInit(void);
void vRgbColorState(u8 state);

//char *xSendMqttData(float cKwh, float kwh, float current,u8 state, u8 reconnect, char *packet_Name, u8 version);


#endif /**********RGB*********/

#endif /*******RGB_CONTROL_H_******/
