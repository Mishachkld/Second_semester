//
// Created by Mishach on 27.03.2023.
//

#include "Triangle.hpp"

namespace sh {

    double Triangle::calculateArea() {
        double p = (a + b + c) / 2;
        area = sqrt(p * (p - a) * (p - b) * (p - c));
        return area;
    }

} // sh