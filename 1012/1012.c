#include <stdlib.h>
#include <stdio.h>

/// Pi constant.
#define PI (3.14159)

/**
 * Calculates the area of a rectangled triangle.
 * @param base Base of the rectangled triangle.
 * @param height Height of the rectangled triangle.
 * @return Returns the area of the rectangled triangle.
 */
double rectangledTriangleArea(double base, double height) {
    return base * height / 2.0;
}

/**
 * Calculates the area of a circle.
 * @param radius Radius of the circle.
 * @return Returns the area of the circle.
 */
double circleArea(double radius) {
    return PI * radius * radius;
}

/**
 * Calculates the area of a trapezium.
 * @param baseA First base of the trapezium.
 * @param baseB Second base of the trapezium.
 * @param height Height of the trapezium.
 * @return Returns the area of the trapezium.
 */
double trapeziumArea(double baseA, double baseB, double height) {
    return (baseA + baseB) * height / 2.0;
}

/**
 * Calculates the area of a square.
 * @param side Side of the square.
 * @return Returns the area of the square.
 */
double squareArea(double side) {
    return side * side;
}

/**
 * Calculates the area of a rectangle.
 * @param sideA First side of the rectangle.
 * @param sideB Second side of the rectangle.
 * @return Returns the area of the rectangle.
 */
double rectangleArea(double sideA, double sideB) {
    return sideA * sideB;
}

int main(int argv, char** argc) {
    double a, b, c;

    (void)scanf("%lf %lf %lf", &a, &b, &c);
    (void)printf("TRIANGULO: %.3f\n", rectangledTriangleArea(a, c));
    (void)printf("CIRCULO: %.3f\n", circleArea(c));
    (void)printf("TRAPEZIO: %.3f\n", trapeziumArea(a, b, c));
    (void)printf("QUADRADO: %.3f\n", squareArea(b));
    (void)printf("RETANGULO: %.3f\n", rectangleArea(a, b));
    return 0;
}