#include "snake.h"

snake::snake()
{

	head = new snake_element;
	head->next_element = 0;
	head->column_pos = 3;
	head->row_pos = 3;

	tail = head;

	temp = new snake_element;
}

snake::~snake(){}

void snake::moveSnake(const int* dir, const int* extend_flag) //default direction: right
{
	switch (dir)
	{
		case 0:	//left
			if (head->next_element->row_pos != head->row_pos)
			{
				snake_element *new_head = new snake_element;
				new_head->column_pos = decreaseCol(head);
				new_head->row_pos = head->row_pos;
				new_head->next_element = head;
				head = new_head;

				if(extend_flag == 0)
				{

					while(temp->next_element->next_element == 0)
					{
						temp = temp->next_element;
					}

					delete temp->next_element;
					tail = temp;
				}
			}
		break;

		case 2:	//right
			if (head->next_element->row_pos != head->row_pos)
			{
				snake_element *new_head = new snake_element;
				new_head->column_pos = increaseCol(head);
				new_head->row_pos = head->row_pos;
				new_head->next_element = head;
				head = new_head;

				if(extend_flag == 0)
				{

					while(temp->next_element->next_element == 0)
					{
						temp = temp->next_element;
					}

					delete temp->next_element;
					tail = temp;
				}
			}
		break;

		case 1:	//up
			if (head->next_element->column_pos != head->column_pos)
			{
				snake_element *new_head = new snake_element;
				new_head->column_pos = head->column_pos;
				new_head->row_pos = increaseRow(head);
				new_head->next_element = head;
				head = new_head;

				if(extend_flag == 0)
				{

					while(temp->next_element->next_element == 0)
					{
						temp = temp->next_element;
					}

					delete temp->next_element;
					tail = temp;
				}
			}
		break;

		case 3:	//down
			if (head->next_element->column_pos != head->column_pos)
			{
				snake_element *new_head = new snake_element;
				new_head->column_pos = head->column_pos;
				new_head->row_pos = decreaseRow(head);
				new_head->next_element = head;
				head = new_head;

				if(extend_flag == 0)
				{

					while(temp->next_element->next_element == 0)
					{
						temp = temp->next_element;
					}

					delete temp->next_element;
					tail = temp;
				}
			}
		break;

	}

}


int snake::increaseCol(snake_element *current)
{
	int col;

	if (current->column_pos < 7)
	{
		col = current->column_pos + 1;
	}
	else col = 0;

	return col;
}
int snake::decreaseCol(snake_element *current)
{
	int col;

	if (current->column_pos > 0)
		{
			col = current->column_pos - 1;
		}
		else current->column_pos = 7;
}
int snake::increaseRow(snake_element *current)
{
	int row;

	if (current->row_pos < 7)
		{
			row = current->row_pos + 1;
		}
		else current->row_pos = 0;
}
int snake::decreaseRow(snake_element *current)
{
	int row;

	if (current->row_pos > 0)
			{
				row = current->row_pos - 1;
			}
			else current->row_pos = 7;
}
int snake::collisonDetect(const int* dir, const foodcoord* food_coord)
{
	switch (dir)
	{
		case 0:	//left
			if (head->next_element->row_pos != head->row_pos)
			{
				snake_element *new_head = new snake_element;
				new_head->column_pos = decreaseCol(head);
				new_head->row_pos = head->row_pos;
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
					tail = temp;
				}
			}
		break;

		case 2:	//right
			if (head->next_element->row_pos != head->row_pos)
			{
				snake_element *new_head = new snake_element;
				new_head->column_pos = increaseCol(head);
				new_head->row_pos = head->row_pos;
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
					tail = temp;
				}
			}
		break;

		case 1:	//up
			if (head->next_element->column_pos != head->column_pos)
			{
				snake_element *new_head = new snake_element;
				new_head->column_pos = head->column_pos;
				new_head->row_pos = increaseRow(head);
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
					tail = temp;
				}
			}
		break;

		case 3:	//down
			if (head->next_element->column_pos != head->column_pos)
			{
				snake_element *new_head = new snake_element;
				new_head->column_pos = head->column_pos;
				new_head->row_pos = decreaseRow(head);
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
					tail = temp;
				}
			}
		break;

	}
}
