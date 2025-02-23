#ifndef QUADTREE_H
#define QUADTREE_H

#include "rect.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;
struct QuadTree {
    rect boundary; // Boundaries of the QuadTree
    int capacity; // Max points before subdivision
    std::vector<point> points; // Points in this QuadTree node
    QuadTree *NE, *NW, *SE, *SW; // Children nodes
    QuadTree(rect _boundary, int _capacity) : boundary(_boundary), capacity(_capacity), NE(NULL), NW(NULL), SE(NULL), SW(NULL) {}
    bool insert(point p); // Insert a point
    void subdivide(); // Subdivide into 4 children
    std::vector<point> queryRange(rect r); // Find points within a range
    void clear(); // Clear the QuadTree
};

#endif // QUADTREE_H