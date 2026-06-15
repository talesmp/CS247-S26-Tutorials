#ifndef STUDENT_H
#define STUDENT_H

#include "course.h"   // BROKEN: circular #include — course.h includes us back.

class Student {
    Course *enrolled_ = nullptr;   // only a POINTER -> we don't actually need course.h
public:
    void enroll(Course *c) { enrolled_ = c; }
};

#endif // STUDENT_H
