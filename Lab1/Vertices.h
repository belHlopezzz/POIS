#pragma once

class Vertices
{
public:
	int x, y;

	Vertices(int x = 0, int y = 0);

	Vertices(const Vertices& copyVert);
};