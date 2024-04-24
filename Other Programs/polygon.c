//Given two polygons,find out whether they intersect or not. 

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *points;
    int count;
} Polygon;

// Function to calculate the dot product of two vectors
double dot_product(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

// Function to calculate the cross product of two vectors
double cross_product(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

// Function to calculate the projection of polygon p1 onto axis defined by point p and direction vector d
double projection(Polygon p1, Point p, Point d) {
    double min = dot_product(p1.points[0], d);
    double max = min;

    for (int i = 1; i < p1.count; i++) {
        double projection = dot_product(p1.points[i], d);
        if (projection < min) {
            min = projection;
        } else if (projection > max) {
            max = projection;
        }
    }

    return max - min;
}

// Function to check if two polygons intersect
bool intersects(Polygon p1, Polygon p2) {
    for (int i = 0; i < p1.count; i++) {
        Point a = p1.points[i];
        Point b = p1.points[(i + 1) % p1.count];
        Point d = {b.x - a.x, b.y - a.y};

        for (int j = 0; j < p2.count; j++) {
            Point p = p2.points[j];
            double min1 = dot_product(p, d);
            double max1 = min1;

            for (int k = 1; k < p2.count; k++) {
                double projection = dot_product(p2.points[(j + k) % p2.count], d);
                if (projection < min1) {
                    min1 = projection;
                } else if (projection > max1) {
                    max1 = projection;
                }
            }

            if (max1 < min1) {
                return false;
            }
        }
    }

    for (int i = 0; i < p2.count; i++) {
        Point a = p2.points[i];
        Point b = p2.points[(i + 1) % p2.count];
        Point d = {b.x - a.x, b.y - a.y};

        for (int j = 0; j < p1.count; j++) {
            Point p = p1.points[j];
            double min2 = dot_product(p, d);
            double max2 = min2;

            for (int k = 1; k < p1.count; k++) {
                double projection = dot_product(p1.points[(j + k) % p1.count], d);
                if (projection < min2) {
                    min2 = projection;
                } else if (projection > max2) {
                    max2 = projection;
                }
            }

            if (max2 < min2) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    Polygon p1 = {(Point[]){{0, 0}, {10, 0}, {10, 10}, {0, 10}}, 4};
    Polygon p2 = {(Point[]){{5, 5}, {15, 5}, {15, 15}, {5, 15}}, 4};

    if (intersects(p1, p2)) {
        printf("The polygons intersect.\n");
    } else {
        printf("The polygons do not intersect.\n");
    }

    return 0;
}