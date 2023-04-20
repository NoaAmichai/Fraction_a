#include "sources/Fraction.hpp"
#include "doctest.h"
#include <sstream>
#include <stdexcept>

using namespace ariel;
using namespace std;


TEST_CASE("Fraction constructor should handle zero as the denominator")
{
    CHECK_THROWS(Fraction(1, 0));
    CHECK_THROWS(Fraction(-1, 0));
    CHECK_THROWS(Fraction(0, 0));
}

TEST_CASE(" Fraction constructor should reduce the fraction")
{
    Fraction a (-4, 8);
    Fraction b (-9, 3);
    CHECK((a == Fraction(-1, 2)));
    CHECK((b == Fraction(-3, 1)));
}

TEST_CASE("Arithmetics with fractions should handle fractions with a numerator of zero")
{
    Fraction a (0, 5);
    Fraction b (1, 3);

    CHECK((a + b == Fraction(1, 3)));
    CHECK((a - b == Fraction(-1, 3)));
    CHECK((a * b == Fraction(0, 1)));
    CHECK_THROWS(b/a);
}

TEST_CASE ("Test fraction operations") {
    Fraction a(1, 2);
    Fraction b(1, 3);
    Fraction c = a + b;
    CHECK((c == Fraction(5, 6)));

    c = a - b;
    CHECK((c == Fraction(1, 6)));

    c = a * b;
    CHECK((c == Fraction(1, 6)));

    c = a / b;
    CHECK((c == Fraction(3, 2)));
}

TEST_CASE ("Test fraction comparison") {
    Fraction a(1, 2);
    Fraction b(1, 3);
    Fraction c(2, 4);
    CHECK((a == c));
    CHECK_FALSE((a == b));
    CHECK_FALSE((c == b));

    CHECK((a > b));
    CHECK((b < a));
    CHECK((a >= c));
    CHECK((a <= c));
}


TEST_CASE ("Test fraction increment") {
    Fraction a(1, 2);
    Fraction b = ++a;
    CHECK((a == Fraction(3, 2)));
    CHECK((b == a));

    a = Fraction(1, 2);
    b = a++;
    CHECK((a == Fraction(3, 2)));
    CHECK((b == Fraction(1, 2)));

    a = Fraction(0, 2);
    b = --a;
    CHECK((a == Fraction(-2, 2)));
    CHECK((b == a));

    a = Fraction(0, 2);
    b = a--;
    CHECK((a == Fraction(-2, 2)));
    CHECK((b == Fraction(0, 2)));
}
