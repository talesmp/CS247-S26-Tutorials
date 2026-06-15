// BROKEN. This header has NO include guard.
// If it gets pasted into one translation unit more than once, `class Widget`
// is DEFINED twice -> "redefinition of 'class Widget'".

#include <string>

class Widget {
    std::string label_;
public:
    Widget() : label_("widget") {}
    std::string label() const { return label_; }
};
