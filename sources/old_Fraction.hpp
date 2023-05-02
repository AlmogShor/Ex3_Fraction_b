//
// Created by shora on 15/04/2023.
//

#pragma once

#include <iostream>

namespace ariel {

    class Fraction {
    public:
        // Constructors
        Fraction();                             // Default constructor
        Fraction(int numerator, int denominator); // Constructor with numerator and denominator
        Fraction(double value);                 // Constructor with value as a float

        // Arithmetic operators
        Fraction operator+(const Fraction &other) const;  // Addition
        Fraction operator-(const Fraction &other) const;  // Subtraction
        Fraction operator*(const Fraction &other) const;  // Multiplication
        Fraction operator/(const Fraction &other) const;  // Division
        Fraction operator+(double value) const;           // Addition with a float value from the left
        Fraction operator-(double value) const;           // Subtraction with a float value from the left
        Fraction operator*(double value) const;           // Multiplication with a float value from the left
        Fraction operator/(double value) const;           // Division with a float value from the left

        friend Fraction operator+(double value, const Fraction& fraction); //Addition with a float value from the right
        friend Fraction operator-(double value, const Fraction& fraction); //Subtraction with a float value from the right
        friend Fraction operator*(double value, const Fraction& fraction); //Multiplication with a float value from the right
        friend Fraction operator/(double value, const Fraction& fraction); //Division with a float value from the right
        // Comparison operators
        bool operator==(const Fraction &other) const;  // Equality
        bool operator!=(const Fraction &other) const;  // Inequality
        bool operator>(const Fraction &other) const;   // Greater than
        bool operator<(const Fraction &other) const;   // Less than
        bool operator>=(const Fraction &other) const;  // Greater than or equal to
        bool operator<=(const Fraction &other) const;  // Less than or equal to
        bool operator==(double value) const;           // Equality with a float value from the left
        bool operator!=(double value) const;           // Inequality with a float value from the left
        bool operator>(double value) const;            // Greater than a float value from the left
        bool operator<(double value) const;            // Less than a float value from the left
        bool operator>=(double value) const;           // Greater than or equal to a float value from the left
        bool operator<=(double value) const;           // Less than or equal to a float value from the left

        friend bool operator==(double value, const Fraction& fraction); //Equality with a float value from the right
        friend bool operator!=(double value, const Fraction& fraction); //Inequality with a float value from the right
        friend bool operator>(double value, const Fraction& fraction); //Greater than a float value from the right
        friend bool operator<(double value, const Fraction& fraction); //Less than a float value from the right
        friend bool operator>=(double value, const Fraction& fraction); //Greater than or equal to a float value from the right
        friend bool operator<=(double value, const Fraction& fraction); //Less than or equal to a float value from the right


        // Increment and decrement operators
        Fraction &operator++();    // Prefix increment
        Fraction operator++(int);  // Postfix increment
        Fraction &operator--();    // Prefix decrement
        Fraction operator--(int);  // Postfix decrement

        // Input and output operators
//        friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction);  // Output
//        friend std::istream &operator>>(std::istream &is, Fraction &fraction);        // Input

        friend std::ostream& operator<<(std::ostream &os, const Fraction &fraction); // Output
        friend std::istream& operator>>(std::istream &is, Fraction &fraction);      // Input

        // getter functions to help handling the input and output and for testing
        int getNumerator() const {
            return numerator;
        }

        int getDenominator() const {
            return denominator;
        }

        // Setter functions to help handling the input and output and for testing
        void setNumerator(int numerator) {
            this->numerator = numerator;
        }

        void setDenominator(int denominator) {
            this->denominator = denominator;
        }


    private:
        mutable int numerator;   // Numerator of the fraction
        mutable int denominator; // Denominator of the fraction

        // Helper functions to reduce the fraction to its simplest form
        void reduce() const;

        int gcd(int a, int b) const;
    };

} // namespace ariel

