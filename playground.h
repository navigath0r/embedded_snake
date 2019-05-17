#ifndef SRC_PLAYGROUND_H_
#define SRC_PLAYGROUND_H_

#include "snake.h"
#include "food.h"
#include "led_matrix.h"

class snake;
class food;

class playground
{
public:
	int playg[8][8];

	playground();
	~playground();

	int* operator[](int x);
	void setPlayground(snake& sn, food& feed);
	void outputFrameBuffer(led_matrix& lm);
	void die();

	
};





#endif /* SRC_PLAYGROUND_H_ */
