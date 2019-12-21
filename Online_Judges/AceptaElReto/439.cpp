#include <math.h>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	char c1, c2;
	int n1, n2, z, casos;
	scanf("%d", &casos);
	for (z = 0; z < casos; z++) {
		scanf(" %c=%d %c=%d", &c1, &n1, &c2, &n2);
		if (c1 == 'D' && c2 == 'T') {
			printf("V=%d\n", n1 / n2);
		}
		if (c1 == 'D' && c2 == 'V') {
			printf("T=%d\n", n1 / n2);
		}
		if (c1 == 'T' && c2 == 'D') {
			printf("V=%d\n", n2 / n1);
		}
		if (c1 == 'T' && c2 == 'V') {
			printf("D=%d\n", n1 * n2);
		}
		if (c1 == 'V' && c2 == 'T') {
			printf("D=%d\n", n1 * n2);
		}
		if (c1 == 'V' && c2 == 'D') {
			printf("T=%d\n", n2 / n1);
		}
	}
	return 0;
}
