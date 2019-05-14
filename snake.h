#ifndef SRC_SNAKE_H_
#define SRC_SNAKE_H_

#include "playground.h"
#include "food.h"

class playground;
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

	void moveSnake(const int& dir);
	int increaseCol();
	int decreaseCol();
	int increaseRow();
	int decreaseRow();
	void next_coord(const int& dir, int& next_row, int& next_col);
	int collisonDetect(const int& dir, playground& pg, int& next_row, int& next_col);
};
#endif /* SRC_SNAKE_H_ */
