/**
* @file play_buzzer.cpp
* @brief this cpp file is where all the logic is handled.
*
* @author Nikolaj M. & Mathias R.
*
* @date 10/1/2019
*/
//PROGRAM: play_buzzer

///INCLUDING HEADER FILE SO ALL FUNCTIONS AND VARIABLES 
#include "play_buzzer.h"

///DEFINING ALL NOTES USED IN SONGS
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988
#define NOTE_0     1
#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880

///NOTES IN SONG
int pirates[] = { 
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_0,
   NOTE_A4, NOTE_G4, NOTE_A4, NOTE_0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_0,
   NOTE_A4, NOTE_G4, NOTE_A4, NOTE_0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_0, 
   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, NOTE_0, 
   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, NOTE_0,
   NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, NOTE_0,
   
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_0, 
   NOTE_D5, NOTE_E5, NOTE_A4, NOTE_0, 
   NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, NOTE_0,
   NOTE_C5, NOTE_A4, NOTE_B4, NOTE_0,

   NOTE_A4, NOTE_A4, 

   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_0,
   NOTE_A4, NOTE_G4, NOTE_A4, NOTE_0,

   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_0, 
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_0, 
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_0,
   NOTE_A4, NOTE_G4, NOTE_A4, NOTE_0,
   
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_0, 
   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, NOTE_0, 
   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, NOTE_0,
   NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, NOTE_0,
   
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_0, 
   NOTE_D5, NOTE_E5, NOTE_A4, NOTE_0, 
   NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, NOTE_0,
   NOTE_C5, NOTE_A4, NOTE_B4, NOTE_0,

   NOTE_E5, NOTE_0, NOTE_0, NOTE_F5, NOTE_0, NOTE_0,
   NOTE_E5, NOTE_E5, NOTE_0, NOTE_G5, NOTE_0, NOTE_E5, NOTE_D5, NOTE_0, NOTE_0,
   NOTE_D5, NOTE_0, NOTE_0, NOTE_C5, NOTE_0, NOTE_0,
   NOTE_B4, NOTE_C5, NOTE_0, NOTE_B4, NOTE_0, NOTE_A4,

   NOTE_E5, NOTE_0, NOTE_0, NOTE_F5, NOTE_0, NOTE_0,
   NOTE_E5, NOTE_E5, NOTE_0, NOTE_G5, NOTE_0, NOTE_E5, NOTE_D5, NOTE_0, NOTE_0,
   NOTE_D5, NOTE_0, NOTE_0, NOTE_C5, NOTE_0, NOTE_0,
   NOTE_B4, NOTE_C5, NOTE_0, NOTE_B4, NOTE_0, NOTE_A4};

///LENGTH OF NOTES IN PIRATES SONG
int piratestones[] = { 
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 125, 250, 125,

  125, 125, 250, 125, 125, 
  250, 125, 250, 125, 
  125, 125, 250, 125, 125,
  125, 125, 375, 375,

  250, 125,

  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125, 
  
  125, 125, 250, 125, 125, 
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 125, 250, 125,

  125, 125, 250, 125, 125, 
  250, 125, 250, 125, 
  125, 125, 250, 125, 125,
  125, 125, 375, 375,
  
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 125, 125, 125, 375,
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 500,

  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 125, 125, 125, 375,
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 500};
 
///NOTES IN STARWARS SONG 
int starwars[] = {
    a, a, a, f, cH,
    a, f, cH, a,
    eH, eH, eH, fH, cH,
    gS, f, cH, a,
    aH, a, a, aH, gSH, gH,
    fSH, fH, fSH,

    aS, dSH, dH, cSH,
    cH, b, cH,

    f, gS, f, a,
    cH, a, cH, eH,
    aH, a, a, aH, gSH, gH,
    fSH, fH, fSH,

    aS, dSH, dH, cSH,
    cH, b, cH,

    f, gS, f, cH,
    a, f, c, a};

///LENGTH OF NOTES IN STARWARS SONG
int starwarstones[] = { 
    500, 500, 500, 350, 150,
    500, 350, 150, 1000,
    500, 500, 500, 350, 150,
    500, 350, 150, 1000,
    500, 350, 150, 500, 250, 250,
    125, 125, 250,

    250, 500, 250, 250,
    125, 125, 250,

    125, 500, 375, 125,
    500, 375, 125, 1000,
    500, 350, 150, 500, 250, 250,
    125, 125, 250,

    250, 500, 250, 250,
    125, 125, 250,

    250, 500, 375, 125,
    500, 375, 125, 1000};

/**
* This method will be used to set the output pin for the buzzer.
* @author Nikolaj M. & Mathias R.
* @param pin The pin that the buzzer is placed
* @date 10/1/2019
*/  
void play_buzzer::setPin(PinName pin){
    this->_pin=pin;
}

/**
* This method will be used to return the output pin for the buzzer.
* @author Nikolaj M. & Mathias R.
* @return PinName The pin that the buzzer is placed
* @date 10/1/2019
*/
PinName play_buzzer::getPin(){
    return this->_pin;
}

/**
* This is the constructor which sets the pin for the buzzer to play, and make the buzzer quiet.
* @author Nikolaj M. & Mathias R.
* @param pin The pin that the buzzer is placed
* @date 10/1/2019
*/
play_buzzer::play_buzzer(PinName pin) : _pwm(pin){
    play_buzzer::setPin(pin);
    _pwm.write(0.0);     // after creating it have to be off
}


/**
* This method will stop buzzer from beeping.
* @author Nikolaj M. & Mathias R.
* @date 10/1/2019
*/
void play_buzzer::nobeep() {
    _pwm.write(0.0);
}

/**
* This method will make the buzzer beep, using notes as freq and tones as play length.
* @author Nikolaj M. & Mathias R.
* @param notes, tones Two arrays with frequency and play length consists of defined ints and ints
* @date 10/1/2019
*/
void play_buzzer::beep(int notes, int tones) { 
    _pwm.period(1.0/notes);
    _pwm.write(0.2);
    wait_ms(tones);
}


/**
* This method will make the buzzer play the song, using a switch to determine which song to play with int.
* @author Nikolaj M. & Mathias R.
* @param song An int that choose song in the switch
* @date 10/1/2019
*/
int play_buzzer::play(int song)
{
    int tones_num;
    int i;
    switch(song){
        case 1:
            tones_num = 66;
            for(i=0; i<tones_num; i++)
            {
                beep(starwars[i], starwarstones[i]);
                if( i == 27 || i == 34 || i == 51 || i == 58 )
                {
                    wait_ms(250);
                }
            }
            break;
        case 2:
            tones_num = 203;
            for(i=0; i<tones_num; i++)
            {
                int noteDuration = piratestones[i];
                if(piratestones[i] != NOTE_0){
                    beep(pirates[i], piratestones[i]); 
                }
                    int pauseBetweenNotes = noteDuration * 0.5;
                    wait_ms(pauseBetweenNotes);
            }
            break;
    }
    return 1;
}