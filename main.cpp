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
	snake* sn;
	food* fd;

	int dir = 2;
	int button = 1;
	int gamestate = 3;
	int score = 0;


	while(true)
	{
		adc.getPotDirection(dir);
		adc.getButton(button);

		switch (gamestate)
		{
			case 1:
			{

				sn->moveSnake(dir,fd,lm,pg,score,gamestate);
				pg.setPlayground(sn,fd);
				pg.outputFrameBuffer(lm);

				if (score == 99)
				{
					gamestate = 2;
				}

				if (fd->getSuperFood() == 1)
				{
					usleep(250000);
					fd->TTL_superfood--;
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

				delete sn;
				delete fd;

				if (button == 0)
				{
					gamestate = 3;
				}
				break;
			}

			case 3:
			{
				sn = new snake;
				fd = new food(pg);

				gamestate = 1;
				break;
			}
		}


	}
	return 0;
}

