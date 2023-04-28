#include <cmath>
#include "Fraction.hpp"

using namespace std;
namespace ariel {

    Fraction::Fraction(int num, int den) : _numerator(num), _denominator(den) {
        if (den == 0) throw invalid_argument("Cannot divide by zero");
        reduce();
    }

    Fraction::Fraction() : _numerator(0), _denominator(1) {}

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

    int Fraction::getNumerator() const {
        return _numerator;
    }

    int Fraction::getDenominator() const {
        return _denominator;
    }

// Reduces the fraction to its simplest form
    void Fraction::reduce() {
        int g = gcd(_numerator, _denominator);
        _numerator = _numerator / g;
        _denominator = _denominator / g;
    }

// Calculates the greatest common divisor (GCD) of two integers
    int Fraction::gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    Fraction operator+(const Fraction &fraction1, const Fraction &fraction2) {
        int new_num = fraction1._numerator * fraction2._denominator +
                      fraction1._denominator * fraction2._numerator;
        int new_den = fraction1._denominator * fraction2._denominator;
        return Fraction(new_num, new_den);
    }

    Fraction operator-(const Fraction &fraction1, const Fraction &fraction2) {
        int new_num = fraction1._numerator * fraction2._denominator -
                      fraction1._denominator * fraction2._numerator;
        int new_den = fraction1._denominator * fraction2._denominator;
        return Fraction(new_num, new_den);
    }

    Fraction operator*(const Fraction &fraction1, const Fraction &fraction2) {
        int new_num = fraction1._numerator * fraction2._numerator;
        int new_den = fraction1._denominator * fraction2._denominator;
        return Fraction(new_num, new_den);
    }

    Fraction operator/(const Fraction &fraction1, const Fraction &fraction2) {
        if (fraction2._numerator == 0) throw invalid_argument("Cannot divide by zero");
        int new_num = fraction1._numerator * fraction2._denominator;
        int new_den = fraction1._denominator * fraction2._numerator;
        return Fraction(new_num, new_den);
    }

    bool operator==(const Fraction &fraction1, const Fraction &fraction2) {
        return (fraction1._numerator == fraction2._numerator && fraction1._denominator == fraction2._denominator);
    }

    bool operator<(const Fraction &fraction1, const Fraction &fraction2) {
        return fraction1._numerator * fraction2._denominator < fraction2._numerator * fraction1._denominator;
    }

    bool operator>(const Fraction &fraction1, const Fraction &fraction2) {
        return fraction2 < fraction1;
    }

    bool operator>=(const Fraction &fraction1, const Fraction &fraction2) {
        return !(fraction1 < fraction2);
    }

    bool operator<=(const Fraction &fraction1, const Fraction &fraction2) {
        return !(fraction1 > fraction2);
    }

    // pre-increment
    Fraction &Fraction::operator++() {
        _numerator += _denominator;
        reduce();
        return *this;
    }

// post-increment
    Fraction Fraction::operator++(int) {
        int temp_num = _numerator;
        int temp_den = _denominator;
        _numerator += _denominator;
        reduce();
        return Fraction(temp_num, temp_den);
    }

// pre-increment
    Fraction &Fraction::operator--() {
        _numerator -= _denominator;
        reduce();
        return *this;
    }

// post-increment
    Fraction Fraction::operator--(int) {
        int temp_num = _numerator;
        int temp_den = _denominator;
        _numerator -= _denominator;
        reduce();
        return Fraction(temp_num, temp_den);
    }


    std::ostream &operator<<(ostream &output, const Fraction &fraction) {
        output << fraction._numerator << '/' << fraction._denominator;
        return output;
    }

    std::istream &operator>>(std::istream &input, Fraction &fraction) {
//        char comma_or_space;
        if (!(input >> fraction._numerator)) {
            throw std::invalid_argument("Invalid numerator");
        }
//        if (!(input >> comma_or_space) || (comma_or_space != ',' && comma_or_space != ' ')) {
//            throw std::invalid_argument("Invalid separator");
//        }
        if (!(input >> fraction._denominator)) {
            throw std::invalid_argument("Invalid denominator");
        }
        fraction.reduce();
        return input;
    }
}