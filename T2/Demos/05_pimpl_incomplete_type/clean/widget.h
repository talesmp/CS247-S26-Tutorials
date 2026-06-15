// Topic: PImpl Idiom (Hidden Implementation)
// Will this header-only pImpl class compile when a client writes `Widget w;`?
// Build with `g++ -std=c++17 clean/*.cpp -o app`
#ifndef WIDGET_H
#define WIDGET_H
#include <memory>

class Widget {
    struct Impl;
    std::unique_ptr<Impl> pImpl_;
public:
    Widget();
};

#endif
