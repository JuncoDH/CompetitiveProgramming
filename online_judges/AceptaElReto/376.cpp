#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int n, cont, i;
	while (1) {
		cin >> n;
		int v[n + 1];
		cont = 0;
		if (!n) {
			return 0;
		}
		for (i = 0; i < n; i++) {
			cin >> v[i];
		}
		v[n] = v[0];
		for (i = 1; i < n; i++) {
			if (v[i - 1] < v[i] && v[i] > v[i + 1]) {
				cont++;
			}
		}
		if(v[0]>v[1]&&v[0]>v[n-1]){
			cont++;
		}
		cout << cont << endl;

	}
	return 0;
}

