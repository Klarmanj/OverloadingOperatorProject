#include "CFraction.h"
#include "Exceptions.h"

CFraction::CFraction() {
    numerator = 0;
    denominator = 1;
}
CFraction::CFraction(const int n, const int d) {
    try {
        if(n < 0 || d < 0)
            throw LessThanZero();
        numerator = n;

        if(d == 0)
            throw DivByZero();
        denominator = d;
    }
    catch(Error& e){
        e.printError();
        abort();
    }
}
//CFraction::CFraction(const double num) {
//
//}

CFraction CFraction::operator+(const CFraction &add) const {
    int top = (this->numerator*add.denominator) + (this->denominator*add.numerator);
    int bottom = (this->denominator*add.denominator);
    std::cout << top << "/" << bottom;
}
CFraction CFraction::operator-(const CFraction &sub) const{
    int top = (this->numerator*sub.denominator) - (this->denominator*sub.numerator);
    int bottom = (this->denominator*sub.denominator);
    std::cout << top << "/" << bottom;
}
CFraction CFraction::operator*(const CFraction &multiply) const {
    int top = (this->numerator * multiply.numerator);
    int bottom = (this->denominator * multiply.denominator);
    std::cout << top << "/" << bottom;
}
CFraction CFraction::operator/(const CFraction &divide) const {
    int top = (this->numerator * divide.denominator);
    int bottom = (this->denominator * divide.numerator);
    std::cout << top << "/" << bottom;
}