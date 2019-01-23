/**
*#include "mbed.h"
*#include "soundsensor.h"
*soundsensor sound(A0);
*bool toDb = true;
*
*int main()
*{
*    while (true) {
*        printf("Loudness: %f\r\n", sound.listen(toDb));
*        wait(0.5);
*    }
*}
**/

//Version mbed: 164

#ifndef SOUNDSENSOR
#define SOUNDSENSOR
#include "mbed.h"

class soundsensor{
    private:
        PinName _pin;
    public:
        soundsensor(PinName);
        void setPin(PinName pin);
        PinName getPin();
        float convertToDb(float);
        float revertFromDb(float);
        float listen(bool toDb);
};

#endif