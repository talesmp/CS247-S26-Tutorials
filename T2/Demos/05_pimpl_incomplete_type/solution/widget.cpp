#include "widget.h"

struct Widget::Impl { int data_; };
Widget::Widget() : pImpl_{std::make_unique<Impl>()} {}

// Defined out-of-line where Impl is complete, so unique_ptr can emit the delete.
Widget::~Widget() = default;
