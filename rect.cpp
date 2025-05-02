#include "rect.h"
bool rect::containsPoint(point p) {
    return (p.x >= TopLeft.x && p.x <= BottomRight.x && p.y >= TopLeft.y && p.y <= BottomRight.y);
}

bool rect::intersects(rect r) {
    return !(r.TopLeft.x > BottomRight.x || r.BottomRight.x < TopLeft.x || r.TopLeft.y > BottomRight.y || r.BottomRight.y < TopLeft.y);
}