#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct SPoint {
    double X;
    double Y;
} Point;

double Point_Distance(Point p1, Point p2) {
    return sqrt(
        (p1.X - p2.X) * (p1.X - p2.X) + (p1.Y - p2.Y) * (p1.Y - p2.Y)
    );
}

int main(int argv, char** argc) {
    Point p1, p2;

    (void)scanf("%lf %lf %lf %lf", &p1.X, &p1.Y, &p2.X, &p2.Y);
    (void)printf("%.4lf\n", Point_Distance(p1, p2));
    return 0;
}