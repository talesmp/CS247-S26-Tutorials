#include "course.h"
#include "student.h"

int main() {
    Course c;
    Student s;
    c.setRep(&s);
    s.enroll(&c);
    return 0;
}
