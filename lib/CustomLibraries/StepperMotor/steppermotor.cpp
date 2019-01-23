#include "steppermotor.h"
#include "sMotor.h"

sMotor motor(A0, A1, A2, A3);

steppermotor::steppermotor(int stepSpeed, int numStep){
    setStepSpeed(stepSpeed);
    setNumStep(numStep);
}

void steppermotor::setStepSpeed(int stepSpeed){
    this->step_speed = stepSpeed;
}

int steppermotor::getStepSpeed(){
    return this->step_speed;
}

void steppermotor::setNumStep(int numStep){
    this->numstep = numStep;
}
        
int steppermotor::getNumStep(){
    return this->numstep;
}

void steppermotor::open(){
    motor.step(getNumStep(),0,getStepSpeed());
}

void steppermotor::close(){
    motor.step(getNumStep(),1,getStepSpeed());
}