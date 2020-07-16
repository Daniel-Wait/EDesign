/*
 * myfunctions.h
 *
 *  Created on: 01 Apr 2019
 *      Author: 20887507
 */

#ifndef MYFUNCTIONS_H_
#define MYFUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "main.h"
#include "bme280.h"
#include "lis2dh12_reg.h"


extern UART_HandleTypeDef huart1;
extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim6;
extern I2C_HandleTypeDef hi2c1;
extern ADC_ChannelConfTypeDef sConfig1;
extern ADC_ChannelConfTypeDef sConfig2 ;

extern HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);

void user_init(void);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void process_buffer(void);
bool check_gga(char *message);
bool is_valid(const char *message, int size);
int check_sum(const char *message, int length);
void split_extract(char *string);
void format_gps(void);
void format_count(void);
void display(void);
void burn_signal(void);
void adc_sb(void);
void format_power(void);
void lcd_init(void);
void lcd_data_write(uint8_t data);
void lcd_instr_write(uint8_t dbs);
void user_delay(uint32_t delay);
void lcd_out(void);
void sensor_init(void);
int8_t user_i2c_read(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len);
int8_t user_i2c_write(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len);
void stream_sensor_data_normal_mode(struct bme280_dev *dev);
void stream_sensor_data_forced_mode(struct bme280_dev *dev);
void format_bme280(void);
void stream_accelerometer_data(void);
int32_t platform_write(void *handle, uint8_t reg, uint8_t *bufp,uint16_t len);
int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp,uint16_t len);
void standardize_accel(void);
void format_accel(void);

//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
#endif /* MYFUNCTIONS_H_ */
