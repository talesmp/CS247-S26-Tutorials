#include <iostream>
#include <stdexcept>

// StudentID is now its own type, not an int alias.
class StudentID {
    int id_;
public:
    explicit StudentID(int id) {       // explicit: no silent int -> StudentID
        if (id <= 0)
            throw std::out_of_range("StudentID must be positive");
        id_ = id;
    }
    int get() const { return id_; }
};

void enroll(StudentID id, int courseCode) {
    std::cout << "Enrolling student " << id.get() << " in course " << courseCode << "\n";
}

int main() {
    StudentID id1{12345};

    // All three former abuses now rejected (uncomment to see):
    // StudentID id2{-9999};        // throws (runtime invariant)
    // auto result = id1 + id1;     // error: no operator+
    int courseCode = 101;
    // enroll(courseCode, id1);     // error: int won't convert to StudentID

    enroll(id1, courseCode);        // correct order, type-checked
}
