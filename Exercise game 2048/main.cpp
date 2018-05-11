#include <conio.h>
#include "Draw.h"
#include "console2048.h"
#include "setting.h"
#include "WinOrLose.h"
#include <MMSystem.h>

#define WidthConsole   700  // Chieu dai man hinh console
#define HeightConsole  400  // Chieu rong man hinh console

int main ()
{
    int matrixGame[4][4]={0},array[4];
 	int scoreGame=0,bestScoreGame,statusOfGame=1;
 	int randomNumber1,randomNumber2,randomNumber3;
    bool stopCondition;
    
    resizeConsole(WidthConsole, HeightConsole);
    hideCursor();
    prepare();
    bestScore(bestScoreGame);
    start(array,matrixGame);
    display(matrixGame,scoreGame,bestScoreGame);
    
    do{
        control(matrixGame,array,scoreGame,bestScoreGame,statusOfGame,randomNumber1,randomNumber2,randomNumber3);
        update(matrixGame,scoreGame,bestScoreGame,statusOfGame,stopCondition);
        draw();
        display(matrixGame,scoreGame,bestScoreGame);
    }
    while (!gameOver(matrixGame,statusOfGame,stopCondition));

    if (statusOfGame==0)
        victory();
    else if (statusOfGame==2 || gameOver(matrixGame,statusOfGame,stopCondition))
        losed(bestScoreGame);
    getch();
    return 0;
}

