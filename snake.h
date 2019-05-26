#ifndef SRC_SNAKE_H_
#define SRC_SNAKE_H_

#include "playground.h"
#include "food.h"
#include "ADC.h"
#include "led_matrix.h"

class playground;
class food;

typedef struct snake_element
	{
		struct snake_element* next_element;
		int row_pos;
		int column_pos;
		int tail_flag;
	} snake_element;


class snake
{
public:

	

	snake_element *head;
	snake_element *tail;
	snake_element *temp;
	snake_element *temp_to_del;

	int extend_flag = 0;

	snake();
	virtual ~snake();

	void moveSnake(const int& dir, food* fd, led_matrix& lm, playground& pg, int& score, int& gamestate);
	int increaseCol();
	int decreaseCol();
	int increaseRow();
	int decreaseRow();
	void next_coord(const int& dir, int& next_row, int& next_col);
	int collisonDetect(playground& pg, int& next_row, int& next_col, int& score);

};
#endif /* SRC_SNAKE_H_ */
