#include <iostream>
#include <fstream>
#include "CFraction.h"
#include "Exceptions.h"

int main() {
    CFraction frac1;
    std::ifstream input("Input.txt");
    if(input.is_open()){
        input >> frac1;
    }
}