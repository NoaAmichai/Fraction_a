#include "Fraction.hpp"

using namespace ariel;
using namespace std;

Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {}

int Fraction::getNumerator() const { return numerator; }

int Fraction::getDenominator() const { return denominator; }

void Fraction::simplfy() {}

Fraction Fraction::operator+(const Fraction &other) const {
    return Fraction();
}

Fraction Fraction::operator+(const float &other) const {
    return Fraction();
}

Fraction ariel::operator+(const float &flt, const Fraction &frac) {
    return Fraction();
}

Fraction Fraction::operator-(const Fraction &other) const {
    return Fraction();
}

Fraction Fraction::operator-(const float &other) const {
    return Fraction();
}

Fraction ariel::operator-(const float &flt, const Fraction &frac) {
    return Fraction();
}

Fraction Fraction::operator*(const Fraction &other) const {
    return Fraction();
}

Fraction Fraction::operator*(const float &other) const {
    return Fraction();
}

Fraction ariel::operator*(const float &flt, const Fraction &frac) {
    return Fraction();
}

Fraction Fraction::operator/(const Fraction &other) const {
    return Fraction();
}

Fraction Fraction::operator/(const float &other) const {
    return Fraction();
}

Fraction ariel::operator/(const float &flt, const Fraction &frac) {
    return Fraction();
}

bool Fraction::operator==(const Fraction &other) const {
    return false;
}

bool Fraction::operator==(const float &other) const {
    return false;
}

bool ariel::operator==(const float &flt, const Fraction &frac) {
    return false;
}

bool Fraction::operator!=(const Fraction &other) const {
    return false;
}

bool Fraction::operator!=(const float &other) const {
    return false;
}

bool ariel::operator!=(const float &flt, const Fraction &frac) {
    return false;
}

bool Fraction::operator>(const Fraction &other) const {
    return false;
}

bool Fraction::operator>(const float &other) const {
    return false;
}

bool ariel::operator>(const float &flt, const Fraction &frac) {
    return false;
}

bool Fraction::operator<(const Fraction &other) const {
    return false;
}

bool Fraction::operator<(const float &other) const {
    return false;
}

bool ariel::operator<(const float &flt, const Fraction &frac) {
    return false;
}

bool Fraction::operator>=(const Fraction &other) const {
    return false;
}

bool Fraction::operator>=(const float &other) const {
    return false;
}

bool ariel::operator>=(const float &flt, const Fraction &frac) {
    return false;
}

bool Fraction::operator<=(const Fraction &other) const {
    return false;
}

bool Fraction::operator<=(const float &other) const {
    return false;
}

bool ariel::operator<=(const float &flt, const Fraction &frac) {
    return false;
}

Fraction &Fraction::operator++() {// pre-increment
    return *this;
}

Fraction Fraction::operator++(int) {// post-increment
    return Fraction();
}

Fraction &Fraction::operator--() {// pre-increment
    return *this;
}

Fraction Fraction::operator--(int) {// post-increment
    return Fraction();
}

std::ostream &ariel::operator<<(ostream &os_, const Fraction &fraction) {
    return os_;
}

std::istream &ariel::operator>>(istream &is_, Fraction &fraction) {
    return is_;
}






