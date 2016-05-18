
#ifndef __si70xx_h__
#define __si70xx_h__

#include "stm32f0xx_hal.h"

/* Commands */
#define SI7013_CMD_MEASURE_HUMIDITY_HOLD				0xE5
#define SI7013_CMD_MEASURE_HUMIDITY_NO_HOLD			0xF5
#define SI7013_CMD_MEASURE_TEMPERATURE_HOLD			0xE3
#define SI7013_CMD_MEASURE_TEMPERATURE_NO_HOLD 	0xF3
#define SI7013_CMD_MEASURE_THERMISTOR_HOLD			0xEE
#define SI7013_CMD_READ_PREVIOUS_TEMPERATURE		0xE0
#define SI7013_CMD_RESET												0xFE
#define SI7013_CMD_WRITE_REGISTER_1							0xE6
#define SI7013_CMD_READ_REGISTER_1							0xE7
#define SI7013_CMD_WRITE_REGISTER_2							0x50
#define SI7013_CMD_READ_REGISTER_2							0x10
#define SI7013_CMD_WRITE_REGISTER_3							0x51
#define SI7013_CMD_READ_REGISTER_3							0x11
#define SI7013_CMD_WRITE_COEFFICIENT						0xC5
#define SI7013_CMD_READ_COEFFICIENT							0x84


/** \brief  Union type for the structure of User Register1 in Si7013
 */
typedef union
{
	struct
	{
			uint8_t res0		:1;  		/*!< bit:  0 RES0 */
			uint8_t 				:1;  		/*!< bit:  1 reserved */
			uint8_t htre		:1;  		/*!< bit:  2 heater enable */
			uint8_t     		:3;  		/*!< bit:  3...5 reserved */
			uint8_t vdds		:1;  		/*!< bit:  6 VDDS */
			uint8_t res1		:1;  		/*!< bit:  7 RES1 */
	} b;
	uint8_t r;
} si7013_reg1_t;
	
/** \brief  Union type for the structure of User Register2 in Si7013
 */
typedef union
{
	struct
	{
			uint8_t vout		:1;  		/*!< bit:  0 VOUT */
			uint8_t vrefp		:1;  		/*!< bit:  1 VREFP */
			uint8_t vin_buf	:1;  		/*!< bit:  2 VIN_BUF */
			uint8_t     		:1;  		/*!< bit:  3 reserved */
			uint8_t convtime:1;  		/*!< bit:  4 CONV_TIME */
			uint8_t therm_corr:1;  	/*!< bit:  5 THERM_CORR */
			uint8_t no_hold :1;  		/*!< bit:  6 NO_HOLD */
			uint8_t 			  :1;  		/*!< bit:  7 reserved */
	} b;
  uint8_t r;
} si7013_reg2_t;

	/** \brief  Union type for the structure of User Register3 in Si7013
	 */
typedef union
{
	struct
	{
			uint8_t heater	:4;  		/*!< bit:  0...3 Heater [3:0] */
			uint8_t 				:4;  		/*!< bit:  4...7 reserved */
	} b;
	uint8_t r;
} si7013_reg3_t;


typedef struct 
{
	si7013_reg1_t 	reg1;
	si7013_reg2_t 	reg2;
	si7013_reg3_t 	reg3;
} si7013_userReg_t;

HAL_StatusTypeDef si7013_get_device_id(I2C_HandleTypeDef *hi2c, int *id);
HAL_StatusTypeDef si7013_measure_intemperature(I2C_HandleTypeDef *hi2c, int32_t *temperature);
HAL_StatusTypeDef si7013_measure_humidity(I2C_HandleTypeDef *hi2c,	int32_t *humidity);
HAL_StatusTypeDef si7013_read_reg(I2C_HandleTypeDef *hi2c, uint8_t reg, uint8_t *val);
HAL_StatusTypeDef si7013_read_regs(I2C_HandleTypeDef *hi2c, si7013_userReg_t *Regs);
HAL_StatusTypeDef si7013_write_regs(I2C_HandleTypeDef *hi2c, si7013_userReg_t *Regs);
HAL_StatusTypeDef si7013_measure_thermistor(I2C_HandleTypeDef *hi2c, int16_t *value);

#endif
