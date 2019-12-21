#include <math.h>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

#define MAX 256

int main() {
	int n, i, letras, exclamacion;
	string s;

	while (getline(cin, s)) {
		n = s.length();
		letras = 0;
		exclamacion = 0;
		for (i = 0; i <= n; i++) {
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
				letras++;
			}
			if (s[i] == '!') {
				exclamacion++;
			}

		}
		if (exclamacion > letras) {
			cout << "ESGRITO\n";
		} else {
			cout << "escrito\n";
		}
	}

	return 0;
}
