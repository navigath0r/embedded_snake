#ifndef SRC_PLAYGROUND_H_
#define SRC_PLAYGROUND_H_

#include "snake.h"
#include "food.h"

class playground
{
public:
	int playg[8][8];

	playground();
	~playground();

	int** getPlayground();
	void setPlayground(const struct snake_element& head, const struct food_elem& feed);
	void outputFrameBuffer();

	
};





#endif /* SRC_PLAYGROUND_H_ */
