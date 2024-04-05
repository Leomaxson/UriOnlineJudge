#include <stdio.h>

int main(int argv, char** argc) {
    int fibs[] = {
      0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765,
      10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309,
      3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986 };
    int calls[] = {
      0, 0, 2, 4, 8, 14, 24, 40, 66, 108, 176, 286, 464, 752, 1218, 1972, 3192, 5166, 8360, 13528,
      21890, 35420, 57312, 92734, 150048, 242784, 392834, 635620, 1028456, 1664078, 2692536,
      4356616, 7049154, 11405772, 18454928, 29860702, 48315632, 78176336, 126491970, 204668308 };
    int instancias, fib;

    // L� o n�mero de inst�ncias.
    scanf("%d", &instancias);
    while(instancias) {
        scanf("%d", &fib);
        (void)printf("fib(%d) = %d calls = %d\n", fib, calls[fib], fibs[fib]);
        instancias--;
    }
    return 0;
}
