	/*
 * revolve_can_definitions.h
 *
 * Created: 20.01.2013 18:47:51
 *  Author: Bruker
 */ 


#ifndef REVOLVE_CAN_DEFINITIONS_H_
#define REVOLVE_CAN_DEFINITIONS_H_

//ID
//Module ID
//Bytemapping

//------------------------------------------------------------------------------
// EXAMPLE: function = command, group = dash, module ID = 0
/* .id = CANR_FCN_CMD_ID | CANR_GRP_DASH_ID | CANR_MODULE_ID0 */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/*	-------	ARBITRATION ID DEFINITIONS ---------------------------------------*/
//------------------------------------------------------------------------------

//- ID[10..8]
#define CANR_FCN_PRI_ID				0x000		// Most significant
#define CANR_FCN_BOOT_ID			0x200		// Priority data
#define CANR_FCN_CMD_ID				0x400		// Module_id control
#define CANR_FCN_DATA_ID			0x600		// Sensor data

//- ID[7..3]
#define CANR_GRP_SENS_ROTARY_ID		0x10		// Torque and steering encoder
#define CANR_GRP_SENS_BRK_ID		0x18		// Brake encoder
#define CANR_GRP_SENS_SPEED_ID		0x20		// Wheel speed
#define CANR_GRP_BMS_ID				0x28		// BMS-data
#define CANR_GRP_ECU_ID				0x30		// ECU
#define CANR_GRP_INVERTER_ID		0x38		// Inverter data
#define CANR_GRP_SUSP_ID			0x40		// Suspension
#define CANR_GRP_SENS_IMU_ID		0x48		// IMU master
#define CANR_GRP_SENS_DAMPER_ID		0x50		// Damper position
#define CANR_GRP_SENS_TEMP_ID		0x56		// Gearbox and water temp
#define CANR_GRP_SENS_GLVBMS_ID		0x58		// GLV BMS
#define CANR_GRP_DASH_ID			0x60		// Dashboard
#define CANR_GRP_SENS_BSPD_ID	 	0x68		// BSPD
#define CANR_GRP_SENS_IMD_ID		0x70		// Laptimer
#define CANR_GRP_TELEMETRY_ID		0x78		// Telemetry
#define CANR_GRP_FAN_CTRL_ID		0x80		// Fan control
//#define CANR_GRP_					0x88		// 
//#define CANR_GRP_					0x90		// 

//- ID[2..0]
#define CANR_MODULE_ID0_ID			0x0
#define CANR_MODULE_ID1_ID			0x1
#define CANR_MODULE_ID2_ID			0x2
#define CANR_MODULE_ID3_ID			0x3
#define CANR_MODULE_ID4_ID			0x4
#define CANR_MODULE_ID5_ID			0x5
#define CANR_MODULE_ID6_ID			0x6
#define CANR_MODULE_ID7_ID			0x7

//------------------------------------------------------------------------------
/*	-------	ALIVE	 ---------------------------------------------------------*/
//------------------------------------------------------------------------------

// ---------------------------------------------------------------------//
// Functionality description:											//
// Each module sends out a message with the following properties:		//
// ID = CANR_FCN_DATA_ID | CANR_GRP_DASH_ID	| CANR_MODULE_ID7_ID		//
// DATA[0] = MODULE ID													//
// Frequency = 1 Hz														//
// ---------------------------------------------------------------------//

//- ALIVE BYTES
#define CANR_ALIVE_MSG_DLC			1
#define CANR_ALIVE_MODULE_B			0

//Module Alive IDs
#define ALIVE_ECU					0x00
#define ALIVE_TRQ					0x01
#define ALIVE_BSPD					0x02
#define ALIVE_TELEMETRY				0x03
#define ALIVE_DASH					0x04
#define ALIVE_ADC_FR				0x05
#define ALIVE_ADC_FL				0x06
#define ALIVE_ADC_RR				0x07
#define ALIVE_ADC_RL				0x08
#define ALIVE_INVERTER				0x09
#define ALIVE_FAN					0x0A
#define ALIVE_BMS					0x0B
#define ALIVE_GLVBMS				0x0C
#define ALIVE_IMU					0x0D
#define ALIVE_STEER_POS				0x0E
#define ALIVE_IMD					0x0F


//-------------------------------------------------------------------------------
/*	------- Module ID overrides	 ----------------------------------------------*/
/*   If you want to make your own macro to replace module_id_x, make it here   */
//-------------------------------------------------------------------------------




//-------------------------------------------------------------------------------
/*	------- Byte mapping 					   --------------------------------*/
/* If you want to describe the mapping of your can bus data, make macros here  */
//-------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------




#endif /* REVOLVE_CAN_DEFINITIONS_H_ */