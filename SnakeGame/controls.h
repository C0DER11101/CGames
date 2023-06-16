#ifndef __CTRL__
#define __CTRL__

#include "snake.h"
#include<sys/ioctl.h>
#include<stdbool.h>

/* welcome the user */
void welcome(char*, struct winsize);

/* snake controls */
void initSnake(snake*, struct winsize, int); // called once
void grow(snake*, int*); // the snake and the length of the snake
void movement(snake*, enum directions, struct winsize);
void showSnake(snake*);

/* function for displaying boundaries */
void boundary(struct winsize);

/* food */
void Food(struct winsize);
void showFood(int);
bool foundFood(snake*);

/* loading */
void load(struct winsize);


#endif
