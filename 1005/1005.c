#include <stdio.h>

#define WEIGHT_GRADE_A (3.5)
#define WEIGHT_GRADE_B (7.5)
#define WEIGHTS_SUM (WEIGHT_GRADE_A + WEIGHT_GRADE_B)

int main(int argv, char** argc) {
    double gradeA, gradeB, average;

    (void)scanf("%lf %lf", &gradeA, &gradeB);
    average = (gradeA * WEIGHT_GRADE_A + gradeB * WEIGHT_GRADE_B) / WEIGHTS_SUM;
    (void)printf("MEDIA = %.5f\n", average);
    return 0;
}