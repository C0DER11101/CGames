#include<stdio.h>
#include<sys/ioctl.h>

void boundary(struct winsize size)
{
	gotoxy(1,1);
	printf("\u2554");

	for(int i=2; i<size.ws_col; i++)
	{
		gotoxy(i, 0);
		printf("\u2550");
	}

	printf("\u2557");

	//gotoxy(size.ws_col, 0);

	for(int i=1; i<size.ws_row-1; i++)
	{
		gotoxy(0, i+1);
		printf("\u2551");
		gotoxy(size.ws_col, i+1);
		printf("\u2551");
	}

	gotoxy(0, size.ws_row-1);
	printf("\u255a");

	for(int i=2; i<size.ws_col; i++)
	{
		gotoxy(i, size.ws_row-1);
		printf("\u2550");
	}

	printf("\u255d");


	printf("\n");

}
