//
// Created by Mishach on 08.04.2023.
//
#pragma once

#include <vector>
#include <iostream>


namespace st {
    template<class T>
    class VectorStack {
    public:
        VectorStack(int size) {  // не имеет смысла
            sizeArray = 0;
            /*sizeArray = size;
             try {
                 sizeArray = size;
                 stack_array.reserve(size);
             }
             catch (const std::exception &e) {
                 std::cout << e.what() << std::endl;
             }*/
        }

        VectorStack(int size, T item) {  // в этом конструкторе больше смысла, т.к. мы чем-то забиваем массив
            try {
                sizeArray = size;
                for (int i = 0; i < sizeArray; i++)
                    stack_array.push_back(item);
            }
            catch (const std::exception &e) {
                std::cout << e.what() << std::endl;
                throw ;
            }
        }

        /*VectorStack() {
            sizeArray = SIZE;
            std::fill(stack_array->begin(), stack_array->end() + SIZE, nullptr);
        }*/

        VectorStack() {
            sizeArray = 0;
        }

        ~VectorStack() {
            //delete stack_array;
        }
        /// возвращает размер
        int size() {
            return sizeArray;
        }
        /// возвращает true или false
        bool empty() {
            bool result = true;
            if (sizeArray != 0)
                result = false;
            return result;
        }
        /// добавляем элемент в стек
        void push(const T &item) {
            try {
                sizeArray++;
                stack_array.push_back(item);
            }
            catch (const std::exception &e) {
                std::cout << e.what() << std::endl;
            }
        }
        /// извлекаем элемент из стека
        void pop() {
            if (!empty()) {
                sizeArray--;
                stack_array.pop_back();
            } else
                throw std::out_of_range("pop exeption: man, stack is empty");
        }
        /// просто смотрим на элемент
        T &top() {
            if (!empty())
                return stack_array[sizeArray - 1];
            throw std::logic_error("top exeption: WTF maaan! stack is empty!");
        }

    private:
        std::vector<T> stack_array;
        int sizeArray;

        friend std::ostream &operator<<(std::ostream &out, const VectorStack st) {
            for (const T item: st.stack_array) {
                out << item << " ";
            }
            out << std::endl;
            return out;
        }
    };

} // st

