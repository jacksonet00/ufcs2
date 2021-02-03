#include <iostream>
#include "Shapes.h"
using namespace std;

#define PI 3.14159f

/*==== Shape ====*/

Shape::~Shape()
{

}

/*==== Shape2D ====*/

Shape2D::~Shape2D()
{

}

void Shape2D::ShowArea() const
{
	cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
}

bool Shape2D::operator>(const Shape2D& rhs) const
{
	return (Area() > rhs.Area());
}

bool Shape2D::operator<(const Shape2D& rhs) const
{
	return (Area() < rhs.Area());
}

bool Shape2D::operator==(const Shape2D& rhs) const
{
	return (Area() == rhs.Area());
}

/*==== Shape3D ====*/

Shape3D::~Shape3D()
{

}

void Shape3D::ShowVolume() const
{
	cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
}

bool Shape3D::operator>(const Shape3D& rhs) const
{
	return (Volume() > rhs.Volume());
}

bool Shape3D::operator<(const Shape3D& rhs) const
{
	return (Volume() < rhs.Volume());
}

bool Shape3D::operator==(const Shape3D& rhs) const
{
	return (Volume() == rhs.Volume());
}

/*==== Square ====*/

Square::Square(float l)
{
	length = l;
}

void Square::Scale(float scaleFactor)
{
	length *= scaleFactor;
}

void Square::Display() const
{
	cout << "The area of the Square is : " << Area() << endl;
	cout << "Length of a side: " << length << endl;
}

float Square::Area() const
{
	return (length * length);
}

string Square::GetName2D() const
{
	return "Square";
}

/*==== Triangle ====*/

Triangle::Triangle(float b, float h)
{
	base = b;
	height = h;
}

void Triangle::Scale(float scaleFactor)
{
	base *= scaleFactor;
	height *= scaleFactor;
}

void Triangle::Display() const
{
	cout << "The area of the Triangle is : " << Area() << endl;
	cout << "Base: " << base << endl;
	cout << "Height: " << height << endl;
}

float Triangle::Area() const
{
	return (0.5f * base * height);
}

string Triangle::GetName2D() const
{
	return "Triangle";
}

/*==== Circle ====*/

Circle::Circle(float r)
{
	radius = r;
}

void Circle::Scale(float scaleFactor)
{
	radius *= scaleFactor;
}

void Circle::Display() const
{
	cout << "The area of the Circle is : " << Area() << endl;
	cout << "Radius: " << radius << endl;
}

float Circle::Area() const
{
	return (PI * radius * radius);
}

string Circle::GetName2D() const
{
	return "Circle";
}

/*==== TriangularPyramid ====*/

TriangularPyramid::TriangularPyramid(float h, float lb, float hb) : Triangle(lb, hb)
{
	height = h;
}

void TriangularPyramid::Scale(float scaleFactor)
{
	height *= scaleFactor;
	Triangle::Scale(scaleFactor);
}

void TriangularPyramid::Display() const
{
	cout << "The volume of the Triangular Pyramid is : " << Volume() << endl;
	cout << "The height is: " << height << endl;
	Triangle::Display();
}

float TriangularPyramid::Volume() const
{
	return ((1.0f/3.0f) * Area() * height);
}

string TriangularPyramid::GetName3D() const
{
	return "Triangular Pyramid";
}

/*==== Cylinder ====*/

Cylinder::Cylinder(float h, float r) : Circle(r)
{
	height = h;
}

void Cylinder::Scale(float scaleFactor)
{
	height *= scaleFactor;
	Circle::Scale(scaleFactor);
}

void Cylinder::Display() const
{
	cout << "The volume of the Cylinder is : " << Volume() << endl;
	cout << "The height is: " << height << endl;
	Circle::Display();
}

float Cylinder::Volume() const
{
	return (Area() * height);
}

string Cylinder::GetName3D() const
{
	return "Cylinder";
}

/*==== Sphere ====*/

Sphere::Sphere(float r) : Circle(r)
{
	radius = r;
}

void Sphere::Scale(float scaleFactor)
{
	radius *= scaleFactor;
	Circle::Scale(scaleFactor);
}

void Sphere::Display() const
{
	cout << "The volume of the Sphere is : " << Volume() << endl;
	Circle::Display();
}

float Sphere::Volume() const
{
	return ((4.0f/3.0f) * Area() * radius);
}

string Sphere::GetName3D() const
{
	return "Sphere";
}