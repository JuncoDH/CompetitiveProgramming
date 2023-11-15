#include <iostream>
#include <math.h>

using namespace std;

int crop(int x, int y) {
	//cout<<":"<<x<<"-"<<y<<endl;

	if (x < 10 || y < 10) {
		return 0;
	}
	if (x > y) {
		if (x / y >= 2) {
			return x / y + crop(x % y, y);
		}
		x -= y;
	} else {
		if (y / x >= 2) {
			return y / x + crop(x, y % x);
		}
		y -= x;
	}

	return 1 + crop(x, y);
}

int main() {
	int a, b;

	while (1) {
		cin >> a >> b;
		if (!a && !b) {
			return 0;
		}
		cout << crop(a, b) << endl;
	}

	return 0;
}
