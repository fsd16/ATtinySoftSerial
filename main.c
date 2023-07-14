/*
 * main.c - example for using TinySoftSerial for ATtiny
 *
 * Created: 14/07/2023
 * Author : Finn Drabsch
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "SoftwareSerial.h"
#include "pins.h"
#include "attiny88.h"

// incoming buffer
volatile char *inbuf[32];
// outgoing buffer
volatile char *outbuf[32];

int main()
{
	// Set built-in LED pin as output
    pin_config(LED, OUTPUT);

	softSerialBegin(9600);
	
	while (1) {


		if (softSerialAvailable()) {
			pin_set(LED, HIGH);
			softSerialWrite( softSerialRead() );
			_delay_ms(10);
		}
	}
}


