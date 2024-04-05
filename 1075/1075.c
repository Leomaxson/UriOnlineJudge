#include <stdio.h>

#define RESTO 2
#define LIMITE 10000

int main() {
	unsigned short n, i;

	scanf("%u", &n);
	i = RESTO;
	while (i < LIMITE) {
		printf("%u\n", i);
		i += n;
	}
	return 0;
}