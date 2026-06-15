// Answer: yes, all silently. 
// `typedef int StudentID` is just an alias; a real ADT turns all three into compile-time errors.

#include <iostream>

// typedef = alias, not a new type. StudentID *is* int, so none of the abuses below are caught.
typedef int StudentID;

void enroll(StudentID id, int courseCode) {
    std::cout << "Enrolling student " << id << " in course " << courseCode << "\n";
}

int main() {
    StudentID id1 = 12345;

    StudentID id2 = -9999;             // (1) negative ID: int holds it, no check
    StudentID result = id1 + id2;      // (2) ID arithmetic: int + int is legal

    int courseCode = 101;

    // (3) swapped args: enroll wants (id, courseCode); 
    //     both are int, so passing (courseCode, id1) compiles and runs silently wrong.
    enroll(courseCode, id1);

    std::cout << "id2 = " << id2 << ", result = " << result << "\n";
    // Nothing caught -- that lack of protection is the whole case for an ADT.
}
