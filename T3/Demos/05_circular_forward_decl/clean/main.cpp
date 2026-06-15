// Topic: Circular includes
// Q5.1: Two headers, each with a proper guard, each #include -ing the other, and main.cpp
// includes both. What's the output of `g++ main.cpp -o app`?
//   a) Infinite preprocessor loop
//   b) Compiles fine: the guards handle it
//   c) Compile error: a class is used before it's declared
//   d) Linker error
#include "course.h"
#include "student.h"

int main() {
    Course c;
    Student s;
    c.setRep(&s);
    s.enroll(&c);
    return 0;
}
