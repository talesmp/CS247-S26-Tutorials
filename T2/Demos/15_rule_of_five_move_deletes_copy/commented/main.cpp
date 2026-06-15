// Answer: it does NOT compile => declaring a move ctor implicitly deletes the copy ctor that Resource r2 = r1; needs.

// Declaring a move operation (even `= default`) implicitly DELETES the copy ctor and copy assignment. 
// `Resource r2 = r1;` needs the copy ctor (r1 is a named lvalue), which is now deleted -> won't compile. 
// It's the act of declaring the move that removed the copies.
// Fix: bring copies back explicitly with `= default` (solution/).
#include <utility>

class Resource {
public:
    Resource() = default;
    Resource(Resource&&) noexcept = default;   // declaring move => copies deleted
};

int main() {
    Resource r1;
    Resource r2 = r1;     // ERROR: copy constructor is implicitly deleted
}
