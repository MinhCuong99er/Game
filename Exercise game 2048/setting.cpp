#include <windows.h>
#include <ctime>
#include <fstream>
#include <conio.h>
#include "Setting.h"
#include "Draw.h"
#include "WinOrLose.h"
#include "Console2048.h"

using namespace std;

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
    count=1;
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
    count=1;
}
void turnRight(int matrix[4][4],int &score,int &bestScore,int &count,int &status)
{
    count=1;
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
    count=1;
}
void goUp(int matrix[4][4],int &score,int &bestScore,int &count,int &status)
{
    count=1;
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
    count=1;
}
void goDown(int matrix[4][4],int &score,int &bestScore,int &count,int &status)
{
    count=1;
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
    count=1;
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
