#ifndef SRC_ADC_H_
#define SRC_ADC_H_

// Xilinx Libraries Begin
#include "xparameters.h"
#include "xadcps.h"
#include "xstatus.h"
#include "xil_printf.h"
// Xilinx Libraries End

// Libraries Begin
#include <stdio.h>
#include <stdint.h>
// Libraries End

// Magic Numbers Begin
#define BUTTON 22
#define YAXIS  23
#define XAXIS  30
#define POT    31
// Magic Numbers End

// ADC_Measurements
// Button:
//	 up:	 65535
//   down:	 11160
// y-axis:
// 	right:    4104 128
//	middle:  33349 700
//	left:      60803 1600
// x-axis:
// 	down:   65469  64980
//	middle:  33842 33700
//	up:    2741    3480
// POT:
//	CCW: 	 125 150
//  CW:  65517	 64530

class ADC
{
	public:

		/*****************************************************************************/
		/**
		* Constructor: Initiates the ADCs using the initADC function
		*
		* @param	None.
		* @return	None
		* @note		None.
		******************************************************************************/
		ADC();
		virtual ~ADC();

		/*****************************************************************************/
		/**
		* Reads the value of a specified ADC
		*
		* @param	u8 Channel: Chooses between AUX channels 0 to 31
		* @return	uint16_6 Value: The read ADC value
		* @note		None.
		******************************************************************************/
		u16 readADC(u8 Channel);

		/*****************************************************************************/
		/**
		* Reads the value of a specified ADC and returns the read voltage as a float
		*
		* @param	u8 Channel: Chooses between AUX channels 0 to 31
		* @return	uint16_6 Voltage: The read voltage
		* @note		None.
		******************************************************************************/
		float readVoltage(u8 Channel);

		/*****************************************************************************/
		/**
		* Reads the value of a specified ADC and prints the read voltage to the screen
		*
		* @param	u8 Channel: Chooses between AUX channels 0 to 31
		* @return	None.
		* @note		None.
		******************************************************************************/
		void printADCReading(u8 Channel);

		int getPotDirection(int& direction);

		int getButton(int button);

	//Private variables
	private:
		uint16_t XADC_DEVICE_ID_ = XPAR_XADCPS_0_DEVICE_ID;
		XAdcPs XAdc_;
		XAdcPs_Config *ConfigPtr_;
	//Private functions
	private:

		/*****************************************************************************/
		/**
		* Initiates the ADC using predefined Xilinx functions
		*
		* @param	None.
		* @return	None
		* @note		None.
		******************************************************************************/
		int initADC();

		/*****************************************************************************/
		/**
		* Converts the fraction of the float value into an integer. Used to output to screen.
		*
		* @param	float FloatNum: The read value from the ADC
		* @return	int: The fraction of the float
		* @note		None.
		******************************************************************************/
		int XAdcFractionToInt(float FloatNum);
};

#endif /* SRC_ADC_H_ */
