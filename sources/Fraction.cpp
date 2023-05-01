#include <cmath>
#include <climits>
#include "Fraction.hpp"

using namespace std;
namespace ariel {
    Fraction::Fraction() : _numerator(0), _denominator(1) {}

    Fraction::Fraction(int num, int den) : _numerator(num), _denominator(den) {
        if (num != 0 && den == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        if (num > INT_MAX || den > INT_MAX) {
            throw overflow_error("Numerator or denominator is too large.");
        }
        reduce();
    }

    Fraction::Fraction(float number) : _numerator(number * 1000), _denominator(1000) {
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
        if (_denominator < 0) {
            _numerator = -1 * _numerator;
            _denominator = -1 * _denominator;
        }
    }

// Calculates the greatest common divisor (GCD) of two integers
    int Fraction::gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    Fraction operator+(const Fraction &fraction1, const Fraction &fraction2) {
        long numerator_sum =
                static_cast<long>(fraction1._numerator) * fraction2._denominator +
                static_cast<long>(fraction2._numerator) * fraction1._denominator;
        long denominator_sum = static_cast<long>(fraction1._denominator) * fraction2._denominator;
        checkOverflow(numerator_sum, denominator_sum);
        int new_num = fraction1._numerator * fraction2._denominator +
                      fraction1._denominator * fraction2._numerator;
        int new_den = fraction1._denominator * fraction2._denominator;
        Fraction res(new_num, new_den);
        res.reduce();
        return res;
    }


    Fraction operator-(const Fraction &fraction1, const Fraction &fraction2) {
        long numerator_sum =
                static_cast<long>(fraction1._numerator) * fraction2._denominator -
                static_cast<long>(fraction2._numerator) * fraction1._denominator;
        long denominator_sum = static_cast<long>(fraction1._denominator) * fraction2._denominator;
        checkOverflow(numerator_sum, denominator_sum);
        int new_num = fraction1._numerator * fraction2._denominator -
                      fraction1._denominator * fraction2._numerator;
        int new_den = fraction1._denominator * fraction2._denominator;
        Fraction res(new_num, new_den);
        res.reduce();
        return res;
    }

    Fraction operator*(const Fraction &fraction1, const Fraction &fraction2) {
        long numerator_sum = static_cast<long>(fraction1._numerator) * fraction2._numerator;
        long denominator_sum = static_cast<long>(fraction1._denominator) * fraction2._denominator;
        checkOverflow(numerator_sum, denominator_sum);
        int new_num = fraction1._numerator * fraction2._numerator;
        int new_den = fraction1._denominator * fraction2._denominator;
        Fraction res(new_num, new_den);
        res.reduce();
        return res;
    }

    Fraction operator/(const Fraction &fraction1, const Fraction &fraction2) {
        if (fraction2._numerator == 0) throw runtime_error("Cannot divide by zero");
        long numerator_sum = static_cast<long>(fraction1._numerator) * fraction2._denominator;
        long denominator_sum = static_cast<long>(fraction1._denominator) * fraction2._numerator;
        checkOverflow(numerator_sum, denominator_sum);
        int new_num = fraction1._numerator * fraction2._denominator;
        int new_den = fraction1._denominator * fraction2._numerator;
        Fraction res(new_num, new_den);
        res.reduce();
        return res;
    }

    bool operator==(const Fraction &fraction1, const Fraction &fraction2) {
        int frac1 = (int) (fraction1._numerator * 1000 / fraction1._denominator) % 1000;
        int frac2 = (int) (fraction2._numerator * 1000 / fraction2._denominator) % 1000;
        return frac1 == frac2;
    }

    bool operator>(const Fraction &fraction1, const Fraction &fraction2) {
        return (fraction1._numerator * fraction2._denominator) > (fraction2._numerator * fraction1._denominator);
    }

    bool operator<(const Fraction &fraction1, const Fraction &fraction2) {
        return (fraction1._numerator * fraction2._denominator) < (fraction2._numerator * fraction1._denominator);
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
        return *this;
    }

    // post-increment
    Fraction Fraction::operator++(int) {
        int temp_num = _numerator;
        int temp_den = _denominator;
        _numerator += _denominator;
        return Fraction(temp_num, temp_den);
    }

    // pre-increment
    Fraction &Fraction::operator--() {
        _numerator -= _denominator;
        return *this;
    }

    // post-increment
    Fraction Fraction::operator--(int) {
        int temp_num = _numerator;
        int temp_den = _denominator;
        _numerator -= _denominator;
        return Fraction(temp_num, temp_den);
    }

    std::ostream &operator<<(ostream &output, const Fraction &fraction) {
        output << fraction._numerator << '/' << fraction._denominator;
        return output;
    }

    std::istream &operator>>(std::istream &input, Fraction &fraction) {
//        char comma_or_space;
        if (!(input >> fraction._numerator)) {
            throw runtime_error("Invalid numerator");
        }
//        if (!(input >> comma_or_space) || (comma_or_space != ',' && comma_or_space != ' ')) {
//            throw std::invalid_argument("Invalid separator");
//        }
        if (!(input >> fraction._denominator)) {
            throw runtime_error("Invalid denominator");
        }
        if (fraction._denominator < 0) {
            fraction._numerator = -1 * fraction._numerator;
            fraction._denominator = abs(fraction._denominator);
        }
        return input;
    }

    void checkOverflow(long numerator_sum, long denominator_sum) {
        if (numerator_sum > INT_MAX || denominator_sum > INT_MAX || numerator_sum < INT_MIN ||
            denominator_sum < INT_MIN) {
            throw overflow_error("Fraction result is too large to be represented as an integer");
        }
    }

}