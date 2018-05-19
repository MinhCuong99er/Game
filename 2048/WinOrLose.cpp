#include <windows.h>
#include <fstream>
#include <conio.h>
#include <iostream>
#include "setting.h"
#include "Draw.h"
#include "Console2048.h"

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
    if (status == 2) return true;
    for (int i=0; i<3; i++)
    {
    	if (matrix[i][3]==matrix[i+1][3]) condition = true;
    	else
    	{
			for (int j=0; j<3; j++)
			{
				if (matrix[3][j]==matrix[3][j+1]) condition =  true;
				else if (matrix[i][j]==matrix[i][j+1] || matrix[i][j]==matrix[i+1][j])
					condition = true;
			}
		}
	}
	if (!emptyBoard(matrix) && !condition) return true;
	else return false;
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


