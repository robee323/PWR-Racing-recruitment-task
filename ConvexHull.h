#pragma once

#include <vector>

// A structure representing a point in the 2D plane
struct Point {
    double x, y;
    Point(double x, double y);
};

bool comparePoints(const Point& p1, const Point& p2);
int orientation(const Point& a, const Point& b, const Point& c);
std::vector<Point> convexHull(std::vector<Point>& points);
