#include"Complex/ComplexNumber.hpp"


int main(){
    cn::ComplexNumber z(1,1);
    cn::ComplexNumber z1(1,0);
    z++;
    ++z;
    z = z1 * z;
    std::cout << z;
    z *= z;
    std::cout << z;


    return 0;
}