#include<stdio.h>
#include<sys/ioctl.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>
#include "snake.h"

extern foodPos foodLocation;

extern int head, tail;

void Food(struct winsize size)
{
	srand(time(NULL));
	foodLocation.x=3+(rand()%(size.ws_col-9));
	foodLocation.y=3+(rand()%(size.ws_row-9));
}

bool foundFood(snake*hissy)
{
	if(hissy[head].x==foodLocation.x && hissy[head].y==foodLocation.y)
		return true;
	return false;
}

void showFood(int number)
{
	gotoxy(foodLocation.x, foodLocation.y);
	printf("%d", number);
}
