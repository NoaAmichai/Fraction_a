#pragma once

#include <iostream>

namespace ariel {
    class Fraction {

    private:
        int numerator, denominator;

    public:
        Fraction() : numerator(0), denominator(0) {};

        Fraction(int num, int den);

        // Conversion constructor from float
        Fraction(float f) : numerator(static_cast<int>(f * 1000)), denominator(1000) {}

        int getNumerator() const;

        int getDenominator() const;

        Fraction operator+(const Fraction &other) const;

        Fraction operator+(const float &other) const;

        friend Fraction operator+(const float &flt, const Fraction &frac);

        Fraction operator-(const Fraction &other) const;

        Fraction operator-(const float &other) const;

        friend Fraction operator-(const float &flt, const Fraction &frac);

        Fraction operator*(const Fraction &other) const;

        Fraction operator*(const float &other) const;

        friend Fraction operator*(const float &flt, const Fraction &frac);

        Fraction operator/(const Fraction &other) const;

        Fraction operator/(const float &other) const;

        friend Fraction operator/(const float &flt, const Fraction &frac);

        bool operator==(const Fraction &other) const;

        bool operator==(const float &other) const;

        friend bool operator==(const float &flt, const Fraction &frac);

        bool operator!=(const Fraction &other) const;

        bool operator!=(const float &other) const;

        friend bool operator!=(const float &flt, const Fraction &frac);

        bool operator>(const Fraction &other) const;

        bool operator>(const float &other) const;

        friend bool operator>(const float &flt, const Fraction &frac);

        bool operator<(const Fraction &other) const;

        bool operator<(const float &other) const;

        friend bool operator<(const float &flt, const Fraction &frac);

        bool operator>=(const Fraction &other) const;

        bool operator>=(const float &other) const;

        friend bool operator>=(const float &flt, const Fraction &frac);

        bool operator<=(const Fraction &other) const;

        bool operator<=(const float &other) const;

        friend bool operator<=(const float &flt, const Fraction &frac);


        Fraction &operator++(); // pre-increment
        Fraction operator++(int);// post-increment
        Fraction &operator--();  // pre-decrement
        Fraction operator--(int);  // post-decrement

        friend std::ostream &operator<<(std::ostream &os, const Fraction &f);

        friend std::istream &operator>>(std::istream &is, Fraction &f);
    };

}
