/**
* Code by Phan Van Hoai | Vu Quang Minh | Pham Nhat Nam
* IT1 - K58 UTC
*/
#include<iostream>
#include<windows.h>

using namespace std;

class DoHoa {
	public:
		void gotoxy(int x, int y)
	{
	    static HANDLE h = NULL;  
	    if(!h)
	        h = GetStdHandle(STD_OUTPUT_HANDLE);
	    COORD c = { x, y };  
	    SetConsoleCursorPosition(h,c);
	}
	
	void resizeConsole(int width, int height)
	{
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r);
		MoveWindow(console, r.left, r.top, width, height, TRUE);
	}
	
	void veKhung() {
		char c = 201;
		gotoxy(0,0);cout << c;  //ve goc trai tren
		c = 200;
		gotoxy(0,18);cout << c; //ve goc trai duoi
		c = 187;
		gotoxy(92,0);cout << c; //ve goc phai tren
		c = 188;
		gotoxy(92,18);cout << c; //ve goc phai duoi
		c = 205;
		for (int i = 1; i <= 91; i++) { // ve ngang tren
			gotoxy(i,0);
			cout << c;
		}
		for (int i = 1; i <= 91; i++) { // ve ngang duoi
			gotoxy(i,18);
			cout << c;
		}
		for (int i = 1; i <= 91; i++) { // ve ngang giua
			gotoxy(i,2);
			cout << c;
		}
		
		c = 186;
		for (int i = 1; i <= 17; i++) { // ve doc trai
			gotoxy(0,i);
			cout << c;
		}
		for (int i = 1; i <= 17; i++) { // ve doc phai
			gotoxy(92,i);
			cout << c;
		}
		c = 204;
		gotoxy(0,2);cout << c; //ve goc cat trai
		c = 185;
		gotoxy(92,2);cout << c; //ve goc cat phai
		c = 219;
		gotoxy(7,1);cout << c; //ve dau tieu de
	    gotoxy(1,1);
	}
};

