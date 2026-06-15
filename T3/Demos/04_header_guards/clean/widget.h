#include <string>

class Widget {
    std::string label_;
public:
    Widget() : label_("widget") {}
    std::string label() const { return label_; }
};
