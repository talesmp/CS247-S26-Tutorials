// Topic: pImpl Rational
// Q13.1: Deep-dive: pImpl + unique_ptr Rational (optional capstone) From
// pitfall_incomplete_type/ (note: the header declares no ~Rational()), shown. You build
// g++ Rational.cpp main.cpp. What happens?
//   a) It compiles, links, and runs fine
//   b) Compile error in `main.cpp`'s TU — it can't `delete` the incomplete `Impl`
//   c) Linker error: undefined reference to `~Rational`
//   d) Runtime crash (double free)

#ifndef RATIONAL_H
#define RATIONAL_H

#include <memory>

class Rational {
public:
    Rational(int numer = 0, int denom = 1);
    int numerator() const;
    // ~Rational();   // <- the missing line that makes pImpl work across files
private:
    struct Impl;
    std::unique_ptr<Impl> rat_;
};

#endif
