/*
 * Charger_JSON.h
 *
 *  Created on: Dec 22, 2023
 *      Author: Admin
 */

#ifndef CHARGER_JSON_H_
#define CHARGER_JSON_H_

#include "configuration.h"

u8 *xSendMqttData(float cKwh, float kwh, float current,u32 state, u32 reconnect, u8 *packet_Name, u8 version);
//u8 *xSendMqttData(float cKwh, float kwh, float current,u32 state);
#endif /* CHARGER_JSON_H_ */
