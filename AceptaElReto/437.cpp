#include <math.h>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	int caso, hh, mm, ss, h, m, s, z;

	scanf("%d", &caso);
	for (z = 0; z < caso; z++) {
		scanf("%d:%d:%d", &hh, &mm, &ss);
		h = 24 - hh - (mm || ss);
		m = 60 - mm - (ss != 0);
		s = 60 - ss;
		h %= 24;
		m %= 60;
		s %= 60;
		printf("%02d:%02d:%02d\n", h, m, s);

	}

	return 0;
}
