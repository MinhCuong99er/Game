#include <windows.h>
#include <ctime>
#include <fstream>
#include <conio.h>
#include "setting.h"
#include "Draw.h"
#include "WinOrLose.h"
#include "Console2048.h"

using namespace std;

void start(int temp[4],int matrix[4][4])
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
void bestScore(int &bestScore)
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
void update(int matrix[4][4], int &score,int &bestScore,int &status,bool condition)
{
    if (score>bestScore  && !checkLose(matrix,status,condition))
    {
        bestScore=score;
        ofstream  Game;
        Game.open("score.txt",ios::out);
        Game<<bestScore;
        Game.close();
    }
}
