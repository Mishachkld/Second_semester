//
// Created by Mishach on 14.02.2023.
//
#include "CustomString.hpp"

namespace cs {

    /// Конструктор 1
    CustomString::CustomString(char &symbol, int &size) : _size(size ), _string(new char[size]) {
        std::fill(_string, _string + _size, symbol);
    }

    ///Конструктор копирования   (!!!)
    CustomString::CustomString(char *str) : _string(str), _size(strlen(str) ) {
        std::copy(str, str + _size, _string);
//        str[_size] = 0;

    }

    /// Конструктор 2
    CustomString::CustomString(const CustomString &other) : CustomString(other._string) {
        /*     _size = other._size;
             ///выделили память
             _string = new char [_size];
             std::copy(other._string, other._string + _size, _string);*/
    }

    CustomString::~CustomString() {
        delete[] _string;
    }

    void CustomString::outString() const {
        for (int i = 0; i < _size; i++)
            std::cout << _string[i];
        std::cout << std::endl;
    }

    int CustomString::length() {
        return _size;
    }


    int CustomString::find(const char &a) {
        int index = -1;
        for (int i = 0; i < _size; i++) {
            if (_string[i] == a) {
                index = i;
                break;   /// осуждаю
            }
        }
        return index;
    }

    char *CustomString::c_str() {
        return _string;
    }

    /// Возвращает ссылку на i-ый элемент. В противном случае возвращает char == '-' (костыль) :)
    char &CustomString::at(const int i) {
        if ((i >= 0) and (i < _size))
            return _string[i];
        outMessageError();
        return exceptionChar;   /// костыль

        /* try {
             return _string[i];
         }
         catch(const std::out_of_range& e){
             return exceptionChar;
             std::cout << e.what() << std::endl;
             outMessageError();
         }*/

    }

    CustomString &CustomString::operator=(const CustomString &other) {
        CustomString temp = other;
        std::swap(temp._string, _string);
        std::swap(temp._size, _size);
        std::copy(other._string, other._string + other._size, _string);
        return *this;
    }

    bool CustomString::operator<(const CustomString &other) const {
        bool result = false;
        if (_size < other._size)
            result = true;
        else if (_size == other._size)
            for (int i = 0; i < _size; ++i)
                if ((int) _string[i] < (int) other._string[i])
                    result = true;
        return result;
    }

    bool CustomString::operator>(const CustomString &other) const {
        bool result = false;
        if (_size > other._size)
            result = true;
        else if (_size == other._size)
            for (int i = 0; i < _size; ++i)
                if ((int) _string[i] > (int) other._string[i])
                    result = true;
        return result;
    }

    bool CustomString::operator==(const CustomString &other) const {
        bool result = true;
        if (_size != other._size)
            result = false;
        else if (_size == other._size)
            for (int i = 0; i < _size; ++i)
                if ((int) _string[i] != (int) other._string[i])
                    result = false;
        return result;
    }

    CustomString CustomString::operator+(const CustomString &other) {
        CustomString newString = other;   /// как можно сделать лучше?
        newString._size = _size + other._size;
        newString._string = new char[newString._size];
        std::copy(_string, _string + _size, newString._string);
        std::copy(other._string, other._string + other._size, newString._string + _size);
        return newString;
    }

    CustomString &CustomString::operator+=(const CustomString &other) {
        int size = other._size + _size;
        char *backup = _string;
        delete[] _string;
        _string = new char[_size];
        std::copy(backup, backup + _size, _string);
        std::copy(other._string, other._string + other._size, _string + _size);
        _size = size;
        return *this;
    }

    char &CustomString::operator[](const int &symbol) {
        if ((symbol < _size) and (symbol >= 0))
            return _string[symbol];
        outMessageError();
        return exceptionChar;   /// костыль
    }

    void CustomString::outMessageError() {
        std::cout << "Errorrr..." << std::endl;
    }

    std::ostream &operator<<(std::ostream &outStream, const CustomString &other) {
        for (int i = 0; i < other._size; i++)
            outStream << other._string[i];
        outStream << std::endl;
        return outStream;
    }

    std::istream& operator >> (std::istream& inputStream, CustomString& other) {
        for (int i = 0; i < other._size; i++)
            inputStream >> other._string[i];
        return inputStream;
    }


} // cs