#ifndef __BQ24735_H__
#define __BQ24735_H__


#include "stm32f1xx_hal.h"
#include "main.h"
#include "string.h"
#include "i2c.h"

#define bq24735_add                 0x12
#define Manufacturer_ID_REG         0xFE
#define Device_ID_REG               0xFF
#define Charge_Voltage_REG          0x15
#define Charge_Current_REG          0x14
#define Charge_Option_REG           0x12
#define Input_Current_REG           0x3F


//***********Reading functions from Bq24735 registers

uint16_t Manufacturer_ID(void);
uint16_t Device_ID(void);
uint16_t Read_Charge_Voltage(void);
uint16_t Read_Charge_Current(void);
uint16_t Read_Charge_Option(void);
uint16_t Read_Input_Current(void);

//****************************************************

//**************Writing functions on Bq24735 registers

void Set_Charge_Current(uint16_t Current);
void Set_Charge_Voltage(uint16_t Voltage);
void Set_Input_Current(uint16_t Current);
void Set_Charge_Option(uint16_t Value);

//****************************************************

//******************Set bits of charge option register
void Charger_Status(char* status);
void ACOK_Time(uint16_t Value);
void Watchdog_Time(uint8_t Value);
void BAT_Depletion_Th(float Value);
void PWM_Fer(char* Status);
void PWM_Status(char* Status);
void IFAULT_HI_Th(uint8_t Value);
void IFAULT_LOW_Th(uint8_t Value);
void Learn_EN(char* Status);
void IOUT(uint8_t Value);
void BOOST_EN(char* Status);
void ACOC_Th(uint8_t Value);
//****************************************************
#endif