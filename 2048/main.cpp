#include <conio.h>
#include "Draw.h"
#include "console2048.h"
#include "setting.h"
#include "WinOrLose.h"

#define ConsoleLength 85   // Chieu dai man hinh console
#define ConsoleWidth 45   // Chieu rong man hinh console

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

