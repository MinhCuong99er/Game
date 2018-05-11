#ifndef DRAW_H
#define DRAW_H

#include <iostream>
#include "console2048.h"
using namespace std;

#define BoardLength 24
#define BoardWidth 16
#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15

const string Face =
    "\n\n\n\n\n\t\t                \n"
    "\t\t       xxxxxxxxxxxx       \n"
    "\t\t      xxxxxxxxxxxxxx      \n"
    "\t\t     xxxxxxxxxxxxxxxx     \n"
    "\t\t     xxxxxxxxxxxxxxxx     \n"
    "\t\t    xxxxxxxxxxxxxxxxxx    \n"
    "\t\t    xxxxxxxxxxxxxxxxxx    \n"
    "\t\t   xxxxxTTTxxxxTTTxxxxx   \n"
    "\t\t     xxx   xxxx   xxx     \n"
    "\t\t     xxx   xxxx   xxx     \n"
    "\t\t      xx___xxxx___xx      \n"
    "\t\t      xxxxxxxxxxxxxx      \n"
    "\t\t       xxxxx  xxxxx       \n"
    "\t\t        xxxxxxxxxx        \n"
    "\t\t        xxxxxxxxxx        \n"
    "\t\t         x      x         \n"
    "\t\t         xx    xx         \n"
    "\t\t          xxxxxx          \n"
    "\t\t            xx            \n"
    "\t\t                          \n"
    "\t\t        YOU LOSED!        \n";


void setText(string text);
void prepare ();
void setColour(int &colour);
void draw();
void display(int matrix[4][4], int &score, int &bestScore);

#endif //DRAW_H
