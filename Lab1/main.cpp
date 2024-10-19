#include <iostream>
#include "Rectangle.h"
#include "Menu.h"

int main()
{
	Rectangle rect1, rect2;
	bool validRect1 = false, validRect2 = false;
	while (!validRect1)
	{
		try
		{
			std::cout << "\nFirst rectangle creation:\n";
			Vertices leftBot, rightTop;
			std::cout << "\nEnter Left Bottom vertex coordinates (x y):\t ";
			std::cin >> leftBot.x >> leftBot.y;
			std::cout << "\nEnter Right Top vertex coordinates (x y):\t ";
			std::cin >> rightTop.x >> rightTop.y;
			rect1 = Rectangle(leftBot, rightTop);
			validRect1 = true;
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << e.what() << "\nPlease enter valid coordinates again.\n";
		}
	}

	while (!validRect2)
	{
		try
		{
			std::cout << "\nSecond rectangle creation:\n";
			Vertices leftBot, rightTop;
			std::cout << "\nEnter Left Bottom vertex coordinates (x y):\t ";
			std::cin >> leftBot.x >> leftBot.y;
			std::cout << "\nEnter Right Top vertex coordinates (x y):\t ";
			std::cin >> rightTop.x >> rightTop.y;
			rect2 = Rectangle(leftBot, rightTop);
			validRect2 = true;
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << e.what() << "\nPlease enter valid coordinates again.\n";
		}
	}

	Menu menu(rect1, rect2);
	menu.Run();
}