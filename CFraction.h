#ifndef UOVERLOADINGOPERATORPROJECT_CFRACTION_H
#define UOVERLOADINGOPERATORPROJECT_CFRACTION_H
#include <iostream>

class CFraction {
    int numerator, denominator;
//    static int count;


public:
    CFraction();
    CFraction(const int, const int);
//    CFraction(const double);
    CFraction operator+(const CFraction&) const;
    CFraction operator-(const CFraction&) const;
    CFraction operator*(const CFraction&) const;
    CFraction operator/(const CFraction&) const;
//    CFraction operator+(double) const;
//    CFraction operator-(double) const;
//    CFraction operator*(double) const;
//    CFraction operator/(double) const;
    bool operator==(const CFraction&) const;
    bool operator>(const CFraction&) const;
    bool operator<(const CFraction&) const;
//    std::istream& operator>>(std::istream&, CFraction&) const;
    void simplify();
};


#endif
