#include "Header.h"

void SetColorBgTex(int Bg = 0, int Tex = 15)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Bg = Bg << 4 | Tex;
	SetConsoleTextAttribute(hConsole, Bg);
}
