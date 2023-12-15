
#include "RGB.h"



#ifdef RGB

void vRgbInit(void)
{
    Ql_GPIO_Init(RGB1_BLUE_PIN, PINDIRECTION_OUT, PINLEVEL_HIGH, PINPULLSEL_PULLUP);
    Ql_GPIO_Init(RGB2_BLUE_PIN, PINDIRECTION_OUT, PINLEVEL_HIGH, PINPULLSEL_PULLUP);
    Ql_GPIO_Init(RGB1_GREEN_PIN, PINDIRECTION_OUT, PINLEVEL_HIGH, PINPULLSEL_PULLUP);
    Ql_GPIO_Init(RGB1_RED_PIN, PINDIRECTION_OUT, PINLEVEL_HIGH, PINPULLSEL_PULLUP);
    Ql_GPIO_Init(RGB2_GREEN_PIN, PINDIRECTION_OUT, PINLEVEL_HIGH, PINPULLSEL_PULLUP);
    Ql_GPIO_Init(RGB2_RED_PIN, PINDIRECTION_OUT, PINLEVEL_HIGH, PINPULLSEL_PULLUP);
    vRgbDeInit();
}
void vRgbDeInit(void)
{
    Ql_GPIO_SetLevel(RGB1_BLUE_PIN,     PINLEVEL_LOW);
    Ql_GPIO_SetLevel(RGB2_BLUE_PIN,     PINLEVEL_LOW);
    Ql_GPIO_SetLevel(RGB1_GREEN_PIN,    PINLEVEL_LOW);
    Ql_GPIO_SetLevel(RGB2_GREEN_PIN,    PINLEVEL_LOW);
    Ql_GPIO_SetLevel(RGB1_RED_PIN,      PINLEVEL_LOW);
    Ql_GPIO_SetLevel(RGB2_RED_PIN,      PINLEVEL_LOW);    
}

void vRgbColorState(u8 state)
{
    switch (state)
    {
        case(GREEN_RGB):
            Ql_GPIO_SetLevel(RGB1_RED_PIN,      PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_BLUE_PIN,     PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB2_RED_PIN,      PINLEVEL_LOW); 
            Ql_GPIO_SetLevel(RGB2_BLUE_PIN,     PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_GREEN_PIN,    PINLEVEL_HIGH);
            Ql_GPIO_SetLevel(RGB2_GREEN_PIN,    PINLEVEL_HIGH);
        break;
        case(RED_RGB):
            Ql_GPIO_SetLevel(RGB1_GREEN_PIN,    PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_BLUE_PIN,     PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB2_GREEN_PIN,    PINLEVEL_LOW);        
            Ql_GPIO_SetLevel(RGB2_BLUE_PIN,     PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_RED_PIN,      PINLEVEL_HIGH);
            Ql_GPIO_SetLevel(RGB2_RED_PIN,      PINLEVEL_HIGH); 
        break;
        case(BLUE_RGB):
            Ql_GPIO_SetLevel(RGB1_GREEN_PIN,    PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_RED_PIN,      PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB2_GREEN_PIN,    PINLEVEL_LOW); 
            Ql_GPIO_SetLevel(RGB2_RED_PIN,      PINLEVEL_LOW); 
            Ql_GPIO_SetLevel(RGB1_BLUE_PIN,     PINLEVEL_HIGH);
            Ql_GPIO_SetLevel(RGB2_BLUE_PIN,     PINLEVEL_HIGH);
        break;
        case(WHITE_RGB):
            Ql_GPIO_SetLevel(RGB1_RED_PIN,      PINLEVEL_HIGH);
            Ql_GPIO_SetLevel(RGB1_GREEN_PIN,    PINLEVEL_HIGH);
            Ql_GPIO_SetLevel(RGB1_BLUE_PIN,     PINLEVEL_HIGH);
            Ql_GPIO_SetLevel(RGB2_RED_PIN,      PINLEVEL_HIGH); 
            Ql_GPIO_SetLevel(RGB2_GREEN_PIN,    PINLEVEL_HIGH);
            Ql_GPIO_SetLevel(RGB2_BLUE_PIN,     PINLEVEL_HIGH);
        break;
        case(GREEN_RGB_BLINK):
            Ql_GPIO_SetLevel(RGB1_RED_PIN,      PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_BLUE_PIN,     PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB2_RED_PIN,      PINLEVEL_LOW); 
            Ql_GPIO_SetLevel(RGB2_BLUE_PIN,     PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_GREEN_PIN,    PINLEVEL_HIGH);
            Ql_GPIO_SetLevel(RGB2_GREEN_PIN,    PINLEVEL_HIGH);
            Ql_Sleep(DELAY_IN_MILLIS_500);
            Ql_GPIO_SetLevel(RGB1_RED_PIN,      PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_BLUE_PIN,     PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB2_RED_PIN,      PINLEVEL_LOW); 
            Ql_GPIO_SetLevel(RGB2_BLUE_PIN,     PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_GREEN_PIN,    PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB2_GREEN_PIN,    PINLEVEL_LOW);
            Ql_Sleep(DELAY_IN_MILLIS_500);

        break;
        case(RED_RGB_BLINK):
            Ql_GPIO_SetLevel(RGB1_GREEN_PIN,    PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_BLUE_PIN,     PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB2_GREEN_PIN,    PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB2_BLUE_PIN,     PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_RED_PIN,      PINLEVEL_HIGH);
            Ql_GPIO_SetLevel(RGB2_RED_PIN,      PINLEVEL_HIGH); 
            Ql_Sleep(DELAY_IN_MILLIS_500);
            Ql_GPIO_SetLevel(RGB1_RED_PIN,      PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_BLUE_PIN,     PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB2_RED_PIN,      PINLEVEL_LOW); 
            Ql_GPIO_SetLevel(RGB2_BLUE_PIN,     PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_GREEN_PIN,    PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB2_GREEN_PIN,    PINLEVEL_LOW);
            Ql_Sleep(DELAY_IN_MILLIS_500);
        break;
        case(BLUE_RGB_BLINK):
            Ql_GPIO_SetLevel(RGB1_GREEN_PIN,    PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_RED_PIN,      PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB2_GREEN_PIN,    PINLEVEL_LOW); 
            Ql_GPIO_SetLevel(RGB2_RED_PIN,      PINLEVEL_LOW); 
            Ql_GPIO_SetLevel(RGB1_BLUE_PIN,     PINLEVEL_HIGH);
            Ql_GPIO_SetLevel(RGB2_BLUE_PIN,     PINLEVEL_HIGH);
            Ql_Sleep(DELAY_IN_MILLIS_500);
            Ql_GPIO_SetLevel(RGB1_RED_PIN,      PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_BLUE_PIN,     PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB2_RED_PIN,      PINLEVEL_LOW); 
            Ql_GPIO_SetLevel(RGB2_BLUE_PIN,     PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_GREEN_PIN,    PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB2_GREEN_PIN,    PINLEVEL_LOW);
            Ql_Sleep(DELAY_IN_MILLIS_500);          
        break;
        case(WHITE_RGB_BLINK):
            Ql_GPIO_SetLevel(RGB1_RED_PIN,      PINLEVEL_HIGH);
            Ql_GPIO_SetLevel(RGB1_GREEN_PIN,    PINLEVEL_HIGH);
            Ql_GPIO_SetLevel(RGB1_BLUE_PIN,     PINLEVEL_HIGH);
            Ql_GPIO_SetLevel(RGB2_RED_PIN,      PINLEVEL_HIGH); 
            Ql_GPIO_SetLevel(RGB2_GREEN_PIN,    PINLEVEL_HIGH);
            Ql_GPIO_SetLevel(RGB2_BLUE_PIN,     PINLEVEL_HIGH);  
            Ql_Sleep(DELAY_IN_MILLIS_500);
            Ql_GPIO_SetLevel(RGB1_RED_PIN,      PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_BLUE_PIN,     PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB2_RED_PIN,      PINLEVEL_LOW); 
            Ql_GPIO_SetLevel(RGB2_BLUE_PIN,     PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_GREEN_PIN,    PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB2_GREEN_PIN,    PINLEVEL_LOW);
            Ql_Sleep(DELAY_IN_MILLIS_500);      
        break;
        case (NO_LIGHT):
            Ql_GPIO_SetLevel(RGB1_RED_PIN,      PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_BLUE_PIN,     PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB2_RED_PIN,      PINLEVEL_LOW); 
            Ql_GPIO_SetLevel(RGB2_BLUE_PIN,     PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_GREEN_PIN,    PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB2_GREEN_PIN,    PINLEVEL_LOW);        
        default:
            Ql_GPIO_SetLevel(RGB1_RED_PIN,      PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_BLUE_PIN,     PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB2_RED_PIN,      PINLEVEL_LOW); 
            Ql_GPIO_SetLevel(RGB2_BLUE_PIN,     PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB1_GREEN_PIN,    PINLEVEL_LOW);
            Ql_GPIO_SetLevel(RGB2_GREEN_PIN,    PINLEVEL_LOW);         
        break;
    }
}

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


#endif /**********RGB************/
