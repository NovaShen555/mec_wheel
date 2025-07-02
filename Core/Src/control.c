#include "control.h"
PID_LocTypeDef PID_V={-1.20f,-1.20f/200.0,0.0f,0,0,0,0};
// Created by link on 25-7-3.
void PID_output(float set,float ture, PID_LocTypeDef *PID, float limit){

    (PID->er)=set-ture;
    PID->LocSum=PID->LocSum+PID->er;
    PID->output = (PID->Kp)*(PID->er)+(PID->Ki)*(PID->LocSum)-(PID->Kd)*(PID->er-PID->er_1);
    if (PID->LocSum >= limit){

        PID->LocSum = limit;
    }

    if ( PID->LocSum <= limit){

        PID->LocSum =limit;

    }
    PID->er_1=PID->er;
}
