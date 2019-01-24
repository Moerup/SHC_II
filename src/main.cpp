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
#include "EthernetInterface.h"
#include "NTPClient.h"
#include "TS_DISCO_F746NG.h"
#include "LCD_DISCO_F746NG.h"
#include "steppermotor.h"
#include "play_buzzer.h"
#include "GUI.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Devices and pin assignment:
steppermotor gate(1200, 512);
int dooropen = 0;
DigitalOut led(D8);
bool toDb = true;

int main()
{
    SCB_CleanDCache(); // Clean the entire data cache
    SCB_DisableDCache(); // Disable the entire data cache

    // Connecting to Internet and NTP servers:
    eth.connect();

    // Variables
    TS_StateTypeDef TS_State;
    uint8_t touches = 0;
    bool touched;
    bool touchedled = false;
    bool motortouched = false;
    bool cogwheeltouched = false;
    bool alarmtouched = false;
    
    //Initial conf
    ts.Init(lcd.GetXSize(), lcd.GetYSize());
    lcd.Clear(LCD_COLOR_WHITE);
    lcd.SetBackColor(LCD_COLOR_WHITE);
    lcd.SetTextColor(LCD_COLOR_BLUE);
    lcd.SetFont(&Font24);
    
    //Startup Screen
    drawStartScreen();
    
    while(1) {
        lcd.SetTextColor(LCD_COLOR_BLUE);
        lcd.SetFont(&Font24);
        ts.GetState(&TS_State);
        
        // Touch counter and resetting bools:
        if ((TS_State.touchDetected == 0) && (touched == true)){
            touches++;
            touched = false;
            touchedled = false;
            motortouched = false;
            cogwheeltouched = false;
            alarmtouched = false;
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
            drawGate(0);
            // Funtions call to StepperMotor library
            gate.open();
            dooropen = 1;
            }
            else {
            drawGate(1);
            // Funtions call to StepperMotor library
            gate.close();
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
            while (alarmtouched == false) {
                ts.GetState(&TS_State);
                while (TS_State.touchDetected == 0 && alarmtouched == false) {
                    drawSecurity();
                    alarmtouched = true; 
                }
            }
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