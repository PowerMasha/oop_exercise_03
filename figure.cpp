#include "figure.h"
#include <cmath>
//Точка
Point::Point() : x{0}, y{0} {}

Point::Point(double x, double y) : x{x}, y{y} {}

double Point::X() const {
	return x;
}

double Point::Y() const {
	return y;
}

std::ostream& operator<< (std::ostream& out, const Point& p) {
	out << "(" << p.X() << ";" << p.Y() << ")";
	return out;
}


std::istream& operator>> (std::istream& in, Point& p) {
        in >> p.x >> p.y; 
	return in;
}
//Квадрат
Square::Square() : A1{0, 0}, B2{0, 0}, C3{0, 0}, D4{0, 0} {}

Square::Square(std::istream& in) {
  in >> A1 >> B2 >> C3 >> D4;
  double a, b, c, d, d1, d2, ABC, BCD, CDA, DAB;
  a = sqrt((B2.X()- A1.X()) * (B2.X() - A1.X()) + (B2.Y() - A1.Y()) * (B2.Y() - A1.Y()));
  b = sqrt((C3.X()- B2.X()) * (C3.X() - B2.X()) + (C3.Y() - B2.Y()) * (C3.Y() - B2.Y()));
  c = sqrt((C3.X()- D4.X()) * (C3.X() - D4.X()) + (C3.Y() - D4.Y()) * (C3.Y() - D4.Y()));
  d = sqrt((D4.X()- A1.X()) * (D4.X() - A1.X()) + (D4.Y() - A1.Y()) * (D4.Y() - A1.Y()));
  d1 = sqrt((B2.X()- D4.X()) * (B2.X() - D4.X()) + (B2.Y() - D4.Y()) * (B2.Y() - D4.Y()));
  d2 = sqrt((C3.X()- A1.X()) * (C3.X() - A1.X()) + (C3.Y() - A1.Y()) * (C3.Y() - A1.Y()));
  ABC = (a * a + b * b - d2 * d2) / 2 * a * b;
  BCD = (b * b + c * c - d1 * d1) / 2 * b * c;
  CDA = (d * d + c * c - d2 * d2) / 2 * d * c;
  DAB = (a * a + d * d - d1 * d1) / 2 * a * d;
  if(ABC != BCD || ABC != CDA || ABC != DAB || a!=b || a!=c || a!=d )
    throw std::logic_error("Это не квадрат!");
}

double Square::area() const{
double p = abs(A1.X()*B2.Y()+B2.X()*C3.Y()+C3.X()*D4.Y()+D4.X()*A1.Y()-B2.X()*A1.Y()-C3.X()*B2.Y()-D4.X()*C3.Y()-A1.X()*D4.Y())/2;
  return p;
}

Point Square::center() const{
  return Point{(A1.X() + B2.X() + C3.X() + D4.X()) / 4, (A1.Y() + B2.Y() + C3.Y() + D4.Y()) / 4};
}

std::ostream& Square::print(std::ostream& out) const{
  out << A1 << " " << B2 << " " << C3 << " " << D4;
  return out;
}
//Прямоугольник
Rectangle::Rectangle() : A1{0, 0}, B2{0, 0}, C3{0, 0}, D4{0, 0} {}

Rectangle::Rectangle(std::istream& in) {
  in >> A1 >> B2 >> C3 >> D4;
  double a, b, c, d, d1, d2, ABC, BCD, CDA, DAB;
  a = sqrt((B2.X()- A1.X()) * (B2.X() - A1.X()) + (B2.Y() - A1.Y()) * (B2.Y() - A1.Y()));
  b = sqrt((C3.X()- B2.X()) * (C3.X() - B2.X()) + (C3.Y() - B2.Y()) * (C3.Y() - B2.Y()));
  c = sqrt((C3.X()- D4.X()) * (C3.X() - D4.X()) + (C3.Y() - D4.Y()) * (C3.Y() - D4.Y()));
  d = sqrt((D4.X()- A1.X()) * (D4.X() - A1.X()) + (D4.Y() - A1.Y()) * (D4.Y() - A1.Y()));
  d1 = sqrt((B2.X()- D4.X()) * (B2.X() - D4.X()) + (B2.Y() - D4.Y()) * (B2.Y() - D4.Y()));
  d2 = sqrt((C3.X()- A1.X()) * (C3.X() - A1.X()) + (C3.Y() - A1.Y()) * (C3.Y() - A1.Y()));
  ABC = (a * a + b * b - d2 * d2) / 2 * a * b;
  BCD = (b * b + c * c - d1 * d1) / 2 * b * c;
  CDA = (d * d + c * c - d2 * d2) / 2 * d * c;
  DAB = (a * a + d * d - d1 * d1) / 2 * a * d;
  if(ABC != BCD || ABC != CDA || ABC !=DAB)
    throw std::logic_error("Это не прямоугольник!");
}

double Rectangle::area() const{
double p = abs(A1.X()*B2.Y()+B2.X()*C3.Y()+C3.X()*D4.Y()+D4.X()*A1.Y()-B2.X()*A1.Y()-C3.X()*B2.Y()-D4.X()*C3.Y()-A1.X()*D4.Y())/2;
  return p;
}

Point Rectangle::center() const{
  return Point{(A1.X() + B2.X() + C3.X() + D4.X()) / 4, (A1.Y() + B2.Y() + C3.Y() + D4.Y()) / 4};
}

std::ostream& Rectangle::print(std::ostream& out) const{
  out << A1 << " " << B2 << " " << C3 << " " << D4;
  return out;
}
//Трапеция
Trapeze::Trapeze() : A1{0, 0}, B2{0, 0}, C3{0, 0}, D4{0,0} {}

Trapeze::Trapeze(std::istream& in) {
  in >> A1 >> B2 >> C3 >> D4;
  if((C3.Y()-B2.Y())/(C3.X()-B2.X())!=(D4.Y()-A1.Y())/(D4.X()-A1.X()))
    throw std::logic_error("Это не трапеция!");
}


double Trapeze::area() const{
double p = abs(A1.X()*B2.Y()+B2.X()*C3.Y()+C3.X()*D4.Y()+D4.X()*A1.Y()-B2.X()*A1.Y()-C3.X()*B2.Y()-D4.X()*C3.Y()-A1.X()*D4.Y())/2;
  return p;
	       
}

Point Trapeze::center() const
{
  return Point{(A1.X() + B2.X() + C3.X() + D4.X()) / 4, (A1.Y() + B2.Y() + C3.Y() + D4.Y()) / 4};
}

std::ostream& Trapeze::print(std::ostream& out) const
{
  out << A1 << " " << B2 << " " << C3 << " " << D4;
  return out;
}

