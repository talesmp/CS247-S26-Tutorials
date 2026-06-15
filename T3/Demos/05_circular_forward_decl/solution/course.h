#ifndef COURSE_H
#define COURSE_H

class Student;   // FIX: forward declaration. A pointer only needs the NAME.

class Course {
    Student *rep_ = nullptr;
public:
    void setRep(Student *s) { rep_ = s; }
};

#endif // COURSE_H
