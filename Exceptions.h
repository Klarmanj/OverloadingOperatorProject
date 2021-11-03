#ifndef UOVERLOADINGOPERATORPROJECT_EXCEPTIONS_H
#define UOVERLOADINGOPERATORPROJECT_EXCEPTIONS_H
#include <string>

class Error{
    std::string error;
public:
    void printError();
    Error(std::string);
};

class DivByZero: public Error{
public:
    DivByZero();
};
class LessThanZero: public Error{
public:
    LessThanZero();
};

#endif
