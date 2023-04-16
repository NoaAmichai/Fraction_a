#include "Fraction.hpp"

using namespace ariel;
using namespace std;

Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {}

void Fraction::simplfy() {}

Fraction ariel::operator+(const Fraction &fra1, const Fraction &fra2) {
    return Fraction();
}

Fraction ariel::operator-(const Fraction &fra1, const Fraction &fra2) {
    return Fraction();
}

Fraction ariel::operator*(const Fraction &fra1, const Fraction &fra2) {
    return Fraction();
}

Fraction ariel::operator/(const Fraction &fra1, const Fraction &fra2) {
    return Fraction();
}

bool ariel::operator==(const Fraction &fra1, const Fraction &fra2) {
    return false;
}

bool ariel::operator!=(const Fraction &fra1, const Fraction &fra2) {
    return false;
}

bool ariel::operator>(const Fraction &fra1, const Fraction &fra2) {
    return false;
}

bool ariel::operator<(const Fraction &fra1, const Fraction &fra2) {
    return false;
}

bool ariel::operator>=(const Fraction &fra1, const Fraction &fra2) {
    return false;
}

bool ariel::operator<=(const Fraction &fra1, const Fraction &fra2) {
    return false;
}

Fraction &Fraction::operator++() {// pre-increment
    return *this;
}

Fraction Fraction::operator++(int) {// post-increment
    return Fraction();
}

Fraction &Fraction::operator--() {// pre-increment
    return *this;
}

Fraction Fraction::operator--(int) {// post-increment
    return Fraction();
}

std::ostream &ariel::operator<<(ostream &os_, const Fraction &fraction) {
    return os_;
}

std::istream &ariel::operator>>(istream &is_, Fraction &fraction) {
    return is_;
}





