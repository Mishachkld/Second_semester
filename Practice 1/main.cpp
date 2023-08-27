#include <iostream>
#include "Encryption.hpp"

int main() {
    std::string str;
    std::cout << "Write smth interesting: " << std::endl;
    std::getline(std::cin, str);
    std::cout << "Now write Integer key using Space or Enter: " << std::endl;
    en::Encryption myString(str);
    myString.showKey();
    myString.showMessage();
	myString.decode();
	myString.showKey();
	myString.showMessage();

    return 0;
}

