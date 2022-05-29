#include <iostream>
#include <conio.h> 
#include <string>
#include <algorithm>
#include <windows.h> 
#include <cstdlib>
#include <fstream> 
#include <time.h>       /* time */
#include "MyWindows.h";

using namespace std;

#define WIDTH  95
#define HEIGHT 25

#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED				4
#define MAGENTA			5
#define BROWN			6
#define LIGHTGRAY		7
#define DARKGRAY		8
#define LIGHTBLUE		9
#define LIGHTGREEN		10
#define LIGHTCYAN		11
#define LIGHTRED		12
#define LIGHTMAGENTA	13
#define YELLOW			14
#define WHITE			15
   
void swapByPointer(int* x, int* y) // pass by pointer
{
	int temp = *x;
	*x = *y;
	*y = temp;
};
void drawArray(MyWindows console, int *a, int w, int size, int left) {
	for (int k = 0; k < size; k++)
	{
		int color = a[k] % 15;
		if (color == BLUE) color = BLACK;


		MyWindows redraw(left + w * k, 1, w - 1, HEIGHT - 4, BLUE, BLUE);
		redraw.clearConsole();
		redraw.drawFrame();
		MyWindows c1(left + w * k, HEIGHT - 4 - a[k], w - 1, a[k], color, WHITE);
		c1.clearConsole();
		c1.drawFrame();
		console.Write("", left + w * k, HEIGHT - 3, BLUE, WHITE);
	}
} 

int main()
{
	/* initialize random seed: */
	srand(time(NULL));

	MyWindows console(0, 0, WIDTH, HEIGHT, BLUE, WHITE);
	console.clearConsole();
	console.drawFrame();
	console.Write(" Bubble Sort ", 2, 0, BLUE, WHITE);


	int a[16] = {};
	int size = sizeof(a) / sizeof(a[0]);

	for (int i = 0; i < size; i++)
	{
		a[i] = (rand() % (HEIGHT - 6)) + 2; // 1 to 20
	} 

	// rectangle's width
	int w = 3;
	// start of main screen
	int left = (WIDTH - (w * size)) / 2;
	console.Write(to_string(size), 80, 0, BLUE, WHITE);
	drawArray(console, a, w, size, left); 
	// bubble sort  
	for (int i = 0; i < size - 1; i++)
	{ 
		for (int j = 0; j < size - 1 - i; j++)
		{
			for (int k = 0; k < size; k++)
			{
				console.Write("  ", left + w * k, HEIGHT - 2, BLUE, WHITE);
			}
			console.Write("L", left + w * j, HEIGHT - 2, RED, WHITE);
			console.Write("R", left + w * (j + 1), HEIGHT - 2, RED, WHITE);
			if (a[j] > a[j + 1]) {
				swapByPointer(&a[j], &a[j + 1]); 
				drawArray(console, a, w, size, left); 
			}
			console.Write("L", left + w * j, HEIGHT - 2, RED, WHITE);
			console.Write("R", left + w * (j + 1), HEIGHT - 2, RED, WHITE);
			Sleep(1000);
		}
		for (int j = size - 1 - i; j < size; j++)
		{
			console.Write(to_string(a[j]) + " ", left + w * j, HEIGHT - 3, RED, WHITE);
		}
		Sleep(2000);
	}  
	console.Write(to_string(a[0]) + " ", left, HEIGHT - 3, RED, WHITE);
	console.Write("   ", left, HEIGHT - 2, BLUE, WHITE);
	console.Write("   ", left + w, HEIGHT - 2, BLUE, WHITE);
	console.Write("DONE", (WIDTH - 6) / 2, HEIGHT - 2, BLUE, WHITE);
	char c = _getch();
}
 

