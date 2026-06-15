// Answer (Q13.1): Compile error in `main.cpp`'s TU => it can't `delete` the incomplete `Impl`.
// With no ~Rational() declared, the compiler generates it inline in main.cpp 's TU, where Impl is only forward-declared. 
// Destroying unique_ptr<Impl> needs a complete type → error: invalid application of 'sizeof' to an incomplete type. 
// Fix: declare ~Rational(); in the header, define it (= default) in the.cpp.

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <memory>

// pImpl ("Pointer to IMPLementation"): the real data lives in a hidden Impl behind one opaque pointer. 
// Clients see only the interface, so reordering the private fields later forces no recompile.
class Rational {
public:
    Rational(int numer = 0, int denom = 1);   // also the default constructor
    Rational(const Rational& r);              // DEEP copy (unique_ptr can't be copied)
    Rational& operator=(const Rational& r);

    // pImpl rule: declare ~Rational() here, define it (= default) in the .cpp where Impl is complete. 
    // Omit it and the implicit dtor is generated in client TUs, where Impl is incomplete => won't compile (see pitfall_incomplete_type/).
    ~Rational();

    int numerator()   const;
    int denominator() const;

    // Immutable: arithmetic returns NEW Rationals, never mutates an operand.
    friend Rational operator+(const Rational& a, const Rational& b);
    friend Rational operator*(const Rational& a, const Rational& b);
    friend bool operator==(const Rational& a, const Rational& b);
    friend bool operator<(const Rational& a, const Rational& b);
    friend std::istream& operator>>(std::istream& in, Rational& r);
    friend std::ostream& operator<<(std::ostream& out, const Rational& r);

private:
    struct Impl;                    // forward declaration only — defined in the .cpp
    std::unique_ptr<Impl> rat_;     // the single owning pointer to the hidden data
    void reduce();                  // keep every value in canonical (lowest-terms) form
};

#endif
