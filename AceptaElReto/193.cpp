#include <iostream>
#include <math.h>

using namespace std;

int reverse(int n) {
	int s = 0;
	while (n) {
		s *= 10;
		s += n % 10;
		n /= 10;
	}
	return s;
}

int main() {
	int num, suma, flag;
	while (1) {
		cin >> num;
		flag = 0;
		if (!num) {
			return 0;
		}
		if (num % 10 == 0) {
			cout << "NO\n";
			continue;
		}
		suma = num + reverse(num);
		while (suma) {
			if (suma % 2 == 0) {
				flag = 1;
				break;
			}
			suma /= 10;
		}
		if (flag) {
			cout << "NO\n";
		} else {
			cout << "SI\n";
		}

	}

	return 0;
}
