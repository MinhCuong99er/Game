#include<iostream>
#include<conio.h>
#include<windows.h>
#include<ctime>
using namespace std;
int boardGame[4][4]={0};
const string Logo =
". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n"
". . . 2 2 2 . . . . . 0 0 0 . . . . . . . . 4 4 . . . . 8 8 8 8 8 . . . . .\n"
". . 2 . . . 2 . . . 0 . . . 0 . . . . . . 4 . 4 . . . 8 . . . . . 8 . . . .\n"
". . . . . . 2 . . 0 . . . . . 0 . . . . 4 . . 4 . . . 8 . . . . . 8 . . . .\n"
". . . . . 2 . . . 0 . . . . . 0 . . . 4 . . . 4 . . . . 8 8 8 8 8 . . . . .\n"
". . . . 2 . . . . 0 . . . . . 0 . . 4 4 4 4 4 4 4 . . 8 . . . . . 8 . . . .\n"
". . . 2 . . . . . . 0 . . . 0 . . . . . . . . 4 . . . 8 . . . . . 8 . . . .\n"
". . 2 2 2 2 2 . . . . 0 0 0 . . . . . . . . . 4 . . . . 8 8 8 8 8 . . . . .\n"
". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n"
". . . . . . . . . . . . PRESS ANY KEY TO CONTINUE . . . . . . . . . . . . .\n";

const string Guide =
"\t\t\tGame instructions:\n\n"
"\t<!> Use the navigation buttons to move:\n\n"
"\t\t+ Up:    W or I\n\n"
"\t\t+ Down:  S or K\n\n"
"\t\t+ Right: D or L\n\n"
"\t\t+ Left:  A or J\n\n"
"\t<!> Press ESC to exit the game.\n\n"
"\t\t\tGood luck !!! (^_^)\n\n\n"
"\t\tPRESS ANY KEY TO CONTINUE";


void gotoxy(int x,int y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x,y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0, 0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
void drawTheFrame()
{
    for(int i=0;i<=16;i++)
    {
        for(int j=0;j<=32;j++)
        {
            gotoxy(j,i);
            if(i==0 && j==0)
                cout<<char(-55);
            else if(i==16 && j==0)
                cout<<char(-56);
            else if(i==0 && j==32)
                cout<<char(-69);
            else if(i==16 && j==32)
                cout<<char(-68);
            else if((i==4 || i==8 || i==12) && j==0)
                cout<<char(-52);
            else if((i==4 || i==8 || i==12) && j==32)
                cout<<char(-71);
            else if(i==0&&(j==8||j==16||j==24))
                cout<<char(-53);
            else if(i==16 && (j==8 || j==16 || j==24))
                cout<<char(-54);
            else if((i==4 || i==8 || i==12) && ( j==8 || j==16 || j==24))
                cout<<char(-50);
            else if(i==4 || i==8 || i==12)
                cout<<char(-51);
            else if(i==0 || i==16)
                cout<<char(-51);
            else if(j==8 || j==16 || j==24)
                cout<<char(-70);
            else if(j==0 || j==32)
                cout<<char(-70);
        }
    }
}
void begining()
{
    srand(time(NULL));
    int temp[4];
    temp[0]=rand()%4;
    temp[1]=rand()%4;

    do
    {
        temp[2]=rand()%4;
        temp[3]=rand()%4;
    }
    while (temp[0]==temp[2] && temp[1]==temp[3]);

    boardGame[temp[0]][temp[1]]=(rand()%2+1)*2;
    boardGame[temp[2]][temp[3]]=(rand()%2+1)*2;
}
void fillTheBoard()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if (boardGame[i][j] !=0)
            {
                gotoxy(4+j*8,2+i*4);
                cout<<boardGame[i][j];
            }
}

int main ()
{
    cout<<Logo;
    getch();
    clrscr();
    cout<<Guide;
    getch();
    clrscr();
    begining();
    drawTheFrame();
    fillTheBoard();
    gotoxy(20,20);
}
