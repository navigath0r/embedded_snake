#ifndef SRC_LED_MATRIX_H_
#define SRC_LED_MATRIX_H_

/***************************** Include Files *********************************/
#include "xparameters.h"
#include "xbram.h"
#include <stdio.h>

/************************** Constant Definitions *****************************/
#define BRAM_DEVICE_ID		XPAR_BRAM_0_DEVICE_ID

/************************** Function Prototypes ******************************/
class led_matrix
{
	public://Public function definitions************************************************
		led_matrix();
		void ledMatrixOut32();
		uint8_t LedMatrixArray[8][8][3] = {};

		/*****************************************************************************/
		/**
		* Writes the value of 1 LED by the function XBram_Out32
		* @param	its row and column position, as well as its red, green and blue values
		* @return   Nothing
		* @note		None.
		******************************************************************************/
		void single_led(uint8_t row_pos,uint8_t column_pos,uint8_t redvalue,uint8_t greenvalue,uint8_t bluevalue);

	private: // Private variable definitions********************************************
		XBram Bram;	/* The Instance of the BRAM Driver */
		uint16_t BramDeviceId = XPAR_BRAM_0_DEVICE_ID;
		XBram_Config *ConfigPtr_;

	private: // Private function definitions********************************************



		/*****************************************************************************/
		/**
		* Initializes the device.
		* @param	None.
		* @return
		*		- XST_SUCCESS to indicate success.
		*		- XST_FAILURE to indicate failure.
		* @note		None.
		******************************************************************************/
		int initLedMatrix();

		//From the xbram controller example********************************************
		int initializeBRAM(uint16_t DeviceId);
		void initializeECC(XBram_Config *ConfigPtr, u32 EffectiveAddr);
};

#endif /* SRC_LED_MATRIX_H_ */
