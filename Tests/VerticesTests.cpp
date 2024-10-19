#include "pch.h"
#include "../OOP/Vertices.h"
#include "../OOP/Vertices.cpp"

TEST(VerticesTest, DefaultCreation) 
{
	Vertices vert;
	EXPECT_EQ(vert.x, 0);
	EXPECT_EQ(vert.y, 0);
}

TEST(VerticesTest, ParameterizedCreation)
{
	Vertices vert(10,12);
	EXPECT_EQ(vert.x, 10);
	EXPECT_EQ(vert.y, 12);
}

TEST(VerticesTest, CopyCreation)
{
	Vertices vert1(2, 4);
	Vertices vert2(vert1);
	EXPECT_EQ(vert1.x, vert2.x);
	EXPECT_EQ(vert1.y, vert2.y);
}
