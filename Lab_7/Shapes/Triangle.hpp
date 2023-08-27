//
// Created by Mishach on 27.03.2023.
//
#pragma once

#include "Shape.hpp"

namespace sh {

    class Triangle :  public sh::Shape {
    public:
        Triangle(double x, double y, std::string colour, double a,
                 double b, double c) : Shape(x, y, std::move(colour)) {
            if ((a > 0) and (b >= 0) and (c >= 0)) {
                this->a = a;
                this->b = b;
                this->c = c;
            }
        };

        double calculateArea() override;

    private:
        double a, b, c; // стороны треугольника
    };

} // sh
