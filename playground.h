#ifndef SRC_PLAYGROUND_H_
#define SRC_PLAYGROUND_H_

#include "snake.h"
#include "food.h"

class snake;
struct food_elem;

class playground
{
public:
	int playg[8][8];

	playground();
	~playground();

	int* operator[](int x);
	void setPlayground(snake& sn, food_elem& feed);
	void outputFrameBuffer();
	void die();

	
};





#endif /* SRC_PLAYGROUND_H_ */
