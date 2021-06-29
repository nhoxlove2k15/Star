#include<iostream>
#include<Windows.h>
#include<string>
#include<conio.h>
#pragma comment (lib, "winmm.lib")
using namespace std;
int WindowWidth = 120;
int WindowHeight = 40;
char ch = char(3);
void Print_String_First(string stuff, int width, int height, int color, int timeMotion , int timeSleep );
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

// generally
void Show_Small_Start(char SmallStar1[15][30], int a, int b); 
void Show_Big_Star(char BigStar[37][48], int x, int y);
void Print_Multi_Character(char ch);
void Print_String_First(string stuff, int width, int height, int color, int timeMotion = 0, int timeSleep = 0);


// Flow

void ShowString_frist(string date, string content);
void Author(int sizeContent, int width, int height, int color, int timeMotion);
//
void Show_Run(string tiltle, int colorTitle, int timeMotion);
//
void ShowNumber();
void ShowNumberConfig(char number[9][15], int width, int height, int color, int timeMotion);
//
void Author2(int width, int height, int color, int timeMotion);
void ShowString_second();
// 
void ShowStar();
void ShowString_third();
void Show_Quote();
void Print_Map(int max_x, int max_y);
void End();


// Define 
void Show_Run(string tiltle, int colorTitle, int timeMotion) {
	int a = WindowWidth / 4 - 10, b = 0;
	int t;
	textcolor(colorTitle);
	if (tiltle.size() < 30) gotoxy(WindowWidth / 4 + 28, WindowHeight / 4);
	else gotoxy(WindowWidth / 4 + 18, WindowHeight / 4);


	cout << tiltle;
	while (!_kbhit())
	{
		if (b < (WindowHeight / 2))
		{
			gotoxy(a, b);
			t = rand() % 15 + 1;
			textcolor(t);
			Print_Multi_Character(ch);

			Sleep(timeMotion);
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
				Print_Multi_Character(ch);
				Sleep(timeMotion);
				gotoxy(WindowWidth - 20, b);
				cout << "                          "; // BAO NHIU KÍ TỰ THÌ BẤY NHIÊU KHOẢNG CÁCH .
				b--;
			}
		}
	}
	clrscr();
	// Sleep(1000);

}

void ShowString_frist(string date, string content)
{
	string wrongMusic = "Mario_Game_Over.wav";
	string rightMusic = "InLove.wav";
	string stuff = "";
	/////////////////////
	Print_String_First(date, WindowWidth / 3, WindowHeight / 2, 13, 100, 0);

	Print_String_First(content, WindowWidth / 3 - 15, WindowHeight / 2 + 1, 13, 100, 0);

	Author(content.size(), WindowWidth / 3 - 5, WindowHeight / 2 - 5, 11, 75);
	clrscr();
	Sleep(1000);
	////////////////////////////
	stuff = "Let music begin";
	Print_String_First(stuff, WindowWidth / 3, WindowHeight / 2, 13, 0, 2000);

	PlaySound(wrongMusic.c_str(), NULL, SND_ASYNC);
	clrscr();

	stuff = "Not Mario . Wrong sound , My fauft!";
	Print_String_First(stuff, WindowWidth / 3, WindowHeight / 2, 10, 0, 500);
	/////////////////////////////
	stuff = " Now try again ! ";
	Print_String_First(stuff, WindowWidth / 3 + 5, WindowHeight / 2 + 1, 14, 300, 1500);

	PlaySound(rightMusic.c_str(), NULL, SND_ASYNC);

	//////////////////////////////
	clrscr();
	stuff = "Perfect!";
	Print_String_First(stuff, WindowWidth / 3, WindowHeight / 2 + 1, 10, 0, 2000);
	///////////////////////
	stuff = "Now I have a surprise for U";
	Print_String_First(stuff, WindowWidth / 3, WindowHeight / 2 + 1, 13, 250, 1500);

	clrscr();

}

void Author(int sizeContent, int width, int height, int color, int timeMotion)
{
	textcolor(color);
	// muc tieu xoa : x = 30 , y = 15 ;

	int x = width, y = height;
	int timee = timeMotion;
	string title = "Hello ! I'm Dy Dy. My Job is to make U happy";
	gotoxy(x, y - 2);
	cout << title;
	gotoxy(WindowWidth / 3 - 15, WindowHeight / 2 + 1);
	while (x > WindowWidth / 6)
	{
		gotoxy(x, y);
		cout << " " << ch << " ";
		x--;
		Sleep(timee);
	}
	while (y < WindowHeight / 2)
	{
		gotoxy(x, y);
		cout << " " << ch << " ";
		Sleep(timee);
		gotoxy(x, y);
		cout << "   ";
		y++;

	}
	while (x < width + sizeContent)
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

void ShowNumberConfig(char number[9][15], int width, int height, int color, int timeMotion) {
	textcolor(color);
	int y = WindowHeight / 2;
	int x = width + 5;
	for (int i = 0; i < 9; i++)
	{
		gotoxy(x, y);
		cout << number[i];
		y++;
	}

	Sleep(timeMotion);
	clrscr();
}
void ShowNumber()
{
	textcolor(10);
	gotoxy(WindowWidth / 3, WindowHeight / 2);
	cout << "Let count on 10 seconds";
	Sleep(1000);
	clrscr();
	int t;
	t = rand() % 15 + 1;
	textcolor(t);
	int y;
	y = WindowHeight / 2;
	int x = WindowWidth / 3 + 5;
	for (int i = 0; i < 9; i++)
	{

		gotoxy(x, y);
		cout << ten[i];
		y++;
	}

	Sleep(1700);
	clrscr();

	int count = 0;
	char number[9][15];
	while (count < 9) {
		t = rand() % 15 + 1;
		switch (count)
		{
		case 0: ShowNumberConfig(nine, WindowWidth / 3 + 5, WindowHeight / 2, t, 1700); break;
		case 1: ShowNumberConfig(eight, WindowWidth / 3 + 5, WindowHeight / 2, t, 1700); break;
		case 2: ShowNumberConfig(seven, WindowWidth / 3 + 5, WindowHeight / 2, t, 1700); break;
		case 3: ShowNumberConfig(six, WindowWidth / 3 + 5, WindowHeight / 2, t, 1700); break;
		case 4: ShowNumberConfig(five, WindowWidth / 3 + 5, WindowHeight / 2, t, 1700); break;
		case 5: ShowNumberConfig(four, WindowWidth / 3 + 5, WindowHeight / 2, t, 1700); break;
		case 6: ShowNumberConfig(three, WindowWidth / 3 + 5, WindowHeight / 2, t, 1700); break;
		case 7: ShowNumberConfig(two, WindowWidth / 3 + 5, WindowHeight / 2, t, 1700); break;
		case 8: ShowNumberConfig(one, WindowWidth / 3 + 5, WindowHeight / 2, t, 1700); break;
		default:
			break;
		}

		count++;
	}

}



void Author2(int width, int height, int color, int timeMotion)
{
	clrscr();
	textcolor(color);
	int x = width, y = height;
	string stuff = "";
	gotoxy(x - 15, y + 3);
	cout << " " << ch << " ";


	stuff = "   nani ???   ";
	Print_String_First(stuff, x, y, color, 0, 2000);
	stuff = "Why I am here ?";
	Print_String_First(stuff, x, y + 1, color, 0, 2000);

	for (int i = y; i < y + 2; i++)
	{
		gotoxy(x, y);
		cout << "               ";
	}
	stuff = " Wrong time to show up again ! ";
	Print_String_First(stuff, x, y, color, 0, 1000);
	stuff = "I'm getting out of here ";
	Print_String_First(stuff, x - 2, y + 1, color, 0, 1000);
	// xoa toa do dau` tien .
	gotoxy(x - 15, y + 3);
	cout << "   ";
	int a = x - 5;
	int b = y + 5;
	while (a < 50)
	{
		gotoxy(a, b);
		cout << " " << ch << " ";
		a++;
		Sleep(timeMotion);
	}
	while (b < 25)
	{
		gotoxy(a, b);
		cout << " " << ch << " ";
		Sleep(100);
		gotoxy(a, b);
		cout << "   ";
		b++;
	}

	while (a < WindowWidth)
	{
		gotoxy(a, b);
		cout << " " << ch << " ";
		a++;
		Sleep(timeMotion - 50);
	}

	clrscr();


	stuff = " Dy Dy will be back ";
	Print_String_First(stuff, x, y, color, 0, 1500);
}
void ShowString_second()
{
	clrscr();
	string a = "";
	string stuff = "";
	int y = WindowHeight / 2;
	int x = WindowWidth / 4 + 15;

	textcolor(13);

	a = "Be ready ! Close your eyes in 3 seconds";
	Print_String_First(a, x, y, 13, 100, 1000);

	textcolor(14);
	stuff = "Now open";
	int temp = WindowWidth;
	while (temp > WindowWidth - a.size() - x)
	{
		gotoxy(temp, y);
		cout << stuff;
		Sleep(75);
		gotoxy(temp, y);
		cout << "          ";
		temp--;

	}
	Sleep(1000);
	clrscr();

}



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



void Show_Quote() {
	int x = 0, y, a = WindowWidth / 2 + 15, b = 5;
	int max_x = 90;
	int max_y = 10;
	char ch = char(3);
	textcolor(10);
	// in chữ ở trên ngôi sao to ( bước cuối ).
	
		a = WindowWidth / 3-10; b = 4; // reset gia tri a , b 
		string temp = "Suddenly the big star has come and warm the sky";
		Print_String_First(temp , a , b , 10 , 75 , 0 );
		
		a = WindowWidth / 3  - 10;
		temp = " JustLike U come and drag me from the darkness ";
		Print_String_First(temp, a, b + 1, 10, 75, 1000);

		Print_Map(max_x, max_y);

		
}



//int height = 20;
//int width = 100;

void ShowString_third() {
	clrscr();

	string a = "There are many stars in the sky";
	Print_String_First(a, WindowWidth / 3, WindowHeight / 2, 13, 200, 0);

	a = "But they left me alone";
	Print_String_First(a, WindowWidth / 3 + 3, WindowHeight / 2 + 1, 15, 200, 2000);


	clrscr();


	a = "Now I feel empty and cold ";
	Print_String_First(a, WindowWidth / 3 + 3, WindowHeight / 2, 12, 100, 2000);
}
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
		Show_Run("this is end ! but music does not end ^^", 15, 100);
	}
	

}
void End() {
	clrscr();
	char string[12][500] = {
"_____*yeu*_*yeu*________*yeu*_*yeu*",
"___*yeu*______*yeu*_*yeu*_______*yeu*",
"__*yeu*__________*yeu*__________*yeu*",
"__*yeu*________________________*yeu*",
"___*yeu*________**Song**________*yeu*",
"____*yeu*____In Love-July____*yeu*",
"______*yeu*________________*yeu*",
"________*yeu*____________*yeu*",
"__________*yeu*________*yeu*",
"____________*yeu*____*yeu*",
"______________*yeu**yeu*",
">>>>>>>>>>>>>>>> *yeu* >>>>>>>>>>>>>>>> Thanks for watching" };
	int x = WindowWidth / 3;
	int y = WindowHeight / 3;
	int z = y -1 ;
	for (int i = 0; i < 12; i++) {
		gotoxy(x, y);
		int t = rand() % 15 + 1;
		textcolor(t);
		cout << string[i] << endl;
		y++;
		Sleep(200);


	}
	int len = 12;
	x = WindowWidth / 3;

	textcolor(10);
	int countt = 0;
	int i = 0;
	while (countt < 12) {
		clrscr();
		if (z <= 0) {
			countt++;
			
		}
		i = countt;
		gotoxy(0, 0);
		cout << i;
		for ( ; i < 12; i++) {
			
			gotoxy(x, z);
			cout << string[i] << endl;
			z++;
			
		}
		
		z = z - 13;
		Sleep(1000);
	}

	/*int countt = 0;
	int conditionn = 0;
	while (y + 11 > -24) {
		clrscr();
		

		for (int i = 11; i >= conditionn; i--) {

			gotoxy(x, y - 1);
			if (y - 1 <= 0) {
				cout << "                                                                                                    " << endl;

				countt++;
			}
			else cout << string[i] << endl;

			y--;

		}
		conditionn = countt;
		y = y + 11;
		Sleep(100);
	}*/
}

void Print_Map(int max_x, int max_y) {

	textcolor(11);
	// x = 20->90 ,  y = 0->18 ,
	int x = 20;  int y = 0;
	while (y <= max_y)
	{
		gotoxy(x, y);

		cout << ch;
		y++;
		Sleep(150);
	}
	y = max_y;
	gotoxy(5, y + 1);
	cout << " ? Left or Right ?";
	Sleep(3000);
	gotoxy(5, y + 1);
	cout << "                   ";
	gotoxy(5, y + 1);
	cout << "Ok ! Left";
	Sleep(2000);
	gotoxy(5, y + 1);
	cout << "                    ";
	while (x <= max_x)
	{
		gotoxy(x, y);

		cout << ch;
		x += 2;
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
		x -= 2;
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

}
void Print_String_First(string stuff, int width, int height, int color, int timeMotion , int timeSleep) {
	gotoxy(width, height);
	textcolor(color);
	for (int i = 0; i < stuff.size(); i++)
	{
		cout << stuff[i];
		Sleep(timeMotion);
	}
	Sleep(timeSleep);
}
void Print_Multi_Character(char ch) {
	cout << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch;
}


int main()
{
	while(!_kbhit()){}
	_getch();
	/*
	ShowString_frist("June 28 , 2021", "Hi Quynh Anh , the girl with cuteness and her beautiful name");
	Show_Run("Welcome to the show !!!" , 15 , 100);
	ShowNumber();
	Author2(WindowWidth / 4 + 10 , WindowHeight / 2 - 5 , 11 , 100);
	ShowString_second();
	ShowStar();
	*/
	End();

	cout << endl;
	system("pause");
	return 0;
}