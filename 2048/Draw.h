#ifndef DRAW_H
#define DRAW_H

#include <iostream>
#include "console2048.h"
using namespace std;

#define BoardLength 24
#define BoardWidth 16

const string Board =
    "\n\n\n\n\n\n\n\n\n\n                             \n"
    "\t\t      +-------------------------------------+\n"
    "\t\t      |                                     |\n"
    "\t\t      |        YOU HAVE BEEN DEFEATED       |\n"
    "\t\t      |                                     |\n"
    "\t\t      |     Your Score is :                 |\n"
    "\t\t      |                                     |\n"
    "\t\t      +-------------------------------------+\n";

void setText(string text);
void prepare ();
void setColour(int &colour);
void draw();
void display(int matrix[4][4], int &score, int &bestScore);

#endif //DRAW
