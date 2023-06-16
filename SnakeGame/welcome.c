#include<stdio.h>
#include<sys/ioctl.h>
#include<time.h>

void welcome(char*username, struct winsize s)
{
	system("clear");
	gotoxy(s.ws_col/2, s.ws_row/2);
	printf("WELCOME %s TO THE SNAKE GAME!!\n", username);

	gotoxy(s.ws_col/2, s.ws_row/2+3);
	printf("Game controls:\n");
	gotoxy(s.ws_col/2, s.ws_row/2+4);
	printf("\"j\" -> move down\n");
	gotoxy(s.ws_col/2, s.ws_row/2+5);
	printf("\"k\" -> move up\n");
	gotoxy(s.ws_col/2, s.ws_row/2+6);
	printf("\"l\" -> move right\n");
	gotoxy(s.ws_col/2, s.ws_row/2+7);
	printf("\"h\" -> move left\n");

	gotoxy(s.ws_col/2, s.ws_row/2+10);
	printf("Press any key\n");
	getch();
}
