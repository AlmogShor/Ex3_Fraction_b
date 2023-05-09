//
// Created by shora on 2/05/2023.
//

#include "Fraction.hpp"
#include <stdexcept>
#include <cmath>
#include <numeric>

namespace ariel {

// Constructors
    Fraction::Fraction() : _numerator(0), _denominator(1) {}

    Fraction::Fraction(int numerator, int denominator) : _numerator(numerator), _denominator(denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        normalize();
    }

    Fraction::Fraction(float num1) : Fraction((int) (num1 * 1000), 1000) {}

    Fraction::Fraction(Fraction const &other) : _numerator(other._numerator), _denominator(other._denominator) {}

    Fraction &Fraction::operator=(const Fraction &other) { // Copy assignment operator
        if (this != &other) {
            _numerator = other._numerator;
            _denominator = other._denominator;
        }
        return *this;
    }

    Fraction::Fraction(Fraction &&other)

    noexcept :
    _numerator(other
    ._numerator),
    _denominator(other
    ._denominator) {
} // Move constructor

Fraction &Fraction::operator=(Fraction &&other)

noexcept { // Move assignment operator
if (this != &other) {
_numerator = other._numerator;
_denominator = other._denominator;
}
return *this;
}

// Destructor
Fraction::~Fraction() {}

// Getters
int Fraction::getNumerator() const {
    return _numerator;
}

int Fraction::getDenominator() const {
    return _denominator;
}

// Arithmetic operators
Fraction Fraction::operator+(const Fraction &other) const {
    int lcm = std::lcm(_denominator, other.getDenominator());
    int numerator_sum1 = _numerator * (lcm / _denominator);
    int numerator_sum2 = other._numerator * (lcm / other._denominator);

    if (add_overflow(numerator_sum1, numerator_sum2)) {
        throw std::overflow_error("Overflow in addition");
    }

    return Fraction(numerator_sum1 + numerator_sum2, lcm);
}

Fraction Fraction::operator-(const Fraction &other) const {
    int lcm = std::lcm(_denominator, other.getDenominator());
    int numerator_diff1 = _numerator * (lcm / _denominator);
    int numerator_diff2 = other._numerator * (lcm / other._denominator);

    if (sub_overflow(numerator_diff1, numerator_diff2)) {
        throw std::overflow_error("Overflow in subtraction");
    }


    int result_numerator = numerator_diff1 - numerator_diff2;


    return Fraction(result_numerator, lcm);
}


Fraction Fraction::operator*(const Fraction &other) const {
    if (mul_overflow(_numerator, other._numerator) || mul_overflow(_denominator, other._denominator)) {
        throw std::overflow_error("Overflow in multiplication");
    }

    return Fraction(_numerator * other._numerator, _denominator * other._denominator);
}

Fraction Fraction::operator/(const Fraction &other) const {
    if (other._numerator == 0) {
        throw std::runtime_error("Division by zero");
    }

    if (mul_overflow(_numerator, other._denominator) || mul_overflow(_denominator, other._numerator)) {
        throw std::overflow_error("Overflow in division");
    }

    return Fraction(_numerator * other._denominator, _denominator * other._numerator);
}

// Comparison operators
bool Fraction::operator==(const Fraction &other) const {
    return _numerator == other._numerator && _denominator == other._denominator;
}

bool Fraction::operator!=(const Fraction &other) const {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction &other) const {
    int lcm = std::lcm(_denominator, other._denominator);
    return _numerator * (lcm / _denominator) < other._numerator * (lcm / other._denominator);
}

bool Fraction::operator<=(const Fraction &other) const {
    return *this < other || *this == other;
}

bool Fraction::operator>(const Fraction &other) const {
    return !(*this <= other);
}

bool Fraction::operator>=(const Fraction &other) const {
    return !(*this < other);
}

// Unary operators
Fraction Fraction::operator+() const {
    return *this;
}

Fraction Fraction::operator-() const {
    return Fraction(-_numerator, _denominator);
}

// Increment and decrement operators
Fraction &Fraction::operator++() {
    _numerator += _denominator;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    ++(*this);
    return temp;
}

Fraction &Fraction::operator--() {
    _numerator -= _denominator;
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction temp = *this;
    --(*this);
    return temp;
}

// Friend arithmetic operators for mixed types
Fraction operator+(const Fraction &frac, double val) {
    return frac + Fraction(val);
}

Fraction operator+(double val, const Fraction &frac) {
    return Fraction(val) + frac;
}

Fraction operator-(const Fraction &frac, double val) {
    return frac - Fraction(val);
}

Fraction operator-(double val, const Fraction &frac) {
    return Fraction(val) - frac;
}


Fraction operator*(const Fraction &frac, double val) {
    return frac * Fraction(val);
}

Fraction operator*(double val, const Fraction &frac) {
    return Fraction(val) * frac;
}

Fraction operator/(const Fraction &frac, double val) {
    return frac / Fraction(val);
}

Fraction operator/(double val, const Fraction &frac) {
    return Fraction(val) / frac;
}

// Friend comparison operators for mixed types
bool operator==(const Fraction &frac, double val) {
    return frac == Fraction(val);
}

bool operator==(double val, const Fraction &frac) {
    return Fraction(val) == frac;
}

bool operator!=(const Fraction &frac, double val) {
    return frac != Fraction(val);
}

bool operator!=(double val, const Fraction &frac) {
    return Fraction(val) != frac;
}

bool operator<(const Fraction &frac, double val) {
    return frac < Fraction(val);
}

bool operator<(double val, const Fraction &frac) {
    return Fraction(val) < frac;
}

bool operator<=(const Fraction &frac, double val) {
    return frac <= Fraction(val);
}

bool operator<=(double val, const Fraction &frac) {
    return Fraction(val) <= frac;
}

bool operator>(const Fraction &frac, double val) {
    return frac > Fraction(val);
}

bool operator>(double val, const Fraction &frac) {
    return Fraction(val) > frac;
}

bool operator>=(const Fraction &frac, double val) {
    return frac >= Fraction(val);
}

bool operator>=(double val, const Fraction &frac) {
    return Fraction(val) >= frac;
}

// Input and output operators
std::istream &operator>>(std::istream &i_s, Fraction &frac) {
    int numerator, denominator;
    // Insert to the input stream.
    i_s >> numerator >> denominator;
    // If frac is null, throw input.
    if (i_s.fail()) {
        throw std::runtime_error("Error: Input failed");
    }
    // If denominator is 0, throw exception.
    if (denominator == 0) {
        throw std::runtime_error("You can't assign 0 to the fraction's denominator!");
    }

    // Assign the data and return the input.
    frac = Fraction(numerator, denominator);
    return i_s;
}


std::ostream &operator<<(std::ostream &os, const Fraction &frac) {
    os << frac.getNumerator() << "/" << frac.getDenominator();
    return os;
}

// Helper functions
void Fraction::normalize() {
    int gcd_value = gcd(_numerator, _denominator);
    _numerator /= gcd_value;
    _denominator /= gcd_value;
    if (_denominator < 0) {
        _numerator = -_numerator;
        _denominator = -_denominator;
    }
}

void Fraction::normalize(int num, int den) {
    int gcd_value = gcd(num, den);
    _numerator /= gcd_value;
    _denominator /= gcd_value;
    if (_denominator < 0) {
        _numerator = -_numerator;
        _denominator = -_denominator;
    }
}

int Fraction::gcd(int num1, int num2) const {
    return num2 == 0 ? num1 : gcd(num2, num1 % num2);
}

// overflow check functions
bool Fraction::add_overflow(int num1, int num2) const {
    return ((num2 > 0) && (num1 > std::numeric_limits<int>::max() - num2)) ||
           ((num2 < 0) && (num1 < std::numeric_limits<int>::min() - num2));
}

bool Fraction::mul_overflow(int num1, int num2) const {
    if (num1 == 0 || num2 == 0) {
        return false;
    }
    int result = num1 * num2;
    return num1 != result / num2;
}

bool Fraction::sub_overflow(int num1, int num2) const {
    return ((num2 > 0) && (num1 < std::numeric_limits<int>::min() + num2)) ||
           ((num2 < 0) && (num1 > std::numeric_limits<int>::max() + num2));
}


} // namespace ariel

