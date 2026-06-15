// Answer (Q5.1): Compile error: a class is used before it's declared -- Guards stop the
// infinite recursion but not the ordering: whichever header expands first names the
// other's class before it's declared. Fix = a forward declaration, not a guard.

#include "course.h"
#include "student.h"

int main() {
    Course c;
    Student s;
    c.setRep(&s);
    s.enroll(&c);
    return 0;
}
