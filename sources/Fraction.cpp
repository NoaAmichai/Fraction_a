#include "Fraction.hpp"

using namespace ariel;
using namespace std;

Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

// Input and output operators
std::ostream &ariel::operator<<(ostream &os, const Fraction &f) {
    os << f.numerator << "/" << f.denominator;
    return os;
}

std::istream &ariel::operator>>(istream &is, Fraction &f) {
    int n, d;
    is >> n >> d;
    f = Fraction(n, d);
    return is;
}






