/*
 * LED.c
 *
 * Created: 19.01.2015 21:05:17
 *  Author: Mikael
 */ 
#include "LED.h"

void LEDs_init() {
	LED_1_init();
	LED_2_init();
}

void LED_1_init() {
	DDRD |= ( 1 << PORTD7 );
}
void LED_2_init() {
	DDRD |= ( 1 << PORTD6 );
}
void LED_2_off() {
	PORTD &= ~(1 << PORTD6);
}
void LED_2_on() {
	PORTD |= (1 << PORTD6);
}
void LED_1_off() {
	PORTD &= ~(1 << PORTD7);
}
void LED_1_on() {
	PORTD |= (1 << PORTD7);
}
void LED_1_toggle() {
	PORTD ^= (1 << PORTD7);
}
void LED_2_toggle() {
	PORTD ^= (1 << PORTD6);
}

