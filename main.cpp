#include <iostream>
#include <fstream>
#include "CFraction.h"
#include "Exceptions.h"

int main() {
//    CFraction test(3,5);
//    CFraction test2(4,5);
//    bool isEqual = test < test2;
//    std::cout << isEqual;


    CFraction frac1;
    std::ifstream input("Input.txt");
    if(input.is_open()){
        input >> frac1;
    }


}
