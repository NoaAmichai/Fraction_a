#pragma once

#include <stdexcept>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

namespace ariel {
    class Fraction {

    private:
        int _numerator, _denominator;
        int gcd(int num, int den);
        void reduce();

    public:
        Fraction();
        Fraction(int num, int den);
        Fraction(float number);

        int getNumerator() const;
        int getDenominator() const;

        Fraction operator+(const Fraction &other) const;
        Fraction operator+(const float &number) const;
        friend Fraction operator+(const float &number, const Fraction &other);

        Fraction operator-(const Fraction &other) const;
        Fraction operator-(const float &number) const;
        friend Fraction operator-(const float &number, const Fraction &other);

        Fraction operator*(const Fraction &other) const;
        Fraction operator*(const float &number) const;
        friend Fraction operator*(const float &number, const Fraction &other);

        Fraction operator/(const Fraction &other) const;
        Fraction operator/(const float &number) const;
        friend Fraction operator/(const float &number, const Fraction &other);

        bool operator==(const Fraction &other) const;
        bool operator==(const float &number) const;
        friend bool operator==(const float &number, const Fraction &other);

        bool operator>(const Fraction &other) const;
        bool operator>(const float &number) const;
        friend bool operator>(const float &number, const Fraction &other);

        bool operator<(const Fraction &other) const;
        bool operator<(const float &number) const;
        friend bool operator<(const float &number, const Fraction &other);

        bool operator>=(const Fraction &other) const;
        bool operator>=(const float &number) const;
        friend bool operator>=(const float &number, const Fraction &other);

        bool operator<=(const Fraction &other) const;
        bool operator<=(const float &number) const;
        friend bool operator<=(const float &number, const Fraction &other);

        Fraction &operator++();  // pre-increment ++a
        Fraction operator++(int); // post-increment a++
        Fraction &operator--();  // pre-decrement --a
        Fraction operator--(int); // post-decrement a--

        friend std::ostream &operator<<(std::ostream &output, const Fraction &fraction);
        friend std::istream &operator>>(std::istream &input, Fraction &fraction);
    };
}
