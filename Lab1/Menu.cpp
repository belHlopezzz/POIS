#include "Menu.h"
#include <iostream>

void Menu::DisplayMenu()
{
	std::cout << "\n--- Menu ---\n";
	std::cout << "1. Move Rectangles\n";
	std::cout << "2. Resize Rectangles\n";
	std::cout << "3. Increment Rectangles\n";
	std::cout << "4. Decrement Rectangles\n";
	std::cout << "5. Add Rectangles\n";
	std::cout << "6. Subtract Rectangles\n";
	std::cout << "7. Draw Rectangles\n";
	std::cout << "0. Exit\n";
	std::cout << "Choose an option: ";
}

Rectangle& Menu::ChooseRectangle()
{
	int choice;
	std::cout << "\nChoose rectangle (1 or 2):\t";
	std::cin >> choice;
	if (choice == 1)
		return rect1;
	else if (choice == 2)
		return rect2;
	else
		throw std::invalid_argument("\nInvalid rectangle choice.\n\n");
}

void Menu::Draw(const Rectangle& rect)
{
	std::cout << "\n(" << rect.GetVertLLow().x << ", " << rect.GetVertRUpper().y << ")\t";
	std::cout << "(" << rect.GetVertRUpper().x << ", " << rect.GetVertRUpper().y << ")\n";
	std::cout << "(" << rect.GetVertLLow().x << ", " << rect.GetVertLLow().y << ")\t";
	std::cout << "(" << rect.GetVertRUpper().x << ", " << rect.GetVertLLow().y << ")\n";
}

void Menu::ProcessRectangleOperations(void (Rectangle::* function)(int, int), int x, int y)
{
	try
	{
		Rectangle& rect = ChooseRectangle();
		try
		{
			(rect.*function)(x, y);
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Menu::ProcessRectangleOperations(Rectangle& (Rectangle::* function)())
{
	Rectangle& rect = ChooseRectangle();
	try
	{
		(rect.*function)();
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << e.what() << std::endl;
	}
}


Menu::Menu(Rectangle& rect1, Rectangle& rect2)
	:rect1(rect1), rect2(rect2) {}

void Menu::Run()
{
	int option;
	do
	{
		DisplayMenu();
		std::cin >> option;
		switch (option)
		{
		case 1:
			int difX, difY;
			std::cout << "\nEnter difference X and Y (dx dy)" << std::endl;
			std::cin >> difX >> difY;
			ProcessRectangleOperations(&Rectangle::Move, difX, difY);
			break;
		case 2:
			int width, height;
			std::cout << "\nEnter width and height (width > 0 and height > 0)" << std::endl;
			std::cin >> width >> height;
			ProcessRectangleOperations(&Rectangle::Resize, width, height);
			break;
		case 3:
			ProcessRectangleOperations(&Rectangle::operator++);
			break;
		case 4:
			ProcessRectangleOperations(&Rectangle::operator--);
			break;
		case 5:
		{
			Rectangle rect3 = rect1 + rect2;
			Draw(rect3);
		}
		break;
		case 6:
		{
			try
			{
				Rectangle rect3 = rect1 - rect2;
				Draw(rect3);
			}
			catch (const std::invalid_argument& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		break;
		case 7:
			try
			{
				Draw(ChooseRectangle());
			}
			catch (const std::invalid_argument& e)
			{
				std::cerr << e.what() << std::endl;
			}
			break;
		case 0:
			std::cout << "\nExiting...\n";
			return;
		default:
			std::cout << "\nInvalid choice.\n\n";
			break;
		}
	} while (option != 0);
}
