#include "ComplexNumber.hpp"

namespace cn {

    ///Комплексное число имеет вид z = a + bi, где а - действительная часть, b - мнимая
    ComplexNumber::ComplexNumber(double a, double b) : a(a), b(b){}

    ComplexNumber::ComplexNumber(const ComplexNumber &temp) :  ComplexNumber (temp.a, temp.b){ // Получается мы берем и задаем правило, ко которому будем копировать?!
    }

    ComplexNumber::ComplexNumber(double a) : a(a), b(0) { }

    ComplexNumber ComplexNumber::operator+(const ComplexNumber &temp) const {  // почему const
        ComplexNumber newNumber(temp.a + a, temp.b + b);
        return newNumber;
    }
    ///a*a1 + a*b1*i + a1*b*i - b*b1
    ComplexNumber ComplexNumber::operator*(const ComplexNumber &temp) {
        ComplexNumber newNumber = temp;
        newNumber.a *= temp.a * a - temp.b * b;
        newNumber.b += temp.a * b + a * temp.b;
        return newNumber;
    }

    ComplexNumber &ComplexNumber::operator*=(const ComplexNumber &temp) {
        *this = *this * temp;
        return *this;
    }

    ComplexNumber& ComplexNumber::operator+=(const ComplexNumber &temp) {
        a += temp.a;
        b += temp.b;
        return *this;
    }

    ComplexNumber ComplexNumber::operator++(int i) {
        a++;
        return *this;
    }
    ComplexNumber& ComplexNumber::operator++() {
        ComplexNumber temp (*this);
        ++temp.a;
        return temp;
    }

    ComplexNumber &ComplexNumber::operator=(const ComplexNumber &temp) {
        /// swap-and-copy
        ComplexNumber number = temp;
        std::swap(number.a, a);
        std::swap(number.b, b);
        return *this;
    }


    std::ostream &operator<<(std::ostream &outStream, const ComplexNumber &temp) {
        outStream << temp.a << " + " << temp.b << "i" << std::endl;
        return outStream;
    }

    std::istream &operator>>(std::istream &inputStream, ComplexNumber &temp) {
        inputStream >> temp.a >> temp.b;
        return inputStream;
    }




}