#ifndef SETTING_H
#define SETTING_H

void start(int temp[4],int matrix[4][4]);
void bestScore(int &bestScore);
void turnLeft(int matrix[4][4],int &score);
void turnRight(int matrix[4][4],int &score);
void goUp(int matrix[4][4],int &score);
void goDown(int matrix[4][4],int &score);
void generateRandomNumber(int matrix[4][4],int boardCheck[4][4],int &number1,int &number2,int &number3);
void restartGame(int matrix[4][4],int temp [4],int &score);
void control(int matrix[4][4],int boardCheck[4][4],int temp [4],int &status,int &score,int &number1,int &number2,int &number3);
void update(int matrix[4][4], int &score,int &bestScore,int &status,bool condition);

#endif // SETTING_H
