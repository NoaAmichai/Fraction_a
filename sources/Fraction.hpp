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
        Fraction(float flt) : numerator(static_cast<int>(flt * ROUND)), denominator(ROUND) {}

        int getNumerator() const;

        int getDenominator() const;

        void simplfy();


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

        Fraction &operator++();  // pre-increment
        Fraction operator++(int); // post-increment
        Fraction &operator--();  // pre-decrement
        Fraction operator--(int); // post-decrement

        friend std::ostream &operator<<(std::ostream &os_, const Fraction &fraction);

        friend std::istream &operator>>(std::istream &is_, Fraction &fraction);
    };

}
