#include <cmath>
#include "Fraction.hpp"

using namespace std;
namespace ariel {

    Fraction::Fraction() : _numerator(0), _denominator(1) {}

    Fraction::Fraction(int num, int den) : _numerator(num), _denominator(den) {
        if (_denominator == 0) throw invalid_argument("Cannot divide by zero");
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
        _numerator = numerator;
        _denominator = denominator;
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
        return b == 0 ? a : gcd(b, a % b);
    }

    Fraction Fraction::operator+(const Fraction &other) const {
        int new_num = _numerator * other._denominator +
                      _denominator * other._numerator;
        int new_den = _denominator * other._denominator;
        return Fraction(new_num, new_den);
    }

    Fraction Fraction::operator+(const float &number) const {
        return *this + Fraction(number);
    }

    Fraction operator+(const float &number, const Fraction &other) {
        return Fraction(number) + other;
    }

    Fraction Fraction::operator-(const Fraction &other) const {
        int new_num = _numerator * other._denominator -
                      _denominator * other._numerator;
        int new_den = _denominator * other._denominator;
        return Fraction(new_num, new_den);
    }

    Fraction Fraction::operator-(const float &number) const {
        return *this - Fraction(number);
    }

    Fraction operator-(const float &number, const Fraction &other) {
        return Fraction(number) - other;
    }

    Fraction Fraction::operator*(const Fraction &other) const {
        int new_num = _numerator * other._numerator;
        int new_den = _denominator * other._denominator;
        return Fraction(new_num, new_den);
    }

    Fraction Fraction::operator*(const float &number) const {
        return *this * Fraction(number);
    }

    Fraction operator*(const float &number, const Fraction &other) {
        return Fraction(number) * other;
    }

    Fraction Fraction::operator/(const Fraction &other) const {
        if (other._numerator == 0) throw invalid_argument("Cannot divide by zero");
        int new_num = _numerator * other._denominator;
        int new_den = _denominator * other._numerator;
        return Fraction(new_num, new_den);
    }

    Fraction Fraction::operator/(const float &number) const {
        return *this / Fraction(number);
    }

    Fraction operator/(const float &number, const Fraction &other) {
        return Fraction(number) / other;
    }

    bool Fraction::operator==(const Fraction &other) const {
        return ((_numerator == other._numerator) && (_denominator == other._denominator));
    }

    bool Fraction::operator==(const float &number) const {
        return *this == Fraction(number);
    }

    bool operator==(const float &number, const Fraction &other) {
        return Fraction(number) == other;
    }

    bool Fraction::operator<(const Fraction &other) const {
        return (_numerator * other._denominator) < (other._numerator * _denominator);
    }

    bool Fraction::operator<(const float &number) const {
        return *this < Fraction(number);
    }

    bool operator<(const float &number, const Fraction &other) {
        return Fraction(number) < other;
    }

    bool Fraction::operator>(const Fraction &other) const {
        return (_numerator * other._denominator) > (other._numerator * _denominator);
    }

    bool Fraction::operator>(const float &number) const {
        return *this > Fraction(number);
    }

    bool operator>(const float &number, const Fraction &other) {
        return Fraction(number) > other;
    }

    bool Fraction::operator>=(const Fraction &other) const {
        return !(*this < other);
    }

    bool Fraction::operator>=(const float &number) const {
        return !(*this < Fraction(number));
    }

    bool operator>=(const float &number, const Fraction &other) {
        return !(Fraction(number) < other);
    }

    bool Fraction::operator<=(const Fraction &other) const {
        return !(*this > other);
    }

    bool Fraction::operator<=(const float &number) const {
        return !(*this > Fraction(number));
    }

    bool operator<=(const float &number, const Fraction &other) {
        return !(Fraction(number) > other);
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