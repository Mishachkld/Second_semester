//
// Created by Mishach on 28.02.2023.
//
#pragma once

#include <iostream>
#include <algorithm>


namespace cn {
    class ComplexNumber {
    public:
        ComplexNumber(double a, double b);

        ComplexNumber(const ComplexNumber &temp);

        ComplexNumber(double a);

        ~ComplexNumber() = default;

        ///Functions

        ///Overrated
        ComplexNumber &operator+=(const ComplexNumber &temp);

        ComplexNumber &operator*=(const ComplexNumber &temp);

        ComplexNumber &operator=(const ComplexNumber &temp);

        ComplexNumber operator+(const ComplexNumber &temp) const;

        ComplexNumber operator*(const ComplexNumber &temp);

        ComplexNumber operator++(int i);

        ComplexNumber& operator++();

        friend std::ostream &operator<<(std::ostream &outStream, const ComplexNumber &temp);

        friend std::istream &operator>>(std::istream &inputStream, ComplexNumber &temp);

    private:
        double a;
        double b;


    };

}

