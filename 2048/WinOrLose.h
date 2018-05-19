#ifndef WINORLOSE_H
#define WINORLOSE_H

void creCheck(int matrix[4][4], int boardCheck[4][4]);
bool checkMove(int matrix[4][4], int boardCheck[4][4])  ;
bool emptyBoard(int matrix[4][4]);
void checkWin(int matrix[4][4],int &status);
bool checkLose(int matrix[4][4],int &status, bool condition);
void gameOver(int &bestScore,int &score);
void victory();

#endif // WINORLOSE_H
