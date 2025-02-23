#ifndef RECT_H
#define RECT_H

#include "point.h"

struct rect {
    point TopLeft, BottomRight;
    rect(point TL, point BR) : TopLeft(TL), BottomRight(BR) {}
    bool containsPoint(point p);
    bool intersects(rect r);
};

#endif // RECT_H