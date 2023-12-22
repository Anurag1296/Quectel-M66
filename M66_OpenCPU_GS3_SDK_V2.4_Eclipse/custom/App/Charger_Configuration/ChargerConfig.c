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




