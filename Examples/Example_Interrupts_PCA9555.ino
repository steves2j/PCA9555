/*
 * Example_Interrupts_PCA95555.ino
 *
 *  Created on: 14 Dec. 2018
 *      Author: s2j.io
 * Interrupt functionality added by s2j.io (2018-12-13)
 */

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "clsPCA9555.h"
#include "Wire.h"

PCA9555 ioport(0x20);

volatile uint16_t pinchanges=0; //Local access store of what pin changed

#define IRQPIN 1 //Pin the PCA9555 int pin is connected to on host

/**
 * @name doInt()
 * interrupt routine the PCA9555 should call if a pin matches the mask
 */
void doInt() {
    pinchanges=ioport.whatPinsInterrupted();
}

/**
 * @name doCallback() {
 * interrupt route to attach to. Put your extra logic in here.
 */
void doCallback() {
    ioport.interruptCallback();
}

/**
 * @name setup()
 * initialize the program
 */
void setup()
{
	//
	// set first 16 pins to inputs
	//
	for (uint8_t i = 0; i < 16; i++){
		ioport.pinMode(i, INPUTS);
	}
    
    ioport.enableInterruptOnPin(ED1); //Enable interrupt on ED1
    ioport.enableInterruptOnPin(ED3); //Enable interrupt on ED3
    ioport.enableInterruptOnPin(ED11);//Enable interrupt on ED11 
    ioport.setInterruptCallback(doInt);//Set what to call if a pin matches the mask.
    
    attachInterrupt(IRQPIN,doCallback,CHANGE);//Attach the host interrupt capture pin to the PCA9555 class

}

/**
 * @name loop()
 * main loop of program and runs endlessly
 */
void loop()
{
	if (pinchanges) {
        if (pinchanges & 0b0000000000000001) Serial.println( "ED0 pin changed.");
        if (pinchanges & 0b0000000000000010) Serial.println( "ED1 pin changed.");
        if (pinchanges & 0b0000000000000100) Serial.println( "ED2 pin changed.");
        if (pinchanges & 0b0000000000001000) Serial.println( "ED3 pin changed.");
        if (pinchanges & 0b0000000000010000) Serial.println( "ED4 pin changed.");
        if (pinchanges & 0b0000000000100000) Serial.println( "ED5 pin changed.");
        if (pinchanges & 0b0000000001000000) Serial.println( "ED6 pin changed.");
        if (pinchanges & 0b0000000010000000) Serial.println( "ED7 pin changed.");
        if (pinchanges & 0b0000000100000000) Serial.println( "ED8 pin changed.");
        if (pinchanges & 0b0000001000000000) Serial.println( "ED9 pin changed.");
        if (pinchanges & 0b0000010000000000) Serial.println("ED10 pin changed.");
        if (pinchanges & 0b0000100000000000) Serial.println("ED11 pin changed.");
        if (pinchanges & 0b0001000000000000) Serial.println("ED12 pin changed.");
        if (pinchanges & 0b0010000000000000) Serial.println("ED13 pin changed.");
        if (pinchanges & 0b0100000000000000) Serial.println("ED14 pin changed.");
        if (pinchanges & 0b1000000000000000) Serial.println("ED15 pin changed.");
    }
}
