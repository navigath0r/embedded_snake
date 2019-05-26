#ifndef SRC_FOOD_H_
#define SRC_FOOD_H_

#include "snake.h"
#include "playground.h"

class playground;
class food
{
	typedef struct food_elem
	{
		int row;
		int column;
		int superfood;
	} food_elem;

public:

	food_elem kaja;
	int TTL_superfood;
	int foods_to_superfood = 1;

	food(playground& pg);
	virtual ~food();

	food_elem getFoodCoord();
	int getFoodRow();
	int getFoodColumn();
	int getTTLSuperfood();
	int getFoodsToSuperfood();
	int getSuperFood();
	int generateFood(playground& pg);





	
};




#endif /* SRC_FOOD_H_ */
