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
	playground pg;

	int dir;
	int gamestate = 0;
	int score = 0;


	while(true)
	{
		adc.getPotDirection(dir);

		switch (gamestate)
		{
			case 1:
			{
				sn.moveSnake(dir,fd,lm,pg,score,gamestate);
				pg.setPlayground(sn,fd);
				pg.outputFrameBuffer(lm);

				if (score == 99)
				{
					gamestate = 2;
				}

				if (fd.getSuperFood() == 1)
				{
					usleep(250000);
				}
				else
				{
					usleep(500000);
				}
				break;
			}

			case 2:
			{
				pg.die(sn,fd,lm,score);

				if (adc.getButton() == 0)
				{
					gamestate = 3;
				}
				break;
			}
			case 3:
			{
				snake sn;
				food fd(pg);

				gamestate = 1;
			}
		}


	}
	return 0;
}

