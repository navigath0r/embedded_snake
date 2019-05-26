#include "food.h"
#include <cstdlib>

food::food(playground& pg)
{
	food::generateFood(pg);
}

food::~food(){}

food::food_elem food::getFoodCoord()
{
	return kaja;
}

int food::getFoodRow()
{
	return kaja.row;
}

int food::getFoodColumn()
{
	return kaja.column;
}

int food::getTTLSuperfood()
{
	return TTL_superfood;
}

int food::getFoodsToSuperfood()
{
	return foods_to_superfood;
}

int food::getSuperFood()
{
	return kaja.superfood;
}


int food::generateFood(playground& pg)
{
	kaja.row = rand() % 8;
	kaja.column = rand() % 8;
	kaja.superfood = 0;

	if (pg[kaja.row][kaja.column] == 1 || pg[kaja.row][kaja.column] == 2)
	{
		food::generateFood(pg);
	}
	else
	{
		pg[kaja.row][kaja.column] = kaja.superfood + 1;
	}



	if (foods_to_superfood == 0)
	{
		kaja.superfood = 1;
		TTL_superfood = 12;
		foods_to_superfood = rand() % 5 + 5;
	}
	else kaja.superfood = 0;

	return kaja.superfood;
}
