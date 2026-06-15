#ifndef PANEL_H
#define PANEL_H

#include "widget.h"

class Panel {
    Widget w_;
public:
    Widget inner() const { return w_; }
};

#endif // PANEL_H
