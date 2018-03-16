#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <dos.h>

using namespace std;

void HuongDan();
void gotoxy(int x, int y);
int generateRandomNumber();

const string diem[14] = {"    ", "  2 ", "  4 ", "  8 ", " 16 ", " 32 ", " 64 ", " 128", " 256", " 512", "1024", "2048", "4096", "8192"};
const string Logo =
". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n"
". . . 2 2 2 . . . . . 0 0 0 . . . . . . . . 4 4 . . . . 8 8 8 8 8 . . . . .\n"
". . 2 . . . 2 . . . 0 . . . 0 . . . . . . 4 . 4 . . . 8 . . . . . 8 . . . .\n"
". . . . . . 2 . . 0 . . . . . 0 . . . . 4 . . 4 . . . 8 . . . . . 8 . . . .\n"
". . . . . 2 . . . 0 . . . . . 0 . . . 4 . . . 4 . . . . 8 8 8 8 8 . . . . .\n"
". . . . 2 . . . . 0 . . . . . 0 . . 4 4 4 4 4 4 4 . . 8 . . . . . 8 . . . .\n"
". . . 2 . . . . . . 0 . . . 0 . . . . . . . . 4 . . . 8 . . . . . 8 . . . .\n"
". . 2 2 2 2 2 . . . . 0 0 0 . . . . . . . . . 4 . . . . 8 8 8 8 8 . . . . .\n"
". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n";

int main()
{
    	HuongDan();
	delay(100);
	system("cls");
}

void HuongDan()
{
	cout << "Huong dan:\n\n\t-Su dung cac nut dieu huong de di chuyen:\n" << endl
		 << "\t\t+Len:\t"<< (char)24 << endl << endl
		 << "\t\t+Xuong:\t"<< (char)25 << endl << endl
		 << "\t\t+Phai:\t" << (char)26 << endl << endl
		 << "\t\t+Trai:\t"<< (char)27 << endl << endl
		 << "\t\t--> Nhan ESC de thoat tro choi!\n\n"
		 << "\t-Co gang dat duoc o 2048 !!! (^_^)\n\n\n";
}

void gotoxy(int x,int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x,y};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
int generateRandomNumber()
{
    int k= rand() % 50 + 1;
    if (k%3==0) return 4;
    else return 2;
}
