
#define F_CPU 1600000UL

#include <avr/io.h>
#include <avr/delay.h>
#include "../SPI/SPI.h"
#include "ads1118.h"

static uint16_t adc_conf = 0;

void adc_init(){
	adc_config(	(ADS_GAIN_SET( ADS_GAIN_RANGE_4_096V ))	|
				(ADS_MODE_SET( ADS_MODE_CONTINUOUS ))	|
				(ADS_RATE_SET( ADS_RATE_128_HZ ))		| 
				(ADS_TS_MODE_SET( ADS_TS_MODE_ADC ))	|
				(ADS_PULLUP_SET( 0 ) )
	);
}

uint16_t adc_config(uint16_t reg){
	adc_conf = reg;
	adc_conf |= ADS_VALIDATE_COMMAND;
	
	uint8_t firstByte = adc_conf >> 8 & 0xFF;
	uint8_t secondByte = adc_conf & 0xFF;
	
	spi_tranceive( firstByte, NOT_LAST_TX );
	spi_tranceive( secondByte, LAST_TX );
	
	return adc_conf;
}

uint16_t adc_read(){
	uint16_t data = 0;
	
	data |= ( spi_tranceive ( SPI_MASTER_DUMMY_BYTE, NOT_LAST_TX ) << 8);
	data |= ( spi_tranceive ( SPI_MASTER_DUMMY_BYTE, LAST_TX ) );
	
	return data;
}

uint16_t adc_read_chan ( uint8_t chan ){
	adc_set_chan( chan );
	adc_set_chan( chan );
	return adc_read();
}

void adc_set_chan( uint8_t chan ){
	uint16_t updateReg = ( adc_conf & ~ADS_MUX_MASK | 1 << 14 );
	updateReg |= ADS_MUX_SET ( ( chan ) );
	adc_config( updateReg );
}