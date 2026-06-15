#include "Rational.h"

#include <cstdlib>
#include <stdexcept>

// The hidden implementation => just the data. 
// Defined here, so the header stays apure interface (the "compilation firewall").
struct Rational::Impl {
    Impl(int num = 0, int den = 1) : numerator_(num), denominator_(den) {}
    int numerator_;
    int denominator_;
};

// Anonymous namespace = internal (file-private) linkage: gcd is invisible outside
// this translation unit.
namespace {
    int gcd(int a, int b) {
        a = std::abs(a);
        b = std::abs(b);
        while (b != 0) { int t = b; b = a % b; a = t; }
        return a == 0 ? 1 : a;   // gcd(0, d) -> 1, so 0/1 stays 0/1
    }
}

Rational::Rational(int numer, int denom)
    : rat_(std::make_unique<Impl>(numer, denom)) {   // build the hidden Impl on the heap
    // Throwing here is safe: rat_ is already built, so unwinding frees it. No leak.
    if (denom == 0)
        throw std::invalid_argument("Rational: denominator cannot be 0");
    reduce();
}

// unique_ptr is non-copyable, so we must deep-copy: allocate a fresh Impl with the source's values -> value semantics, each Rational independent.
Rational::Rational(const Rational& r)
    : rat_(std::make_unique<Impl>(*r.rat_)) {}

Rational& Rational::operator=(const Rational& r) {
    *rat_ = *r.rat_;   // copy the pointed-to Impl's value (both already exist)
    return *this;
}

// Defined out of line where Impl is complete; = default is fine -- the point is the definition lives in THIS TU, not in clients' (see the header).
Rational::~Rational() = default;

int Rational::numerator()   const { return rat_->numerator_; }
int Rational::denominator() const { return rat_->denominator_; }

// Canonical form: divide out the gcd and keep the denominator positive. This is what lets operator== compare fields directly (1/2 and 2/4 both become 1/2).
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

// Direct field comparison is valid ONLY because reduce() canonicalizes every value.
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
    if (in >> num >> slash >> den)   // reads "a/b"
        r = Rational(num, den);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Rational& r) {
    return out << r.rat_->numerator_ << '/' << r.rat_->denominator_;
}
