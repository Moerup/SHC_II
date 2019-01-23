/**
*       @file main.cpp
*       @brief This program manage and activates different
*       functionality in a smart home, through a LCD screen
*
*       @author Mathias Rasmussen & Nikolaj Mørup
*       
*       @date 10/01/2019
*
*/

#include "mbed.h"
#include "rtos.h"
#include "TS_DISCO_F746NG.h"
#include "LCD_DISCO_F746NG.h"
#include "steppermotor.h"
#include "play_buzzer.h"
#include "soundsensor.h"
#include "GUI.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Devices and pin assignment:
//LCD_DISCO_F746NG lcd;
//TS_DISCO_F746NG ts;
steppermotor gate(1200, 512);
int dooropen = 0;
DigitalOut led(D8);
soundsensor sound(A3);
bool toDb = true;
Thread threadtest;
Thread threadtest2;
Thread threadtest3;

void test () {
    while (true) {
        led = !led;
        ThisThread::sleep_for(1000);
    }
}
void test2 () {
        gate.open();
}
void test3 () {
        gate.close();
}

int main()
{
    printf("0");
    // Variables
    TS_StateTypeDef TS_State;
    uint8_t touches = 0;
    bool touched;
    bool touchedled = false;
    bool motortouched = false;
    bool cogwheeltouched = false;
    
    //Initial conf
    ts.Init(lcd.GetXSize(), lcd.GetYSize());
    lcd.Clear(LCD_COLOR_WHITE);
    lcd.SetBackColor(LCD_COLOR_WHITE);
    lcd.SetTextColor(LCD_COLOR_BLUE);
    lcd.SetFont(&Font24);
    
    printf("1");
    //Bootup Screen
    //lcd.DrawBitmap(0, 50, (uint8_t *)SmartHome);
    printf("2");
    wait(4);
    //Startup Screen
    drawStartScreen();
    printf("3");
    
    //threadtest.start(test);
    //threadtest2.start(test2);
    while(1) {
        //printf("Loudness: %f\r\n", sound.listen(toDb));
        wait(0.5);
        lcd.SetTextColor(LCD_COLOR_BLUE);
        lcd.SetFont(&Font24);
        ts.GetState(&TS_State);
        
        // Touch counter and reseting bools:
        if ((TS_State.touchDetected == 0) && (touched == true)){
            touches++;
            touched = false;
            touchedled = false;
            motortouched = false;
            cogwheeltouched = false;
        }
        if (TS_State.touchDetected == 1){
            touched = true;
        }
        
        // Button 1 - Lights
        // Defining touch area for this button and then enabling the led
        if ((TS_State.touchDetected) && (TS_State.touchX[0] < 100) && (TS_State.touchY[0] > 190 )){
            while (touchedled == false){
            led = !led;
            touchedled = true;
            }
        }
        
        // Button 2 - Door
        // Defining touch area for this button and then enabling the motor. Both open and close.
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 150) && (TS_State.touchX[0] < 240) && (TS_State.touchY[0] > 190 )){
            while (motortouched == false) {
            lcd.Clear(LCD_COLOR_WHITE);
            if (dooropen == 0) {
            threadtest2.set_priority(osPriorityHigh);
            threadtest2.start(&test2);
            dooropen = 1;
            }
            else {
            threadtest3.set_priority(osPriorityHigh);
            threadtest3.start(&test3);
            dooropen = 0;
            } 
            motortouched = true;
            lcd.Clear(LCD_COLOR_WHITE);
            drawStartScreen();
            }
        }
        
        // Button 3 - Music Library
        // Defining touch area for this button and then opening the music library:
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 270) && (TS_State.touchX[0] < 360) && (TS_State.touchY[0] > 190 )){
            drawMusicLibrary();
            drawStartScreen();
        }
        
        // Button 4 - Alarm
        // Defining touch area for this button:
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 410) && (TS_State.touchX[0] < 479) && (TS_State.touchY[0] > 190 )){
            drawSecurity();
            drawStartScreen();
        }
        
        //Button 5 - Settings
        // Defining touch area for this button:
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 400) && (TS_State.touchX[0] < 479) && (TS_State.touchY[0] < 70 )){
            while (cogwheeltouched == false){
                ts.GetState(&TS_State);
                while (TS_State.touchDetected == 0 && cogwheeltouched == false) {
                    lcd.Clear(LCD_COLOR_WHITE);
                    drawSettings();
                    cogwheeltouched = true;
                }
            }
        }
    }
}