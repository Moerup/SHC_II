/**
*#include "steppermotor.h"
*steppermotor gate(2200, 200);
*
*
*int main() {  
*   gate.open();
*   gate.close();
*}
**/


#ifndef STEPPERMOTOR
#define STEPPERMOTOR


class steppermotor{
    private:
        int step_speed;
        int numstep;
    public:
        steppermotor(int stepSpeed, int numStep);
        void setStepSpeed(int stepSpeed);
        int getStepSpeed();
        void setNumStep(int numStep);
        int getNumStep();
        void open();
        void close();
};

#endif