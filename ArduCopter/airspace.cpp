/*
 * =====================================================================================
 *
 *       Filename:  airspace.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/01/2018 02:08:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hong-Bin Yoon (HBY), hong-bin@airspace.co
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "Copter.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  as_take_control
 *  Description:  Requests flight mode changes based on RC Channel 7 
 *                Scheduled at 10 Hz
 * =====================================================================================
 */
    void
Copter::as_take_control (  )
{
    if((int)channel_7->get_control_in() < 500){
        //gcs().send_text(MAV_SEVERITY_WARNING, "STABILIZE");
        if(control_mode == GUIDED_NO_GPS){
            gcs().send_text(MAV_SEVERITY_WARNING, "Ch7 triggered. Requesting LOITER");
            set_mode(LOITER, MODE_REASON_GCS_FAILSAFE);
        }
    }else{
        //gcs().send_text(MAV_SEVERITY_WARNING, "GUIDED");
        if(control_mode != GUIDED_NO_GPS){
            set_mode(GUIDED_NO_GPS, MODE_REASON_GCS_FAILSAFE);
        }
    }
}		/* -----  end of function as_take_control  ----- */

