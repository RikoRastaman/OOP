// triangle_test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "../triangle/CTriangle.h"
#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"

void checkTriangle(CTriangle triangle, double side1, double side2, double side3)
{
	REQUIRE((triangle.GetSide1() == side1));
	REQUIRE((triangle.GetSide2() == side2));
	REQUIRE((triangle.GetSide3() == side3));
}
TEST_CASE("Test_sides")
{
	checkTriangle(CTriangle(1, 2 , 3), 1, 2, 3);
}