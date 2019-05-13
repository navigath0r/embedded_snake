#ifndef SRC_FOOD_H_
#define SRC_FOOD_H_

#include "snake.h"
#include "playground.h"

class food
{
	typedef struct food_elem
	{
		int column;
		int row;
		int superfood;
	} food_elem;

public:

	int TTL_superfood;
	int foods_to_superfood;

	food();
	virtual ~food();

	food_elem getFoodCoord();
	int getTTLSuperfood();
	int getFoodsToSuperfood();

	int timerGen();
	void generateFood(),
	void generateSuperFood();





	
};




#endif /* SRC_FOOD_H_ */
