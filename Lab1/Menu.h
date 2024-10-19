#pragma once
#include "Rectangle.h"
#include <iostream>

class Menu
{
private:
	Rectangle& rect1;
	Rectangle& rect2;

	void DisplayMenu();

	Rectangle& ChooseRectangle();

	void Draw(const Rectangle& rect);

	void ProcessRectangleOperations(void (Rectangle::* function)(int, int), int x, int y);

	void ProcessRectangleOperations(Rectangle& (Rectangle::* function)());

public:
	Menu() = delete;
	Menu(Menu& menu) = delete;
	Menu(Rectangle& rect1, Rectangle& rect2);

	void Run();
};
