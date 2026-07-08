#include <iostream>

class LegacyRectangle {
public:
    void draw(int x1, int y1, int x2, int y2) const {
        std::cout << "Rectangle from (" << x1 << "," << y1
                  << ") to (" << x2 << "," << y2 << ")\n";
    }
};

class Shape {
public:
    virtual void drawShape() const = 0;
    virtual ~Shape() = default;
};

class RectangleAdapter : public Shape {
    LegacyRectangle legacy;
    int x, y, width, height;
public:
    RectangleAdapter(int x, int y, int w, int h)
        : x(x), y(y), width(w), height(h) {}
    void drawShape() const override {
        legacy.draw(x, y, width, height);
    }
};

int main() {
    RectangleAdapter r(10, 20, 50, 30);   // position (10,20), size 50 x 30
    r.drawShape();
}
