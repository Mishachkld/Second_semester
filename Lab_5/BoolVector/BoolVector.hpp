#include <iostream>
#include <cstring>


#pragma once


namespace vb {
    /// q = 10101101
    /// Мантра:
    /// (~(1 << index)) & q | (val << index) (изменить на 0 или 1 (все зависит от val));
    /// где index - индекс элемента, который нужно изменить, q - элемент, который мы изменяем (в битовом представлении),
    /// & - умножить получившуюся строку на q, чтобы получить искомое зн-е, val - элемент на который мы меняем
    template<class T>
    class BoolVector {
    public:
        BoolVector() { std::cout << "weee, Amigooooooooo" << std::endl; }
    };

    template<>
    class BoolVector<bool> {
    public:
        BoolVector() {
            createArray();
        };

        ~BoolVector() {
            delete[] array;
        }

        int size() {
            return bitSize;
        }

        void changeElement(int index, bool value) {  /// метод изменения по индексу
            if ((index >= 0) and (index < bitSize)) {
                int bitIndex = index % 8;
                int arrayIndex = index / 8;
                changeElement(bitIndex, arrayIndex, value);
            }
            else
                throw std::exception();  //std::cout << "Errorr..." << std::endl;
        }

        bool operator[](int index) const {
            int arrayIndex = index / 8;
            int bitIndex = index % 8;
            return ((1 << bitIndex) & array[arrayIndex]) != 0;
        }

        void pushBack(bool item) {
            bitSize++;
            int index = (bitSize - 1) % 8;
            int arrayIndex = (bitSize - 1) / 8;
            if (((bitSize - 1) % 8 == 0) and (bitSize != 0))
                increaseSizeArray();
            changeElement(index, arrayIndex, item);
        }

        void insert(const int &position, const int &count,
                    const bool &value) { /// Вставляет элемент, множество элементов или диапазон элементов в вектор по заданной позиции.
            if ((position < bitSize) and (position >= 0)) {
                if ((bitSize + count) % 9 == 0)
                    increaseSizeArray();
                for (int i = (bitSize - 1) + count; i > position; i--)
                    changeElement(i % 8, i / 8, getItem((i - count) % 8, (i - count) / 8)); /// (*this)[i - count]);
                for (int i = position; i < position + count; i++)
                    changeElement(i % 8, i / 8, value);
                bitSize += count;
            } else
                std::cout << "Error..." << std::endl;
        }

        void erase(const int &position,
                   const int &count) { ///Удаляет элемент или диапазон элементов в векторе из заданных позиций в правую сторону на count.
            int index = position % 8;
            if ((index < bitSize) and (index >= 0) and
                ((count + position) < bitSize)) { /// если не будет работать, то заменить все символы на &
                for (int j = position; j < bitSize - 1; j++)
                    changeElement(j % 8, j / 8, getItem((j + count) % 8, (j + count) / 8));  //(*this)[j + count]);
                bitSize -= count;
                if ((bitSize / 8) < (arraySize - 1))
                    decreaseSizeArray();  /// вроде правильно отрабатывает, но если что-то пойдет не так, то лучше вот это закоменьтить :)
            } else
                std::cout << "Error..." << std::endl;
        }

        void outArray() const {
            for (int i = 0; i < bitSize; i++)
                std::cout << (bool) (*this)[i] << " ";
            std::cout << "| " << bitSize << std::endl;

            /*for (int i = 0; i < arraySize; i++) {   /// альтернативный способ вывода
               for (int j = 0; j < 8; j++)
                   std::cout << (((1 << j) & array[i]) && true) << " ";
               std::cout << std::endl;
           }
           std::cout << std::endl;*/
        }

    private:
        int bitSize = 0;   /// число булей
        int arraySize = 1; /// число чариков
        char *array;       /// сам массив чариков

        void createArray() {
            array = new char[arraySize];
            for (int i = 0; i < 8; i++) {
                array[0] = (0 << i) & array[0];
            }
        }

        bool getItem(const int &bitIndex,
                     const int &arrayIndex) const {
            return ((1 << bitIndex) & array[arrayIndex]) != 0;
        }

        void changeElement(const int &bitIndex, const int &arrayIndex, const bool item) {
            array[arrayIndex] = (~(1 << bitIndex)) & array[arrayIndex] | (item << bitIndex);
        }

        void increaseSizeArray() {
            char *tempArray = array;
            array = new char[arraySize + 1];
            std::memcpy(array, tempArray, arraySize);
            delete[] tempArray;
            arraySize++;
        }

        void decreaseSizeArray() {
            arraySize--;
            char *tempArray = array;
            array = new char[arraySize];
            std::memcpy(array, tempArray, arraySize);
            delete[] tempArray;
        }
    };
} // vb