#ifndef SRC_SNAKE_H_
#define SRC_SNAKE_H_

#include "playground.h"
#include "food.h"

class snake
{
public:

	typedef struct snake_element
	{
		struct snake_element* next_element;
		int column_pos;
		int row_pos;
	} snake_element;

	snake_element *head;
	snake_element *tail;
	snake_element *temp;

	int extend_flag;

	snake();
	virtual ~snake();

	void moveSnake(const int& dir, const int& extend_flag);
	int increaseCol(snake_element &current);
	int decreaseCol(snake_element &current);
	int increaseRow(snake_element &current);
	int decreaseRow(snake_element &current);
	int collisonDetect();
};
#endif /* SRC_SNAKE_H_ */
