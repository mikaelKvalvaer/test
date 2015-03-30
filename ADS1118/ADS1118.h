/*
 * ads1118.h
 *
 * Created: 20.04.2014 13:37:28
 *  Author: Simen
 */ 


#ifndef ADS1118_H_
#define ADS1118_H_

#define ADS_SS_START_bit		15
#define ADS_SS_START			(1 << ADS_SS_START_bit)

#define ADS_MUX_bit	12
#define ADS_MUX_SET(mux)		(mux << ADS_MUX_bit)
#define ADS_MUX_MASK			(0b111 << ADS_MUX_bit)

#define ADS_MUX_DIFF_0_1		0
#define ADS_MUX_DIFF_0_3		1
#define ADS_MUX_DIFF_1_3		2
#define ADS_MUX_DIFF_2_3		3

#define ADS_MUX_SINGLE_OFFSET	4

#define ADS_MUX_SINGLE_0		4
#define ADS_MUX_SINGLE_1		5
#define ADS_MUX_SINGLE_2		6
#define ADS_MUX_SINGLE_3		7

#define ADS_GAIN_bit			9
#define ADS_GAIN_SET(gain)		(gain << ADS_GAIN_bit)

#define ADS_GAIN_RANGE_6_144V	0
#define ADS_GAIN_DIV_3			ADS_GAIN_RANGE_6_144V
#define ADS_GAIN_RANGE_4_096V	1
#define ADS_GAIN_DIV_2			ADS_GAIN_RANGE_4_096V
#define ADS_GAIN_RANGE_2_048V	2
#define ADS_GAIN_MUL_1			ADS_GAIN_RANGE_2_048V
#define ADS_GAIN_RANGE_1_024V	3
#define ADS_GAIN_MUL_2			ADS_GAIN_RANGE_1_024V
#define ADS_GAIN_RANGE_0_512V	4
#define ADS_GAIN_MUL_4			ADS_GAIN_RANGE_0_512V
#define ADS_GAIN_RANGE_0_256V	5
#define ADS_GAIN_DIV_8			ADS_GAIN_RANGE_0_256V

#define ADS_MODE_bit			8
#define ADS_MODE_SET(mode)		(mode << ADS_MODE_bit)

#define ADS_MODE_CONTINUOUS		0
#define ADS_MODE_SINGLE_SHOT	1

#define ADS_RATE_bit			5
#define ADS_RATE_SET(rate)		(rate << ADS_RATE_bit)

#define ADS_RATE_8_HZ			0
#define ADS_RATE_16_HZ			1
#define ADS_RATE_32_HZ			2
#define ADS_RATE_64_HZ			3
#define ADS_RATE_128_HZ			4
#define ADS_RATE_250_HZ			5
#define ADS_RATE_475_HZ			6
#define ADS_RATE_860_HZ			7

#define ADS_TS_MODE_bit			4
#define ADS_TS_MODE_SET(enable)	(enable << ADS_TS_MODE_bit)

#define ADS_TS_MODE_TEMP_SENS	1
#define ADS_TS_MODE_ADC			0

#define ADS_PULLUP_ENABLE_bit	3
#define ADS_PULLUP_SET(enable)	(enable << ADS_PULLUP_ENABLE_bit)

#define ADS_VALIDATE_COMMAND    2

#define ADC_ANALOG_IN_0			0
#define ADC_ANALOG_IN_1			1
#define ADC_ANALOG_IN_2			2
#define ADC_ANALOG_IN_3			3

void adc_init ();
uint16_t adc_config ( uint16_t reg );
uint16_t adc_read ();
uint16_t adc_read_chan ( uint8_t chan );
void adc_set_chan ( uint8_t chan );

#endif /* ADS1118_H_ */