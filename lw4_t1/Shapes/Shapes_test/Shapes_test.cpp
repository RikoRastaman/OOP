#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"

#include "../Shapes/Triangle.h"
#include "../Shapes/Circle.h"
#include "../Shapes/Rectangle.h"
#include "../Shapes/LineSegment.h"
#include "../Shapes/ConsoleMenu.h"

void CheckCoordinates(SPoint const & currentCoordinates, SPoint const & correctCoordinates)
{
	CHECK((currentCoordinates.x == correctCoordinates.x));
	CHECK((currentCoordinates.y == correctCoordinates.y));
}

TEST_CASE("Create large triangle")
{
	const SPoint vertex1 = { 0, 0 };
	const SPoint vertex2 = { 0, 100000000000 };
	const SPoint vertex3 = { 100000000000, 100000000000 };
	const std::string outlineColor = "000000";
	const std::string fillColor = "FFFFFF";
	const CTriangle triangle(vertex1, vertex2, vertex3, outlineColor, fillColor);
	CHECK(std::round(triangle.GetPerimeter()) == 341421356237.0);
}

TEST_CASE("Create zero triangle")
{
	const SPoint vertex1 = { 0, 0 };
	const SPoint vertex2 = { 0, 0 };
	const SPoint vertex3 = { 0, 0 };
	const std::string outlineColor = "000000";
	const std::string fillColor = "FFFFFF";
	const CTriangle triangle(vertex1, vertex2, vertex3, outlineColor, fillColor);
	CHECK(triangle.GetPerimeter() == 0);
}

TEST_CASE("triangle")
{
	const SPoint vertex1 = { 1, 1 };
	const SPoint vertex2 = { 1, 4 };
	const SPoint vertex3 = { 5, 1 };
	const std::string outlineColor = "000000";
	const std::string fillColor = "FFFFFF";
	const CTriangle triangle(vertex1, vertex2, vertex3, outlineColor, fillColor);

	SECTION("has_vertexes")
	{

		CheckCoordinates(triangle.GetVertex1(), vertex1);
		CheckCoordinates(triangle.GetVertex2(), vertex2);
		CheckCoordinates(triangle.GetVertex3(), vertex3);

	}

	SECTION("has_colours")
	{
		CHECK((triangle.GetFillColor() == fillColor));
		CHECK((triangle.GetOutlineColor() == outlineColor));
	}

	SECTION("can_find_perimeter")
	{
		CHECK((triangle.GetPerimeter() == 12));
	}

	SECTION("can_find_area")
	{
		CHECK(triangle.GetArea() == 6);
	}

	SECTION("can_get_name")
	{
		CHECK(triangle.GetName() == "triangle");
	}

	SECTION("can_get_special_info")
	{
		CHECK(triangle.GetSpecialInfo() == "Vertex 1 (1.00, 1.00)Vertex 2 (1.00, 4.00)Vertex 3 (5.00, 1.00)Fill color = #FFFFFF");
	}
}

TEST_CASE("Rectangle")
{
	const SPoint leftTopVertex = { 0, 0 };
	const double width = 10;
	const double height = 20;
	const std::string outlineColor = "000000";
	const std::string fillColor = "FFFFFF";
	CRectangle rectangle(leftTopVertex, width, height, outlineColor, fillColor);

	SECTION("has vertexes")
	{
		CheckCoordinates(rectangle.GetLeftTop(), leftTopVertex);
		CheckCoordinates(rectangle.GetRightBottom(), { leftTopVertex.x + width, leftTopVertex.y + height });
	}

	SECTION("high width")
	{
		CHECK(rectangle.GetWidth() == width);
		CHECK(rectangle.GetHeight() == height);
	}

	SECTION("has_colours")
	{
		CHECK((rectangle.GetFillColor() == fillColor));
		CHECK((rectangle.GetOutlineColor() == outlineColor));
	}

	SECTION("perimeter area")
	{
		CHECK(rectangle.GetPerimeter() == 60);
		CHECK(rectangle.GetArea() == 200);
	}

	SECTION("has name and info")
	{
		CHECK(rectangle.GetName() == "rectangle");
		CHECK(rectangle.GetSpecialInfo() == "Left top point (0.00, 0.00)Right bottom point(10.00, 20.00) Width = 10.00 Height = 20.00Fill color = #FFFFFF");
	}
}

TEST_CASE("Circle")
{
	const SPoint center = { 0, 0 };
	const double radius = 10;
	const std::string outlineColor = "000000";
	const std::string fillColor = "FFFFFF";
	CCircle circle(center, radius, outlineColor, fillColor);

	SECTION("check center")
	{
		CheckCoordinates(circle.GetCenter(), center);
	}

	SECTION("check radius")
	{
		CHECK(circle.GetRadius() == radius);
	}

	SECTION("check colours")
	{
		CHECK((circle.GetFillColor() == fillColor));
		CHECK((circle.GetOutlineColor() == outlineColor));
	}

	SECTION("can measure perimeter and area")
	{
		CHECK(static_cast<int>(circle.GetPerimeter()) == 62);
		CHECK(static_cast<int>(circle.GetArea()) == 314);
	}

	SECTION("get name and info")
	{
		CHECK(circle.GetName() == "circle");
		CHECK(circle.GetSpecialInfo() == "Center (0.00, 0.00) Radius = 10.00Fill color = #FFFFFF");
	}
}

TEST_CASE("LineSegment")
{
	const SPoint startPoint = { 0, 0 };
	const SPoint endPoint = { 1, 1 };
	const std::string outlineColor = "000000";
	CLineSegment line(startPoint, endPoint, outlineColor);

	SECTION("line segment start, end points")
	{
		CheckCoordinates(line.GetStartPoint(), startPoint);
		CheckCoordinates(line.GetEndPoint(), endPoint);
	}

	SECTION("has_outline_color")
	{
		CHECK(line.GetOutlineColor() == outlineColor);
	}

	SECTION("get perimetr and area")
	{
		CHECK(static_cast<int>(line.GetPerimeter()) == 1);
		CHECK(line.GetArea() == 0);
	}

	SECTION("can get name and info")
	{
		CHECK(line.GetName() == "line");
		CHECK(line.GetSpecialInfo() == "Start point (0.00, 0.00)End point (1.00, 1.00)");
	}
}

TEST_CASE("menu")
{
	std::stringstream In("rectangle 0 0 10 10 ffffff ffffff");
	std::stringstream Out;
	CConsoleMenu menu;

	menu.RunCommand(In, Out);

	CHECK(Out.str() == "Rectangle was created\n\n");

}