// Answer (Q13.2): `ar is unbound` => std::move(ar) transfers ownership of the Rational to `at`, leaving `ar` null. 
// So report takes the unbound branch. (`at` is now bound to 1/2.)
// Moving a unique_ptr always empties the source.

#include "Rational.h"

#include <memory>

// Reports whether a unique_ptr<Rational> currently owns a value => exercises operator bool (if (p)) and operator* / operator<< on the Rational.
static void report(const char* name, const std::unique_ptr<Rational>& p) {
    if (p) std::cout << name << " is bound to " << *p << '\n';
    else   std::cout << name << " is unbound\n";
}

int main() {
    // Two levels of heap indirection: a unique_ptr<Rational>, and each Rational
    // itself holds a unique_ptr<Impl>. Not one delete in the whole program.
    auto ar = std::make_unique<Rational>();
    auto as = std::make_unique<Rational>();

    std::cout << "Enter rational number (a/b): ";
    std::cin >> *ar;                       // dereference, then operator>>  (enter 1/2)
    std::cout << "Enter rational number (a/b): ";
    std::cin >> *as;                       // (enter 3/4)

    std::cout << "Numerator of ar is " << ar->numerator()      // -> calls a member
              << ", denominator of ar is " << ar->denominator() << '\n';

    std::cout << *ar << " + " << *as << " = " << *ar + *as << '\n';   // 5/4
    std::cout << *ar << " * " << *as << " = " << *ar * *as << '\n';   // 3/8

    report("ar", ar);                      // 1/2
    report("as", as);                      // 3/4

    std::unique_ptr<Rational> at(std::move(ar));   // transfer ar -> at; ar goes null
    report("ar", ar);                      // unbound
    report("at", at);                      // 1/2

    ar = std::move(as);                    // transfer as -> ar; as goes null
    report("ar", ar);                      // 3/4
    report("as", as);                      // unbound

    ar = std::make_unique<Rational>(100);  // ar's current 3/4 is destroyed; ar -> 100/1
    report("ar", ar);                      // 100/1

    return 0;
}   // ar (100/1), at (1/2), as (null) destroyed -> their Rationals -> their Impls. No leaks.
