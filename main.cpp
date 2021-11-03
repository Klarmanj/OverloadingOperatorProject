#include <iostream>
#include "CFraction.h"
#include "Exceptions.h"

int main() {
    CFraction test(3,5);
    CFraction test2(3,5);
    bool isEqual = test > test2;
    std::cout << isEqual;

}
