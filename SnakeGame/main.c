#include<stdio.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<Co.h>
#include "controls.h"

bool over=false;

int head=0, tail=0; // for the snake

foodPos foodLocation={-1, -1};

int main(void)
{
	struct winsize size;
	ioctl(0, TIOCGWINSZ, &size); // get the dimensions of the terminal!!
	char*password=malloc(100*sizeof(char)), *username=malloc(sizeof(char)*1000);
	int c, idx=0, score=0, lastScore;

	FILE*userDet=NULL, *retScore=NULL;

	userDet=fopen("UserDetails.txt", "r");

	if(userDet==NULL)
	{
		printf("New user!!\n");
		printf("Enter your username(no space): ");
		scanf("%[^\n]%*c", username);
		printf("Type password carefully, no backspace allowed!\n");
		sleep(1);
		system("clear");
		printf("Password: ");

		while((c=getch())!='\n') // silent input from the user!!
		{
			printf("Password: ");
			password[idx++]=c;
			system("clear");
		}
		userDet=fopen("UserDetails.txt", "w");
		if(userDet==NULL)
		{
			printf("\nFile error!\n");
			free(username);
			free(password);
			return 0;
		}

		else
		{
			fprintf(userDet, "%s %s", username, password);
			fclose(userDet);
		}

		welcome(username, size);
		retScore=fopen("Score.txt", "w");
		fclose(retScore);
	}

	else
	{
		char*match=malloc(sizeof(char)*100);
		system("clear");
		printf("Login password: ");

		while(tolower(c=getch())!='\n')
		{
			printf("Login password: ");
			match[idx++]=c;
			system("clear");
		}

		fscanf(userDet, "%s %s", username, password);

		if(strcmp(password, match)==0)
		{
			welcome(username, size);
		}

		else
		{
			gotoxy(size.ws_col/2, size.ws_row/2);
			printf("\e[33mLOGIN FAILED!!\n");
			free(username);
			free(password);
			free(match);
			return 0;
		}

		fclose(userDet);

		retScore=fopen("Score.txt", "r");
		if(retScore==NULL)
		{
			printf("\nFile error!\n");
			free(username);
			free(password);
			free(match);
			return 0;
		}

		else
		{
			fscanf(retScore, "%d", &lastScore);
		}

		fclose(retScore);

		free(match);
	}


	srand(time(NULL));
	int num=1+(rand()%10);
	int length=5; // initial length of the snake
	system("clear");
	int move;
	snake hissy[100]; // snake Hissy's initial length!
	load(size); // loading...
	boundary(size);
	initSnake(hissy, size, length);
	Food(size);
	showFood(num);
	showSnake(hissy);

	while(tolower(move)!='e')
	{
		if(kbhit())
		{
			move=getch(); // get the input directly from the console and not from the buffer

			switch(tolower(move))
			{
				case 'j': // move down
					movement(hissy, down, size);
					break;

				case 'k': // move up
					movement(hissy, up, size);
					break;

				case 'l': // move right
					movement(hissy, right, size);
					break;

				case 'h': // move left
					movement(hissy, left, size);
					break;

				default:
					continue;

			}
		}

		else
			continue;
		
		if(over==true)
		{
			system("clear");
			gotoxy(size.ws_col/2, size.ws_row/2);
			printf("GAME OVER!\n");
			break;
		}

		system("clear");
		if(foundFood(hissy))
		{
			grow(hissy, &length);
			score+=num;
			Food(size);
			num=1+(rand()%10);
		}
		boundary(size);
		gotoxy(3, size.ws_row+2);
		printf("Current Score: %d", score);
		gotoxy(size.ws_col-30, size.ws_row+2);
		printf("Last Score: %d", lastScore);
		showFood(num);
		showSnake(hissy);

	}


	free(password);
	free(username);

	if(score>lastScore)
	{
		sleep(2);
		system("clear");
		gotoxy(size.ws_col/2, size.ws_row/2);
		printf("Best Score: %d\n", score);
		retScore=fopen("Score.txt", "w");
		if(retScore==NULL)
		{
			printf("\nFile error!\n");
			return 0;
		}
		
		else
		{
			fprintf(retScore, "%d", score);
		}

		fclose(retScore);
	}

	else
	{
		sleep(2);
		system("clear");
		gotoxy(size.ws_col/2, size.ws_row/2);
		printf("Best score is still: %d\n", lastScore);
		retScore=fopen("Score.txt", "w");
		if(retScore==NULL)
		{
			printf("\nFile error!\n");
			return 0;
		}
		
		else
		{
			fprintf(retScore, "%d", lastScore);
		}

		fclose(retScore);
	}

	return 0;
}
