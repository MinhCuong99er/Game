#include <windows.h>
#include <ctime>
#include <fstream>
#include <conio.h>
#include "Setting.h"
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
void turnLeft(int matrix[4][4],int &score,int &bestScore,int &status)
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
}
void turnRight(int matrix[4][4],int &score,int &bestScore,int &status)
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
}
void goUp(int matrix[4][4],int &score,int &bestScore,int &status)
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
}
void goDown(int matrix[4][4],int &score,int &bestScore,int &status)
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
}
void generateRandomNumber(int matrix[4][4],int &number1,int &number2,int &number3)
{
    if (emptyBoard(matrix))
    {
        srand(time(NULL));
        do
        {
            number1=rand()%4;
            number2=rand()%4;
        } while (matrix[number1][number2]!=0);

        srand(time(NULL));
        number3 = rand() % 101;
        (number3%10==0) ? matrix[number1][number2]=4 : matrix[number1][number2]=2;
    }
}
void replayGame(int matrix[4][4],int temp [4],int &score)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            matrix[i][j]=0;
    }
    score=0;
    start(temp,matrix);
}
void control(int matrix[4][4],int temp [4],int &score,int &bestScore,int &status,int &number1,int &number2,int &number3)
{
    char keys = _getch();
    switch (keys)
    {
        case 'w': case 'W':
        {
            goUp(matrix,score,bestScore,status);
            generateRandomNumber(matrix,number1,number2,number3);
            break;
        }
        case 's': case 'S':
        {
            goDown(matrix,score,bestScore,status);
            generateRandomNumber(matrix,number1,number2,number3);
            break;
        }
        case 'a': case 'A':
        {
            turnLeft(matrix,score,bestScore,status);
            generateRandomNumber(matrix,number1,number2,number3);
            break;
        }
        case 'd': case 'D':
        {
            turnRight(matrix,score,bestScore,status);
            generateRandomNumber(matrix,number1,number2,number3);
            break;
        }
        case 27:
        {
            status = 2;
            break;
        }
        case 'r': case 'R':
        {
            replayGame(matrix,temp,score);
            break;
        }
    }
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
