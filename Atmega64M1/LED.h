/*
 * LED.h
 *
 * Created: 19.01.2015 21:05:40
 *  Author: Mikael
 */ 
#include <avr/io.h>

#ifndef LED_H_
#define LED_H_

extern void LEDs_init();
extern void LED_2_init();
extern void LED_1_init();
extern void LED_1_on();
extern void LED_1_off();
extern void LED_2_on();
extern void LED_2_off();
extern void LED_1_toggle();
extern void LED_2_toggle();

#endif /* LED_H_ */