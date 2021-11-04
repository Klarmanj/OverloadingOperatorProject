#ifndef UOVERLOADINGOPERATORPROJECT_CFRACTION_H
#define UOVERLOADINGOPERATORPROJECT_CFRACTION_H
#include <iostream>


class CFraction {
    int numerator, denominator;
    static int count;


public:
    CFraction();
    CFraction(const int, const int);
    CFraction(const double);
    CFraction operator+(const CFraction&) const;
    CFraction operator-(const CFraction&) const;
    CFraction operator*(const CFraction&) const;
    CFraction operator/(const CFraction&) const;
    CFraction operator+(double) const;
    CFraction operator-(double) const;
    CFraction operator*(double) const;
    CFraction operator/(double) const;
    bool operator==(const CFraction&) const;
    bool operator>(const CFraction&) const;
    bool operator<(const CFraction&) const;
    friend std::istream& operator>>(std::istream&, CFraction&);
    friend std::ostream& operator<<(std::ostream&, CFraction&);
    void simplify();
    static int getcount() {
        return count;
    }
};


#endif
