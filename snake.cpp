#include "snake.h"

snake::snake()
{

	head = new snake_element;
	head->next_element = 0;
	head->column_pos = 3;
	head->row_pos = 3;

	tail = head;
	tail->tail_flag = 1;

	temp = new snake_element;
}

snake::~snake(){}

void snake::moveSnake(const int& dir, playground& pg, food& fd, int& points) //default direction: right
{

	snake_element *new_head = new snake_element;
	int next_row;
	int next_col;

	next_coord(dir, next_row, next_col);

	switch (collisonDetect(pg, next_row, next_col, points))
	{
		case 1:
		{
			pg.die();
			break;
		}

		case 3:
		{
			fd.generateFood(pg);
			break;
		}

		case 4:
		{
			fd.generateFood(pg);
			break;
		}

		default:
		break;
	} 

	new_head->row_pos = next_row;
	new_head->column_pos = next_col;

	new_head->next_element = head;
	head = new_head;

	temp = head;

	if(extend_flag == 0)
	{

		while(temp->next_element->next_element == 0)
		{
			temp = temp->next_element;
		}

		delete temp->next_element;
		temp->tail_flag = 1;
	}
	else
	{
		extend_flag = 0;
	}

}

int snake::increaseCol()
{
	int col;

	if (head->column_pos < 7)
	{
		col = head->column_pos + 1;
	}
	else col = 0;

	return col;
}
int snake::decreaseCol()
{
	int col;

	if (head->column_pos > 0)
		{
			col = head->column_pos - 1;
		}
		else col = 7;

	return col;
}
int snake::increaseRow()
{
	int row;

	if (head->row_pos < 7)
		{
			row = head->row_pos + 1;
		}
		else row = 0;

	return row;
}

int snake::decreaseRow()
{
	int row;

	if (head->row_pos > 0)
			{
				row = head->row_pos - 1;
			}
			else row = 7;

	return row;
}

int snake::collisonDetect(playground& pg, int& next_row, int& next_col, int& points)
{
	
			switch (pg[next_row][next_col])
			{
				case 1:	//hit snake body, die
				{
					return 1;
				}

				case 3: //hit regular food
				{
					extend_flag = 1;
					points++;
					return 3;
				}

				case 4: //hit superfood
				{
					extend_flag = 1;
					points += 3;
					return 4;
				}

				default:
				{
					return 0;
					break;
				}
			}
}		

void snake::next_coord(const int& dir, int& next_row, int& next_col)
{
	switch (dir)
	{
		case 0:
		{
			next_row = head->row_pos;
			next_col = decreaseCol();
			break;
		}

		case 2:
		{
			next_row = head->row_pos;
			next_col = increaseCol();
			break;
		}

		case 1:
		{
			next_row = increaseRow();
			next_col = head->column_pos;
			break;
		}

		case 3:
		{
			next_row = decreaseRow();
			next_col = head->column_pos;
			break;
		}
		default:
			break;
	}
}
