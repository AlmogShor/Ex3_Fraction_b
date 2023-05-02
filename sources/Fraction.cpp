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
        const int precision = 10000; // You can adjust the precision here
        _denominator = precision;
        _numerator = static_cast<int>(round(value * precision));
        normalize();
    }

    Fraction::Fraction(Fraction const &other) : _numerator(other._numerator), _denominator(other._denominator) {}

// Getters
    int Fraction::getNumerator() const {
        return _numerator;
    }

    int Fraction::getDenominator() const {
        return _denominator;
    }

// Arithmetic operators
    Fraction Fraction::operator+(const Fraction &other) const {
        int lcm = std::lcm(_denominator, other._denominator);
        int numerator_sum = _numerator * (lcm / _denominator) + other._numerator * (lcm / other._denominator);
        return Fraction(numerator_sum, lcm);
    }

    Fraction Fraction::operator-(const Fraction &other) const {
        int lcm = std::lcm(_denominator, other._denominator);
        int numerator_diff = _numerator * (lcm / _denominator) - other._numerator * (lcm / other._denominator);
        return Fraction(numerator_diff, lcm);
    }

    Fraction Fraction::operator*(const Fraction &other) const {
        return Fraction(_numerator * other._numerator, _denominator * other._denominator);
    }

    Fraction Fraction::operator/(const Fraction &other) const {
        if (other._numerator == 0) {
            throw std::domain_error("Division by zero");
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
    std::istream &operator>>(std::istream &is, Fraction &frac) {
        int numerator, denominator;
        char separator;
        is >> numerator >> separator >> denominator;
        if (is && separator == '/') {
            frac = Fraction(numerator, denominator);
        } else {
            is.setstate(std::ios::failbit);
        }
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

    int Fraction::gcd(int a, int b) const {
        return b == 0 ? a : gcd(b, a % b);
    }

} // namespace ariel

