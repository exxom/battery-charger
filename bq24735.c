
#include "bq24735.h"

//#############################################################
/*
		This function reads the chip manufacturer ID
		If the reading protocol is correct, the read value should be "0x0040" 
*/
uint16_t Manufacturer_ID(void){
	static uint8_t read[2];
	uint16_t data;
	uint8_t Reg;
	
	HAL_Delay(5);
	
	Reg=Manufacturer_ID_REG;
	HAL_I2C_Master_Transmit(&hi2c2,bq24735_add ,&Reg,1,100);
	HAL_I2C_Master_Receive(&hi2c2,bq24735_add ,read,2,100);
	data=(((uint16_t)read[1]<<8)|read[0]);
	
	return data;
	
}
//#############################################################
/*
		This function reads the chip device ID
		If the reading protocol is correct, the read value should be "0x001B" 
*/
uint16_t Device_ID(void){
	static uint8_t read[2];
	uint16_t data; 
	uint8_t Reg;
	
	HAL_Delay(5);
	
	Reg=Device_ID_REG;
	HAL_I2C_Master_Transmit(&hi2c2,bq24735_add ,&Reg,1,100);
	HAL_I2C_Master_Receive(&hi2c2,bq24735_add ,read,2,100);
	data=(((uint16_t)read[1]<<8)|read[0]);
	
	return data;
	
}
//#############################################################
/*
		This function reads the charge voltage
*/
uint16_t Read_Charge_Voltage(void){
	static uint8_t read[2];
	uint16_t data; 
	uint8_t Reg;
	
	HAL_Delay(5);
	
	Reg=Charge_Voltage_REG;
	HAL_I2C_Master_Transmit(&hi2c2,bq24735_add ,&Reg,1,100);
	HAL_I2C_Master_Receive(&hi2c2,bq24735_add ,read,2,100);
	data=(((uint16_t)read[1]<<8)|read[0]);
	
	return data;
	
}
//#############################################################
/*
		This function reads the charge current
*/
uint16_t Read_Charge_Current(void){
	static uint8_t read[2];
	uint16_t data; 
	uint8_t Reg;
	
	HAL_Delay(5);
	
	Reg=Charge_Current_REG;
	HAL_I2C_Master_Transmit(&hi2c2,bq24735_add ,&Reg,1,100);
	HAL_I2C_Master_Receive(&hi2c2,bq24735_add ,read,2,100);
	data=(((uint16_t)read[1]<<8)|read[0]);
	
	return data;
	
}
//#############################################################
/*
		This function reads the charge option
*/
uint16_t Read_Charge_Option(void){
	static uint8_t read[2];
	uint16_t data; 
	uint8_t Reg;
	
	HAL_Delay(5);
	
	Reg=Charge_Option_REG;
	HAL_I2C_Master_Transmit(&hi2c2,bq24735_add ,&Reg,1,100);
	HAL_I2C_Master_Receive(&hi2c2,bq24735_add ,read,2,100);
	data=(((uint16_t)read[1]<<8)|read[0]);
	
	return data;
	
}
//#############################################################
/*
		This function reads the input current
*/
uint16_t Read_Input_Current(void){
	static uint8_t read[2];
	uint16_t data; 
	uint8_t Reg;
	
	HAL_Delay(5);
	
	Reg=Input_Current_REG;
	HAL_I2C_Master_Transmit(&hi2c2,bq24735_add ,&Reg,1,100);
	HAL_I2C_Master_Receive(&hi2c2,bq24735_add ,read,2,100);
	data=(((uint16_t)read[1]<<8)|read[0]);
	
	return data;
	
}
//#############################################################
/*
		This function set the charge voltage
		In this function voltage must be given in mV according to the datasheet
		Charge Voltage Register (0x15H)
		BIT BIT NAME DESCRIPTION
		0 - Not used.
		1 - Not used.
		2 - Not used.
		3 - Not used.
		4 Charge Voltage, DACV 0 
		0 = Adds 0 mV of charger voltage.
		1 = Adds 16 mV of charger voltage.
		5 Charge Voltage, DACV 1 
		0 = Adds 0 mV of charger voltage.
		1 = Adds 32 mV of charger voltage.
		6 Charge Voltage, DACV 2 
		0 = Adds 0 mV of charger voltage.
		1 = Adds 64 mV of charger voltage.
		7 Charge Voltage, DACV 3 
		0 = Adds 0 mV of charger voltage.
		1 = Adds 128 mV of charger voltage.
		8 Charge Voltage, DACV 4 
		0 = Adds 0 mV of charger voltage.
		1 = Adds 256 mV of charger voltage.
		9 Charge Voltage, DACV 5 
		0 = Adds 0 mV of charger voltage.
		1 = Adds 512 mV of charger voltage.
		10 Charge Voltage, DACV 6 
		0 = Adds 0 mV of charger voltage.
		1 = Adds 1024 mV of charger voltage.
		11 Charge Voltage, DACV 7 
		0 = Adds 0 mV of charger voltage.
		1 = Adds 2048 mV of charger voltage.
		12 Charge Voltage, DACV 8 
		0 = Adds 0 mV of charger voltage.
		1 = Adds 4096 mV of charger voltage.
		13 Charge Voltage, DACV 9 
		0 = Adds 0 mV of charger voltage.
		1 = Adds 8192 mV of charger voltage.
		14 Charge Voltage, DACV 10 
		0 = Adds 0 mV of charger voltage.
		1 = Adds 16384 mV of charger voltage.
		15 - Not used.
		It can also sum of this values
*/
void Set_Charge_Voltage(uint16_t Voltage){
	uint8_t write[3];
	
	HAL_Delay(5);
	
	write[0]=Charge_Voltage_REG;
	write[1]=Voltage;
	write[2]=Voltage>>8;
	HAL_I2C_Master_Transmit(&hi2c2,bq24735_add,write,3,100);

}
//#############################################################
/*
		This function set the charge current
		In this function voltage must be given in mA according to the datasheet
		Charge Current Register (0x14H), Using a 10-mO Sense Resistor
		BIT BIT NAME DESCRIPTION
		0 – Not used.
		1 – Not used.
		2 – Not used.
		3 – Not used.
		4 – Not used.
		5 – Not used.
		6 Charge Current, DACICHG 0 
		0 = Adds 0 mA of charger current.
		1 = Adds 64 mA of charger current.
		7 Charge Current, DACICHG 1 
		0 = Adds 0 mA of charger current.
		1 = Adds 128 mA of charger current.
		8 Charge Current, DACICHG 2 
		0 = Adds 0 mA of charger current.
		1 = Adds 256 mA of charger current.
		9 Charge Current, DACICHG 3 
		0 = Adds 0 mA of charger current.
		1 = Adds 512 mA of charger current.
		10 Charge Current, DACICHG 4 
		0 = Adds 0 mA of charger current.
		1 = Adds 1024 mA of charger current.
		11 Charge Current, DACICHG 5 
		0 = Adds 0 mA of charger current.
		1 = Adds 2048 mA of charger current.
		12 Charge Current, DACICHG 6 
		0 = Adds 0 mA of charger current.
		1 = Adds 4096 mA of charger current.
		13 – Not used.
		14 – Not used.
		15 – Not used.
		It can also sum of this values
*/
void Set_Charge_Current(uint16_t Current){
	uint8_t write[3];
	
	HAL_Delay(5);
	
	write[0]=Charge_Current_REG;
	write[1]=Current;
	write[2]=Current>>8;
	HAL_I2C_Master_Transmit(&hi2c2,bq24735_add,write,3,100);
	
}
//#############################################################
/*
		 System current normally fluctuates as portions of the system are powered up or put to sleep. With the input
		 current limit, the output current requirement of the AC wall adapter can be lowered, reducing system cost.
		 The bq24735 provides an input current-limit range of 128 mA to 8.064 A, with 128-mA resolution.
		 The suggested input current limit is set to no less than 512 mA.
		 Sending InputCurrent() below 128 mA or above 8.064 A clears the register and terminates charging.
		 The default input current limit is 4096 mA.
		 Input Current Register (0x3FH), Using a 10-mO Sense Resistor
		 BIT BIT NAME DESCRIPTION
		 0 – Not used.
		 1 – Not used.
		 2 – Not used.
		 3 – Not used.
		 4 – Not used.
		 5 – Not used.
		 6 – Not used.
		 7 Input Current, DACIIN 0 0 = Adds 0 mA of input current.
		 1 = Adds 128 mA of input current.
		 8 Input Current, DACIIN 1 0 = Adds 0 mA of input current.
		 1 = Adds 256 mA of input current.
		 9 Input Current, DACIIN 2 0 = Adds 0 mA of input current.
		 1 = Adds 512 mA of input current.
		 10 Input Current, DACIIN 3 0 = Adds 0 mA of input current.
		 1 = Adds 1024 mA of input current.
		 11 Input Current, DACIIN 4 0 = Adds 0 mA of input current.
		 1 = Adds 2048 mA of input current.
		 12 Input Current, DACIIN 5 0 = Adds 0 mA of input current.
		 1 = Adds 4096 mA of input current.
		 13 – Not used.
		 14 – Not used.
		 15 – Not used.
		 It can also sum of this values
*/
//#############################################################

void Set_Input_Current(uint16_t Current){
	uint8_t write[3];
	
	HAL_Delay(5);
	
	write[0]=Input_Current_REG;
	write[1]=Current;
	write[2]=Current>>8;
	HAL_I2C_Master_Transmit(&hi2c2,bq24735_add,write,3,100);
	
}
//#############################################################
/*
		This function set charge option register 
*/
void Set_Charge_Option(uint16_t Value){
	uint8_t write[3];
	
	HAL_Delay(5);
	
	write[0]=Charge_Option_REG;
	write[1]=Value;
	write[2]=Value>>8;
	HAL_I2C_Master_Transmit(&hi2c2,bq24735_add,write,3,100);
}
//#############################################################
/*
		This function set status of charger
		Status string :
		if "off" = charger off 
		if "on"  = charger on
*/

void Charger_Status(char* status){
	uint16_t state;
			
		if(strstr(status,"on")){
			state=Read_Charge_Option();
			state&=~(1<<0);
			Set_Charge_Option(state);
		}else if(strstr(status,"off")){
			state=Read_Charge_Option();
			state|=(1<<0);
			Set_Charge_Option(state);
		}
}
//#############################################################
/*
		This function set ACOK deglitch time
		If Value 150 = ACOK deglitch time set to 150ms 
		If Value 1300 = ACOK deglitch time set to 1.3s<default>
*/
void ACOK_Time(uint16_t Value){
	uint16_t state;
	
	switch(Value){
		case 150:
			state=Read_Charge_Option();
			state&=~(1<<0);
			Set_Charge_Option(state);
		break;
		case 1300:
			state=Read_Charge_Option();
			state|=(1<<0);
			Set_Charge_Option(state);
		break;
	}
}
//#############################################################
/*
	 This function set watchdog time for charge voltage and charge current values
	 If Value 0 = disable waychdog timer
	 If Value 44 = watchdog time is 44s
	 If Value 88 = watchdog time is 88s
	 If Value 175 = watchdog time is 175s<default>
*/
void Watchdog_Time(uint8_t Value){
	uint16_t state;
	
	switch(Value){
		case 0:
			state=Read_Charge_Option();
			state&=~((1<<14)|(1<<13));
			Set_Charge_Option(state);
		break;
		case 44:
			state=Read_Charge_Option();
			state|=(1<<13);
			state&=~(1<<14);
			Set_Charge_Option(state);
		break;
		case 88:
			state=Read_Charge_Option();
			state|=(1<<14);
			state&=~(1<<13);
			Set_Charge_Option(state);
		break;
		case 175: 
			state=Read_Charge_Option();
			state|=((1<<14)|(1<<13));
			Set_Charge_Option(state);
		break;
	}
}
//#############################################################
/*
	 This function set deplition battery threshould 
	 00: Falling Threshold = 59.19% of voltage regulation limit
		(approximately 2.486 V/cell)
	 01: Falling Threshold = 62.65% of voltage regulation limit
		(approximately 2.631 V/cell)
	 10: Falling Threshold = 66.55% of voltage regulation limit
		(approximately 2.795 V/cell)
	 11: Falling Threshold = 70.97% of voltage regulation limit
		(approximately 2.981 V/cell) < default>
*/
void BAT_Depletion_Th(float Value){
	uint16_t state;
	
	if(Value==59.19){
		state=Read_Charge_Option();
		state&=~((1<<12)|(1<<11));
		Set_Charge_Option(state);
	}else if(Value==62.65){
		state=Read_Charge_Option();
		state|=(1<<11);
		state&=~(1<<12);
		Set_Charge_Option(state);
	}else if(Value==66.55){
		state=Read_Charge_Option();
		state|=(1<<12);
		state&=~(1<<11);
		Set_Charge_Option(state);
	}else if(Value==70.97){
		state=Read_Charge_Option();
		state|=((1<<12)|(1<<11));
		Set_Charge_Option(state);
	}
}
//#############################################################
/*
	 This function set PWM switching frequency
	 If Status string "reduce":
	 0: Reduce PWM switching frequency by 18% <default>
	 If Status string "increase":
	 1: Increase PWM switching frequency by 18%	
*/
void PWM_Fer(char* Status){
	uint16_t state;
	
	if(strstr(Status,"reduce")){
		state=Read_Charge_Option();
		state&=~(1<<10);
		Set_Charge_Option(state);
	}else if(strstr(Status,"increase")){
		state=Read_Charge_Option();
		state|=(1<<10);
		Set_Charge_Option(state);
	}
}
//#############################################################
/*
	 This function Enable/Disable PWM switching frequency
	 If Status string "disable":
	 0: Disable adjust PWM switching frequency <default>
	 If Status string "enable":
	 1: Enable adjust PWM switching frequency	
*/
void PWM_Status(char* Status){
	uint16_t state;
	
	if(strstr(Status,"disable")){
		state=Read_Charge_Option();
		state&=~(1<<9);
		Set_Charge_Option(state);
	}else if(strstr(Status,"enable")){
		state=Read_Charge_Option();
		state|=(1<<9);
		Set_Charge_Option(state);
	}
}
//#############################################################
/*
		This function setShort circuit protection high-side MOSFET
		If Value = 0: function is disabled
		If Value = 1: 750 mV <default>
*/
void IFAULT_HI_Th(uint8_t Value){
	uint16_t state;
	
	switch(Value){
		case 0:
			state=Read_Charge_Option();
			state&=~(1<<8);
			Set_Charge_Option(state);
		break;
		case 1:
			state=Read_Charge_Option();
			state|=(1<<8);
			Set_Charge_Option(state);
		break;
	}
}
//#############################################################
/*
		This function set Short circuit protection low-side MOSFET
		If Value = 0: 135 mV <default>
		If Value = 1: 230 mV
*/
void IFAULT_LOW_Th(uint8_t Value){
	uint16_t state;
	
	switch(Value){
		case 0:
			state=Read_Charge_Option();
			state&=~(1<<7);
			Set_Charge_Option(state);
		break;
		case 1:
			state=Read_Charge_Option();
			state|=(1<<7);
			Set_Charge_Option(state);
		break;
	}
}
//#############################################################
/*
		This function set status of battery learn cycle
		If Status string "disable":
		0: Disable LEARN Cycle <default>
		If Status string "Enable":
		1: Enable LEARN Cycle
*/
void Learn_EN(char* Status){
	uint16_t state;
	
	if(strstr(Status,"disable")){
		state=Read_Charge_Option();
		state&=~(1<<6);
		Set_Charge_Option(state);
	}else if(strstr(Status,"enable")){
		state=Read_Charge_Option();
		state|=(1<<6);
		Set_Charge_Option(state);
	}
}
//#############################################################
/*
		This function select IOUT
		If Value = 0: IOUT is the 20x adapter current amplifier output <default>
		If Value = 1: IOUT is the 20x charge current amplifier output
*/
void IOUT(uint8_t Value){
	uint16_t state;
	
	switch(Value){
		case 0:
			state=Read_Charge_Option();
			state&=~(1<<5);
			Set_Charge_Option(state);
		break;
		case 1:
			state=Read_Charge_Option();
			state|=(1<<5);
			Set_Charge_Option(state);
		break;
	}
}
//#############################################################
/*
		This function Enable/Disable BOOST mode
		If Status string "disable":
		0: Disable Turbo Boost function <default>
		If Status string "Enable":
		1: Enable Turbo Boost function
*/
void BOOST_EN(char* Status){
	uint16_t state;
	
	if(strstr(Status,"disable")){
		state=Read_Charge_Option();
		state&=~(1<<3);
		Set_Charge_Option(state);
	}else if(strstr(Status,"enable")){
		state=Read_Charge_Option();
		state|=(1<<3);
		Set_Charge_Option(state);
	}
}
//#############################################################
/*
		This function set ACOC threshould
		0: function is disabled
		1: 3.33x of input current regulation limit <default>		
*/
void ACOC_Th(uint8_t Value){
	uint16_t state;
	
	switch(Value){
		case 0:
			state=Read_Charge_Option();
			state&=~(1<<1);
			Set_Charge_Option(state);
		break;
		case 1:
			state=Read_Charge_Option();
			state|=(1<<1);
			Set_Charge_Option(state);
		break;
	}
}
