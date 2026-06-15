#include "widget.h"

// Destroying `w` forces the implicit ~Widget() here, where Impl is incomplete => compile error pointing into <memory> about an incomplete type.
int main() { Widget w; }
