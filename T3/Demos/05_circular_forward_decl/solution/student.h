#ifndef STUDENT_H
#define STUDENT_H

class Course;   // FIX: forward declaration instead of #include "course.h".

class Student {
    Course *enrolled_ = nullptr;
public:
    void enroll(Course *c) { enrolled_ = c; }
};

#endif // STUDENT_H
