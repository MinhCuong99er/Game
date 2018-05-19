#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<windows.h>
#include<ctime>
#include<fstream>

#define BoardLength 24       // Chieu dai bang
#define BoardWidth 16       // Chieu rong bang
#define ConsoleLength 85   // Chieu dai man hinh console
#define ConsoleWidth 45   // Chieu rong man hinh console

using namespace std;

const string Logo =
    "\n\n\n\n\n\n\n\n\n\n\n\n                                           \n"
    "\t\t  2 2 2           0 0 0                 4 4         8 8 8 8 8  \n"
    "\t\t2       2       0       0             4   4       8           8\n"
    "\t\t        2     0           0         4     4       8           8\n"
    "\t\t      2       0           0       4       4         8 8 8 8 8  \n"
    "\t\t    2         0           0     4 4 4 4 4 4 4     8           8\n"
    "\t\t  2             0       0                 4       8           8\n"
    "\t\t2 2 2 2 2         0 0 0                   4         8 8 8 8 8  \n";
const string Guide =
    "\n\n\n\n\n\n\n\n\n                       \n\n"
    "\t\t\t\tGame instructions:                 \n\n"
    "\t\t<!> Use the navigation buttons to move:\n\n"
    "\t\t\t+ Up:    W                           \n\n"
    "\t\t\t+ Down:  S                           \n\n"
    "\t\t\t+ Right: D                           \n\n"
    "\t\t\t+ Left:  A                           \n\n"
    "\t\t<!> Press ESC to exit the game.        \n\n"
    "\t\t<!> Press R to restart the game.        \n\n"
    "\t\t\t\tGood luck !!! (^_^)\n              \n\n"
    "\t\t\tREADY!!! GO  --->>> ";
const string BoardHand=
    "\t\t      +-------------------------------------+   \n"
    "\t\t      |                                     |      \n"
    "\t\t      |        Best Score:                  |      \n"
    "\t\t      |                                     |      \n"
    "\t\t    _ |        Your Score:                  | _    \n"
    "\t\t   (o)|                                     |(o)   \n"
    "\t\t  ( { |                                     | } )  \n"
    "\t\t ( (_ |                                     | _) ) \n"
    "\t\t((# {)+-------------------------------------+(} #))\n"
    "\t\t(### {_} }                               { {_} ###)\n"
    "\t\t {      }                                 {      } \n"
    "\t\t  {____}                                   {____}  \n"
    "\t\t  |    |                                   |    |  \n"
    "\t\t  |    |                                   |    |  \n"
    "\t\t  |    |                                   |    |  \n"
    "\t\t  |    |                                   |    |  \n"
    "\t\t  |    |                                   |    |  \n"
    "\t\t  (____)                                   (____)  \n";
const string Board =
    "\n\n\n\n\n\n\n\n\n\n                             \n"
    "\t\t      +-------------------------------------+\n"
    "\t\t      |                                     |\n"
    "\t\t      |          YOU LOSE !!!               |\n"
    "\t\t      |                                     |\n"
    "\t\t      |     Your Score is :                 |\n"
    "\t\t      |                                     |\n"
    "\t\t      +-------------------------------------+\n";

void gotoxy(short x,short y)
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
void textColor(int color)                   // Ham to mau chu
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
void setText(string text)                                   // Ham tao mau cho 1 chuoi ky tu
{
    while(1)
    {
        textColor(rand() % 15);
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
void prepare ()                                             // Ham in Logo va huong dan
{
    setText(Logo);
    clrscr();
    setText(Guide);
    clrscr();
}
void setColour(int &colour)                                 // Ham cai dat mau cho so
{
    switch (colour)
    {
        case 2:     textColor(62);  break;
        case 4:     textColor(61);  break;
        case 8:     textColor(60);  break;
        case 16:    textColor(59);  break;
        case 32:    textColor(58);  break;
        case 64:    textColor(57);  break;
        case 128:   textColor(56);  break;
        case 256:   textColor(55);  break;
        case 512:   textColor(54);  break;
        case 1024:  textColor(53);  break;
        case 2048:  textColor(52);  break;
        default:    textColor(51);
    }
}
void draw()                                                 // Ham ve khung
{
    gotoxy(0,0);
    for(int line=0;line<=BoardWidth;line++)
    {
    	for(int column=0;column<=BoardLength;column++)
        {
            gotoxy(column+29,line+2);
            if(line==0 && column==0)
            {
                textColor(15);
                cout<<char(-55);
            }
            else if(line==16 && column==0)
            {
                textColor(15);
                cout<<char(-56);
            }
            else if(line==0 && column==24)
            {
                textColor(15);
                cout<<char(-69);
            }
            else if(line==16 && column==24)
            {
                textColor(15);
                cout<<char(-68);
            }
            else if(line%4==0 && column==0)
            {
                textColor(15);
                cout<<char(-52);
            }
            else if(line%4==0 && column==24)
            {
                textColor(15);
                cout<<char(-71);
            }
            else if(line==0 && column%6==0)
            {
                textColor(15);
                cout<<char(-53);
            }
            else if(line==16 && column%6==0)
            {
                textColor(15);
                cout<<char(-54);
            }
            else if(line%4==0 && column%6==0)
            {
                textColor(15);
                cout<<char(-50);
            }
            else if(line%4==0)
            {
                textColor(15);
                cout<<char(-51);
            }
            else if(column%6==0)
            {
                textColor(15);
                cout<<char(-70);
            }
            else if (line%4!=0 && column%6!=0)
            {
                textColor(51);
                cout<<char(219);
            }
        }
    }
    gotoxy(0,20);
    textColor(14);
    cout<<BoardHand;
}
void display(int matrix[4][4], int &score, int &bestScore)  // Ham dien so
{
    for(int line=0;line<4;line++)
    {
        for(int column=0;column<4;column++)
        {
            setColour(matrix[line][column]);
            if (matrix[line][column]<100 && matrix[line][column]!=0)
            {
                gotoxy(32+column*6,4+line*4);
                cout<<matrix[line][column];
            }
            else if ((matrix[line][column]>100 && matrix[line][column]!=0))
            {
                gotoxy(31+column*6,4+line*4);
                cout<<matrix[line][column];
            }
        }
    }
    gotoxy(43,24);
    textColor(15);
    cout<<score;
    textColor(12);
    gotoxy(43,22);
    cout<<bestScore;
}
void start(int temp[4],int matrix[4][4])                    // Bat dau tro choi
{
    draw();
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
void bestScore(int &bestScore)                              // Cap nhat diem cao nhat
{
    fstream Game;
    Game.open("score.txt",ios::in);
    Game >> bestScore;
    Game.close();
}
void turnLeft(int matrix[4][4],int &score)                  // Di chuyen cac o so ve ben trai
{
    for(int k=0;k<3;k++)
    {
        for(int line=0;line<4;line++)
        {
            for(int column=0;column<3;column++)
            {
                if(matrix[line][column]==0)
                    swap(matrix[line][column],matrix[line][column+1]);
            }
        }
    }
    for(int line=0;line<4;line++)
    {
        for(int column=0;column<3;column++)
        {
            if(matrix[line][column] == matrix[line][column+1])
            {
                matrix[line][column]*=2;
                matrix[line][column+1]=0;
                score += matrix[line][column];
            }
        }
    }
    for(int line=0;line<4;line++)
    {
        for(int column=0;column<3;column++)
        {
            if(matrix[line][column]==0)
                swap(matrix[line][column],matrix[line][column+1]);
        }
    }
}
void turnRight(int matrix[4][4],int &score)                 // Di chuyen cac o so ve ben phi
{
    for(int k=0;k<3;k++)
    {
        for(int line=0;line<4;line++)
        {
            for(int column=3;column>0;column--)
            {
                if(matrix[line][column] == 0)
                    swap(matrix[line][column],matrix[line][column-1]);
            }
        }
    }
    for(int line=0;line<4;line++)
    {
        for(int column=3;column>0;column--)
        {
            if(matrix[line][column] == matrix[line][column-1])
            {
                matrix[line][column] *= 2;
                matrix[line][column-1] = 0;
                score += matrix[line][column];
            }
        }
    }
    for(int line=0;line<4;line++)
    {
        for(int column=3;column>0;column--)
        {
            if(matrix[line][column]==0)
                swap(matrix[line][column],matrix[line][column-1]);
        }
    }
}
void goUp(int matrix[4][4],int &score)                      // Di chuyen cac o so len tren
{
    for(int k=0;k<3;k++)
    {
        for(int line=0;line<3;line++)
        {
            for(int column=0;column<4;column++)
            {
                if(matrix[line][column]==0)
                    swap(matrix[line][column],matrix[line+1][column]);
            }
        }
    }
    for(int line=0;line<3;line++)
    {
        for(int column=0;column<4;column++)
        {
            if(matrix[line][column]==matrix[line+1][column])
            {
                matrix[line][column]*=2;
                matrix[line+1][column] = 0;
                score += matrix[line][column];
            }
        }
    }
    for(int line=0;line<3;line++)
    {
        for(int column=0;column<4;column++)
        {
            if(matrix[line][column]==0)
                swap(matrix[line][column],matrix[line+1][column]);
        }
    }
}
void goDown(int matrix[4][4],int &score)                    // Di chuyen cac o so xuong duoi
{
    for(int k=0;k<3;k++)
    {
        for(int line=3;line>0;line--)
        {
            for(int column=0;column<4;column++)
            {
                if(matrix[line][column]==0)
                    swap(matrix[line][column],matrix[line-1][column]);
            }
        }
    }
    for(int line=3;line>0;line--)
    {
        for(int column=0;column<4;column++)
        {
            if(matrix[line][column]==matrix[line-1][column])
            {
                matrix[line][column]*=2;
                matrix[line-1][column]=0;
                score+=matrix[line][column];
            }
        }
    }
    for(int line=3;line>0;line--)
    {
        for(int column=0;column<4;column++)
        {
            if(matrix[line][column]==0)
            swap(matrix[line][column],matrix[line-1][column]);
        }
    }
}
void creCheck(int matrix[4][4], int boardCheck[4][4])       // Gan gia tri cho mang can kiem tra
{
    for (int line=0;line<4;line++)
    {
	for (int column=0;column<4;column++)
            boardCheck[line][column] = matrix[line][column];
    }
}
bool checkMove(int matrix[4][4], int boardCheck[4][4])      // Kiem tra sau khi dieu khien xem mang co bi dich chuyen hay khong
{
    for (int line=0;line<4;line++)
    {
	for (int column=0;column<4;column++)
		if (boardCheck[line][column] != matrix[line][column]) return true;
    }
    return false;
}
bool emptyBoard(int matrix[4][4])                           // Kiem tra xem co con o trong
{
    for (int line=0;line<4;line++)
    {
        for (int column=0;column<4;column++)
        {
            if (matrix[line][column]==0) return true;
        }
    }
    return false;
}
void generateRandomNumber(int matrix[4][4],int boardCheck[4][4],int &number1,int &number2,int &number3) // Tao so ngau nhien
{
    if (emptyBoard(matrix) && checkMove(matrix,boardCheck))
    {
        srand(time(NULL));
        do
        {
            number1=rand()%4;
            number2=rand()%4;
        }
        while (matrix[number1][number2]!=0);
        srand(time(NULL));
        number3 = rand() % 101;
        (number3%10==0) ? matrix[number1][number2]=4 : matrix[number1][number2]=2;
    }
}
void restartGame(int matrix[4][4],int temp [4],int &score)  // Choi moi
{
    for(int line=0;line<4;line++)
    {
        for(int column=0;column<4;column++)
            matrix[line][column]=0;
    }
    score=0;
    start(temp,matrix);
}
void control(int matrix[4][4],int boardCheck[4][4],int temp [4],int &status,int &score,int &number1,int &number2,int &number3)  // Dieu khien
{
    char keys = _getch();
    switch (keys)
    {
        case 'w': case 'W':
        {
            goUp(matrix,score);
            generateRandomNumber(matrix,boardCheck,number1,number2,number3);
            break;
        }
        case 's': case 'S':
        {
            goDown(matrix,score);
            generateRandomNumber(matrix,boardCheck,number1,number2,number3);
            break;
        }
        case 'a': case 'A':
        {
            turnLeft(matrix,score);
            generateRandomNumber(matrix,boardCheck,number1,number2,number3);
            break;
        }
        case 'd': case 'D':
        {
            turnRight(matrix,score);
            generateRandomNumber(matrix,boardCheck,number1,number2,number3);
            break;
        }
        case 27:
        {
            status = 2;
            break;
        }
        case 'r': case 'R':
        {
            restartGame(matrix,temp,score);
            break;
        }
    }
}
void checkWin(int matrix[4][4],int &status)
{
    for(int line=0;line<4;line++)
    {
        for(int column=0;column<4;column++)
            if (matrix[line][column]==2048)
                status=0;
    }
}
bool checkLose(int matrix[4][4],int &status,bool condition)
{
    if (status==2) return true;
    for (int line=0; line<3; line++)
    {
    	if (matrix[line][3]==matrix[line+1][3]) condition = true;
    	else
    	{
		for (int column=0; column<3; column++)
		{
			if (matrix[3][column]==matrix[3][column+1]) condition =  true;
			else if (matrix[line][column]==matrix[line][column+1] || matrix[line][column]==matrix[line+1][column])
				condition = true;
		}
	}
     }
     if (!emptyBoard(matrix) && !condition) return true;
     else return false;
}
void update(int matrix[4][4],int &score,int &bestScore,int &status,bool condition)  // Cap nhat diem cao
{
    if (score>bestScore  && !checkLose(matrix,status,condition))
    {
        bestScore=score;
        ofstream Game;
        Game.open("score.txt",ios::out);
        Game<<bestScore;
        Game.close();
    }
}
void gameOver(int &bestScore, int &score)
{
    ofstream  Game;
    Game.open("score.txt",ios::out);
    Game<<bestScore;
    Game.close();
    gotoxy(31,26);
    textColor(11);
    cout<<"GAME OVER!!!";
    getch();
    clrscr();
    gotoxy(0,0);
    cout<<Board;
    gotoxy(44,15);
    textColor(10);
    cout<<score;
    gotoxy(0,18);
}
void victory ()
{
    gotoxy(0,0);
    setText("\n\n\n\n\n\t\tCONGRALULATIONS. YOU WIN!!!");
}

int main ()
{
    int matrixGame[4][4]={0},boardCheckGame[4][4],array[4];
    int scoreGame=0,bestScoreGame,statusOfGame=1;
    int randomNumber1,randomNumber2,randomNumber3;
    bool stopCondition;

    hideCursor();
    prepare();
    bestScore(bestScoreGame);
    start(array,matrixGame);
    display(matrixGame,scoreGame,bestScoreGame);
    do{
        control(matrixGame,boardCheckGame,array,statusOfGame,scoreGame,randomNumber1,randomNumber2,randomNumber3);
        update(matrixGame,scoreGame,bestScoreGame,statusOfGame,stopCondition);
        checkWin(matrixGame,statusOfGame);
        draw();
        display(matrixGame,scoreGame,bestScoreGame);
    }
    while (!checkLose(matrixGame,statusOfGame,stopCondition));

    if (statusOfGame==0)
        victory();
    else if (statusOfGame==2 || checkLose(matrixGame,statusOfGame,stopCondition))
    {
        gameOver(bestScoreGame,scoreGame);
    }
    getch();
    return 0;
}
