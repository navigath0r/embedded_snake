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

void snake::moveSnake(const int& dir, const int& extend_flag) //default direction: right
{

	snake_element *new_head = new snake_element;

	switch (dir)
	{
		case 0:	//left
		{
			if (head->next_element->row_pos != head->row_pos)
			{				
				new_head->column_pos = decreaseCol(head);
				new_head->row_pos = head->row_pos;				
			}
		break;
		}

		case 2:	//right
		{
			if (head->next_element->row_pos != head->row_pos)
			{				
				new_head->column_pos = increaseCol(head);
				new_head->row_pos = head->row_pos;				
			}
		break;
		}

		case 1:	//up
		{
			if (head->next_element->column_pos != head->column_pos)
			{				
				new_head->column_pos = head->column_pos;
				new_head->row_pos = increaseRow(head);				
			}
		break;
		}

		case 3:	//down
		{
			if (head->next_element->column_pos != head->column_pos)
			{
				new_head->column_pos = head->column_pos;
				new_head->row_pos = decreaseRow(head);
			}
		break;
		}

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
}


int snake::increaseCol(const snake_element *current)
{
	int col;

	if (current->column_pos < 7)
	{
		col = current->column_pos + 1;
	}
	else col = 0;

	return col;
}
int snake::decreaseCol(const snake_element *current)
{
	int col;

	if (current->column_pos > 0)
		{
			col = current->column_pos - 1;
		}
		else col = 7;

	return col;
}
int snake::increaseRow(const snake_element *current)
{
	int row;

	if (current->row_pos < 7)
		{
			row = current->row_pos + 1;
		}
		else row = 0;

	return row;
}

int snake::decreaseRow(const snake_element *current)
{
	int row;

	if (current->row_pos > 0)
			{
				row = current->row_pos - 1;
			}
			else row = 7;

	return row;
}
int snake::collisonDetect(const int& dir, food& feed, playground& pg)
{
	int** playground = pg.getPlayground();

	switch (dir)
	{
		case 0:	//left
		{
			switch (playground[head->row][decreaseCol(head)])
			{
				case 1:	//hit snake body, die
				{
					return 1;
				}
				case 3: //hit regular food
				{
					extend_flag = 1;
				return 3;
				}
				case 4: //hit superfood
				{
					extend_flag = 1;
				return 4;
				}

			}
		}
	}

}

