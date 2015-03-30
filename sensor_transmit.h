/*
 * sensor_transmit.h
 *
 * Created: 29.03.2015 17:03:10
 *  Author: Mikael-pc
 */ 
#ifndef SENSOR_TRANSMIT_H_
#define SENSOR_TRANSMIT_H_

#include "revolve_can_definitions.h"
#include "ADS1118/ADS1118.h"

#define ADC_CHANNEL_DAMPER_POSITION				ADC_ANALOG_IN_0
#define ADC_CHANNEL_TEMPERATURE					ADC_ANALOG_IN_1
#define ADC_CHANNEL_BRAKE_PRESSURE				ADC_ANALOG_IN_2
#define DIGITAL_CHANNEL_WHEEL_SPEED				0

#define ADC_TEMPERATURE_SENSOR_COOLING_SYSTEM	CANR_MODULE_ID0_ID
#define ADC_TEMPERATURE_SENSOR_GEARBOX			CANR_MODULE_ID1_ID

#define ADC_WHEEL_SPEED_SENSOR_FR				CANR_MODULE_ID0_ID
#define ADC_WHEEL_SPEED_SENSOR_FL				CANR_MODULE_ID1_ID
#define ADC_WHEEL_SPEED_SENSOR_RR				CANR_MODULE_ID2_ID
#define ADC_WHEEL_SPEED_SENSOR_RL				CANR_MODULE_ID3_ID

#define ADC_BRAKE_PRESSURE_SENSOR_FR			CANR_MODULE_ID0_ID
#define ADC_BRAKE_PRESSURE_SENSOR_FL			CANR_MODULE_ID1_ID

#define ADC_DAMPER_POSITION_SENSOR_FR			CANR_MODULE_ID0_ID
#define ADC_DAMPER_POSITION_SENSOR_FL			CANR_MODULE_ID1_ID
#define ADC_DAMPER_POSITION_SENSOR_RR			CANR_MODULE_ID2_ID
#define ADC_DAMPER_POSITION_SENSOR_RL			CANR_MODULE_ID3_ID

#define TIME_PERIOD(T)							T
#define TIMEOUT									25

void transmit_temperature_sensor_value ( uint8_t sensor );
void transmit_wheel_speed_sensor_value ( uint8_t sensor );
void transmit_brake_pressure_sensor_value ( uint8_t sensor );
void transmit_damper_position_sensor_value ( uint8_t sensor);
void transmit_i_am_alive_message ( uint8_t alive_adc_dataID );

uint16_t calculate_wheel_speed (uint16_t period_T_milliseconds);
void can_messages_init();

#endif /* SENSOR_TRANSMIT_H_ */