/*
 * BT_Configuration.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Admin
 */

#include "BT_Configuration.h"

BTParam Bluetooth;

#ifdef BT_CLASSIC

static void vBtCallback(s32 event, s32 errCode, void* param1, void* param2)
{
    ST_BT_BasicInfo *pstNewBtdev = NULL;
    ST_BT_BasicInfo *pstconBtdev = NULL;
    s32 ret = RIL_AT_SUCCESS;
    s32 connid = -1;

    switch(event)
    {
        case MSG_BT_SCAN_IND :

            if(URC_BT_SCAN_FINISHED== errCode)
            {
                APP_DEBUG("Scan is over.\r\n");
                //APP_DEBUG("Pair/Connect if need.\r\n");
                RIL_BT_GetDevListInfo();
                //here obtain ril layer table list for later use
                g_dev_info = RIL_BT_GetDevListPointer();
                g_pair_search = TRUE;
            }
            if(URC_BT_SCAN_FOUND == errCode)
            {
                pstNewBtdev = (ST_BT_BasicInfo *)param1;
                //you can manage the scan device here,or you don't need to manage it ,for ril layer already handle it
                APP_DEBUG("BTHdl[0x%08x] Addr[%s] Name[%s]\r\n",pstNewBtdev->devHdl,pstNewBtdev->addr,pstNewBtdev->name);

            }
            break;
         case MSG_BT_PAIR_IND :
              if(URC_BT_NEED_PASSKEY == errCode)
              {
                    //must ask for pincode;
                    pstconBtdev = (ST_BT_BasicInfo*)param1;
                    APP_DEBUG("Pair device BTHdl: 0x%08x\r\n",pstconBtdev->devHdl);
                    APP_DEBUG("Pair device addr: %s\r\n",pstconBtdev->addr);
                    APP_DEBUG("Waiting for pair confirm with pinCode...\r\n");
              }
              else if(URC_BT_NO_NEED_PASSKEY == errCode)
              {
                    //no need pincode
                    pstconBtdev = (ST_BT_BasicInfo*)param1;
                    Ql_strncpy(pinCode,(char*)param2,BT_PIN_LEN);
					pinCode[BT_PIN_LEN-1] = 0;
                    APP_DEBUG("Pair device BTHdl: 0x%08x\r\n",pstconBtdev->devHdl);
                    APP_DEBUG("Pair device addr: %s\r\n",pstconBtdev->addr);
                    APP_DEBUG("Pair pin code: %s\r\n",pinCode);
                    APP_DEBUG("pair confirm automatically\r\n");
                    RIL_BT_PairConfirm(TRUE,NULL);
              }

            break;
         case MSG_BT_PAIR_CNF_IND :
            if(URC_BT_PAIR_CNF_SUCCESS == errCode)
            {
                pstconBtdev = (ST_BT_BasicInfo*)param1;
                APP_DEBUG("Paired successful.\r\n");
            }
            else
            {
                APP_DEBUG("Paired failed.\r\n");
            }
            break;

         case MSG_BT_SPP_CONN_IND :

              if(URC_BT_CONN_SUCCESS == errCode )
              {

                Ql_memcpy(&(BTSppDev1.btDevice),(ST_BT_BasicInfo *)param1,sizeof(ST_BT_BasicInfo));

                APP_DEBUG("Connect successful.\r\n");
              }
              else
              {
                APP_DEBUG("Connect failed.\r\n");
              }

              break;

         case MSG_BT_RECV_IND :

             connid = *(s32 *)param1;
             pstconBtdev = (ST_BT_BasicInfo *)param2;
             Ql_memcpy(&pSppRecHdl,pstconBtdev,sizeof(pSppRecHdl));
             APP_DEBUG("SPP receive data from BTHdl[0x%08x].\r\n",pSppRecHdl.devHdl);
             break;

         case MSG_BT_PAIR_REQ:

              if(URC_BT_NEED_PASSKEY == errCode)
              {
                   //must ask for pincode;
                    pstconBtdev = (ST_BT_BasicInfo*)param1;
                    APP_DEBUG("Pair device BTHdl: 0x%08x\r\n",pstconBtdev->devHdl);
                    APP_DEBUG("Pair device addr: %s\r\n",pstconBtdev->addr);
                    APP_DEBUG("Waiting for pair confirm with pinCode...\r\n");
              }

              if(URC_BT_NO_NEED_PASSKEY == errCode)
              {
                    //no need pincode
                    pstconBtdev = (ST_BT_BasicInfo*)param1;
                    Ql_strncpy(pinCode,(char*)param2,BT_PIN_LEN);
					pinCode[BT_PIN_LEN-1] = 0;
                    APP_DEBUG("Pair device BTHdl: 0x%08x\r\n",pstconBtdev->devHdl);
                    APP_DEBUG("Pair device addr: %s\r\n",pstconBtdev->addr);
                    APP_DEBUG("Pair pin code: %s\r\n",pinCode);
                    APP_DEBUG("pair confirm automatically\r\n");
                    RIL_BT_PairConfirm(TRUE,NULL);
              }

            break;

        case  MSG_BT_CONN_REQ :

            pstconBtdev = (ST_BT_BasicInfo*)param1;
            APP_DEBUG("Get a connect req\r\n");
            APP_DEBUG("BTHdl: 0x%08x\r\n",pstconBtdev->devHdl);
            APP_DEBUG("Addr: %s\r\n",pstconBtdev->addr);
            APP_DEBUG("Name: %s\r\n",pstconBtdev->name);

            APP_DEBUG("Waiting connect accept.\r\n");

       case  MSG_BT_DISCONN_IND :

             if(URC_BT_DISCONNECT_PASSIVE == errCode || URC_BT_DISCONNECT_POSITIVE == errCode)
             {
                APP_DEBUG("Disconnect ok!\r\n");
             }

          break;


        default :
            break;
    }
}


void vBluetoothInit(void)
{
    s32 ret = RIL_AT_FAILED ;
    // s32 ret = RIL_AT_SUCCESS;
    /**
     * @fn Ql_RIL_Initialize()
     * @brief This function initializes RIl-related functions. and sets the initial AT commands 
    */
	 Ql_RIL_Initialize();
    APP_DEBUG("After Ql_RIL_Initialize.  ret = %d \r\n", ret);
    /**
     * @fn  RIL_BT_Switch(BL_POWERON);
     * @brief This function turn ON and OFF BT Communication 
     * @param 0 - OFF & 1 ON
    */
    RIL_BT_Switch(BL_POWERON);
    Ql_memset(Bluetooth.btName,0,sizeof(Bluetooth.btName));
    /**
     * @fn RIL_BT_GetName(RIL_BT_GetName(*char addr[BT_NAME_LEN],u8 len)
     * @brief This function get the name of BT device 
     * @param bt_name Char Array to get Bluetooth Name 
     * @param BT_NAME_LEN size of array 
    */
    RIL_BT_GetName(Bluetooth.btName,sizeof(Bluetooth.btName));

    APP_DEBUG("BT device name is: %s.\r\n",Bluetooth.btName);
    /**
     * @fn RIL_BT_Initialize(CALLBACK_BT_IND cb)
     * @brief Bluetooth initialization after power on, register callback and upate paired info
     * @param vBtCallback - Callback function to be registerd
    */
    RIL_BT_Initialize(vBtCallback);
    /**
     * @fn s32 RIL_BT_SetVisble(Enum_VisibleMode mode,u8 timeout)
     * @brief This function sets Bluetooth to viewed or not 
     * @param mode BT_MODE_INVISBLE_FOREVER = Invisible Mode 
     *             BT_MODE_VISIBLE_FOREVER = Visible Forever
     *             BT_MODE_VISIBLE_TMEPORARY = Visibility Temporary 
     * @param timeout BT_VISIBILITY_MODE_TIMEOUT = When mode is set to "BT_MODE_VISIBLE_TMEPORARY", this param decides during 
     * which time bluetooth can be found by others unit second, can be 1-255, after timeout, MSG_BT_INVISIBLE will be triggered,
     * other mode is ignored. 
    */
    RIL_BT_SetVisble(BT_MODE_VISIBLE_FOREVER, BT_VISIBILITY_MODE_TIMEOUT);
    /**
     * 
    */
   while (ret != RIL_AT_SUCCESS)
   {
    ret = RIL_BT_ConnAccept(TRUE,BT_SPP_CONN_MODE_TRANS);
    if(RIL_AT_SUCCESS != ret) 
        APP_DEBUG("Pairing failed!\r\n");
    if(RIL_AT_SUCCESS == ret)
    	APP_DEBUG("Pairing Sucessfull. \n");
    Ql_Sleep(DELAY_IN_MILLIS_500);
   }

}

#endif
