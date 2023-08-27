#include "BoolVector/BoolVector.hpp"

int main() {
    vb::BoolVector<bool> boolVector;
    boolVector.pushBack(false);
    boolVector.pushBack(true);
    boolVector.pushBack(true);
    boolVector.pushBack(false);
    boolVector.pushBack(true);
    boolVector.pushBack(false);
    boolVector.pushBack(false);
    boolVector.pushBack(false);
    boolVector.pushBack(true);
    boolVector.pushBack(false);
    boolVector.pushBack(true);
    boolVector.pushBack(true);
    boolVector.pushBack(true);
    boolVector.pushBack(false);
    boolVector.pushBack(false);
    boolVector.pushBack(false);
    boolVector.pushBack(false);
    boolVector.pushBack(false);
    boolVector.pushBack(false);
    boolVector.pushBack(true);
    boolVector.pushBack(false);
    boolVector.pushBack(true);
    boolVector.pushBack(false);
    boolVector.pushBack(false);

    boolVector.outArray();
    boolVector.erase(12, 2);
    boolVector.outArray();

    /*for (int i = 0; i < 1; ++i) {
        boolVector.pushBack(true);
        boolVector.pushBack(false);
        boolVector.pushBack(true);
        boolVector.pushBack(true);
        boolVector.pushBack(true);
        boolVector.pushBack(true);
    }
    boolVector.pushBack(false);
    boolVector.pushBack(true);
    boolVector.pushBack(false);
    boolVector.outArray();   /// после '|' пишется размер массива
    boolVector.erase(3,2);
    boolVector.outArray();
    boolVector.erase(0,4);

      boolVector.outArray();
      boolVector.insert(2, 3, true); boolVector.outArray();
      boolVector.insert(2, 3, true); boolVector.outArray();
      boolVector.insert(0, 3, false);boolVector.outArray();
      boolVector.insert(2, 3, true); boolVector.outArray();
    boolVector.changeElement(0, true);
    boolVector.changeElement(10, true);
    boolVector.outArray();
    std::cout << boolVector[5] << std::endl;*/
    return 0;
}