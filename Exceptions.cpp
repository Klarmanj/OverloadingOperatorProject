#include "Exceptions.h"
#include <iostream>

void Error::printError() {
    std::cout << error;
}
Error::Error(std::string message) {
    error = message;
}
DivByZero::DivByZero() : Error("Division by Zero! Please fix your fraction.") {}
LessThanZero::LessThanZero() : Error("You may not use negative numbers. Please fix your input."){}