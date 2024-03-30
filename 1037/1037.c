#include <stdio.h>

typedef enum EInterval {
  eOutOfInterval,
  e0to25,
  e25to50,
  e50to75,
  e75to100
} Interval;

Interval getInterval(double value) {
  if(value <    0.0) return eOutOfInterval;
  if(value <=  25.0) return e0to25;
  if(value <=  50.0) return e25to50;
  if(value <=  75.0) return e50to75;
  if(value <= 100.0) return e75to100;
  return eOutOfInterval;
}

void printInterval(Interval interval) {
  switch(interval) {
    case e0to25:
      (void)printf("Intervalo [0,25]\n");
      break;
    case e25to50:
      (void)printf("Intervalo (25,50]\n");
      break;
    case e50to75:
      (void)printf("Intervalo (50,75]\n");
      break;
    case e75to100:
      (void)printf("Intervalo (75,100]\n");
      break;
    default:
      (void)printf("Fora de intervalo\n");
  }
}

int main(int argv, char** argc) {
  double value;

  (void)scanf("%lf", &value);
  printInterval(getInterval(value));
  return 0;
}