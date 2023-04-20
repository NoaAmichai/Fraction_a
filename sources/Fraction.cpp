#include "Fraction.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>

using namespace std;

Fraction::Fraction(int num, int den) : _numerator(num), _denominator(den) {
    if (_denominator == 0) throw invalid_argument("Denominator can not be zero");
    reduce();
}

Fraction::Fraction(float number) {
    int precision = 1000;
    int numerator = floor(number * precision);
    int denominator = precision;
    while (numerator % 10 == 0 && denominator % 10 == 0) {
        numerator /= 10;
        denominator /= 10;
    }
    this->_numerator = numerator;
    this->_denominator = denominator;
    reduce();
}

void Fraction::reduce() {
    int g = gcd(_numerator, _denominator);
    _numerator = _numerator / g;
    _denominator = _denominator / g;
}

int Fraction::gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

Fraction operator+(const Fraction &fraction1, const Fraction &fraction2) {
    int temp_num = fraction1._numerator * fraction2._denominator +
                   fraction1._denominator * fraction2._numerator;
    int temp_den = fraction1._denominator * fraction2._denominator;
    return Fraction(temp_num, temp_den);
}

Fraction operator-(const Fraction &fraction1, const Fraction &fraction2) {
    return Fraction(0, 1);
}

Fraction operator*(const Fraction &fraction1, const Fraction &fraction2) {
    return Fraction(0, 1);
}

Fraction operator/(const Fraction &fraction1, const Fraction &fraction2) {
    return Fraction(0, 1);
}

bool operator==(const Fraction &fraction1, const Fraction &fraction2) {
    return (fraction1._numerator == fraction2._numerator && fraction1._denominator == fraction2._denominator);
}

bool operator>(const Fraction &fraction1, const Fraction &fraction2) {
    return false;
}

bool operator<(const Fraction &fraction1, const Fraction &fraction2) {
    return false;
}

bool operator>=(const Fraction &fraction1, const Fraction &fraction2) {
    return false;
}

bool operator<=(const Fraction &fraction1, const Fraction &fraction2) {
    return false;
}

Fraction &Fraction::operator++() {// pre-increment
    _numerator += _denominator;
    reduce();
    return *this;
}

Fraction Fraction::operator++(int) {// post-increment
    int temp_num = _numerator;
    int temp_den = _denominator;
    _numerator += _denominator;
    reduce();
    return Fraction(temp_num, temp_den);
}

Fraction &Fraction::operator--() {// pre-increment
    _numerator -= _denominator;
    reduce();
    return *this;
}

Fraction Fraction::operator--(int) {// post-increment
    int temp_num = _numerator;
    int temp_den = _denominator;
    _numerator -= _denominator;
    reduce();
    return Fraction(temp_num, temp_den);
}

std::ostream &operator<<(ostream &output, const Fraction &fraction) {
    output << ' ' << fraction._numerator << '/' << fraction._denominator << ' ';
    return output;
}

std::istream &operator>>(istream &input, Fraction &fraction) {
    char slash;
    input >> fraction._numerator >> slash >> fraction._denominator;
    fraction.reduce();
    return input;
}





