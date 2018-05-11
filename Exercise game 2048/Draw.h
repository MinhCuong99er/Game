#ifndef DRAW_H
#define DRAW_H

#include <iostream>
#include "console2048.h"
using namespace std;

#define BoardLength 24
#define BoardWidth 16

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
