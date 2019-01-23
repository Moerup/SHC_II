#ifndef DRAWIMAGE_H
#define DRAWIMAGE_H

#include "mbed.h"
#include "LCD_DISCO_F746NG.h"
#include "TS_DISCO_F746NG.h"
#include <stdio.h>
#include <string>
#include <iostream>

// Including images:
#include "Cancel.h"
#include "Check.h"
#include "CogWheel.h"
#include "DarthVader.h"
#include "Delete.h"
#include "Home.h"
#include "LightBulb.h"
#include "Motor.h"
#include "Music.h"
#include "Pirate.h"
#include "Security.h"
//#include "SmartHome.h"


LCD_DISCO_F746NG lcd;
TS_DISCO_F746NG ts;
TS_StateTypeDef TS_State;
play_buzzer buzzer(D6);
bool enteredlibrary;
bool enteredsecurity;


//Draw StartUp Screen
void drawStartScreen() {
    lcd.Clear(LCD_COLOR_WHITE);
    //lcd.DrawBitmap(0, 50, (uint8_t *)SmartHome);
    lcd.DrawBitmap(416, 0, (uint8_t *)CogWheel);
    lcd.DrawBitmap(0, 192, (uint8_t *)LightBulb);
    lcd.DrawBitmap(133, 192, (uint8_t *)Motor);
    lcd.DrawBitmap(266, 192, (uint8_t *)Music);
    lcd.DrawBitmap(399, 192, (uint8_t *)Security);
}

//Draw Music Library
void drawMusicLibrary() {

    enteredlibrary = true;
    lcd.Clear(LCD_COLOR_WHITE);
    lcd.DisplayStringAt(0, LINE(0), (uint8_t *)"Music Library", LEFT_MODE);
    lcd.SetTextColor(LCD_COLOR_BLACK);
    lcd.DisplayStringAt(70,70, (uint8_t *)"Star Wars", LEFT_MODE);
    lcd.DrawBitmap(0, 50, (uint8_t *)DarthVader);
    lcd.DisplayStringAt(70,140, (uint8_t *)"Pirates", LEFT_MODE);
    lcd.DrawBitmap(0, 120, (uint8_t *)Pirate);
    lcd.DrawBitmap(416, 0, (uint8_t *)Cancel);
    
    while (enteredlibrary == true) {
        ts.GetState(&TS_State);
        
        // Button 1 - Star Wars
        // Defining touch area for this button:
        if ((TS_State.touchDetected) && (TS_State.touchX[0] < 170) && (TS_State.touchX[0] > 5) && (TS_State.touchY[0] > 50) && (TS_State.touchY[0] < 110)){
            lcd.Clear(LCD_COLOR_WHITE);
            buzzer.play(1);
            buzzer.nobeep();
            enteredlibrary = false;
        }
        // Button 2 - Pirates
        // Defining touch area for this button:
        if ((TS_State.touchDetected) && (TS_State.touchX[0] < 170) && (TS_State.touchX[0] > 5) && (TS_State.touchY[0] > 120) && (TS_State.touchY[0] < 180)){
            lcd.Clear(LCD_COLOR_WHITE);
            buzzer.play(2);
            buzzer.nobeep();
            enteredlibrary = false;
        }
        // Button 3 - Cancel
        // Defining touch area for this button:
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 400) && (TS_State.touchX[0] < 479) && (TS_State.touchY[0] < 70 )) {
            lcd.Clear(LCD_COLOR_WHITE);
            enteredlibrary = false;
        }
    }
}

//Draw Settings Screen
void drawSettings() {
    lcd.Clear(LCD_COLOR_WHITE);
    lcd.DrawBitmap(416, 0, (uint8_t *)Home);
    
    bool enteredsettings = true;
    bool hometouched = false;
     
    while (enteredsettings == true) {
        ts.GetState(&TS_State);
        printf("1");
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 400) && (TS_State.touchX[0] < 479) && (TS_State.touchY[0] < 70 )){
            while (hometouched == false){
                ts.GetState(&TS_State);
                printf("2");
                while (TS_State.touchDetected == 0 && hometouched == false) {
                    lcd.Clear(LCD_COLOR_WHITE);
                    enteredsettings = false;
                    hometouched = true;
                    printf("3");
                }
            }
        }
    }
    drawStartScreen();
}
//Draw Keypad
void drawKeypad() {
    
    // Creating grid
    lcd.DrawHLine(0,270,480);
    lcd.DrawHLine(0,271,480);
    lcd.DrawHLine(0,272,480);
    lcd.DrawHLine(0,192,480);
    lcd.DrawHLine(0,193,480);
    lcd.DrawHLine(0,112,480);
    lcd.DrawHLine(0,113,480);
    lcd.DrawVLine(80,112,160);
    lcd.DrawVLine(160,112,160);
    lcd.DrawVLine(240,112,160);
    lcd.DrawVLine(320,112,160);
    lcd.DrawVLine(400,112,160);
    
    // Inserting numbers and icons into the grid
    lcd.SetTextColor(LCD_COLOR_BLACK);
    lcd.DisplayStringAt(34, 146, (uint8_t *)"0", LEFT_MODE);
    lcd.DisplayStringAt(114, 146, (uint8_t *)"1", LEFT_MODE);
    lcd.DisplayStringAt(194, 146, (uint8_t *)"2", LEFT_MODE);
    lcd.DisplayStringAt(274, 146, (uint8_t *)"3", LEFT_MODE);
    lcd.DisplayStringAt(354, 146, (uint8_t *)"4", LEFT_MODE);
    lcd.DrawBitmap(408, 120, (uint8_t *)Delete);
    lcd.DisplayStringAt(34, 226,(uint8_t *)"5", LEFT_MODE);
    lcd.DisplayStringAt(114, 226, (uint8_t *)"6", LEFT_MODE);
    lcd.DisplayStringAt(194, 226, (uint8_t *)"7", LEFT_MODE);
    lcd.DisplayStringAt(274, 226, (uint8_t *)"8", LEFT_MODE);
    lcd.DisplayStringAt(354, 226, (uint8_t *)"9", LEFT_MODE);
    lcd.DrawBitmap(408, 200, (uint8_t *)Check);
    lcd.SetTextColor(LCD_COLOR_BLUE);
    
}


//Draw Security screen
void drawSecurity() {
    
    enteredsecurity = true;
    lcd.Clear(LCD_COLOR_WHITE);
    lcd.DrawBitmap(416, 0, (uint8_t *)Cancel);
    drawKeypad();
    
    // Variables used to write and check if pin is correct
    bool touched2;
    bool button0 = false;
    bool button1 = false;
    bool button2 = false;
    bool button3 = false;
    bool button4 = false;
    bool button5 = false;
    bool button6 = false;
    bool button7 = false;
    bool button8 = false;
    bool button9 = false;
    bool button10 = false;
    bool button11 = false;
    bool button12= false;
    string pin = "";
    
    while(enteredsecurity == true) {
        ts.GetState(&TS_State);
        
        lcd.DisplayStringAt(0, LINE(1), (uint8_t *)"Enter PIN:", CENTER_MODE);
        // Displaying entered PIN
        lcd.DisplayStringAt(0, LINE(2), (uint8_t *)pin.c_str(), CENTER_MODE);
    
        //Key states to check if a certain key has been pressed and then resetting it
        
        if ((TS_State.touchDetected == 0) && (touched2 == true)){
            touched2 = false;
            button0 = false;
            button1 = false;
            button2 = false;
            button3 = false;
            button4 = false;
            button5 = false;
            button6 = false;
            button7 = false;
            button8 = false;
            button9 = false;
            button10 = false;
            button11 = false;
            button12 = false;
        }
        if (TS_State.touchDetected == 1){
            touched2 = true;
        }
        // Button 0 - 0
        // Defining touch area for this button:
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 0) && (TS_State.touchX[0] < 80) && (TS_State.touchY[0] > 112) && (TS_State.touchY[0] < 192)) {
            while (button0 == false){
                pin += "0";
                printf("%s \r\n", pin.c_str());
                button0 = true;
            }
        }
        // Button 1 - 1
        // Defining touch area for this button:
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 80) && (TS_State.touchX[0] < 160) && (TS_State.touchY[0] > 112) && (TS_State.touchY[0] < 192 )) {
            while (button1 == false){
                pin += "1";
                printf("%s \r\n", pin.c_str());
                button1 = true;
            }
        }
        // Button 2 - 2
        // Defining touch area for this button:
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 160) && (TS_State.touchX[0] < 240) && (TS_State.touchY[0] > 112) && (TS_State.touchY[0] < 192 )) {
            while (button2 == false){
                pin += "2";
                printf("%s \r\n", pin.c_str());
                button2 = true;
            }
        }
        // Button 3 - 3
        // Defining touch area for this button:
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 240) && (TS_State.touchX[0] < 320) && (TS_State.touchY[0] > 112) && (TS_State.touchY[0] < 192 )) {
            while (button3 == false){
                pin += "3";
                printf("%s \r\n", pin.c_str());
                button3 = true;
            }
        }
        // Button 4 - 4
        // Defining touch area for this button:
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 320) && (TS_State.touchX[0] < 400) && (TS_State.touchY[0] > 112) && (TS_State.touchY[0] < 192 )) {
            while (button4 == false){
                pin += "4";
                printf("%s \r\n", pin.c_str());
                button4 = true;
            }
        }
        // Button 5 - 5
        // Defining touch area for this button:
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 0) && (TS_State.touchX[0] < 80) && (TS_State.touchY[0] > 192) && (TS_State.touchY[0] < 272 )) {
            while (button5 == false){
                pin += "5";
                printf("%s \r\n", pin.c_str());
                button5 = true;
            }
        }
        // Button 6 - 6
        // Defining touch area for this button:
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 80) && (TS_State.touchX[0] < 160) && (TS_State.touchY[0] > 192) && (TS_State.touchY[0] < 272 )) {
            while (button6 == false){
                pin += "6";
                printf("%s \r\n", pin.c_str());
                button6 = true;
            }
        }
        // Button 7 - 7
        // Defining touch area for this button:
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 160) && (TS_State.touchX[0] < 240) && (TS_State.touchY[0] > 192) && (TS_State.touchY[0] < 272 )) {
            while (button7 == false){
                pin += "7";
                printf("%s \r\n", pin.c_str());
                button7 = true;
            }
        }
        // Button 8 - 8
        // Defining touch area for this button:
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 240) && (TS_State.touchX[0] < 320) && (TS_State.touchY[0] > 192) && (TS_State.touchY[0] < 272 )) {
            while (button8 == false){
                pin += "8";
                printf("%s \r\n", pin.c_str());
                button8 = true;
            }
        }
        // Button 9 - 9
        // Defining touch area for this button:
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 400) && (TS_State.touchX[0] < 400) && (TS_State.touchY[0] > 192) && (TS_State.touchY[0] < 272 )) {
            while (button9 == false){
                pin += "9";
                printf("%s \r\n", pin.c_str());
                button9 = true;
            }
        }
        // Button 10 - Delete
        // Defining touch area for this button:
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 400) && (TS_State.touchX[0] < 480) && (TS_State.touchY[0] > 112) && (TS_State.touchY[0] < 192 )) {
            while (button10 == false){
                pin = "";
                lcd.ClearStringLine(2);
                lcd.DrawBitmap(416, 0, (uint8_t *)Cancel);
                button10 = true;
            }
        }
        // Button 11 - Check
        // Defining touch area for this button:
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 400) && (TS_State.touchX[0] < 480) && (TS_State.touchY[0] > 192) && (TS_State.touchY[0] < 272 )) {
            while (button11 == false){
                if (pin == "1234") {
                    lcd.SetTextColor(LCD_COLOR_GREEN);
                    lcd.ClearStringLine(1);
                    lcd.ClearStringLine(2);
                    lcd.DisplayStringAt(0, LINE(1), (uint8_t *)"Success!", CENTER_MODE);
                    lcd.DisplayStringAt(0, LINE(2), (uint8_t *)"Security activated", CENTER_MODE);
                    lcd.DrawBitmap(416, 0, (uint8_t *)Cancel);
                    wait(3);
                    enteredsecurity = false;
                }
                else {
                    lcd.SetTextColor(LCD_COLOR_RED);
                    lcd.ClearStringLine(1);
                    lcd.ClearStringLine(2);
                    lcd.DisplayStringAt(0, LINE(1), (uint8_t *)"Wrong PIN!", CENTER_MODE);
                    lcd.DrawBitmap(416, 0, (uint8_t *)Cancel);
                    pin = "";
                    wait(3);
                    lcd.SetTextColor(LCD_COLOR_BLUE);    
                }
                button11 = true;
            }
        }
        // Button 12 - Cancel
        // Defining touch area for this button:
        if ((TS_State.touchDetected) && (TS_State.touchX[0] > 400) && (TS_State.touchY[0] < 479) && (TS_State.touchY[0] < 70 )) {
            while (button12 == false){
                ts.GetState(&TS_State);
                while (TS_State.touchDetected == 0 && button12 == false) {
                    lcd.Clear(LCD_COLOR_WHITE);
                    enteredsecurity = false;
                    button12 = true;
                }
            }
        }
    }
}

#endif