#include "led_matrix.h"

led_matrix::led_matrix()
{
	initLedMatrix();
}

void led_matrix::single_led(uint8_t row_pos,uint8_t column_pos,uint8_t redvalue,uint8_t greenvalue,uint8_t bluevalue)
{
	uint32_t Addr = 0;
	uint32_t Data = 0;
	Addr=ConfigPtr_->MemBaseAddress+(4*column_pos)+(8*4*row_pos);
	Data=Data+redvalue;
	Data=(Data<<8)+greenvalue;
	Data=(Data<<8)+bluevalue;
	XBram_Out32(Addr, Data);
}

void led_matrix::ledMatrixOut32()
{
	for(uint8_t row_pos=0 ; row_pos<8 ; row_pos++)
	{
		for(uint8_t column_pos=0 ; column_pos<8 ; column_pos++)
		{
			uint8_t redvalue=LedMatrixArray[row_pos][column_pos][0];
			uint8_t greenvalue=LedMatrixArray[row_pos][column_pos][1];
			uint8_t bluevalue=LedMatrixArray[row_pos][column_pos][2];
			single_led(row_pos,column_pos,redvalue,greenvalue,bluevalue);
		}
	}
}

int led_matrix::initLedMatrix()
{
	int Status;

	Status = initializeBRAM(BramDeviceId);

	if (Status != XST_SUCCESS ) {
		xil_printf("xBram Initialization Failed\r\n");
		return XST_FAILURE;
	}

	return XST_SUCCESS;
}

int led_matrix::initializeBRAM(uint16_t DeviceId)
{
	int Status;

	ConfigPtr_ = XBram_LookupConfig(DeviceId);
	if (ConfigPtr_ == (XBram_Config *) NULL) {
		return XST_FAILURE;
	}

	Status = XBram_CfgInitialize(&Bram, ConfigPtr_,
				     ConfigPtr_->CtrlBaseAddress);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}


        initializeECC(ConfigPtr_, ConfigPtr_->CtrlBaseAddress);


	/*
	 * Execute the BRAM driver selftest.
	 */
	Status = XBram_SelfTest(&Bram, 0);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	return XST_SUCCESS;
}



void led_matrix::initializeECC(XBram_Config *ConfigPtr, u32 EffectiveAddr)
{
	u32 Addr;
	volatile u32 Data;

	if (ConfigPtr->EccPresent &&
	    ConfigPtr->EccOnOffRegister &&
	    ConfigPtr->EccOnOffResetValue == 0 &&
	    ConfigPtr->WriteAccess != 0) {
		for (Addr = ConfigPtr->MemBaseAddress;
		     Addr < ConfigPtr->MemHighAddress; Addr+=4) {
			Data = XBram_In32(Addr);
			XBram_Out32(Addr, Data);
		}
		XBram_WriteReg(EffectiveAddr, XBRAM_ECC_ON_OFF_OFFSET, 1);
	}
}
