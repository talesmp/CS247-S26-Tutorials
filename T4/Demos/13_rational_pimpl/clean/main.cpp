// Topic: pImpl Rational
// Q13.2: From clean/main.cpp (after reading 1/2 into *ar),
// shown. report prints "<name> is bound to <value>" or "<name> is unbound". That
// report("ar", ar) line prints:
//   a) `ar is bound to 1/2`
//   b) `ar is unbound`
//   c) a compile error
//   d) `ar is bound to 0/1`

#include "Rational.h"

#include <memory>

static void report(const char* name, const std::unique_ptr<Rational>& p) {
    if (p) std::cout << name << " is bound to " << *p << '\n';
    else   std::cout << name << " is unbound\n";
}

int main() {
    auto ar = std::make_unique<Rational>();
    auto as = std::make_unique<Rational>();

    std::cout << "Enter rational number (a/b): ";
    std::cin >> *ar;
    std::cout << "Enter rational number (a/b): ";
    std::cin >> *as;

    std::cout << "Numerator of ar is " << ar->numerator()
              << ", denominator of ar is " << ar->denominator() << '\n';

    std::cout << *ar << " + " << *as << " = " << *ar + *as << '\n';
    std::cout << *ar << " * " << *as << " = " << *ar * *as << '\n';

    report("ar", ar);
    report("as", as);

    std::unique_ptr<Rational> at(std::move(ar));
    report("ar", ar);
    report("at", at);

    ar = std::move(as);
    report("ar", ar);
    report("as", as);

    ar = std::make_unique<Rational>(100);
    report("ar", ar);

    return 0;
}
