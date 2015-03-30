/*
 * ADC_kort.c
 *
 * Created: 02.03.2015 17:43:32
 *  Author: Mikael
 */ 
#include <util/delay.h>
#include <avr/interrupt.h>

#include "SPI/SPI.h"
#include "CAN/can_drv.h"
#include "ADS1118/ADS1118.h"
#include "Atmega64M1/atmega_setups.h"
#include "sensor_transmit.h"
#include "ADC_module_compile.h"

volatile uint16_t interrupt_time_counter = 0;

int main() {
	spi_init ( spi_mode_0, spi_prescaler_64 );
	can_init ( clkph_16MHZ, CAN_BPS_100K );
	can_messages_init ();
	atmega_init ();
  	adc_init ();
	
	#ifdef ADC_MODULE_COMPILE_FRONT_LEFT
	while ( true ) {
		transmit_damper_position_sensor_value ( ADC_DAMPER_POSITION_SENSOR_FL );
		_delay_ms(100);
		transmit_temperature_sensor_value ( ADC_TEMPERATURE_SENSOR_COOLING_SYSTEM );
		_delay_ms(100);
		LED_1_toggle();
	}
	
	#endif /* ADC_MODULE_COMPILE_FRONT_LEFT */
	
	#ifdef ADC_MODULE_COMPILE_FRONT_RIGHT
	transmit_damper_position_sensor_value ( ADC_DAMPER_POSITION_SENSOR_FR );
	transmit_wheel_speed_sensor_value ( ADC_WHEEL_SPEED_SENSOR_FR );
	transmit_i_am_alive_message ( ALIVE_ADC_FR );
	#endif /* ADC_MODULE_COMPILE_FRONT_RIGHT */
	
	#ifdef ADC_MODULE_COMPILE_REAR_LEFT
	transmit_i_am_alive_message ( ALIVE_ADC_RL );
	transmit_wheel_speed_sensor_value ( ADC_WHEEL_SPEED_SENSOR_FL );
	#endif /* ADC_MODULE_COMPILE_REAR_LEFT */
	
	#ifdef ADC_MODULE_COMPILE_REAR_RIGHT
	transmit_i_am_alive_message ( ALIVE_ADC_RR );
	transmit_wheel_speed_sensor_value ( ADC_WHEEL_SPEED_SENSOR_RR );
	#endif /* ADC_MODULE_COMPILE_REAR_RIGHT */
}

ISR( TIMER1_COMPA_vect ) {
	LED_2_toggle();
	interrupt_time_counter += 1;
}
ISR ( INT0_vect ) {
	LED_1_toggle();
}