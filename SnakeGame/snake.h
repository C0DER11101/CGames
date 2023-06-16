#ifndef __SNAKE__
#define __SNAKE__

enum directions{up, down, right, left};

typedef struct snake
{
	char body;
	int x, y;
}snake;

typedef struct foodPos
{
	int x, y;
}foodPos;

#endif
