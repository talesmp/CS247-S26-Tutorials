// Answer (Q11.1): Yes — `~File` runs during unwinding, *before* `caught:...` 
// f is a stack object; unwinding calls its destructor on the way to the handler, so File closed prints before caught. 
// That automatic, exception-safe release is the whole point of RAII the cure for station 7's leak.

// RAII (observation demo): the positive twin of the raw-pointer leak.
// File ACQUIRES the handle in its ctor and RELEASES it in its dtor. 
// A stack object's dtor runs when scope ends (normal return OR exception unwinding), so cleanup is automatic and exception-safe.

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

class File {
    std::ofstream file_;
public:
    File(const std::string& filename) : file_(filename) {   // ACQUIRE in the ctor
        if (!file_.is_open())
            throw std::runtime_error("Failed to open file");
        std::cout << "File opened: " << filename << '\n';
    }
    ~File() {                                               // RELEASE in the dtor
        if (file_.is_open()) {
            file_.close();
            std::cout << "File closed\n";
        }
    }
    void write(const std::string& data) {
        file_ << data << '\n';
        std::cout << "wrote: " << data << '\n';
    }
    File(const File&) = delete;             // one owner per handle (like unique_ptr)
    File& operator=(const File&) = delete;
};

int main() {
    try {
        File f("out.txt");
        f.write("Hello, RAII!");
        throw std::runtime_error("boom after open");   // unwinds -> ~File() still runs
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << '\n';
    }
    return 0;
}
// Output — note "File closed" prints DURING unwinding, before "caught":
//   File opened: out.txt
//   wrote: Hello, RAII!
//   File closed                 <- the destructor ran on the throw path, automatically
//   caught: boom after open
// (Creates out.txt in the current directory; harmless, delete it after.)
