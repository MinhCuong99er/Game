#include <conio.h>
#include "Draw.h"
#include "console2048.h"
#include "setting.h"
#include "WinOrLose.h"

int main ()
{
    int matrixGame[4][4]={0},temp[4];
 	int count=0,scoreGame=0,bestScoreGame,statusOfGame=1;
    bool stopCondition=false;

    hideCursor();
    prepare();
    bestScore(bestScoreGame);
    start(temp,matrixGame);
    fillTheBoard(matrixGame,scoreGame,bestScoreGame);

    do{
        control(matrixGame,scoreGame,bestScoreGame,count,statusOfGame);
        update(matrixGame,scoreGame,bestScoreGame,statusOfGame,stopCondition);
        drawTheFrame();
        fillTheBoard(matrixGame,scoreGame,bestScoreGame);
    }
    while (!gameOver(matrixGame,statusOfGame,stopCondition));

    if (statusOfGame==0)
        victory();
    else if (statusOfGame==2 || gameOver(matrixGame,statusOfGame,stopCondition))
        losed(bestScoreGame);
    return 0;
}


