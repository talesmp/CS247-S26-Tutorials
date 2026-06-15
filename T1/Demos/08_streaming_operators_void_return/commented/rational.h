#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
    int num_, denom_;
public:
    Rational(int num, int denom = 1) : num_{num}, denom_{denom} {}
    int getnum() const { return num_; }
    int getdenom() const { return denom_; }
};
#endif
