#ifndef STUDENT_H
#define STUDENT_H

#include "course.h"

class Student {
    Course *enrolled_ = nullptr;
public:
    void enroll(Course *c) { enrolled_ = c; }
};

#endif
