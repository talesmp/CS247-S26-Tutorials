// Topic: Function Overloading
// Can two functions differ only in return type?
class Rational {
public:
    int    getValue();
    double getValue();
};

int main() {
    Rational r;
    auto x = r.getValue();
}
