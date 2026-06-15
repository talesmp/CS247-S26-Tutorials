#include "widget.h"

struct Widget::Impl { int data_; };
Widget::Widget() : pImpl_{std::make_unique<Impl>()} {}
