#include <iostream>
#include <conio.h>

using namespace std;

void HuongDan();
void gotoxy(int x, int y);
int generateRandomNumber();
void DrawTheFrame();

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
    	Guide();
	delay(100);
	system("cls");
}

void Guide()
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
void DrawTheFrame()
{
    for(int i=0;i<=20;i++)  {
        for(int j=0;j<=40;j++)  {
            if(i==0 && j==0)
            {
                gotoxy(j,i);
                cout<<char(-55);
            }
            else if(i==20 && j==0)
            {
                gotoxy(j,i);
                cout<<char(-56);
            }
            else if(i==0 && j==40)
            {
                gotoxy(j,i);
                cout<<char(-69);
            }
            else if(i==20&&j==40)
            {
                gotoxy(j,i);
                cout<<char(-68);
            }
            else if((i==5 || i==10 || i==15) && j==0)
            {
                gotoxy(j,i);
                cout<<char(-52);
            }
            else if((i==5 || i==10 || i==15) && j==40)
            {
                gotoxy(j,i);
                cout<<char(-71);
            }
            else if(i==0&&(j==10||j==20||j==30))
            {
                gotoxy(j,i);
                cout<<char(-53);
            }
            else if(i==20 && (j==10 || j==20 || j==30))
            {
                gotoxy(j,i);
                cout<<char(-54);
            }
            else if((i==5 || i==10 || i==15) && ( j==10 || j==20 || j==30))
            {
                gotoxy(j,i);
                cout<<char(-50);
            }
            else if(i==5 || i==10 || i==15)
            {
                gotoxy(j,i);
                cout<<char(-51);
            }
            else if(i==0 || i==20)
            {
                gotoxy(j,i);
                cout<<char(-51);
            }
            else if(j==10 || j==20 || j==30)
            {
                gotoxy(j,i);
                cout<<char(-70);
            }
            else if(j==0 || j==40)
            {
                gotoxy(j,i);
                cout<<char(-70);
            }
        }
    }
}
int generateRandomNumber()
{
    int k= rand() % 50 + 1;
    if (k%3==0) return 4;
    else return 2;
}
