// Topic: noexcept
// Q12.1: The whole of clean/main.cpp is shown. What does it print?
//   a) `caught: oops` then `after`
//   b) `caught: oops` only
//   c) nothing — `std::terminate` is called; the `catch` is bypassed
//   d) `after` only

// Q12.2: (illustrative — concept) Which of these does NOT call std::terminate in C++17?
//   a) An exception with no matching handler anywhere on the stack
//   b) A bare `throw;` executed with no exception currently being handled
//   c) A destructor that throws during stack unwinding
//   d) A function that throws `std::runtime_error` and is caught by `catch (const
//      std::exception&)`

#include <iostream>
#include <stdexcept>

void cleanup() noexcept {
    throw std::runtime_error("oops");
}

int main() {
    try {
        cleanup();
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << '\n';
    }
    std::cout << "after\n";
    return 0;
}

