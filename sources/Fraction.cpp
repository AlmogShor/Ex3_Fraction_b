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

    Fraction::Fraction(double value) {
        const int precision = 1000; // You can adjust the precision here
        _denominator = precision;
        _numerator = static_cast<int>(round(value * precision));
        normalize();
    }

    Fraction::Fraction(Fraction const &other) : _numerator(other._numerator), _denominator(other._denominator) {}

    Fraction &Fraction::operator=(const Fraction &other) { // Copy assignment operator
        if (this != &other) {
            _numerator = other._numerator;
            _denominator = other._denominator;
        }
        return *this;
    }

    Fraction::Fraction(Fraction &&other) noexcept : _numerator(other._numerator), _denominator(other._denominator) {} // Move constructor

Fraction &Fraction::operator=(Fraction &&other) noexcept { // Move assignment operator
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
    int numerator_sum = _numerator * (lcm / _denominator) + other._numerator * (lcm / other._denominator);
    return Fraction(numerator_sum, lcm);
}

Fraction Fraction::operator-(const Fraction &other) const {
    int lcm = std::lcm(_denominator, other.getDenominator());
    int numerator_diff = _numerator * (lcm / _denominator) - other._numerator * (lcm / other._denominator);
    return Fraction(numerator_diff, lcm);
}

Fraction Fraction::operator*(const Fraction &other) const {
    return Fraction(_numerator * other._numerator, _denominator * other._denominator);
}

Fraction Fraction::operator/(const Fraction &other) const {
    if (other._numerator == 0) {
        throw std::runtime_error("Division by zero");
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
Fraction operator+(const Fraction &f1, double num) {
    Fraction f2 = Fraction::from_double(num);
    int lcm = std::lcm(f1._denominator, f2._denominator);
    int numer = f1._numerator * (lcm / f1._denominator) + f2._numerator * (lcm / f2._denominator);
    return Fraction(numer, lcm);
}

Fraction operator+(double val, const Fraction &frac) {
    return Fraction(val) + frac;
}

Fraction operator-(const Fraction &f1, double num) {
    Fraction f2 = Fraction::from_double(num);
    int lcm = std::lcm(f1._denominator, f2._denominator);
    int numer = f1._numerator * (lcm / f1._denominator) - f2._numerator * (lcm / f2._denominator);
    return Fraction(numer, lcm);
}

//helper friend function
Fraction Fraction::from_double(double num) {
    const double epsilon = 1e-10;
    int64_t denom = 1;
    while (std::abs(num - static_cast<int64_t>(num)) > epsilon && denom <= 1000000) {
        num *= 10;
        denom *= 10;
    }
    return Fraction(static_cast<int64_t>(num), denom);
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
std::istream &operator>>(std::istream &is, Fraction &frac) {
    int numerator, denominator;
    char separator;
    is >> numerator;
    if (!is) {
        return is;
    }
    is >> separator;
    if (!is || (separator != '/' && separator != ',' && !std::isspace(separator))) {
        is.setstate(std::ios::failbit);
        throw std::invalid_argument("Invalid separator");
    }
    // If separator is a space or comma, we need to consume it
    if (separator == ' ' || separator == ',') {
        is.get();
    }
    is >> denominator;
    if (!is) {
        return is;
    }
    frac = Fraction(numerator, denominator);
    return is;
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

} // namespace ariel

