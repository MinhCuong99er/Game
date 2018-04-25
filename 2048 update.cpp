#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<windows.h>
#include<ctime>
#include<fstream>

#define BoardLength 24
#define BoardWidth 16

using namespace std;

const string Logo =
    "\n\n\n\n\n                                                         \n"
    "\t\t  2 2 2           0 0 0                 4 4         8 8 8 8 8  \n"
    "\t\t2       2       0       0             4   4       8           8\n"
    "\t\t        2     0           0         4     4       8           8\n"
    "\t\t      2       0           0       4       4         8 8 8 8 8  \n"
    "\t\t    2         0           0     4 4 4 4 4 4 4     8           8\n"
    "\t\t  2             0       0                 4       8           8\n"
    "\t\t2 2 2 2 2         0 0 0                   4         8 8 8 8 8  \n";
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
const string BoardHand=
    "  +----------------------------------+   \n"
    "\t\t\t\t      |                                  |      \n"
    "\t\t\t\t      |        Best Score:               |      \n"
    "\t\t\t\t      |                                  |      \n"
    "\t\t\t\t    _ |        Your Score:               | _    \n"
    "\t\t\t\t   (o)|                                  |(o)   \n"
    "\t\t\t\t  ( { |                                  | } )  \n"
    "\t\t\t\t ( (_ |                                  | _) ) \n"
    "\t\t\t\t((# {)+----------------------------------+(} #))\n"
    "\t\t\t\t(### {_} }                            { {_} ###)\n"
    "\t\t\t\t {      }                              {      } \n"
    "\t\t\t\t  {____}                                {____}  \n"
    "\t\t\t\t  |    |                                |    |  \n"
    "\t\t\t\t  |    |                                |    |  \n"
    "\t\t\t\t  |    |                                |    |  \n"
    "\t\t\t\t  |    |                                |    |  \n"
    "\t\t\t\t  |    |                                |    |  \n"
    "\t\t\t\t  (____)                                (____)  \n";
const string Face =
    "                          \n"
    "       xxxxxxxxxxxx       \n"
    "      xxxxxxxxxxxxxx      \n"
    "     xxxxxxxxxxxxxxxx     \n"
    "     xxxxxxxxxxxxxxxx     \n"
    "    xxxxxxxxxxxxxxxxxx    \n"
    "    xxxxxxxxxxxxxxxxxx    \n"
    "   xxxxxTTTxxxxTTTxxxxx   \n"
    "     xxx   xxxx   xxx     \n"
    "     xxx   xxxx   xxx     \n"
    "      xx___xxxx___xx      \n"
    "      xxxxxxxxxxxxxx      \n"
    "       xxxxx  xxxxx       \n"
    "        xxxxxxxxxx        \n"
    "        xxxxxxxxxx        \n"
    "         x      x         \n"
    "         xx    xx         \n"
    "          xxxxxx          \n"
    "            xx            \n"
    "                          \n"
    "        YOU LOSED!        \n";

void gotoxy(int x,int y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x,y};
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
void setText(string text)
{
    while(1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , rand() % 15);
        cout<<text;
        if(kbhit())
        {
            getch();
            break;
        }
        Sleep(250);
        clrscr();
    }
}

void prepare ()
{
    setText(Logo);
    clrscr();
    setText(Guide);
    clrscr();
}
void setColour(int &colour)
{
    switch (colour)
    {

        case 2:     textColor(15); break;
        case 4:     textColor(14); break;
        case 8:     textColor(13); break;
        case 16:    textColor(12); break;
        case 32:    textColor(11); break;
        case 64:    textColor(10); break;
        case 128:   textColor(9);  break;
        case 256:   textColor(8);  break;
        case 512:   textColor(7);  break;
        case 1024:  textColor(6);  break;
        case 2048:  textColor(5);  break;
        default:    textColor(4);
    }
}
void drawTheFrame()
{
    gotoxy(36,0);
    textColor(3);
    cout<<BoardHand;
    textColor(2);

    for(int i=0;i<=BoardWidth;i++)
    {
        for(int j=0;j<=BoardLength;j++)
        {
        	gotoxy(j,i);
            if(i==0 && j==0)
                cout<<char(-55);
            else if(i==16 && j==0)
                cout<<char(-56);
            else if(i==0 && j==24)
                cout<<char(-69);
            else if(i==16 && j==24)
                cout<<char(-68);
            else if((i==4 || i==8 || i==12) && j==0)
                cout<<char(-52);
            else if((i==4 || i==8 || i==12) && j==24)
                cout<<char(-71);
            else if(i==0 && (j==6 || j==12 || j==18))
                cout<<char(-53);
            else if(i==16 && (j==6 || j==12 || j==18))
                cout<<char(-54);
            else if((i==4 || i==8 || i==12) && (j==6||j==12||j==18))
                cout<<char(-50);
            else if(i==0 || i==4 || i==8 || i==12 || i==16)
                cout<<char(-51);
            else if(j==0 || j==6 || j==12 || j==18 || j==24)
                cout<<char(-70);
        }
    }
}
void fillTheBoard(int matrix[4][4], int &score, int &bestScore)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            setColour(matrix[i][j]);
            if (matrix[i][j]<100 && matrix[i][j]!=0)
            {
                gotoxy(3+j*6,2+i*4);
                cout<<matrix[i][j];
            }
            else if ((matrix[i][j]>100 && matrix[i][j]!=0))
            {
                gotoxy(2+j*6,2+i*4);
                cout<<matrix[i][j];
            }
        }
    }
    textColor(1);
    gotoxy(59,4);
    cout<<score;
    textColor(4);
    gotoxy(59,2);
    cout<<bestScore;
}
int generateRandomNumber(int &randomNumber)
{
    srand(time(NULL));
    randomNumber = rand() % 100;
    if (randomNumber%10==0) return 4;
    else return 2;
}
void start(int temp[4],int matrix[4][4])
{
    drawTheFrame();
    srand(time(NULL));
    temp[0] = rand()%4;
    temp[1] = rand()%4;
    do
    {
        temp[2] = rand()%4;
        temp[3] = rand()%4;
    }
    while (temp[0]==temp[2] && temp[1]==temp[3]);

    matrix[temp[0]][temp[1]] = 2;
    matrix[temp[2]][temp[3]] = 2;
}
void bestScore(int &bestScore)
{
    fstream Game;
    Game.open("score.txt",ios::in);
    Game >> bestScore;
    Game.close();
}
void turnLeft(int matrix[4][4],int &score,int &bestScore,int &count,int &status)
{
    for(int k=0;k<3;k++)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][j]=matrix[i][j+1];
                    matrix[i][j+1]=0;
                    count++;
                }
            }
        }
    }
    for(int m=0;m<4;m++)
    {
        for(int n=0;n<3;n++)
        {
            if(matrix[m][n] == 2048)
            {
                status = 0;
                break;
            }
            else if(matrix[m][n] == matrix[m][n+1])
            {
                matrix[m][n]*=2;
                matrix[m][n+1]=0;
                score += matrix[m][n];
                count++;
            }
        }
    }
    for(int p=0;p<4;p++)
    {
        for(int q=0;q<3;q++)
        {
            if(matrix[p][q]==0)
            {
                matrix[p][q]=matrix[p][q+1];
                matrix[p][q+1]=0;
            }
        }
    }
    if(matrix[0][3]*matrix[1][3]*matrix[2][3]*matrix[3][3]==0 && count!=0)
    {
        int random,number;
        srand(time(NULL));
        do
        {
            random=rand()%4;
        }
        while (matrix[random][3]!=0);
        matrix[random][3]=generateRandomNumber(number);
    }
    count=0;
}
void turnRight(int matrix[4][4],int &score,int &bestScore,int &count,int &status)
{
    for(int k=0;k<3;k++)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=3;j>0;j--)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][j] = matrix[i][j-1];
                    matrix[i][j-1] = 0;
                    count++;
                }
            }
        }
    }
    for(int m=0;m<4;m++)
    {
        for(int n=3;n>0;n--)
        {
            if(matrix[m][n] == 2048)
            {
                status = 0;
                break;
            }
            else if(matrix[m][n] == matrix[m][n-1])
            {
                matrix[m][n] *= 2;
                matrix[m][n-1] = 0;
                score += matrix[m][n];
                count++;
            }
        }
    }
    for(int p=0;p<4;p++)
    {
        for(int q=3;q>0;q--)
        {
            if(matrix[p][q]==0)
            {
                matrix[p][q] = matrix[p][q-1];
                matrix[p][q-1] = 0;
            }
        }
    }
    if(matrix[0][0]*matrix[1][0]*matrix[2][0]*matrix[3][0]==0 && count!=0)
    {
        int random,number;
        srand(time(NULL));
        do
        {
            random=rand()%4;
        }
        while (matrix[random][0]!=0);
        matrix[random][0]=generateRandomNumber(number);
    }
    count=0;
}
void goUp(int matrix[4][4],int &score,int &bestScore,int &count,int &status)
{
    for(int k=0;k<3;k++)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][j] = matrix[i+1][j];
                    matrix[i+1][j] = 0;
                    count++;
                }
            }
        }
    }
    for(int m=0;m<3;m++)
    {
        for(int n=0;n<4;n++)
        {
            if(matrix[m][n] == 2048)
            {
                status = 0;
                break;
            }
            else if(matrix[m][n]==matrix[m+1][n])
            {
                matrix[m][n]*=2;
                matrix[m+1][n] = 0;
                score += matrix[m][n];
                count++;
            }
        }
    }
    for(int p=0;p<3;p++)
    {
        for(int q=0;q<4;q++)
           {
            if(matrix[p][q]==0)
            {
                matrix[p][q]=matrix[p+1][q];
                matrix[p+1][q]=0;
            }
        }
    }
    if(matrix[3][0]*matrix[3][1]*matrix[3][2]*matrix[3][3]==0&&count!=0)
    {
        int random,number;
        srand(time(NULL));
        do
        {
            random=rand()%4;
        }
        while(matrix[3][random] != 0);
        matrix[3][random] = generateRandomNumber(number);
    }
    count=0;
}
void goDown(int matrix[4][4],int &score,int &bestScore,int &count,int &status)
{
    for(int k=0;k<3;k++)
    {
        for(int i=3;i>0;i--)
        {
            for(int j=0;j<4;j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][j]=matrix[i-1][j];
                    matrix[i-1][j]=0;
                    count++;
                }
            }
        }
    }
    for(int m=3;m>0;m--)
    {
        for(int n=0;n<4;n++)
        {
            if(matrix[m][n] == 2048)
            {
                status = 0;
                break;
            }
            else if(matrix[m][n] == matrix[m-1][n])
            {
                matrix[m][n] *= 2;
                matrix[m-1][n] = 0;
                score += matrix[m][n];
                count++;
            }
        }
    }
    for(int p=3;p>0;p--)
    {
        for(int q=0;q<4;q++)
        {
            if(matrix[p][q]==0)
            {
                matrix[p][q]=matrix[p-1][q];
                matrix[p-1][q]=0;
            }
        }
    }
    if(matrix[0][0]*matrix[0][1]*matrix[0][2]*matrix[0][3]==0 && count!=0)
    {
        int random,number;
        srand(time(NULL));
        do
        {
            random=rand()%4;
        }
        while(matrix[0][random]!=0);
        matrix[0][random]=generateRandomNumber(number);
    }
    count=0;
}

void control(int matrix[4][4],int &score,int &bestScore,int &count,int &status)
{
    char keys = _getch();
    switch (keys)
    {
        case 'w': case 72:
        {
            goUp(matrix,score,bestScore,count,status);
            break;
        }
        case 's': case 80:
        {
            goDown(matrix,score,bestScore,count,status);
            break;
        }
        case 'a': case 75:
        {
            turnLeft(matrix,score,bestScore,count,status);
            break;
        }
        case 'd': case 77:
        {
            turnRight(matrix,score,bestScore,count,status);
            break;
        }
        case 27:
        {
            status = 2;
            break;
        }
    }
}
bool EmptyBoard(int matrix[4][4])
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            if (matrix[i][j]==0) return true;
        }
    }
    return false;
}
bool gameOver(int matrix[4][4],int &status, bool condition)
{
    if (status == 0 || status == 2) return true;
    for (int i=0; i<3; i++)
    {
		for (int j=0; j<3; j++)
		{
			if (matrix[i][j]==matrix[i][j+1] || matrix[i][j]==matrix[i+1][j])
				condition = true;
		}
	}
	if (!EmptyBoard(matrix) && !condition) return true;
	else return false;
}
void update(int matrix[4][4], int &score,int &bestScore,int &status,bool condition)
{
    if (score>bestScore  && !gameOver(matrix,status,condition))
    {
        bestScore=score;
        ofstream  Game;
        Game.open("score.txt",ios::out);
        Game<<bestScore;
        Game.close();
    }
}
void losed(int &bestScore)
{
    ofstream  Game;
    Game.open("score.txt",ios::out);
    Game<<bestScore;
    Game.close();
    gotoxy(47,6);
    cout<<"GAME OVER!!!";
    Sleep(2000);
    clrscr();
    gotoxy(0,20);
    setText(Face);

}
void victory ()
{
    setText("\n\n\n\n\n\t\tCONGRALULATIONS. YOU WIN!!!");
}

int main ()
{
    int matrixGame[4][4]={0},temp[4];
 	int count=0,scoreGame=0,bestScoreGame,statusOfGame=1;
    bool stopCondition;

    hideCursor();
    prepare();
    bestScore(bestScoreGame);
    start(temp,matrixGame);
    fillTheBoard(matrixGame,scoreGame,bestScoreGame);
    do{
        control(matrixGame,scoreGame,bestScoreGame,count,statusOfGame);
        update(matrixGame,scoreGame,bestScoreGame,statusOfGame,stopCondition);
        drawTheFrame();
        fillTheBoard(matrixGame,scoreGame,bestScoreGame);
    }
    while (!gameOver(matrixGame,statusOfGame,stopCondition));

    if (statusOfGame==0)
        victory();
    else if (statusOfGame==2 || gameOver(matrixGame,statusOfGame,stopCondition))
        losed(bestScoreGame);
    getch();
    return 0;
}

