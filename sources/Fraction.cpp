//
// Created by shora on 15/04/2023.
//

#include "Fraction.hpp"
#include <iostream>

using namespace std;
using namespace ariel;
namespace ariel {
//Ctors

    Fraction::Fraction() {
        this->numerator = 0;
        this->denominator = 1;
        this->reduce();
    }

    Fraction::Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("Denominator can't be 0");
        }
        this->numerator = numerator;
        this->denominator = denominator;
        this->reduce();
    }

    Fraction::Fraction(double value) {
        this->numerator = value * 1000;
        this->denominator = 1000;
        this->reduce();
    }

/**
 * Arithmetic operators
 */

    Fraction Fraction::operator+(const Fraction &other) const {
        int newNumerator = this->numerator * other.denominator + other.numerator * this->denominator;
        int newDenominator = this->denominator * other.denominator;
        this->reduce();
        return Fraction(newNumerator, newDenominator);
    }

    Fraction Fraction::operator-(const Fraction &other) const {
        int newNumerator = this->numerator * other.denominator - other.numerator * this->denominator;
        int newDenominator = this->denominator * other.denominator;
        this->reduce();
        return Fraction(newNumerator, newDenominator);
    }

    Fraction Fraction::operator*(const Fraction &other) const {
        int newNumerator = this->numerator * other.numerator;
        int newDenominator = this->denominator * other.denominator;
        this->reduce();
        return Fraction(newNumerator, newDenominator);
    }

    Fraction Fraction::operator/(const Fraction &other) const {
        //check if denominator is 0
        if (other.numerator == 0) {
            throw invalid_argument("Denominator can't be 0");
        }
        int newNumerator = this->numerator * other.denominator;
        int newDenominator = this->denominator * other.numerator;
        this->reduce();
        return Fraction(newNumerator, newDenominator);
    }


/**
 * Arithmetic operators with double on the left
 */

    Fraction Fraction::operator+(double value) const {
        return Fraction(value) + *this;
    }        // Addition with a float value from the left
    Fraction Fraction::operator-(double value) const {
        return Fraction(value) - *this;
    }           // Subtraction with a float value from the left
    Fraction Fraction::operator*(double value) const {
        return Fraction(value) * *this;
    }           // Multiplication with a float value from the left
    Fraction Fraction::operator/(double value) const {
        return Fraction(value) / *this;
    }           // Division with a float value from the left

/**
 * Arithmetic operators with double on the right
 */
// Addition with a double value from the right
    Fraction operator+(double value, const Fraction &fraction) {
        return Fraction(value) + fraction;
    }

// Subtraction with a double value from the right
    Fraction operator-(double value, const Fraction &fraction) {
        return Fraction(value) - fraction;
    }

// Multiplication with a double value from the right
    Fraction operator*(double value, const Fraction &fraction) {
        return Fraction(value) * fraction;
    }

// Division with a double value from the right
    Fraction operator/(double value, const Fraction &fraction) {
        return Fraction(value) / fraction;
    }


/**
 * Comparison operators
 */
    bool Fraction::operator==(const Fraction &other) const { return true; }  // Equality
    bool Fraction::operator!=(const Fraction &other) const { return true; }  // Inequality
    bool Fraction::operator>(const Fraction &other) const { return true; }   // Greater than
    bool Fraction::operator<(const Fraction &other) const { return true; }   // Less than
    bool Fraction::operator>=(const Fraction &other) const { return true; }  // Greater than or equal to
    bool Fraction::operator<=(const Fraction &other) const { return true; }  // Less than or equal to

/**
 * Comparison operators with double
 */
    bool Fraction::operator==(double value) const {
        return Fraction(value) == *this;
    }           // Equality with a float value
    bool Fraction::operator!=(double value) const { return true; }           // Inequality with a float value
    bool Fraction::operator>(double value) const { return true; }            // Greater than a float value
    bool Fraction::operator<(double value) const { return true; }            // Less than a float value
    bool Fraction::operator>=(double value) const { return true; }           // Greater than or equal to a float value
    bool Fraction::operator<=(double value) const { return true; }           // Less than or equal to a float value

    /**
     * Comparison operators with double on the right
     */
    bool
    operator==(double value, const Fraction &fraction) { return true; } //Equality with a float value from the right
    bool
    operator!=(double value, const Fraction &fraction) { return true; } //Inequality with a float value from the right
    bool operator>(double value, const Fraction &fraction) { return true; } //Greater than a float value from the right
    bool operator<(double value, const Fraction &fraction) { return true; } //Less than a float value from the right
    bool operator>=(double value,
                    const Fraction &fraction) { return true; } //Greater than or equal to a float value from the right
    bool operator<=(double value,
                    const Fraction &fraction) { return true; } //Less than or equal to a float value from the right
/**
 * Increment and decrement operators
 */

    Fraction &Fraction::operator++() {
        this->numerator += this->denominator;
        this->reduce();
        return *this;
    }

    Fraction Fraction::operator++(int) {  // Postfix increment
        Fraction temp = *this;
        ++*this;
        return temp;
    }

    Fraction &Fraction::operator--() {
        this->numerator -= this->denominator;
        this->reduce();
        return *this;
    }

    Fraction Fraction::operator--(int) {  // Postfix decrement
        Fraction temp = *this;
        --*this;
        return temp;
    }


/**
 * ouput &input operators
 * */

    ostream &operator<<(ostream &os, const Fraction &fraction) {
        os << fraction.getNumerator() << "/" << fraction.getDenominator();
        return os;
    }

//input operator


    istream &operator>>(istream &is, Fraction &fraction) {
        int numerator;
        int denominator;
        char c;

        is >> numerator >> c >> denominator;

        if (c != '/') {
            throw invalid_argument("Invalid input");
        }
        // Set the numerator and denominator of the Fraction object
        fraction.setNumerator(numerator);
        fraction.setDenominator(denominator);

        return is;
    }


/**
 * Reduction functions
 */
    void Fraction::reduce() const {// need to fix
        int gcd_tmp = gcd(this->numerator, this->denominator);
        this->numerator /= gcd_tmp;
        this->denominator /= gcd_tmp;
        if (this->denominator < 0) { // is it right?
            this->numerator *= -1;
            this->denominator *= -1;
        }
    }

    int Fraction::gcd(int a, int b) const {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }


}