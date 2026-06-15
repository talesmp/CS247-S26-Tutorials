#ifndef WIDGET_H        // FIX: the header guard.
#define WIDGET_H        // First paste: WIDGET_H undefined -> define it, keep body.
                        // Second paste: WIDGET_H defined  -> body is deleted.
#include <string>

class Widget {
    std::string label_;
public:
    Widget() : label_("widget") {}
    std::string label() const { return label_; }
};

#endif // WIDGET_H
