// Topic: C++17 Special Members Table (Rule of Five)
// Does this compile, and which constructor runs at the marked line?
#include <utility>

class Resource {
public:
    Resource() = default;
    Resource(Resource&&) noexcept = default;
};

int main() {
    Resource r1;
    Resource r2 = r1;
}
