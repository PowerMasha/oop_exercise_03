#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class Point {
public:
	Point();
	Point(double x, double y);
	double X() const;
	double Y() const;
	friend std::ostream& operator<< (std::ostream& out, const Point& p);
	friend std::istream& operator>> (std::istream& in, Point& p);
private:
	double x;
	double y;
};

class Figure {
public:
	virtual double area() const = 0;
	virtual Point center() const = 0;
	virtual std::ostream& print(std::ostream& out) const = 0;
	virtual ~Figure() = default;
};


class Square : public Figure {
public:
	Square();
	Square(std::istream& in);
	double area() const override;
	Point center() const override;
	std::ostream& print(std::ostream& out) const override;
private:
	Point A1;
	Point B2;
	Point C3;
	Point D4;
};

class Rectangle : public Figure {
public:
	Rectangle();
	Rectangle(std::istream& in);
	double area() const override;
	Point center() const override;
	std::ostream& print(std::ostream& out) const override;
private:
	Point A1;
	Point B2;
	Point C3;
	Point D4;
};

class Trapeze : public Figure {
public:
        Trapeze();
	Trapeze(std::istream& in);
	double area() const override;
	Point center() const override;
	std::ostream& print(std::ostream& out) const override;
private:
	Point A1;
	Point B2;
	Point C3;
	Point D4;
};


#endif
