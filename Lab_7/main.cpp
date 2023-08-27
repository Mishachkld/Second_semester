#include <iostream>
#include "Shapes/Circle.hpp"
#include "Shapes/Triangle.hpp"
#include "Shapes/Rectangle.hpp"

int main() {
    sh::Circle* circle = new sh::Circle( 1, 1, "red", 5);
    sh::Triangle* triangle = new sh::Triangle( 1, 1, "red", 3, 4, 6);
    sh::Rectangle* rectangle = new sh::Rectangle( 1, 1, "red", 3, 4);
    circle->calculateArea();
    rectangle->calculateArea();

    rectangle->printArea();
    std::cout << "Circle area: " << circle->calculateArea() << std::endl <<"Triangle area: " <<  triangle->calculateArea();
    return 0;
}

