#include "pch.h"
#include "../OOP/Rectangle.h"
#include "../OOP/Rectangle.cpp"
#include "../OOP/Vertices.h"
#include "../OOP/Vertices.cpp"

TEST(RectangleTest, DefaultConstructor) {
    Rectangle rect;
    Vertices vertLLow = rect.GetVertLLow();
    Vertices vertRUpper = rect.GetVertRUpper();

    EXPECT_EQ(vertLLow.x, 0);
    EXPECT_EQ(vertLLow.y, 0);
    EXPECT_EQ(vertRUpper.x, 1);
    EXPECT_EQ(vertRUpper.y, 1);
}

TEST(RectangleTest, ParamConstructor) {
    Vertices vertA = { 2, 3 };
    Vertices vertB = { 5, 6 };
    Rectangle rect(vertA, vertB);

    EXPECT_EQ(rect.GetVertLLow().x, 2);
    EXPECT_EQ(rect.GetVertLLow().y, 3);
    EXPECT_EQ(rect.GetVertRUpper().x, 5);
    EXPECT_EQ(rect.GetVertRUpper().y, 6);
}

TEST(RectangleTest, InvalidConstructor) {
    Vertices vertA = { 5, 6 };
    Vertices vertB = { 2, 3 };

    EXPECT_THROW(Rectangle rect(vertA, vertB), std::invalid_argument);
}

TEST(RectangleTest, SetVertLLowValid) {
    Rectangle rect({ 0, 0 }, { 5, 5 });
    Vertices newLLow = { 1, 1 };
    rect.SetVertLLow(newLLow);

    EXPECT_EQ(rect.GetVertLLow().x, 1);
    EXPECT_EQ(rect.GetVertLLow().y, 1);
}

TEST(RectangleTest, SetVertLLowInvalid) {
    Rectangle rect({ 0, 0 }, { 5, 5 });
    Vertices invalidLLow = { 6, 6 };

    EXPECT_THROW(rect.SetVertLLow(invalidLLow), std::invalid_argument);
}

TEST(RectangleTest, SetVertRUpperValid) {
    Rectangle rect({ 0, 0 }, { 5, 5 });
    Vertices newRUpper = { 6, 6 };
    rect.SetVertRUpper(newRUpper);

    EXPECT_EQ(rect.GetVertRUpper().x, 6);
    EXPECT_EQ(rect.GetVertRUpper().y, 6);
}

TEST(RectangleTest, SetVertRUpperInvalid) {
    Rectangle rect({ 0, 0 }, { 5, 5 });
    Vertices invalidRUpper = { -1, -1 };

    EXPECT_THROW(rect.SetVertRUpper(invalidRUpper), std::invalid_argument);
}

TEST(RectangleTest, Move) {
    Rectangle rect({ 0, 0 }, { 5, 5 });
    rect.Move(2, 3);

    EXPECT_EQ(rect.GetVertLLow().x, 2);
    EXPECT_EQ(rect.GetVertLLow().y, 3);
    EXPECT_EQ(rect.GetVertRUpper().x, 7);
    EXPECT_EQ(rect.GetVertRUpper().y, 8);
}

TEST(RectangleTest, ResizeValid) {
    Rectangle rect({ 0, 0 }, { 5, 5 });
    rect.Resize(10, 15);

    EXPECT_EQ(rect.GetVertRUpper().x, 10);
    EXPECT_EQ(rect.GetVertRUpper().y, 15);
}

TEST(RectangleTest, ResizeInvalid) {
    Rectangle rect({ 0, 0 }, { 5, 5 });

    EXPECT_THROW(rect.Resize(0, -5), std::invalid_argument);
}

TEST(RectangleTest, PrefixIncrementOperator) {
    Rectangle rect({ 0, 0 }, { 5, 5 });
    ++rect;

    EXPECT_EQ(rect.GetVertRUpper().x, 6);
    EXPECT_EQ(rect.GetVertRUpper().y, 6);
}

TEST(RectangleTest, PostfixIncrementOperator) {
    Rectangle rect({ 0, 0 }, { 5, 5 });
    rect++;

    EXPECT_EQ(rect.GetVertRUpper().x, 6);
    EXPECT_EQ(rect.GetVertRUpper().y, 6);
}

TEST(RectangleTest, PrefixDecrementOperatorValid) {
    Rectangle rect({ 0, 0 }, { 5, 5 });
    --rect;

    EXPECT_EQ(rect.GetVertRUpper().x, 4);
    EXPECT_EQ(rect.GetVertRUpper().y, 4);
}

TEST(RectangleTest, PrefixDecrementOperatorInvalid) {
    Rectangle rect({ 0, 0 }, { 1, 1 });

    EXPECT_THROW(--rect, std::invalid_argument);
}

TEST(RectangleTest, PostfixDecrementOperatorValid) {
    Rectangle rect({ 0, 0 }, { 5, 5 });
    rect--;

    EXPECT_EQ(rect.GetVertRUpper().x, 4);
    EXPECT_EQ(rect.GetVertRUpper().y, 4);
}

TEST(RectangleTest, PostfixDecrementOperatorInvalid) {
    Rectangle rect({ 0, 0 }, { 1, 1 });

    EXPECT_THROW(rect--, std::invalid_argument);
}

TEST(RectangleTest, AdditionOperator) {
    Rectangle rect1({ 0, 0 }, { 3, 3 });
    Rectangle rect2({ 2, 2 }, { 5, 5 });
    Rectangle result = rect1 + rect2;

    EXPECT_EQ(result.GetVertLLow().x, 0);
    EXPECT_EQ(result.GetVertLLow().y, 0);
    EXPECT_EQ(result.GetVertRUpper().x, 5);
    EXPECT_EQ(result.GetVertRUpper().y, 5);
}

TEST(RectangleTest, SelfAdditionOperator) {
    Rectangle rect1({ 0, 0 }, { 3, 3 });
    Rectangle rect2({ 2, 2 }, { 5, 5 });
    rect1 += rect2;

    EXPECT_EQ(rect1.GetVertLLow().x, 0);
    EXPECT_EQ(rect1.GetVertLLow().y, 0);
    EXPECT_EQ(rect1.GetVertRUpper().x, 5);
    EXPECT_EQ(rect1.GetVertRUpper().y, 5);
}

TEST(RectangleTest, SubtractionOperatorValid) {
    Rectangle rect1({ 0, 0 }, { 5, 5 });
    Rectangle rect2({ 2, 2 }, { 4, 4 });
    Rectangle result = rect1 - rect2;

    EXPECT_EQ(result.GetVertLLow().x, 2);
    EXPECT_EQ(result.GetVertLLow().y, 2);
    EXPECT_EQ(result.GetVertRUpper().x, 4);
    EXPECT_EQ(result.GetVertRUpper().y, 4);
}

TEST(RectangleTest, SubtractionOperatorInvalid) {
    Rectangle rect1({ 0, 0 }, { 1, 1 });
    Rectangle rect2({ 2, 2 }, { 4, 4 });

    EXPECT_THROW(rect1 - rect2, std::invalid_argument);
}

TEST(RectangleTest, SelfSubtractionOperatorValid) {
    Rectangle rect1({ 0, 0 }, { 5, 5 });
    Rectangle rect2({ 2, 2 }, { 4, 4 });
    rect1 -= rect2;

    EXPECT_EQ(rect1.GetVertLLow().x, 2);
    EXPECT_EQ(rect1.GetVertLLow().y, 2);
    EXPECT_EQ(rect1.GetVertRUpper().x, 4);
    EXPECT_EQ(rect1.GetVertRUpper().y, 4);
}

TEST(RectangleTest, SelfSubtractionOperatorInvalid) {
    Rectangle rect1({ 0, 0 }, { 1, 1 });
    Rectangle rect2({ 2, 2 }, { 4, 4 });

    EXPECT_THROW(rect1 -= rect2, std::invalid_argument);
}

