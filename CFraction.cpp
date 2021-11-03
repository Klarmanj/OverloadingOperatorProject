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
void CFraction::simplify() {
    int max = (numerator < denominator) ? denominator : numerator;
    int lcd = denominator;
    for(int lowest = 2; lowest < max; lowest++){
        if(((numerator % lowest == 0) && (denominator % lowest == 0))){
            lcd = lowest;
            numerator = (this->numerator / lcd);
            denominator = (this->denominator/lcd);
        }
    }
    std::cout << numerator << "/" << denominator;
}
bool CFraction::operator==(const CFraction &equal) const {
    if((this->numerator == equal.numerator) && (this->denominator == equal.denominator))
        return true;
    else if((this->numerator * equal.denominator) == (equal.numerator * this->denominator))
        return true;

    return false;
}
bool CFraction::operator>(const CFraction &greater) const {
   return ((this->numerator * greater.denominator) > (greater.numerator * this->denominator));
}
bool CFraction::operator<(const CFraction &greater) const {
    return ((this->numerator * greater.denominator) < (greater.numerator * this->denominator));
}


/**
* 1/2 + 2/4
 * 1 * 4 put that over 4 * 2
 * 2 * 2 put that over 4 * 2
 * N1 * D2 over D2 * D1
 * N2 * D1 over D2 * D1
*/