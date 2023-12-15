#include "configuration.h"



//static ST_BT_BasicInfo pSppRecHdl;


/*******************************************************************/
#ifdef TIMER
void vHeartbeatHandler(u32 timerId, void* param)
{
    printf("HEARTBEAT Timer_handler \n");
}

void vSessionHandler(u32 timerId,  void* param)
{
    printf("SESSION Timer_handler \n");
}

void vTimerInit(u8 heartbeatRate, u8 sessionRate)
{
	Ql_Timer_Register(HEARTBEAT_TIMER_ID,vHeartbeatHandler, HEARTBEAT_TIMER_PARAM);
    Ql_Timer_Register(SESSION_TIMER_ID,vSessionHandler, SESSION_TIMER_PARAM);
    Ql_Timer_Start(HEARTBEAT_TIMER_ID,heartbeatRate * 1000,TRUE);
    Ql_Timer_Start(SESSION_TIMER_ID,sessionRate * 1000,TRUE);
}


void vTimerStop(void)
{
    Ql_Timer_Stop(HEARTBEAT_TIMER_ID);
    Ql_Timer_Stop(SESSION_TIMER_ID);
}

#endif /**************TIMER************/





/*******************************************************************/
//char *xSendMqttData(float cKwh, float kwh, float current,u8 state, u8 reconnect, char *packet_Name, u8 version)
//{
//	jasonPaylod = cJSON_CreateObject();
//	    cJSON_AddNumberToObject(jasonPaylod, "cKwh", cKwh);
//	    cJSON_AddNumberToObject(jasonPaylod, "kwh", kwh);
//	    cJSON_AddNumberToObject(jasonPaylod, "re", state);
//	    cJSON_AddNumberToObject(jasonPaylod, "amp", current);
//	    cJSON_AddStringToObject(jasonPaylod, "dsc", packet_Name);
//	    cJSON_AddStringToObject(jasonPaylod, "dId", OAKTER_CHARGER_ID);
//	    cJSON_AddStringToObject(jasonPaylod, "v", OAKTER_FIRMWARE_VERSION);
//	    cJSON_AddNumberToObject(jasonPaylod, "ReCo", reconnect);
//	    char * jSONBody = cJSON_Print(jasonPaylod);
//	    cJSON_Delete(jasonPaylod);
//	    return jSONBody;
//}

//char *xSendMqttData(float cKwh, float kwh, float current,u8 state, u8 reconnect, char *packet_Name, u8 version)
//{
//	    char assignVal[10] = " ";
//	    char mqttSting[250] ;
//	    strcat(mqttSting,CHARGER_ID_OBJECT);
//	    strcat(mqttSting, CHARGER_ID);
//	    strcat(mqttSting, EPOCH_OBJECT);
//	    sprintf(assignVal , "%0.02f", cKwh);
//	    strcat(mqttSting, assignVal);
//	    strcat(mqttSting,NEXT_LINE_OBJECT_WITH_SINGLE_TAB);
//	    strcat(mqttSting,GSM_STRENGTH_OBJECT);
//	    memset(assignVal,0,sizeof(assignVal));
//	    sprintf(assignVal,"%0.02f",kwh);
//	    strcat(mqttSting,assignVal);
//	    memset(assignVal,0,sizeof(assignVal));
//	    strcat(mqttSting,SOCKET_OBJECT);
//	    strcat(mqttSting,SOCKET1_OBJECT);
//	     strcat(mqttSting,CURRENT_OBJECT);
//	    sprintf(assignVal,"%0.02f",current);
//	    strcat(mqttSting,assignVal);
//	    memset(assignVal,0,sizeof(assignVal));
//	    strcat(mqttSting,STATE_OBJECT);
//	    sprintf(assignVal,"%d",state);
//	    strcat(mqttSting,assignVal);
//	     memset(assignVal,0,sizeof(assignVal));
//	     strcat(mqttSting,HEARTBEAT_PACKET_END);
//	     char *result = malloc(strlen(mqttSting) + 1);
//	    strcpy(result, mqttSting);
//	    return result;
//}

//#endif
