#include <stdio.h>

// Car efficiency (in km/l)
#define CAR_EFICIENCY (12.0)

int main(int argv, char** argc) {
    int travelTime_Hours, averageSpeed_KmH;

    (void)scanf("%d %d", &travelTime_Hours, &averageSpeed_KmH);
    (void)printf("%.3lf\n", travelTime_Hours * averageSpeed_KmH / CAR_EFICIENCY);
    return 0;
}