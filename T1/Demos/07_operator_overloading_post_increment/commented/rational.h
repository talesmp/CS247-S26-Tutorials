#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational {
    int num_, denom_;
public:
    Rational(int num, int denom = 1) : num_{num}, denom_{denom} {}
    int getnum() const { return num_; }
    int getdenom() const { return denom_; }
    void setnum(int n) { num_ = n; }
    void setdenom(int d) { denom_ = d; }
};

// Nonmember operator+ (slide 9): one symmetric set handles r+s, 5+r, and r+5.
inline Rational operator+(const Rational& lhs, const Rational& rhs) {
    return Rational{
        lhs.getnum() * rhs.getdenom() + lhs.getdenom() * rhs.getnum(),
        lhs.getdenom() * rhs.getdenom()
    };
}
inline Rational operator+(int lhs, const Rational& rhs) { return Rational(lhs) + rhs; }
inline Rational operator+(const Rational& lhs, int rhs) { return lhs + Rational(rhs); }

inline std::ostream& operator<<(std::ostream& out, const Rational& r) {
    out << r.getnum() << '/' << r.getdenom();
    return out;
}
#endif
