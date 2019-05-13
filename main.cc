#include "led_matrix.h"
#include "sleep.h"
#include "xparameters.h"
#include "xbram.h"
#include "ADC.h"
#include "snake.h"
#include "food.h"
#include "playground.h"
#include <stdio.h>

int main()
{
	ADC adc;
	led_matrix lm;

	int column = 3;
	int row = 3;

	lm.LedMatrixArray[column][row][0]=255;
	lm.ledMatrixOut32();


	while(true)
	{


		switch (adc.getPotDirection())
			{
				case 0:
						lm.LedMatrixArray[row][column][0] = 0;
						lm.ledMatrixOut32();
						column--;
						lm.LedMatrixArray[row][column][0] = 255;
						lm.ledMatrixOut32();
					break;
				case 2:
						lm.LedMatrixArray[row][column][0] = 0;
						lm.ledMatrixOut32();
						column++;
						lm.LedMatrixArray[row][column][0] = 255;
						lm.ledMatrixOut32();
					break;
				case 1:
						lm.LedMatrixArray[row][column][0] = 0;
						lm.ledMatrixOut32();
						row++;
						lm.LedMatrixArray[row][column][0] = 255;
						lm.ledMatrixOut32();
					break;
				case 3:
						lm.LedMatrixArray[row][column][0] = 0;
						lm.ledMatrixOut32();
						row--;
						lm.LedMatrixArray[row][column][0] = 255;
						lm.ledMatrixOut32();
					break;
				default:
					break;
			}

		usleep(250000);

	}
	return 0;
}

