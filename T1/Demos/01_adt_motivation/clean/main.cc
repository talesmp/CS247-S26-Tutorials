// Topic: ADT Motivation
// Do negative IDs, ID arithmetic, and swapped arguments compile?
#include <iostream>

typedef int StudentID;

void enroll(StudentID id, int courseCode) {
    std::cout << "Enrolling student " << id << " in course " << courseCode << "\n";
}

int main() {
    StudentID id1 = 12345;
    StudentID id2 = -9999;
    StudentID result = id1 + id2;

    int courseCode = 101;
    enroll(courseCode, id1);

    std::cout << "id2 = " << id2 << ", result = " << result << "\n";
}
