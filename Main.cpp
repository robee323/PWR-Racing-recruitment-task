#include <iostream>
#include <fstream>
#include "ConvexHull.h"


int main() {
    std::string fileName;
    std::cout << "Enter the name of the data file: ";
    std::cin >> fileName;

    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Unable to open the file." << std::endl;
        return 1;
    }

    int n;
    file >> n;
    std::vector<Point> points;
    
    // Reads points from a file
    for (int i = 0; i < n; i++) {
        double x, y;
        file >> x >> y;
        points.push_back(Point(x, y));
    }

    file.close();

    std::vector<Point> convexHullPoints = convexHull(points);

    std::cout << "Points forming the convex hull:" << std::endl;
    for (const Point& p : convexHullPoints) {
        std::cout << "(" << p.x << ", " << p.y << ") ";
    }
    std::cout << std::endl;

    return 0;
}
