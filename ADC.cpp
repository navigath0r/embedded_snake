#include "ADC.h"

//Public functions
ADC::ADC()
{
	initADC();
}

ADC::~ADC(){}

u16 ADC::readADC(u8 Channel)
{
	return XAdcPs_GetAdcData(&XAdc_, Channel);
}

float ADC::readVoltage(u8 Channel)
{
	return XAdcPs_RawToVoltage(XAdcPs_GetAdcData(&XAdc_, Channel));
}

void ADC::printADCReading(u8 Channel)
{
	u16 readData = readADC(Channel);

	switch (Channel)
	{
		case BUTTON:
				printf("The value of the button is %0d \r\n\n\n\n\n\n\n\n\n",
						readData);
			break;
		case YAXIS:
			printf("The value of the y-axis is %0d \r\n",
					readData);
			break;
		case XAXIS:
			printf("The value of the x-axis is %0d \r\n",
					readData);
			break;
		case POT:
			printf("The value of the pot is %0d \r\n",
					readData);
			break;
		default:
			break;
	}
}

int ADC::getPotDirection(int& direction)
{
	u16 x_axis = readADC(XAXIS);
	u16 y_axis = readADC(YAXIS);

	printADCReading(XAXIS);
	printADCReading(YAXIS);
	printADCReading(POT);
	printADCReading(BUTTON);

	if (y_axis > 1400 && x_axis > 15000 && x_axis < 50000) direction = 0;	//left
	if (y_axis < 250 && x_axis > 15000 && x_axis < 50000) direction = 2;	//right
	if (x_axis < 15000 && y_axis > 250 && y_axis < 1400) direction = 1;		//up
	if (x_axis > 50000 && y_axis > 250 && y_axis < 1400) direction = 3;		//down

	xil_printf("direction: %d", direction);

	return direction;
}

int ADC::getButton(int button)
{
	button = readADC(BUTTON);

	return button;
}

//Private functions
int ADC::initADC()
{
	/*
	 * Initialize the XAdc driver.
	 */
	ConfigPtr_ = XAdcPs_LookupConfig(XADC_DEVICE_ID_);
	if (ConfigPtr_ == NULL)
	{
		return XST_FAILURE;
	}
	XAdcPs_CfgInitialize(&XAdc_, ConfigPtr_, ConfigPtr_->BaseAddress);

	/*
	 * Self Test the XADC/ADC device
	 */
	if (XAdcPs_SelfTest(&XAdc_) != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	/*
	 * Disable the Channel Sequencer before configuring the Sequence
	 * registers.
	 */
	XAdcPs_SetSequencerMode(&XAdc_, XADCPS_SEQ_MODE_CONTINPASS);

	return XST_SUCCESS;
}


int ADC::XAdcFractionToInt(float FloatNum)
{
	float Temp;

	Temp = FloatNum;
	if (FloatNum < 0) {
		Temp = -(FloatNum);
	}

	return( ((int)((Temp -(float)((int)Temp)) * (1000.0f))));
}
