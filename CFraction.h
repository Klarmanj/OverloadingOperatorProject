#ifndef UOVERLOADINGOPERATORPROJECT_CFRACTION_H
#define UOVERLOADINGOPERATORPROJECT_CFRACTION_H


class CFraction {
    int numerator, denominator;
    static int count;
    void simplify();

public:
    CFraction();
    CFraction(const int, const int);
    CFraction operator+(const CFraction&) const;
    CFraction operator-(const CFraction&) const;
    CFraction operator*(const CFraction&) const;
    CFraction operator/(const CFraction&) const;
    CFraction operator+(double) const;
    CFraction operator-(double) const;
    CFraction operator*(double) const;
    CFraction operator/(double) const;
    bool operator==(const CFraction&) const;
    bool operator>(const CFraction&);
};


#endif
