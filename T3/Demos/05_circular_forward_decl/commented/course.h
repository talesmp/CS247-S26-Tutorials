#ifndef COURSE_H
#define COURSE_H

#include "student.h"   // BROKEN: circular #include — student.h includes us back.

class Course {
    Student *rep_ = nullptr;   // only a POINTER -> we don't actually need student.h
public:
    void setRep(Student *s) { rep_ = s; }
};

#endif // COURSE_H
