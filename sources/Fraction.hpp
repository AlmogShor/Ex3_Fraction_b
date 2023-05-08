//
// Created by shora on 2/05/2023.
//

//#ifndef EX3_FRACTION_B_FRACTION_HPP
//#define EX3_FRACTION_B_FRACTION_HPP

#pragma once

#include <iostream>

namespace ariel {

    class Fraction {
    public:
        // Constructors
        Fraction(); // Default constructor
        Fraction(int numerator, int denominator); // Conversion constructor
        Fraction(double value); // Conversion constructor from float
        Fraction(Fraction const &other); // Copy constructor
        Fraction &operator=(const Fraction &other); // Copy assignment operator
        Fraction(Fraction &&other) noexcept;        //Move constructor
        Fraction &operator=(Fraction &&other) noexcept; // Move assignment operator

        //Destructor
        ~Fraction();

        // Getters
        int getNumerator() const;
        int getDenominator() const;

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

        //helper for friend arithmetic operators for mixed types
        static Fraction from_double(double num);

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
        friend std::istream &operator>>(std::istream &in_s, Fraction &frac);
        friend std::ostream &operator<<(std::ostream &out_s, const Fraction &frac);

    private:
        int _numerator;
        int _denominator;

        // Helper functions
        void normalize();
        void normalize(int num, int den);
        int gcd(int num1, int num2) const;
    };

} // namespace ariel

//#endif //EX3_FRACTION_B_FRACTION_HPP
