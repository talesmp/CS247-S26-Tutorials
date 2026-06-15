#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <memory>

class Rational {
public:
    Rational(int numer = 0, int denom = 1);
    Rational(const Rational& r);
    Rational& operator=(const Rational& r);
    ~Rational();

    int numerator() const;
    int denominator() const;

    friend Rational operator+(const Rational& a, const Rational& b);
    friend Rational operator*(const Rational& a, const Rational& b);
    friend bool operator==(const Rational& a, const Rational& b);
    friend bool operator<(const Rational& a, const Rational& b);
    friend std::istream& operator>>(std::istream& in, Rational& r);
    friend std::ostream& operator<<(std::ostream& out, const Rational& r);

private:
    struct Impl;
    std::unique_ptr<Impl> rat_;
    void reduce();
};

#endif
