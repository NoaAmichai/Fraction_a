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
        Fraction(int num, int den);
        Fraction(float flt);


        friend Fraction operator+(const Fraction &fraction1, const Fraction &fraction2);
        friend Fraction operator-(const Fraction &fraction1, const Fraction &fraction2);
        friend Fraction operator*(const Fraction &fraction1, const Fraction &fraction2);
        friend Fraction operator/(const Fraction &fraction1, const Fraction &fraction2);

        friend bool operator==(const Fraction &fraction1, const Fraction &fraction2);
        friend bool operator>(const Fraction &fraction1, const Fraction &fraction2);
        friend bool operator<(const Fraction &fraction1, const Fraction &fraction2);
        friend bool operator>=(const Fraction &fraction1, const Fraction &fraction2);
        friend bool operator<=(const Fraction &fraction1, const Fraction &fraction2);

        Fraction &operator++();  // pre-increment ++a
        Fraction operator++(int); // post-increment a++
        Fraction &operator--();  // pre-decrement --a
        Fraction operator--(int); // post-decrement a--

        friend std::ostream &operator<<(std::ostream &output, const Fraction &fraction);
        friend std::istream &operator>>(std::istream &input, Fraction &fraction);

    };
}
