#include <iostream>
#include <math.h>

using namespace std;

#define MAX 10000

int v[MAX];

int next(int n) {
	int suma = 0;
	while (n) {
		suma += (n % 10) * (n % 10) * (n % 10);
		n /= 10;
	}
	return suma;

}

int main() {
	int num, i, j, flag;
	while (1) {
		cin >> num;
		i = 0;
		if (!num) {
			return 0;
		}
		v[0] = num; //CASO QUE EL PRIMERO SEA UN 1
		cout << v[0];
		if (v[0] == 1) {
			cout << " -> cubifinito.\n";
			continue;
		}
		for (i = 1; i < MAX; i++) {
			v[i] = next(v[i - 1]);
			cout << " - " << v[i];
			if (v[i] == 1) {
				flag = 1;
				break;
			}
			for (j = 0; j < i; j++) {
				if (v[j] == v[i]) {
					flag = 0;
					i = MAX;
					break;
				}
			}

		}
		if (flag) {
			cout << " -> cubifinito.\n";
		} else {
			cout << " -> no cubifinito.\n";
		}
	}
	return 0;
}
