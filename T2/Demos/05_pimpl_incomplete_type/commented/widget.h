// Answer: No, the implicit ~Widget() is emitted in main.cpp's TU, where Impl is incomplete.

// `struct Impl;` is only a forward decl; Impl is defined in widget.cpp. 
// We declare a ctor but no dtor, so the implicit ~Widget() is emitted in the client TU (main.cpp), where deleting unique_ptr<Impl> needs a COMPLETE Impl, so it won't compile.
// Fix: declare ~Widget() here, define it `= default` in widget.cpp (solution/).
#ifndef WIDGET_H
#define WIDGET_H
#include <memory>

class Widget {
    struct Impl;                       // forward declaration only
    std::unique_ptr<Impl> pImpl_;
public:
    Widget();
    // No ~Widget() -> implicit one emitted in the client, where Impl is incomplete.
};

#endif
