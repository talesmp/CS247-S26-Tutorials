// Topic: RAII
// Q11.1: The whole main from clean/main.cpp (the File ctor prints File opened, the
// dtor prints File closed), shown. Does File closed print — and if so, when?
//   a) No — we threw before any close call, so the file is never closed
//   b) Yes — `~File` runs during unwinding, *before* `caught:...`
//   c) Yes, but *after* `caught:...`
//   d) No — it only closes on a normal return

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

class File {
    std::ofstream file_;
public:
    File(const std::string& filename) : file_(filename) {
        if (!file_.is_open())
            throw std::runtime_error("Failed to open file");
        std::cout << "File opened: " << filename << '\n';
    }
    ~File() {
        if (file_.is_open()) {
            file_.close();
            std::cout << "File closed\n";
        }
    }
    void write(const std::string& data) {
        file_ << data << '\n';
        std::cout << "wrote: " << data << '\n';
    }
    File(const File&) = delete;
    File& operator=(const File&) = delete;
};

int main() {
    try {
        File f("out.txt");
        f.write("Hello, RAII!");
        throw std::runtime_error("boom after open");
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << '\n';
    }
    return 0;
}
