#ifndef COURSE_H
#define COURSE_H

class Student;   // forward declaration -> Student is an INCOMPLETE type here.

class Course {
    Student rep_;   // BROKEN: storing Student BY VALUE needs its full SIZE,
                    // which a forward declaration does not give.
                    // -> "field 'rep_' has incomplete type 'Student'"
};

#endif // COURSE_H
