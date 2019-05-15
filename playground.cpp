#include "playground.h"

playground::playground(){}

playground::~playground(){}

int* playground::operator[](int x){
    if(x > 7 || x < 0)
        return 0;

    return playg[x];
}

void playground::setPlayground(snake& sn, food_elem& feed)
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			playg[row][col] = 0;
		}
	}

	sn.temp = sn.head;

	while (sn.temp->next_element == 0)
	{
		if (sn.temp->tail_flag == 1)
		{
			playg[sn.temp->row_pos][sn.temp->column_pos] = 2;
		}
		else
		{
			playg[sn.temp->row_pos][sn.temp->column_pos] = 1;
		}

		sn.temp = sn.temp->next_element;
	}

	if (feed.superfood == 1)
	{
		playg[feed.row][feed.column] = 4;
	}
	else
	{
		playg[feed.row][feed.column] = 3;
	}
}
