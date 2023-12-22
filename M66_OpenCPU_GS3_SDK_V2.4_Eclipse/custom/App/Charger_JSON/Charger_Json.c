/*
 * Charger_Json.c
 *
 *  Created on: Dec 22, 2023
 *      Author: Admin
 */

#include "Charger_JSON.h"

/*******************************************************************/
 u8 *xSendMqttData(float cKwh, float kwh, float current,u32 state, u32 reconnect, u8 *packet_Name, u8 version)
 {
 	    cJSON	*jasonPaylod = cJSON_CreateObject();
 	    cJSON_AddNumberToObject(jasonPaylod, "cKwh", cKwh);
 	    cJSON_AddNumberToObject(jasonPaylod, "kwh", kwh);
 	    cJSON_AddNumberToObject(jasonPaylod, "re", state);
 	    cJSON_AddNumberToObject(jasonPaylod, "amp", current);
 	    cJSON_AddStringToObject(jasonPaylod, "dsc", packet_Name);
 	    cJSON_AddStringToObject(jasonPaylod, "dId", OAKTER_CHARGER_ID);
 	    cJSON_AddStringToObject(jasonPaylod, "v", OAKTER_FIRMWARE_VERSION);
 	    cJSON_AddNumberToObject(jasonPaylod, "ReCo", reconnect);
 	    char * jSONBody = cJSON_Print(jasonPaylod);
 	    cJSON_Delete(jasonPaylod);
 	    return jSONBody;
 }

//u8 *xSendMqttData(float cKwh, float kwh, float current,u32 state)
//{
//	    u8 assignVal[10] = " ";
//	    u8 mqttSting[250] ;
//	    Ql_strcat(mqttSting,CHARGER_ID_OBJECT);
//	    Ql_strcat(mqttSting, CHARGER_ID);
//	    Ql_strcat(mqttSting, EPOCH_OBJECT);
//	    Ql_sprintf(assignVal , "%0.02f", cKwh);
//	    Ql_strcat(mqttSting, assignVal);
//	    Ql_strcat(mqttSting,NEXT_LINE_OBJECT_WITH_SINGLE_TAB);
//	    Ql_strcat(mqttSting,GSM_STRENGTH_OBJECT);
//	    Ql_memset(assignVal,0,sizeof(assignVal));
//	    Ql_sprintf(assignVal,"%0.02f",kwh);
//	    Ql_strcat(mqttSting,assignVal);
//	    Ql_memset(assignVal,0,sizeof(assignVal));
//	    Ql_strcat(mqttSting,SOCKET_OBJECT);
//	    Ql_strcat(mqttSting,SOCKET1_OBJECT);
//	    Ql_strcat(mqttSting,CURRENT_OBJECT);
//	    Ql_sprintf(assignVal,"%0.02f",current);
//	    Ql_strcat(mqttSting,assignVal);
//	    Ql_memset(assignVal,0,sizeof(assignVal));
//	    Ql_strcat(mqttSting,STATE_OBJECT);
//	    Ql_sprintf(assignVal,"%d",state);
//	    Ql_strcat(mqttSting,assignVal);
//	    Ql_memset(assignVal,0,sizeof(assignVal));
//	    Ql_strcat(mqttSting,HEARTBEAT_PACKET_END);
//	    u8 *result = malloc(strlen(mqttSting) + 1);
//	    Ql_strcpy(result, mqttSting);
//	    return result;
//}

//#endif
