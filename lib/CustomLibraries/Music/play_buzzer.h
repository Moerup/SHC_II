/**
* @file play_buzzer.h
* @brief this cpp file is where all the logic is handled.
*
* @author Nikolaj M. & Mathias R.
*
* @date 10/1/2019
*/

//PROGRAM: play_buzzer
#ifndef PLAY_BUZZER_H
#define PLAY_BUZZER_H

#include "mbed.h"
 

namespace mbed {
///play_buzzer CLASS
class play_buzzer {
 
///INITIALIZE VARIABLES USED IN CLASS
private :
    PinName _pin;
    PwmOut _pwm;
    Timeout toff;
///FUNCTIONS AND CONSTRUCTOR
public:
    play_buzzer(PinName);
    void beep (int notes, int tones);
    void nobeep();
    int play(int song);
    void setPin(PinName pin);
    PinName getPin();
    };
};
#endif
 
            
