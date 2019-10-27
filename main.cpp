#include <iostream>
#include "figure.h"
#include <vector>
#include <string>

void read_typeF(std::vector<Figure *>& fig)
{
  int typeF;
  Rectangle *re = nullptr;
  Trapeze *t = nullptr;
  Square *s = nullptr;
 
  std::cout << "Выберете фигуру: 1-квадрат; 2-прямоугольник; 3-трапеция. \n";
  std::cin >> typeF;
  switch (typeF) {
  case 1:
 try{
      s = new Square(std::cin);
    } catch(std::logic_error& err){
      std::cout << err.what() << std::endl;
      break;
    }
    fig.push_back(dynamic_cast<Figure*>(s));
    break;
  case 2:
	try {
		re = new Rectangle(std::cin);
	} catch(std::logic_error& err){
	std::cout << err.what() << std::endl;
	break;
    }
    fig.push_back(dynamic_cast<Figure*>(re));
    break;
  case 3:
 try{
      t = new Trapeze(std::cin);
    } 
      catch(std::logic_error& err){
      std::cout << err.what() << std::endl;
      break;
    }
    fig.push_back(dynamic_cast<Figure*>(t));
    break;
  default:
    std::cout << "Ошибка\n";  }
}

int main(){
  unsigned int index;
  double Tarea = 0;
  std::string operation;
  std::vector<Figure*> fig;
  std::cout << "Operations: add / delete / out / quit\n";
  
  while (std::cin >> operation) {
    if (operation == "add") {
      read_typeF(fig);
    }
    else if (operation == "delete") {
      std::cin >> index;
      delete fig[index];
      for (; index < fig.size() - 1; ++index) {
	fig[index] = fig[index + 1];
      }
      fig.pop_back();
    }
    else if (operation == "out") {
      Tarea = 0;
      for (unsigned int i = 0; i < fig.size(); i++) {
	std::cout << i << ":\n";
	std::cout << "Area: " << fig[i]->area() << std::endl;
	std::cout << "Center: " << fig[i]->center() << std::endl;
	std::cout << "Coordinates: ";
	fig[i]->print(std::cout);
	std::cout << std::endl;
	Tarea += fig[i]->area();
      }
      std::cout << "Total area: " << Tarea << std::endl;
    }
    else if (operation == "quit"){
      for (unsigned int i = 0; i < fig.size(); ++i) {
	delete fig[i];
      }
      return 0;
    }
    else {
      std::cout << "Ошибка\n";
    }
  }
}
