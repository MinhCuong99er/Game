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
void draw()
{
    gotoxy(0,0);
	for(int i=0;i<=BoardWidth;i++)
	{
		for(int j=0;j<=BoardLength;j++)
		{
		    gotoxy(j+29,i+2);
			if (i%4==0 || j%6==0)
            {
                textColor(2);
                cout << char (219);
            }
			else
            {
                textColor(0);
                cout << char (219);
            }
		}
		cout<<endl;
	}
	gotoxy(0,20);
    textColor(3);
    cout<<BoardHand;
}
void display(int matrix[4][4], int &score, int &bestScore)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            setColour(matrix[i][j]);
            if (matrix[i][j]<100 && matrix[i][j]!=0)
            {
                gotoxy(32+j*6,4+i*4);
                cout<<matrix[i][j];
            }
            else if ((matrix[i][j]>100 && matrix[i][j]!=0))
            {
                gotoxy(31+j*6,4+i*4);
                cout<<matrix[i][j];
            }
        }
    }
    gotoxy(43,24);
    textColor(1);
    cout<<score;
    textColor(4);
    gotoxy(43,22);
    cout<<bestScore;
}
