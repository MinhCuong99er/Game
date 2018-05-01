#include <windows.h>
#include <conio.h>
#include "Draw.h"
#include "console2048.h"

using namespace std;

const string Logo =
    "\n\n\n\n\n                                                         \n"
    "\t\t  2 2 2           0 0 0                 4 4         8 8 8 8 8  \n"
    "\t\t2       2       0       0             4   4       8           8\n"
    "\t\t        2     0           0         4     4       8           8\n"
    "\t\t      2       0           0       4       4         8 8 8 8 8  \n"
    "\t\t    2         0           0     4 4 4 4 4 4 4     8           8\n"
    "\t\t  2             0       0                 4       8           8\n"
    "\t\t2 2 2 2 2         0 0 0                   4         8 8 8 8 8  \n";
const string Guide =
    "\t\t\tGame instructions:\n\n"
    "\t<!> Use the navigation buttons to move:\n\n"
    "\t\t+ Up:    W \n\n"
    "\t\t+ Down:  S \n\n"
    "\t\t+ Right: D \n\n"
    "\t\t+ Left:  A \n\n"
    "\t<!> Press ESC to exit the game.\n\n"
    "\t\t\tGood luck !!! (^_^)\n\n\n"
    "\t\tREADY!!! GO  --->>> ";
const string BoardHand=
    "  +----------------------------------+   \n"
    "\t\t\t\t      |                                  |      \n"
    "\t\t\t\t      |        Best Score:               |      \n"
    "\t\t\t\t      |                                  |      \n"
    "\t\t\t\t    _ |        Your Score:               | _    \n"
    "\t\t\t\t   (o)|                                  |(o)   \n"
    "\t\t\t\t  ( { |                                  | } )  \n"
    "\t\t\t\t ( (_ |                                  | _) ) \n"
    "\t\t\t\t((# {)+----------------------------------+(} #))\n"
    "\t\t\t\t(### {_} }                            { {_} ###)\n"
    "\t\t\t\t {      }                              {      } \n"
    "\t\t\t\t  {____}                                {____}  \n"
    "\t\t\t\t  |    |                                |    |  \n"
    "\t\t\t\t  |    |                                |    |  \n"
    "\t\t\t\t  |    |                                |    |  \n"
    "\t\t\t\t  |    |                                |    |  \n"
    "\t\t\t\t  |    |                                |    |  \n"
    "\t\t\t\t  (____)                                (____)  \n";

void setText(string text)
{
    while(1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , rand() % 15);
        cout<<text;
        if(kbhit())
        {
            getch();
            break;
        }
        Sleep(250);
        clrscr();
    }
}

void prepare ()
{
    setText(Logo);
    clrscr();
    setText(Guide);
    clrscr();
}
void setColour(int &colour)
{
    switch (colour)
    {

        case 2:     textColor(15); break;
        case 4:     textColor(14); break;
        case 8:     textColor(13); break;
        case 16:    textColor(12); break;
        case 32:    textColor(11); break;
        case 64:    textColor(10); break;
        case 128:   textColor(9);  break;
        case 256:   textColor(8);  break;
        case 512:   textColor(7);  break;
        case 1024:  textColor(6);  break;
        case 2048:  textColor(5);  break;
        default:    textColor(4);
    }
}
void drawTheFrame()
{
    gotoxy(36,0);
    textColor(3);
    cout<<BoardHand;
    textColor(2);

    for(int i=0;i<=BoardWidth;i++)
    {
        for(int j=0;j<=BoardLength;j++)
        {
        	gotoxy(j,i);
            if(i==0 && j==0)
                cout<<char(-55);
            else if(i==16 && j==0)
                cout<<char(-56);
            else if(i==0 && j==24)
                cout<<char(-69);
            else if(i==16 && j==24)
                cout<<char(-68);
            else if((i==4 || i==8 || i==12) && j==0)
                cout<<char(-52);
            else if((i==4 || i==8 || i==12) && j==24)
                cout<<char(-71);
            else if(i==0 && (j==6 || j==12 || j==18))
                cout<<char(-53);
            else if(i==16 && (j==6 || j==12 || j==18))
                cout<<char(-54);
            else if((i==4 || i==8 || i==12) && (j==6 || j==12 || j==18))
                cout<<char(-50);
            else if(i==0 || i==4 || i==8 || i==12 || i==16)
                cout<<char(-51);
            else if(j==0 || j==6 || j==12 || j==18 || j==24)
                cout<<char(-70);
        }
    }
}
void fillTheBoard(int matrix[4][4], int &score, int &bestScore)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            setColour(matrix[i][j]);
            if (matrix[i][j]<100 && matrix[i][j]!=0)
            {
                gotoxy(3+j*6,2+i*4);
                cout<<matrix[i][j];
            }
            else if ((matrix[i][j]>100 && matrix[i][j]!=0))
            {
                gotoxy(2+j*6,2+i*4);
                cout<<matrix[i][j];
            }
        }
    }
    textColor(1);
    gotoxy(59,4);
    cout<<score;
    textColor(4);
    gotoxy(59,2);
    cout<<bestScore;
}
