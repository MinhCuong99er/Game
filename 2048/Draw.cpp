#include <windows.h>
#include <conio.h>
#include "Draw.h"
#include "console2048.h"

using namespace std;

const string Logo =
    "\n\n\n\n\n\n\n\n\n\n\n\n                                           \n"
    "\t\t  2 2 2           0 0 0                 4 4         8 8 8 8 8  \n"
    "\t\t2       2       0       0             4   4       8           8\n"
    "\t\t        2     0           0         4     4       8           8\n"
    "\t\t      2       0           0       4       4         8 8 8 8 8  \n"
    "\t\t    2         0           0     4 4 4 4 4 4 4     8           8\n"
    "\t\t  2             0       0                 4       8           8\n"
    "\t\t2 2 2 2 2         0 0 0                   4         8 8 8 8 8  \n";
const string Guide =
    "\n\n\n\n\n\n\n\n\n                       \n\n"
    "\t\t\t\tGame instructions:                 \n\n"
    "\t\t<!> Use the navigation buttons to move:\n\n"
    "\t\t\t+ Up:    W                           \n\n"
    "\t\t\t+ Down:  S                           \n\n"
    "\t\t\t+ Right: D                           \n\n"
    "\t\t\t+ Left:  A                           \n\n"
    "\t\t<!> Press ESC to exit the game.        \n\n"
    "\t\t<!> Press R to replay the game.        \n\n"
    "\t\t\t\tGood luck !!! (^_^)\n              \n\n"
    "\t\t\tREADY!!! GO  --->>> ";
const string BoardHand=
    "\t\t      +-------------------------------------+   \n"
    "\t\t      |                                     |      \n"
    "\t\t      |        Best Score:                  |      \n"
    "\t\t      |                                     |      \n"
    "\t\t    _ |        Your Score:                  | _    \n"
    "\t\t   (o)|                                     |(o)   \n"
    "\t\t  ( { |                                     | } )  \n"
    "\t\t ( (_ |                                     | _) ) \n"
    "\t\t((# {)+-------------------------------------+(} #))\n"
    "\t\t(### {_} }                               { {_} ###)\n"
    "\t\t {      }                                 {      } \n"
    "\t\t  {____}                                   {____}  \n"
    "\t\t  |    |                                   |    |  \n"
    "\t\t  |    |                                   |    |  \n"
    "\t\t  |    |                                   |    |  \n"
    "\t\t  |    |                                   |    |  \n"
    "\t\t  |    |                                   |    |  \n"
    "\t\t  (____)                                   (____)  \n";
void setText(string text)
{
    while(1)
    {
        textColor(rand()%15);
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
void setColour(int &colour)                                 // Ham cai dat mau cho so
{
    switch (colour)
    {
        case 2:     textColor(62);  break;
        case 4:     textColor(61);  break;
        case 8:     textColor(60);  break;
        case 16:    textColor(59);  break;
        case 32:    textColor(58);  break;
        case 64:    textColor(57);  break;
        case 128:   textColor(56);  break;
        case 256:   textColor(55);  break;
        case 512:   textColor(54);  break;
        case 1024:  textColor(53);  break;
        case 2048:  textColor(52);  break;
        default:    textColor(51);
    }
}
void draw()                                                 // Ham ve khung
{
    gotoxy(0,0);
    for(int line=0;line<=BoardWidth;line++)
    {
        for(int column=0;column<=BoardLength;column++)
        {
        	gotoxy(column+29,line+2);
            if(line==0 && column==0)
            {
                textColor(15);
                cout<<char(-55);
            }
            else if(line==16 && column==0)
            {
                textColor(15);
                cout<<char(-56);
            }
            else if(line==0 && column==24)
            {
                textColor(15);
                cout<<char(-69);
            }
            else if(line==16 && column==24)
            {
                textColor(15);
                cout<<char(-68);
            }
            else if(line%4==0 && column==0)
            {
                textColor(15);
                cout<<char(-52);
            }
            else if(line%4==0 && column==24)
            {
                textColor(15);
                cout<<char(-71);
            }
            else if(line==0 && column%6==0)
            {
                textColor(15);
                cout<<char(-53);
            }
            else if(line==16 && column%6==0)
            {
                textColor(15);
                cout<<char(-54);
            }
            else if(line%4==0 && column%6==0)
            {
                textColor(15);
                cout<<char(-50);
            }
            else if(line%4==0)
            {
                textColor(15);
                cout<<char(-51);
            }
            else if(column%6==0)
            {
                textColor(15);
                cout<<char(-70);
            }
            else if (line%4!=0 && column%6!=0)
            {
                textColor(51);
                cout<<char(219);
            }
        }
    }
	gotoxy(0,20);
    textColor(14);
    cout<<BoardHand;
}
void display(int matrix[4][4], int &score, int &bestScore)  // Ham dien so
{
    for(int line=0;line<4;line++)
    {
        for(int column=0;column<4;column++)
        {
            setColour(matrix[line][column]);
            if (matrix[line][column]<100 && matrix[line][column]!=0)
            {
                gotoxy(32+column*6,4+line*4);
                cout<<matrix[line][column];
            }
            else if ((matrix[line][column]>100 && matrix[line][column]!=0))
            {
                gotoxy(31+column*6,4+line*4);
                cout<<matrix[line][column];
            }
        }
    }
    gotoxy(43,24);
    textColor(15);
    cout<<score;
    textColor(12);
    gotoxy(43,22);
    cout<<bestScore;
}
