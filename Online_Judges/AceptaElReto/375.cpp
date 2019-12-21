#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	string s;
	while (cin >> s) {

		if (s == "18") {
			cout << "36\n";
			continue;
		}
		if (s == "18L") {
			cout << "36R\n";
			continue;
		}
		if (s == "18C") {
			cout << "36C\n";
			continue;
		}
		if (s == "18R") {
			cout << "36L\n";
			continue;
		}

		if (s.length() == 2) {
			printf("%02d\n", (stoi(s) + 18) % 36);
			continue;
		}
		if (s[2] == 'C') {
			printf("%02dC\n", (stoi(s) + 18) % 36);
			continue;
		}
		if (s[2] == 'L') {
			printf("%02dR\n", (stoi(s) + 18) % 36);
			continue;
		}
		if (s[2] == 'R') {
			printf("%02dL\n", (stoi(s) + 18) % 36);
			continue;
		}

	}
	return 0;
}

