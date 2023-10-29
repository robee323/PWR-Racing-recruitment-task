#include "ConvexHull.h"
#include <algorithm>

Point::Point(double x, double y) : x(x), y(y) {}

// Comparison of the coordinates of two points
bool comparePoints(const Point& p1, const Point& p2) {
    if (p1.x == p2.x)
        return p1.y < p2.y;
    return p1.x < p2.x;
}

// Checking the position of three points (a, b, c)
int orientation(const Point& a, const Point& b, const Point& c) {
    double crossProduct = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (crossProduct == 0)
        return 0;  // the points are collinear
    return (crossProduct > 0) ? 1 : -1; // returns 1 for left and -1 for right orientation
}

// Finds points that form a convex hull using Graham's algorithm.
std::vector<Point> convexHull(std::vector<Point>& points) {
    int n = points.size();
    // At least 3 points are needed to create a convex hull
    if (n < 3) {
        std::vector<Point> emptyHull;
        return emptyHull;
    }
       // Find the point with the lowest y-coordinate (or leftmost, if there are several)
    int pivot = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[pivot].y || (points[i].y == points[pivot].y && points[i].x < points[pivot].x))
            pivot = i;
    }

    // Move the reference point to the beginning of the points vector
    std::swap(points[0], points[pivot]);

    // Sort points relative to a reference point
    std::sort(points.begin() + 1, points.end(), [&](const Point& p1, const Point& p2) {
        int o = orientation(points[0], p1, p2);
        if (o == 0)
            return (p1.x * p1.x + p1.y * p1.y) < (p2.x * p2.x + p2.y * p2.y);
        return o > 0;
    });
    
    // Initialize the heap
    std::vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);

    // Executes Graham's algorithm for the remaining points
    for (int i = 2; i < n; i++) {
        while (hull.size() >= 2 && orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) != -1) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    return hull;
}
