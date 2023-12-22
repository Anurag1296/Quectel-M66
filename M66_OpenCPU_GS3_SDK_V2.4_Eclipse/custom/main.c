#include "RGB.h"
#include "BT_Configuration.h"
#include "Charger_JSON.h"


void proc_main_task(s32 taskId)
{
	ST_MSG msg;
    vUart1Init();
    #ifdef RGB
        vRgbInit();
    #endif
    #ifdef RELAY
        vRelayInit();
    #endif
    printf("%s \n", (const u8 *)xSendMqttData(1,1,1,1,1,HEARTBEAT_PACKET,"asdf"));
    while (TRUE)
    {
        Ql_OS_GetMessage(&msg);
         switch(msg.message)
         {
         case MSG_ID_RIL_READY:
         	 vBluetoothInit();
           
             break;
         case MSG_ID_USER_START:
             break;
         case MSG_ID_URC_INDICATION:
             break;
         default:
             break;
         }
    }
}
