#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {
	int n, z, num;
	string s;
	while (cin >> s) {
		if (s.length() == 3) {
			s = "0" + s;
		}
		if (s.length() == 2) {
			s = "00" + s;
		}
		if (s.length() == 1) {
			s = "000" + s;
		}

		num = stoi(s.substr(s.length() - 4, 1)) * 1000
				+ stoi(s.substr(s.length() - 3, 1)) * 100
				+ stoi(s.substr(s.length() - 2, 1)) * 10
				+ stoi(s.substr(s.length() - 1, 1));

		num %= 16;
		if (num == 0 || num == 1 || num == 4 || num == 9) {
			cout << "NO SE\n";
		} else {
			cout << "IMPERFECTO\n";
		}

	}
	return 0;
}

