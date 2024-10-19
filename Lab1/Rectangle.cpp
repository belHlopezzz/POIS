#include "Rectangle.h"
#include <iostream>
#include <algorithm>

bool Rectangle::ValidateVertices(const Vertices& vert1, const Vertices& vert2) const
{
	return (vert1.x < vert2.x && vert1.y < vert2.y);
}

Rectangle::Rectangle(const Vertices& vertA, const Vertices& vertB)
{
	if (!ValidateVertices(vertA, vertB))
	{
		throw std::invalid_argument("Invalid rectangle vertex coordinates.\n");
	}
	m_vertLLow = vertA;
	m_vertRUpper = vertB;
}

Rectangle::Rectangle(const Rectangle& copyRect)
	: m_vertLLow(copyRect.m_vertLLow), m_vertRUpper(copyRect.m_vertRUpper) {}

Rectangle::Rectangle()
{
	m_vertLLow.x = 0;
	m_vertLLow.y = 0;
	m_vertRUpper.x = 1;
	m_vertRUpper.y = 1;
}

Vertices Rectangle::GetVertLLow() const
{
	return m_vertLLow;
}

Vertices Rectangle::GetVertRUpper() const
{
	return m_vertRUpper;
}

void Rectangle::SetVertLLow(const Vertices& vert)
{
	if (!ValidateVertices(vert, m_vertRUpper))
	{
		throw std::invalid_argument("Invalid resizing: the bottom left corner must be smaller than the top right.\n");
	}
	m_vertLLow = vert;
}

void Rectangle::SetVertRUpper(const Vertices& vert)
{
	if (!ValidateVertices(m_vertLLow, vert))
	{
		throw std::invalid_argument("Invalid resizing: the bottom left corner must be smaller than the top right.\n");
	}
	m_vertRUpper = vert;
}

void Rectangle::Move(int difX, int difY)
{
	m_vertLLow.x += difX;
	m_vertLLow.y += difY;
	m_vertRUpper.x += difX;
	m_vertRUpper.y += difY;
}

void Rectangle::Resize(int width, int height)
{
	if (width <= 0 || height <= 0)
	{
		throw std::invalid_argument("Invalid width or height.\n");
	}
	m_vertRUpper.x = m_vertLLow.x + width;
	m_vertRUpper.y = m_vertLLow.y + height;
}

Rectangle& Rectangle::operator++()
{
	m_vertRUpper.x++;
	m_vertRUpper.y++;
	return *this;
}

Rectangle Rectangle::operator++(int) {
	Rectangle temp = *this;
	++(*this);
	return temp;
}

Rectangle& Rectangle::operator--()
{
	Vertices temp = { m_vertRUpper.x - 1, m_vertRUpper.y - 1 };
	if (!ValidateVertices(m_vertLLow, temp))
	{
		throw std::invalid_argument("Invalid decrement: the bottom left corner must be smaller than the top right.\n");
	}
	m_vertRUpper.x--;
	m_vertRUpper.y--;
	return *this;
}

Rectangle Rectangle::operator--(int)
{
	Rectangle temp = *this;
	--(*this);
	return temp;
}

Rectangle Rectangle::operator+(const Rectangle& rect) const
{
	int newLLowX = std::min(rect.m_vertLLow.x, m_vertLLow.x);
	int newLLowY = std::min(rect.m_vertLLow.y, m_vertLLow.y);
	int newRUpperX = std::max(rect.m_vertRUpper.x, m_vertRUpper.x);
	int newRUpperY = std::max(rect.m_vertRUpper.y, m_vertRUpper.y);

	return Rectangle(Vertices(newLLowX, newLLowY), Vertices(newRUpperX, newRUpperY));
}

Rectangle& Rectangle::operator+=(const Rectangle& rect)
{
	*this = *this + rect;
	return *this;
}

Rectangle Rectangle::operator-(const Rectangle& rect) const
{
	int newLLowX = std::max(rect.m_vertLLow.x, m_vertLLow.x);
	int newLLowY = std::max(rect.m_vertLLow.y, m_vertLLow.y);
	int newRUpperX = std::min(rect.m_vertRUpper.x, m_vertRUpper.x);
	int newRUpperY = std::min(rect.m_vertRUpper.y, m_vertRUpper.y);

	if (newLLowX >= newRUpperX || newLLowY >= newRUpperY) {
		throw std::invalid_argument("Rectangles do not intersect.");
	}

	return Rectangle(Vertices(newLLowX, newLLowY), Vertices(newRUpperX, newRUpperY));
}

Rectangle& Rectangle::operator-=(const Rectangle& rect)
{
	*this = *this - rect;
	return *this;
}
