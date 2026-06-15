#include "Rational.h"

#include <cstdlib>
#include <stdexcept>

struct Rational::Impl {
    Impl(int num = 0, int den = 1) : numerator_(num), denominator_(den) {}
    int numerator_;
    int denominator_;
};

namespace {
    int gcd(int a, int b) {
        a = std::abs(a);
        b = std::abs(b);
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a == 0 ? 1 : a;
    }
}

Rational::Rational(int numer, int denom)
    : rat_(std::make_unique<Impl>(numer, denom)) {
    if (denom == 0)
        throw std::invalid_argument("Rational: denominator cannot be 0");
    reduce();
}

Rational::Rational(const Rational& r)
    : rat_(std::make_unique<Impl>(*r.rat_)) {}

Rational& Rational::operator=(const Rational& r) {
    *rat_ = *r.rat_;
    return *this;
}

Rational::~Rational() = default;

int Rational::numerator()   const { return rat_->numerator_; }
int Rational::denominator() const { return rat_->denominator_; }

void Rational::reduce() {
    int g = gcd(rat_->numerator_, rat_->denominator_);
    rat_->numerator_   /= g;
    rat_->denominator_ /= g;
    if (rat_->denominator_ < 0) {
        rat_->numerator_   = -rat_->numerator_;
        rat_->denominator_ = -rat_->denominator_;
    }
}

Rational operator+(const Rational& a, const Rational& b) {
    return Rational(a.rat_->numerator_ * b.rat_->denominator_
                  + b.rat_->numerator_ * a.rat_->denominator_,
                    a.rat_->denominator_ * b.rat_->denominator_);
}

Rational operator*(const Rational& a, const Rational& b) {
    return Rational(a.rat_->numerator_ * b.rat_->numerator_,
                    a.rat_->denominator_ * b.rat_->denominator_);
}

bool operator==(const Rational& a, const Rational& b) {
    return a.rat_->numerator_   == b.rat_->numerator_
        && a.rat_->denominator_ == b.rat_->denominator_;
}

bool operator<(const Rational& a, const Rational& b) {
    return a.rat_->numerator_ * b.rat_->denominator_
         < b.rat_->numerator_ * a.rat_->denominator_;
}

std::istream& operator>>(std::istream& in, Rational& r) {
    int num, den;
    char slash;
    if (in >> num >> slash >> den)
        r = Rational(num, den);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Rational& r) {
    return out << r.rat_->numerator_ << '/' << r.rat_->denominator_;
}
