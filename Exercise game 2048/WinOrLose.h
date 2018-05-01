#ifndef WINORLOSE_H
#define WINORLOSE_H

bool emptyBoard(int matrix[4][4]);
bool gameOver(int matrix[4][4],int &status, bool condition);
void losed(int &bestScore);
void victory();
#endif // WINORLOSE_H
