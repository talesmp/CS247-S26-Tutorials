#include "widget.h"

// Impl is complete here, so widget.cpp alone compiles fine; the break only shows in a TU that destroys a Widget while Impl is incomplete.
struct Widget::Impl { int data_; };
Widget::Widget() : pImpl_{std::make_unique<Impl>()} {}
