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

	int column = 2;
	int row = 3;

	lm.LedMatrixArray[row][column][0]=255;
	lm.ledMatrixOut32();

	int dir;


	while(true)
	{
		adc.getPotDirection(dir);
		if (adc.readADC(22) == 0) dir = 4;


		switch (dir)
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

