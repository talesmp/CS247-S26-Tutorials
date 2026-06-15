// Topic: Construction throws
// Q6.1: From clean/main.cpp (W#i prints ctor i; throws when i==2;
// prints dtor i on destruction), shown. Which lines appear, in order?
//   a) `ctor 0/1/2` · `dtor 2/1/0` · `caught: boom`
//   b) `ctor 0/1/2` · `dtor 1/0` · `caught: boom`
//   c) `ctor 0/1/2/3` · `dtor 3/2/1/0` · `caught: boom`
//   d) `ctor 0/1/2` · `caught: boom` (no dtors)

#include <iostream>
#include <stdexcept>

struct W {
    int id;
    W(int i) : id(i) {
        std::cout << "ctor " << id << '\n';
        if (id == 2) throw std::runtime_error("boom");
    }
    ~W() { std::cout << "dtor " << id << '\n'; }
};

int main() {
    try {
        W a(0);
        W b(1);
        W c(2);
        W d(3);
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << '\n';
    }
    return 0;
}

