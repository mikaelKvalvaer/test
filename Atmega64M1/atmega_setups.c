#include <avr/interrupt.h>
#include <avr/io.h>

#include "atmega_setups.h"
#include "LED.h"

void atmega_init () {
	atmega_setup_timer ( TIMER_MODE_CTC, TIMER_PRESCALER_64 );
	atmega_setup_external_interrupt ( INTERRUPT_EXT0, INTERRUPT_TRIGGER_RISING_EDGE );
	atmega_setup_digital_pin ();
	atmega_disable_watchdog_timer();
	LEDs_init ();
}
void atmega_setup_external_interrupt ( uint8_t ext_interrupt, uint8_t interrupt_trigger )
{
	cli();
	EIMSK |= ( 1 << ext_interrupt );
	EICRA |= ( interrupt_trigger << 2*ext_interrupt );
	sei();
}
void atmega_setup_timer( uint8_t timer_mode, uint8_t prescaler )
{
	atmega_set_timer_mode ( timer_mode );
	atmega_set_prescaler ( prescaler );
	
	switch ( timer_mode ) {
		case TIMER_MODE_CTC:
			TIMSK1 |= ( 1 << OCIE1A ); /* enable output compare to value in OCR1A register.*/
			OCR1A = 15625;
			break;
		
		default:
			break;
	}
}
void atmega_set_prescaler ( uint8_t prescaler ) {
	TCCR1B |= ( prescaler << TIMER_PRESCALER_BIT );
}
void atmega_set_timer_mode ( uint8_t mode ) {
	TCCR1B |= ( mode << TIMER_MODE_BIT );
}
void atmega_setup_digital_pin () {
	DDRB &= ~(1 << PORTB3); /* sets digital0 as input. Specific for this ADC module. */
	PORTB |= (1 << PORTB3);
}
void atmega_disable_watchdog_timer () {
	cli ();
	WDTCSR &= ~( 1 << WDIE );
}
void atmega_enable_watchdog_timer ( uint8_t mode ) {
	
	switch ( mode ) {
		case WATCHDOG_TIMER_MODE_RESET:
			WDTCSR |= ( 1 << WATCHDOG_RESET_BIT);
			break;
		case WATCHDOG_TIMER_MODE_INTERRUPT:
			WDTCSR |= ( 1 << WATCHDOG_INTERRUPT_BIT );
			break;
		case WATCHDOG_TIMER_MODE_RESET_AND_INTERRUPT:
			WDTCSR |= ( 1 << WATCHDOG_INTERRUPT_BIT );
			WDTCSR |= ( 1 << WATCHDOG_RESET_BIT );
			break;
	}
	//MCUSR |= ( 1 << )
	WDTCSR |= ( 1 << WDIE );
}