//
// Created by Mishach on 27.03.2023.
//

#pragma once

#include "Shape.hpp"

namespace sh {

    class Circle :  public sh::Shape {
    public:
        Circle(double x = 0, double y = 0, std::string colour = "black", double radius = 0)
                : Shape(x, y, std::move(colour)){
            if (radius >= 0)
                this->radius = radius;
        }

        double getRadius() const;

        double calculateArea() override ;


    private:
        double radius = -1;
        //const double PI = 3.14; // можно использовать с библиотеки Math

    };

} // sh
