#include<iostream>
#include<conio.h>
#include<windows.h>
#include<ctime>
using namespace std;

int boardGame[4][4]={0};
int count=0,scoreGame=0;
bool continueGame=true;

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
void prepare ()
{
    cout<<Logo;
    getch();
    clrscr();
    cout<<Guide;
    getch();
    clrscr();
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
int generateRandomNumber()
{
    int k = rand() % 100 + 1;
    if (k%8==0) return 4;
    else return 2;
}
void start()
{
    int temp[4];
    srand(time(NULL));
    temp[0] = rand()%4;
    temp[1] = rand()%4;

    do
    {
        temp[2] = rand()%4;
        temp[3] = rand()%4;
    }
    while (temp[0]==temp[2] && temp[1]==temp[3]);

    boardGame[temp[0]][temp[1]] = (rand()%2+1)*2;
    boardGame[temp[2]][temp[3]] = (rand()%2+1)*2;
}
void fillTheBoard()
{
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if (boardGame[i][j]!=0)
            {
                gotoxy(4+j*8,2+i*4);
                cout<<boardGame[i][j];
            }
        }
    }
}
void turnLeft()
{
    for(int q=0;q<3;q++)
    {
        for(int i=0;i<4;i++)
            for(int j=0;j<3;j++)
                if(boardGame[i][j]==0)
                {
                    count++;
                    boardGame[i][j]=boardGame[i][j+1];
                    boardGame[i][j+1]=0;
                }
    }
    for(int w=0;w<4;w++)
        for(int e=0;e<3;e++)
            if(boardGame[w][e] == boardGame[w][e+1])
            {
                count++;
                boardGame[w][e]=boardGame[w][e]+boardGame[w][e+1];
                boardGame[w][e+1]=0;
                if(boardGame[w][e]==2048) continueGame=false;
                scoreGame += boardGame[w][e];
            }
    for(int r=0;r<4;r++)
        for(int t=0;t<3;t++)
        if(boardGame[r][t]==0)
        {
            boardGame[r][t]=boardGame[r][t+1];
            boardGame[r][t+1]=0;
        }
    if(boardGame[0][3]*boardGame[1][3]*boardGame[2][3]*boardGame[3][3]==0 && count!=0)
    {
        int tmp;
        srand(time(NULL));
        do
        {
            tmp=rand()%4;
        }
        while (boardGame[tmp][3]!=0);
        boardGame[tmp][3]=generateRandomNumber();
        clrscr();
        drawTheFrame();
        fillTheBoard();
    }
    count=0;
}
void turnRight()
{
    for(int q=0;q<3;q++)
    {
        for(int i=0;i<4;i++)
            for(int j=3;j>0;j--)
                if(boardGame[i][j]==0)
                {
                    count++;
                    boardGame[i][j]=boardGame[i][j-1];
                    boardGame[i][j-1]=0;
                }
    }
    for(int w=0;w<4;w++)
        for(int e=3;e>0;e--)
            if(boardGame[w][e]==boardGame[w][e-1])
            {
                count++;
                boardGame[w][e]=boardGame[w][e]+boardGame[w][e-1];
                boardGame[w][e-1]=0;
                if(boardGame[w][e]==2048) continueGame=false;
                scoreGame+=boardGame[w][e];
            }
    for(int r=0;r<4;r++)
        for(int t=3;t>0;t--)
        if(boardGame[r][t]==0)
        {
            boardGame[r][t]=boardGame[r][t-1];
            boardGame[r][t-1]=0;
        }
    if(boardGame[0][0]*boardGame[1][0]*boardGame[2][0]*boardGame[3][0]==0 && count!=0)
    {
        int tmp;
        srand(time(NULL));
        do
        {
            tmp=rand()%4;
        }
        while (boardGame[tmp][0]!=0);
        boardGame[tmp][0]=generateRandomNumber();
        clrscr();
        drawTheFrame();
        fillTheBoard();
    }
    count=0;
}
void goUp()
{
    for(int q=0;q<3;q++)
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<4;j++)
                if(boardGame[i][j]==0)
                {
                    count++;
                    boardGame[i][j]=boardGame[i+1][j];
                    boardGame[i+1][j]=0;
                }
    }
    for(int w=0;w<3;w++)
        for(int e=0;e<4;e++)
            if(boardGame[w][e]==boardGame[w+1][e])
            {
                count++;
                boardGame[w][e]=boardGame[w][e]+boardGame[w+1][e];
                boardGame[w+1][e]=0;
                if(boardGame[w][e]==2048) continueGame=false;
                scoreGame+=boardGame[w][e];
            }
    for(int r=0;r<3;r++)
        for(int t=0;t<4;t++)
        if(boardGame[r][t]==0)
        {
            boardGame[r][t]=boardGame[r+1][t];
            boardGame[r+1][t]=0;
        }
    if(boardGame[3][0]*boardGame[3][1]*boardGame[3][2]*boardGame[3][3]==0&&count!=0)
    {
        int tmp;
        srand(time(NULL));
        do
        {
            tmp=rand()%4;
        }
        while(boardGame[3][tmp]!=0);
        boardGame[3][tmp]=generateRandomNumber();
        clrscr();
        drawTheFrame();
        fillTheBoard();
    }
    count=0;
}
void goDown()
{
    for(int q=0;q<3;q++)
    {
        for(int i=3;i>0;i--)
            for(int j=0;j<4;j++)
                if(boardGame[i][j]==0)
                {
                    count++;
                    boardGame[i][j]=boardGame[i-1][j];
                    boardGame[i-1][j]=0;
                }
    }
    for(int w=3;w>0;w--)
        for(int e=0;e<4;e++)
            if(boardGame[w][e]==boardGame[w-1][e])
            {
                count++;
                boardGame[w][e]=boardGame[w][e]+boardGame[w-1][e];
                boardGame[w-1][e]=0;
                if(boardGame[w][e]==2048) continueGame=false;
                scoreGame+=boardGame[w][e];
            }
    for(int r=3;r>0;r--)
        for(int t=0;t<4;t++)
        if(boardGame[r][t]==0)
        {
            boardGame[r][t]=boardGame[r-1][t];
            boardGame[r-1][t]=0;
        }
    if(boardGame[0][0]*boardGame[0][1]*boardGame[0][2]*boardGame[0][3]==0&&count!=0)
    {
        int tmp;
        srand(time(NULL));
        do
        {
            tmp=rand()%4;
        }
        while(boardGame[0][tmp]!=0);
        boardGame[0][tmp]=generateRandomNumber();
        clrscr();
        drawTheFrame();
        fillTheBoard();
    }
    count=0;
}
int theJoystick()
{
    char key=_getch();
    if(key=='w') goUp();
    if(key=='s') goDown();
    if(key=='d') turnRight();
    if(key=='a') turnLeft();
}
int main ()
{
    prepare();
    start();
    drawTheFrame();
    fillTheBoard();
    do{
        theJoystick();
        clrscr();
        drawTheFrame();
        fillTheBoard();
    } while (continueGame==true);
}

