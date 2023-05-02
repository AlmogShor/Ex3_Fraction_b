//
// Created by shora on 2/05/2023.
//

//#ifndef EX3_FRACTION_B_NEW_FRACTION_H
//#define EX3_FRACTION_B_NEW_FRACTION_H

#pragma once


#include <iostream>

namespace ariel {

    class Fraction {

    private:
        int m_numerator;
        int m_denominator;

        void reduce();

    public:

        // constructors
        Fraction(); // Default constructor

        Fraction(int numerator, int denominator = 1); // Constructor with numerator and denominator

        Fraction(double value); // Constructor with value as a float
        Fraction(const Fraction &other); // Copy constructor

        //destructor
        ~Fraction();

        // getters for numerator and denominator
        int numerator() const { return m_numerator; }

        int denominator() const { return m_denominator; }

        // friend headers for operations with different types
        friend Fraction operator+(const Fraction &lhs, const Fraction &rhs);

        friend Fraction operator-(const Fraction &lhs, const Fraction &rhs);

        friend Fraction operator*(const Fraction &lhs, const Fraction &rhs);

        friend Fraction operator/(const Fraction &lhs, const Fraction &rhs);

        friend bool operator==(const Fraction &lhs, const Fraction &rhs);

        friend bool operator!=(const Fraction &lhs, const Fraction &rhs);

        friend bool operator<(const Fraction &lhs, const Fraction &rhs);

        friend bool operator<=(const Fraction &lhs, const Fraction &rhs);

        friend bool operator>(const Fraction &lhs, const Fraction &rhs);

        friend bool operator>=(const Fraction &lhs, const Fraction &rhs);

        friend Fraction operator+(const Fraction &lhs, double d);

        friend Fraction operator-(const Fraction &lhs, double d);

        friend Fraction operator*(const Fraction &lhs, double d);

        friend Fraction operator/(const Fraction &lhs, double d);

        friend Fraction operator+(double d, const Fraction &rhs);

        friend Fraction operator-(double d, const Fraction &rhs);

        friend Fraction operator*(double d, const Fraction &rhs);

        friend Fraction operator/(double d, const Fraction &rhs);

        Fraction &operator+=(const Fraction &rhs);

        Fraction &operator-=(const Fraction &rhs);

        Fraction &operator*=(const Fraction &rhs);

        Fraction &operator/=(const Fraction &rhs);

        // prefix and postfix increment and decrement operators
        Fraction &operator++(); // prefix increment operator
        Fraction operator++(int); // postfix increment operator
        Fraction &operator--(); // prefix decrement operator
        Fraction operator--(int); // postfix decrement operator
    };

    // non-member functions for arithmetic operations
    Fraction operator+(const Fraction &lhs, const Fraction &rhs);

    Fraction operator-(const Fraction &lhs, const Fraction &rhs);

    Fraction operator*(const Fraction &lhs, const Fraction &rhs);

    Fraction operator/(const Fraction &lhs, const Fraction &rhs);

    friend bool operator==(const Fraction &lhs, const Fraction &rhs);

    friend bool operator!=(const Fraction &lhs, const Fraction &rhs);

    friend bool operator<(const Fraction &lhs, const Fraction &rhs);

    friend bool operator<=(const Fraction &lhs, const Fraction &rhs);

    friend bool operator>(const Fraction &lhs, const Fraction &rhs);

    friend bool operator>=(const Fraction &lhs, const Fraction &rhs);

    Fraction operator+(const Fraction &lhs, double d);

    Fraction operator-(const Fraction &lhs, double d);

    Fraction operator*(const Fraction &lhs, double d);

    Fraction operator/(const Fraction &lhs, double d);

    Fraction operator+(double d, const Fraction &rhs);

    Fraction operator-(double d, const Fraction &rhs);

    Fraction operator*(double d, const Fraction &rhs);

    Fraction operator/(double d, const Fraction &rhs);

    // output and input stream operators
    friend std::ostream &operator<<(std::ostream &os, const Fraction &frac);

    friend std::istream &operator>>(std::istream &is, Fraction &frac);

}


//#endif //EX3_FRACTION_B_NEW_FRACTION_H
