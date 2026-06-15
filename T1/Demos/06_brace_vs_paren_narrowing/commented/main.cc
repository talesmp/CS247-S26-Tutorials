// Answer: {} rejects the narrowing (clang error / g++ -Wnarrowing); () silently truncates to 2/1.

class Rational {
    int num_, denom_;
public:
    Rational(int num, int denom = 1) : num_{num}, denom_{denom} {}
};

int main() {
    // Braces forbid narrowing: double 2.3 -> int loses info, so it's diagnosed at compile time (clang: error; g++: -Wnarrowing warning).
    Rational m{2.3};   // narrowing
    // Compare: m(2.3) compiles, silently truncates to 2/1 (../pitfall_paren_truncates);
    //          m{2} is fine (../solution).
}
