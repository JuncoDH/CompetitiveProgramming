#include <math.h>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	string s;
	int i, cambios;
	while (cin >> s) {
		cambios = 0;
		for (i = s.length() - 1; i >= 0; i--) {
			if (s[i] == '.') {
				continue;
			}
			if (s[i] == '9') {
				s[i] = '0';
			} else {
				s[i]++;
				cambios = 1;
				break;
			}

		}
		if (cambios) {
			cout << s << endl;
		} else {
			if (s.length() % 4 == 3) {
				cout << "1." << s << endl;
			} else {
				cout << "1" << s << endl;
			}
		}

	}

	return 0;
}
