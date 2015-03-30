/*
 * atmega_setups.h
 *
 * Created: 02.03.2015 18:38:30
 *  Author: Mikael-pc
 */ 


#ifndef ATMEGA_SETUPS_H_
#define ATMEGA_SETUPS_H_

#define TIMER_PRESCALER_BIT							0
#define TIMER_PRESCALER_1							1
#define TIMER_PRESCALER_8							2
#define TIMER_PRESCALER_64							3
#define TIMER_PRESCALER_256							4
#define TIMER_PRESCALER_1024						5

#define TIMER_MODE_BIT								8
#define TIMER_MODE_NORMAL							0
#define TIMER_MODE_PWM_8_BIT						1
#define TIMER_MODE_CTC								4
#define TIMER_MODE_FAST_PWM_8_BIT					5

#define INTERRUPT_EXT0								0
#define INTERRUPT_EXT1								1
#define INTERRUPT_EXT2								2
#define INTERRUPT_EXT3								3

#define INTERRUPT_TRIGGER_LOW						0
#define INTERRUPT_TRIGGER_CHANGE					1
#define INTERRUPT_TRIGGER_FALLING_EDGE				2
#define INTERRUPT_TRIGGER_RISING_EDGE				3

#define WATCHDOG_RESET_BIT							3
#define WATCHDOG_INTERRUPT_BIT						6
#define WATCHDOG_TIMER_MODE_RESET					1
#define WATCHDOG_TIMER_MODE_INTERRUPT				2
#define WATCHDOG_TIMER_MODE_RESET_AND_INTERRUPT		3

void atmega_init ();
void atmega_set_prescaler ( uint8_t prescaler );
void atmega_set_timer_mode ( uint8_t mode );
void atmega_setup_timer ( uint8_t timer_mode, uint8_t prescaler );
void atmega_setup_external_interrupt ( uint8_t ext_interrupt, uint8_t interrupt_trigger );
void atmega_setup_digital_pin ();
void atmega_disable_watchdog_timer ();
void atmega_enable_watchdog_timer ( uint8_t mode );

#endif /* ATMEGA_SETUPS_H_ */