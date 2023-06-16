#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ioctl.h>
#include<time.h>
#include<unistd.h>

void load(struct winsize size)
{
	srand(time(NULL));

	char Load[10];

	for(int i=0; i<10; i++)
	{
		gotoxy(size.ws_col/2-15, size.ws_row/2);
		printf("Loading:\n");
		gotoxy((size.ws_col/2)-5, size.ws_row/2);
		printf("|\n");
		gotoxy((size.ws_col/2)+6, size.ws_row/2);
		printf("|\n");
		gotoxy(size.ws_col/2-4, size.ws_row/2);
		strcat(Load, "=");
		printf("%s\n", Load);
		sleep(0+(rand()%3));
		system("clear");
	}
}
