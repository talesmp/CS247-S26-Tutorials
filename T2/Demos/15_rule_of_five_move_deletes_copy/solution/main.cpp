#include <utility>

class Resource {
public:
    Resource() = default;
    Resource(const Resource&) = default;        // bring copy back explicitly
    Resource(Resource&&) noexcept = default;
};

int main() {
    Resource r1;
    Resource r2 = r1;     // OK now: copy constructor is available
    (void)r2;
}
