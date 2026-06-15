#ifndef WIDGET_H
#define WIDGET_H
#include <memory>

class Widget {
    struct Impl;
    std::unique_ptr<Impl> pImpl_;
public:
    Widget();
    ~Widget();        // declared here, DEFINED in widget.cpp where Impl is complete
};

#endif
