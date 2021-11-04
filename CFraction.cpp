#include "CFraction.h"
#include "Exceptions.h"
#include <sstream>
#include <fstream>


CFraction::CFraction() {
    numerator = 0;
    denominator = 1;
}
CFraction::CFraction(const int n, const int d) {
    try {
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
    CFraction added(top, bottom);
    return added;
}
CFraction CFraction::operator-(const CFraction &sub) const{
    int top = (this->numerator*sub.denominator) - (this->denominator*sub.numerator);
    int bottom = (this->denominator*sub.denominator);
    CFraction subtracted(top, bottom);
    return subtracted;
}
CFraction CFraction::operator*(const CFraction &multiply) const {
    int top = (this->numerator * multiply.numerator);
    int bottom = (this->denominator * multiply.denominator);
    CFraction multiplied(top, bottom);
    return multiplied;
}
CFraction CFraction::operator/(const CFraction &divide) const {
    int top = (this->numerator * divide.denominator);
    int bottom = (this->denominator * divide.numerator);
    CFraction divided(top, bottom);
    return divided;
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

std::istream& operator>>(std::istream &input, CFraction &frac1) {
    std::string line;
    char choice;
    std::ofstream output("output.txt");
    while(std::getline(input,line)){
        std::istringstream ss(line);
        ss >> choice;
        std::string num1;
        ss >> num1;
        size_t found = num1.find('.');
        if(found != std::string::npos){
            double num1_double = std::stod(num1);
            std::string num2;
            ss >> num2;
            size_t found2 = num2.find('.');
            if(found2 != std::string::npos){
                double num2_double = std::stod(num2);
            }
        }
        else{
            frac1.numerator = std::stoi(num1);
            std::string num2;
            ss >> num2;
            frac1.denominator = std::stoi(num2);
        }
        std::string num3;
        ss >> num3;
        size_t found3 = num3.find('.');
        if(found3 != std::string::npos) {
            double num3_double = std::stod(num3);
        }

        CFraction frac2;
        std::string num4;
        frac2.numerator = stoi(num3);
        ss >> num4;
        frac2.denominator = stoi(num4);
        frac1.simplify();
        frac2.simplify();
        switch (choice) {
            case 'a': {
                CFraction add = frac1 + frac2;
                add.simplify();
                std::cout << frac1 << " + " << frac2 << " = " << add << std::endl;
                output << frac1 << " + " << frac2 << " = " << add << std::endl;
                break;
            }
            case 's': {
                CFraction sub = frac1 - frac2;
                sub.simplify();
                std::cout << frac1 << " - " << frac2 << " = " << sub << std::endl;
                output << frac1 << " - " << frac2 << " = " << sub << std::endl;
                break;
            }
            case 'm': {
                CFraction mul = frac1 * frac2;
                mul.simplify();
                std::cout << frac1 << " * " << frac2 << " = " << mul << std::endl;
                output << frac1 << " * " << frac2 << " = " << mul << std::endl;
                break;
            }
            case 'd':
            {
                CFraction div = frac1 / frac2;
                div.simplify();
                std::cout << frac1 << " / " << frac2 << " = " << div << std::endl;
                output << frac1 << " / " << frac2 << " = " << div << std::endl;
                break;
            }
            case 'c': {
                if (frac1 > frac2) {
                    std::cout << frac1 << " is greater than " << frac2 << std::endl;
                } else if (frac1 < frac2) {
                    std::cout << frac1 << " is less than " << frac2 << std::endl;
                } else if (frac1 == frac2) {
                    std::cout << frac1 << " is equal to " << frac2 << std::endl;
                }
                break;
            }
        }
    }

    return input;
}
std::ostream& operator<<(std::ostream& output, CFraction& temp){
    std::string outputString;
    int number = 0;
    int newNumerator = temp.numerator;
    if(temp.numerator == temp.denominator){
        number = 1;
    }
    if(temp.numerator > temp.denominator){
        // have improper fraction, so make the count what it needs to and change the num and den accordingly
        number = (temp.numerator/temp.denominator);
        newNumerator = (temp.numerator % temp.denominator);
    }

    // 1. if count == 1, then we dont print num/den, print only count
    // 2. if count > 1 && (count == num) && (den == 1) then print count only
    // 3. else, print count and num / den

    if(number == 1){
        outputString = "1";
    }

    if((number == temp.numerator) && (temp.denominator == 1)) {
        // print count only
        outputString = std::to_string(number);
    }
    else if(number == 0){
        outputString = std::to_string(newNumerator) + "/" + std::to_string(temp.denominator);
    }
    else{
        outputString = std::to_string(number) + " " + std::to_string(newNumerator) + "/" + std::to_string(temp.denominator);
    }

    output << outputString;

    return output;

}



/**
* 1/2 + 2/4
 * 1 * 4 put that over 4 * 2
 * 2 * 2 put that over 4 * 2
 * N1 * D2 over D2 * D1
 * N2 * D1 over D2 * D1
*/