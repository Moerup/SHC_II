#include "soundsensor.h"

soundsensor::soundsensor(PinName pin){
    soundsensor::setPin(pin);
}

void soundsensor::setPin(PinName pin){
    this->_pin=pin;
}

PinName soundsensor::getPin(){
    return this->_pin;
}

float soundsensor::convertToDb(float value){
    return 16.801 * log(value/65535) + 9.872;
}

float soundsensor::revertFromDb(float value){
/**
*CODE NEEDS TO BE IMPLEMENTED
**/
    return 0;
}

float soundsensor::listen(bool toDb){
    AnalogIn sensor(this->getPin());
    int values[] = {};
    float sum;
    float average;
    
    for(int i=0;i<100;i++){
       values[i] = sensor.read_u16();
        wait(0.0001);
    }
 
    for(int j=0;j<100;j++){
        sum += values[j];   
        }
    average = sum/100;

    if(toDb){
        return this->convertToDb(average);
    }else{
        return average;
    }
}