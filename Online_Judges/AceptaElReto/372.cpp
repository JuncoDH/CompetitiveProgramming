#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {
	int n, z;
	string s;
	cin >> n;
	for (z = 0; z < n; z++) {
		cin >> s;
		if (isupper(s[0])) {
			s[0] = tolower(s[0]);
			reverse(s.begin(), s.end());
			s[0] = toupper(s[0]);
		} else {
			reverse(s.begin(), s.end());
		}
		cout << s<<endl;
	}
	return 0;
}
