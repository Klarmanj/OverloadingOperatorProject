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