//
// Created by shora on 2/05/2023.
//

#ifndef EX3_FRACTION_B_FRACTION_HPP
#define EX3_FRACTION_B_FRACTION_HPP

#include <iostream>

namespace ariel {

    class Fraction {
    public:
        // Constructors
        Fraction();
        Fraction(int numerator = 0, int denominator = 1);
        Fraction(double value);
        Fraction(Fraction const &other);

        // Getters
        int get_numerator() const;
        int get_denominator() const;

        // Arithmetic operators
        Fraction operator+(const Fraction &other) const;
        Fraction operator-(const Fraction &other) const;
        Fraction operator*(const Fraction &other) const;
        Fraction operator/(const Fraction &other) const;

        // Comparison operators
        bool operator==(const Fraction &other) const;
        bool operator!=(const Fraction &other) const;
        bool operator<(const Fraction &other) const;
        bool operator<=(const Fraction &other) const;
        bool operator>(const Fraction &other) const;
        bool operator>=(const Fraction &other) const;

        // Unary operators
        Fraction operator+() const;
        Fraction operator-() const;

        // Increment and decrement operators
        Fraction &operator++();          // Prefix increment
        Fraction operator++(int);        // Postfix increment
        Fraction &operator--();          // Prefix decrement
        Fraction operator--(int);        // Postfix decrement

        // Friend arithmetic operators for mixed types
        friend Fraction operator+(const Fraction &frac, double val);
        friend Fraction operator+(double val, const Fraction &frac);
        friend Fraction operator-(const Fraction &frac, double val);
        friend Fraction operator-(double val, const Fraction &frac);
        friend Fraction operator*(const Fraction &frac, double val);
        friend Fraction operator*(double val, const Fraction &frac);
        friend Fraction operator/(const Fraction &frac, double val);
        friend Fraction operator/(double val, const Fraction &frac);

        // Friend comparison operators for mixed types
        friend bool operator==(const Fraction &frac, double val);
        friend bool operator==(double val, const Fraction &frac);
        friend bool operator!=(const Fraction &frac, double val);
        friend bool operator!=(double val, const Fraction &frac);
        friend bool operator<(const Fraction &frac, double val);
        friend bool operator<(double val, const Fraction &frac);
        friend bool operator<=(const Fraction &frac, double val);
        friend bool operator<=(double val, const Fraction &frac);
        friend bool operator>(const Fraction &frac, double val);
        friend bool operator>(double val, const Fraction &frac);
        friend bool operator>=(const Fraction &frac, double val);
        friend bool operator>=(double val, const Fraction &frac);

        // Input and output operators
        friend std::istream &operator>>(std::istream &is, Fraction &frac);
        friend std::ostream &operator<<(std::ostream &os, const Fraction &frac);

    private:
        int _numerator;
        int _denominator;

        // Helper functions
        void normalize();
        int gcd(int a, int b) const;
    };

} // namespace ariel

#endif //EX3_FRACTION_B_FRACTION_HPP
