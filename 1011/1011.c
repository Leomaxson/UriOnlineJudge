#include <stdlib.h>
#include <stdio.h>

// Pi constant.
#define PI (3.14159)

/**
 * Calculates the volume of a sphere.
 * @param radius The radius of the sphere.
 * @return Returns the radius of the sphere.
 */
double sphereVolume(double radius) {
  return 4.0 / 3.0 * PI * radius * radius * radius;
}

int main(int argv, char** argc) {
  double radius;

  (void)scanf("%lf", &radius);
  (void)printf("VOLUME = %.3f\n", sphereVolume(radius));
  return 0;
}