#include "playground.h"
#include "numbers.h"
#include <cmath>

playground::playground(){}

playground::~playground(){}


int* playground::operator[](int x){
    if(x > 7 || x < 0)
        return 0;

    return playg[x];
}

void playground::setPlayground(snake* sn, food* fd)
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			playg[row][col] = 0;
		}
	}

	sn->temp = sn->head;

	do
	{
		if (sn->temp->tail_flag == 1)
		{
			playg[sn->temp->row_pos][sn->temp->column_pos] = 2;
		}
		else
		{
			playg[sn->temp->row_pos][sn->temp->column_pos] = 1;
		}

		sn->temp = sn->temp->next_element;
	}
	while (sn->temp->next_element != 0);

	if (fd->getSuperFood() == 1)
	{
		playg[fd->getFoodRow()][fd->getFoodColumn()] = 4;
	}
	else
	{
		playg[fd->getFoodRow()][fd->getFoodColumn()] = 3;
	}
}

void playground::outputFrameBuffer(led_matrix& lm)
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			switch (playg[row][col])
			{
				case 0:
				{
					lm.single_led(row,col,0,0,0);
					break;
				}
				case 1:
				{
					lm.single_led(row,col,0,255,0);
					break;
				}

				case 2:
				{
					lm.single_led(row,col,0,255,0);
					break;
				}

				case 3:
				{
					lm.single_led(row,col,0,0,255);
					break;
				}

				case 4:
				{
					lm.single_led(row,col,255,0,0);
					break;

				}
				case 5:
				{
					lm.single_led(row,col,255,255,255);
					break;
				}

				default:
				break;
			}
		}
	}
}

void playground::drawTens(int number[8][4])
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			playg[row][col] = number[row][col];
		}
	}
}


void playground::drawOnes(int number[8][4])
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			playg[row][col + 4] = number[row][col];
		}
	}
}

void playground::displayScore(int& score, led_matrix& lm)
{
	int tens = floor(score / 10);
	int ones = score % 10;

	switch (tens)
	{
		case 9:
		{
			drawTens(NumNine);
			break;		
		}

		case 8:
		{
			drawTens(NumEight);
			break;		
		}

		case 7:
		{
			drawTens(NumSeven);
			break;		
		}

		case 6:
		{
			drawTens(NumSix);
			break;		
		}

		case 5:
		{
			drawTens(NumFive);
			break;		
		}

		case 4:
		{
			drawTens(NumFour);
			break;		
		}

		case 3:
		{
			drawTens(NumThree);
			break;		
		}

		case 2:
		{
			drawTens(NumTwo);
			break;		
		}

		case 1:
		{
			drawTens(NumOne);
			break;		
		}

		case 0:
		{
			drawTens(NumZero);
			break;		
		}

		default:
		break;
	}

	switch (ones)
	{
		case 9:
		{
			drawOnes(NumNine);
			break;		
		}

		case 8:
		{
			drawOnes(NumEight);
			break;		
		}

		case 7:
		{
			drawOnes(NumSeven);
			break;		
		}

		case 6:
		{
			drawOnes(NumSix);
			break;		
		}

		case 5:
		{
			drawOnes(NumFive);
			break;		
		}

		case 4:
		{
			drawOnes(NumFour);
			break;		
		}

		case 3:
		{
			drawOnes(NumThree);
			break;		
		}

		case 2:
		{
			drawOnes(NumTwo);
			break;		
		}

		case 1:
		{
			drawOnes(NumOne);
			break;		
		}

		case 0:
		{
			drawOnes(NumZero);
			break;		
		}

		default:
		break;
	}

	outputFrameBuffer(lm);
}

void playground::die(snake* sn, food* fd, led_matrix lm, int& score)
{
	displayScore(score,lm);

	score = 0;

}
