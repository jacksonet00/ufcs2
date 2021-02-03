#pragma once
#include <string>
using std::string;

class Shape
{
public:
	virtual ~Shape() = 0;
	virtual void Scale(float scaleFactor) = 0;
	virtual void Display() const = 0;
};

class Shape2D : virtual public Shape
{
public:
	virtual ~Shape2D() = 0;
	virtual float Area() const = 0;
	void ShowArea() const;
	virtual string GetName2D() const = 0;
	bool operator>(const Shape2D& rhs) const;
	bool operator<(const Shape2D& rhs) const;
	bool operator==(const Shape2D& rhs) const;
};

class Shape3D : virtual public Shape
{
public:
	virtual ~Shape3D() = 0;
	virtual float Volume() const = 0;
	void ShowVolume() const;
	virtual string GetName3D() const = 0;
	bool operator>(const Shape3D& rhs) const;
	bool operator<(const Shape3D& rhs) const;
	bool operator==(const Shape3D& rhs) const;
};

class Square : virtual public Shape2D
{
	float length;
public:
	Square(float l = 0);

	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	string GetName2D() const;
};

class Triangle : virtual public Shape2D
{
	float base, height;
public:
	Triangle(float b = 0, float h = 0);

	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	string GetName2D() const;
};

class Circle : virtual public Shape2D
{
	float radius;
public:
	Circle(float r = 0);

	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	string GetName2D() const;
};

class TriangularPyramid : virtual public Shape3D, private Triangle
{
	float height;
public:
	TriangularPyramid(float h = 0, float lb = 0, float hb = 0);

	void Scale(float scaleFactor);
	void Display() const;
	float Volume() const;
	string GetName3D() const;
};

class Cylinder : virtual public Shape3D, private Circle
{
	float height;
public:
	Cylinder(float h = 0, float r = 0);

	void Scale(float scaleFactor);
	void Display() const;
	float Volume() const;
	string GetName3D() const;
};

class Sphere : virtual public Shape3D, private Circle
{
	float radius;
public:
	Sphere(float r = 0);

	void Scale(float scaleFactor);
	void Display() const;
	float Volume() const;
	string GetName3D() const;
};