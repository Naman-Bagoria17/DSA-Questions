#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

struct Point {
    int x, y;
};

// To find orientation of ordered triplet (p, q, r).
// Returns 0 if colinear, 1 if clockwise, 2 if counterclockwise.
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;           // colinear
    return (val > 0) ? 1 : 2;         // clock or counterclock wise
}

// Distance square between two points (for tie-breaking in sorting)
int distSq(Point p1, Point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) +
           (p1.y - p2.y)*(p1.y - p2.y);
}

// Global reference point
Point p0;

// Compare function for qsort (sort by polar angle)
bool compare(Point p1, Point p2) {
    int o = orientation(p0, p1, p2);
    if (o == 0)
        return distSq(p0, p1) < distSq(p0, p2);
    return o == 2;
}

// Prints convex hull of a set of n points.
void convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) {
        cout << "Convex hull not possible\n";
        return;
    }

    // Step 1: Find the bottom-most point (or left-most if tie)
    int ymin = points[0].y, minIndex = 0;
    for (int i = 1; i < n; i++) {
        if ((points[i].y < ymin) || 
           (points[i].y == ymin && points[i].x < points[minIndex].x)) {
            ymin = points[i].y;
            minIndex = i;
        }
    }

    // Place the bottom-most point at first position
    swap(points[0], points[minIndex]);
    p0 = points[0];

    // Step 2: Sort the points based on polar angle with p0
    sort(points.begin() + 1, points.end(), compare);

    // Step 3: Remove colinear points at the end
    vector<Point> filtered;
    filtered.push_back(points[0]);
    for (int i = 1; i < n; i++) {
        while (i < n - 1 && orientation(p0, points[i], points[i+1]) == 0)
            i++;
        filtered.push_back(points[i]);
    }

    if (filtered.size() < 3) {
        cout << "Convex hull not possible\n";
        return;
    }

    // Step 4: Create an empty stack and push first 3 points
    stack<Point> S;
    S.push(filtered[0]);
    S.push(filtered[1]);
    S.push(filtered[2]);

    // Step 5: Process remaining points
    for (int i = 3; i < filtered.size(); i++) {
        while (S.size() > 1) {
            Point top = S.top(); S.pop();
            Point nextToTop = S.top();
            // If the orientation of nextToTop,top,filtered[i] is not counterclockwise then
            // continue bcz you did right by popping out the top otherwise you have to push the top again onto the stack.
            if (orientation(nextToTop, top, filtered[i]) != 2)
                continue;
            else {
                S.push(top);
                break;
            }
        }
        //push the new poibt onto the stack.
        S.push(filtered[i]);
    }

    // Output the convex hull
    cout << "Convex Hull Points:\n";
    vector<Point> hull;
    while (!S.empty()) {
        hull.push_back(S.top());
        S.pop();
    }
    reverse(hull.begin(), hull.end());
    for (const auto& p : hull)
        cout << "(" << p.x << ", " << p.y << ")\n";
}

int main() {
    vector<Point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                            {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    convexHull(points);
    return 0;
}
