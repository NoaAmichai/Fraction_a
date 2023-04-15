#include "sources/Fraction.hpp"
#include "doctest.h"
#include <sstream>
#include <stdexcept>

using namespace ariel;
using namespace std;

TEST_CASE("test constructor throws exception when denominator is zero") {
    CHECK_THROWS(Fraction(3, 0));
}

TEST_CASE ("test fraction operations") {
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

TEST_CASE ("test fraction comparison") {
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


TEST_CASE ("test fraction increment") {
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

TEST_CASE("test fraction input and output operators") {
    Fraction a(2, 5), b(-7, 9), c(6, -13);
    stringstream ss1, ss2, ss3;
    ss1 << a;
    ss2 << b;
    ss3 << c;

    CHECK((ss1.str() == "2/5"));
    CHECK((ss2.str() == "-7/9"));
    CHECK((ss3.str() == "-6/13"));

    Fraction d, e, f;
    stringstream ss4("3 1/2");
    stringstream ss5("-2.75");
    stringstream ss6("0");
    ss4 >> d;
    ss5 >> e;
    ss6 >> f;

    CHECK((d == Fraction(7, 2)));
    CHECK((e == Fraction(-11, 4)));
    CHECK((f == Fraction(0, 1)));
}