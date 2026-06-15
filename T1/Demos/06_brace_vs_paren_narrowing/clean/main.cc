// Topic: Default Arguments - Challenge 2
// What is the difference between () and {} when calling an explicit constructor?  (m(2.3) vs m{2.3})
class Rational {
    int num_, denom_;
public:
    Rational(int num, int denom = 1) : num_{num}, denom_{denom} {}
};

int main() {
    Rational m{2.3};
}
