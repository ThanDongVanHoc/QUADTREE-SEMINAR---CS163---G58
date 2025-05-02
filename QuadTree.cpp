#include "QuadTree.h"

bool QuadTree::insert(point p)
{
    if (!boundary.containsPoint(p))
    {
        return false; // Point outside boundary
    }
    if (points.size() < capacity && NE == NULL)
    {
        points.push_back(p); // Add point if there's space
        return true;
    }
    if (NE == NULL)
    {
        subdivide(); // Subdivide if necessary
    }
    // We have to add the points/data contained in this quad array to the new quads if we only want the last node to hold the data
    for (vector<point>::iterator it = points.begin(); it != points.end(); ++it)
    {
        if (NE->insert(*it))
            continue;
        if (NW->insert(*it))
            continue;
        if (SE->insert(*it))
            continue;
        if (SW->insert(*it))
            continue;
    }
    points.clear();

    if (NE->insert(p))
        return true;
    if (NW->insert(p))
        return true;
    if (SE->insert(p))
        return true;
    if (SW->insert(p))
        return true;

    return false; // Should never happen
}

void QuadTree::subdivide()
{
    point TL = boundary.TopLeft;
    point BR = boundary.BottomRight;
    point center = point((TL.x + BR.x) / 2, (TL.y + BR.y) / 2);
    NE = new QuadTree(rect(point(center.x, TL.y), point(BR.x, center.y)), capacity);
    NW = new QuadTree(rect(TL, center), capacity);
    SE = new QuadTree(rect(point(center.x, center.y), BR), capacity);
    SW = new QuadTree(rect(point(TL.x, center.y), point(center.x, BR.y)), capacity);
}

vector<point> QuadTree::queryRange(rect r)
{
    vector<point> pointsInRange;
    if (!boundary.intersects(r))
        return pointsInRange; // No intersection
    for (vector<point>::iterator it = points.begin(); it != points.end(); ++it)
    {
        if (r.containsPoint(*it))
        {
            pointsInRange.push_back(*it);
        }
    }
    if (NE == NULL)
        return pointsInRange; // No children
    vector<point> NEPoints = NE->queryRange(r);
    vector<point> NWPoints = NW->queryRange(r);
    vector<point> SEPoints = SE->queryRange(r);
    vector<point> SWPoints = SW->queryRange(r);
    pointsInRange.insert(pointsInRange.end(), NEPoints.begin(), NEPoints.end());
    pointsInRange.insert(pointsInRange.end(), NWPoints.begin(), NWPoints.end());
    pointsInRange.insert(pointsInRange.end(), SEPoints.begin(), SEPoints.end());
    pointsInRange.insert(pointsInRange.end(), SWPoints.begin(), SWPoints.end());
    return pointsInRange;
}

void QuadTree::clear()
{
    points.clear();
    if (NE != NULL)
    {
        NE->clear();
        NW->clear();
        SE->clear();
        SW->clear();
    }
    delete NE;
    delete NW;
    delete SE;
    delete SW;
    NE = NULL;
    NW = NULL;
    SE = NULL;
    SW = NULL;
}
