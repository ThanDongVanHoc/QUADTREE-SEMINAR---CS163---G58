#include <bits/stdc++.h>
using namespace std;
#include "rect.h"
#include "QuadTree.h"
int main()
{
    rect boundary(point(0, 0), point(100, 100));
    QuadTree qt(boundary, 4);
    qt.insert(point(10, 10));
    qt.insert(point(51, 20));
    qt.insert(point(32, 30));
    qt.insert(point(40, 51));
    qt.insert(point(50, 50));
    qt.insert(point(60, 60));
    qt.insert(point(70, 70));
    qt.insert(point(80, 80));
    qt.insert(point(90, 90));
    vector<point> pointsInRange = qt.queryRange(rect(point(0, 0), point(50, 50)));
    cout << pointsInRange.size() << endl;
    for (vector<point>::iterator it = pointsInRange.begin(); it != pointsInRange.end(); ++it)
    {
        cout << it->x << " " << it->y << endl;
    }
    return 0;
}
