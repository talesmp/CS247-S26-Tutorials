// Answer: no -- overload resolution ignores return type, so it's an illegal redeclaration (compile error).

class Rational {
public:
    // Overload resolution looks at ARGUMENT types only. 
    // These differ just in return type -> illegal redeclaration, not an overload. 
    // Errors at the declaration, before any call.
    int    getValue();
    double getValue();   // ERROR: cannot be overloaded
};

int main() {
    Rational r;
    auto x = r.getValue();
}
