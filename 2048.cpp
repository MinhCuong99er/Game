#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <math.h>
using namespace std;

const string diem[14] = {"    ", "  2 ", "  4 ", "  8 ", " 16 ", " 32 ", " 64 ", " 128", " 256", " 512", "1024", "2048", "4096", "8192"};

void PrintLogo ();
void HuongDan();
void gotoxy(int x, int y);

int main()
{
    int score, highScore;
    int Matrix[4][4];
    HuongDan();
}

void PrintLogo ()
{

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


