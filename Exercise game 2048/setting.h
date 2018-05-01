#ifndef SETTING_H
#define SETTING_H



int generateRandomNumber(int &randomNumber);
void start(int temp[4],int matrix[4][4]);
void bestScore(int &bestScore);
void turnLeft(int matrix[4][4],int &score,int &bestScore,int &count,int &status);
void turnRight(int matrix[4][4],int &score,int &bestScore,int &count,int &status);
void goUp(int matrix[4][4],int &score,int &bestScore,int &count,int &status);
void goDown(int matrix[4][4],int &score,int &bestScore,int &count,int &status);
void control(int matrix[4][4],int &score,int &bestScore,int &count,int &status);
void update(int matrix[4][4], int &score,int &bestScore,int &status,bool condition);

#endif // SETTING_H
