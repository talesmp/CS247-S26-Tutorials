#ifndef COURSE_H
#define COURSE_H

#include "student.h"

class Course {
    Student *rep_ = nullptr;
public:
    void setRep(Student *s) { rep_ = s; }
};

#endif
