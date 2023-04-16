#pragma once

#include <iostream>

namespace ariel {

    const int ROUND = 1000;

    class Fraction {
    private:
        int numerator, denominator;
    public:
        Fraction(int num = 0, int den = 1);

        // Conversion constructor from float
        Fraction(double flt) : numerator(static_cast<int>(flt * ROUND)), denominator(ROUND) {}

        void simplfy();

        friend Fraction operator+(const Fraction &fra1, const Fraction &fra2);

        friend Fraction operator-(const Fraction &fra1, const Fraction &fra2);

        friend Fraction operator*(const Fraction &fra1, const Fraction &fra2);

        friend Fraction operator/(const Fraction &fra1, const Fraction &fra2);

        friend bool operator==(const Fraction &fra1, const Fraction &fra2);

        friend bool operator!=(const Fraction &fra1, const Fraction &fra2);

        friend bool operator>(const Fraction &fra1, const Fraction &fra2);

        friend bool operator<(const Fraction &fra1, const Fraction &fra2);

        friend bool operator>=(const Fraction &fra1, const Fraction &fra2);

        friend bool operator<=(const Fraction &fra1, const Fraction &fra2);

        Fraction &operator++();  // pre-increment ++a

        Fraction operator++(int); // post-increment a++

        Fraction &operator--();  // pre-decrement --a

        Fraction operator--(int); // post-decrement a--

        friend std::ostream &operator<<(std::ostream &os_, const Fraction &fraction);

        friend std::istream &operator>>(std::istream &is_, Fraction &fraction);
    };
}
