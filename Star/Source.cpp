#include<iostream>
#include<Windows.h>
#include<string>
#include<conio.h>
#pragma comment (lib, "winmm.lib")
using namespace std;
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
void Show_ABC() {
	int x = 0, y, a = 35, b = 5;
	int max_x = 90;
	int max_y = 15;
	char ch = char(3);
	textcolor(10);
	// in chữ ở trên ngôi sao to ( bước cuối ).
	while (KT1 == true)
	{

		a = 35; b = 5; // reset gia tri a , b 
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
		// x = 20->90 ,  y = 0->18 ,
		x = 20, y = 0;
		while (y <= max_y)
		{
			gotoxy(x, y);

			cout << ch;
			y++;
			Sleep(100);
		}
		y = max_y;
		gotoxy(0, y+1);
		cout << "???Where am I ?";
		Sleep(3000);
		gotoxy(0, y+1);
		cout << "                   ";
		gotoxy(0, y+1);
		cout << "Ok!I Found The Way.";
		Sleep(2000);
		gotoxy(0, y);
		cout << "                    ";
		while (x <= max_x)
		{
			gotoxy(x, y);

			cout << ch;
			x+=2;
			Sleep(100);

		}
		x = max_x;
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
			cout << ch;
			y--;
			Sleep(100);
		}
		y = 0;

		while (x >= 20)
		{
			gotoxy(x, y);
			cout << ch;
			x-= 2;
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
	y = 15;
	for (int i = 0; i < 9; i++)
	{

		gotoxy(35, y);
		cout << five[i];
		y++;
	}

	Sleep(1700);
	clrscr();
	t = rand() % 15 + 1;
	textcolor(t);
	y = 15;
	for (int i = 0; i < 9; i++)
	{
		gotoxy(35, y);
		cout << four[i];
		y++;
	}
	Sleep(1700);
	clrscr();
	t = rand() % 15 + 1;
	textcolor(t);
	y = 15;
	for (int i = 0; i < 9; i++)
	{

		gotoxy(35, y);
		cout << three[i];
		y++;
	}
	Sleep(1700);
	clrscr();
	t = rand() % 15 + 1;
	textcolor(t);
	y = 15;
	for (int i = 0; i < 9; i++)
	{

		gotoxy(35, y);
		cout << two[i];
		y++;
	}
	Sleep(1700);
	clrscr();
	t = rand() % 15 + 1;
	textcolor(t);
	y = 15;
	for (int i = 0; i < 9; i++)
	{

		gotoxy(35, y);
		cout << one[i];
		y++;
	}
	Sleep(1700);

}
void ShowNumber2()
{
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
	y = 15;
	for (int i = 0; i < 9; i++)
	{

		gotoxy(30, y);
		cout << ten[i];
		y++;
	}

	Sleep(1700);
	clrscr();
	t = rand() % 15 + 1;
	textcolor(t);
	y = 15;
	for (int i = 0; i < 9; i++)
	{
		gotoxy(35, y);
		cout << nine[i];
		y++;
	}
	Sleep(1700);
	clrscr();
	t = rand() % 15 + 1;
	textcolor(t);
	y = 15;
	for (int i = 0; i < 9; i++)
	{

		gotoxy(35, y);
		cout << eight[i];
		y++;
	}
	Sleep(1700);
	clrscr();
	t = rand() % 15 + 1;
	textcolor(t);
	y = 15;
	for (int i = 0; i < 9; i++)
	{

		gotoxy(35, y);
		cout << seven[i];
		y++;
	}
	Sleep(1700);
	clrscr();
	t = rand() % 15 + 1;
	textcolor(t);
	y = 15;
	for (int i = 0; i < 9; i++)
	{

		gotoxy(35, y);
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
		gotoxy(x, y);
		cout << BigStar[i];
		y++;
	}
	if (count3 != 1)
	{
		Sleep(500);
	}


}
int height = 20;
int width = 100;
void Show_Run() {
	int a = 0 , b = 0;
	while (!_kbhit())
	{
		if (b < (height / 4))
		{
			gotoxy(a, b);
			textcolor(11);
			cout << "*****";
			Sleep(100);
			gotoxy(a, b);
			cout << "     "; // BAO NHIU KÍ TỰ THÌ BẤY NHIÊU KHOẢNG CÁCH .
			b++;
		}
		else if (b == (height / 4))
		{
			while (b > 0)
			{
				gotoxy(68, b);
				textcolor(14);
				cout << "#####";
				Sleep(100);
				gotoxy(68, b);
				cout << "     "; // BAO NHIU KÍ TỰ THÌ BẤY NHIÊU KHOẢNG CÁCH .
				b--;
			}
		}
	}
	Sleep(1000);
	textcolor(13);
	gotoxy((width / 4), 2);

	cout << "Chao Mung Ban Den Voi Snake Game!!! ";
}

// hàm tổng hợp các hàm in sao 
void ShowStar()
{
	/*
	char SmallStar[15][25] = {
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
	};*/
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
	/*char SmallStar[15][30] = {
		"         *            ",
		"                      ",
		"       *   *          ",
		"                      ",
		"     *        *         ",
		"                      ",
		"* * * *  * *  * * * *  ",
		"                      ",
		"*  *            *  *     ",
		"                        ",
		"   *      *     *      ",
		"                      ",
		"  *   *       *   *   *",
		"                      ",
		"*                   * "
	};*/


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
	
	while (!_kbhit()) {
		Show_Small_Start(SmallStar, 1, 1);
		Show_Small_Start(SmallStar, 1, 17);
		Show_Small_Start(SmallStar, 1, 34);
		Sleep(1000);

		
	}
	 Sleep(2000);
	clrscr();
	_getch();
	while (!_kbhit()) {
		Show_ABC();
		Show_Big_Star(BigStar, 35, 20);
	}
	clrscr();
	cout << "hello world";
	// while (!_kbhit()) { Show_Star4(SmallStar, BigStar); }
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
	textcolor(9);
	// muc tieu xoa : x = 30 , y = 15 ;
	int x = 25, y = 5;
	gotoxy(25, 3);
	cout << "Hello ! I'm Author. My Job is clean characters";
	while (x > 10)
	{
		gotoxy(x, y);
		cout << " * ";
		x--;
		Sleep(100);
	}
	while (y < 15)
	{
		gotoxy(x, y);
		cout << " * ";
		Sleep(100);
		gotoxy(x, y);
		cout << "   ";
		y++;

	}
	while (x < 50)
	{
		gotoxy(x, y);
		cout << " *";
		x++;
		Sleep(100);
	}
	gotoxy(x, y);
	cout << "   ";
	y = y + 1; // y = 16 .
	gotoxy(x, y);
	cout << " * ";
	gotoxy(x, y);
	cout << "   ";

	while (x >= 10)
	{
		gotoxy(x, y);
		cout << "* ";
		x--;
		Sleep(100);
	}

}
void ShowString_frist()
{
	/////////////////////
	gotoxy(30, 15);
	textcolor(3);
	string a = "September 15th , 2019";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
		Sleep(100);
	}
	gotoxy(33, 16);
	a = "Dear My Friend!";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
		Sleep(100);
	}
	Author();

	clrscr();
	Sleep(1000);
	////////////////////////////
	gotoxy(30, 15);
	textcolor(5);
	cout << "Let play music";
	Sleep(2000);
	//PlaySound("Mario_Game_Over.wav", NULL, SND_ASYNC);
	/////////////////////////////
	clrscr();
	gotoxy(30, 15);
	textcolor(4);
	a = " Wrong music,My fauft!";
	cout << a;
	Sleep(2000);
	/////////////////////////////
	gotoxy(30, 16);
	textcolor(4);
	a = "    Now try again ! ";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
		Sleep(200);
	}
	Sleep(2000);
	//PlaySound("Romeo-And-Juliet.wav", NULL, SND_ASYNC);

	//////////////////////////////
	clrscr();
	gotoxy(30, 15);
	textcolor(4);
	a = "Perfect!";
	cout << a;
	Sleep(2000);
	///////////////////////
	gotoxy(30, 15);
	textcolor(4);
	a = "Now I have a surprise for U";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
		Sleep(200);
	}
	clrscr();
	Sleep(2000);
	////////////////////////////
	gotoxy(30, 15);
	cout << "Let count on 10 seconds";
	Sleep(2000);

	/////////////////////////
}
void Author2()
{
	clrscr();
	textcolor(11);
	int x = 30, y = 15;
	gotoxy(15, 20);
	cout << " * ";

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
	gotoxy(15, 20);
	cout << "   ";
	x = x - 5;
	y = y + 5;
	while (x < 50)
	{
		gotoxy(x, y);
		cout << " * ";
		x++;
		Sleep(100);
	}
	while (y < 25)
	{
		gotoxy(x, y);
		cout << " * ";
		Sleep(100);
		gotoxy(x, y);
		cout << "   ";
		y++;
	}

	while (x < 70)
	{
		gotoxy(x, y);
		cout << " * ";
		x++;
		Sleep(100);
	}

	clrscr();

	gotoxy(30, 15);
	cout << " I'll be back ";
	Sleep(1500);
}
void ShowString_second()
{
	clrscr();
	gotoxy(30, 15);
	textcolor(8);
	string a = "Be ready!Close your eyes in 3 seconds";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
		Sleep(200);
	}
	clrscr();
	Sleep(2000);
	////////////////

	//////////////////////
	gotoxy(30, 15);
	textcolor(5);
	a = "Now open";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
		Sleep(200);
	}
	clrscr();
	Sleep(2000);
}
int main()
{

	resizeConsole(1200, 1000);
	//	Show();
	ShowString_frist();
	
	//Author2();
	
	//ShowString_second();
		//ShowNumber2();
		ShowNumber1();
		   Show_Run();
		   Author2();
	// Show_ABC();
		   _getch();
	ShowStar();
	
	textcolor(7);
	cout << endl;
	system("pause");
	return 0;
}