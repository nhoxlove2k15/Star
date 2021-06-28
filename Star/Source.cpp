#include<iostream>
#include<Windows.h>
#include<string>
#include<conio.h>
#pragma comment (lib, "winmm.lib")
using namespace std;
int WindowWidth = 120;
int WindowHeight = 40;
char ch = char(3);
void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void clrscr()
{
	COORD origin = { 0, 0 };
	unsigned long len;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	unsigned long size;
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);


	GetConsoleScreenBufferInfo(handle, &csbi);
	size = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(handle, TEXT(' '), size, origin, &len);
	FillConsoleOutputAttribute(handle, csbi.wAttributes, size, origin, &len);
	SetConsoleCursorPosition(handle, origin);
}
// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
// biến count để cho hiển thị màu nhìn ok như trong console  
// nói cách khác là biến count dùng để hiển thị màu chậm đi .
// nếu ko có thì nó sẽ hiện rất nhanh .
int countt = 0 ;
void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
// hàm in đầy đủ 4 ngôi sao 
void Show_Small_Start(char SmallStar1[15][30] , int a , int b) {
	//clrscr();
	int x, y;
	// int a, b;
	int yy = b;
	int t;

	
		// in ngôi sao 1 
		// a = 1, b = 1;
		t = rand() % 15 + 1;
		textcolor(t);
		for (int i = 0; i < 15; i++)
		{
			gotoxy(a, b);
			cout << SmallStar1[i];
			b++;
		}
		/* if (countt != 0)
		{
			Sleep(1000);
			 
		} */
		countt++;
		// in ngôi sao 2 
		a = a + 33 ;
		b = yy;
		t = rand() % 15 + 1;
		textcolor(t);
		for (int i = 0; i < 15; i++)
		{
			gotoxy(a, b);
			cout << SmallStar1[i];
			b++;
		}
		/*
		if (countt != 1)
		{
			Sleep(500);

		} */
		countt++;
		// in ngôi sao 3 
		a = a + 33; b = yy;
		t = rand() % 15 + 1;
		textcolor(t);
		for (int i = 0; i < 15; i++)
		{
			gotoxy(a, b);
			cout << SmallStar1[i];
			b++;
		}
		countt++;
		// in ngôi sao 4 
		a = a + 33; b = yy;
		t = rand() % 15 + 1;
		textcolor(t);
		for (int i = 0; i < 15; i++)
		{
			gotoxy(a, b);
			cout << SmallStar1[i];
			b++;
		}
	
}
void Show_Star1(char SmallStar1[15][25], char BigStar[37][48])
{
	clrscr();
	int x, y;
	int a, b;
	int t;

	while (!_kbhit())
	{
		// in ngôi sao 1 
		a = 1, b = 1;
		t = rand() % 15 + 1;
		textcolor(t);
		for (int i = 0; i < 15; i++)
		{
			gotoxy(a, b);
			cout << SmallStar1[i];
			b++;
		}
		if (countt != 0)
		{
			Sleep(1000);

		}
		countt++;
		// in ngôi sao 2 
		a = 28, b = 1;
		t = rand() % 15 + 1;
		textcolor(t);
		for (int i = 0; i < 15; i++)
		{
			gotoxy(a, b);
			cout << SmallStar1[i];
			b++;
		}
		if (countt != 1)
		{
			Sleep(500);

		}
		countt++;
		// in ngôi sao 3 
		a = 55, b = 1;
		t = rand() % 15 + 1;
		textcolor(t);
		for (int i = 0; i < 15; i++)
		{
			gotoxy(a, b);
			cout << SmallStar1[i];
			b++;
		}
		// in ngôi sao to
		x = 15; y = 20;
		t = rand() % 15 + 1;
		textcolor(t);

		for (int i = 0; i < 37; i++)
		{
			gotoxy(x, y);
			cout << BigStar[i];
			y++;
		}if (countt != 2)
		{
			Sleep(200);

		}
		countt++;
	}

}

// hàm in 3 ngôi sao ( ngôi sao đầu , ngôi sao giữa , ngôi sao to  ) 
int count2;
bool kt = true;
void Show_Star2(char SmallStar1[15][25], char BigStar[37][48])
{
	clrscr();
	int x, y;
	int a, b;
	int t;
	while (!_kbhit())
	{


		// in ngôi sao 1 	
		a = 1, b = 1;
		t = rand() % 15 + 1;
		textcolor(t);
		for (int i = 0; i < 15; i++)
		{
			gotoxy(a, b);
			cout << SmallStar1[i];
			b++;
		}
		if (count2 != 0)  Sleep(200);
		count2++;


		// in ngôi sao 3 
		a = 55, b = 1;
		t = rand() % 15 + 1;
		textcolor(t);
		for (int i = 0; i < 15; i++)
		{
			gotoxy(a, b);
			cout << SmallStar1[i];
			b++;
		}
		if (count2 != 1)  Sleep(200);
		count2++;

		// in ngôi sao giữa 
		x = 15; y = 20;
		t = rand() % 15 + 1;
		textcolor(t);
		if (count2 != 2)  Sleep(200);
		count2++;

		for (int i = 0; i < 37; i++)
		{
			gotoxy(x, y);
			cout << BigStar[i];
			y++;
		}
		// in chữ khi mất ngôi sao 2 
		while (kt == true)
		{
			a = 28, b = 1;
			string temp = "The Sky Has Lost One Star";
			textcolor(15);
			for (int i = 0; i < temp.size(); i++)
			{
				gotoxy(a, b);
				cout << temp[i];
				Sleep(200);
				a++;
			}
			kt = false;
		}
	}
}
// hàm in 2 ngôi sao ( ngôi sao cuối và ngôi sao to ) 
int count3;
bool kt1 = true;
void Show_Star3(char SmallStar1[15][25], char BigStar[37][48])
{
	clrscr();
	int x, y;
	int a, b;
	int t;
	while (!_kbhit())
	{



		// in ngôi sao 3 
		a = 55, b = 1;
		t = rand() % 15 + 1;
		textcolor(t);
		for (int i = 0; i < 15; i++)
		{
			gotoxy(a, b);
			cout << SmallStar1[i];
			b++;
		}
		if (count3 != 0)
		{
			Sleep(500);
		}
		count3++;
		// in ngôi sao to 
		x = 15; y = 20;
		t = rand() % 15 + 1;
		textcolor(t);

		for (int i = 0; i < 37; i++)
		{
			gotoxy(x, y);
			cout << BigStar[i];
			y++;
		}
		if (count3 != 1)
		{
			Sleep(500);
		}
		count3++;
		// in chữ khi mất ngôi sao 1 	
		while (kt1 == true)
		{

			a = 1, b = 1;

			textcolor(10);
			string temp = "The Sky Has Lost One Star";
			for (int i = 0; i < temp.size(); i++)
			{
				gotoxy(a, b);
				cout << temp[i];
				Sleep(200);
				a++;
			}
			kt1 = false;
		}
	}
}
// hàm in ngôi sao to 
int count4;
bool KT = true;
bool KT1 = true;
int k = 0;
int k1 = 0;
void Show_Star4(char SmallStar1[15][25], char BigStar[37][48])
{
	// ko can ham` clrscr();
	int x, y;
	int a, b;
	int t;
	while (k == 0)
	{
		// in ngôi sao to 
		x = 15; y = 20;
		t = rand() % 15 + 1;
		textcolor(t);

		for (int i = 0; i < 37; i++)
		{
			gotoxy(x, y);
			cout << BigStar[i];
			y++;
		}
		k++;
		// in chữ khi mất ngôi sao 2 
		while (KT == true)
		{

			a = 55, b = 1;
			textcolor(12);
			string temp = "The Sky Has Lost One Star";
			for (int i = 0; i < temp.size(); i++)
			{
				gotoxy(a, b);
				cout << temp[i];
				Sleep(100);
				a++;
			}
			clrscr();
			KT = false;
		}
	}
	textcolor(10);
	// in chữ ở trên ngôi sao to ( bước cuối ).
	while (KT1 == true)
	{

		a = 25; b = 5; // reset gia tri a , b 
		string temp = "Now only a big star stay with the sky";
		for (int i = 0; i < temp.size(); i++)
		{
			gotoxy(a, b);
			cout << temp[i];
			Sleep(50);
			a++;
		}
		a = 10;
		temp = " JustLike I always stay with you whenever you're up and down";
		for (int i = 0; i < temp.size(); i++)
		{
			gotoxy(a, b + 1);
			cout << temp[i];
			Sleep(50);
			a++;
		}
		KT1 = false;

	}
	textcolor(13);
	while (k1 == 0)
	{
		// x = 10->90 ,  y = 0->18 ,
		x = 10, y = 0;
		while (y <= 18)
		{
			gotoxy(x, y);

			cout << char(219);
			y++;
			Sleep(100);
		}
		y = 18;
		gotoxy(0, 19);
		cout << "???Where am I ?";
		Sleep(3000);
		gotoxy(0, 19);
		cout << "                   ";
		gotoxy(0, 19);
		cout << "Ok!I Found The Way.";
		Sleep(2000);
		gotoxy(0, 19);
		cout << "                    ";
		while (x <= 70)
		{
			gotoxy(x, y);

			cout << char(219);
			x++;
			Sleep(100);

		}
		x = 70;
		gotoxy(50, 19);
		cout << "Dafuq ! I Lost again";
		Sleep(2000);
		gotoxy(50, 19);
		cout << "                    ";
		gotoxy(50, 19);
		cout << "Ok!";
		Sleep(2000);
		gotoxy(50, 19);
		cout << "                    ";
		while (y >= 0)
		{
			gotoxy(x, y);
			cout << char(219);
			y--;
			Sleep(100);
		}
		y = 0;

		while (x >= 10)
		{
			gotoxy(x, y);
			cout << char(219);
			x--;
			Sleep(100);

		}
		gotoxy(0, 0);
		cout << "I'm Done";
		Sleep(2000);
		gotoxy(0, 1);
		cout << "Bye";
		Sleep(2000);
		// chi xoa 2 lan thoi 
		for (int i = 0; i < 2; i++)
		{
			gotoxy(0, i);
			cout << "           ";
		}


		x = 10;
		k1 = 1;
	}
	////////////////////////////////////////////////////////
		/*	x  = 10 , y = 0 ;


			while ( y <= 10)
			{
				gotoxy(x,y);

				cout << char(219);
				y++;
			}

			y = 10 ;
			while (x <= 70 )
			{
				gotoxy(x,y);

				cout << char(219);
				x++;
			}

			x = 70;
			while (y >= 0 )
			{
				gotoxy(x,y);

				cout << char(219);
				y --;
			}

			y = 0 ;

				while (x >= 10 )
			{
				gotoxy(x,y);

				cout << char(219);
				x --;
			}
				x = 10;

			*/
			////////////////////////////////////////////
					// in lai ngoi sao to 
	x = 15; y = 20;
	t = rand() % 15 + 1;
	textcolor(t);

	for (int i = 0; i < 37; i++)
	{
		gotoxy(x, y);
		cout << BigStar[i];
		y++;
	}
}
void Show_Quote() {
	int x = 0, y, a = WindowWidth / 2 + 15, b = 5;
	int max_x = 90;
	int max_y = 10;
	char ch = char(3);
	textcolor(10);
	// in chữ ở trên ngôi sao to ( bước cuối ).
	while (KT1 == true)
	{

		a = WindowWidth / 3-10; b = 4; // reset gia tri a , b 
		string temp = "Suddenly the big star has come and warm the sky";
		for (int i = 0; i < temp.size(); i++)
		{
			gotoxy(a, b);
			cout << temp[i];
			Sleep(75);
			a++;
		}
		a = WindowWidth / 3  - 10;
		temp = " JustLike U come and drag me from the darkness ";
		for (int i = 0; i < temp.size(); i++)
		{
			gotoxy(a, b + 1);
			cout << temp[i];
			Sleep(75);
			a++;
		}
		KT1 = false;

	}
	Sleep(1000);
	textcolor(11);
	while (k1 == 0)
	{
		// x = 20->90 ,  y = 0->18 ,
		x = 20, y = 0;
		while (y <= max_y)
		{
			gotoxy(x, y);

			cout << ch;
			y++;
			Sleep(150);
		}
		y = max_y;
		gotoxy(5, y+1);
		cout << " ? Left or Right ?";
		Sleep(3000);
		gotoxy(5, y+1);
		cout << "                   ";
		gotoxy(5, y+1);
		cout << "Ok ! Left";
		Sleep(2000);
		gotoxy(5, y + 1);
		cout << "                    ";
		while (x <= max_x)
		{
			gotoxy(x, y);

			cout << ch;
			x+=2;
			Sleep(150);

		}
		x = max_x;
		gotoxy(60, 14);
		cout << "Dkm ! I get lost again";
		Sleep(2000);
		gotoxy(60, 14);
		cout << "                               ";
		gotoxy(65, 13);
		cout << "Which way can I get to your heart ^^ ? ";
		Sleep(3000);
		gotoxy(65, 13);
		cout << "                                          ";
	
		
		/*
		cout << "OK ! I have found the way ";
		Sleep(2000);
		gotoxy(60, 14);
		cout << "                                          "; */
		while (y >= 0)
		{
			gotoxy(x, y);
			cout << ch;
			y--;
			Sleep(150);
		}
		y = 0;

		while (x >= 20)
		{
			gotoxy(x, y);
			cout << ch;
			x-= 2;
			Sleep(150);

		}
		gotoxy(5, 0);
		cout << "I'm Done";
		Sleep(2000);
		Sleep(1000);
		gotoxy(5, 0);
		cout << "Dy is out";
		Sleep(2000);
		gotoxy(7, 1);
		cout << "Bye";
		Sleep(2000);
		// chi xoa 2 lan thoi 
		for (int i = 0; i < 2; i++)
		{
			gotoxy(5, i);
			cout << "           ";
		}


		x = 10;
		k1 = 1;
	}
}
// hàm đếm số 1 -> trước khi in ngôi sao 	
void ShowNumber1()
{
	clrscr();

	char five[9][15] = {
		"555555555555",
		"55          ",
		"55          ",
		"55          " ,
		"555555555555",
		"          55",
		"          55",
		"          55",
		"555555555555",

	};
	char four[9][15] = {
		"44        44",
		"44        44",
		"44        44",
		"44        44",
		"444444444444",
		"          44",
		"          44",
		"          44",
		"          44",
	};
	char three[9][15] = {
		"333333333333",
		"          33",
		"          33",
		"          33",
		"333333333333",
		"          33",
		"          33",
		"          33",
		"333333333333",
	};
	char two[9][15] = {
		"222222222222",
		"          22",
		"          22",
		"          22",
		"222222222222",
		"22          ",
		"22          ",
		"22          ",
		"222222222222",
	};
	char one[9][15] = {
		"     11     ",
		"     11     ",
		"     11     ",
		"     11     ",
		"     11     ",
		"     11     ",
		"     11     ",
		"     11     ",
		"     11     ",
	};
	int t;
	t = rand() % 15 + 1;
	textcolor(t);
	int y;
	y = WindowHeight / 2 ;
	int x = WindowWidth / 3 + 5;
	for (int i = 0; i < 9; i++)
	{

		gotoxy(x, y);
		cout << five[i];
		y++;
	}

	Sleep(1700);
	clrscr();
	t = rand() % 15 + 1;
	textcolor(t);
	y = WindowHeight / 2;
	for (int i = 0; i < 9; i++)
	{
		gotoxy(x, y);
		cout << four[i];
		y++;
	}
	Sleep(1700);
	clrscr();
	t = rand() % 15 + 1;
	textcolor(t);
	y = WindowHeight / 2;
	for (int i = 0; i < 9; i++)
	{

		gotoxy(x, y);
		cout << three[i];
		y++;
	}
	Sleep(1700);
	clrscr();
	t = rand() % 15 + 1;
	textcolor(t);
	y = WindowHeight / 2;
	for (int i = 0; i < 9; i++)
	{

		gotoxy(x, y);
		cout << two[i];
		y++;
	}
	Sleep(1700);
	clrscr();
	t = rand() % 15 + 1;
	textcolor(t);
	y = WindowHeight / 2;
	for (int i = 0; i < 9; i++)
	{

		gotoxy(x, y);
		cout << one[i];
		y++;
	}
	Sleep(1700);

}
void ShowNumber2()
{	
	textcolor(10);
	gotoxy(WindowWidth / 3, WindowHeight / 2);
	cout << "Let count on 10 seconds";
	Sleep(1000); 
	clrscr();

	char six[9][15] = {
		"666666666666",
		"66          ",
		"66          ",
		"66          " ,
		"666666666666",
		"66        66",
		"66        66",
		"66        66",
		"666666666666",

	};
	char seven[9][15] = {
		"777777777777",
		"777777777777",
		"          77",
		"          77",
		"          77",
		"          77",
		"          77",
		"          77",
		"          77",

	};
	char eight[9][15] = {
		"888888888888",
		"88        88",
		"88        88",
		"88        88",
		"888888888888",
		"88        88",
		"88        88",
		"88        88",
		"888888888888",

	};
	char nine[9][15] = {
		"999999999999",
		"99        99",
		"99        99",
		"99        99",
		"888888888888",
		"          99",
		"          99",
		"          99",
		"999999999999",

	};
	char ten[9][30] = {
		"     11    000000000000",
		"     11    00        00",
		"     11    00        00",
		"     11    00        00",
		"     11    00        00",
		"     11    00        00",
		"     11    00        00",
		"     11    00        00",
		"     11    000000000000",

	};
	int t;
	t = rand() % 15 + 1;
	textcolor(t);
	int y;
	y = WindowHeight / 2  ;
	int x = WindowWidth / 3 + 5;
	for (int i = 0; i < 9; i++)
	{

		gotoxy(x, y  );
		cout << ten[i];
		y++;
	}

	Sleep(1700);
	clrscr();
	t = rand() % 15 + 1;
	textcolor(t);
	y = WindowHeight / 2;
	for (int i = 0; i < 9; i++)
	{
		gotoxy(x, y);
		cout << nine[i];
		y++;
	}
	Sleep(1700);
	clrscr();
	t = rand() % 15 + 1;
	textcolor(t);
	y = WindowHeight / 2 ;
	for (int i = 0; i < 9; i++)
	{

		gotoxy(x, y);
		cout << eight[i];
		y++;
	}
	Sleep(1700);
	clrscr();
	t = rand() % 15 + 1;
	textcolor(t);
	y = WindowHeight / 2;
	for (int i = 0; i < 9; i++)
	{

		gotoxy(x, y);
		cout << seven[i];
		y++;
	}
	Sleep(1700);
	clrscr();
	t = rand() % 15 + 1;
	textcolor(t);
	y = WindowHeight / 2 ;
	for (int i = 0; i < 9; i++)
	{

		gotoxy(x, y);
		cout << six[i];
		y++;
	}
	Sleep(1700);


}
void Show_Big_Star(char BigStar[37][48], int x, int y) {
	// in ngôi sao to 
	// x = 15; y = 20;
	int t = rand() % 15 + 1;
	textcolor(t);

	for (int i = 0; i < 37; i++)
	{
		ShowCursor(false);
		gotoxy(x, y);
		cout << BigStar[i];
		y++;
		Sleep(1);
		//Sleep(1);
	}
		


}
int height = 20;
int width = 100;
void Show_Run() {
	int a = WindowWidth / 4 - 10 , b = 0;
	int t;

	gotoxy(WindowWidth / 4 + 24 , WindowHeight / 4); // 50 , 2
	textcolor(15);
	cout << "Welcome to the Show !!! ";
	while (!_kbhit())
	{
		if (b < (WindowHeight / 2))
		{
			gotoxy(a, b);
			t = rand() % 15 + 1;
			textcolor(t);
			cout << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch;
			//cout << "***************";
			Sleep(100);
			gotoxy(a, b);
			cout << "                        "; // BAO NHIU KÍ TỰ THÌ BẤY NHIÊU KHOẢNG CÁCH .
			b++;
		}
		else if (b == (WindowHeight / 2))
		{
			while (b > 0)
			{
				t = rand() % 15 + 1;
				gotoxy(WindowWidth - 20, b);
				textcolor(t);
				cout << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch;
				Sleep(100);
				gotoxy(WindowWidth - 20, b);
				cout << "                          "; // BAO NHIU KÍ TỰ THÌ BẤY NHIÊU KHOẢNG CÁCH .
				b--;
			}
		}
	}
	clrscr();
	// Sleep(1000);

}
void Show_Run2() {
	int a = WindowWidth / 4 - 10, b = 0;
	int t;

	gotoxy(WindowWidth / 4 + 18, WindowHeight / 4); // 50 , 2
	textcolor(15);
	cout << "This is end ! But music does not end ^^  ";
	while (!_kbhit())
	{
		if (b < (WindowHeight / 2))
		{
			gotoxy(a, b);
			t = rand() % 15 + 1;
			textcolor(t);
			cout << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch;
			//cout << "***************";
			Sleep(100);
			gotoxy(a, b);
			cout << "                        "; // BAO NHIU KÍ TỰ THÌ BẤY NHIÊU KHOẢNG CÁCH .
			b++;
		}
		else if (b == (WindowHeight / 2))
		{
			while (b > 0)
			{
				t = rand() % 15 + 1;
				gotoxy(WindowWidth - 20, b);
				textcolor(t);
				cout << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch;
				Sleep(100);
				gotoxy(WindowWidth - 20, b);
				cout << "                          "; // BAO NHIU KÍ TỰ THÌ BẤY NHIÊU KHOẢNG CÁCH .
				b--;
			}
		}
	}
	clrscr();
	// Sleep(1000);

}
void ShowString_third();
void End();
// hàm tổng hợp các hàm in sao 
void ShowStar()
{

	char SmallStar[15][30] = {
		"         *            ",
		"                      ",
		"        *  *          ",
		"                      ",
		"       *    *         ",
		"                      ",
		"* * * *  * *  * * * *  ",
		"                      ",
		"  *  *        *  *     ",
		"                        ",
		"   *      *     *      ",
		"                      ",
		"  *   *       *   *   ",
		"                      ",
		"*                   * "
	};



	char BigStar[37][48] = {
		"                      *                        ",
		"                                               ",
		"                     *  *                      ",
		"                                               ",
		"                    *    *                     ",
		"                                               ",
		"                   *      *                    ",
		"                                               ",
		"                  *        *                   ",
		"                                               ",
		"                 *          *                  ",
		"                                               ",
		"                *            *                 ",
		"                                               ",
		"* * * * * * *  * *  *  *  * * * * * * * * * * *",
		"                                               ",
		"  *	        *  	  *       *           *   ",
		"                                               ",
		"    *        *                  *        *     ",
		"                                               ",
		"      *     *                    *     *       ",
		"                                               ",
		"        *  *                      *  *         ",
		"                                               ",
		"	       *                        *           ",
		"                                               ",
		"         *     *             *      *          ",
		"                                               ",
		"        *             *              *         ",
		"                                               ",
		"       *          *        *          *        ",
		"                                               ",
		"      *      *                   *     *       ",
		"                                               ",
		"     *    *                         *   *      ",
		"                                               ",
		"    *                                    *     ",
	};
	//cin.ignore();
	/*Show_Star1(SmallStar, BigStar);
	cin.ignore();
	Show_Star2(SmallStar, BigStar);
	cin.ignore();
	Show_Star3(SmallStar, BigStar);
	cin.ignore();*/
	_getch();
	while (!_kbhit()) {
		Show_Small_Start(SmallStar, 1, 1);
		Show_Small_Start(SmallStar, 1, 17);
		Show_Small_Start(SmallStar, 1, 34);
		Sleep(750);

		
	}
	 Sleep(1000);
	 ShowString_third();
	 clrscr();
	_getch();
	Show_Quote();
	while (!_kbhit()) {
		
		
		Show_Big_Star(BigStar, 35, 12);
	}
	
	End();
	_getch();
	while (!_kbhit()) {
		Show_Run2();
	}
	
	// while (!_kbhit()) { Show_Star4(SmallStar, BigStar); }
}
void End() {
	clrscr();
	char string[12][500] = {
"_____*yeu*_*yeu*________*yeu*_*yeu*",
"___*yeu*______*yeu*_*yeu*_______*yeu*",
"__*yeu*__________*yeu*__________*yeu*",
"__*yeu*________________________*yeu*",
"___*yeu*________**Song**________*yeu*",
"____*yeu*____In Love - July____*yeu*",
"______*yeu*________________*yeu*",
"________*yeu*____________*yeu*",
"__________*yeu*________*yeu*",
"____________*yeu*____*yeu*",
"______________*yeu**yeu*",
">>>>>>>>>>>>>>>> *yeu* >>>>>>>>>>>>>>>> Thanks for watching" };
	int x = WindowWidth / 3;
	int y = WindowHeight / 3;
	for (int i = 0; i < 12; i++) {
		gotoxy(x, y);
		int t = rand() % 15 + 1;
		textcolor(t);
		cout << string[i] << endl;
		y++;
		Sleep(1000);


	}
	int len = 12;
	x = WindowWidth / 3;
	int z = y;
	textcolor(10);
	while (y > 0) {
		clrscr();
		for (int i = 11; i >= 0; i--) {

			gotoxy(x, y - 1);
			if (y - 1 <= 0) {
				cout << "                                                                                                    " << endl;
			} else cout << string[i] << endl;
			y--;

		}
		y = y + 11;
		Sleep(500);
	}
}
	


	


void ShowString_third() {
	clrscr();
	/////////////////////
	gotoxy(WindowWidth / 3, WindowHeight / 2);
	textcolor(13);
	string a = "There are many stars in the sky";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
		Sleep(200);
	}
	textcolor(15);
	gotoxy(WindowWidth / 3 + 3, WindowHeight / 2 + 1);
	a = "But they left me alone";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
		Sleep(200);
	}
	Sleep(2000);
	gotoxy(WindowWidth / 3, WindowHeight / 2);
	cout << "                                                   ";
	gotoxy(WindowWidth / 3, WindowHeight / 2 + 1 );
	cout << "                                                   ";
	textcolor(12);
	gotoxy(WindowWidth / 3 + 3, WindowHeight / 2 );
	a = "Now I feel empty and cold ";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
		Sleep(100);
	}
	Sleep(2000);
}

bool Over = true;
/*void Show()
{
	while(!_kbhit() )
	{
	gotoxy(5,5);
	int t = rand() % 15+1;
	textcolor(t);
	cout<<">>>>";
	////////////////
	gotoxy(40,30);
	 t = rand() % 15+1;
	textcolor(t);
	cout<<"<<<<<";
	}
}*/
void Author()
{
	textcolor(11);
	// muc tieu xoa : x = 30 , y = 15 ;
	int x = WindowWidth/3 - 5, y = WindowHeight / 2 - 5;
	int timee = 75; 
	gotoxy(x, y-2);
	cout << "Hello ! I'm Dy Dy. My Job is to make U happy";
	gotoxy(WindowWidth / 3 - 15, WindowHeight / 2 + 1);
	while (x > WindowWidth / 6)
	{
		gotoxy(x, y);
		cout << " " << ch << " ";
		x--;
		Sleep(timee);
	}
	while (y < WindowHeight / 2 )
	{
		gotoxy(x, y);
		cout << " " << ch << " ";
		Sleep(timee);
		gotoxy(x, y);
		cout << "   ";
		y++;

	}
	while (x < WindowWidth - 30)
	{
		gotoxy(x, y);
		cout << " " << ch << " ";
		x++;
		Sleep(timee);
	}
	gotoxy(x, y);
	cout << "   ";
	y = y + 1; // y = 16 .
	gotoxy(x, y);
	cout << " " << ch << " ";
	gotoxy(x, y);
	cout << "   ";

	while (x >= 10)
	{
		gotoxy(x, y);
		cout << " " << ch << " ";
		x--;
		Sleep(timee);
	}

}
void ShowString_frist()
{
	/////////////////////
	gotoxy(WindowWidth/3 , WindowHeight/2);
	textcolor(13);
	string a = "June 28th , 2021";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
		Sleep(100);
	}
	gotoxy(WindowWidth / 3 - 15 , WindowHeight / 2 + 1 );
	a = "Hi Quynh Anh ! The girl with cuteness and her beautiful name";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
		Sleep(100);
	}
	Author();

	clrscr();
	Sleep(1000);
	////////////////////////////
	gotoxy(WindowWidth / 3, WindowHeight / 2 );
	textcolor(13);
	cout << "Let music begin";
	Sleep(2000);
	


	//mciSendString("play mp3", NULL, 0, NULL);
	PlaySound("Mario_Game_Over.wav", NULL, SND_ASYNC);
	/////////////////////////////
	clrscr();
	gotoxy(WindowWidth / 3, WindowHeight / 2);
	textcolor(10);
	Sleep(500);
	a = "Not Mario . Wrong sound , My fauft!";
	cout << a;
	Sleep(2000);
	/////////////////////////////
	gotoxy(WindowWidth / 3 + 7, WindowHeight / 2 + 1);
	textcolor(14);
	a = " Now try again ! ";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
		Sleep(200);
	}
	Sleep(2000);
	PlaySound("InLove.wav", NULL, SND_ASYNC);

	//////////////////////////////
	clrscr();
	gotoxy(WindowWidth / 3, WindowHeight / 2 + 1);
	Sleep(1500);
	textcolor(10);
	a = "Perfect !";
	cout << a;
	Sleep(2000);
	///////////////////////
	gotoxy(WindowWidth / 3, WindowHeight / 2 + 1);
	textcolor(13);
	a = "Now I have a surprise for U";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
		Sleep(200);
	}
	clrscr();
	Sleep(2000);
	////////////////////////////
	/*gotoxy(WindowWidth / 3, WindowHeight / 2 + 1);
	cout << "Let count on 10 seconds";
	Sleep(2000);*/

	/////////////////////////
}
void Author2()
{
	clrscr();
	textcolor(11);
	int x = WindowWidth / 4 + 10, y = WindowHeight/2 - 5 ;
	gotoxy(x  - 15 , y + 3 );
	cout << " " << ch << " ";

	gotoxy(x, y);
	cout << "   nani ???   ";
	Sleep(2000);
	gotoxy(x, y + 1);
	cout << "Why I am here ?";
	Sleep(2000);
	for (int i = y; i < y + 2; i++)
	{
		gotoxy(x, y);
		cout << "               ";
	}
	gotoxy(x, y);
	cout << " Wrong time to show up again ! ";
	Sleep(1000);
	gotoxy(x - 2, y + 1);
	cout << "I'm getting out of here ";
	// xoa toa do dau` tien .
	gotoxy(x - 15, y + 3);
	cout << "   ";
	int a = x - 5;
	int b = y + 5;
	while (a < 50)
	{
		gotoxy(a,b);
		cout << " " << ch << " ";
		a++;
		Sleep(100);
	}
	while (b < 25)
	{
		gotoxy(a, b);
		cout << " " << ch << " ";
		Sleep(100);
		gotoxy(a,b);
		cout << "   ";
		b++;
	}

	while (a < WindowWidth)
	{
		gotoxy(a, b);
		cout << " " << ch << " ";
		a++;
		Sleep(50);
	}

	clrscr();

	gotoxy(x, y);
	cout << " Dy Dy will be back ";
	Sleep(1500);
}
void ShowString_second()
{
	
	clrscr();
	int y = WindowHeight / 2;
	gotoxy(WindowWidth / 4 + 15 , y );
	textcolor(13);
	string a = "Be ready ! Close your eyes in 3 seconds";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
		Sleep(100);
	}
	Sleep(3000);
	clrscr();
	
	ShowCursor(false);
	////////////////

	//////////////////////
	// gotoxy(30, 15);
	textcolor(14);
	a = "Now open";
	int temp = WindowWidth;
	while (temp > WindowWidth / 4 + 25)
	{
		gotoxy(temp, y);
		cout << a;
		Sleep(75);
		gotoxy(temp, y);
		cout << "          ";
		temp--;

	}
	Sleep(1000);
	clrscr();
	
}
int main()
{
	//hidecursor();


	// ...
	ShowConsoleCursor(false);
	//resizeConsole(1143, 985);
	
	while(!_kbhit()){}
	_getch();
	 ShowString_frist();
	
	Show_Run();
		
		ShowNumber2();
		ShowNumber1();
		Author2();
		ShowString_second(); 
		
		
	
		 
	
	ShowStar();
	
	//Show_Run2();
	
	textcolor(7);
	cout << endl;
	system("pause");
	return 0;
}