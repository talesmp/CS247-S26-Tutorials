#include "Rational.h"

struct Rational::Impl {
    Impl(int num, int den) : numerator_(num), denominator_(den) {}
    int numerator_;
    int denominator_;
};

Rational::Rational(int numer, int denom)
    : rat_(std::make_unique<Impl>(numer, denom)) {}

int Rational::numerator() const { return rat_->numerator_; }
