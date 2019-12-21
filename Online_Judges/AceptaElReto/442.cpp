#include <math.h>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int main() {
	string s, base;
	int i, n;

	while (cin >> s) {
		cin >> base;

		if (base == "CamelCase") {
			s[0] = toupper(s[0]);
			for (i = 1; i < s.length(); i++) {
				if (s[i] == '-' || s[i] == '_') {
					s[i + 1] = toupper(s[i + 1]);
					s = s.substr(0, i) + s.substr(i + 1, s.length());
				}
			}

		} else if (base == "snake_case") {
			if (isupper(s[0])) {
				s[0] = tolower(s[0]);
				for (i = 1; i < s.length(); i++) {
					if (isupper(s[i])) {
						s[i] = tolower(s[i]);
						s = s.substr(0, i) + "_" + s.substr(i, s.length());
					}
				}
			} else {
				for (i = 0; i < s.length(); i++) {
					if (s[i] == '-') {
						s[i] = '_';
					}
				}
			}

		} else {

			if (isupper(s[0])) {
				s[0] = tolower(s[0]);
				for (i = 1; i < s.length(); i++) {
					if (isupper(s[i])) {
						s[i] = tolower(s[i]);
						s = s.substr(0, i) + "-" + s.substr(i, s.length());
					}
				}
			} else {
				for (i = 0; i < s.length(); i++) {
					if (s[i] == '_') {
						s[i] = '-';
					}
				}
			}
		}
		cout << s << endl;
	}
	return 0;
}
