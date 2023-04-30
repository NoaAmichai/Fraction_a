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
        if (den < 0) {
            _numerator = -1 * num;
            _denominator = abs(den);
        }
        reduce();
    }

    Fraction::Fraction(float number) {
        int denominator = 1000;
        int numerator = round(number * denominator);
        while (numerator % 10 == 0 && denominator % 10 == 0) {
            numerator /= 10;
            denominator /= 10;
        }
        if (denominator < 0) {
            _numerator = -1 * numerator;
            _denominator = abs(denominator);
        } else {
            _numerator = numerator;
            _denominator = denominator;
        }
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
        long numerator_sum =
                static_cast<long>(_numerator) * other._denominator + static_cast<long>(other._numerator) * _denominator;
        long denominator_sum = static_cast<long>(_denominator) * other._denominator;
        checkOverflow(numerator_sum, denominator_sum);
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
        long numerator_sum =
                static_cast<long>(_numerator) * other._denominator - static_cast<long>(other._numerator) * _denominator;
        long denominator_sum = static_cast<long>(_denominator) * other._denominator;
        checkOverflow(numerator_sum, denominator_sum);
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
        long numerator_sum = static_cast<long>(_numerator) * other._numerator;
        long denominator_sum = static_cast<long>(_denominator) * other._denominator;
        checkOverflow(numerator_sum, denominator_sum);
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
        if (other._numerator == 0) throw runtime_error("Cannot divide by zero");
        long numerator_sum = static_cast<long>(_numerator) * other._denominator;
        long denominator_sum = static_cast<long>(_denominator) * other._numerator;
        checkOverflow(numerator_sum, denominator_sum);
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
        return ((_numerator * other._denominator) == (_denominator * other._numerator));
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

    void Fraction::checkOverflow(long numerator_sum, long denominator_sum) const {
        if (numerator_sum > INT_MAX || denominator_sum > INT_MAX || numerator_sum < INT_MIN ||
            denominator_sum < INT_MIN) {
            throw overflow_error("Fraction result is too large to be represented as an integer");
        }
    }
}