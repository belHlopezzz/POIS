#pragma once
#include "Vertices.h"

class Rectangle
{
private:
	Vertices m_vertLLow, m_vertRUpper; // vertLLow - Left Low && vertRUpper - Rigth Upper

private:
	bool ValidateVertices(const Vertices&, const Vertices&) const;

public:
	Rectangle(const Vertices&, const Vertices&);

	Rectangle(const Rectangle&);

	Rectangle();

	Vertices GetVertLLow() const;

	Vertices GetVertRUpper() const;

	void SetVertLLow(const Vertices&);

	void SetVertRUpper(const Vertices&);

	void Move(int difX = 0, int difY = 0);

	void Resize(int width = 1, int height = 1);

	Rectangle& operator++();

	Rectangle operator++(int);

	Rectangle& operator--();

	Rectangle operator--(int);

	Rectangle operator+(const Rectangle&) const;

	Rectangle& operator+=(const Rectangle&);

	Rectangle operator-(const Rectangle&) const;

	Rectangle& operator-=(const Rectangle&);
};
