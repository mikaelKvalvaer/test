/*
 * sensor_transmit.c
 *
 * Created: 29.03.2015 17:03:19
 *  Author: Mikael-pc
 */ 

#include <avr/io.h>
#include <math.h>

#include "sensor_transmit.h"
#include "CAN/can_drv.h"
#include "CAN/can_lib.h"
#include "ADS1118/ADS1118.h"
#include "revolve_can_definitions.h"

st_cmd_t i_am_alive; /* setup struct for CAN transmission */
st_cmd_t sensor_message;
can_data_t sensor_message_data; /* setup data for CAN transmission */
can_data_t i_am_alive_data;

volatile uint16_t tag_count = 0; /*wheel speed debug. erase soon */
uint16_t timeout_counter = 0;

void transmit_temperature_sensor_value ( uint8_t sensor ) {
	sensor_message.id.std = CANR_FCN_DATA_ID | CANR_GRP_SENS_TEMP_ID | sensor; 
	sensor_message_data.u16[0] = adc_read_chan( ADC_CHANNEL_TEMPERATURE );
	can_free_single_mob( sensor_message.handle );
	can_cmd( &sensor_message );
	while ( can_get_status( &sensor_message ) != CAN_STATUS_COMPLETED ) {
		timeout_counter += 1;
		if ( timeout_counter >= 25 ) {
			timeout_counter = 0;
			break;
		}
	}
}
void transmit_wheel_speed_sensor_value ( uint8_t sensor ) {
	sensor_message.id.std =  CANR_FCN_DATA_ID | CANR_GRP_SENS_SPEED_ID | sensor;
	sensor_message_data.u16[0] = calculate_wheel_speed ( TIME_PERIOD(2 /*ms*/) );
	can_free_single_mob( sensor_message.handle );
	can_cmd( &sensor_message );
	while ( can_get_status( &sensor_message ) != CAN_STATUS_COMPLETED ) {
		timeout_counter += 1;
		if ( timeout_counter >= 25 ) {
			timeout_counter = 0;
			break;
		}
	}
}
void transmit_brake_pressure_sensor_value ( uint8_t sensor ) {
	sensor_message.id.std = CANR_FCN_DATA_ID | CANR_GRP_SENS_BRK_ID | sensor;
	sensor_message_data.u16[0] = adc_read_chan( ADC_CHANNEL_BRAKE_PRESSURE );
	can_free_single_mob( sensor_message.handle );
	can_cmd( &sensor_message );
	while ( can_get_status( &sensor_message ) != CAN_STATUS_COMPLETED ) {
		timeout_counter += 1;
		if ( timeout_counter >= TIMEOUT ) { break; LED_1_toggle(); }
	}
}
void transmit_damper_position_sensor_value ( uint8_t sensor ) {
	sensor_message.id.std = CANR_FCN_DATA_ID | CANR_GRP_SENS_DAMPER_ID | sensor;
	sensor_message_data.u16[0] = adc_read_chan( ADC_CHANNEL_DAMPER_POSITION );
	can_free_single_mob( sensor_message.handle );
	can_cmd( &sensor_message );
	while ( can_get_status( &sensor_message ) != CAN_STATUS_COMPLETED ) {
		timeout_counter += 1;
		if ( timeout_counter >= TIMEOUT ) { break; }
	}
}
void transmit_i_am_alive_message ( uint8_t alive_adc_dataID ) {
	sensor_message_data.u8[0] = alive_adc_dataID;
	can_free_single_mob( sensor_message.handle );
	can_cmd( &sensor_message );
	while ( can_get_status( &sensor_message ) != CAN_STATUS_COMPLETED ) {
		timeout_counter += 1;
		if ( timeout_counter >= 25 ) {
			timeout_counter = 0;
			break;
		}
	}
}
uint16_t calculate_wheel_speed (uint16_t period_T_milliseconds) {
	float dt = period_T_milliseconds;
	static float d_tag = 0.0024; /* distance covered by each tag counted by sensor */
	static float millisecond_constant = 1000.0f;
	float dx = (float) tag_count * d_tag;
	
	tag_count = 0;
	
	return ( int ) floor ( dx/dt * millisecond_constant );
}
void can_messages_init() {
	i_am_alive.ctrl.ide = 0;
	i_am_alive.ctrl.rtr = 0;
	i_am_alive.dlc = 1;
	i_am_alive.cmd = CMD_TX_DATA;
	i_am_alive.pt_data = &i_am_alive_data;
	i_am_alive.id.std= CANR_FCN_DATA_ID | CANR_GRP_DASH_ID | CANR_MODULE_ID7_ID;
	
	sensor_message.dlc = 2;
	sensor_message.ctrl.ide = 0;
	sensor_message.ctrl.rtr = 0;
	sensor_message.cmd = CMD_TX_DATA;
	sensor_message.pt_data = &sensor_message_data;
}