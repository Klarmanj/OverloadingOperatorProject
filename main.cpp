#include <iostream>
#include "CFraction.h"
#include "Exceptions.h"

int main() {
    CFraction test(1,2);
    CFraction test2(3,5);
    test / test2;
    test - test2;

}
