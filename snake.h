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
		int row_pos;
		int column_pos;
		int tail_flag;
	} snake_element;

	snake_element *head;
	snake_element *tail;
	snake_element *temp;

	int extend_flag;

	snake();
	virtual ~snake();

	void moveSnake(const int& dir, const int& extend_flag);
	int increaseCol(const snake_element *current);
	int decreaseCol(const snake_element *current);
	int increaseRow(const snake_element *current);
	int decreaseRow(const snake_element *current);
	int collisonDetect(const int& dir, food& feed, playground& pg);
};
#endif /* SRC_SNAKE_H_ */
