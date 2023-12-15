#include "App/RGB-Control/RGB.h"
#include "App/Bluetooth_Configuration/BT_Configuration.h"



void proc_main_task(s32 taskId)
{
	ST_MSG msg;
    vUart1Init();
    msg.message = TRUE;
    #ifdef RGB
        vRgbInit();
    #endif
    #ifdef RELAY
        vRelayInit();
    #endif
    	 APP_DEBUG("<-- Testing for RIL -->\r\n");
    Ql_OS_GetMessage(&msg);
    while (msg.message != FALSE)
    {
        APP_DEBUG("IN LOOP\n");
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
         msg.message = FALSE;
        Ql_Sleep(DELAY_IN_MILLIS_500);
    }
}
