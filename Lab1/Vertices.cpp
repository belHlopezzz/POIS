#include "Vertices.h"

Vertices::Vertices(int x, int y)
	: x(x), y(y) {}

Vertices::Vertices(const Vertices& copyVert)
	: x(copyVert.x), y(copyVert.y) {}
