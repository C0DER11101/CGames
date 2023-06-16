#include<stdio.h>
#include<unistd.h>
#include<stdbool.h>
#include<ctype.h>
#include<sys/ioctl.h>
#include<stdlib.h>
#include "snake.h"

extern int head, tail;
extern bool over;

void initSnake(snake*hissy, struct winsize size, int length)
{
	head=length-1;
	hissy[head].body='O';
	hissy[head].x=size.ws_col/2; // middle of the screen
	hissy[head].y=size.ws_row/2;
	int x=size.ws_col/2;

	for(int i=head-1; i>=tail; i--)
	{
		hissy[i].body='o';
		hissy[i].x=--x;
		hissy[i].y=hissy[head].y;
	}
}

void movement(snake*hissy, enum directions move, struct winsize size)
{
	if(move==up)
	{
		//shift the coordinates towards the left
		for(int i=tail; i<head; i++)
		{
			hissy[i]=hissy[i+1];
			hissy[i].body=tolower(hissy[i].body);
		}

		hissy[head].y--;

		if(hissy[head].y==1)
		{
			over=true;
			return;
		}

		for(int i=head-1; i>=tail; i--)
		{
			if(hissy[head].x==hissy[i].x && hissy[head].y==hissy[i].y)
			{
				over=true;
				return;
			}
		}
	}

	else if(move==down)
	{
		for(int i=tail; i<head; i++)
		{
			hissy[i]=hissy[i+1];
			hissy[i].body=tolower(hissy[i].body);
		}

		hissy[head].y++;

		if(hissy[head].y==size.ws_row-1)
		{
			over=true;
			return;
		}

		for(int i=head-1; i>=tail; i--)
		{
			if(hissy[head].x==hissy[i].x && hissy[head].y==hissy[i].y)
			{
				over=true;
				return;
			}
		}
	}

	else if(move==left)
	{
		for(int i=tail; i<head; i++)
		{
			hissy[i]=hissy[i+1];
			hissy[i].body=tolower(hissy[i].body);
		}
		
		hissy[head].x--;

		if(hissy[head].x==1)
		{
			over=true;
			return;
		}

		for(int i=head-1; i>=tail; i--)
		{
			if(hissy[head].x==hissy[i].x && hissy[head].y==hissy[i].y)
			{
				over=true;
				return;
			}
		}
	}

	else
	{
		for(int i=tail; i<head; i++)
		{
			hissy[i]=hissy[i+1];
			hissy[i].body=tolower(hissy[i].body);
		}

		hissy[head].x++;

		if(hissy[head].x==size.ws_col)
		{
			over=true;
			return;
		}

		for(int i=head-1; i>=tail; i--)
		{
			if(hissy[head].x==hissy[i].x && hissy[head].y==hissy[i].y)
			{
				over=true;
				return;
			}
		}
	}
}

void grow(snake*hissy, int*length)
{
	(*length)++;

	head=(*length)-1;

	for(int i=head; i>tail; i--)
		hissy[i]=hissy[i-1];
		

	int gx=1, gy=1;
	for(int i=head; i>tail; i--)
	{
		if(hissy[i].x!=hissy[i-1].x)
		{
			gx=0;
			break;
		}

		if(hissy[i].y!=hissy[i-1].y)
		{
			gy=0;
			break;
		}
	}

	if(gx==0)
	{
		hissy[tail].x=hissy[tail+1].x>hissy[tail+2].x ? hissy[tail+1].x+1:hissy[tail+1].x-1;
		hissy[tail].y=hissy[tail+1].y;
	}

	else if(gy==0)
	{
		hissy[tail].y=hissy[tail+1].y>hissy[tail+2].y ? hissy[tail+1].y+1:hissy[tail+1].y-1;
		hissy[tail].x=hissy[tail+1].x;
	}
}

void showSnake(snake*hissy)
{
	int i=head;
SNAKE:
	if(i<tail)
		goto end;

	gotoxy(hissy[i].x, hissy[i].y);
	printf("%c", hissy[i].body);
	i--;
	goto SNAKE;

end:
	return;
}
