#include <windows.h>
#include <fstream>
#include "Setting.h"
#include "Draw.h"
#include "Console2048.h"

bool emptyBoard(int matrix[4][4])
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
	if (!emptyBoard(matrix) && !condition) return true;
	else return false;
}
void losed(int &bestScore)
{
    ofstream  Game;
    Game.open("score.txt",ios::out);
    Game<<bestScore;
    Game.close();
    gotoxy(47,6);
    cout<<"GAME OVER!!!";
    gotoxy(0,20);
    system("pause");
    clrscr();
    gotoxy(0,20);
    setText(Face);
}
void victory()
{
    setText("\n\n\n\n\n\t\tCONGRALULATIONS. YOU WIN!!!");
}

