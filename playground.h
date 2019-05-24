#ifndef SRC_PLAYGROUND_H_
#define SRC_PLAYGROUND_H_

#include "snake.h"
#include "food.h"
#include "led_matrix.h"
#include "ADC.h"

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
	void drawTens(int number[8][4]);
	void drawOnes(int number[8][4]);
	void displayScore(int& score, led_matrix& lm);
	void die(snake& sn, food& fd, led_matrix lm, int& score);

};





#endif /* SRC_PLAYGROUND_H_ */
