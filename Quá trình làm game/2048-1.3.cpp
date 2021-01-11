#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<windows.h>
#include<ctime>
#include<fstream>
using namespace std;

int boardGame[4][4]={0};
int count=0,scoreGame=0,bestScoreGame;
bool continueGame=true;
const string Logo =
". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n"
". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n"
". . . 2 2 2 . . . . . 0 0 0 . . . . . . . . 4 4 . . . . 8 8 8 8 8 . . .\n"
". . 2 . . . 2 . . . 0 . . . 0 . . . . . . 4 . 4 . . . 8 . . . . . 8 . .\n"
". . . . . . 2 . . 0 . . . . . 0 . . . . 4 . . 4 . . . 8 . . . . . 8 . .\n"
". . . . . 2 . . . 0 . . . . . 0 . . . 4 . . . 4 . . . . 8 8 8 8 8 . . .\n"
". . . . 2 . . . . 0 . . . . . 0 . . 4 4 4 4 4 4 4 . . 8 . . . . . 8 . .\n"
". . . 2 . . . . . . 0 . . . 0 . . . . . . . . 4 . . . 8 . . . . . 8 . .\n"
". . 2 2 2 2 2 . . . . 0 0 0 . . . . . . . . . 4 . . . . 8 8 8 8 8 . . .\n"
". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n"
". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n";

const string Guide =
"\t\t\tGame instructions:\n\n"
"\t<!> Use the navigation buttons to move:\n\n"
"\t\t+ Up:    W \n\n"
"\t\t+ Down:  S \n\n"
"\t\t+ Right: D \n\n"
"\t\t+ Left:  A \n\n"
"\t<!> Press ESC to exit the game.\n\n"
"\t\t\tGood luck !!! (^_^)\n\n\n"
"\t\tREADY!!! GO  --->>> ";

void gotoxy(int x,int y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x,y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
void clrscr()
{
    CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
    HANDLE  hConsoleOut;
    COORD   Home = { 0, 0 };
    DWORD   dummy;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
    FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
    csbiInfo.dwCursorPosition.X = 0;
    csbiInfo.dwCursorPosition.Y = 0;
    SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
void textColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void hideCursor()
{
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &ConCurInf);
}
void prepare ()
{
    cout<<Logo;
    getch();
    clrscr();
    textColor(2);
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
            if (i==0 || i==4 || i==8 || i==12 || i==16 || j==0 || j==8 || j==16 || j==24 || j==32)
            {
                textColor(3);
            }
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
int generateRandomNumber(int randomNumber)
{
    srand(time(NULL));
    randomNumber = rand() % 100 + 0;
    if (randomNumber%10==0) return 4;
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
void setColour(int colour)
{
    switch (colour)
    {
        case 2:     textColor(4); break;
        case 4:     textColor(5); break;
        case 8:     textColor(6); break;
        case 16:    textColor(7); break;
        case 32:    textColor(8); break;
        case 64:    textColor(9); break;
        case 128:   textColor(10); break;
        case 256:   textColor(11); break;
        case 512:   textColor(12); break;
        case 1024:  textColor(13); break;
        case 2048:  textColor(14); break;
        default:    textColor(15);
    }
}
void bestScore()
{
    fstream Game;
    Game.open("score.txt",ios::in);
    Game >> bestScoreGame;
    Game.close();

}
void fillTheBoard()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if (boardGame[i][j]!=0)
            {
                gotoxy(4+j*8,2+i*4);
                setColour(boardGame[i][j]);
                cout<<boardGame[i][j];
            }
        }
    }
    textColor(1);
    gotoxy(40,4);
    cout<<"Best score:";
    gotoxy(40,8);
    cout<<"Your score: ";
    textColor(2);
    cout<<scoreGame;
    gotoxy(52,4);
    cout<<bestScoreGame;
}
void turnLeft()
{
    for(int k=0;k<3;k++)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(boardGame[i][j]==0)
                {
                    boardGame[i][j]=boardGame[i][j+1];
                    boardGame[i][j+1]=0;
                    count++;
                }
            }
        }
    }
    for(int m=0;m<4;m++)
    {
        for(int n=0;n<3;n++)
        {
            if(boardGame[m][n] == boardGame[m][n+1])
            {
                boardGame[m][n]*=2;
                boardGame[m][n+1]=0;
                scoreGame += boardGame[m][n];
                count++;
            }
        }
    }
    for(int p=0;p<4;p++)
    {
        for(int q=0;q<3;q++)
        {
            if(boardGame[p][q]==0)
            {
                boardGame[p][q]=boardGame[p][q+1];
                boardGame[p][q+1]=0;
            }
        }
    }
    if(boardGame[0][3]*boardGame[1][3]*boardGame[2][3]*boardGame[3][3]==0 && count!=0)
    {
        int random,number;
        srand(time(NULL));
        do
        {
            random=rand()%4;
        }
        while (boardGame[random][3]!=0);
        boardGame[random][3]=generateRandomNumber(number);
    }
    count=0;
}
void turnRight()
{
    for(int k=0;k<3;k++)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=3;j>0;j--)
            {
                if(boardGame[i][j]==0)
                {
                    boardGame[i][j]=boardGame[i][j-1];
                    boardGame[i][j-1]=0;
                    count++;
                }
            }
        }
    }
    for(int m=0;m<4;m++)
    {
        for(int n=3;n>0;n--)
        {
            if(boardGame[m][n]==boardGame[m][n-1])
            {
                boardGame[m][n]*=2;
                boardGame[m][n-1]=0;
                scoreGame+=boardGame[m][n];
                count++;
            }
        }
    }
    for(int p=0;p<4;p++)
    {
        for(int q=3;q>0;q--)
        {
            if(boardGame[p][q]==0)
            {
                boardGame[p][q]=boardGame[p][q-1];
                boardGame[p][q-1]=0;
            }
        }
    }
    if(boardGame[0][0]*boardGame[1][0]*boardGame[2][0]*boardGame[3][0]==0 && count!=0)
    {
        int random,number;
        srand(time(NULL));
        do
        {
            random=rand()%4;
        }
        while (boardGame[random][0]!=0);
        boardGame[random][0]=generateRandomNumber(number);
    }
    count=0;
}
void goUp()
{
    for(int k=0;k<3;k++)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(boardGame[i][j]==0)
                {
                    boardGame[i][j]=boardGame[i+1][j];
                    boardGame[i+1][j]=0;
                    count++;
                }
            }
        }
    }
    for(int m=0;m<3;m++)
    {
        for(int n=0;n<4;n++)
        {
            if(boardGame[m][n]==boardGame[m+1][n])
            {
                boardGame[m][n]*=2;
                boardGame[m+1][n]=0;
                scoreGame+=boardGame[m][n];
                count++;
            }
        }
    }
    for(int p=0;p<3;p++)
    {
        for(int q=0;q<4;q++)
           {
            if(boardGame[p][q]==0)
            {
                boardGame[p][q]=boardGame[p+1][q];
                boardGame[p+1][q]=0;
            }
        }
    }
    if(boardGame[3][0]*boardGame[3][1]*boardGame[3][2]*boardGame[3][3]==0&&count!=0)
    {
        int random,number;
        srand(time(NULL));
        do
        {
            random=rand()%4;
        }
        while(boardGame[3][random]!=0);
        boardGame[3][random]=generateRandomNumber(number);
    }
    count=0;
}
void goDown()
{
    for(int k=0;k<3;k++)
    {
        for(int i=3;i>0;i--)
        {
            for(int j=0;j<4;j++)
            {
                if(boardGame[i][j]==0)
                {
                    boardGame[i][j]=boardGame[i-1][j];
                    boardGame[i-1][j]=0;
                    count++;
                }
            }
        }
    }
    for(int m=3;m>0;m--)
    {
        for(int n=0;n<4;n++)
        {
            if(boardGame[m][n]==boardGame[m-1][n])
            {
                boardGame[m][n]*=2;
                boardGame[m-1][n]=0;
                scoreGame+=boardGame[m][n];
                count++;
            }
        }
    }
    for(int p=3;p>0;p--)
    {
        for(int q=0;q<4;q++)
        {
            if(boardGame[p][q]==0)
            {
                boardGame[p][q]=boardGame[p-1][q];
                boardGame[p-1][q]=0;
            }
        }
    }
    if(boardGame[0][0]*boardGame[0][1]*boardGame[0][2]*boardGame[0][3]==0&&count!=0)
    {
        int random,number;
        srand(time(NULL));
        do
        {
            random=rand()%4;
        }
        while(boardGame[0][random]!=0);
        boardGame[0][random]=generateRandomNumber(number);
    }
    count=0;
}

int control()
{
    char keys=_getch();
    switch (keys)
    {
        case 72:
        {
            goUp();
            break;
        }
        case 80:
        {
            goDown();
            break;
        }
        case 75:
        {
            turnLeft();
            break;
        }
        case 77:
        {
            turnRight();
            break;
        }
        case 27:
        {
            continueGame = false;
            break;
        }
    }
}
bool testEmptyBoard()
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            if (boardGame[i][j] == 0) return true;
        }
    }
    return false;
}
bool testGameOver()
{
    if (!continueGame) return true;
    if (!testEmptyBoard() && continueGame)
    {
        for (int i=0;i<4;i++)
        {
            for (int j=0;j<4;j++)
            {
                if (boardGame[i][j] == boardGame[i][j + 1] || boardGame[i][j] == boardGame[i-1][j] || boardGame[i][j] == boardGame[i][j-1] ||
                    boardGame[i][j] == boardGame[i + 1][j]) return false;
            }
        }
        return true;
    }
    else return false;
}
void update()
{
    if (scoreGame>bestScoreGame  && !testGameOver())
    {
        bestScoreGame=scoreGame;
        ofstream  Game;
        Game.open("score.txt",ios::out);
        Game<<bestScoreGame;
        Game.close();
    }
}
void GameOver()
{
    ofstream  Game;
    Game.open("score.txt",ios::out);
    Game<<bestScoreGame;
    Game.close();
    textColor(3);
    gotoxy(0, 18);
    cout<<"GAME OVER";
}
int main ()
{
    hideCursor();
    bestScore();
    prepare();
    start();
    drawTheFrame();
    fillTheBoard();
    do{
        control();
        update();
        clrscr();
        drawTheFrame();
        fillTheBoard();
    }
    while (!testGameOver());
    GameOver();
}
